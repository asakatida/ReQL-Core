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

#include "./reql/query.h"

#include "./reql/error.h"
#include "./reql/types.h"

#include <cstdlib>
#include <memory>

extern ReQL_Term_t
reql_term_type(const ReQL_Obj_t *obj) {
  if (obj == nullptr) {
    return REQL_DATUM;
  }
  return obj->tt;
}

static ReQL_Obj_t *
reql_term_args(const ReQL_Obj_t *obj) {
  return obj->obj.args.args;
}

static ReQL_Obj_t *
reql_term_kwargs(const ReQL_Obj_t *obj) {
  return obj->obj.args.kwargs;
}

extern ReQL_Datum_t
reql_datum_type(const ReQL_Obj_t *obj) {
  if (obj == nullptr) {
    return REQL_R_JSON;
  }
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
  if (obj == nullptr) {
    return 0;
  }
  return obj->obj.datum.json.var.size;
}

static ReQL_Obj_t *
reql_owner(ReQL_Obj_t *obj) {
  if (obj == nullptr) {
    return nullptr;
  }
  return obj->owner;
}

static ReQL_Size
reql_ensure_space(const ReQL_Obj_t *obj, ReQL_Size size) {
  if (reql_alloc_size(obj) < size) {
    const ReQL_Size min_size = static_cast<ReQL_Size>(static_cast<double>(reql_size(obj) + size) * 1.1);

    if (min_size < size) {
      return UINT32_MAX;
    }

    return min_size;
  }

  return 0;
}

static void
reql_term_init(ReQL_Obj_t *obj, const ReQL_Term_t tt, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  if (obj == nullptr) {
    return;
  }
  memset(obj, static_cast<int>(NULL), sizeof(ReQL_Obj_t));
  obj->tt = tt;
  obj->obj.args.args = nullptr;
  if (args != nullptr) {
    if (reql_owner(args) == nullptr) {
      obj->obj.args.args = args;
      args->owner = obj;
    } else {
      reql_error_init(REQL_E_JSON, "args array is already owned", __func__);
    }
  }
  obj->obj.args.kwargs = nullptr;
  if (kwargs != nullptr) {
    if (reql_owner(kwargs) == nullptr) {
      obj->obj.args.kwargs = kwargs;
      kwargs->owner = obj;
    } else {
      reql_error_init(REQL_E_JSON, "kwargs object is already owned", __func__);
    }
  }
  obj->owner = nullptr;
}

static void
reql_json_init(ReQL_Obj_t *obj, const ReQL_Datum_t dt) {
  reql_term_init(obj, REQL_DATUM, nullptr, nullptr);
  obj->obj.datum.dt = dt;
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
  if (obj == nullptr) {
    return;
  }
  reql_json_init(obj, REQL_R_NUM);
  obj->obj.datum.json.number = num;
}

extern double
reql_to_number(const ReQL_Obj_t *obj) {
  if (obj == nullptr) {
    return 0;
  }
  return obj->obj.datum.json.number;
}

extern void
reql_string_init(ReQL_Obj_t *obj, ReQL_Byte *str, const ReQL_Byte *ext, const ReQL_Size alloc_size) {
  if (obj == nullptr) {
    return;
  }
  reql_var_json_init(obj, REQL_R_STR, alloc_size);
  memcpy(str, ext, alloc_size);
  reql_set_str(obj, str);
  reql_set_size(obj, alloc_size);
}

extern ReQL_Byte *
reql_string_buf(const ReQL_Obj_t *obj) {
  if (obj == nullptr) {
    return nullptr;
  }
  return obj->obj.datum.json.var.data.str;
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
  ReQL_Obj_t *next = nullptr;

  if (reql_size(obj->obj) > obj->idx) {
    if (reql_datum_type(obj->obj) == REQL_R_ARRAY) {
      next = reql_array_index(obj->obj, obj->idx);
    } else if (reql_datum_type(obj->obj) == REQL_R_OBJECT) {
      next = reql_pair(obj->obj)[obj->idx].key;
    } else {
      return nullptr;
    }
    ++obj->idx;

    if (next == nullptr) {
      return reql_iter_next(obj);
    }
  }

  return next;
}

