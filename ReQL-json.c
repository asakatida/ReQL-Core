/*
Copyright 2014-2015 Adam Grandquist

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

extern _ReQL_Datum_t
_reql_datum_type(_ReQL_Op obj) {
  if (_reql_term_type(obj) != _REQL_DATUM) {
    return _REQL_R_REQL;
  }

  return obj->obj.datum.dt;
}

extern _ReQL_Term_t
_reql_term_type(_ReQL_Op obj) {
  return obj->tt;
}

extern void
_reql_number_init(_ReQL_Op obj, double num) {
  _reql_null_init(obj);

  obj->obj.datum.dt = _REQL_R_NUM;
  obj->obj.datum.json.number = num;
}

extern double
_reql_to_number(_ReQL_Op obj) {
  return obj->obj.datum.json.number;
}

extern void
_reql_string_init(_ReQL_Op obj, uint8_t *str, uint32_t size, uint32_t alloc_size) {
  _reql_null_init(obj);

  obj->obj.datum.dt = _REQL_R_STR;
  obj->obj.datum.json.string.str = str;
  obj->obj.datum.json.string.size = size;
  obj->obj.datum.json.string.alloc_size = alloc_size;
}

extern uint8_t *
_reql_string_buf(_ReQL_Op obj) {
  return obj->obj.datum.json.string.str;
}

extern uint32_t
_reql_string_size(_ReQL_Op obj) {
  return obj->obj.datum.json.string.size;
}

extern _ReQL_Iter_t
_reql_new_iter(_ReQL_Op obj) {
  _ReQL_Iter_t iter;
  iter.idx = 0;
  iter.obj = obj;
  return iter;
}

extern _ReQL_Pair
_reql_object_index(_ReQL_Op obj, uint32_t idx) {
  if (obj->obj.datum.json.object.alloc_size <= idx) {
    return NULL;
  }

  return &obj->obj.datum.json.object.pair[idx];
}

extern _ReQL_Op
_reql_iter_next(_ReQL_Iter_t *obj) {
  _ReQL_Op next = NULL;

  if (_reql_datum_type(obj->obj) == _REQL_R_ARRAY) {
    if (obj->obj->obj.datum.json.array.alloc_size < obj->idx) {
      next = _reql_array_index(obj->obj, obj->idx);
    }
  } else {
    if (obj->obj->obj.datum.json.object.alloc_size < obj->idx) {
      next = _reql_object_index(obj->obj, obj->idx)->key;
    }
  }

  if (next != NULL) {
    obj->idx += 1;
  }

  return next;
}

extern void
_reql_array_init(_ReQL_Op obj, _ReQL_Op *arr, uint32_t size) {
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

extern uint32_t
_reql_array_size(_ReQL_Op obj) {
  return obj->obj.datum.json.array.size;
}

extern size_t
_reql_array_insert(_ReQL_Op obj, _ReQL_Op val, uint32_t idx) {
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

extern _ReQL_Op
_reql_array_index(_ReQL_Op obj, uint32_t idx) {
  if (obj->obj.datum.json.array.alloc_size <= idx) {
    return NULL;
  }

  return obj->obj.datum.json.array.arr[idx];
}

extern size_t
_reql_array_append(_ReQL_Op obj, _ReQL_Op val) {
  uint32_t size = _reql_array_size(obj);
  return _reql_array_insert(obj, val, size + 1);
}

extern _ReQL_Op
_reql_array_pop(_ReQL_Op obj) {
  _ReQL_Op res = _reql_array_last(obj);
  _reql_array_insert(obj, NULL, _reql_array_size(obj));

  if (res) {
    obj->obj.datum.json.array.size -= 1;
  }

  return res;
}

extern _ReQL_Op
_reql_array_last(_ReQL_Op obj) {
  return _reql_array_index(obj, _reql_array_size(obj));
}

extern void
_reql_object_init(_ReQL_Op obj, _ReQL_Pair pairs, uint32_t size) {
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

extern char
_reql_op_eq(_ReQL_Op l, _ReQL_Op r) {
  char res = 0;
  if (l == r) {
    res = 1;
  } else {
    if ((l && r)) {
      if (_reql_term_type(l) == _reql_term_type(r)) {
        if (_reql_term_type(l) == _REQL_DATUM) {
          if (_reql_datum_type(l) == _reql_datum_type(r)) {
            switch (_reql_datum_type(l)) {
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
                _ReQL_Iter_t i = _reql_new_iter(l);

                res = 1;
                _ReQL_Op key = NULL;

                while ((key = _reql_iter_next(&i))) {
                  res &= _reql_op_eq(_reql_object_get(l, key), _reql_object_get(r, key));
                }

                i = _reql_new_iter(r);

                while ((key = _reql_iter_next(&i))) {
                  res &= _reql_op_eq(_reql_object_get(l, key), _reql_object_get(r, key));
                }
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

static int
_reql_key_sort(const void *l, const void *r) {
  if (l == NULL && r == NULL) {
    return 0;
  } else if (l == NULL) {
    return -1;
  } else if (r == NULL) {
    return 1;
  }
  _ReQL_Pair lobj = (_ReQL_Pair)l;
  _ReQL_Pair robj = (_ReQL_Pair)r;
  if (lobj->key == NULL && robj->key == NULL) {
    return 0;
  } else if (lobj->key == NULL) {
    return -1;
  } else if (robj->key == NULL) {
    return 1;
  }
  uint32_t lsize = _reql_string_size(lobj->key);
  uint32_t rsize = _reql_string_size(robj->key);
  if (lsize == rsize) {
    return memcmp(_reql_string_buf(lobj->key), _reql_string_buf(robj->key), lsize);
  } else if (lsize < rsize) {
    return -1;
  }
  return 1;
}

static _ReQL_Pair
_reql_object_find(_ReQL_Op obj, _ReQL_Op key) {
  _ReQL_Pair pair = obj->obj.datum.json.object.pair;
  _ReQL_Pair_t test;
  test.key = key;

  return bsearch(&test, pair, obj->obj.datum.json.object.size, sizeof(_ReQL_Pair_t), _reql_key_sort);
}

extern size_t
_reql_object_add(_ReQL_Op obj, _ReQL_Op key, _ReQL_Op val) {
  _ReQL_Pair pair = _reql_object_find(obj, key);

  if (pair == NULL) {
    if (obj->obj.datum.json.object.pair[obj->obj.datum.json.object.size].key != NULL) {
      obj->obj.datum.json.object.size += 1;
    }

    if (obj->obj.datum.json.object.size >= obj->obj.datum.json.object.alloc_size) {
      size_t alloc_size = obj->obj.datum.json.object.alloc_size * 1.1;

      if (alloc_size < obj->obj.datum.json.object.alloc_size) {
        return SIZE_MAX;
      }

      return alloc_size * sizeof(_ReQL_Pair_t);
    }

    pair = _reql_object_index(obj, obj->obj.datum.json.object.size);
    pair->key = key;
    pair->val = val;

    qsort(pair, obj->obj.datum.json.object.size, sizeof(_ReQL_Pair_t), _reql_key_sort);
  } else {
    pair->val = val;
  }

  return 0;
}

extern _ReQL_Op
_reql_object_get(_ReQL_Op obj, _ReQL_Op key) {
  _ReQL_Pair pair = _reql_object_find(obj, key);

  if (pair == NULL) {
    return NULL;
  }

  return pair->val;
}

extern void
_reql_null_init(_ReQL_Op obj) {
  obj->tt = _REQL_DATUM;
  obj->obj.datum.dt = _REQL_R_NULL;
}

extern void
_reql_bool_init(_ReQL_Op obj, char val) {
  _reql_null_init(obj);

  obj->obj.datum.dt = _REQL_R_BOOL;
  obj->obj.datum.json.boolean = val ? 1 : 0;
}

extern char
_reql_to_bool(_ReQL_Op obj) {
  return obj->obj.datum.json.boolean;
}
