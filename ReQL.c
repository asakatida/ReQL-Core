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

static pthread_mutex_t conn_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_once_t init_lock = PTHREAD_ONCE_INIT;
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
_reql_get_32_le(char *buf) {
  _ReQL_LE32 _magic = {0};
  memcpy(_magic.buf, buf, 4);
  return le32toh(_magic.num);
}

static int64_t
_reql_get_64_token(char *buf) {
  _ReQL_LE64 _magic = {0};
  memcpy(_magic.buf, buf, 8);
  return le64toh(_magic.num);
}

static void
_reql_init_conn(void) {
  pthread_mutexattr_t *attrs = malloc(sizeof(pthread_mutexattr_t));

  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

  pthread_mutex_init(&conn_lock, attrs);

  pthread_mutexattr_destroy(attrs);

  free(attrs);
}

extern void
_reql_connection_init(_ReQL_Conn conn) {
  pthread_once(&init_lock, _reql_init_conn);

  conn->socket = -1;
  conn->done = 0;
  conn->max_token = 0;
  conn->cursors = NULL;
  conn->timeout = 20;
  conn->auth_size = 0;
  conn->auth = NULL;
  conn->port = "28015";
  conn->addr = NULL;
}

extern void
_reql_conn_set_auth(_ReQL_Conn_t *conn, uint32_t size, char *auth) {
  conn->auth_size = size;
  conn->auth = auth;
}

extern void
_reql_conn_set_addr(_ReQL_Conn_t *conn, char *addr) {
  conn->addr = addr;
}

extern void
_reql_conn_set_port(_ReQL_Conn_t *conn, char *port) {
  conn->port = port;
}

extern void
_reql_conn_set_timeout(_ReQL_Conn_t *conn, unsigned long timeout) {
  conn->timeout = timeout;
}

static int
_reql_conn_socket(_ReQL_Conn_t *conn) {
  pthread_mutex_lock(&conn_lock);
  int sock = conn->socket;
  pthread_mutex_unlock(&conn_lock);
  return sock;
}

static void
_reql_conn_close_socket(_ReQL_Conn_t *conn) {
  pthread_mutex_lock(&conn_lock);
  close(conn->socket);
  conn->socket = -1;
  pthread_mutex_unlock(&conn_lock);
}

static void
_reql_set_cur_res(_ReQL_Conn_t *conn, _ReQL_Op res, unsigned long long token) {
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
  pthread_mutex_lock(&conn_lock);
  char res = conn->done;
  pthread_mutex_unlock(&conn_lock);
  return res;
}

static void *
_reql_conn_loop(void *_conn) {
  _ReQL_Conn_t *conn = _conn;
  char msg_header[12];
  uint8_t *response = NULL;
  uint64_t token = 0;
  uint32_t pos = 0, size = 12;

  while (!_reql_conn_done(conn)) {
    pos += recvfrom(conn->socket, &response[pos], size, MSG_WAITALL, NULL, NULL);
    if (response) {
      if (pos == size) {
        _reql_set_cur_res(conn, _reql_decode(response, size), token);

        pos = 0;
        size = 12;

        free(response); response = NULL;
      }
    } else {
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
_reql_connect(_ReQL_Conn_t *conn, char *buf, size_t size) {
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

  recvfrom(conn->socket, buf, 8, MSG_WAITALL, NULL, NULL);

  if (strcmp(buf, "SUCCESS")) {
    recvfrom(conn->socket, buf, size - 8, MSG_WAITALL, NULL, NULL);
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
  pthread_mutex_lock(&conn_lock);
  conn->done = 1;
  pthread_mutex_unlock(&conn_lock);
}

extern void
_reql_ensure_conn_close(_ReQL_Conn_t *conn) {
  _reql_close_conn(conn);
  while (_reql_conn_socket(conn) > 0) {
    sleep(1);
  }
}

extern int
_reql_run(_ReQL_Cur cur, _ReQL_Op query, _ReQL_Conn conn, _ReQL_Op kwargs) {
  pthread_mutex_lock(&conn_lock);
  if (conn->cursors) {
    cur->next = conn->cursors;
    cur->next->prev = cur;
  }

  conn->cursors = cur;

  cur->conn = conn;
  cur->token = conn->max_token++;

  pthread_mutex_unlock(&conn_lock);
  return 0;
}
