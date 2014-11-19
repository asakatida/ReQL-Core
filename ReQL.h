/**
 * @author Adam Grandquist
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
void _reql_next(_ReQL_Cur_t *cur);
void _reql_close_cur(_ReQL_Cur_t *cur);

#endif
