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

#include "./c/dev/json.h"

#include "./c/dev/error.h"

#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

extern ReQL_Term_t
reql_term_type(const ReQL_Obj_t *obj) {
  return obj->tt;
}

extern ReQL_Obj_t *
reql_args(const ReQL_Obj_t *obj) {
  return obj->obj.args.args;
}

extern ReQL_Obj_t *
reql_kwargs(const ReQL_Obj_t *obj) {
  return obj->obj.args.kwargs;
}

extern ReQL_Datum_t
reql_datum_type(const ReQL_Obj_t *obj) {
  if (reql_term_type(obj) != REQL_DATUM) {
    return REQL_R_REQL;
  }
  return obj->obj.datum.dt;
}

static ReQL_Size
reql_alloc_size(const ReQL_Obj_t *obj) {
  return obj->obj.datum.json.var.alloc_size;
}

static void
reql_set_array(ReQL_Obj_t *obj, ReQL_Obj_t **array) {
  obj->obj.datum.json.var.data.array = array;
}

static ReQL_Obj_t **
reql_array(const ReQL_Obj_t *obj) {
  return obj->obj.datum.json.var.data.array;
}

static void
reql_set_pair(ReQL_Obj_t *obj, ReQL_Pair_t *pair) {
  obj->obj.datum.json.var.data.pair = pair;
}

static ReQL_Pair_t *
reql_pair(const ReQL_Obj_t *obj) {
  return obj->obj.datum.json.var.data.pair;
}

static void
reql_set_size(ReQL_Obj_t *obj, const ReQL_Size size) {
  obj->obj.datum.json.var.size = size;
}

extern ReQL_Size
reql_size(const ReQL_Obj_t *obj) {
  return obj->obj.datum.json.var.size;
}

static ReQL_Obj_t *
reql_owner(ReQL_Obj_t *obj) {
  if (obj == NULL) {
    return NULL;
  }
  return obj->owner;
}

static ReQL_Size
reql_ensure_space(const ReQL_Obj_t *obj, ReQL_Size size) {
  if (reql_alloc_size(obj) < size) {
    const ReQL_Size min_size = (ReQL_Size)((double)(reql_size(obj) + size) * 1.1);

    if (min_size < size) {
      return UINT32_MAX;
    }
    
    return min_size;
  }

  return 0;
}

static void
reql_json_init(ReQL_Obj_t *obj, const ReQL_Datum_t dt) {
  reql_term_init(obj, REQL_DATUM, NULL, NULL);
  obj->obj.datum.dt = dt;
}

extern void
reql_term_init(ReQL_Obj_t *obj, const ReQL_Term_t tt, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  memset(obj, (int)NULL, sizeof(ReQL_Obj_t));
  obj->tt = tt;
  obj->obj.args.args = NULL;
  if (args != NULL) {
    if (reql_owner(args) == NULL) {
      obj->obj.args.args = args;
      args->owner = obj;
    } else {
      reql_error_init(REQL_E_JSON, "args array is already owned", __func__);
    }
  }
  obj->obj.args.kwargs = NULL;
  if (kwargs != NULL) {
    if (reql_owner(kwargs) == NULL) {
      obj->obj.args.kwargs = kwargs;
      kwargs->owner = obj;
    } else {
      reql_error_init(REQL_E_JSON, "kwargs object is already owned", __func__);
    }
  }
  obj->owner = NULL;
}

static void
reql_var_json_init(ReQL_Obj_t *obj, const ReQL_Datum_t dt, const ReQL_Size alloc_size) {
  reql_json_init(obj, dt);
  obj->obj.datum.json.var.alloc_size = alloc_size;
  reql_set_size(obj, 0);
}

static void
reql_set_str(ReQL_Obj_t *obj, ReQL_Byte *str) {
  obj->obj.datum.json.var.data.str = str;
}

extern void
reql_number_init(ReQL_Obj_t *obj, const double num) {
  reql_json_init(obj, REQL_R_NUM);
  obj->obj.datum.json.number = num;
}

