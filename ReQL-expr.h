/**
 * @author Adam Grandquist
 */

#ifndef _REQL_EXPR_H
#define _REQL_EXPR_H

struct _ReQL_Op_s {
  int tt;
  int dt;

  unsigned int str_len;
  char *str;

  double num;

  struct _ReQL_Op_s *child;
  struct _ReQL_Op_s *next;
};
typedef struct _ReQL_Op_s _ReQL_Op_t;

_ReQL_Op_t *_reql_expr_bool(int val);
_ReQL_Op_t *_reql_expr_null();
_ReQL_Op_t *_reql_expr_number(double val);
_ReQL_Op_t *_reql_expr_string(char *val, unsigned int str_len);

_ReQL_Op_t *_reql_expr_array();
void _reql_array_append(_ReQL_Op_t *arr, _ReQL_Op_t *val);

_ReQL_Op_t *_reql_expr_object();
void _reql_object_add(_ReQL_Op_t *obj, _ReQL_Op_t *key, _ReQL_Op_t *val);

#endif