extern void
reql_array_init(ReQL_Obj_t *obj, ReQL_Obj_t **arr, const ReQL_Size alloc_size) {
  memset(arr, static_cast<int>(NULL), sizeof(ReQL_Obj_t*) * alloc_size);
  reql_var_json_init(obj, REQL_R_ARRAY, alloc_size);
  reql_set_array(obj, arr);
}

extern ReQL_Size
reql_array_insert(ReQL_Obj_t *obj, ReQL_Obj_t *val, const ReQL_Size idx) {
  if (reql_owner(val) != nullptr) {
    reql_error_init(REQL_E_JSON, "element already owned", __func__);
    return UINT32_MAX;
  }

  if (idx >= reql_size(obj)) {
    const ReQL_Size new_alloc = reql_ensure_space(obj, idx + 1);

    if (new_alloc != 0) {
      reql_error_init(REQL_E_JSON, "insufficient space in object", __func__);
      return new_alloc;
    }

    reql_set_size(obj, idx + 1);
  }

  ReQL_Obj_t **arr = reql_array(obj);

  arr[idx] = val;
  if (val != nullptr) {
    val->owner = obj;
  }

  return 0;
}

extern ReQL_Obj_t *
reql_array_index(const ReQL_Obj_t *obj, const ReQL_Size idx) {
  if (reql_alloc_size(obj) <= idx) {
    return nullptr;
  }

  return reql_array(obj)[idx];
}

extern ReQL_Size
reql_array_append(ReQL_Obj_t *obj, ReQL_Obj_t *val) {
  if (val == nullptr) {
    return 0;
  }
  return reql_array_insert(obj, val, reql_size(obj));
}

extern ReQL_Obj_t *
reql_array_last(ReQL_Obj_t *obj) {
  ReQL_Size size = reql_size(obj);
  if (size > 0) {
    --size;
    ReQL_Obj_t *res = reql_array_index(obj, size);
    if (res == nullptr) {
      reql_set_size(obj, size);
      res = reql_array_last(obj);
    }
    return res;
  }
  return nullptr;
}

extern void
reql_object_init(ReQL_Obj_t *obj, ReQL_Pair_t *pairs, const ReQL_Size alloc_size) {
  memset(pairs, static_cast<int>(NULL), sizeof(ReQL_Pair_t) * alloc_size);
  reql_var_json_init(obj, REQL_R_OBJECT, alloc_size);
  reql_set_pair(obj, pairs);
}