extern double
reql_to_number(const ReQL_Obj_t *obj) {
  return obj->obj.datum.json.number;
}

extern void
reql_string_init(ReQL_Obj_t *obj, ReQL_Byte *str, const ReQL_Size alloc_size) {
  reql_var_json_init(obj, REQL_R_STR, alloc_size);
  reql_set_str(obj, str);
}

extern ReQL_Byte *
reql_string_buf(const ReQL_Obj_t *obj) {
  return obj->obj.datum.json.var.data.str;
}

extern ReQL_Size
reql_string_append(ReQL_Obj_t *obj, const ReQL_Byte *ext, const ReQL_Size size) {
  const ReQL_Size new_alloc = reql_ensure_space(obj, size);

  if (new_alloc != 0) {
    return new_alloc;
  }

  ReQL_Byte *buf = reql_string_buf(obj);
  const ReQL_Size old_size = reql_size(obj);

  memcpy(&buf[old_size], ext, size);

  reql_set_size(obj, old_size + size);

  return 0;
}

extern ReQL_Iter_t
reql_new_iter(const ReQL_Obj_t *obj) {
  ReQL_Iter_t iter;
  iter.idx = 0;
  iter.obj = obj;
  return iter;
}

extern ReQL_Obj_t *
reql_iter_next(ReQL_Iter_t *obj) {
  ReQL_Obj_t *next = NULL;

  if (reql_size(obj->obj) > obj->idx) {
    if (reql_datum_type(obj->obj) == REQL_R_ARRAY) {
      next = reql_array_index(obj->obj, obj->idx);
    } else if (reql_datum_type(obj->obj) == REQL_R_OBJECT) {
      next = reql_pair(obj->obj)[obj->idx].key;
    } else {
      return NULL;
    }
    ++obj->idx;
  }

  return next;
}

extern void
reql_array_init(ReQL_Obj_t *obj, ReQL_Obj_t **arr, const ReQL_Size alloc_size) {
  memset(arr, (int)NULL, sizeof(ReQL_Obj_t*) * alloc_size);
  reql_var_json_init(obj, REQL_R_ARRAY, alloc_size);
  reql_set_array(obj, arr);
}

extern ReQL_Size
reql_array_insert(ReQL_Obj_t *obj, ReQL_Obj_t *val, const ReQL_Size idx) {
  if (reql_owner(val) != NULL) {
    reql_error_init(REQL_E_JSON, "element already owned", __func__);
    return UINT32_MAX;
  }

  if (idx >= reql_size(obj)) {
    const ReQL_Size new_alloc = reql_ensure_space(obj, idx + 1);

    if (new_alloc != 0) {
      return new_alloc;
    }

    reql_set_size(obj, idx + 1);
  }

  ReQL_Obj_t **arr = reql_array(obj);

  arr[idx] = val;
  if (val != NULL) {
    val->owner = obj;
  }

  return 0;
}

extern ReQL_Obj_t *
reql_array_index(const ReQL_Obj_t *obj, const ReQL_Size idx) {
  if (reql_alloc_size(obj) <= idx) {
    return NULL;
  }

  return reql_array(obj)[idx];
}

extern ReQL_Size
reql_array_append(ReQL_Obj_t *obj, ReQL_Obj_t *val) {
  return reql_array_insert(obj, val, reql_size(obj));
}

extern ReQL_Obj_t *
reql_array_pop(ReQL_Obj_t *obj) {
  ReQL_Obj_t *res = reql_array_last(obj);

  ReQL_Size size = reql_size(obj);

  size = size > 0 ? size - 1 : 0;

  reql_set_size(obj, size);

  if (res != NULL) {
    reql_array_insert(obj, NULL, size);
    res->owner = NULL;
  } else if (size > 0) {
    return reql_array_pop(obj);
  }

  return res;
}

extern ReQL_Obj_t *
reql_array_last(const ReQL_Obj_t *obj) {
  return reql_array_index(obj, reql_size(obj) - 1);
}

