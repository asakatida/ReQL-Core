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

#include "ReQL-json.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

_ReQL_Datum_t _reql_datum_type(_ReQL_Op obj) {
  if (_reql_term_type(obj) != _REQL_DATUM) {
    return _REQL_R_REQL;
  }

  return obj->obj.datum.dt;
}

_ReQL_Term_t _reql_term_type(_ReQL_Op obj) {
  return obj->tt;
}

void _reql_number_init(_ReQL_Op obj, double num) {
  _reql_null_init(obj);

  obj->obj.datum.dt = _REQL_R_NUM;
  obj->obj.datum.json.number = num;
}

double _reql_to_number(_ReQL_Op obj) {
  return obj->obj.datum.json.number;
}

void _reql_string_init(_ReQL_Op obj, uint8_t *str, uint32_t size) {
  _reql_null_init(obj);

  obj->obj.datum.dt = _REQL_R_STR;
  obj->obj.datum.json.string.str = str;
  obj->obj.datum.json.string.alloc_size = size;
}

uint8_t *_reql_string_buf(_ReQL_Op obj) {
  return obj->obj.datum.json.string.str;
}

uint32_t _reql_string_size(_ReQL_Op obj) {
  return obj->obj.datum.json.string.size;
}

void _reql_iter_init(_ReQL_Iter res, _ReQL_Op obj) {
  res->idx = 0;
  res->obj = obj;
}

_ReQL_Op _reql_iter_next(_ReQL_Iter obj) {
  _ReQL_Op next = NULL;

  if (_reql_datum_type(obj->obj) == _REQL_R_ARRAY) {
    if (obj->obj->obj.datum.json.array.alloc_size < obj->idx) {
      next = _reql_array_index(obj->obj, obj->idx);
      obj->idx += 1;
    }
  } else {
    if (obj->obj->obj.datum.json.object.alloc_size < obj->idx) {
      next = obj->obj->obj.datum.json.object.pair[obj->idx].key;
      obj->idx += 1;
    }
  }

  return next;
}

void _reql_array_init(_ReQL_Op obj, _ReQL_Op *arr, uint32_t size) {
  uint32_t i;

  for (i=0; i<size; ++i) {
    arr[i] = NULL;
  }

  _reql_null_init(obj);

  obj->obj.datum.dt = _REQL_R_ARRAY;
  obj->obj.datum.json.array.arr = arr;
  obj->obj.datum.json.array.alloc_size = size;
  obj->obj.datum.json.array.size = 0;
}

uint32_t _reql_array_size(_ReQL_Op obj) {
  return obj->obj.datum.json.array.size;
}

size_t _reql_array_insert(_ReQL_Op obj, _ReQL_Op val, uint32_t idx) {
  if (idx >= obj->obj.datum.json.array.alloc_size) {
    size_t alloc_size = idx * 1.1;

    if (alloc_size < idx) {
      return SIZE_MAX;
    }

    return alloc_size * sizeof(_ReQL_Op);
  }

  if (idx > obj->obj.datum.json.array.size) {
    obj->obj.datum.json.array.size = idx;
  }

  obj->obj.datum.json.array.arr[idx] = val;

  return 0;
}

_ReQL_Op _reql_array_index(_ReQL_Op obj, uint32_t idx) {
  if (obj->obj.datum.json.array.alloc_size <= idx) {
    return NULL;
  }

  return obj->obj.datum.json.array.arr[idx];
}

size_t _reql_array_append(_ReQL_Op obj, _ReQL_Op val) {
  uint32_t size = _reql_array_size(obj);
  return _reql_array_insert(obj, val, size + 1);
}

_ReQL_Op _reql_array_pop(_ReQL_Op obj) {
  _ReQL_Op res = _reql_array_last(obj);

  if (res) {
    obj->obj.datum.json.array.size -= 1;
  }

  return res;
}

_ReQL_Op _reql_array_last(_ReQL_Op obj) {
  return _reql_array_index(obj, _reql_array_size(obj));
}

void _reql_object_init(_ReQL_Op obj, _ReQL_Pair pairs, uint32_t size) {
  uint32_t i;

  for (i=0; i<10; ++i) {
    pairs[i].key = NULL;
    pairs[i].val = NULL;
  }

  _reql_null_init(obj);

  obj->obj.datum.dt = _REQL_R_OBJECT;
  obj->obj.datum.json.object.pair = pairs;
  obj->obj.datum.json.object.size = 0;
  obj->obj.datum.json.object.alloc_size = size;
}

