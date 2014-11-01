/**
 * @author Adam Grandquist
 */

#include "ReQL-ast.h"

#ifndef _REQL_H
#define _REQL_H

struct _ReQL_Conn_s {
  int socket;
  int error;
  char *buf;
  unsigned int max_token;
  struct _ReQL_Cur_s **cursor;
};
typedef struct _ReQL_Conn_s _ReQL_Conn_t;

struct _ReQL_Cur_s {
};
typedef struct _ReQL_Cur_s _ReQL_Cur_t;

int _reql_connect(_ReQL_Conn_t *conn, unsigned char host_len, char *host, unsigned char port);
int _reql_close_conn(_ReQL_Conn_t *conn);

_ReQL_Cur_t *_reql_run(_ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_Op_t *kwargs);
void _reql_next(_ReQL_Cur_t *cur);
void _reql_close_cur(_ReQL_Cur_t *cur);

#endif