extern void
reql_object_init(ReQL_Obj_t *obj, ReQL_Pair_t *pairs, const ReQL_Size alloc_size) {
  memset(pairs, (int)NULL, sizeof(ReQL_Pair_t) * alloc_size);
  reql_var_json_init(obj, REQL_R_OBJECT, alloc_size);
  reql_set_pair(obj, pairs);
}

static char
reql_type_eq(const ReQL_Obj_t *l, const ReQL_Obj_t *r) {
  char res = (l != NULL) && (r != NULL);
  if (res) {
    res = reql_term_type(l) == reql_term_type(r);
    if (res) {
      res = reql_datum_type(l) == reql_datum_type(r);
    }
  }
  return res;
}

extern char
reql_op_eq(const ReQL_Obj_t *l, const ReQL_Obj_t *r) {
  char res = l == r;
  if (res) {
    return res;
  }
  res = reql_type_eq(l, r);
  if (res) {
    switch (reql_datum_type(l)) {
      case REQL_R_ARRAY: {
        const ReQL_Size size = reql_size(l);
        res = size == reql_size(r);
        if (res) {
          ReQL_Size i;
          for (i=0; i < size; ++i) {
            res &= reql_op_eq(reql_array_index(l, i), reql_array_index(r, i));
          }
        }
        break;
      }
      case REQL_R_BOOL: {
        res = reql_to_bool(l) == reql_to_bool(r);
        break;
      }
      case REQL_R_NULL: break;
      case REQL_R_NUM: {
        res = fabsl((long double)reql_to_number(l) - reql_to_number(r)) <= LDBL_EPSILON;
        break;
      }
      case REQL_R_OBJECT: {
        res = reql_size(l) == reql_size(r);
        if (res) {
          ReQL_Iter_t i = reql_new_iter(l);

          ReQL_Obj_t *key = NULL;

          while ((key = reql_iter_next(&i)) != NULL) {
            res &= reql_op_eq(reql_object_get(l, key), reql_object_get(r, key));
          }

          i = reql_new_iter(r);

          while ((key = reql_iter_next(&i))) {
            res &= reql_op_eq(reql_object_get(l, key), reql_object_get(r, key));
          }
        }
        break;
      }
      case REQL_R_STR: {
        const ReQL_Size size = reql_size(l);

        res = size == reql_size(r);
        if (res) {
          res = memcmp(reql_string_buf(l), reql_string_buf(r), size) == 0;
        }

        break;
      }
      case REQL_R_REQL: {
        res = reql_op_eq(reql_args(l), reql_args(r));
        if (res) {
          res = reql_op_eq(reql_kwargs(l), reql_kwargs(r));
        }
        break;
      }
      case REQL_R_JSON: break;
    }
  }
  return res;
}