static int
reql_key_sort(const void *l, const void *r) {
  if (l == nullptr && r == nullptr) {
    return 0;
  } else if (l == nullptr) {
    return -1;
  } else if (r == nullptr) {
    return 1;
  }
  const ReQL_Pair_t *lobj = reinterpret_cast<const ReQL_Pair_t *>(l);
  const ReQL_Obj_t *lkey = lobj->key;
  const ReQL_Pair_t *robj = reinterpret_cast<const ReQL_Pair_t *>(r);
  const ReQL_Obj_t *rkey = robj->key;
  if (lkey == nullptr && rkey == nullptr) {
    return 0;
  } else if (lkey == nullptr) {
    return -1;
  } else if (rkey == nullptr) {
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
  return reinterpret_cast<ReQL_Pair_t *>(bsearch(key, reql_pair(obj), reql_size(obj), sizeof(ReQL_Pair_t), reql_key_sort));
}

extern ReQL_Size
reql_object_add(ReQL_Obj_t *obj, ReQL_Obj_t *key, ReQL_Obj_t *val) {
  if (reql_owner(key) != nullptr && reql_owner(key) != obj) {
    reql_error_init(REQL_E_JSON, "key already owned", __func__);
    return UINT32_MAX;
  }
  if (reql_owner(val) != nullptr) {
    reql_error_init(REQL_E_JSON, "element already owned", __func__);
    return UINT32_MAX;
  }

  ReQL_Pair_t test = {key, nullptr};
  ReQL_Pair_t *pair = reql_object_find(obj, &test);

  if (pair == nullptr) {
    ReQL_Size size = reql_size(obj);
    pair = reql_pair(obj);

    if (pair[size].key != nullptr) {
      size += 1;

      ReQL_Size new_alloc = reql_ensure_space(obj, size);

      if (new_alloc != 0) {
        reql_error_init(REQL_E_JSON, "insufficient space in object", __func__);
        return new_alloc;
      }
    }

    pair[size].key = key;
    pair[size].val = val;

    key->owner = obj;

    if (val != nullptr) {
      val->owner = obj;
    }

    size += 1;

    qsort(pair, size, sizeof(ReQL_Pair_t), reql_key_sort);

    reql_set_size(obj, size);
  } else {
    pair->val = val;

    if (val != nullptr) {
      val->owner = obj;
    }
  }

  return 0;
}

extern ReQL_Obj_t *
reql_object_get(const ReQL_Obj_t *obj, ReQL_Obj_t *key) {
  const ReQL_Pair_t test = {key, nullptr};
  ReQL_Pair_t *pair = reql_object_find(obj, &test);

  if (pair == nullptr) {
    return nullptr;
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
  obj->obj.datum.json.boolean = val ? true : false;
}

extern char
reql_to_bool(const ReQL_Obj_t *obj) {
  return obj->obj.datum.json.boolean;
}

static void
reql_arr_destroy(ReQL_Obj_t **arr, ReQL_Size size) {
  if (arr == nullptr) {
    return;
  }

  ReQL_Size i;

  for (i=0; i < size; ++i) {
    reql_json_destroy(arr[i]);
  }

  delete arr;
}

static void
reql_pair_destroy(ReQL_Pair_t *pair, ReQL_Size size) {
  if (pair == nullptr) {
    return;
  }

  ReQL_Size i;

  for (i=0; i < size; ++i) {
    reql_json_destroy(pair[i].key);
    reql_json_destroy(pair[i].val);
  }

  delete pair;
}

extern void
reql_json_destroy(ReQL_Obj_t *json) {
  if (json == nullptr) {
    return;
  }

  ReQL_Obj_t *owner = reql_owner(json);

  if (owner != nullptr) {
    switch (reql_datum_type(owner)) {
      case REQL_R_ARRAY: {
        const ReQL_Size size = reql_alloc_size(owner);
        ReQL_Obj_t **array = reql_array(owner);

        ReQL_Size i;

        for (i=0; i < size; ++i) {
          if (array[i] == json) {
            array[i] = nullptr;
            break;
          }
        }

        break;
      }
      case REQL_R_OBJECT: {
        const ReQL_Size size = reql_alloc_size(owner);
        ReQL_Pair_t *pair = reql_pair(owner);

        ReQL_Size i;

        for (i=0; i < size; ++i) {
          if (pair[i].val == json) {
            pair[i].val = nullptr;
            break;
          } else if (pair[i].key == json) {
            reql_json_destroy(pair[i].val); pair[i].val = nullptr;
            pair[i].key = nullptr;
            break;
          }
        }

        break;
      }
      case REQL_R_REQL: {
        if (reql_term_args(owner) == json) {
          owner->obj.args.args = nullptr;
        } else if (reql_term_kwargs(owner) == json) {
          owner->obj.args.kwargs = nullptr;
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

  json->owner = nullptr;

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
      reql_json_destroy(reql_term_args(json));
      reql_json_destroy(reql_term_kwargs(json));
      break;
    }
    case REQL_R_STR: {
      ReQL_Byte *buf = reql_string_buf(json);
      if (buf != nullptr) {
        delete buf;
      }
      break;
    }
  }

  delete json;
}

extern void
reql_ast_add(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ADD, a, nullptr);
}

extern void
reql_ast_and(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_AND, a, nullptr);
}

extern void
reql_ast_append(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_APPEND, a, nullptr);
}

extern void
reql_ast_april(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_APRIL, a, nullptr);
}

extern void
reql_ast_args(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ARGS, a, nullptr);
}

extern void
reql_ast_asc(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ASC, a, nullptr);
}

extern void
reql_ast_august(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_AUGUST, a, nullptr);
}

extern void
reql_ast_avg(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_AVG, a, nullptr);
}

extern void
reql_ast_between(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BETWEEN, a, nullptr);
}

extern void
reql_ast_between_deprecated(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BETWEEN_DEPRECATED, a, nullptr);
}

extern void
reql_ast_binary(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BINARY, a, nullptr);
}

extern void
reql_ast_bracket(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BRACKET, a, nullptr);
}

