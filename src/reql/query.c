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

#include <float.h>
#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

enum ReQL_Term_e {
  REQL_ADD = 24,
  REQL_AND = 67,
  REQL_APPEND = 29,
  REQL_APRIL = 117,
  REQL_ARGS = 154,
  REQL_ASC = 73,
  REQL_AUGUST = 121,
  REQL_AVG = 146,
  REQL_BETWEEN = 182,
  REQL_BETWEEN_DEPRECATED = 36,
  REQL_BINARY = 155,
  REQL_BRACKET = 170,
  REQL_BRANCH = 65,
  REQL_CEIL = 184,
  REQL_CHANGES = 152,
  REQL_CHANGE_AT = 84,
  REQL_CIRCLE = 165,
  REQL_COERCE_TO = 51,
  REQL_CONCAT_MAP = 40,
  REQL_CONFIG = 174,
  REQL_CONTAINS = 93,
  REQL_COUNT = 43,
  REQL_DATE = 106,
  REQL_DATUM = 1,
  REQL_DAY = 130,
  REQL_DAY_OF_WEEK = 131,
  REQL_DAY_OF_YEAR = 132,
  REQL_DB = 14,
  REQL_DB_CREATE = 57,
  REQL_DB_DROP = 58,
  REQL_DB_LIST = 59,
  REQL_DECEMBER = 125,
  REQL_DEFAULT = 92,
  REQL_DELETE = 54,
  REQL_DELETE_AT = 83,
  REQL_DESC = 74,
  REQL_DIFFERENCE = 95,
  REQL_DISTANCE = 162,
  REQL_DISTINCT = 42,
  REQL_DIV = 27,
  REQL_DOWNCASE = 142,
  REQL_DURING = 105,
  REQL_EPOCH_TIME = 101,
  REQL_EQ = 17,
  REQL_EQ_JOIN = 50,
  REQL_ERROR = 12,
  REQL_FEBRUARY = 115,
  REQL_FILL = 167,
  REQL_FILTER = 39,
  REQL_FLOOR = 183,
  REQL_FOR_EACH = 68,
  REQL_FRIDAY = 111,
  REQL_FUNC = 69,
  REQL_FUNCALL = 64,
  REQL_GE = 22,
  REQL_GEOJSON = 157,
  REQL_GET = 16,
  REQL_GET_ALL = 78,
  REQL_GET_FIELD = 31,
  REQL_GET_INTERSECTING = 166,
  REQL_GET_NEAREST = 168,
  REQL_GROUP = 144,
  REQL_GT = 21,
  REQL_HAS_FIELDS = 32,
  REQL_HOURS = 133,
  REQL_HTTP = 153,
  REQL_IMPLICIT_VAR = 13,
  REQL_INCLUDES = 164,
  REQL_INDEX_CREATE = 75,
  REQL_INDEX_DROP = 76,
  REQL_INDEX_LIST = 77,
  REQL_INDEX_RENAME = 156,
  REQL_INDEX_STATUS = 139,
  REQL_INDEX_WAIT = 140,
  REQL_INFO = 79,
  REQL_INNER_JOIN = 48,
  REQL_INSERT = 56,
  REQL_INSERT_AT = 82,
  REQL_INTERSECTS = 163,
  REQL_IN_TIMEZONE = 104,
  REQL_ISO8601 = 99,
  REQL_IS_EMPTY = 86,
  REQL_JANUARY = 114,
  REQL_JAVASCRIPT = 11,
  REQL_JSON = 98,
  REQL_JULY = 120,
  REQL_JUNE = 119,
  REQL_KEYS = 94,
  REQL_LE = 20,
  REQL_LIMIT = 71,
  REQL_LINE = 160,
  REQL_LITERAL = 137,
  REQL_LT = 19,
  REQL_MAKE_ARRAY = 2,
  REQL_MAKE_OBJ = 3,
  REQL_MAP = 38,
  REQL_MARCH = 116,
  REQL_MATCH = 97,
  REQL_MAX = 148,
  REQL_MAXVAL = 181,
  REQL_MAY = 118,
  REQL_MERGE = 35,
  REQL_MIN = 147,
  REQL_MINUTES = 134,
  REQL_MINVAL = 180,
  REQL_MOD = 28,
  REQL_MONDAY = 107,
  REQL_MONTH = 129,
  REQL_MUL = 26,
  REQL_NE = 18,
  REQL_NOT = 23,
  REQL_NOVEMBER = 124,
  REQL_NOW = 103,
  REQL_NTH = 45,
  REQL_OBJECT = 143,
  REQL_OCTOBER = 123,
  REQL_OFFSETS_OF = 87,
  REQL_OR = 66,
  REQL_ORDER_BY = 41,
  REQL_OUTER_JOIN = 49,
  REQL_PLUCK = 33,
  REQL_POINT = 159,
  REQL_POLYGON = 161,
  REQL_POLYGON_SUB = 171,
  REQL_PREPEND = 80,
  REQL_RANDOM = 151,
  REQL_RANGE = 173,
  REQL_REBALANCE = 179,
  REQL_RECONFIGURE = 176,
  REQL_REDUCE = 37,
  REQL_REPLACE = 55,
  REQL_ROUND = 185,
  REQL_SAMPLE = 81,
  REQL_SATURDAY = 112,
  REQL_SECONDS = 135,
  REQL_SEPTEMBER = 122,
  REQL_SET_DIFFERENCE = 91,
  REQL_SET_INSERT = 88,
  REQL_SET_INTERSECTION = 89,
  REQL_SET_UNION = 90,
  REQL_SKIP = 70,
  REQL_SLICE = 30,
  REQL_SPLICE_AT = 85,
  REQL_SPLIT = 149,
  REQL_STATUS = 175,
  REQL_SUB = 25,
  REQL_SUM = 145,
  REQL_SUNDAY = 113,
  REQL_SYNC = 138,
  REQL_TABLE = 15,
  REQL_TABLE_CREATE = 60,
  REQL_TABLE_DROP = 61,
  REQL_TABLE_LIST = 62,
  REQL_THURSDAY = 110,
  REQL_TIME = 136,
  REQL_TIMEZONE = 127,
  REQL_TIME_OF_DAY = 126,
  REQL_TO_EPOCH_TIME = 102,
  REQL_TO_GEOJSON = 158,
  REQL_TO_ISO8601 = 100,
  REQL_TO_JSON_STRING = 172,
  REQL_TUESDAY = 108,
  REQL_TYPE_OF = 52,
  REQL_UNGROUP = 150,
  REQL_UNION = 44,
  REQL_UPCASE = 141,
  REQL_UPDATE = 53,
  REQL_UUID = 169,
  REQL_VAR = 10,
  REQL_WAIT = 177,
  REQL_WEDNESDAY = 109,
  REQL_WITHOUT = 34,
  REQL_WITH_FIELDS = 96,
  REQL_YEAR = 128,
  REQL_ZIP = 72
};
typedef enum ReQL_Term_e ReQL_Term_t;

