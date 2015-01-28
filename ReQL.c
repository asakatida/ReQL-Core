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

static const uint32_t _REQL_VERSION = 0x5f75e83e;
static const uint32_t _REQL_PROTOCOL = 0x7e6970c7;

enum {
  _REQL_CONTINUE = 2,
  _REQL_NOREPLY_WAIT = 4,
  _REQL_START = 1,
  _REQL_STOP = 3
};

typedef union {
  uint32_t num;
  uint8_t buf[4];
} _ReQL_LE32;

typedef union {
  uint64_t num;
  uint8_t buf[8];
} _ReQL_LE64;

static void
_reql_make_32_le(uint8_t *buf, const uint32_t magic) {
  _ReQL_LE32 _magic = {htole32(magic)};
  memcpy(buf, _magic.buf, 4);
}

static void
_reql_make_64_token(uint8_t *buf, const uint64_t magic) {
  _ReQL_LE64 _magic = {htole64(magic)};
  memcpy(buf, _magic.buf, 8);
}

static uint32_t
_reql_get_32_le(uint8_t *buf) {
  _ReQL_LE32 _magic = {0};
  memcpy(_magic.buf, buf, 4);
  return le32toh(_magic.num);
}

static int64_t
_reql_get_64_token(uint8_t *buf) {
  _ReQL_LE64 _magic = {0};
  memcpy(_magic.buf, buf, 8);
  return le64toh(_magic.num);
}

static int
_reql_conn_lock(_ReQL_Conn_t *conn) {
  return pthread_mutex_lock(conn->mutex);
}

static int
_reql_conn_unlock(_ReQL_Conn_t *conn) {
  return pthread_mutex_unlock(conn->mutex);
}

extern void
_reql_connection_init(_ReQL_Conn_t *conn) {
  pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));

  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

  conn->mutex = malloc(sizeof(pthread_mutex_t));

  pthread_mutex_init(conn->mutex, attrs);

  pthread_mutexattr_destroy(attrs);

  free(attrs); attrs = NULL;

  pthread_mutex_lock(conn->mutex);
  conn->socket = -1;
  conn->done = 0;
  conn->max_token = 0;
  conn->cursors = NULL;
  conn->timeout = 20;
  conn->auth_size = 0;
  conn->auth = NULL;
  conn->port = "28015";
  conn->addr = NULL;
  pthread_mutex_unlock(conn->mutex);
}

extern void
_reql_conn_set_auth(_ReQL_Conn_t *conn, uint32_t size, char *auth) {
  _reql_conn_lock(conn);
  conn->auth_size = size;
  conn->auth = auth;
  _reql_conn_unlock(conn);
}

extern void
_reql_conn_set_addr(_ReQL_Conn_t *conn, char *addr) {
  _reql_conn_lock(conn);
  conn->addr = addr;
  _reql_conn_unlock(conn);
}

extern void
_reql_conn_set_port(_ReQL_Conn_t *conn, char *port) {
  _reql_conn_lock(conn);
  conn->port = port;
  _reql_conn_unlock(conn);
}

extern void
_reql_conn_set_timeout(_ReQL_Conn_t *conn, unsigned long timeout) {
  _reql_conn_lock(conn);
  conn->timeout = timeout;
  _reql_conn_unlock(conn);
}

static int
_reql_conn_socket(_ReQL_Conn_t *conn) {
  _reql_conn_lock(conn);
  int sock = conn->socket;
  _reql_conn_unlock(conn);
  return sock;
}

static void
_reql_conn_close_socket(_ReQL_Conn_t *conn) {
  _reql_conn_lock(conn);
  close(conn->socket);
  conn->socket = -1;
  _reql_conn_unlock(conn);
}

static void
_reql_set_cur_res(_ReQL_Conn_t *conn, _ReQL_Obj_t *res, unsigned long long token) {
  _ReQL_Cur_t *cur = conn->cursors;

  if (cur->token == token) {
    return _reql_set_cur_response(cur, res);
  }

  while (cur->next != cur) {
    cur = cur->next;
    if (cur->token == token) {
      return _reql_set_cur_response(cur, res);
    }
  }
}

static char
_reql_conn_done(_ReQL_Conn_t *conn) {
  _reql_conn_lock(conn);
  char res = conn->done;
  _reql_conn_unlock(conn);
  return res;
}

static uint32_t
_reql_conn_read(_ReQL_Conn_t *conn, uint8_t *buf, const uint32_t size) {
  const ssize_t rcv_size = recvfrom(_reql_conn_socket(conn), buf, size, 0, NULL, NULL);

  if (rcv_size != size) {
  }

  return (uint32_t)rcv_size;
}

