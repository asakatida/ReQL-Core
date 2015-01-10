/*
Copyright 2015 Adam Grandquist

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

#include "ReQL-cursor.h"

#ifndef _REQL_H
#define _REQL_H

struct _ReQL_Conn_s {
  char done;
  int socket;

  uint64_t max_token;
  uint32_t auth_size;

  unsigned long timeout;

  char *port;
  char *addr;

  char *auth;
  _ReQL_Cur_t *cursors;
};
typedef struct _ReQL_Conn_s _ReQL_Conn_t;
typedef _ReQL_Conn_t* _ReQL_Conn;

void _reql_connection_init(_ReQL_Conn conn);
void _reql_conn_set_auth(_ReQL_Conn conn, uint32_t size, char *auth);
void _reql_conn_set_addr(_ReQL_Conn conn, char *addr);
void _reql_conn_set_port(_ReQL_Conn conn, char *port);
void _reql_conn_set_timeout(_ReQL_Conn conn, unsigned long timeout);
int _reql_connect(_ReQL_Conn conn, char *buf, size_t size);
void _reql_close_conn(_ReQL_Conn conn);
void _reql_ensure_conn_close(_ReQL_Conn_t *conn);

int _reql_run(_ReQL_Cur cur, _ReQL_Op query, _ReQL_Conn conn, _ReQL_Op kwargs);

#endif
