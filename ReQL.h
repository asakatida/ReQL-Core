/**
 * @author Adam Grandquist
 */

#include "ReQL-ast.h"

#ifndef _REQL_H
#define _REQL_H

struct _ReQL_Cur_s {
  unsigned int token;
  unsigned int idx;
  struct _ReQL_Conn_s *conn;
  _ReQL_Op_t *response;
  _ReQL_Op_t *array;
};
typedef struct _ReQL_Cur_s _ReQL_Cur_t;

struct _ReQL_Cur_Arr_s {
  _ReQL_Cur_t *cur;
  struct _ReQL_Cur_Arr_s *next;
  struct _ReQL_Cur_Arr_s *prev;
};
typedef struct _ReQL_Cur_Arr_s _ReQL_Cur_Arr_t;

struct _ReQL_Conn_s {
  int socket;
  int error;
  unsigned int max_token;
  unsigned int auth_len;
  struct sockaddr *address;
  char *auth;
  _ReQL_Cur_Arr_t *cursors;
};
typedef struct _ReQL_Conn_s _ReQL_Conn_t;

int _reql_connect(_ReQL_Conn_t *conn, char *buf);
int _reql_close_conn(_ReQL_Conn_t *conn);

_ReQL_Cur_t *_reql_run(_ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_Op_t *kwargs);
void _reql_next(_ReQL_Cur_t *cur);
void _reql_close_cur(_ReQL_Cur_t *cur);

#endif
