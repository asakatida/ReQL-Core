/*
Copyright 2014 Adam Grandquist

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */
/**
 * @author Adam Grandquist
 * @copyright Apache
 */

#include "ReQL-expr.h"

#include <stdlib.h>
#include <string.h>

_ReQL_Op_t *_reql_expr_number(double num) {
  _ReQL_Op_t *obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_NUM;
    obj->num = num;
  }
  return obj;
}

int _reql_to_number(_ReQL_Op_t *obj, double *num) {
  if (obj) {
    if (obj->dt == _REQL_R_NUM) {
      *num = obj->num;
      return 0;
    }
  }
  return -1;
}

_ReQL_Op_t *_reql_expr_string(const char *str, unsigned long str_len) {
  _ReQL_Op_t *obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_STR;
    obj->str = malloc(sizeof(char) * str_len);
    obj->str = memcpy((char *)obj->str, str, sizeof(char) * str_len);
    obj->str_len = str_len;
  }
  return obj;
}

int _reql_to_string(_ReQL_Op_t *obj, const char **str, unsigned long *str_len) {
  int err = -1;
  if (obj) {
    if (obj->dt == _REQL_R_STR) {
      if (obj->str) {
        *str_len = obj->str_len;
        *str = obj->str;
        err = 0;
      }
    }
  }
  return err;
}

_ReQL_Op_t *_reql_iter(_ReQL_Op_t *obj) {
  if (!obj) {
    return NULL;
  }
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
  if (!obj) {
    return -1;
  }
  if (!*obj) {
    return -1;
  }
  if (*obj == (*obj)->next) {
    return -1;
  }
  *obj = (*obj)->next;
  return 0;
}

_ReQL_Op_t *_reql_expr_array() {
  _ReQL_Op_t *obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_ARRAY;
    obj->next = obj->prev = obj;
    obj->val = NULL;
  }
  return obj;
}

_ReQL_Op_t *_reql_to_array(_ReQL_Op_t *obj) {
  _ReQL_Op_t *err = NULL;
  if (obj) {
    if (obj->dt == _REQL_R_ARRAY) {
      err = _reql_iter(obj);
    }
  }
  return err;
}

