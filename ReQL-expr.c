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

_ReQL_Op _reql_expr_number(double num) {
  _ReQL_Op obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_NUM;
    obj->num = num;
  }
  return obj;
}

int _reql_to_number(_ReQL_Op obj, double *num) {
  if (obj) {
    if (obj->dt == _REQL_R_NUM) {
      *num = obj->num;
      return 0;
    }
  }
  return -1;
}

_ReQL_Op _reql_expr_string(const char *str, unsigned long str_len) {
  char *copy = malloc(sizeof(char) * str_len);
  copy = memcpy(copy, str, sizeof(char) * str_len);

  if (copy) {
    return _reql_expr_string_nc(copy, str_len);
  }

  return NULL;
}

_ReQL_Op _reql_expr_string_nc(char *str, unsigned long str_len) {
  _ReQL_Op obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_STR;
    obj->str = str;
    obj->str_len = str_len;
  }
  return obj;
}

int _reql_to_string(_ReQL_Op obj, const char **str, unsigned long *str_len) {
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

_ReQL_Op _reql_iter(_ReQL_Op obj) {
  if (!obj) {
    return NULL;
  }
  _ReQL_Op res = obj;
  while (res->prev != res) {
    res = res->prev;
    if (res == obj) {
      return NULL;
    }
  }
  return res;
}

int _reql_iter_next(_ReQL_Op *obj) {
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

_ReQL_Op _reql_expr_c_array(unsigned long size) {
  _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t) * size);
  if (obj) {
    unsigned long i;
    for (i=0; i<size; ++i) {
      obj[i].tt = _REQL_DATUM;
      obj[i].dt = _REQL_C_ARRAY;
      obj[i].str_len = size - i;
      obj[i].args = obj[i].kwargs = obj[i].key = obj[i].val = NULL;
      obj[i].next = obj[i].prev = obj;
      obj[i].num = 0.0;
      obj[i].str = NULL;
    }
  }
  return obj;
}

int _reql_to_c_array(_ReQL_Op obj, unsigned long *size) {
  int err = -1;
  if (obj) {
    if (obj->dt == _REQL_C_ARRAY) {
      *size = obj->str_len;
      err = 0;
    }
  }
  return err;
}

int _reql_c_array_insert(_ReQL_Op obj, _ReQL_Op val, unsigned long idx) {
  if ((!(obj && val)) || obj->str_len <= idx) {
    return -1;
  }

  _reql_expr_free(obj[idx].val);

  obj[idx].val = val;

  return 0;
}

_ReQL_Op _reql_c_array_index(_ReQL_Op obj, unsigned long idx) {
  if ((!obj) || obj->str_len <= idx) {
    return NULL;
  }
  return obj[idx].val;
}

_ReQL_Op _reql_expr_array() {
  _ReQL_Op obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_ARRAY;
    obj->next = obj->prev = obj;
    obj->val = NULL;
  }
  return obj;
}

_ReQL_Op _reql_to_array(_ReQL_Op obj) {
  _ReQL_Op err = NULL;
  if (obj) {
    if (obj->dt == _REQL_R_ARRAY) {
      err = _reql_iter(obj);
    }
  }
  return err;
}