extern int
reql_term_type(const ReQL_Obj_t *obj) {
  if (obj == NULL) {
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
  if (obj == NULL) {
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
  if (obj == NULL) {
    return 0;
  }
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
reql_term_init(ReQL_Obj_t *obj, const ReQL_Term_t tt, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  if (obj == NULL) {
    return;
  }
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
reql_json_init(ReQL_Obj_t *obj, const ReQL_Datum_t dt) {
  reql_term_init(obj, REQL_DATUM, NULL, NULL);
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
  if (obj == NULL) {
    return;
  }
  reql_json_init(obj, REQL_R_NUM);
  obj->obj.datum.json.number = num;
}

extern double
reql_to_number(const ReQL_Obj_t *obj) {
  if (obj == NULL) {
    return 0;
  }
  return obj->obj.datum.json.number;
}

extern void
reql_string_init(ReQL_Obj_t *obj, ReQL_Byte *str, const ReQL_Byte *ext, const ReQL_Size alloc_size) {
  if (obj == NULL) {
    return;
  }
  reql_var_json_init(obj, REQL_R_STR, alloc_size);
  memcpy(str, ext, alloc_size);
  reql_set_str(obj, str);
  reql_set_size(obj, alloc_size);
}

extern ReQL_Byte *
reql_string_buf(const ReQL_Obj_t *obj) {
  if (obj == NULL) {
    return NULL;
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

    if (next == NULL) {
      return reql_iter_next(obj);
    }
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
      reql_error_init(REQL_E_JSON, "insufficient space in object", __func__);
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
  if (val == NULL) {
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
    if (res == NULL) {
      reql_set_size(obj, size);
      res = reql_array_last(obj);
    }
    return res;
  }
  return NULL;
}

extern void
reql_object_init(ReQL_Obj_t *obj, ReQL_Pair_t *pairs, const ReQL_Size alloc_size) {
  memset(pairs, (int)NULL, sizeof(ReQL_Pair_t) * alloc_size);
  reql_var_json_init(obj, REQL_R_OBJECT, alloc_size);
  reql_set_pair(obj, pairs);
}

extern ReQL_Obj_t *
reql_json_copy(const ReQL_Obj_t *other) {
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
          elem = reql_json_copy(elem);
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

      ReQL_Iter_t it = reql_new_iter(other);

      ReQL_Obj_t *key = NULL;
      ReQL_Obj_t *value = NULL;

      while ((key = reql_iter_next(&it)) != NULL) {
        key = reql_json_copy(key);
        if (key == NULL) {
          reql_json_destroy(self); self = NULL;
          return NULL;
        }
        value = reql_object_get(other, key);
        if (value != NULL) {
          value = reql_json_copy(value);
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

      reql_string_init(self, buf, reql_string_buf(other), size);
      break;
    }
    case REQL_R_REQL: {
      reql_term_init(self, (ReQL_Term_t)(reql_term_type(other)), reql_json_copy(reql_term_args(other)), reql_json_copy(reql_term_kwargs(other)));
      break;
    }
    case REQL_R_JSON: {
      free(self); self = NULL;
      break;
    }
  }

  return self;
}

extern ReQL_Obj_t *
reql_json_move(ReQL_Obj_t *other) {
  ReQL_Obj_t *self = malloc(sizeof(ReQL_Obj_t));

  if (self == NULL) {
    return NULL;
  }

  switch (reql_datum_type(other)) {
    case REQL_R_ARRAY: {
      const ReQL_Size alloc_size = reql_alloc_size(other);
      ReQL_Obj_t **array = reql_array(other);
      reql_set_array(other, NULL);
      reql_array_init(self, array, alloc_size);
      reql_set_size(self, reql_size(other));
      reql_set_size(other, 0);

      ReQL_Size i;
      for (i=0; i < alloc_size; ++i) {
        if (array[i] != NULL) {
          array[i]->owner = self;
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
      const ReQL_Size alloc_size = reql_alloc_size(other);
      ReQL_Pair_t *pairs = reql_pair(other);
      reql_set_pair(other, NULL);
      reql_object_init(self, pairs, alloc_size);
      reql_set_size(self, reql_size(other));
      reql_set_size(other, 0);

      ReQL_Size i;
      for (i=0; i < alloc_size; ++i) {
        if (pairs[i].key != NULL) {
          pairs[i].key->owner = self;
        }
        if (pairs[i].val != NULL) {
          pairs[i].val->owner = self;
        }
      }
      break;
    }
    case REQL_R_STR: {
      reql_var_json_init(self, REQL_R_STR, reql_alloc_size(other));
      reql_set_str(self, reql_string_buf(other));
      reql_set_size(self, reql_size(other));
      reql_set_str(other, NULL);
      reql_set_size(other, 0);
      break;
    }
    case REQL_R_REQL: {
      reql_term_args(other)->owner = NULL;
      reql_term_kwargs(other)->owner = NULL;
      reql_term_init(self, (ReQL_Term_t)(reql_term_type(other)), reql_term_args(other), reql_term_kwargs(other));
      reql_term_init(other, REQL_DATUM, NULL, NULL);
      break;
    }
    case REQL_R_JSON: {
      free(self); self = NULL;
      break;
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
        reql_error_init(REQL_E_JSON, "insufficient space in object", __func__);
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
        const ReQL_Size size = reql_alloc_size(owner);
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
        const ReQL_Size size = reql_alloc_size(owner);
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
        if (reql_term_args(owner) == json) {
          owner->obj.args.args = NULL;
        } else if (reql_term_kwargs(owner) == json) {
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
      reql_json_destroy(reql_term_args(json));
      reql_json_destroy(reql_term_kwargs(json));
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

extern void
reql_ast_add(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ADD, a, NULL);
}

extern void
reql_ast_and(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_AND, a, NULL);
}

extern void
reql_ast_append(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_APPEND, a, NULL);
}

extern void
reql_ast_april(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_APRIL, a, NULL);
}

extern void
reql_ast_args(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ARGS, a, NULL);
}

extern void
reql_ast_asc(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ASC, a, NULL);
}

extern void
reql_ast_august(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_AUGUST, a, NULL);
}

extern void
reql_ast_avg(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_AVG, a, NULL);
}

extern void
reql_ast_between(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BETWEEN, a, NULL);
}

extern void
reql_ast_between_deprecated(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BETWEEN_DEPRECATED, a, NULL);
}

extern void
reql_ast_binary(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BINARY, a, NULL);
}

