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

#include "./reql/encode.hpp"

#include "./reql/cursor.h"
#include "./reql/error.h"
#include "./reql/portable_endian.h"
#include "./reql/query.h"
#include "./reql/types.h"

#include <memory>
#include <sstream>
#include <string>

#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
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

static void
reql_make_32_le(ReQL_Byte *buf, const ReQL_Size magic) {
  ReQL_LE32 convert = {htole32(magic)};
  memcpy(buf, convert.buf, sizeof(ReQL_Byte) * 4);
}

static void
reql_make_64_token(ReQL_Byte *buf, const ReQL_Token magic) {
  ReQL_LE64 convert = {htole64(magic)};
  memcpy(buf, convert.buf, sizeof(ReQL_Byte) * 8);
}

static ReQL_Size
reql_get_32_le(ReQL_Byte *buf) {
  ReQL_LE32 convert = {0};
  memcpy(convert.buf, buf, sizeof(ReQL_Byte) * 4);
  return le32toh(convert.num);
}

static ReQL_Token
reql_get_64_token(ReQL_Byte *buf) {
  ReQL_LE64 convert = {0};
  memcpy(convert.buf, buf, sizeof(ReQL_Byte) * 8);
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
reql_conn_lock(ReQL_Conn_t *conn) {
  if (conn->condition.mutex == nullptr) {
    return;
  }
  pthread_mutex_lock(conn->condition.mutex);
}

static void
reql_conn_unlock(ReQL_Conn_t *conn) {
  if (conn == nullptr) {
    return;
  }
  if (conn->condition.mutex == nullptr) {
    return;
  }
  pthread_mutex_unlock(conn->condition.mutex);
}

extern void
reql_conn_init(ReQL_Conn_t *conn) {
  pthread_mutexattr_t *attrs;
  try {
    attrs = new pthread_mutexattr_t;
  } catch (std::bad_alloc&) {
    reql_conn_memory_error(__func__);
    return;
  }
  pthread_mutex_t *mutex;
  try {
    mutex = new pthread_mutex_t;
  } catch (std::bad_alloc&) {
    delete attrs;
    reql_conn_memory_error(__func__);
    return;
  }
  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);
  pthread_mutex_init(mutex, attrs);
  pthread_mutexattr_destroy(attrs);
  delete attrs;

  memset(conn, static_cast<int>(NULL), sizeof(ReQL_Conn_t));

  conn->condition.mutex = mutex;

  reql_conn_lock(conn);
  conn->socket = -1;
  conn->timeout_s = 20;
  conn->port = reinterpret_cast<void *>(const_cast<char *>("28015"));
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
  char *port = reinterpret_cast<char *>(conn->port);
  reql_conn_unlock(conn);
  return port;
}

extern void
reql_conn_set_timeout(ReQL_Conn_t *conn, const ReQL_Token s, const ReQL_Token us) {
  reql_conn_lock(conn);
  conn->timeout_s = s;
  conn->timeout_us = us;
  reql_conn_unlock(conn);
}

extern ReQL_Token
reql_conn_timeout(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  const ReQL_Token timeout = conn->timeout_s;
  reql_conn_unlock(conn);
  return timeout;
}

static int
reql_conn_socket(const ReQL_Conn_t *conn) {
  return conn->socket;
}

static void
reql_conn_close_(ReQL_Conn_t *conn) {
  int sock = reql_conn_socket(conn);
  conn->socket = -1;
  if (sock >= 0) {
    close(sock);
  }
}