int _reql_array_append(_ReQL_Op obj, _ReQL_Op val) {
  if (!(obj && val)) {
    return -1;
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

  return 0;
}

int _reql_array_next(_ReQL_Op *obj, _ReQL_Op *val) {
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

_ReQL_Op _reql_array_pop(_ReQL_Op obj) {
  _ReQL_Op res = NULL;

  obj = _reql_to_array(obj);

  if (obj) {
    while (!_reql_array_next(&obj, &res)) ;

    obj->val = NULL;
    if (obj->prev != obj) {
      obj->prev->next = obj->prev;
      obj->next = NULL;
      obj->prev = NULL;
      _reql_expr_free(obj);
    }
  }

  return res;
}

_ReQL_Op _reql_array_last(_ReQL_Op obj) {
  _ReQL_Op res = NULL;

  obj = _reql_to_array(obj);

  if (obj) {
    while (!_reql_array_next(&obj, &res)) ;
  }

  return res;
}

_ReQL_Op _reql_expr_object() {
  _ReQL_Op obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_OBJECT;
    obj->next = obj->prev = obj;
    obj->key = NULL;
    obj->val = NULL;
  }
  return obj;
}

_ReQL_Op _reql_to_object(_ReQL_Op obj) {
  _ReQL_Op err = NULL;
  if (obj) {
    if (obj->dt == _REQL_R_OBJECT) {
      err = _reql_iter(obj);
    }
  }
  return err;
}

int _reql_op_eq(_ReQL_Op l, _ReQL_Op r) {
  int res = 0;
  if (l == r) {
    res = 1;
  } else {
    if ((l && r)) {
      if (l->tt == r->tt && l->dt == r->dt) {
        switch (l->dt) {
          case _REQL_C_ARRAY: {
            unsigned long larr_len, rarr_len;
            if (_reql_to_c_array(l, &larr_len) || _reql_to_c_array(r, &rarr_len)) {
              break;
            }
            if (larr_len == rarr_len) {
              res = 1;
              unsigned long i;
              for (i=0; i<larr_len; ++i) {
                res &= _reql_op_eq(_reql_c_array_index(l, i), _reql_c_array_index(r, i));
              }
            }
            break;
          }
          case _REQL_R_ARRAY: {
            l = _reql_to_array(l);
            r = _reql_to_array(r);
            if (!(l && r)) {
              break;
            }
            res = 1;
            _ReQL_Op lelem = NULL;
            _ReQL_Op relem = NULL;
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
            _ReQL_Op lkey = NULL;
            _ReQL_Op lval = NULL;
            _ReQL_Op rkey = NULL;
            _ReQL_Op rval = NULL;
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

void _reql_object_add(_ReQL_Op obj, _ReQL_Op key, _ReQL_Op val) {
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

int _reql_object_next(_ReQL_Op *obj, _ReQL_Op *key, _ReQL_Op *val) {
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

_ReQL_Op _reql_expr_null() {
  _ReQL_Op obj = malloc(sizeof(_ReQL_Op_t));
  if (obj) {
    obj->tt = _REQL_DATUM;
    obj->dt = _REQL_R_NULL;
    obj->args = obj->kwargs = obj->key = obj->val = NULL;
    obj->next = obj->prev = obj;
    obj->str_len = obj->num = 0.0;
    obj->str = NULL;
  }
  return obj;
}

int _reql_is_null(_ReQL_Op obj) {
  if (!obj) {
    return 0;
  }
  return obj->dt == _REQL_R_NULL;
}

_ReQL_Op _reql_expr_bool(int val) {
  _ReQL_Op obj = _reql_expr_null();
  if (obj) {
    obj->dt = _REQL_R_BOOL;
    obj->str_len = (unsigned long)val;
  }
  return obj;
}

int _reql_to_bool(_ReQL_Op obj, int *val) {
  if (obj) {
    if (obj->dt == _REQL_R_BOOL) {
      *val = (int)obj->str_len;
      return 0;
    }
  }
  return -1;
}

_ReQL_Op _reql_expr_copy(_ReQL_Op obj) {
  _ReQL_Op res = NULL;
  switch (obj->dt) {
    case _REQL_C_ARRAY: {
      unsigned long size;
      if (_reql_to_c_array(obj, &size)) {
        break;
      }
      res = _reql_expr_c_array(size);
      unsigned long i;
      for (i=0; i<size; ++i) {
        _reql_c_array_insert(obj, _reql_expr_copy(_reql_c_array_index(obj, i)), i);
      }
      break;
    }
    case _REQL_R_ARRAY: {
      obj = _reql_to_array(obj);
      if (!obj) {
        break;
      }
      res = _reql_expr_array();
      _ReQL_Op elem;
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
      _ReQL_Op key;
      _ReQL_Op val;
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

void _reql_expr_free(_ReQL_Op obj) {
  if (!obj) {
    return;
  }

  if (obj->str) {
    free((char *)obj->str); obj->str = NULL;
  }

  unsigned long size;

  if (!_reql_to_c_array(obj, &size)) {
    unsigned long i;
    for (i=0; i<size; ++i) {
      _reql_expr_free(_reql_c_array_index(obj, i));
    }
  }

  _reql_expr_free(obj->key); obj->key = NULL;
  _reql_expr_free(obj->val); obj->val = NULL;
  _reql_expr_free(obj->args); obj->args = NULL;
  _reql_expr_free(obj->kwargs); obj->kwargs = NULL;
  _reql_expr_free(obj->next); obj->next = NULL;
  _reql_expr_free(obj->prev); obj->prev = NULL;

  free(obj);
}

_ReQL_Op _reql_build(_ReQL_Op query) {
  if (!query) {
    return NULL;
  }
  if (query->tt == _REQL_DATUM) {
    return query;
  }

  _ReQL_Op res = _reql_expr_c_array(3);
  _reql_c_array_insert(res, _reql_expr_number(query->tt), 0);
  unsigned long size;
  _ReQL_Op args;
  _ReQL_Op arr;

  if (!_reql_to_c_array(query->args, &size)) {
    _ReQL_Op arr = _reql_expr_c_array(size);

    unsigned long i;

    for (i=0; i<size; ++i) {
      _reql_c_array_insert(arr, _reql_build(_reql_c_array_index(query->args, i)), i);
    }
  } else if ((args = _reql_to_array(query->args))) {
    _ReQL_Op elem;
    _ReQL_Op arr = _reql_expr_array();

    while (_reql_array_next(&args, &elem)) {
      _reql_array_append(arr, _reql_build(elem));
    }
  } else {
    _reql_expr_free(res); res = NULL;
  }

  _reql_c_array_insert(res, arr, 1);

  _ReQL_Op kwargs = _reql_to_object(query->kwargs);
  if (kwargs) {
    _ReQL_Op key;
    _ReQL_Op val;
    _ReQL_Op obj = _reql_expr_object();

    char has_kwargs = 0;

    while (_reql_object_next(&kwargs, &key, &val)) {
      _reql_object_add(obj, _reql_build(key), _reql_build(val));
      has_kwargs = 1;
    }

    if (has_kwargs) {
      _reql_c_array_insert(res, obj, 2);
    } else {
      _reql_expr_free(obj);
    }
  }

  return res;
}