extern void
reql_ast_bracket(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BRACKET, a, NULL);
}

extern void
reql_ast_branch(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_BRANCH, a, NULL);
}

extern void
reql_ast_ceil(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CEIL, a, NULL);
}

extern void
reql_ast_changes(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CHANGES, a, NULL);
}

extern void
reql_ast_change_at(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CHANGE_AT, a, NULL);
}

extern void
reql_ast_circle(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_CIRCLE, a, k);
}

extern void
reql_ast_coerce_to(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_COERCE_TO, a, NULL);
}

extern void
reql_ast_concat_map(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CONCAT_MAP, a, NULL);
}

extern void
reql_ast_config(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CONFIG, a, NULL);
}

extern void
reql_ast_contains(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_CONTAINS, a, NULL);
}

extern void
reql_ast_count(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_COUNT, a, NULL);
}

extern void
reql_ast_date(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DATE, a, NULL);
}

extern void
reql_ast_datum(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DATUM, a, NULL);
}

extern void
reql_ast_day(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DAY, a, NULL);
}

extern void
reql_ast_day_of_week(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DAY_OF_WEEK, a, NULL);
}

extern void
reql_ast_day_of_year(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DAY_OF_YEAR, a, NULL);
}

extern void
reql_ast_db(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DB, a, NULL);
}

