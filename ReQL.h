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

#include <sys/socket.h>

#include "ReQL-ast.h"

#ifndef _REQL_H
#define _REQL_H

typedef enum {
  _REQL_CLIENT_ERROR = 16,
  _REQL_COMPILE_ERROR = 17,
  _REQL_RUNTIME_ERROR = 18,
  _REQL_SUCCESS_ATOM = 1,
  _REQL_SUCCESS_FEED = 5,
  _REQL_SUCCESS_PARTIAL = 3,
  _REQL_SUCCESS_SEQUENCE = 2,
  _REQL_WAIT_COMPLETE = 4
} _ReQL_Response_t;

struct _ReQL_Cur_s {
  unsigned int token;
  unsigned int idx;
  struct _ReQL_Conn_s *conn;
  _ReQL_Op_t *response;
  _ReQL_Op_t *array;
  _ReQL_Op_t *iter;
  struct _ReQL_Cur_s *next;
  struct _ReQL_Cur_s *prev;
};
typedef struct _ReQL_Cur_s _ReQL_Cur_t;

struct _ReQL_Conn_s {
  int socket;
  int error;
  unsigned int max_token;
  unsigned int auth_len;
  struct sockaddr *address;
  char *auth;
  _ReQL_Cur_t *cursors;
};
typedef struct _ReQL_Conn_s _ReQL_Conn_t;

_ReQL_Conn_t *_reql_new_connection(unsigned int auth_len, struct sockaddr *address, char *auth);
int _reql_connect(_ReQL_Conn_t *conn, char *buf);
int _reql_close_conn(_ReQL_Conn_t *conn);

_ReQL_Cur_t *_reql_run(_ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_Op_t *kwargs);
void _reql_cursor_next(_ReQL_Cur_t *cur);
void _reql_close_cur(_ReQL_Cur_t *cur);

#endif
