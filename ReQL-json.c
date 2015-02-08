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

extern void
reql_obj_set_term_type(ReQL_Obj_t *obj, const ReQL_Term_t type) {
  obj->tt = type;
}

extern ReQL_Term_t
reql_obj_term_type(ReQL_Obj_t *obj) {
  return obj->tt;
}

extern void
reql_obj_set_args(ReQL_Obj_t *obj, ReQL_Obj_t *args) {
  obj->obj.args.args = args;
}

extern ReQL_Obj_t *
reql_obj_args(ReQL_Obj_t *obj) {
  return obj->obj.args.args;
}

extern void
reql_obj_set_kwargs(ReQL_Obj_t *obj, ReQL_Obj_t *kwargs) {
  obj->obj.args.kwargs = kwargs;
}

extern ReQL_Obj_t *
reql_obj_kwargs(ReQL_Obj_t *obj) {
  return obj->obj.args.kwargs;
}

static void
reql_obj_set_datum_type(ReQL_Obj_t *obj, const ReQL_Datum_t type) {
  if (reql_obj_term_type(obj) == REQL_DATUM) {
    obj->obj.datum.dt = type;
  }
}

extern ReQL_Datum_t
reql_datum_type(ReQL_Obj_t *obj) {
  if (reql_obj_term_type(obj) != REQL_DATUM) {
    return REQL_R_REQL;
  }

  return obj->obj.datum.dt;
}

static void
reql_obj_set_alloc_size(ReQL_Obj_t *obj, uint32_t alloc_size) {
  obj->obj.datum.json.alloc_size = alloc_size;
}

static uint32_t
reql_obj_alloc_size(ReQL_Obj_t *obj) {
  return obj->obj.datum.json.alloc_size;
}

static void
reql_obj_set_array(ReQL_Obj_t *obj, ReQL_Obj_t **array) {
  obj->obj.datum.json.array = array;
}

static ReQL_Obj_t **
reql_obj_array(ReQL_Obj_t *obj) {
  return obj->obj.datum.json.array;
}

static void
reql_obj_set_boolean(ReQL_Obj_t *obj, char boolean) {
  obj->obj.datum.json.boolean = boolean;
}

static void
reql_obj_set_number(ReQL_Obj_t *obj, double number) {
  obj->obj.datum.json.number = number;
}

static void
reql_obj_set_pair(ReQL_Obj_t *obj, ReQL_Pair_t *pair) {
  obj->obj.datum.json.pair = pair;
}

static ReQL_Pair_t *
reql_obj_pair(ReQL_Obj_t *obj) {
  return obj->obj.datum.json.pair;
}

static void
reql_obj_set_size(ReQL_Obj_t *obj, uint32_t size) {
  obj->obj.datum.json.size = size;
}

static uint32_t
reql_obj_size(ReQL_Obj_t *obj) {
  return obj->obj.datum.json.size;
}

static uint32_t
reql_obj_ensure_space(ReQL_Obj_t *obj, uint32_t size) {
  size += reql_obj_size(obj);

  if (reql_obj_alloc_size(obj) < size) {
    return size * 1.1;
  }

  return 0;
}

static void
reql_var_obj_init(ReQL_Obj_t *obj, ReQL_Datum_t dt, uint32_t alloc_size) {
  reql_null_init(obj);

  reql_obj_set_datum_type(obj, dt);
  reql_obj_set_alloc_size(obj, alloc_size);
  reql_obj_set_size(obj, 0);
}

static void
reql_obj_set_str(ReQL_Obj_t *obj, uint8_t *str) {
  obj->obj.datum.json.str = str;
}

extern void
reql_number_init(ReQL_Obj_t *obj, double num) {
  reql_null_init(obj);

  reql_obj_set_datum_type(obj, REQL_R_NUM);
  reql_obj_set_number(obj, num);
}

extern double
reql_to_number(ReQL_Obj_t *obj) {
  return obj->obj.datum.json.number;
}

extern void
reql_string_init(ReQL_Obj_t *obj, uint8_t *str, uint32_t alloc_size) {
  reql_var_obj_init(obj, REQL_R_STR, alloc_size);

  reql_obj_set_str(obj, str);
}

extern uint8_t *
reql_string_buf(ReQL_Obj_t *obj) {
  return obj->obj.datum.json.str;
}

extern uint32_t
reql_string_append(ReQL_Obj_t *obj, const uint8_t *ext, uint32_t size) {
  uint32_t new_alloc = reql_obj_ensure_space(obj, size);

  if (new_alloc != 0) {
    return new_alloc;
  }

  uint8_t *buf = reql_string_buf(obj);
  uint32_t old_size = reql_obj_size(obj);

  memcpy(&buf[old_size], ext, size);

  reql_obj_set_size(obj, old_size + size);

  return 0;
}

extern uint32_t
reql_string_size(ReQL_Obj_t *obj) {
  return reql_obj_size(obj);
}

extern ReQL_Iter_t
reql_new_iter(ReQL_Obj_t *obj) {
  ReQL_Iter_t iter;
  iter.idx = 0;
  iter.obj = obj;
  return iter;
}

