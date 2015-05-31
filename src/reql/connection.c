/*
Copyright 2014-2015 Adam Grandquist

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */
/**
 * @author Adam Grandquist
 * @copyright Apache
 */

#include "./reql/connection.h"

#include "./reql/core.h"
#include "./reql/portable_endian.h"

#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

static const ReQL_Size REQL_VERSION = 0x400c2d20;
static const ReQL_Size REQL_PROTOCOL = 0x7e6970c7;

enum ReQL_Query_e {
  REQL_CONTINUE = 2,
  REQL_NOREPLY_WAIT = 4,
  REQL_START = 1,
  REQL_STOP = 3
};

typedef union {
  ReQL_Size num;
  ReQL_Byte buf[4];
} ReQL_LE32;

typedef union {
  ReQL_Token num;
  ReQL_Byte buf[8];
} ReQL_LE64;

static int
reql_continue_query(ReQL_Cur_t *cur, ReQL_Conn_t *conn);

static void
reql_make_32_le(ReQL_Byte *buf, const ReQL_Size magic) {
  ReQL_LE32 convert = {htole32(magic)};
  memcpy(buf, convert.buf, 4);
}

static void
reql_make_64_token(ReQL_Byte *buf, const ReQL_Token magic) {
  ReQL_LE64 convert = {htole64(magic)};
  memcpy(buf, convert.buf, 8);
}

static ReQL_Size
reql_get_32_le(ReQL_Byte *buf) {
  ReQL_LE32 convert = {0};
  memcpy(convert.buf, buf, 4);
  return le32toh(convert.num);
}

static ReQL_Token
reql_get_64_token(ReQL_Byte *buf) {
  ReQL_LE64 convert = {0};
  memcpy(convert.buf, buf, 8);
  return le64toh(convert.num);
}

static void
reql_conn_error(const char *msg, const char *trace) {
  reql_error_init(REQL_E_CONNECTION, msg, trace);
}

static void
reql_conn_memory_error(const char *trace) {
  reql_conn_error("Insufficient memory", trace);
}

static void
reql_conn_mutex_init(ReQL_Conn_t *conn) {
  if (conn->condition.mutex == NULL) {
    pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));

    if (attrs == NULL) {
      reql_conn_memory_error(__func__);
      return;
    }

    pthread_mutexattr_init(attrs);
    pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

    pthread_mutex_t *mutex = malloc(sizeof(pthread_mutex_t));

    pthread_mutex_init(mutex, attrs);

    conn->condition.mutex = mutex;

    pthread_mutexattr_destroy(attrs);

    free(attrs); attrs = NULL;
  }

  if (conn->condition.done == NULL) {
    pthread_condattr_t *attrs = malloc(sizeof(pthread_condattr_t));

    if (attrs == NULL) {
      reql_conn_memory_error(__func__);
      return;
    }

    pthread_condattr_init(attrs);
    pthread_condattr_setpshared(attrs, PTHREAD_PROCESS_PRIVATE);

    pthread_cond_t *done = malloc(sizeof(pthread_cond_t));

    pthread_cond_init(done, attrs);

    conn->condition.done = done;

    pthread_condattr_destroy(attrs);

    free(attrs); attrs = NULL;
  }
}

static void
reql_conn_lock(ReQL_Conn_t *conn) {
  reql_conn_mutex_init(conn);
  pthread_mutex_lock(conn->condition.mutex);
}

static void
reql_conn_unlock(ReQL_Conn_t *conn) {
  if (conn == NULL) {
    return;
  }
  if (conn->condition.mutex == NULL) {
    return;
  }
  pthread_mutex_unlock(conn->condition.mutex);
}

extern void
reql_conn_init(ReQL_Conn_t *conn) {
  memset(conn, (int)NULL, sizeof(ReQL_Conn_t));
  reql_conn_lock(conn);
  conn->socket = -1;
  conn->timeout = 20;
  conn->port = "28015";
  reql_conn_unlock(conn);
}