extern ReQL_Obj_t *
reql_obj_copy(const ReQL_Obj_t *other) {
  ReQL_Obj_t *self = malloc(sizeof(ReQL_Obj_t));

  if (self == NULL) {
    return NULL;
  }

  switch (reql_datum_type(other)) {
    case REQL_R_ARRAY: {
      const ReQL_Size size = reql_size(other);

      ReQL_Obj_t **array = malloc(size * sizeof(ReQL_Obj_t*));

      if (array == NULL) {
        free(self); self = NULL;
        return NULL;
      }

      reql_array_init(self, array, size);

      ReQL_Size i;
      for (i=0; i < size; ++i) {
        ReQL_Obj_t *elem = reql_array_index(other, i);
        if (elem != NULL) {
          elem = reql_obj_copy(elem);
          if (elem == NULL) {
            reql_json_destroy(self); self = NULL;
            return NULL;
          }
        }
        if (reql_array_insert(self, elem, i) != 0) {
          reql_json_destroy(self); self = NULL;
          return NULL;
        }
      }
      break;
    }
    case REQL_R_BOOL: {
      reql_bool_init(self, reql_to_bool(other));
      break;
    }
    case REQL_R_NULL: {
      reql_null_init(self);
      break;
    }
    case REQL_R_NUM: {
      reql_number_init(self, reql_to_number(other));
      break;
    }
    case REQL_R_OBJECT: {
      const ReQL_Size size = reql_size(other);

      ReQL_Pair_t *pairs = malloc(size * sizeof(ReQL_Pair_t));

      if (pairs == NULL) {
        free(self); self = NULL;
        return NULL;
      }

      reql_object_init(self, pairs, size);

      ReQL_Iter_t i = reql_new_iter(other);

      ReQL_Obj_t *key = NULL;
      ReQL_Obj_t *value = NULL;

      while ((key = reql_iter_next(&i)) != NULL) {
        key = reql_obj_copy(key);
        if (key == NULL) {
          reql_json_destroy(self); self = NULL;
          return NULL;
        }
        value = reql_object_get(other, key);
        if (value != NULL) {
          value = reql_obj_copy(value);
          if (value == NULL) {
            reql_json_destroy(key); key = NULL;
            reql_json_destroy(self); self = NULL;
            return NULL;
          }
        }
        if (reql_object_add(self, key, value) != 0) {
          reql_json_destroy(key); key = NULL;
          reql_json_destroy(value); value = NULL;
          reql_json_destroy(self); self = NULL;
          return NULL;
        }
      }
      break;
    }
    case REQL_R_STR: {
      const ReQL_Size size = reql_size(other);

      ReQL_Byte *buf = malloc(size * sizeof(ReQL_Byte));

      if (buf == NULL) {
        free(self); self = NULL;
        return NULL;
      }

      reql_string_init(self, buf, size);
      if (reql_string_append(self, reql_string_buf(other), size) != 0) {
        free(self); self = NULL;
        free(buf); buf = NULL;
        return NULL;
      }

      break;
    }
    case REQL_R_REQL: {
      reql_term_init(self, reql_term_type(other), reql_args(other), reql_kwargs(other));
      break;
    }
    case REQL_R_JSON: {
      free(self); self = NULL;
      return NULL;
    }
  }

  return self;
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
  const ReQL_Pair_t *lobj = l;
  const ReQL_Obj_t *lkey = lobj->key;
  const ReQL_Pair_t *robj = r;
  const ReQL_Obj_t *rkey = robj->key;
  if (lkey == NULL && rkey == NULL) {
    return 0;
  } else if (lkey == NULL) {
    return -1;
  } else if (rkey == NULL) {
    return 1;
  }
  const ReQL_Size lsize = reql_size(lkey);
  const ReQL_Size rsize = reql_size(rkey);
  if (lsize == rsize) {
    return memcmp(reql_string_buf(lkey), reql_string_buf(rkey), lsize);
  } else if (lsize < rsize) {
    return -1;
  }
  return 1;
}

static ReQL_Pair_t *
reql_object_find(const ReQL_Obj_t *obj, const ReQL_Pair_t *key) {
  return bsearch(key, reql_pair(obj), reql_size(obj), sizeof(ReQL_Pair_t), reql_key_sort);
}

extern ReQL_Size
reql_object_add(ReQL_Obj_t *obj, ReQL_Obj_t *key, ReQL_Obj_t *val) {
  if (reql_owner(key) != NULL && reql_owner(key) != obj) {
    reql_error_init(REQL_E_JSON, "key already owned", __func__);
    return UINT32_MAX;
  }
  if (reql_owner(val) != NULL) {
    reql_error_init(REQL_E_JSON, "element already owned", __func__);
    return UINT32_MAX;
  }

  ReQL_Pair_t test = {key, NULL};
  ReQL_Pair_t *pair = reql_object_find(obj, &test);

  if (pair == NULL) {
    ReQL_Size size = reql_size(obj);
    pair = reql_pair(obj);

    if (pair[size].key != NULL) {
      size += 1;

      ReQL_Size new_alloc = reql_ensure_space(obj, size);

      if (new_alloc != 0) {
        return new_alloc;
      }
    }

    pair[size].key = key;
    pair[size].val = val;

    key->owner = obj;

    if (val != NULL) {
      val->owner = obj;
    }

    size += 1;

    qsort(pair, size, sizeof(ReQL_Pair_t), reql_key_sort);

    reql_set_size(obj, size);
  } else {
    pair->val = val;

    if (val != NULL) {
      val->owner = obj;
    }
  }

  return 0;
}