void _reql_array_append(_ReQL_Op_t *obj, _ReQL_Op_t *val) {
  if (!(obj && val)) {
    return;
  }
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

  if (val) {
    if (!_reql_iter_next(obj)) {
      if ((*obj)->val) {
        *val = (*obj)->val;
        err = 0;
      }
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
  if (obj) {
    obj->dt = _REQL_R_OBJECT;
    obj->next = obj->prev = obj;
    obj->key = NULL;
    obj->val = NULL;
  }
  return obj;
}

_ReQL_Op_t *_reql_to_object(_ReQL_Op_t *obj) {
  _ReQL_Op_t *err = NULL;
  if (obj) {
    if (obj->dt == _REQL_R_OBJECT) {
      err = _reql_iter(obj);
    }
  }
  return err;
}

int _reql_op_eq(_ReQL_Op_t *l, _ReQL_Op_t *r) {
  int res = 0;
  if (l == r) {
    res = 1;
  } else {
    if ((l && r)) {
      if (l->tt == r->tt && l->dt == r->dt) {
        switch (l->dt) {
          case _REQL_R_ARRAY: {
            l = _reql_to_array(l);
            r = _reql_to_array(r);
            if (!(l && r)) {
              break;
            }
            res = 1;
            _ReQL_Op_t *lelem = NULL;
            _ReQL_Op_t *relem = NULL;
            while (!(_reql_array_next(&l, &lelem) || _reql_array_next(&r, &relem))) {
              res &= _reql_op_eq(lelem, relem);
            }
            if (!(_reql_array_next(&l, &lelem) && _reql_array_next(&r, &relem))) {
              res = 0;
            }
            break;
          }
          case _REQL_R_BOOL: {
            int lval, rval;
            if (_reql_to_bool(l, &lval) || _reql_to_bool(r, &rval)) {
              break;
            }
            res = lval == rval;
            break;
          }
          case _REQL_R_JSON: {
            res = _reql_op_eq(l->args, r->args) && _reql_op_eq(l->kwargs, r->kwargs);
            break;
          }
          case _REQL_R_NULL: {
            res = 1;
            break;
          }
          case _REQL_R_NUM: {
            double lval, rval;
            if (_reql_to_number(l, &lval) || _reql_to_number(r, &rval)) {
              break;
            }
            res = lval == rval;
            break;
          }
          case _REQL_R_OBJECT: {
            l = _reql_to_object(l);
            r = _reql_to_object(r);
            if (!(l && r)) {
              break;
            }
            res = 1;
            _ReQL_Op_t *lkey = NULL;
            _ReQL_Op_t *lval = NULL;
            _ReQL_Op_t *rkey = NULL;
            _ReQL_Op_t *rval = NULL;
            while (!(_reql_object_next(&l, &lkey, &lval) || _reql_object_next(&r, &rkey, &rval))) {
              res &= _reql_op_eq(lkey, rkey) && _reql_op_eq(lval, rval);
            }
            if (!(_reql_object_next(&l, &lkey, &lval) && _reql_object_next(&r, &rkey, &rval))) {
              res = 0;
            }
            break;
          }
          case _REQL_R_STR: {
            const char *rstr;
            const char *lstr;
            unsigned long lstr_len, rstr_len;
            if (_reql_to_string(l, &lstr, &lstr_len) || _reql_to_string(r, &rstr, &rstr_len)) {
              break;
            }
            if (lstr_len == rstr_len) {
              res = !memcmp(rstr, lstr, lstr_len);
            }
            break;
          }
        }
      }
    }
  }
  return res;
}

void _reql_object_add(_ReQL_Op_t *obj, _ReQL_Op_t *key, _ReQL_Op_t *val) {
  if (!(obj && key && val)) {
    return;
  }
  while (obj->next != obj && !_reql_op_eq(obj->key, key)) {
    obj = obj->next;
  }
  if (obj->key && !_reql_op_eq(obj->key, key)) {
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

  if (key && val) {
    if (!_reql_iter_next(obj)) {
      if ((*obj)->key) {
        *key = (*obj)->key;
        *val = (*obj)->val;
        err = 0;
      }
    }
  }

  return err;
}

_ReQL_Op_t *_reql_expr_null() {
  _ReQL_Op_t *obj = malloc(sizeof(_ReQL_Op_t));
  if (obj) {
    obj->tt = _REQL_DATUM;
    obj->dt = _REQL_R_NULL;
  }
  return obj;
}

int _reql_is_null(_ReQL_Op_t *obj) {
  if (!obj) {
    return -1;
  }
  return obj->dt == _REQL_R_NULL;
}

_ReQL_Op_t *_reql_expr_bool(int val) {
  _ReQL_Op_t *obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_BOOL;
    obj->str_len = (unsigned long)val;
  }
  return obj;
}

int _reql_to_bool(_ReQL_Op_t *obj, int *val) {
  if (obj) {
    if (obj->dt == _REQL_R_BOOL) {
      *val = (int)obj->str_len;
      return 0;
    }
  }
  return -1;
}

_ReQL_Op_t *_reql_expr_copy(_ReQL_Op_t *obj) {
  _ReQL_Op_t *res = NULL;
  switch (obj->dt) {
    case _REQL_R_ARRAY: {
      obj = _reql_to_array(obj);
      if (!obj) {
        break;
      }
      res = _reql_expr_array();
      _ReQL_Op_t *elem;
      while (!_reql_array_next(&obj, &elem)) {
        _reql_array_append(res, _reql_expr_copy(elem));
      }
      break;
    }
    case _REQL_R_BOOL: {
      int val;
      if (_reql_to_bool(obj, &val)) {
        break;
      }
      res = _reql_expr_bool(val);
      break;
    }
    case _REQL_R_JSON: {
      res = _reql_expr_null();
      res->tt = obj->tt;
      res->dt = obj->dt;
      res->args = _reql_expr_copy(obj->args);
      res->kwargs = _reql_expr_copy(obj->kwargs);
      break;
    }
    case _REQL_R_NULL: {
      obj = _reql_expr_null();
      break;
    }
    case _REQL_R_NUM: {
      double val;
      if (_reql_to_number(obj, &val)) {
        break;
      }
      res = _reql_expr_number(val);
      break;
    }
    case _REQL_R_OBJECT: {
      obj = _reql_to_object(obj);
      if (!obj) {
        break;
      }
      res = _reql_expr_object();
      _ReQL_Op_t *key;
      _ReQL_Op_t *val;
      while (!_reql_object_next(&obj, &key, &val)) {
        _reql_object_add(res, _reql_expr_copy(key), _reql_expr_copy(val));
      }
      break;
    }
    case _REQL_R_STR: {
      const char *str;
      unsigned long str_len;
      if (_reql_to_string(obj, &str, &str_len)) {
        break;
      }
      res = _reql_expr_string(str, str_len);
      break;
    }
  }
  return res;
}

void _reql_expr_free(_ReQL_Op_t *obj) {
  if (!obj) {
    return;
  }

  if (obj->str) {
    free((char *)obj->str); obj->str = NULL;
  }

  _reql_expr_free(obj->key); obj->key = NULL;
  _reql_expr_free(obj->val); obj->val = NULL;
  _reql_expr_free(obj->args); obj->args = NULL;
  _reql_expr_free(obj->kwargs); obj->kwargs = NULL;
  _reql_expr_free(obj->next); obj->next = NULL;
  _reql_expr_free(obj->prev); obj->prev = NULL;

  free(obj);
}

_ReQL_Op_t *_reql_build(_ReQL_Op_t *query) {
  if (!query) {
    return NULL;
  }
  if (query->tt == _REQL_DATUM) {
    return query;
  }

  _ReQL_Op_t *res = _reql_expr_array();
  _reql_array_append(res, _reql_expr_number(query->tt));

  _ReQL_Op_t *args = _reql_to_array(query->args);
  if (!args) {
    _reql_expr_free(res);
    return NULL;
  }

  _ReQL_Op_t *elem;
  _ReQL_Op_t *arr = _reql_expr_array();

  char has_args = 0;

  while (_reql_array_next(&args, &elem)) {
    _reql_array_append(arr, _reql_build(elem));
    has_args = 1;
  }

  if (has_args) {
    _reql_array_append(res, arr);
  }

  _ReQL_Op_t *kwargs = _reql_to_object(query->kwargs);
  if (kwargs) {
    _ReQL_Op_t *key;
    _ReQL_Op_t *val;
    _ReQL_Op_t *obj = _reql_expr_object();

    char has_kwargs = 0;
    
    while (_reql_object_next(&kwargs, &key, &val)) {
      _reql_object_add(obj, _reql_build(key), _reql_build(val));
      has_kwargs = 1;
    }

    if (has_kwargs) {
      _reql_array_append(res, obj);
    }
  }

  return res;
}