extern void
reql_ast_branch(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BRANCH, a, nullptr);
}

extern void
reql_ast_ceil(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CEIL, a, nullptr);
}

extern void
reql_ast_changes(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CHANGES, a, nullptr);
}

extern void
reql_ast_change_at(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CHANGE_AT, a, nullptr);
}

extern void
reql_ast_circle(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_CIRCLE, a, k);
}

extern void
reql_ast_coerce_to(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_COERCE_TO, a, nullptr);
}

extern void
reql_ast_concat_map(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CONCAT_MAP, a, nullptr);
}

extern void
reql_ast_config(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CONFIG, a, nullptr);
}

extern void
reql_ast_contains(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CONTAINS, a, nullptr);
}

extern void
reql_ast_count(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_COUNT, a, nullptr);
}

extern void
reql_ast_date(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DATE, a, nullptr);
}

extern void
reql_ast_datum(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DATUM, a, nullptr);
}

extern void
reql_ast_day(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DAY, a, nullptr);
}

extern void
reql_ast_day_of_week(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DAY_OF_WEEK, a, nullptr);
}

extern void
reql_ast_day_of_year(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DAY_OF_YEAR, a, nullptr);
}

extern void
reql_ast_db(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DB, a, nullptr);
}

extern void
reql_ast_db_create(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DB_CREATE, a, nullptr);
}

extern void
reql_ast_db_drop(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DB_DROP, a, nullptr);
}

extern void
reql_ast_db_list(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DB_LIST, a, nullptr);
}

extern void
reql_ast_december(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DECEMBER, a, nullptr);
}

extern void
reql_ast_default(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DEFAULT, a, nullptr);
}

extern void
reql_ast_delete(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_DELETE, a, k);
}

extern void
reql_ast_delete_at(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DELETE_AT, a, nullptr);
}

extern void
reql_ast_desc(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DESC, a, nullptr);
}

extern void
reql_ast_difference(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DIFFERENCE, a, nullptr);
}

extern void
reql_ast_distance(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DISTANCE, a, nullptr);
}

extern void
reql_ast_distinct(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_DISTINCT, a, k);
}

extern void
reql_ast_div(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DIV, a, nullptr);
}

extern void
reql_ast_downcase(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DOWNCASE, a, nullptr);
}

extern void
reql_ast_during(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DURING, a, nullptr);
}

extern void
reql_ast_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_EPOCH_TIME, a, nullptr);
}

extern void
reql_ast_eq(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_EQ, a, nullptr);
}

extern void
reql_ast_eq_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_EQ_JOIN, a, k);
}

extern void
reql_ast_error(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ERROR, a, nullptr);
}

extern void
reql_ast_february(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FEBRUARY, a, nullptr);
}

extern void
reql_ast_fill(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FILL, a, nullptr);
}

extern void
reql_ast_filter(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_FILTER, a, k);
}

extern void
reql_ast_floor(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FLOOR, a, nullptr);
}

extern void
reql_ast_for_each(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FOR_EACH, a, nullptr);
}

extern void
reql_ast_friday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FRIDAY, a, nullptr);
}

extern void
reql_ast_func(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FUNC, a, nullptr);
}

extern void
reql_ast_funcall(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FUNCALL, a, nullptr);
}

extern void
reql_ast_ge(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GE, a, nullptr);
}

extern void
reql_ast_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GEOJSON, a, nullptr);
}

extern void
reql_ast_get(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GET, a, nullptr);
}

extern void
reql_ast_get_all(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_GET_ALL, a, k);
}

extern void
reql_ast_get_field(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GET_FIELD, a, nullptr);
}

extern void
reql_ast_get_intersecting(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_GET_INTERSECTING, a, k);
}

extern void
reql_ast_get_nearest(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_GET_NEAREST, a, k);
}

extern void
reql_ast_group(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_GROUP, a, k);
}

extern void
reql_ast_gt(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GT, a, nullptr);
}

extern void
reql_ast_has_fields(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_HAS_FIELDS, a, nullptr);
}

extern void
reql_ast_hours(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_HOURS, a, nullptr);
}

extern void
reql_ast_http(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_HTTP, a, k);
}

extern void
reql_ast_implicit_var(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_IMPLICIT_VAR, a, nullptr);
}

