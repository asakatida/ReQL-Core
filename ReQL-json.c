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

static void
_reql_obj_set_term_type(_ReQL_Obj_t *obj, const _ReQL_Term_t type) {
  obj->tt = type;
}

extern _ReQL_Term_t
_reql_obj_term_type(_ReQL_Obj_t *obj) {
  return obj->tt;
}

static void
_reql_obj_set_args(_ReQL_Obj_t *obj, _ReQL_Obj_t *args) {
  obj->obj.args.args = args;
}

static _ReQL_Obj_t *
_reql_obj_args(_ReQL_Obj_t *obj) {
  return obj->obj.args.args;
}

static void
_reql_obj_set_kwargs(_ReQL_Obj_t *obj, _ReQL_Obj_t *kwargs) {
  obj->obj.args.kwargs = kwargs;
}

static _ReQL_Obj_t *
_reql_obj_kwargs(_ReQL_Obj_t *obj) {
  return obj->obj.args.kwargs;
}

static void
_reql_obj_set_datum_type(_ReQL_Obj_t *obj, const _ReQL_Datum_t type) {
  if (_reql_obj_term_type(obj) == _REQL_DATUM) {
    obj->obj.datum.dt = type;
  }
}

extern _ReQL_Datum_t
_reql_datum_type(_ReQL_Obj_t *obj) {
  if (_reql_obj_term_type(obj) != _REQL_DATUM) {
    return _REQL_R_REQL;
  }

  return obj->obj.datum.dt;
}

static void
_reql_obj_set_alloc_size(_ReQL_Obj_t *obj, uint32_t alloc_size) {
  obj->obj.datum.json.alloc_size = alloc_size;
}

static uint32_t
_reql_obj_alloc_size(_ReQL_Obj_t *obj) {
  return obj->obj.datum.json.alloc_size;
}

static void
_reql_obj_set_array(_ReQL_Obj_t *obj, _ReQL_Obj_t **array) {
  obj->obj.datum.json.array = array;
}

static _ReQL_Obj_t **
_reql_obj_array(_ReQL_Obj_t *obj) {
  return obj->obj.datum.json.array;
}

static void
_reql_obj_set_boolean(_ReQL_Obj_t *obj, char boolean) {
  obj->obj.datum.json.boolean = boolean;
}

static void
_reql_obj_set_number(_ReQL_Obj_t *obj, double number) {
  obj->obj.datum.json.number = number;
}

static void
_reql_obj_set_pair(_ReQL_Obj_t *obj, _ReQL_Pair_t *pair) {
  obj->obj.datum.json.pair = pair;
}

static _ReQL_Pair_t *
_reql_obj_pair(_ReQL_Obj_t *obj) {
  return obj->obj.datum.json.pair;
}

static void
_reql_obj_set_size(_ReQL_Obj_t *obj, uint32_t size) {
  obj->obj.datum.json.size = size;
}

static uint32_t
_reql_obj_size(_ReQL_Obj_t *obj) {
  return obj->obj.datum.json.size;
}

static uint32_t
_reql_obj_ensure_space(_ReQL_Obj_t *obj, uint32_t size) {
  size += _reql_obj_size(obj);

  if (_reql_obj_alloc_size(obj) < size) {
    return size * 1.1;
  }

  return 0;
}

static void
_reql_var_obj_init(_ReQL_Obj_t *obj, _ReQL_Datum_t dt, uint32_t alloc_size) {
  _reql_null_init(obj);

  _reql_obj_set_datum_type(obj, dt);
  _reql_obj_set_alloc_size(obj, alloc_size);
  _reql_obj_set_size(obj, 0);
}

static void
_reql_obj_set_str(_ReQL_Obj_t *obj, uint8_t *str) {
  obj->obj.datum.json.str = str;
}

extern void
_reql_number_init(_ReQL_Obj_t *obj, double num) {
  _reql_null_init(obj);

  _reql_obj_set_datum_type(obj, _REQL_R_NUM);
  _reql_obj_set_number(obj, num);
}

extern double
_reql_to_number(_ReQL_Obj_t *obj) {
  return obj->obj.datum.json.number;
}

extern void
_reql_string_init(_ReQL_Obj_t *obj, uint8_t *str, uint32_t alloc_size) {
  _reql_var_obj_init(obj, _REQL_R_STR, alloc_size);

  _reql_obj_set_str(obj, str);
}

extern uint8_t *
_reql_string_buf(_ReQL_Obj_t *obj) {
  return obj->obj.datum.json.str;
}

