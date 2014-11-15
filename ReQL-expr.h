/**
 * @author Adam Grandquist
 */

#ifndef _REQL_EXPR_H
#define _REQL_EXPR_H

struct _ReQL_Op_s {
  int tt;
  int dt;

  unsigned long str_len;
  const char *str;

  double num;

  struct _ReQL_Op_s *key;
  struct _ReQL_Op_s *val;
  struct _ReQL_Op_s *args;
  struct _ReQL_Op_s *kwargs;
  struct _ReQL_Op_s *next;
  struct _ReQL_Op_s *prev;
};
typedef struct _ReQL_Op_s _ReQL_Op_t;

_ReQL_Op_t *_reql_expr_bool(int val);
_ReQL_Op_t *_reql_expr_null();
_ReQL_Op_t *_reql_expr_number(double val);
_ReQL_Op_t *_reql_expr_string(const char *val, unsigned long str_len);

_ReQL_Op_t *_reql_expr_array();
void _reql_array_append(_ReQL_Op_t *arr, _ReQL_Op_t *val);

_ReQL_Op_t *_reql_expr_object();
void _reql_object_add(_ReQL_Op_t *obj, _ReQL_Op_t *key, _ReQL_Op_t *val);

_ReQL_Op_t *_reql_build(_ReQL_Op_t *query);

#endif