extern ReQL_Pair_t *
reql_object_index(ReQL_Obj_t *obj, uint32_t idx) {
  if (reql_obj_alloc_size(obj) <= idx) {
    return NULL;
  }

  return &obj->obj.datum.json.pair[idx];
}

extern ReQL_Obj_t *
reql_iter_next(ReQL_Iter_t *obj) {
  ReQL_Obj_t *next = NULL;

  if (reql_obj_alloc_size(obj->obj) < obj->idx) {
    if (reql_datum_type(obj->obj) == REQL_R_ARRAY) {
      next = reql_array_index(obj->obj, obj->idx);
    } else {
      next = reql_object_index(obj->obj, obj->idx)->key;
    }
  }

  if (next != NULL) {
    obj->idx += 1;
  }

  return next;
}

extern void
reql_array_init(ReQL_Obj_t *obj, ReQL_Obj_t **arr, uint32_t alloc_size) {
  uint32_t i;

  for (i=0; i<alloc_size; ++i) {
    arr[i] = NULL;
  }

  reql_var_obj_init(obj, REQL_R_ARRAY, alloc_size);

  reql_obj_set_array(obj, arr);
}

extern uint32_t
reql_array_size(ReQL_Obj_t *obj) {
  return reql_obj_size(obj);
}

extern uint32_t
reql_array_insert(ReQL_Obj_t *obj, ReQL_Obj_t *val, uint32_t idx) {
  uint32_t size = reql_obj_size(obj);
  if (idx >= size) {
    uint32_t new_alloc = reql_obj_ensure_space(obj, idx - size + 1);

    if (new_alloc != 0) {
      return new_alloc;
    }

    reql_obj_set_size(obj, idx + 1);
  }

  ReQL_Obj_t **arr = reql_obj_array(obj);

  arr[idx] = val;

  return 0;
}

extern ReQL_Obj_t *
reql_array_index(ReQL_Obj_t *obj, uint32_t idx) {
  if (reql_obj_alloc_size(obj) <= idx) {
    return NULL;
  }

  return reql_obj_array(obj)[idx];
}

extern uint32_t
reql_array_append(ReQL_Obj_t *obj, ReQL_Obj_t *val) {
  return reql_array_insert(obj, val, reql_array_size(obj));
}

extern ReQL_Obj_t *
reql_array_pop(ReQL_Obj_t *obj) {
  ReQL_Obj_t *res = reql_array_last(obj);

  if (res != NULL) {
    uint32_t size = reql_array_size(obj) - 1;
    reql_array_insert(obj, NULL, size);
    reql_obj_set_size(obj, size);
  }

  return res;
}

extern ReQL_Obj_t *
reql_array_last(ReQL_Obj_t *obj) {
  return reql_array_index(obj, reql_array_size(obj) - 1);
}

extern void
reql_object_init(ReQL_Obj_t *obj, ReQL_Pair_t *pairs, uint32_t alloc_size) {
  uint32_t i;

  for (i=0; i<alloc_size; ++i) {
    pairs[i].key = NULL;
    pairs[i].val = NULL;
  }

  reql_var_obj_init(obj, REQL_R_OBJECT, alloc_size);

  reql_obj_set_pair(obj, pairs);
}

static char
reql_obj_type_eq(ReQL_Obj_t *l, ReQL_Obj_t *r) {
  char res = 0;
  if (l == r) {
    res = 1;
  } else {
    if ((l != NULL) && (r != NULL)) {
      if (reql_obj_term_type(l) == reql_obj_term_type(r)) {
        if (reql_datum_type(l) == reql_datum_type(r)) {
          res = 1;
        }
      }
    }
  }
  return res;
}

extern char
reql_op_eq(ReQL_Obj_t *l, ReQL_Obj_t *r) {
  char res = reql_obj_type_eq(l, r);
  if (res) {
    if (reql_obj_term_type(l) == REQL_DATUM) {
      switch (reql_datum_type(l)) {
        case REQL_R_ARRAY: {
          uint32_t l_size = reql_array_size(l), r_size = reql_array_size(r);
          if (l_size == r_size) {
            res = 1;
            uint32_t i;
            for (i=0; i<l_size; ++i) {
              res &= reql_op_eq(reql_array_index(l, i), reql_array_index(r, i));
            }
          }
          break;
        }
        case REQL_R_BOOL: {
          res = reql_to_bool(l) == reql_to_bool(r);
          break;
        }
        case REQL_R_NULL: {
          res = 1;
          break;
        }
        case REQL_R_NUM: {
          res = reql_to_number(l) == reql_to_number(r);
          break;
        }
        case REQL_R_OBJECT: {
          ReQL_Iter_t i = reql_new_iter(l);

          res = 1;
          ReQL_Obj_t *key = NULL;

          while ((key = reql_iter_next(&i)) != NULL) {
            res &= reql_op_eq(reql_object_get(l, key), reql_object_get(r, key));
          }

          i = reql_new_iter(r);

          while ((key = reql_iter_next(&i))) {
            res &= reql_op_eq(reql_object_get(l, key), reql_object_get(r, key));
          }
          break;
        }
        case REQL_R_STR: {
          uint32_t size = reql_string_size(l);

          if (size == reql_string_size(r)) {
            res = memcmp(reql_string_buf(r), reql_string_buf(r), size) == 0;
          }
          break;
        }
        case REQL_R_REQL:
        case REQL_R_JSON: break;
      }
    } else {
      if (reql_op_eq(reql_obj_args(l), reql_obj_args(r))) {
        res = reql_op_eq(reql_obj_kwargs(l), reql_obj_kwargs(r));
      }
    }
  }
  return res;
}