static void *
reql_conn_loop(void *data) {
  ReQL_Conn_t *conn = reinterpret_cast<ReQL_Conn_t *>(data);
  ReQL_Token token = 0;
  ReQL_Size pos = 0, size = 0;

  reql_conn_lock(conn);

  ReQL_Byte *response;
  try {
    response = new ReQL_Byte[12];
  } catch (std::bad_alloc&) {
    reql_conn_close_(conn);
  }

  while (reql_conn_socket(conn) >= 0) {
    if (conn->cursors == nullptr) {
      reql_conn_unlock(conn);
      sched_yield();
      reql_conn_lock(conn);
      continue;
    }

    size_t rcv_size_request = (size > 0 ? size : 12) - pos;
    ssize_t rcv_size = recvfrom(reql_conn_socket(conn), &response[pos], rcv_size_request, 0, nullptr, nullptr);
    reql_conn_unlock(conn);

    if (rcv_size < 0) {
    } else if (static_cast<size_t>(rcv_size) == rcv_size_request) {
      pos += rcv_size;
    } else {
      pos += rcv_size;
    }

    if (size > 0) {
      if (pos >= size) {
        reql_conn_lock(conn);
        ReQL_Cur_t *cur = conn->cursors;
        if (cur == nullptr) {
          break;
        }
        while (1) {
          if (cur->token == token) {
            reql_cur_set_response(cur, response, size);
            break;
          } else if (cur->next == cur) {
            reql_conn_close_(conn);
            break;
          } else {
            cur = cur->next;
          }
        }
        reql_conn_unlock(conn);

        pos -= size;

        ReQL_Byte *buf;
        try {
          buf = new ReQL_Byte[12];
        } catch (std::bad_alloc&) {
          break;
        }
        memcpy(buf, &response[size], sizeof(ReQL_Byte) * pos);
        delete []response;
        response = buf;

        size = 0;
      }
    } else if (pos >= 12) {
      pos -= 12;
      token = reql_get_64_token(response);
      size = reql_get_32_le(&response[8]);
      ReQL_Byte *buf;
      try {
        buf = new ReQL_Byte[size];
      } catch (std::bad_alloc&) {
        break;
      }
      memcpy(buf, &response[12], sizeof(ReQL_Byte) * pos);
      delete []response;
      response = buf;
    }
    reql_conn_lock(conn);
  }

  reql_conn_close_(conn);

  reql_conn_unlock(conn);

  delete []response;

  return nullptr;
}

static int
reql_connect_(ReQL_Conn_t *conn, ReQL_Byte *buf, const ReQL_Size size) {
  struct addrinfo hints;
  struct addrinfo *result, *rp;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  hints.ai_protocol = IPPROTO_TCP;

  if (getaddrinfo(conn->addr, reinterpret_cast<char *>(conn->port), &hints, &result) != 0) {
    return -1;
  }

  int sock = -1;

  for (rp = result; rp != nullptr; rp = rp->ai_next) {
    sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

    if (sock == -1) continue;

    if (connect(sock, rp->ai_addr, rp->ai_addrlen) != -1) break;

    close(sock);
  }

  if (rp == nullptr) {
    freeaddrinfo(result);
    return -1;
  }

  freeaddrinfo(result);

  {
    const struct timeval timeout = {static_cast<time_t>(conn->timeout_s), static_cast<suseconds_t>(conn->timeout_us)};

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval))) {
      return -1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(struct timeval))) {
      return -1;
    }
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

  const ssize_t rcv_size = recvfrom(sock, buf, 8, 0, nullptr, nullptr);

  if (rcv_size < 0) {
    return -1;
  } else if (rcv_size != 8) {
    return -1;
  } else if (memcmp(buf, "SUCCESS", 8) != 0) {
    recvfrom(sock, &buf[8], size - 8, 0, nullptr, nullptr);
    return -1;
  }

  {
    const struct timeval timeout = {0, 1};

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval))) {
      return -1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(struct timeval))) {
      return -1;
    }
  }

  conn->socket = sock;

  if (pthread_create(&conn->condition.thread, nullptr, reql_conn_loop, conn) != 0) {
    return -1;
  }

  return 0;
}

extern int
reql_conn_connect(ReQL_Conn_t *conn, ReQL_Byte *buf, const ReQL_Size size) {
  reql_conn_lock(conn);
  const int status = reql_connect_(conn, buf, size);
  reql_conn_unlock(conn);
  if (status != 0) {
    reql_conn_close(conn);
  }
  return status;
}

extern void
reql_conn_close(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  reql_conn_close_(conn);
  reql_conn_unlock(conn);
}

extern void
reql_conn_destroy(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  reql_conn_close_(conn);
  while (conn->cursors != nullptr) {
    reql_cur_close(conn->cursors);
  }
  reql_conn_unlock(conn);
  if (conn->condition.thread != nullptr) {
    pthread_join(conn->condition.thread, nullptr);
    conn->condition.thread = nullptr;
  }
  conn->condition.thread = nullptr;
  if (conn->condition.mutex != nullptr) {
    pthread_mutex_destroy(conn->condition.mutex);
  }
  delete conn->condition.mutex; conn->condition.mutex = nullptr;
}

extern char
reql_conn_open(ReQL_Conn_t *conn) {
  reql_conn_lock(conn);
  const char open = reql_conn_socket(conn) >= 0;
  reql_conn_unlock(conn);
  return open;
}

