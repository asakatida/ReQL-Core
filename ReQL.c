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

#include "ReQL.h"

#include "ReQL-util.h"
#include "ReQL-encode.h"
#include "ReQL-decode.h"

#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/uio.h>
#include <unistd.h>

static const uint32_t REQL_VERSION = 0x400c2d20;
static const uint32_t REQL_PROTOCOL = 0x7e6970c7;

enum {
  REQL_CONTINUE = 2,
  REQL_NOREPLY_WAIT = 4,
  REQL_START = 1,
  REQL_STOP = 3
};

typedef union {
  uint32_t num;
  uint8_t buf[4];
} ReQL_LE32;

typedef union {
  uint64_t num;
  uint8_t buf[8];
} ReQL_LE64;

static void
reql_make_32_le(uint8_t *buf, const uint32_t magic) {
  ReQL_LE32 convert = {htole32(magic)};
  memcpy(buf, convert.buf, 4);
}

static void
reql_make_64_token(uint8_t *buf, const uint64_t magic) {
  ReQL_LE64 convert = {htole64(magic)};
  memcpy(buf, convert.buf, 8);
}

static uint32_t
reql_get_32_le(uint8_t *buf) {
  ReQL_LE32 convert = {0};
  memcpy(convert.buf, buf, 4);
  return le32toh(convert.num);
}

static uint64_t
reql_get_64_token(uint8_t *buf) {
  ReQL_LE64 convert = {0};
  memcpy(convert.buf, buf, 8);
  return le64toh(convert.num);
}

static int
reql_conn_lock(const ReQL_Conn_t *conn) {
  return pthread_mutex_lock(conn->mutex);
}

static int
reql_conn_unlock(const ReQL_Conn_t *conn) {
  return pthread_mutex_unlock(conn->mutex);
}

extern void
reql_connection_init(ReQL_Conn_t *conn) {
  pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));

  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

  pthread_mutex_t *mutex = malloc(sizeof(pthread_mutex_t));

  pthread_mutex_init(mutex, attrs);

  conn->mutex = mutex;

  pthread_mutexattr_destroy(attrs);

  free(attrs); attrs = NULL;

  reql_conn_lock(conn);
  conn->socket = -1;
  conn->done = 0;
  conn->max_token = 0;
  conn->cursors = NULL;
  conn->timeout = 20;
  conn->auth_size = 0;
  conn->auth = NULL;
  conn->port = "28015";
  conn->addr = NULL;
  reql_conn_unlock(conn);
}

extern void
reql_conn_set_auth(ReQL_Conn_t *conn, const uint32_t size, char *auth) {
  reql_conn_lock(conn);
  conn->auth_size = size;
  conn->auth = auth;
  reql_conn_unlock(conn);
}

extern void
reql_conn_set_addr(ReQL_Conn_t *conn, char *addr) {
  reql_conn_lock(conn);
  conn->addr = addr;
  reql_conn_unlock(conn);
}

extern void
reql_conn_set_port(ReQL_Conn_t *conn, char *port) {
  reql_conn_lock(conn);
  conn->port = port;
  reql_conn_unlock(conn);
}

extern void
reql_conn_set_timeout(ReQL_Conn_t *conn, const unsigned long timeout) {
  reql_conn_lock(conn);
  conn->timeout = timeout;
  reql_conn_unlock(conn);
}

static int
reql_conn_socket(const ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  int sock = conn->socket;
  reql_conn_unlock(conn);
  return sock;
}

static void
reql_conn_close_socket(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  close(conn->socket);
  conn->socket = -1;
  reql_conn_unlock(conn);
}

static void
reql_set_cur_res(const ReQL_Conn_t *conn, ReQL_Obj_t *res, const uint64_t token) {
  ReQL_Cur_t *cur = conn->cursors;

  while (1) {
    if (cur->token == token) {
      reql_set_cur_response(cur, res);
      break;
    }
    if (cur == cur->next) {
      break;
    }
    cur = cur->next;
  }
}

static char
reql_conn_done(const ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  char res = conn->done;
  reql_conn_unlock(conn);
  return res;
}

static uint32_t
reql_conn_read(const ReQL_Conn_t *conn, uint8_t *buf, const uint32_t size) {
  const ssize_t rcv_size = recvfrom(reql_conn_socket(conn), buf, size, 0, NULL, NULL);

  if (rcv_size < 0) {
    return 0;
  }

  return (uint32_t)rcv_size;
}

