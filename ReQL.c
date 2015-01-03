/*
Copyright 2014 Adam Grandquist

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

#ifndef htole32
#ifdef OSSwapHostToLittleConstInt32
#define htole32 OSSwapHostToLittleConstInt32
#else
#error need to provide htole32 for this platform
#endif
#endif

#ifndef le32toh
#ifdef OSSwapLittleToHostConstInt32
#define le32toh OSSwapLittleToHostConstInt32
#else
#error need to provide le32toh for this platform
#endif
#endif

static pthread_mutex_t *response_lock;
static pthread_mutex_t *conn_lock;
static pthread_once_t *init_lock = NULL;
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

void _reql_make_32_le(uint8_t *buf, const uint32_t magic) {
  _ReQL_LE32 _magic = {htole32(magic)};
  memcpy(buf, _magic.buf, 4);
}

void _reql_make_64_token(uint8_t *buf, const uint64_t magic) {
  _ReQL_LE64 _magic = {magic};
  memcpy(buf, _magic.buf, 8);
}

uint32_t _reql_get_32_le(char *buf) {
  _ReQL_LE32 _magic = {0};
  memcpy(_magic.buf, buf, 4);
  return le32toh(_magic.num);
}

uint64_t _reql_get_64_token(char *buf) {
  _ReQL_LE64 _magic = {0};
  memcpy(_magic.buf, buf, 8);
  return _magic.num;
}

void _reql_cursor_init(_ReQL_Cur cur, _ReQL_Op arr, _ReQL_Iter iter) {
  cur->token = 0;
  cur->done = 0;
  cur->next = cur->prev = cur;
  cur->conn = NULL;
  cur->response = NULL;
  cur->array = arr;
  cur->iter = iter;
}

void _reql_connection_init(_ReQL_Conn conn) {
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

void _reql_conn_set_auth(_ReQL_Conn_t *conn, unsigned int size, char *auth) {
  conn->auth_size = size;
  conn->auth = auth;
}

void _reql_conn_set_addr(_ReQL_Conn_t *conn, char *addr) {
  conn->addr = addr;
}

void _reql_conn_set_port(_ReQL_Conn_t *conn, char *port) {
  conn->port = port;
}

void _reql_conn_set_timeout(_ReQL_Conn_t *conn, unsigned long timeout) {
  conn->timeout = timeout;
}

void _reql_set_cur_res(_ReQL_Conn_t *conn, _ReQL_Op res, unsigned long long token) {
  _ReQL_Cur_t *cur = conn->cursors;

  if (cur->token == token) {
    pthread_mutex_lock(response_lock);
    cur->response = res;
    pthread_mutex_unlock(response_lock);
    return;
  }

  while (cur->next != cur) {
    cur = cur->next;
    if (cur->token == token) {
      pthread_mutex_lock(response_lock);
      cur->response = res;
      pthread_mutex_unlock(response_lock);
      return;
    }
  }
}

_ReQL_Op _reql_get_cur_res(_ReQL_Cur_t *cur) {
  _ReQL_Op res = NULL;

  while (1) {
    pthread_mutex_lock(response_lock);
    if (cur->response) {
      res = cur->response;
      cur->response = NULL;
      pthread_mutex_unlock(response_lock);
      break;
    }
    pthread_mutex_unlock(response_lock);
    sleep(1);
  }

  return res;
}

void _reql_end_cur_res(_ReQL_Conn_t *conn, _ReQL_Op res, uint64_t token) {
  _ReQL_Cur_t *cur = conn->cursors;

  if (cur->token == token) {
    pthread_mutex_lock(response_lock);
    cur->response = res;
    pthread_mutex_unlock(response_lock);
    return;
  }

  while (cur->next != cur) {
    cur = cur->next;
    if (cur->token == token) {
      pthread_mutex_lock(response_lock);
      cur->response = res;
      pthread_mutex_unlock(response_lock);
      return;
    }
  }
}

void *_reql_conn_loop(void *_conn) {
  _ReQL_Conn_t *conn = _conn;
  char msg_header[12];
  uint8_t *response = NULL;
  uint64_t token = 0;
  uint32_t pos = 0, size = 12;

  while (1) {
    pthread_mutex_lock(conn_lock);
    if (conn->socket < 0) {
      pthread_mutex_unlock(conn_lock);
      break;
    }
    pthread_mutex_unlock(conn_lock);
    pos += recvfrom(conn->socket, &response[pos], size, MSG_WAITALL, NULL, NULL);
    if (response) {
      if (pos == size) {
        _ReQL_Op json = malloc(sizeof(_ReQL_Op_t));

        _reql_string_init(json, response, size);
        _reql_set_cur_res(conn, _reql_decode(json), token);

        pos = 0;
        size = 12;

        free(json); json = NULL;
        free(response); response = NULL;
      }
    } else {
      if (pos == 12) {
        pos = 0;
        token = _reql_get_64_token(&msg_header[0]);
        size = _reql_get_32_le(&msg_header[8]);
        response = malloc(sizeof(char) * size);
        if (!response) {
          return NULL;
        }
      }
    }
  }

  return NULL;
}

void _reql_init(void) {
  pthread_mutexattr_t *attrs = NULL;

  pthread_mutexattr_init(attrs);
  pthread_mutexattr_settype(attrs, PTHREAD_MUTEX_ERRORCHECK);

  pthread_mutex_init(response_lock, attrs);

  pthread_mutexattr_destroy(attrs);
}

int _reql_connect(_ReQL_Conn_t *conn, char *buf, size_t size) {
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
    return -1;
  }

  freeaddrinfo(result);

  struct timeval timeout;

  timeout.tv_sec = conn->timeout;
  timeout.tv_usec = 0;

  if (setsockopt(conn->socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout))) {
    return -1;
  }

  if (setsockopt(conn->socket, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout))) {
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
    return -1;
  }

  pthread_t thread;

  pthread_once(init_lock, _reql_init);

  if (pthread_create(&thread, NULL, _reql_conn_loop, conn)) {
    _reql_close_conn(conn);
    return -1;
  }

  if (pthread_detach(thread)) {
    _reql_close_conn(conn);
    return -1;
  }

  return -1;
}

void _reql_close_conn(_ReQL_Conn_t *conn) {
  conn->done = 1;
}

int _reql_run(_ReQL_Cur cur, _ReQL_Op query, _ReQL_Conn conn, _ReQL_Op kwargs) {
  if (conn->cursors) {
    cur->next = conn->cursors;
    cur->next->prev = cur;
  }

  conn->cursors = cur;

  cur->conn = conn;
  cur->token = conn->max_token++;

  return 0;
}

void _reql_cursor_next(_ReQL_Cur_t *cur) {
}

void _reql_close_cur(_ReQL_Cur cur) {
  cur->prev->next = cur->next == cur ? cur->prev : cur->next;
  cur->next->prev = cur->prev == cur ? cur->next : cur->prev;
}
