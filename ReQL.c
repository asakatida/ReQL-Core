#include "ReQL.h"

#include "ReQL-ast.h"

#include <sys/socket.h>

_ReQL_arg_t *_reql_arg_new() {
  _ReQL_arg_t *arg;
  arg->next_arg = arg;
  return arg;
}

int _reql_arg_append(_ReQL_arg_t *args, _ReQL_Op_t *val) {
  while (args->next_arg != args) {
    args = args->next_arg;
  }
  args->arg = val;
  _ReQL_arg_t *next_arg;
  args->next_arg = next_arg;
  next_arg->next_arg = next_arg;
  return 0;
}

_ReQL_kwarg_t *_reql_kwarg_new() {
  _ReQL_kwarg_t *kwarg;
  kwarg->next_kwarg = kwarg;
  return kwarg;
}

int _reql_kwarg_add(_ReQL_kwarg_t *kwargs, char *key, _ReQL_Op_t *val) {
  while (kwargs->next_kwarg != kwargs) {
    kwargs = kwargs->next_kwarg;
  }
  kwargs->key = key;
  kwargs->val = val;
  _ReQL_kwarg_t *next_kwarg;
  kwargs->next_kwarg = next_kwarg;
  next_kwarg->next_kwarg = next_kwarg;
  return 0;
}

_ReQL_Op_t *_reql_expr_number(double val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_NUM;
  term->num = val;
  return term;
}
_ReQL_Op_t *_reql_expr_string(char *val, int str_len) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_STR;
  term->str = val;
  term->str_len = str_len;
  return term;
}

_ReQL_Op_t *_reql_expr_array(_ReQL_arg_t *val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_ARRAY;
  return term;
}

_ReQL_Op_t *_reql_expr_object(_ReQL_kwarg_t *val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_OBJECT;
  return term;
}

_ReQL_Op_t *_reql_expr_null() {
  _ReQL_Op_t *term;
  term->tt = _REQL_DATUM;
  term->dt = _REQL_R_NULL;
  term->str_len = 0;
  term->str = 0;
  term->num = 0;
  term->args = 0;
  term->kwargs = 0;
  return term;
}

_ReQL_Op_t *_reql_expr_bool(int val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_BOOL;
  return term;
}

_ReQL_Conn_t *_reql_connect(char *host, int port) {
  _ReQL_Conn_t *conn;
  return conn;
}

_ReQL_Cur_t *_reql_run(
    _ReQL_Op_t *query, _ReQL_Conn_t *conn, _ReQL_kwarg_t *kwargs) {
  _ReQL_Cur_t *cur;
  return cur;
}

int _reql_close_conn(_ReQL_Conn_t *conn){
  return 0;
}
int _reql_close_cur(_ReQL_Cur_t *cur){
  return 0;
}
