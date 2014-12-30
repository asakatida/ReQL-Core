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

#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/uio.h>
#include <unistd.h>

static pthread_mutex_t *response_lock;
static pthread_once_t *init_lock = NULL;
static const unsigned int _REQL_VERSION = 0x5f75e83e;
static const unsigned int _REQL_PROTOCOL = 0x7e6970c7;

enum {
  _REQL_CONTINUE = 2,
  _REQL_NOREPLY_WAIT = 4,
  _REQL_START = 1,
  _REQL_STOP = 3
};

void _reql_make_magic(char *buf, size_t size, const unsigned long long magic) {
  size_t i;

  for (i=0; i<size; ++i) {
    buf[i] = (magic >> (8 * (size - i - 1))) & 0xff;
  }
}

void _reql_make_magic_32(char *buf, const unsigned long magic) {
  _reql_make_magic(buf, 4, htonl(magic));
}

void _reql_make_magic_64(char *buf, const unsigned long long magic) {
  _reql_make_magic(buf, 8, htonll(magic));
}

unsigned long long _reql_get_magic(char *buf, size_t size) {
  size_t i;
  unsigned long long magic = 0;

  for (i=size; i>1; --i) {
    magic |= buf[i];
    magic <<= 8;
  }

  magic |= buf[0];

  return magic;
}

unsigned long _reql_get_magic_32(char *buf) {
  return ntohl(_reql_get_magic(buf, 4));
}

unsigned long long _reql_get_magic_64(char *buf) {
  return ntohll(_reql_get_magic(buf, 8));
}

_ReQL_Cur_t *_reql_new_cursor() {
  _ReQL_Cur_t *cur = malloc(sizeof(_ReQL_Cur_t));
  cur->token = 0;
  cur->idx = 0;
  cur->next = cur->prev = cur;
  cur->conn = NULL;
  cur->response = NULL;
  cur->array = _reql_json_array(NULL);
  cur->iter = _reql_to_array(cur->array);
  return cur;
}

_ReQL_Conn_t *_reql_new_connection(_ReQL_Conn_t *conn) {
  if (!conn) {
    conn = malloc(sizeof(_ReQL_Conn_t));
  }

  conn->socket = -1;
  conn->error = 0;
  conn->max_token = 0;
  conn->cursors = _reql_new_cursor();
  conn->timeout = 20;
  conn->auth_size = 0;
  conn->auth = NULL;
  conn->port = "28015";
  conn->addr = NULL;

  return conn;
}

int _reql_conn_set_auth(_ReQL_Conn_t *conn, unsigned int size, char *auth) {
  conn->auth_size = size;
  conn->auth = auth;

  return 0;
}

int _reql_conn_set_addr(_ReQL_Conn_t *conn, char *addr) {
  conn->addr = addr;

  return 0;
}

int _reql_conn_set_port(_ReQL_Conn_t *conn, char *port) {
  conn->port = port;

  return 0;
}

int _reql_conn_set_timeout(_ReQL_Conn_t *conn, unsigned long timeout) {
  conn->timeout = timeout;

  return 0;
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

  conn->error = -1;
}

_ReQL_Op _reql_get_cur_res(_ReQL_Cur_t *cur) {
  _ReQL_Op res = NULL;

  while (1) {
    pthread_mutex_lock(response_lock);
    if (cur->response) {
      res = _reql_expr_copy(cur->response);
      pthread_mutex_unlock(response_lock);
      break;
    }
    pthread_mutex_unlock(response_lock);
    sleep(1);
  }

  return res;
}

void _reql_end_cur_res(_ReQL_Conn_t *conn, _ReQL_Op res, unsigned long long token) {
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

  conn->error = -1;
}