extern void
reql_ast_db_create(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DB_CREATE, a, NULL);
}

extern void
reql_ast_db_drop(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DB_DROP, a, NULL);
}

extern void
reql_ast_db_list(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DB_LIST, a, NULL);
}

extern void
reql_ast_december(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DECEMBER, a, NULL);
}

extern void
reql_ast_default(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DEFAULT, a, NULL);
}

extern void
reql_ast_delete(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_DELETE, a, k);
}

extern void
reql_ast_delete_at(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DELETE_AT, a, NULL);
}

extern void
reql_ast_desc(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DESC, a, NULL);
}

extern void
reql_ast_difference(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DIFFERENCE, a, NULL);
}

extern void
reql_ast_distance(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DISTANCE, a, NULL);
}

extern void
reql_ast_distinct(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_DISTINCT, a, k);
}

extern void
reql_ast_div(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DIV, a, NULL);
}

extern void
reql_ast_downcase(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DOWNCASE, a, NULL);
}

extern void
reql_ast_during(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_DURING, a, NULL);
}

extern void
reql_ast_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_EPOCH_TIME, a, NULL);
}

extern void
reql_ast_eq(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_EQ, a, NULL);
}

extern void
reql_ast_eq_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_EQ_JOIN, a, k);
}

extern void
reql_ast_error(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ERROR, a, NULL);
}

extern void
reql_ast_february(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FEBRUARY, a, NULL);
}

extern void
reql_ast_fill(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FILL, a, NULL);
}

extern void
reql_ast_filter(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_FILTER, a, k);
}

extern void
reql_ast_floor(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FLOOR, a, NULL);
}

extern void
reql_ast_for_each(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FOR_EACH, a, NULL);
}

extern void
reql_ast_friday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FRIDAY, a, NULL);
}

extern void
reql_ast_func(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FUNC, a, NULL);
}

extern void
reql_ast_funcall(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_FUNCALL, a, NULL);
}

extern void
reql_ast_ge(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GE, a, NULL);
}

extern void
reql_ast_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GEOJSON, a, NULL);
}

extern void
reql_ast_get(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GET, a, NULL);
}

extern void
reql_ast_get_all(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_GET_ALL, a, k);
}