static void *
_reql_conn_loop(void *conn) {
  uint8_t msg_header[12];
  uint8_t *response = NULL;
  uint64_t token = 0;
  uint32_t pos = 0, size = 12;

  while (!_reql_conn_done(conn)) {
    if (response) {
      pos += _reql_conn_read(conn, &response[pos], size);
      if (pos == size) {
        _reql_set_cur_res(conn, _reql_decode(response, size), token);

        pos = 0;

        free(response); response = NULL;
      }
    } else {
      pos += _reql_conn_read(conn, msg_header, 12);
      if (pos == 12) {
        pos = 0;
        token = _reql_get_64_token(&msg_header[0]);
        size = _reql_get_32_le(&msg_header[8]);
        response = malloc(sizeof(uint8_t) * size);
        if (response == NULL) {
          _reql_close_conn(conn);
        }
      }
    }
  }

  _reql_conn_close_socket(conn);

  return NULL;
}

extern int
_reql_connect(_ReQL_Conn_t *conn, uint8_t *buf, uint32_t size) {
  struct addrinfo hints;
  struct addrinfo *result, *rp;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  hints.ai_protocol = IPPROTO_TCP;

  if (getaddrinfo(conn->addr, conn->port, &hints, &result)) {
    return -1;
  }

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    conn->socket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

    if (conn->socket == -1) continue;

    if (connect(conn->socket, rp->ai_addr, rp->ai_addrlen) != -1) break;

    close(conn->socket);
  }

  if (!rp) {
    freeaddrinfo(result);
    conn->socket = -1;
    return -1;
  }

  freeaddrinfo(result);

  struct timeval timeout;

  timeout.tv_sec = conn->timeout;
  timeout.tv_usec = 0;

  if (setsockopt(conn->socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout))) {
    _reql_close_conn(conn);
    _reql_conn_close_socket(conn);
    return -1;
  }

  if (setsockopt(conn->socket, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout))) {
    _reql_close_conn(conn);
    _reql_conn_close_socket(conn);
    return -1;
  }

  uint8_t iov_base[3][4];

  _reql_make_32_le(iov_base[0], _REQL_VERSION);
  _reql_make_32_le(iov_base[1], conn->auth_size);
  _reql_make_32_le(iov_base[2], _REQL_PROTOCOL);

  struct iovec magic[4];

  magic[0].iov_base = iov_base[0];
  magic[0].iov_len = 4;

  magic[1].iov_base = iov_base[1];
  magic[1].iov_len = 4;

  magic[2].iov_base = conn->auth;
  magic[2].iov_len = conn->auth_size;

  magic[3].iov_base = iov_base[2];
  magic[3].iov_len = 4;

  writev(conn->socket, magic, 4);

  _reql_conn_read(conn, buf, 8);

  if (memcmp(buf, "SUCCESS", 8) != 0) {
    _reql_conn_read(conn, buf, size - 8);
    _reql_close_conn(conn);
    _reql_conn_close_socket(conn);
    return -1;
  }

  pthread_t thread;

  if (pthread_create(&thread, NULL, _reql_conn_loop, conn)) {
    _reql_close_conn(conn);
    _reql_conn_close_socket(conn);
    return -1;
  }

  if (pthread_detach(thread)) {
    _reql_ensure_conn_close(conn);
    return -1;
  }

  return 0;
}

extern void
_reql_close_conn(_ReQL_Conn_t *conn) {
  _reql_conn_lock(conn);
  conn->done = 1;
  _reql_conn_unlock(conn);
}

extern void
_reql_ensure_conn_close(_ReQL_Conn_t *conn) {
  _reql_close_conn(conn);
  while (_reql_conn_socket(conn) > 0) {
    sleep(1);
  }
  pthread_mutex_destroy(conn->mutex);
  free(conn->mutex);
}

extern char
_reql_conn_open(_ReQL_Conn_t *conn) {
  return _reql_conn_socket(conn) > 0 && !_reql_conn_done(conn);
}

extern int
_reql_run(_ReQL_Cur_t *cur, _ReQL_Obj_t *query, _ReQL_Conn_t *conn, _ReQL_Obj_t *kwargs) {
  _ReQL_Obj_t start;

  _ReQL_Obj_t array;
  _ReQL_Obj_t *arr[3];

  _reql_number_init(&start, _REQL_START);
  _reql_array_init(&array, arr, 3);
  _reql_array_insert(&array, &start, 0);
  _reql_array_insert(&array, query, 1);
  _reql_array_insert(&array, kwargs, 2);

  _ReQL_String_t *_query = _reql_encode(&array);

  if (_query == NULL) {
    return -1;
  }

  _reql_conn_lock(conn);

  if (conn->socket < 0) {
    _reql_conn_unlock(conn);
    return -1;
  }

  if (conn->cursors) {
    cur->next = conn->cursors;
    cur->next->prev = cur;
  }

  conn->cursors = cur;

  cur->conn = conn;
  cur->token = conn->max_token++;

  uint8_t token[8];

  _reql_make_64_token(token, cur->token);

  uint8_t size[4];

  _reql_make_32_le(size, _query->size);

  struct iovec magic[3];

  magic[0].iov_base = token;
  magic[0].iov_len = 8;

  magic[1].iov_base = size;
  magic[1].iov_len = 4;

  magic[2].iov_base = _query->str;
  magic[2].iov_len = _query->size;

  writev(conn->socket, magic, 3);

  _reql_conn_unlock(conn);
  return 0;
}