extern void
reql_conn_set_auth(ReQL_Conn_t *conn, const ReQL_Size size, char *auth) {
  reql_conn_lock(conn);
  conn->auth_size = size;
  conn->auth = auth;
  reql_conn_unlock(conn);
}

extern char *
reql_conn_auth_key(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  char *auth = conn->auth;
  reql_conn_unlock(conn);
  return auth;
}

extern ReQL_Size
reql_conn_auth_size(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  const ReQL_Size size = conn->auth_size;
  reql_conn_unlock(conn);
  return size;
}

extern void
reql_conn_set_addr(ReQL_Conn_t *conn, char *addr) {
  reql_conn_lock(conn);
  conn->addr = addr;
  reql_conn_unlock(conn);
}

extern char *
reql_conn_addr(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  char *addr = conn->addr;
  reql_conn_unlock(conn);
  return addr;
}

extern void
reql_conn_set_port(ReQL_Conn_t *conn, char *port) {
  reql_conn_lock(conn);
  conn->port = port;
  reql_conn_unlock(conn);
}

extern char *
reql_conn_port(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  char *port = conn->port;
  reql_conn_unlock(conn);
  return port;
}

extern void
reql_conn_set_timeout(ReQL_Conn_t *conn, const ReQL_Token timeout) {
  reql_conn_lock(conn);
  conn->timeout = timeout;
  reql_conn_unlock(conn);
}

extern ReQL_Token
reql_conn_timeout(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  const ReQL_Token timeout = conn->timeout;
  reql_conn_unlock(conn);
  return timeout;
}

static int
reql_conn_socket(const ReQL_Conn_t *conn) {
  return conn->socket;
}

static void
reql_close_conn_(ReQL_Conn_t *conn) {
  int sock = reql_conn_socket(conn);
  if (sock >= 0) {
    close(sock);
    pthread_cond_broadcast(conn->condition.done);
    conn->socket = -1;
  }
}

static void
reql_ensure_conn_close_(ReQL_Conn_t *conn) {
  reql_close_conn_(conn);
  while (reql_conn_socket(conn) > 0) {
    pthread_cond_wait(conn->condition.done, conn->condition.mutex);
  }
  while (conn->cursors != NULL) {
    reql_close_cur(conn->cursors);
  }
  reql_conn_unlock(conn);
  pthread_mutex_destroy(conn->condition.mutex);
  free(conn->condition.mutex); conn->condition.mutex = NULL;
}

static void
reql_conn_set_res(ReQL_Conn_t *conn, ReQL_Obj_t *res, const ReQL_Token token) {
  ReQL_Cur_t *cur = conn->cursors;

  if (cur == NULL) {
    reql_json_destroy(res);
    return;
  }

  while (1) {
    if (cur->token == token) {
      reql_cur_set_response(cur, res);
      if (reql_cur_open(cur) != 0) {
        reql_continue_query(cur, conn);
      }
      break;
    } else if (cur->next == cur) {
      reql_json_destroy(res);
      break;
    } else {
      cur = cur->next;
    }
  }
}

