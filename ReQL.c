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
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/uio.h>
#include <unistd.h>

static const unsigned int _REQL_VERSION = 0x5f75e83e;
static const unsigned int _REQL_PROTOCOL = 0x7e6970c7;

enum {
  _REQL_CONTINUE = 2,
  _REQL_NOREPLY_WAIT = 4,
  _REQL_START = 1,
  _REQL_STOP = 3
};

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
  conn->timeout = malloc(sizeof(struct timeval));
  conn->timeout->tv_sec = 20;
  conn->timeout->tv_usec = 0;
  conn->auth_len = 0;
  conn->auth = NULL;
  conn->port = "28015";
  conn->addr = NULL;

  return conn;
}

int _reql_conn_set_auth(_ReQL_Conn_t *conn, unsigned int len, char *auth) {
  conn->auth_len = len;
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
  conn->timeout->tv_sec = timeout;

  return 0;
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

  unsigned int j;
  char iov_base[3][4];

  const unsigned int version = htonl(_REQL_VERSION);

  for (j=0; j<4; ++j) {
    iov_base[0][j] = (version << (8 * (3 - j))) & 0xff;
  }

  const unsigned int auth_len = htonl(conn->auth_len);

  for (j=0; j<4; ++j) {
    iov_base[1][j] = (auth_len << (8 * (3 - j))) & 0xff;
  }

  const unsigned int protocol = htonl(_REQL_PROTOCOL);

  for (j=0; j<4; ++j) {
    iov_base[2][j] = (protocol << (8 * (3 - j))) & 0xff;
  }

  struct iovec magic[4];

  magic[0].iov_base = iov_base[0];
  magic[0].iov_len = 4 * sizeof(char);

  magic[1].iov_base = iov_base[1];
  magic[1].iov_len = 4 * sizeof(char);

  magic[2].iov_base = conn->auth;
  magic[2].iov_len = conn->auth_len * sizeof(char);

  magic[3].iov_base = iov_base[2];
  magic[3].iov_len = 4 * sizeof(char);

  writev(conn->socket, magic, 4);

  *buf = malloc(sizeof(char) * 500);

  conn->error = 0;

  fd_set read;

  FD_ZERO(&read);
  FD_SET(conn->socket, &read);

  if (select(1, NULL, &read, NULL, NULL) < 0) {
    return conn->error;
  }

  recvfrom(conn->socket, buf, 500, MSG_WAITALL, NULL, NULL);

  if (strcmp(*buf, "SUCCESS")) {
    conn->error = -1;
    close(conn->socket);
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
  return conn->error = close(conn->socket);
}

void _reql_free_conn(_ReQL_Conn_t *conn) {
  _reql_free_cur(conn->cursors);
  free(conn->timeout);
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