static int
reql_key_sort(const void *l, const void *r) {
  if (l == NULL && r == NULL) {
    return 0;
  } else if (l == NULL) {
    return -1;
  } else if (r == NULL) {
    return 1;
  }
  ReQL_Pair_t *lobj = (ReQL_Pair_t *)l;
  ReQL_Pair_t *robj = (ReQL_Pair_t *)r;
  if (lobj->key == NULL && robj->key == NULL) {
    return 0;
  } else if (lobj->key == NULL) {
    return -1;
  } else if (robj->key == NULL) {
    return 1;
  }
  uint32_t lsize = reql_string_size(lobj->key);
  uint32_t rsize = reql_string_size(robj->key);
  if (lsize == rsize) {
    return memcmp(reql_string_buf(lobj->key), reql_string_buf(robj->key), lsize);
  } else if (lsize < rsize) {
    return -1;
  }
  return 1;
}

static ReQL_Pair_t *
reql_object_find(ReQL_Obj_t *obj, ReQL_Pair_t *key) {
  return bsearch(key, reql_obj_pair(obj), reql_obj_size(obj), sizeof(ReQL_Pair_t), reql_key_sort);
}

extern uint32_t
reql_object_add(ReQL_Obj_t *obj, ReQL_Obj_t *key, ReQL_Obj_t *val) {
  ReQL_Pair_t test = {key, NULL};
  ReQL_Pair_t *pair = reql_object_find(obj, &test);

  if (pair == NULL) {
    uint32_t size = reql_obj_size(obj);
    pair = reql_obj_pair(obj);

    if (pair[size].key != NULL) {
      size += 1;

      uint32_t new_alloc = reql_obj_ensure_space(obj, size);

      if (new_alloc != 0) {
        return new_alloc;
      }
    }

    pair[size].key = key;
    pair[size].val = val;

    size += 1;

    qsort(pair, size, sizeof(ReQL_Pair_t), reql_key_sort);

    reql_obj_set_size(obj, size);
  } else {
    pair->val = val;
  }

  return 0;
}

extern ReQL_Obj_t *
reql_object_get(ReQL_Obj_t *obj, ReQL_Obj_t *key) {
  ReQL_Pair_t test = {key, NULL};
  ReQL_Pair_t *pair = reql_object_find(obj, &test);

  if (pair == NULL) {
    return NULL;
  }

  return pair->val;
}

extern void
reql_null_init(ReQL_Obj_t *obj) {
  reql_obj_set_term_type(obj, REQL_DATUM);
  reql_obj_set_datum_type(obj, REQL_R_NULL);
}

extern void
reql_bool_init(ReQL_Obj_t *obj, char val) {
  reql_null_init(obj);

  reql_obj_set_datum_type(obj, REQL_R_BOOL);
  reql_obj_set_boolean(obj, val ? 1 : 0);
}

extern char
reql_to_bool(ReQL_Obj_t *obj) {
  return obj->obj.datum.json.boolean;
}

static void
reql_arr_destroy(ReQL_Obj_t **arr, int32_t size) {
  if (arr == NULL) {
    return;
  }

  int32_t i;

  for (i=0; i<size; ++i) {
    reql_json_destroy(arr[i]);
  }

  free(arr);
}

static void
reql_pair_destroy(ReQL_Pair_t *pair, uint32_t size) {
  if (pair == NULL) {
    return;
  }

  uint32_t i;

  for (i=0; i<size; ++i) {
    reql_json_destroy(pair[i].key);
    reql_json_destroy(pair[i].val);
  }

  free(pair);
}

extern void
reql_json_destroy(ReQL_Obj_t *json) {
  if (json == NULL) {
    return;
  }

  switch (reql_datum_type(json)) {
    case REQL_R_ARRAY: {
      reql_arr_destroy(reql_obj_array(json), reql_obj_alloc_size(json));
      break;
    }
    case REQL_R_BOOL:
    case REQL_R_JSON:
    case REQL_R_NULL:
    case REQL_R_NUM: break;
    case REQL_R_OBJECT: {
      reql_pair_destroy(reql_obj_pair(json), reql_obj_alloc_size(json));
      break;
    }
    case REQL_R_REQL: {
      reql_json_destroy(reql_obj_args(json));
      reql_json_destroy(reql_obj_kwargs(json));
      break;
    }
    case REQL_R_STR: {
      uint8_t *buf = reql_string_buf(json);
      if (buf != NULL) {
        free(buf);
      }
      break;
    }
  }

  free(json);
}