extern void
reql_ast_includes(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INCLUDES, a, nullptr);
}

extern void
reql_ast_index_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_INDEX_CREATE, a, k);
}

extern void
reql_ast_index_drop(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INDEX_DROP, a, nullptr);
}

extern void
reql_ast_index_list(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INDEX_LIST, a, nullptr);
}

extern void
reql_ast_index_rename(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_INDEX_RENAME, a, k);
}

extern void
reql_ast_index_status(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INDEX_STATUS, a, nullptr);
}

extern void
reql_ast_index_wait(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INDEX_WAIT, a, nullptr);
}

extern void
reql_ast_info(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INFO, a, nullptr);
}

extern void
reql_ast_inner_join(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INNER_JOIN, a, nullptr);
}

extern void
reql_ast_insert(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INSERT, a, nullptr);
}

extern void
reql_ast_insert_at(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INSERT_AT, a, nullptr);
}

extern void
reql_ast_intersects(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INTERSECTS, a, nullptr);
}

extern void
reql_ast_in_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_IN_TIMEZONE, a, nullptr);
}

extern void
reql_ast_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_ISO8601, a, k);
}

extern void
reql_ast_is_empty(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_IS_EMPTY, a, nullptr);
}

extern void
reql_ast_january(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_JANUARY, a, nullptr);
}

extern void
reql_ast_javascript(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_JAVASCRIPT, a, k);
}

extern void
reql_ast_json(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_JSON, a, nullptr);
}

extern void
reql_ast_july(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_JULY, a, nullptr);
}

extern void
reql_ast_june(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_JUNE, a, nullptr);
}

extern void
reql_ast_keys(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_KEYS, a, nullptr);
}

extern void
reql_ast_le(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LE, a, nullptr);
}

extern void
reql_ast_limit(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LIMIT, a, nullptr);
}

extern void
reql_ast_line(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LINE, a, nullptr);
}

extern void
reql_ast_literal(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LITERAL, a, nullptr);
}

extern void
reql_ast_lt(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LT, a, nullptr);
}

extern void
reql_ast_make_array(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAKE_ARRAY, a, nullptr);
}

extern void
reql_ast_make_obj(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAKE_OBJ, a, nullptr);
}

extern void
reql_ast_map(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAP, a, nullptr);
}

extern void
reql_ast_march(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MARCH, a, nullptr);
}

extern void
reql_ast_match(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MATCH, a, nullptr);
}

extern void
reql_ast_max(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAX, a, nullptr);
}

extern void
reql_ast_maxval(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAXVAL, a, nullptr);
}

extern void
reql_ast_may(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAY, a, nullptr);
}

extern void
reql_ast_merge(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MERGE, a, nullptr);
}

extern void
reql_ast_min(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MIN, a, nullptr);
}

extern void
reql_ast_minutes(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MINUTES, a, nullptr);
}

extern void
reql_ast_minval(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MINVAL, a, nullptr);
}

extern void
reql_ast_mod(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MOD, a, nullptr);
}

extern void
reql_ast_monday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MONDAY, a, nullptr);
}

extern void
reql_ast_month(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MONTH, a, nullptr);
}

extern void
reql_ast_mul(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MUL, a, nullptr);
}

extern void
reql_ast_ne(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NE, a, nullptr);
}

extern void
reql_ast_not(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NOT, a, nullptr);
}

extern void
reql_ast_november(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NOVEMBER, a, nullptr);
}

extern void
reql_ast_now(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NOW, a, nullptr);
}

extern void
reql_ast_nth(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NTH, a, nullptr);
}

extern void
reql_ast_object(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OBJECT, a, nullptr);
}

extern void
reql_ast_october(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OCTOBER, a, nullptr);
}

extern void
reql_ast_offsets_of(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OFFSETS_OF, a, nullptr);
}

extern void
reql_ast_or(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OR, a, nullptr);
}

extern void
reql_ast_order_by(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_ORDER_BY, a, k);
}

extern void
reql_ast_outer_join(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OUTER_JOIN, a, nullptr);
}

extern void
reql_ast_pluck(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_PLUCK, a, nullptr);
}

extern void
reql_ast_point(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_POINT, a, nullptr);
}

extern void
reql_ast_polygon(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_POLYGON, a, nullptr);
}