extern uint32_t
_reql_string_append(_ReQL_Obj_t *obj, const uint8_t *ext, uint32_t size) {
  uint32_t new_alloc = _reql_obj_ensure_space(obj, size);

  if (new_alloc != 0) {
    return new_alloc;
  }

  uint8_t *buf = _reql_string_buf(obj);
  uint32_t old_size = _reql_obj_size(obj);

  memcpy(&buf[old_size], ext, size);

  _reql_obj_set_size(obj, old_size + size);

  return 0;
}

extern uint32_t
_reql_string_size(_ReQL_Obj_t *obj) {
  return _reql_obj_size(obj);
}

extern _ReQL_Iter_t
_reql_new_iter(_ReQL_Obj_t *obj) {
  _ReQL_Iter_t iter;
  iter.idx = 0;
  iter.obj = obj;
  return iter;
}

extern _ReQL_Pair_t *
_reql_object_index(_ReQL_Obj_t *obj, uint32_t idx) {
  if (_reql_obj_alloc_size(obj) <= idx) {
    return NULL;
  }

  return &obj->obj.datum.json.pair[idx];
}

extern _ReQL_Obj_t *
_reql_iter_next(_ReQL_Iter_t *obj) {
  _ReQL_Obj_t *next = NULL;

  if (_reql_obj_alloc_size(obj->obj) < obj->idx) {
    if (_reql_datum_type(obj->obj) == _REQL_R_ARRAY) {
      next = _reql_array_index(obj->obj, obj->idx);
    } else {
      next = _reql_object_index(obj->obj, obj->idx)->key;
    }
  }

  if (next != NULL) {
    obj->idx += 1;
  }

  return next;
}

extern void
_reql_array_init(_ReQL_Obj_t *obj, _ReQL_Obj_t **arr, uint32_t alloc_size) {
  uint32_t i;

  for (i=0; i<alloc_size; ++i) {
    arr[i] = NULL;
  }

  _reql_var_obj_init(obj, _REQL_R_ARRAY, alloc_size);

  _reql_obj_set_array(obj, arr);
}

extern uint32_t
_reql_array_size(_ReQL_Obj_t *obj) {
  return _reql_obj_size(obj);
}

extern uint32_t
_reql_array_insert(_ReQL_Obj_t *obj, _ReQL_Obj_t *val, uint32_t idx) {
  uint32_t size = _reql_obj_size(obj);
  if (idx >= size) {
    uint32_t new_alloc = _reql_obj_ensure_space(obj, idx - size + 1);

    if (new_alloc != 0) {
      return new_alloc;
    }

    _reql_obj_set_size(obj, idx + 1);
  }

  _ReQL_Obj_t **arr = _reql_obj_array(obj);

  arr[idx] = val;

  return 0;
}

extern _ReQL_Obj_t *
_reql_array_index(_ReQL_Obj_t *obj, uint32_t idx) {
  if (_reql_obj_alloc_size(obj) <= idx) {
    return NULL;
  }

  return _reql_obj_array(obj)[idx];
}

extern uint32_t
_reql_array_append(_ReQL_Obj_t *obj, _ReQL_Obj_t *val) {
  return _reql_array_insert(obj, val, _reql_array_size(obj));
}

extern _ReQL_Obj_t *
_reql_array_pop(_ReQL_Obj_t *obj) {
  _ReQL_Obj_t *res = _reql_array_last(obj);

  if (res != NULL) {
    uint32_t size = _reql_array_size(obj) - 1;
    _reql_array_insert(obj, NULL, size);
    _reql_obj_set_size(obj, size);
  }

  return res;
}

extern _ReQL_Obj_t *
_reql_array_last(_ReQL_Obj_t *obj) {
  return _reql_array_index(obj, _reql_array_size(obj) - 1);
}

extern void
_reql_object_init(_ReQL_Obj_t *obj, _ReQL_Pair_t *pairs, uint32_t alloc_size) {
  uint32_t i;

  for (i=0; i<alloc_size; ++i) {
    pairs[i].key = NULL;
    pairs[i].val = NULL;
  }

  _reql_var_obj_init(obj, _REQL_R_OBJECT, alloc_size);

  _reql_obj_set_pair(obj, pairs);
}

static char
_reql_obj_type_eq(_ReQL_Obj_t *l, _ReQL_Obj_t *r) {
  char res = 0;
  if (l == r) {
    res = 1;
  } else {
    if ((l != NULL) && (r != NULL)) {
      if (_reql_obj_term_type(l) == _reql_obj_term_type(r)) {
        if (_reql_datum_type(l) == _reql_datum_type(r)) {
          res = 1;
        }
      }
    }
  }
  return res;
}