static void *
reql_conn_loop(void *conn) {
  reql_conn_lock(conn);

  const struct timeval timeout = {0, 1};

  if (setsockopt(reql_conn_socket(conn), SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval))) {
    reql_close_conn_(conn);
    reql_conn_unlock(conn);
    return NULL;
  }

  if (setsockopt(reql_conn_socket(conn), SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(struct timeval))) {
    reql_close_conn_(conn);
    reql_conn_unlock(conn);
    return NULL;
  }

  ReQL_Byte *response = malloc(sizeof(ReQL_Byte) * 12);
  ReQL_Token token = 0;
  ReQL_Size pos = 0, size = 0;

  while (reql_conn_socket(conn) >= 0) {
    if (((ReQL_Conn_t *)conn)->cursors == NULL) {
      reql_conn_unlock(conn);
      sched_yield();
      reql_conn_lock(conn);
      continue;
    }

    size_t rcv_size_request = (size > 0 ? size : 12) - pos;
    ssize_t rcv_size = recvfrom(reql_conn_socket(conn), &response[pos], rcv_size_request, 0, NULL, NULL);
    reql_conn_unlock(conn);

    if (rcv_size < 0) {
    } else if ((size_t)rcv_size == rcv_size_request) {
      pos += rcv_size;
    } else {
      pos += rcv_size;
    }

    if (size > 0) {
      if (pos >= size) {
        printf("found query response %s\n", response);
        ReQL_Obj_t *res = reql_decode(response, size);
        if (res == NULL) {
          printf("failed to decode query response\n");
          if (reql_error_type() == REQL_E_NO) {
            reql_conn_error("Failed to decode response", __func__);
          }
          reql_close_conn(conn);
        } else {
          reql_conn_lock(conn);
          reql_conn_set_res(conn, res, token);
          reql_conn_unlock(conn);
        }

        pos -= size;
        size = 0;

        ReQL_Byte *buf = realloc(response, sizeof(ReQL_Byte) * 12);
        if (buf == NULL) {
          reql_close_conn(conn);
        } else {
          response = buf;
        }
      }
    } else {
      if (pos >= 12) {
        pos -= 12;
        token = reql_get_64_token(response);
        size = reql_get_32_le(&response[8]);
        printf("found response for token %llu size %i\n", token, size);
        ReQL_Byte *buf = realloc(response, sizeof(ReQL_Byte) * size);
        if (buf == NULL) {
          reql_close_conn(conn);
        } else {
          response = buf;
        }
      }
    }
    reql_conn_lock(conn);
  }

  reql_conn_unlock(conn);

  free(response);

  return NULL;
}

static int
reql_connect_(ReQL_Conn_t *conn, ReQL_Byte *buf, const ReQL_Size size) {
  struct addrinfo hints;
  struct addrinfo *result, *rp;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  hints.ai_protocol = IPPROTO_TCP;

  if (getaddrinfo(conn->addr, conn->port, &hints, &result) != 0) {
    return -1;
  }

  int sock = -1;

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

    if (sock == -1) continue;

    if (connect(sock, rp->ai_addr, rp->ai_addrlen) != -1) break;

    close(sock);
  }

  if (rp == NULL) {
    freeaddrinfo(result);
    return -1;
  }

  freeaddrinfo(result);

  const struct timeval timeout = {(int64_t)conn->timeout, 0};

  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval))) {
    return -1;
  }

  if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(struct timeval))) {
    return -1;
  }

  ReQL_Byte iov_base[3][4];

  reql_make_32_le(iov_base[0], REQL_VERSION);
  reql_make_32_le(iov_base[1], conn->auth_size);
  reql_make_32_le(iov_base[2], REQL_PROTOCOL);

  struct iovec magic[4];

  magic[0].iov_base = iov_base[0];
  magic[0].iov_len = 4;

  magic[1].iov_base = iov_base[1];
  magic[1].iov_len = 4;

  magic[2].iov_base = conn->auth;
  magic[2].iov_len = conn->auth_size;

  magic[3].iov_base = iov_base[2];
  magic[3].iov_len = 4;

  if (writev(sock, magic, 4) != (conn->auth_size + 12)) {
    return -1;
  }

  const ssize_t rcv_size = recvfrom(sock, buf, 8, 0, NULL, NULL);

  if (rcv_size < 0) {
    return -1;
  } else if (rcv_size != 8) {
    return -1;
  } else if (memcmp(buf, "SUCCESS", 8) != 0) {
    recvfrom(sock, &buf[8], size - 8, 0, NULL, NULL);
    return -1;
  }

  conn->socket = sock;

  pthread_t thread;

  if (pthread_create(&thread, NULL, reql_conn_loop, conn) != 0) {
    return -1;
  }

  if (pthread_detach(thread) != 0) {
    reql_ensure_conn_close_(conn);
    pthread_join(thread, NULL);
    return -1;
  }

  return 0;
}

