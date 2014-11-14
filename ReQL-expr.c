/**
 * @author Adam Grandquist
 */

#include <stdlib.h>

#include "ReQL-ast.h"

#include "ReQL-expr.h"

_ReQL_Op_t *_reql_expr_number(double val) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_NUM;
  term->num = val;
  return term;
}

_ReQL_Op_t *_reql_expr_string(const char *val, unsigned int str_len) {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_STR;
  term->str = val;
  term->str_len = str_len;
  return term;
}

_ReQL_Op_t *_reql_expr_array() {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_ARRAY;
  term->args->next = term->args->prev = term->args;
  term->args->elem = NULL;
  return term;
}

void _reql_array_append(_ReQL_Op_t *arr, _ReQL_Op_t *val) {
  _ReQL_Array_t *int_arr = arr->args;
  while (int_arr->next != int_arr) {
    int_arr = int_arr->next;
  }
  if (int_arr->elem) {
    _ReQL_Array_t *next;
    next->prev = int_arr;
    int_arr->next = next->next = next;
    next->elem = val;
  } else {
    int_arr->elem = val;
  }
}

_ReQL_Op_t *_reql_expr_object() {
  _ReQL_Op_t *term = _reql_expr_null();
  term->dt = _REQL_R_OBJECT;
  term->kwargs->next = term->kwargs->prev = term->kwargs;
  term->kwargs->key = NULL;
  term->kwargs->val = NULL;
  return term;
}

void _reql_object_add(_ReQL_Op_t *obj, _ReQL_Op_t *key, _ReQL_Op_t *val) {
  _ReQL_Object_t *int_obj = obj->kwargs;
  while (int_obj->next != int_obj) {
    int_obj = int_obj->next;
  }
  if (int_obj->key) {
    _ReQL_Object_t *next;
    next->prev = int_obj;
    int_obj->next = next->next = next;
    next->key = key;
    next->val = val;
  } else {
    int_obj->key = key;
    int_obj->val = val;
  }
}

_ReQL_Op_t *_reql_expr_null() {
  _ReQL_Op_t *term = malloc(sizeof(_ReQL_Op_t));
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

_ReQL_Op_t *_reql_build(_ReQL_Op_t *query) {
  if (query->tt == _REQL_DATUM) {
    return query;
  }

  _ReQL_Op_t *res = _reql_expr_array();
  _reql_array_append(res, _reql_expr_number(query->tt));
  if (query->args  && query->args->elem) {
    _ReQL_Array_t *elem = query->args;
    _ReQL_Op_t *args = _reql_expr_array();
    while (elem->next != elem) {
      _reql_array_append(args, _reql_build(elem->elem));
      elem = elem->next;
    }
    _reql_array_append(args, _reql_build(elem->elem));
    _reql_array_append(res, args);
  }
  if (query->kwargs && query->kwargs->key) {
    _ReQL_Object_t *pair = query->kwargs;
    _ReQL_Op_t *kwargs = _reql_expr_object();
    while (pair->next != pair) {
      _reql_object_add(kwargs, pair->key, _reql_build(pair->val));
      pair = pair->next;
    }
    _reql_object_add(kwargs, pair->key, _reql_build(pair->val));
    _reql_array_append(res, kwargs);
  }
  return res;
}