extern void
reql_ast_get_field(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_GET_FIELD, a, NULL);
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
  reql_term_init(t, REQL_GT, a, NULL);
}

extern void
reql_ast_has_fields(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_HAS_FIELDS, a, NULL);
}

extern void
reql_ast_hours(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_HOURS, a, NULL);
}

extern void
reql_ast_http(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_HTTP, a, k);
}

extern void
reql_ast_implicit_var(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_IMPLICIT_VAR, a, NULL);
}

extern void
reql_ast_includes(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INCLUDES, a, NULL);
}

extern void
reql_ast_index_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_INDEX_CREATE, a, k);
}

extern void
reql_ast_index_drop(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INDEX_DROP, a, NULL);
}

extern void
reql_ast_index_list(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INDEX_LIST, a, NULL);
}

extern void
reql_ast_index_rename(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_INDEX_RENAME, a, k);
}

extern void
reql_ast_index_status(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INDEX_STATUS, a, NULL);
}

extern void
reql_ast_index_wait(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INDEX_WAIT, a, NULL);
}

extern void
reql_ast_info(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INFO, a, NULL);
}

extern void
reql_ast_inner_join(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INNER_JOIN, a, NULL);
}

extern void
reql_ast_insert(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INSERT, a, NULL);
}

extern void
reql_ast_insert_at(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INSERT_AT, a, NULL);
}

extern void
reql_ast_intersects(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_INTERSECTS, a, NULL);
}

extern void
reql_ast_in_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_IN_TIMEZONE, a, NULL);
}

extern void
reql_ast_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_ISO8601, a, k);
}

extern void
reql_ast_is_empty(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_IS_EMPTY, a, NULL);
}

extern void
reql_ast_january(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_JANUARY, a, NULL);
}

extern void
reql_ast_javascript(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_JAVASCRIPT, a, k);
}

extern void
reql_ast_json(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_JSON, a, NULL);
}

extern void
reql_ast_july(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_JULY, a, NULL);
}

extern void
reql_ast_june(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_JUNE, a, NULL);
}

extern void
reql_ast_keys(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_KEYS, a, NULL);
}

extern void
reql_ast_le(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LE, a, NULL);
}

extern void
reql_ast_limit(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LIMIT, a, NULL);
}

extern void
reql_ast_line(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LINE, a, NULL);
}

extern void
reql_ast_literal(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LITERAL, a, NULL);
}

extern void
reql_ast_lt(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_LT, a, NULL);
}

extern void
reql_ast_make_array(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAKE_ARRAY, a, NULL);
}

extern void
reql_ast_make_obj(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAKE_OBJ, a, NULL);
}

extern void
reql_ast_map(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAP, a, NULL);
}

extern void
reql_ast_march(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MARCH, a, NULL);
}

extern void
reql_ast_match(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MATCH, a, NULL);
}

extern void
reql_ast_max(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAX, a, NULL);
}

extern void
reql_ast_maxval(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAXVAL, a, NULL);
}

extern void
reql_ast_may(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MAY, a, NULL);
}

extern void
reql_ast_merge(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MERGE, a, NULL);
}

extern void
reql_ast_min(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MIN, a, NULL);
}

extern void
reql_ast_minutes(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MINUTES, a, NULL);
}

extern void
reql_ast_minval(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MINVAL, a, NULL);
}

extern void
reql_ast_mod(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MOD, a, NULL);
}

extern void
reql_ast_monday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MONDAY, a, NULL);
}

extern void
reql_ast_month(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MONTH, a, NULL);
}

extern void
reql_ast_mul(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_MUL, a, NULL);
}

extern void
reql_ast_ne(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NE, a, NULL);
}

extern void
reql_ast_not(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NOT, a, NULL);
}

extern void
reql_ast_november(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NOVEMBER, a, NULL);
}

extern void
reql_ast_now(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NOW, a, NULL);
}

extern void
reql_ast_nth(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_NTH, a, NULL);
}

extern void
reql_ast_object(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OBJECT, a, NULL);
}

extern void
reql_ast_october(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OCTOBER, a, NULL);
}

extern void
reql_ast_offsets_of(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OFFSETS_OF, a, NULL);
}

extern void
reql_ast_or(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OR, a, NULL);
}

extern void
reql_ast_order_by(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_ORDER_BY, a, k);
}