extern int
reql_connect(ReQL_Conn_t *conn, ReQL_Byte *buf, const ReQL_Size size) {
  reql_conn_lock(conn);
  const int status = reql_connect_(conn, buf, size);
  if (status != 0) {
    reql_ensure_conn_close_(conn);
  }
  reql_conn_unlock(conn);
  return status;
}

extern void
reql_close_conn(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  reql_close_conn_(conn);
  reql_conn_unlock(conn);
}

extern void
reql_ensure_conn_close(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  reql_ensure_conn_close_(conn);
  reql_conn_unlock(conn);
}

extern char
reql_conn_open(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  const char open = reql_conn_socket(conn) >= 0;
  reql_conn_unlock(conn);
  return open;
}

static ReQL_Obj_t *
reql_build(const ReQL_Obj_t *query) {
  ReQL_Obj_t *obj = NULL;

  switch (reql_datum_type(query)) {
    case REQL_R_ARRAY: {
      obj = malloc(sizeof(ReQL_Obj_t));
      if (obj == NULL) {
        break;
      }
      ReQL_Size size = reql_size(query);
      ReQL_Obj_t **arrray = malloc(sizeof(ReQL_Obj_t*) * size);
      reql_array_init(obj, arrray, size);
      ReQL_Iter_t it = reql_new_iter(query);
      const ReQL_Obj_t *elem;
      while ((elem = reql_iter_next(&it)) != NULL) {
        reql_array_append(obj, reql_build(elem));
      }
      break;
    }
    case REQL_R_BOOL: {
      obj = malloc(sizeof(ReQL_Obj_t));
      if (obj == NULL) {
        break;
      }
      reql_bool_init(obj, reql_to_bool(query));
      break;
    }
    case REQL_R_JSON: break;
    case REQL_R_NULL: {
      obj = malloc(sizeof(ReQL_Obj_t));
      if (obj == NULL) {
        break;
      }
      reql_null_init(obj);
      break;
    }
    case REQL_R_NUM: {
      obj = malloc(sizeof(ReQL_Obj_t));
      if (obj == NULL) {
        break;
      }
      reql_number_init(obj, reql_to_number(query));
      break;
    }
    case REQL_R_OBJECT: {
      obj = malloc(sizeof(ReQL_Obj_t));
      if (obj == NULL) {
        break;
      }
      ReQL_Size size = reql_size(query);
      ReQL_Pair_t *pairs = malloc(sizeof(ReQL_Pair_t) * size);
      reql_object_init(obj, pairs, size);
      ReQL_Iter_t it = reql_new_iter(query);
      ReQL_Obj_t *key;
      while ((key = reql_iter_next(&it)) != NULL) {
        reql_object_add(obj, reql_build(key), reql_build(reql_object_get(query, key)));
      }
      break;
    }
    case REQL_R_REQL: {
      obj = malloc(sizeof(ReQL_Obj_t));
      if (obj == NULL) {
        break;
      }
      ReQL_Obj_t **array = malloc(sizeof(ReQL_Obj_t*) * 3);
      reql_array_init(obj, array, 3);

      ReQL_Obj_t *term = malloc(sizeof(ReQL_Obj_t));

      reql_number_init(term, (double)(reql_term_type(query)));

      reql_array_append(obj, term);

      if (query->obj.args.args != NULL) {
        reql_array_append(obj, reql_build(query->obj.args.args));
      }

      if (query->obj.args.kwargs != NULL) {
        reql_array_append(obj, reql_build(query->obj.args.kwargs));
      }
      break;
    }
    case REQL_R_STR: {
      obj = malloc(sizeof(ReQL_Obj_t));
      if (obj == NULL) {
        break;
      }
      ReQL_Size size = reql_size(query);
      ReQL_Byte *buf = malloc(sizeof(ReQL_Byte) * size);
      reql_string_init(obj, buf, size);
      reql_string_append(obj, reql_string_buf(query), size);
      break;
    }
  }

  return obj;
}