void *_reql_conn_loop(void *_conn) {
  _ReQL_Conn_t *conn = _conn;
  char msg_header[12];
  char *response = NULL;
  unsigned long long token = 0;
  long pos = 0, size = 0;

  while (conn->socket > 0) {
    if (response) {
      pos += recvfrom(conn->socket, &response[pos], size, MSG_WAITALL, NULL, NULL);
      if (pos == size) {
        _ReQL_String_t *json = _reql_string(NULL, response, size);
        _reql_set_cur_res(conn, _reql_json_decode(json), token);
        pos = 0;
        free(response); response = NULL;
      }
    } else {
      pos += recvfrom(conn->socket, &msg_header[pos], 12, MSG_WAITALL, NULL, NULL);
      if (pos == 12) {
        pos = 0;
        token = _reql_get_magic_64(&msg_header[0]);
        size = _reql_get_magic_32(&msg_header[8]);
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

int _reql_connect(_ReQL_Conn_t *conn, char **buf) {
  conn->error = -1;

  struct addrinfo hints;
  struct addrinfo *result, *rp;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  hints.ai_protocol = IPPROTO_TCP;

  if (getaddrinfo(conn->addr, conn->port, &hints, &result)) {
    return conn->error;
  }

  for (rp = result; rp != NULL; rp = rp->ai_next) {
    conn->socket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

    if (conn->socket == -1) continue;

    if (connect(conn->socket, rp->ai_addr, rp->ai_addrlen) != -1) break;

    close(conn->socket);
  }

  if (!rp) {
    return conn->error;
  }

  freeaddrinfo(result);

  struct timeval timeout;

  timeout.tv_sec = conn->timeout;
  timeout.tv_usec = 0;

  if (setsockopt(conn->socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout))) {
    return conn->error;
  }

  if (setsockopt(conn->socket, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout))) {
    return conn->error;
  }

  char iov_base[3][4];

  _reql_make_magic_32(iov_base[0], _REQL_VERSION);
  _reql_make_magic_32(iov_base[1], conn->auth_size);
  _reql_make_magic_32(iov_base[2], _REQL_PROTOCOL);

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

  *buf = malloc(sizeof(char) * 500);

  conn->error = 0;

  recvfrom(conn->socket, *buf, 8, MSG_WAITALL, NULL, NULL);

  if (strcmp(*buf, "SUCCESS")) {
    recvfrom(conn->socket, *buf, 500, MSG_WAITALL, NULL, NULL);
    conn->error = -1 | _reql_close_conn(conn);
  }

  pthread_t thread;

  pthread_once(init_lock, _reql_init);

  if (pthread_create(&thread, NULL, _reql_conn_loop, conn)) {
    conn->error = -1;
  }

  if (pthread_detach(thread)) {
    conn->error = -1;
  }

  return conn->error;
}

void _reql_free_cur(_ReQL_Cur_t *cur) {
  while (cur != cur->prev) {
    cur = cur->prev;
  }
  while (cur != cur->next) {
    cur = cur->next;
    _reql_close_cur(cur->prev);
  }
  _reql_close_cur(cur);
}

int _reql_close_conn(_ReQL_Conn_t *conn) {
  conn->max_token = 0;
  _reql_free_cur(conn->cursors);
  conn->cursors = _reql_new_cursor();
  conn->error = close(conn->socket); conn->socket = -1;
  return conn->error;
}

void _reql_free_conn(_ReQL_Conn_t *conn) {
  _reql_free_cur(conn->cursors);
  free(conn); conn = NULL;
}

_ReQL_Cur_t *_reql_run(_ReQL_Op query, _ReQL_Conn_t *conn, _ReQL_Op kwargs) {
  _ReQL_Cur_t *cur = conn->cursors;

  while (cur->next != cur) {
    cur = cur->next;
  }

  if (cur->response) {
    cur->next = _reql_new_cursor();
    cur->next->prev = cur;
    cur = cur->next;
  }

  cur->conn = conn;
  cur->token = conn->max_token++;

  _reql_build(query);

  return cur;
}

void _reql_cursor_next(_ReQL_Cur_t *cur) {
  cur->response = _reql_expr_null();
}

void _reql_close_cur(_ReQL_Cur_t *cur) {
  if (!cur) {
    return;
  }

  cur->prev->next = cur->next == cur ? cur->prev : cur->next;
  cur->next->prev = cur->prev == cur ? cur->next : cur->prev;
  free(cur); cur = NULL;
}