extern void
reql_ast_polygon_sub(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_POLYGON_SUB, a, nullptr);
}

extern void
reql_ast_prepend(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_PREPEND, a, nullptr);
}

extern void
reql_ast_random(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_RANDOM, a, k);
}

extern void
reql_ast_range(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_RANGE, a, nullptr);
}

extern void
reql_ast_rebalance(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_REBALANCE, a, nullptr);
}

extern void
reql_ast_reconfigure(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_RECONFIGURE, a, nullptr);
}

extern void
reql_ast_reduce(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_REDUCE, a, nullptr);
}

extern void
reql_ast_replace(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_REPLACE, a, k);
}

extern void
reql_ast_round(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ROUND, a, nullptr);
}

extern void
reql_ast_sample(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SAMPLE, a, nullptr);
}

extern void
reql_ast_saturday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SATURDAY, a, nullptr);
}

extern void
reql_ast_seconds(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SECONDS, a, nullptr);
}

extern void
reql_ast_september(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SEPTEMBER, a, nullptr);
}

extern void
reql_ast_set_difference(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SET_DIFFERENCE, a, nullptr);
}

extern void
reql_ast_set_insert(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SET_INSERT, a, nullptr);
}

extern void
reql_ast_set_intersection(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SET_INTERSECTION, a, nullptr);
}

extern void
reql_ast_set_union(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SET_UNION, a, nullptr);
}

extern void
reql_ast_skip(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SKIP, a, nullptr);
}

extern void
reql_ast_slice(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_SLICE, a, k);
}

extern void
reql_ast_splice_at(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SPLICE_AT, a, nullptr);
}

extern void
reql_ast_split(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SPLIT, a, nullptr);
}

extern void
reql_ast_status(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_STATUS, a, nullptr);
}

extern void
reql_ast_sub(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SUB, a, nullptr);
}

extern void
reql_ast_sum(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SUM, a, nullptr);
}

extern void
reql_ast_sunday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SUNDAY, a, nullptr);
}

extern void
reql_ast_sync(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SYNC, a, nullptr);
}

extern void
reql_ast_table(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_TABLE, a, k);
}

extern void
reql_ast_table_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_TABLE_CREATE, a, k);
}

extern void
reql_ast_table_drop(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TABLE_DROP, a, nullptr);
}

extern void
reql_ast_table_list(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TABLE_LIST, a, nullptr);
}

extern void
reql_ast_thursday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_THURSDAY, a, nullptr);
}

extern void
reql_ast_time(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TIME, a, nullptr);
}

extern void
reql_ast_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TIMEZONE, a, nullptr);
}

extern void
reql_ast_time_of_day(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TIME_OF_DAY, a, nullptr);
}

extern void
reql_ast_to_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TO_EPOCH_TIME, a, nullptr);
}

extern void
reql_ast_to_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TO_GEOJSON, a, nullptr);
}

extern void
reql_ast_to_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TO_ISO8601, a, nullptr);
}

extern void
reql_ast_to_json_string(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TO_JSON_STRING, a, nullptr);
}

extern void
reql_ast_tuesday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TUESDAY, a, nullptr);
}

extern void
reql_ast_type_of(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TYPE_OF, a, nullptr);
}

extern void
reql_ast_ungroup(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_UNGROUP, a, nullptr);
}

extern void
reql_ast_union(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_UNION, a, nullptr);
}

extern void
reql_ast_upcase(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_UPCASE, a, nullptr);
}

extern void
reql_ast_update(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_UPDATE, a, k);
}

extern void
reql_ast_uuid(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_UUID, a, nullptr);
}

extern void
reql_ast_values(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_VALUES, a, nullptr);
}

extern void
reql_ast_var(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_VAR, a, nullptr);
}

extern void
reql_ast_wait(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_WAIT, a, nullptr);
}

extern void
reql_ast_wednesday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_WEDNESDAY, a, nullptr);
}

extern void
reql_ast_without(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_WITHOUT, a, nullptr);
}

extern void
reql_ast_with_fields(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_WITH_FIELDS, a, nullptr);
}

extern void
reql_ast_year(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_YEAR, a, nullptr);
}

extern void
reql_ast_zip(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ZIP, a, nullptr);
}