static ReQL_String_t *
reql_encode_query(const ReQL_Obj_t *query, ReQL_Obj_t *kwargs) {
  ReQL_Obj_t start;

  ReQL_Obj_t array;
  ReQL_Obj_t *arr[3];

  reql_number_init(&start, REQL_START);
  reql_array_init(&array, arr, 3);
  reql_array_insert(&array, &start, 0);

  ReQL_Obj_t *build = reql_build(query);

  reql_array_insert(&array, build, 1);

  reql_array_insert(&array, kwargs, 2);

  ReQL_String_t *wire_query = reql_encode(&array);

  reql_json_destroy(build);

  return wire_query;
}

static int
reql_run__(const ReQL_String_t *wire_query, ReQL_Conn_t *conn, const ReQL_Token token) {
  ReQL_Byte token_bytes[8];

  reql_make_64_token(token_bytes, token);

  ReQL_Byte size[4];

  reql_make_32_le(size, wire_query->size);

  struct iovec magic[3];

  magic[0].iov_base = token_bytes;
  magic[0].iov_len = 8;

  magic[1].iov_base = size;
  magic[1].iov_len = 4;

  magic[2].iov_base = wire_query->str;
  magic[2].iov_len = wire_query->size;

  printf("sending query %llu, %zu, %s\n", token, magic[2].iov_len, magic[2].iov_base);

  if (writev(reql_conn_socket(conn), magic, 3) != (wire_query->size + 12)) {
    return -1;
  }

  return 0;
}

static int
reql_run_(ReQL_Cur_t *cur, const ReQL_String_t *wire_query, ReQL_Conn_t *conn) {
  if (reql_conn_open(conn) == 0) {
    return -1;
  }

  const ReQL_Token token = conn->max_token++;

  if (cur != NULL) {
    reql_cur_init(cur, conn, token);
    conn->cursors = cur;
  }

  return reql_run__(wire_query, conn, token);
}

static int
reql_encode_constant_query(ReQL_String_t *wire_query, const enum ReQL_Query_e type, char *buf, ReQL_Size alloc_size) {
  const int size = snprintf(buf, alloc_size, "[%i]", type);
  if ((ReQL_Size)size > alloc_size || size < 3) {
    return -1;
  }
  wire_query->alloc_size = alloc_size;
  wire_query->size = (ReQL_Size)size;
  wire_query->str = (ReQL_Byte *)buf;

  return 0;
}

static int
reql_continue_query(ReQL_Cur_t *cur, ReQL_Conn_t *conn) {
  ReQL_String_t wire_query;

  char buf[10];

  if (reql_encode_constant_query(&wire_query, REQL_CONTINUE, buf, 10) != 0) {
    return -1;
  }

  return reql_run__(&wire_query, conn, cur->token);
}

extern int
reql_no_reply_wait_query(ReQL_Conn_t *conn) {
  ReQL_String_t wire_query;

  char buf[10];

  if (reql_encode_constant_query(&wire_query, REQL_NOREPLY_WAIT, buf, 10) != 0) {
    return -1;
  }

  reql_conn_lock(conn);
  const int status = reql_run__(&wire_query, conn, conn->max_token++);
  reql_conn_lock(conn);

  return status;
}

extern int
reql_stop_query(ReQL_Cur_t *cur, ReQL_Conn_t *conn) {
  ReQL_String_t wire_query;

  char buf[10];

  if (reql_encode_constant_query(&wire_query, REQL_STOP, buf, 10) != 0) {
    return -1;
  }

  reql_conn_lock(conn);
  const int status = reql_run__(&wire_query, conn, cur->token);
  reql_conn_unlock(conn);

  return status;
}

extern int
reql_run(ReQL_Cur_t *cur, const ReQL_Obj_t *query, ReQL_Conn_t *conn, ReQL_Obj_t *kwargs) {
  ReQL_String_t *wire_query = reql_encode_query(query, kwargs);

  if (wire_query == NULL) {
    return -1;
  }

  reql_conn_lock(conn);
  const int status = reql_run_(cur, wire_query, conn);
  reql_conn_unlock(conn);

  free(wire_query->str); wire_query->str = NULL;
  free(wire_query); wire_query = NULL;

  return status;
}