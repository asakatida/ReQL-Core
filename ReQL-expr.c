/**
 * @author Adam Grandquist
 */

#include "ReQL-ast.h"

#include "ReQL-expr.h"

_ReQL_Op_t *_reql_expr_number(double val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_NUM;
  term->num = val;
  return term;
}
_ReQL_Op_t *_reql_expr_string(char *val, unsigned int str_len) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_STR;
  term->str = val;
  term->str_len = str_len;
  return term;
}

_ReQL_Op_t *_reql_expr_array() {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_ARRAY;
  return term;
}

void _reql_array_append(_ReQL_Op_t *arr, _ReQL_Op_t *val) {
  _ReQL_Op_t *last_elem = arr;
  while (last_elem->next) {
    last_elem = last_elem->next;
  }
  last_elem->next = _reql_expr_null();
  last_elem = last_elem->next;
  last_elem->child = val;
}

_ReQL_Op_t *_reql_expr_object() {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_OBJECT;
  return term;
}

void _reql_object_add(_ReQL_Op_t *obj, _ReQL_Op_t *key, _ReQL_Op_t *val) {
  _ReQL_Op_t *last_elem = obj;
  while (last_elem->next) {
    last_elem = last_elem->next;
  }
  last_elem->next = _reql_expr_null();;
  last_elem = last_elem->next;
  last_elem->str_len = key->str_len;
  last_elem->str = key->str;
  last_elem->child = val;
}

_ReQL_Op_t *_reql_expr_null() {
  _ReQL_Op_t *term;
  term->tt = _REQL_DATUM;
  term->dt = _REQL_R_NULL;
  return term;
}

_ReQL_Op_t *_reql_expr_bool(int val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_BOOL;
  term->num = val;
  return term;
}