static void *
reql_conn_loop(void *conn) {
  uint8_t *response = malloc(sizeof(uint8_t) * 12);
  uint64_t token = 0;
  uint32_t pos = 0, size = 0;

  while (!reql_conn_done(conn)) {
    pos += reql_conn_read(conn, &response[pos], (size > 0 ? size : 12) - pos);
    if (size > 0) {
      if (pos >= size) {
        reql_set_cur_res(conn, reql_decode(response, size), token);

        pos -= size;
        size = 0;

        response = realloc(response, sizeof(uint8_t) * 12);
        if (response == NULL) {
          break;
        }
      }
    } else {
      if (pos >= 12) {
        pos -= 12;
        token = reql_get_64_token(response);
        size = reql_get_32_le(&response[8]);
        response = realloc(response, sizeof(uint8_t) * size);
        if (response == NULL) {
          break;
        }
        if (response == NULL) {
          reql_close_conn(conn);
        }
      }
    }
  }

  free(response);

  reql_conn_close_socket(conn);

  return NULL;
}

extern int
reql_connect(ReQL_Conn_t *conn, uint8_t *buf, const uint32_t size) {
  struct addrinfo hints;
  struct addrinfo *result, *rp;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  hints.ai_protocol = IPPROTO_TCP;

  if (getaddrinfo(conn->addr, conn->port, &hints, &result) != 0) {
    return -1;
  }

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    conn->socket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

    if (conn->socket == -1) continue;

    if (connect(conn->socket, rp->ai_addr, rp->ai_addrlen) != -1) break;

    close(conn->socket);
  }

  if (rp == NULL) {
    freeaddrinfo(result);
    conn->socket = -1;
    return -1;
  }

  freeaddrinfo(result);

  const struct timeval timeout = {conn->timeout, 0};

  if (setsockopt(conn->socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval))) {
    reql_close_conn(conn);
    reql_conn_close_socket(conn);
    return -1;
  }

  if (setsockopt(conn->socket, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(struct timeval))) {
    reql_close_conn(conn);
    reql_conn_close_socket(conn);
    return -1;
  }

  uint8_t iov_base[3][4];

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

  if (writev(conn->socket, magic, 4) != (conn->auth_size + 12)) {
    reql_close_conn(conn);
    reql_conn_close_socket(conn);
    return -1;
  }

  reql_conn_read(conn, buf, 8);

  if (memcmp(buf, "SUCCESS", 8) != 0) {
    reql_conn_read(conn, buf, size - 8);
    reql_close_conn(conn);
    reql_conn_close_socket(conn);
    return -1;
  }

  pthread_t thread;

  if (pthread_create(&thread, NULL, reql_conn_loop, conn) != 0) {
    reql_close_conn(conn);
    reql_conn_close_socket(conn);
    return -1;
  }

  if (pthread_detach(thread) != 0) {
    reql_ensure_conn_close(conn);
    return -1;
  }

  return 0;
}

extern void
reql_close_conn(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  conn->done = 1;
  reql_conn_unlock(conn);
}

extern void
reql_ensure_conn_close(ReQL_Conn_t *conn) {
  reql_close_conn(conn);
  while (reql_conn_socket(conn) > 0) {
    sleep(1);
  }
  pthread_mutex_destroy(conn->mutex);
  free(conn->mutex); conn->mutex = NULL;
}

extern char
reql_conn_open(const ReQL_Conn_t *conn) {
  return reql_conn_socket(conn) > 0 && !reql_conn_done(conn);
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
      uint32_t size = reql_size(query);
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
      uint32_t size = reql_size(query);
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

      reql_number_init(term, (double)reql_term_type(query));

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
      uint32_t size = reql_size(query);
      uint8_t *buf = malloc(sizeof(uint8_t) * size);
      reql_string_init(obj, buf, size);
      reql_string_append(obj, reql_string_buf(query), size);
      break;
    }
  }

  return obj;
}

extern int
reql_run(ReQL_Cur_t *cur, const ReQL_Obj_t *query, ReQL_Conn_t *conn, ReQL_Obj_t *kwargs) {
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

  if (wire_query == NULL) {
    return -1;
  }

  reql_conn_lock(conn);

  if (conn->socket < 0) {
    reql_conn_unlock(conn);
    return -1;
  }

  const uint64_t token = conn->max_token++;

  if (cur != NULL) {
    if (conn->cursors) {
      cur->next = conn->cursors;
      cur->next->prev = cur;
    }

    conn->cursors = cur;

    cur->conn = conn;
    cur->token = token;
  }

  uint8_t token_bytes[8];

  reql_make_64_token(token_bytes, token);

  uint8_t size[4];

  reql_make_32_le(size, wire_query->size);

  struct iovec magic[3];

  magic[0].iov_base = token_bytes;
  magic[0].iov_len = 8;

  magic[1].iov_base = size;
  magic[1].iov_len = 4;

  magic[2].iov_base = wire_query->str;
  magic[2].iov_len = wire_query->size;

  if (writev(conn->socket, magic, 3) != (wire_query->size + 12)) {
    reql_conn_unlock(conn);
    return -1;
  }

  reql_conn_unlock(conn);
  return 0;
}