static int
reql_run_query_(const std::string &wire_query, ReQL_Conn_t *conn, const ReQL_Token token) {
  auto size = wire_query.size();

  if (size > UINT32_MAX) {
    return -1;
  }

  ReQL_Byte token_bytes[8];

  reql_make_64_token(token_bytes, token);

  ReQL_Byte size_buf[4];
  reql_make_32_le(size_buf, static_cast<ReQL_Size>(size));

  struct iovec magic[3];

  magic[0].iov_base = token_bytes;
  magic[0].iov_len = 8;

  magic[1].iov_base = size_buf;
  magic[1].iov_len = 4;

  magic[2].iov_base = std::unique_ptr<char>(new char[size]).get();
  magic[2].iov_len = wire_query.size();

  reql_conn_lock(conn);
  int sock = reql_conn_socket(conn);
  if (sock < 0) {
    reql_conn_unlock(conn);
    return -1;
  }
  if (writev(sock, magic, 3) != static_cast<ssize_t>(size + 12)) {
    reql_conn_unlock(conn);
    return -1;
  }
  reql_conn_unlock(conn);

  return 0;
}

static void
reql_encode_constant_query(std::stringstream &wire_query, const enum ReQL_Query_e type) {
  wire_query << "[" << type << "]";
}

extern int
reql_continue_query(ReQL_Cur_t *cur) {
  std::stringstream wire_query;

  try {
    reql_encode_constant_query(wire_query, REQL_CONTINUE);
  } catch (std::exception) {
    return -1;
  }

  return reql_run_query_(wire_query.str(), cur->conn, cur->token);
}

static int
_event(ReQL_Parse_t *, const char *, size_t) {
  return 0;
}

template <typename type>
static int
_event(ReQL_Parse_t *, type) {
  return 0;
}

static int
_event(ReQL_Parse_t *) {
  return 0;
}

static void
_error(ReQL_Parse_t *p) {
  p->data = nullptr;
}

static ReQL_Parse_t
reql_get_parser() {
  ReQL_Parse_t p;
  p.add_bool = _event;
  p.add_null = _event;
  p.add_number = _event;
  p.add_string = _event;
  p.data = &p;
  p.end_array = _event;
  p.end_element = _event;
  p.end_key_value = _event;
  p.end_object = _event;
  p.end_parse = _event;
  p.error = _error;
  p.start_array = _event;
  p.start_element = _event;
  p.start_key_value = _event;
  p.start_object = _event;
  p.start_parse = _event;
  return p;
}

extern int
reql_no_reply_wait_query(ReQL_Conn_t *conn) {
  std::stringstream wire_query;
  try {
    reql_encode_constant_query(wire_query, REQL_NOREPLY_WAIT);
  } catch (std::exception) {
    return -1;
  }

  ReQL_Cur_t *cur;
  try {
    cur = new ReQL_Cur_t;
  } catch (std::bad_alloc&) {
    return -1;
  }

  reql_conn_lock(conn);
  const ReQL_Token token = conn->max_token++;
  reql_cur_init(cur, conn, token, reql_get_parser);
  conn->cursors = cur;
  reql_conn_unlock(conn);

  const int status = reql_run_query_(wire_query.str(), conn, token);

  if (status == 0) {
    reql_cur_drain(cur);
  }

  reql_cur_destroy(cur);
  delete cur;

  return status;
}

extern int
reql_stop_query(ReQL_Cur_t *cur) {
  std::stringstream wire_query;
  try {
    reql_encode_constant_query(wire_query, REQL_STOP);
  } catch (std::exception) {
    return -1;
  }
  return reql_run_query_(wire_query.str(), cur->conn, cur->token);
}

extern int
reql_run_query(ReQL_Cur_t *cur, ReQL_Obj_t *query, ReQL_Conn_t *conn, ReQL_Obj_t *kwargs, ReQL_Parse_t (*get_parser)()) {
  ReQL_Obj_t start;

  ReQL_Obj_t array;
  ReQL_Obj_t *arr[3];

  reql_number_init(&start, REQL_START);
  reql_array_init(&array, arr, 3);
  reql_array_append(&array, &start);

  reql_array_append(&array, query);

  reql_array_append(&array, kwargs);

  std::string wire_query;
  try {
    wire_query = reql_encode(&array);
  } catch (std::exception) {
    return -1;
  }

  reql_conn_lock(conn);
  const ReQL_Token token = conn->max_token++;
  if (cur != nullptr) {
    reql_cur_init(cur, conn, token, get_parser);
    conn->cursors = cur;
  }
  reql_conn_unlock(conn);

  const int status = reql_run_query_(wire_query, conn, token);

  return status;
}