char _reql_op_eq(_ReQL_Op l, _ReQL_Op r) {
  char res = 0;
  if (l == r) {
    res = 1;
  } else {
    if ((l && r)) {
      if (l->tt == r->tt) {
        if (l->tt == _REQL_DATUM) {
          if (l->obj.datum.dt == r->obj.datum.dt) {
            switch (l->obj.datum.dt) {
              case _REQL_R_ARRAY: {
                uint32_t l_size = _reql_array_size(l), r_size = _reql_array_size(r);
                if (l_size == r_size) {
                  res = 1;
                  uint32_t i;
                  for (i=0; i<l_size; ++i) {
                    res &= _reql_op_eq(_reql_array_index(l, i), _reql_array_index(r, i));
                  }
                }
                break;
              }
              case _REQL_R_BOOL: {
                res = _reql_to_bool(l) == _reql_to_bool(r);
                break;
              }
              case _REQL_R_NULL: {
                res = 1;
                break;
              }
              case _REQL_R_NUM: {
                res = _reql_to_number(l) == _reql_to_number(r);
                break;
              }
              case _REQL_R_OBJECT: {
                _ReQL_Iter i = malloc(sizeof(_ReQL_Iter_t));
                _reql_iter_init(i, l);

                res = 1;
                _ReQL_Op key = NULL;

                while ((key = _reql_iter_next(i))) {
                  res &= _reql_op_eq(_reql_object_get(l, key), _reql_object_get(r, key));
                }

                _reql_iter_init(i, r);

                while ((key = _reql_iter_next(i))) {
                  res &= _reql_op_eq(_reql_object_get(l, key), _reql_object_get(r, key));
                }

                free(i); i = NULL;
                break;
              }
              case _REQL_R_STR: {
                uint32_t size = _reql_string_size(l);

                if (size == _reql_string_size(r)) {
                  res = !memcmp(_reql_string_buf(r), _reql_string_buf(r), size);
                }
                break;
              }
              case _REQL_R_REQL:
              case _REQL_R_JSON: break;
            }
          }
        } else {
          if (_reql_op_eq(l->obj.args.args, r->obj.args.args)) {
            res = _reql_op_eq(l->obj.args.kwargs, r->obj.args.kwargs);
          }
        }
      }
    }
  }
  return res;
}

size_t _reql_object_add(_ReQL_Op obj, _ReQL_Op key, _ReQL_Op val) {
  _ReQL_Pair_t *pair = obj->obj.datum.json.object.pair;

  uint32_t idx;

  for (idx=0; idx<obj->obj.datum.json.object.size; ++idx) {
    if (_reql_op_eq(pair[idx].key, key)) {
      pair[idx].key = NULL;
      break;
    }
  }

  if (pair[idx].key) {
    ++idx;
  }

  if (idx >= obj->obj.datum.json.object.alloc_size) {
    obj->obj.datum.json.object.alloc_size *= 1.1;

    pair = realloc(pair, obj->obj.datum.json.object.alloc_size);

    if (!pair) {
      obj->obj.datum.json.object.alloc_size = 0;
      obj->obj.datum.json.object.size = 0;
      return -1;
    }

    uint32_t i;

    for (i=obj->obj.datum.json.array.size; i<obj->obj.datum.json.array.alloc_size; ++i) {
      pair[i].key = NULL;
      pair[i].val = NULL;
    }

    obj->obj.datum.json.object.pair = pair;
  }

  if (idx > obj->obj.datum.json.object.size) {
    obj->obj.datum.json.object.size = idx;
  }

  pair[idx].key = key;
  pair[idx].val = val;

  return 0;
}

int _reql_object_next(_ReQL_Iter obj, _ReQL_Op *key, _ReQL_Op *val) {
  if (!obj) {
    return -1;
  }

  if (!obj) {
    return -1;
  }

  uint32_t size = obj->obj->obj.datum.json.object.size;

  if (obj->idx >= size) {
    return -1;
  }

  if (obj->obj->obj.datum.json.object.pair[obj->idx].key) {
    if (key && val) {
      *key = obj->obj->obj.datum.json.object.pair[obj->idx].key;
      *val = obj->obj->obj.datum.json.object.pair[obj->idx].val;
    }
  }

  obj->idx += 1;

  return 0;
}

_ReQL_Op _reql_object_get(_ReQL_Op obj, _ReQL_Op key) {
  _ReQL_Iter iter = malloc(sizeof(_ReQL_Iter_t));

  if (!iter) {
    return NULL;
  }

  _reql_iter_init(iter, obj);

  _ReQL_Op _key = NULL, val = NULL;

  while ((_key = _reql_iter_next(iter)) != NULL) {
    if (_reql_op_eq(key, _key)) {
      val = _reql_object_get(obj, key);
      break;
    }
  }

  free(iter);

  return NULL;
}

void _reql_null_init(_ReQL_Op obj) {
  obj->tt = _REQL_DATUM;
  obj->obj.datum.dt = _REQL_R_NULL;
}

void _reql_bool_init(_ReQL_Op obj, char val) {
  _reql_null_init(obj);

  obj->obj.datum.dt = _REQL_R_BOOL;
  obj->obj.datum.json.boolean = val;
}

char _reql_to_bool(_ReQL_Op obj) {
  return obj->obj.datum.json.boolean;
}

void _reql_expr_copy(_ReQL_Op obj, _ReQL_Op orig) {
  obj->tt = orig->tt;
  obj->obj = orig->obj;
}
