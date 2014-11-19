/**
 * @author Adam Grandquist
 */

#include "ReQL-expr.h"

#include <stdlib.h>

_ReQL_Op_t *_reql_expr_number(double num) {
  _ReQL_Op_t *obj = _reql_expr_null();
  obj->dt = _REQL_R_NUM;
  obj->num = num;
  return obj;
}

int _reql_to_number(_ReQL_Op_t *obj, double *num) {
  if (obj->dt == _REQL_R_NUM) {
    *num = obj->num;
    return 0;
  }
  return -1;
}

_ReQL_Op_t *_reql_expr_string(const char *str, unsigned long str_len) {
  _ReQL_Op_t *obj = _reql_expr_null();
  obj->dt = _REQL_R_STR;
  obj->str = str;
  obj->str_len = str_len;
  return obj;
}

int _reql_to_string(_ReQL_Op_t *obj, const char **str, unsigned long *str_len) {
  int err = -1;
  if (obj->dt == _REQL_R_STR) {
    if (obj->str) {
      *str_len = obj->str_len;
      *str = obj->str;
      err = 0;
    }
  }
  return err;
}

_ReQL_Op_t *_reql_iter(_ReQL_Op_t *obj) {
  _ReQL_Op_t *res = obj;
  while (res->prev != res) {
    res = res->prev;
    if (res == obj) {
      return NULL;
    }
  }
  return res;
}

int _reql_iter_next(_ReQL_Op_t **obj) {
  if (*obj == (*obj)->next) {
    return -1;
  }
  *obj = (*obj)->next;
  return 0;
}

_ReQL_Op_t *_reql_expr_array() {
  _ReQL_Op_t *obj = _reql_expr_null();
  obj->dt = _REQL_R_ARRAY;
  obj->next = obj->prev = obj;
  obj->val = NULL;
  return obj;
}

_ReQL_Op_t *_reql_to_array(_ReQL_Op_t *obj) {
  _ReQL_Op_t *err = NULL;
  if (obj->dt == _REQL_R_ARRAY) {
    err = _reql_iter(obj);
  }
  return err;
}

void _reql_array_append(_ReQL_Op_t *obj, _ReQL_Op_t *val) {
  while (obj->next != obj) {
    obj = obj->next;
  }
  if (obj->val) {
    obj->next = _reql_expr_array();
    obj->next->prev = obj;
    obj = obj->next;
    obj->next = obj;
  }
  obj->val = val;
}

int _reql_array_next(_ReQL_Op_t **obj, _ReQL_Op_t **val) {
  int err = -1;

  if (!_reql_iter_next(obj)) {
    if ((*obj)->val) {
      *val = (*obj)->val;
      err = 0;
    }
  }

  return err;
}

_ReQL_Op_t *_reql_array_pop(_ReQL_Op_t *obj) {
  _ReQL_Op_t *res = NULL;
  while (!_reql_array_next(&obj, &res)) {
  }

  if (res) {
    res->prev->next = res->prev;
    res->next = NULL;
    res->prev = NULL;
  }

  return res;
}

_ReQL_Op_t *_reql_expr_object() {
  _ReQL_Op_t *obj = _reql_expr_null();
  obj->dt = _REQL_R_OBJECT;
  obj->next = obj->prev = obj->kwargs;
  obj->key = NULL;
  obj->val = NULL;
  return obj;
}

_ReQL_Op_t *_reql_to_object(_ReQL_Op_t *obj) {
  _ReQL_Op_t *err = NULL;
  if (obj->dt == _REQL_R_OBJECT) {
    err = _reql_iter(obj);
  }
  return err;
}


void _reql_object_add(_ReQL_Op_t *obj, _ReQL_Op_t *key, _ReQL_Op_t *val) {
  while (obj->next != obj) {
    obj = obj->next;
  }
  if (obj->key) {
    obj->next = _reql_expr_object();
    obj->next->prev = obj;
    obj = obj->next;
    obj->next = obj;
  }
  obj->key = key;
  obj->val = val;
}

int _reql_object_next(_ReQL_Op_t **obj, _ReQL_Op_t **key, _ReQL_Op_t **val) {
  int err = -1;

  if (!_reql_iter_next(obj)) {
    if ((*obj)->key) {
      *key = (*obj)->key;
      *val = (*obj)->val;
      err = 0;
    }
  }

  return err;
}

_ReQL_Op_t *_reql_expr_null() {
  _ReQL_Op_t *obj = malloc(sizeof(_ReQL_Op_t));
  obj->tt = _REQL_DATUM;
  obj->dt = _REQL_R_NULL;
  return obj;
}

int _reql_is_null(_ReQL_Op_t *obj) {
  return obj->dt == _REQL_R_NULL;
}

_ReQL_Op_t *_reql_expr_bool(int val) {
  _ReQL_Op_t *obj = _reql_expr_null();
  obj->dt = _REQL_R_BOOL;
  obj->str_len = (unsigned long)val;
  return obj;
}

int _reql_to_bool(_ReQL_Op_t *obj, int *val) {
  if (obj->dt == _REQL_R_BOOL) {
    *val = (int)obj->str_len;
    return 0;
  }
  return -1;
}

_ReQL_Op_t *_reql_build(_ReQL_Op_t *query) {
  if (query->tt == _REQL_DATUM) {
    return query;
  }

  _ReQL_Op_t *res = _reql_expr_array();
  _reql_array_append(res, _reql_expr_number(query->tt));
  if (query->args  && query->args->val) {
    _ReQL_Op_t *elem = query->args;
    _ReQL_Op_t *args = _reql_expr_array();
    _reql_array_append(args, _reql_build(elem->val));
    do {
       elem = elem->next;
      _reql_array_append(args, _reql_build(elem->val));
    } while (elem->next != elem);
    _reql_array_append(res, args);
  }
  if (query->kwargs && query->kwargs->key) {
    _ReQL_Op_t *pair = query->kwargs;
    _ReQL_Op_t *kwargs = _reql_expr_object();
    _reql_object_add(kwargs, pair->key, _reql_build(pair->val));
    do {
      pair = pair->next;
      _reql_object_add(kwargs, pair->key, _reql_build(pair->val));
    } while (pair->next != pair);
    _reql_array_append(res, kwargs);
  }
  return res;
}
