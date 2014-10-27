#ifndef _REQL_H
#define _REQL_H

struct _ReQL_arg_s {
  struct _ReQL_Op_s *arg;
  struct _ReQL_arg_s *next_arg;
};
typedef struct _ReQL_arg_s _ReQL_arg_t;

struct _ReQL_kwarg_s {
  char *key;
  struct _ReQL_Op_s *val;
  struct _ReQL_kwarg_s *next_kwarg;
};
typedef struct _ReQL_kwarg_s _ReQL_kwarg_t;

struct _ReQL_Op_s {
  int tt;
  int dt;

  int str_len;
  char *str;

  double num;

  _ReQL_arg_t *args;
  _ReQL_kwarg_t *kwargs;
};
typedef struct _ReQL_Op_s _ReQL_Op_t;

struct _ReQL_Conn_s {
  int socket;
  int error;
  char *buf;
};
typedef struct _ReQL_Conn_s _ReQL_Conn_t;

struct _ReQL_Cur_s {
};
typedef struct _ReQL_Cur_s _ReQL_Cur_t;

_ReQL_arg_t *_reql_arg_new();
int _reql_arg_append(_ReQL_arg_t *args, _ReQL_Op_t *val);

_ReQL_kwarg_t *_reql_kwarg_new();
int _reql_kwarg_add(_ReQL_kwarg_t *kwargs, char *key, _ReQL_Op_t *val);

_ReQL_Op_t *_reql_expr_number(double val);
_ReQL_Op_t *_reql_expr_string(char *val, int str_len);
_ReQL_Op_t *_reql_expr_array(_ReQL_arg_t *val);
_ReQL_Op_t *_reql_expr_object(_ReQL_kwarg_t *val);
_ReQL_Op_t *_reql_expr_null();
_ReQL_Op_t *_reql_expr_bool(int val);

int _reql_connect(_ReQL_Conn_t *conn, unsigned char host_len, char *host, unsigned char port);
int _reql_close_conn(_ReQL_Conn_t *conn);

_ReQL_Cur_t *_reql_run(_ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_kwarg_t *kwargs);
void _reql_next(_ReQL_Cur_t *cur);
void _reql_close_cur(_ReQL_Cur_t *cur);

#endif