extern char
_reql_op_eq(_ReQL_Obj_t *l, _ReQL_Obj_t *r) {
  char res = _reql_obj_type_eq(l, r);
  if (res) {
    if (_reql_obj_term_type(l) == _REQL_DATUM) {
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
          _ReQL_Obj_t *key = NULL;

          while ((key = _reql_iter_next(&i)) != NULL) {
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
            res = memcmp(_reql_string_buf(r), _reql_string_buf(r), size) == 0;
          }
          break;
        }
        case _REQL_R_REQL:
        case _REQL_R_JSON: break;
      }
    } else {
      if (_reql_op_eq(_reql_obj_args(l), _reql_obj_args(r))) {
        res = _reql_op_eq(_reql_obj_kwargs(l), _reql_obj_kwargs(r));
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
  _ReQL_Pair_t *lobj = (_ReQL_Pair_t *)l;
  _ReQL_Pair_t *robj = (_ReQL_Pair_t *)r;
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

static _ReQL_Pair_t *
_reql_object_find(_ReQL_Obj_t *obj, _ReQL_Pair_t *key) {
  return bsearch(key, _reql_obj_pair(obj), _reql_obj_size(obj), sizeof(_ReQL_Pair_t), _reql_key_sort);
}

extern uint32_t
_reql_object_add(_ReQL_Obj_t *obj, _ReQL_Obj_t *key, _ReQL_Obj_t *val) {
  _ReQL_Pair_t test = {key, NULL};
  _ReQL_Pair_t *pair = _reql_object_find(obj, &test);

  if (pair == NULL) {
    uint32_t size = _reql_obj_size(obj);
    pair = _reql_obj_pair(obj);

    if (pair[size].key != NULL) {
      size += 1;

      uint32_t new_alloc = _reql_obj_ensure_space(obj, size);

      if (new_alloc != 0) {
        return new_alloc;
      }
    }

    pair[size].key = key;
    pair[size].val = val;

    size += 1;

    qsort(pair, size, sizeof(_ReQL_Pair_t), _reql_key_sort);

    _reql_obj_set_size(obj, size);
  } else {
    pair->val = val;
  }

  return 0;
}

extern _ReQL_Obj_t *
_reql_object_get(_ReQL_Obj_t *obj, _ReQL_Obj_t *key) {
  _ReQL_Pair_t test = {key, NULL};
  _ReQL_Pair_t *pair = _reql_object_find(obj, &test);

  if (pair == NULL) {
    return NULL;
  }

  return pair->val;
}

extern void
_reql_null_init(_ReQL_Obj_t *obj) {
  _reql_obj_set_term_type(obj, _REQL_DATUM);
  _reql_obj_set_datum_type(obj, _REQL_R_NULL);
}

extern void
_reql_bool_init(_ReQL_Obj_t *obj, char val) {
  _reql_null_init(obj);

  _reql_obj_set_datum_type(obj, _REQL_R_BOOL);
  _reql_obj_set_boolean(obj, val ? 1 : 0);
}

extern char
_reql_to_bool(_ReQL_Obj_t *obj) {
  return obj->obj.datum.json.boolean;
}

static void
_reql_arr_destroy(_ReQL_Obj_t **arr, int32_t size) {
  if (arr == NULL) {
    return;
  }

  int32_t i;

  for (i=0; i<size; ++i) {
    _reql_json_destroy(arr[i]);
  }

  free(arr);
}

static void
_reql_pair_destroy(_ReQL_Pair_t *pair, uint32_t size) {
  if (pair == NULL) {
    return;
  }

  uint32_t i;

  for (i=0; i<size; ++i) {
    _reql_json_destroy(pair[i].key);
    _reql_json_destroy(pair[i].val);
  }

  free(pair);
}

extern void
_reql_json_destroy(_ReQL_Obj_t *json) {
  if (json == NULL) {
    return;
  }

  switch (_reql_datum_type(json)) {
    case _REQL_R_ARRAY: {
      _reql_arr_destroy(_reql_obj_array(json), _reql_obj_alloc_size(json));
      break;
    }
    case _REQL_R_BOOL:
    case _REQL_R_JSON:
    case _REQL_R_NULL:
    case _REQL_R_NUM: break;
    case _REQL_R_OBJECT: {
      _reql_pair_destroy(_reql_obj_pair(json), _reql_obj_alloc_size(json));
      break;
    }
    case _REQL_R_REQL: {
      _reql_json_destroy(_reql_obj_args(json));
      _reql_json_destroy(_reql_obj_kwargs(json));
      break;
    }
    case _REQL_R_STR: {
      uint8_t *buf = _reql_string_buf(json);
      if (buf != NULL) {
        free(buf);
      }
      break;
    }
  }

  free(json);
}