extern void
reql_ast_outer_join(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_OUTER_JOIN, a, NULL);
}

extern void
reql_ast_pluck(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_PLUCK, a, NULL);
}

extern void
reql_ast_point(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_POINT, a, NULL);
}

extern void
reql_ast_polygon(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_POLYGON, a, NULL);
}

extern void
reql_ast_polygon_sub(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_POLYGON_SUB, a, NULL);
}

extern void
reql_ast_prepend(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_PREPEND, a, NULL);
}

extern void
reql_ast_random(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_RANDOM, a, k);
}

extern void
reql_ast_range(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_RANGE, a, NULL);
}

extern void
reql_ast_rebalance(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_REBALANCE, a, NULL);
}

extern void
reql_ast_reconfigure(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_RECONFIGURE, a, NULL);
}

extern void
reql_ast_reduce(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_REDUCE, a, NULL);
}

extern void
reql_ast_replace(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_REPLACE, a, k);
}

extern void
reql_ast_round(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ROUND, a, NULL);
}

extern void
reql_ast_sample(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SAMPLE, a, NULL);
}

extern void
reql_ast_saturday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SATURDAY, a, NULL);
}

extern void
reql_ast_seconds(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SECONDS, a, NULL);
}

extern void
reql_ast_september(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SEPTEMBER, a, NULL);
}

extern void
reql_ast_set_difference(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SET_DIFFERENCE, a, NULL);
}

extern void
reql_ast_set_insert(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SET_INSERT, a, NULL);
}

extern void
reql_ast_set_intersection(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SET_INTERSECTION, a, NULL);
}

extern void
reql_ast_set_union(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SET_UNION, a, NULL);
}

extern void
reql_ast_skip(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SKIP, a, NULL);
}

extern void
reql_ast_slice(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_SLICE, a, k);
}

extern void
reql_ast_splice_at(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SPLICE_AT, a, NULL);
}

extern void
reql_ast_split(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SPLIT, a, NULL);
}

extern void
reql_ast_status(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_STATUS, a, NULL);
}

extern void
reql_ast_sub(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SUB, a, NULL);
}

extern void
reql_ast_sum(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SUM, a, NULL);
}

extern void
reql_ast_sunday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SUNDAY, a, NULL);
}

extern void
reql_ast_sync(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_SYNC, a, NULL);
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
  reql_term_init(t, REQL_TABLE_DROP, a, NULL);
}

extern void
reql_ast_table_list(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TABLE_LIST, a, NULL);
}

extern void
reql_ast_thursday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_THURSDAY, a, NULL);
}

extern void
reql_ast_time(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TIME, a, NULL);
}

extern void
reql_ast_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TIMEZONE, a, NULL);
}

extern void
reql_ast_time_of_day(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TIME_OF_DAY, a, NULL);
}

extern void
reql_ast_to_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TO_EPOCH_TIME, a, NULL);
}

extern void
reql_ast_to_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TO_GEOJSON, a, NULL);
}

extern void
reql_ast_to_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TO_ISO8601, a, NULL);
}

extern void
reql_ast_to_json_string(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TO_JSON_STRING, a, NULL);
}

extern void
reql_ast_tuesday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TUESDAY, a, NULL);
}

extern void
reql_ast_type_of(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_TYPE_OF, a, NULL);
}

extern void
reql_ast_ungroup(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_UNGROUP, a, NULL);
}

extern void
reql_ast_union(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_UNION, a, NULL);
}

extern void
reql_ast_upcase(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_UPCASE, a, NULL);
}

extern void
reql_ast_update(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_term_init(t, REQL_UPDATE, a, k);
}

extern void
reql_ast_uuid(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_UUID, a, NULL);
}

extern void
reql_ast_var(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_VAR, a, NULL);
}

extern void
reql_ast_wait(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_WAIT, a, NULL);
}

extern void
reql_ast_wednesday(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_WEDNESDAY, a, NULL);
}

extern void
reql_ast_without(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_WITHOUT, a, NULL);
}

extern void
reql_ast_with_fields(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_WITH_FIELDS, a, NULL);
}

extern void
reql_ast_year(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_YEAR, a, NULL);
}

extern void
reql_ast_zip(ReQL_Obj_t *t, ReQL_Obj_t *a) {
  reql_term_init(t, REQL_ZIP, a, NULL);
}