extern ReQL_Obj_t *
reql_object_get(const ReQL_Obj_t *obj, ReQL_Obj_t *key) {
  const ReQL_Pair_t test = {key, NULL};
  ReQL_Pair_t *pair = reql_object_find(obj, &test);

  if (pair == NULL) {
    return NULL;
  }

  return pair->val;
}

extern void
reql_null_init(ReQL_Obj_t *obj) {
  reql_json_init(obj, REQL_R_NULL);
}

extern void
reql_bool_init(ReQL_Obj_t *obj, char val) {
  reql_json_init(obj, REQL_R_BOOL);
  obj->obj.datum.json.boolean = val ? 1 : 0;
}

extern char
reql_to_bool(const ReQL_Obj_t *obj) {
  return obj->obj.datum.json.boolean;
}

static void
reql_arr_destroy(ReQL_Obj_t **arr, ReQL_Size size) {
  if (arr == NULL) {
    return;
  }

  ReQL_Size i;

  for (i=0; i < size; ++i) {
    reql_json_destroy(arr[i]);
  }

  free(arr);
}

static void
reql_pair_destroy(ReQL_Pair_t *pair, ReQL_Size size) {
  if (pair == NULL) {
    return;
  }

  ReQL_Size i;

  for (i=0; i < size; ++i) {
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

  ReQL_Obj_t *owner = reql_owner(json);

  if (owner != NULL) {
    switch (reql_datum_type(owner)) {
      case REQL_R_ARRAY: {
        const ReQL_Size size = reql_size(owner);
        ReQL_Obj_t **array = reql_array(owner);

        ReQL_Size i;

        for (i=0; i < size; ++i) {
          if (array[i] == json) {
            array[i] = NULL;
            break;
          }
        }

        break;
      }
      case REQL_R_OBJECT: {
        const ReQL_Size size = reql_size(owner);
        ReQL_Pair_t *pair = reql_pair(owner);

        ReQL_Size i;

        for (i=0; i < size; ++i) {
          if (pair[i].val == json) {
            pair[i].val = NULL;
            break;
          } else if (pair[i].key == json) {
            reql_json_destroy(pair[i].val); pair[i].val = NULL;
            pair[i].key = NULL;
            break;
          }
        }

        break;
      }
      case REQL_R_REQL: {
        if (reql_args(owner) == json) {
          owner->obj.args.args = NULL;
        } else if (reql_kwargs(owner) == json) {
          owner->obj.args.kwargs = NULL;
        }
        break;
      }
      case REQL_R_BOOL:
      case REQL_R_JSON:
      case REQL_R_NULL:
      case REQL_R_NUM:
      case REQL_R_STR: break;
    }
  }
  
  json->owner = NULL;

  switch (reql_datum_type(json)) {
    case REQL_R_ARRAY: {
      reql_arr_destroy(reql_array(json), reql_alloc_size(json));
      break;
    }
    case REQL_R_BOOL:
    case REQL_R_JSON:
    case REQL_R_NULL:
    case REQL_R_NUM: break;
    case REQL_R_OBJECT: {
      reql_pair_destroy(reql_pair(json), reql_alloc_size(json));
      break;
    }
    case REQL_R_REQL: {
      reql_json_destroy(reql_args(json));
      reql_json_destroy(reql_kwargs(json));
      break;
    }
    case REQL_R_STR: {
      ReQL_Byte *buf = reql_string_buf(json);
      if (buf != NULL) {
        free(buf);
      }
      break;
    }
  }

  free(json);
}
