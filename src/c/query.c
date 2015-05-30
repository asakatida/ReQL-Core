/*
Copyright 2015 Adam Grandquist

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

#include "./c/query.h"

#include "./reql/core.h"

#include <stdlib.h>
#include <string.h>

typedef ReQL_Obj_t *(*ReQL_Build)(ReQL_t *obj);

#define NEW_REQL ReQL_t *reql = malloc(sizeof(ReQL_t));\
if (reql == NULL) {\
  return NULL;\
}

#define SET_DATA(size, obj) reql->data = malloc(size);\
if (reql->data == NULL) {\
  free(reql);\
  return NULL;\
}\
memcpy(reql->data, obj, size);

#define NEW_REQL_OBJ ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));\
if (obj == NULL) {\
  return NULL;\
}

struct ReQL_s {
  ReQL_Build cb;
  void *data;
  size_t size;
};

struct ReQL_Args_s {
  ReQL_t *args;
  ReQL_t *kwargs;
};
typedef struct ReQL_Args_s ReQL_Args_t;

static ReQL_Obj_t *
reql_array_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  ReQL_Obj_t **buf = malloc(sizeof(ReQL_Obj_t*) * reql->size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_array_init(obj, buf, (ReQL_Size)reql->size);
  unsigned long i;
  for (i = 0; i < reql->size;) {
    ReQL_t *val = ((ReQL_t**)reql->data)[i++];
    reql_array_append(obj, val->cb(val));
  }
  return obj;
}

extern ReQL_t *
reql_array(ReQL_t **val) {
  NEW_REQL;
  reql->size = 0;
  while (val[reql->size++] != NULL) {}
  SET_DATA(sizeof(ReQL_t*) * reql->size, val);
  reql->cb = reql_array_;
  return reql;
}

static ReQL_Obj_t *
reql_bool_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  reql_bool_init(obj, reql->size ? 1 == 1 : 0 == 1);
  return obj;
}

extern ReQL_t *
reql_bool(const int val) {
  NEW_REQL;
  reql->data = NULL;
  reql->size = (size_t)val;
  reql->cb = reql_bool_;
  return reql;
}

static ReQL_Obj_t *
reql_destroy_(ReQL_t *reql) {
  (void)reql;
  return NULL;
}

extern void
reql_destroy(ReQL_t *reql) {
  reql->cb = reql_destroy_;
  free(reql->data); reql->data = NULL;
  free(reql);
}

static ReQL_Obj_t *
reql_json_object_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  ReQL_Pair_t *buf = malloc(sizeof(ReQL_Pair_t) * reql->size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_object_init(obj, buf, (ReQL_Size)reql->size);
  unsigned long i;
  for (i = 0; i < reql->size;) {
    ReQL_t *key = ((ReQL_t**)reql->data)[i++];
    ReQL_t *val = ((ReQL_t**)reql->data)[i++];
    reql_object_add(obj, key->cb(key), val->cb(val));
  }
  return obj;
}

extern ReQL_t *
reql_json_object(ReQL_t **val) {
  NEW_REQL;
  reql->size = 0;
  while (val[reql->size++] != NULL) {}
  SET_DATA(sizeof(ReQL_t*) * reql->size, val);
  reql->size /= 2;
  reql->cb = reql_json_object_;
  return reql;
}

static ReQL_Obj_t *
reql_null_(ReQL_t *reql) {
  (void)reql;
  NEW_REQL_OBJ;
  reql_null_init(obj);
  return obj;
}

extern ReQL_t *
reql_null() {
  NEW_REQL;
  reql->data = NULL;
  reql->size = 0;
  reql->cb = reql_null_;
  return reql;
}

static ReQL_Obj_t *
reql_number_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  reql_number_init(obj, *(double *)reql->data);
  return obj;
}

extern ReQL_t *
reql_number(double val) {
  NEW_REQL;
  SET_DATA(sizeof(double), &val);
  reql->cb = reql_number_;
  return reql;
}

static ReQL_Obj_t *
reql_string_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  ReQL_Byte *buf = malloc(sizeof(ReQL_Byte) * reql->size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_string_init(obj, buf, (ReQL_Size)reql->size);
  reql_string_append(obj, (ReQL_Byte *)reql->data, (ReQL_Size)reql->size);
  return obj;
}

extern ReQL_t *
reql_string(const char *val, const unsigned long size) {
  NEW_REQL;
  reql->size = (size_t)size;
  SET_DATA(sizeof(char) * reql->size, val);
  reql->cb = reql_string_;
  return reql;
}

static ReQL_Obj_t *
reql_term_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  ReQL_Args_t *data = (ReQL_Args_t *)reql->data;
  ReQL_t *args = data->args;
  ReQL_Obj_t *r_args = NULL;
  if (args != NULL) {
    r_args = args->cb(args);
  }
  ReQL_t *kwargs = data->kwargs;
  ReQL_Obj_t *r_kwargs = NULL;
  if (kwargs != NULL) {
    r_kwargs = kwargs->cb(kwargs);
  }
  reql_term_init(obj, (ReQL_Term_t)reql->size, r_args, r_kwargs);
  return obj;
}

static ReQL_t *
reql_term(ReQL_Term_t tt, ReQL_t **args, ReQL_t **kwargs) {
  NEW_REQL;
  ReQL_Args_t *data = malloc(sizeof(ReQL_Args_t));
  if (data == NULL) {
    free(reql);
    return NULL;
  }
  if (args == NULL) {
    data->args = NULL;
  } else {
    data->args = reql_array(args);
    if (data->args == NULL) {
      free(data);
      free(reql);
      return NULL;
    }
  }
  if (kwargs == NULL) {
    data->kwargs = NULL;
  } else {
    data->kwargs = reql_json_object(kwargs);
    if (data->kwargs == NULL) {
      if (data->args != NULL) {
        reql_destroy(data->args);
      }
      free(data);
      free(reql);
      return NULL;
    }
  }
  reql->size = (size_t)tt;
  reql->data = data;
  reql->cb = reql_term_;
  return reql;
}

extern ReQL_t *
reql_add(ReQL_t **args) {
  return reql_term(REQL_ADD, args, NULL);
}

extern ReQL_t *
reql_and(ReQL_t **args) {
  return reql_term(REQL_AND, args, NULL);
}

extern ReQL_t *
reql_append(ReQL_t **args) {
  return reql_term(REQL_APPEND, args, NULL);
}

extern ReQL_t *
reql_april(ReQL_t **args) {
  return reql_term(REQL_APRIL, args, NULL);
}

extern ReQL_t *
reql_args(ReQL_t **args) {
  return reql_term(REQL_ARGS, args, NULL);
}

extern ReQL_t *
reql_asc(ReQL_t **args) {
  return reql_term(REQL_ASC, args, NULL);
}

extern ReQL_t *
reql_august(ReQL_t **args) {
  return reql_term(REQL_AUGUST, args, NULL);
}

extern ReQL_t *
reql_avg(ReQL_t **args) {
  return reql_term(REQL_AVG, args, NULL);
}

extern ReQL_t *
reql_between(ReQL_t **args) {
  return reql_term(REQL_BETWEEN, args, NULL);
}

extern ReQL_t *
reql_between_deprecated(ReQL_t **args) {
  return reql_term(REQL_BETWEEN_DEPRECATED, args, NULL);
}

extern ReQL_t *
reql_binary(ReQL_t **args) {
  return reql_term(REQL_BINARY, args, NULL);
}

extern ReQL_t *
reql_bracket(ReQL_t **args) {
  return reql_term(REQL_BRACKET, args, NULL);
}

extern ReQL_t *
reql_branch(ReQL_t **args) {
  return reql_term(REQL_BRANCH, args, NULL);
}

extern ReQL_t *
reql_ceil(ReQL_t **args) {
  return reql_term(REQL_CEIL, args, NULL);
}

extern ReQL_t *
reql_changes(ReQL_t **args) {
  return reql_term(REQL_CHANGES, args, NULL);
}

extern ReQL_t *
reql_change_at(ReQL_t **args) {
  return reql_term(REQL_CHANGE_AT, args, NULL);
}

extern ReQL_t *
reql_circle(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_CIRCLE, args, kwargs);
}

extern ReQL_t *
reql_coerce_to(ReQL_t **args) {
  return reql_term(REQL_COERCE_TO, args, NULL);
}

extern ReQL_t *
reql_concat_map(ReQL_t **args) {
  return reql_term(REQL_CONCAT_MAP, args, NULL);
}

extern ReQL_t *
reql_config(ReQL_t **args) {
  return reql_term(REQL_CONFIG, args, NULL);
}

extern ReQL_t *
reql_contains(ReQL_t **args) {
  return reql_term(REQL_CONTAINS, args, NULL);
}

extern ReQL_t *
reql_count(ReQL_t **args) {
  return reql_term(REQL_COUNT, args, NULL);
}

extern ReQL_t *
reql_date(ReQL_t **args) {
  return reql_term(REQL_DATE, args, NULL);
}

extern ReQL_t *
reql_datum(ReQL_t **args) {
  return reql_term(REQL_DATUM, args, NULL);
}

extern ReQL_t *
reql_day(ReQL_t **args) {
  return reql_term(REQL_DAY, args, NULL);
}

extern ReQL_t *
reql_day_of_week(ReQL_t **args) {
  return reql_term(REQL_DAY_OF_WEEK, args, NULL);
}

extern ReQL_t *
reql_day_of_year(ReQL_t **args) {
  return reql_term(REQL_DAY_OF_YEAR, args, NULL);
}

extern ReQL_t *
reql_db(ReQL_t **args) {
  return reql_term(REQL_DB, args, NULL);
}

extern ReQL_t *
reql_db_create(ReQL_t **args) {
  return reql_term(REQL_DB_CREATE, args, NULL);
}

extern ReQL_t *
reql_db_drop(ReQL_t **args) {
  return reql_term(REQL_DB_DROP, args, NULL);
}

extern ReQL_t *
reql_db_list(ReQL_t **args) {
  return reql_term(REQL_DB_LIST, args, NULL);
}

extern ReQL_t *
reql_december(ReQL_t **args) {
  return reql_term(REQL_DECEMBER, args, NULL);
}

extern ReQL_t *
reql_default(ReQL_t **args) {
  return reql_term(REQL_DEFAULT, args, NULL);
}

extern ReQL_t *
reql_delete(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_DELETE, args, kwargs);
}

extern ReQL_t *
reql_delete_at(ReQL_t **args) {
  return reql_term(REQL_DELETE_AT, args, NULL);
}

extern ReQL_t *
reql_desc(ReQL_t **args) {
  return reql_term(REQL_DESC, args, NULL);
}

extern ReQL_t *
reql_difference(ReQL_t **args) {
  return reql_term(REQL_DIFFERENCE, args, NULL);
}

extern ReQL_t *
reql_distance(ReQL_t **args) {
  return reql_term(REQL_DISTANCE, args, NULL);
}

extern ReQL_t *
reql_distinct(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_DISTINCT, args, kwargs);
}

extern ReQL_t *
reql_div(ReQL_t **args) {
  return reql_term(REQL_DIV, args, NULL);
}

extern ReQL_t *
reql_downcase(ReQL_t **args) {
  return reql_term(REQL_DOWNCASE, args, NULL);
}

extern ReQL_t *
reql_during(ReQL_t **args) {
  return reql_term(REQL_DURING, args, NULL);
}

extern ReQL_t *
reql_epoch_time(ReQL_t **args) {
  return reql_term(REQL_EPOCH_TIME, args, NULL);
}

extern ReQL_t *
reql_eq(ReQL_t **args) {
  return reql_term(REQL_EQ, args, NULL);
}

extern ReQL_t *
reql_eq_join(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_EQ_JOIN, args, kwargs);
}

extern ReQL_t *
reql_error(ReQL_t **args) {
  return reql_term(REQL_ERROR, args, NULL);
}

extern ReQL_t *
reql_february(ReQL_t **args) {
  return reql_term(REQL_FEBRUARY, args, NULL);
}

extern ReQL_t *
reql_fill(ReQL_t **args) {
  return reql_term(REQL_FILL, args, NULL);
}

extern ReQL_t *
reql_filter(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_FILTER, args, kwargs);
}

extern ReQL_t *
reql_floor(ReQL_t **args) {
  return reql_term(REQL_FLOOR, args, NULL);
}

extern ReQL_t *
reql_for_each(ReQL_t **args) {
  return reql_term(REQL_FOR_EACH, args, NULL);
}

extern ReQL_t *
reql_friday(ReQL_t **args) {
  return reql_term(REQL_FRIDAY, args, NULL);
}

extern ReQL_t *
reql_func(ReQL_t **args) {
  return reql_term(REQL_FUNC, args, NULL);
}

extern ReQL_t *
reql_funcall(ReQL_t **args) {
  return reql_term(REQL_FUNCALL, args, NULL);
}

extern ReQL_t *
reql_ge(ReQL_t **args) {
  return reql_term(REQL_GE, args, NULL);
}

extern ReQL_t *
reql_geojson(ReQL_t **args) {
  return reql_term(REQL_GEOJSON, args, NULL);
}

extern ReQL_t *
reql_get(ReQL_t **args) {
  return reql_term(REQL_GET, args, NULL);
}

extern ReQL_t *
reql_get_all(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_GET_ALL, args, kwargs);
}

extern ReQL_t *
reql_get_field(ReQL_t **args) {
  return reql_term(REQL_GET_FIELD, args, NULL);
}

extern ReQL_t *
reql_get_intersecting(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_GET_INTERSECTING, args, kwargs);
}

extern ReQL_t *
reql_get_nearest(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_GET_NEAREST, args, kwargs);
}

extern ReQL_t *
reql_group(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_GROUP, args, kwargs);
}

extern ReQL_t *
reql_gt(ReQL_t **args) {
  return reql_term(REQL_GT, args, NULL);
}

extern ReQL_t *
reql_has_fields(ReQL_t **args) {
  return reql_term(REQL_HAS_FIELDS, args, NULL);
}

extern ReQL_t *
reql_hours(ReQL_t **args) {
  return reql_term(REQL_HOURS, args, NULL);
}

extern ReQL_t *
reql_http(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_HTTP, args, kwargs);
}

extern ReQL_t *
reql_implicit_var(ReQL_t **args) {
  return reql_term(REQL_IMPLICIT_VAR, args, NULL);
}

extern ReQL_t *
reql_includes(ReQL_t **args) {
  return reql_term(REQL_INCLUDES, args, NULL);
}

extern ReQL_t *
reql_index_create(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_INDEX_CREATE, args, kwargs);
}

extern ReQL_t *
reql_index_drop(ReQL_t **args) {
  return reql_term(REQL_INDEX_DROP, args, NULL);
}

extern ReQL_t *
reql_index_list(ReQL_t **args) {
  return reql_term(REQL_INDEX_LIST, args, NULL);
}

extern ReQL_t *
reql_index_rename(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_INDEX_RENAME, args, kwargs);
}

extern ReQL_t *
reql_index_status(ReQL_t **args) {
  return reql_term(REQL_INDEX_STATUS, args, NULL);
}

extern ReQL_t *
reql_index_wait(ReQL_t **args) {
  return reql_term(REQL_INDEX_WAIT, args, NULL);
}

extern ReQL_t *
reql_info(ReQL_t **args) {
  return reql_term(REQL_INFO, args, NULL);
}

extern ReQL_t *
reql_inner_join(ReQL_t **args) {
  return reql_term(REQL_INNER_JOIN, args, NULL);
}

extern ReQL_t *
reql_insert(ReQL_t **args) {
  return reql_term(REQL_INSERT, args, NULL);
}

extern ReQL_t *
reql_insert_at(ReQL_t **args) {
  return reql_term(REQL_INSERT_AT, args, NULL);
}

extern ReQL_t *
reql_intersects(ReQL_t **args) {
  return reql_term(REQL_INTERSECTS, args, NULL);
}

extern ReQL_t *
reql_in_timezone(ReQL_t **args) {
  return reql_term(REQL_IN_TIMEZONE, args, NULL);
}

extern ReQL_t *
reql_iso8601(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_ISO8601, args, kwargs);
}

extern ReQL_t *
reql_is_empty(ReQL_t **args) {
  return reql_term(REQL_IS_EMPTY, args, NULL);
}

extern ReQL_t *
reql_january(ReQL_t **args) {
  return reql_term(REQL_JANUARY, args, NULL);
}

extern ReQL_t *
reql_javascript(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_JAVASCRIPT, args, kwargs);
}

extern ReQL_t *
reql_json(ReQL_t **args) {
  return reql_term(REQL_JSON, args, NULL);
}

extern ReQL_t *
reql_july(ReQL_t **args) {
  return reql_term(REQL_JULY, args, NULL);
}

extern ReQL_t *
reql_june(ReQL_t **args) {
  return reql_term(REQL_JUNE, args, NULL);
}

extern ReQL_t *
reql_keys(ReQL_t **args) {
  return reql_term(REQL_KEYS, args, NULL);
}

extern ReQL_t *
reql_le(ReQL_t **args) {
  return reql_term(REQL_LE, args, NULL);
}

extern ReQL_t *
reql_limit(ReQL_t **args) {
  return reql_term(REQL_LIMIT, args, NULL);
}

extern ReQL_t *
reql_line(ReQL_t **args) {
  return reql_term(REQL_LINE, args, NULL);
}

extern ReQL_t *
reql_literal(ReQL_t **args) {
  return reql_term(REQL_LITERAL, args, NULL);
}

extern ReQL_t *
reql_lt(ReQL_t **args) {
  return reql_term(REQL_LT, args, NULL);
}

extern ReQL_t *
reql_make_array(ReQL_t **args) {
  return reql_term(REQL_MAKE_ARRAY, args, NULL);
}

extern ReQL_t *
reql_make_obj(ReQL_t **args) {
  return reql_term(REQL_MAKE_OBJ, args, NULL);
}

extern ReQL_t *
reql_map(ReQL_t **args) {
  return reql_term(REQL_MAP, args, NULL);
}

extern ReQL_t *
reql_march(ReQL_t **args) {
  return reql_term(REQL_MARCH, args, NULL);
}

extern ReQL_t *
reql_match(ReQL_t **args) {
  return reql_term(REQL_MATCH, args, NULL);
}

extern ReQL_t *
reql_max(ReQL_t **args) {
  return reql_term(REQL_MAX, args, NULL);
}

extern ReQL_t *
reql_maxval(ReQL_t **args) {
  return reql_term(REQL_MAXVAL, args, NULL);
}

extern ReQL_t *
reql_may(ReQL_t **args) {
  return reql_term(REQL_MAY, args, NULL);
}

extern ReQL_t *
reql_merge(ReQL_t **args) {
  return reql_term(REQL_MERGE, args, NULL);
}

extern ReQL_t *
reql_min(ReQL_t **args) {
  return reql_term(REQL_MIN, args, NULL);
}

extern ReQL_t *
reql_minutes(ReQL_t **args) {
  return reql_term(REQL_MINUTES, args, NULL);
}

extern ReQL_t *
reql_minval(ReQL_t **args) {
  return reql_term(REQL_MINVAL, args, NULL);
}

extern ReQL_t *
reql_mod(ReQL_t **args) {
  return reql_term(REQL_MOD, args, NULL);
}

extern ReQL_t *
reql_monday(ReQL_t **args) {
  return reql_term(REQL_MONDAY, args, NULL);
}

extern ReQL_t *
reql_month(ReQL_t **args) {
  return reql_term(REQL_MONTH, args, NULL);
}

extern ReQL_t *
reql_mul(ReQL_t **args) {
  return reql_term(REQL_MUL, args, NULL);
}

extern ReQL_t *
reql_ne(ReQL_t **args) {
  return reql_term(REQL_NE, args, NULL);
}

extern ReQL_t *
reql_not(ReQL_t **args) {
  return reql_term(REQL_NOT, args, NULL);
}

extern ReQL_t *
reql_november(ReQL_t **args) {
  return reql_term(REQL_NOVEMBER, args, NULL);
}

extern ReQL_t *
reql_now(ReQL_t **args) {
  return reql_term(REQL_NOW, args, NULL);
}

extern ReQL_t *
reql_nth(ReQL_t **args) {
  return reql_term(REQL_NTH, args, NULL);
}

extern ReQL_t *
reql_object(ReQL_t **args) {
  return reql_term(REQL_OBJECT, args, NULL);
}

extern ReQL_t *
reql_october(ReQL_t **args) {
  return reql_term(REQL_OCTOBER, args, NULL);
}

extern ReQL_t *
reql_offsets_of(ReQL_t **args) {
  return reql_term(REQL_OFFSETS_OF, args, NULL);
}

extern ReQL_t *
reql_or(ReQL_t **args) {
  return reql_term(REQL_OR, args, NULL);
}

extern ReQL_t *
reql_order_by(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_ORDER_BY, args, kwargs);
}

extern ReQL_t *
reql_outer_join(ReQL_t **args) {
  return reql_term(REQL_OUTER_JOIN, args, NULL);
}

extern ReQL_t *
reql_pluck(ReQL_t **args) {
  return reql_term(REQL_PLUCK, args, NULL);
}

extern ReQL_t *
reql_point(ReQL_t **args) {
  return reql_term(REQL_POINT, args, NULL);
}

extern ReQL_t *
reql_polygon(ReQL_t **args) {
  return reql_term(REQL_POLYGON, args, NULL);
}

extern ReQL_t *
reql_polygon_sub(ReQL_t **args) {
  return reql_term(REQL_POLYGON_SUB, args, NULL);
}

extern ReQL_t *
reql_prepend(ReQL_t **args) {
  return reql_term(REQL_PREPEND, args, NULL);
}

extern ReQL_t *
reql_random(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_RANDOM, args, kwargs);
}

extern ReQL_t *
reql_range(ReQL_t **args) {
  return reql_term(REQL_RANGE, args, NULL);
}

extern ReQL_t *
reql_rebalance(ReQL_t **args) {
  return reql_term(REQL_REBALANCE, args, NULL);
}

extern ReQL_t *
reql_reconfigure(ReQL_t **args) {
  return reql_term(REQL_RECONFIGURE, args, NULL);
}

extern ReQL_t *
reql_reduce(ReQL_t **args) {
  return reql_term(REQL_REDUCE, args, NULL);
}

extern ReQL_t *
reql_replace(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_REPLACE, args, kwargs);
}

extern ReQL_t *
reql_round(ReQL_t **args) {
  return reql_term(REQL_ROUND, args, NULL);
}

extern ReQL_t *
reql_sample(ReQL_t **args) {
  return reql_term(REQL_SAMPLE, args, NULL);
}

extern ReQL_t *
reql_saturday(ReQL_t **args) {
  return reql_term(REQL_SATURDAY, args, NULL);
}

extern ReQL_t *
reql_seconds(ReQL_t **args) {
  return reql_term(REQL_SECONDS, args, NULL);
}

extern ReQL_t *
reql_september(ReQL_t **args) {
  return reql_term(REQL_SEPTEMBER, args, NULL);
}

extern ReQL_t *
reql_set_difference(ReQL_t **args) {
  return reql_term(REQL_SET_DIFFERENCE, args, NULL);
}

extern ReQL_t *
reql_set_insert(ReQL_t **args) {
  return reql_term(REQL_SET_INSERT, args, NULL);
}

extern ReQL_t *
reql_set_intersection(ReQL_t **args) {
  return reql_term(REQL_SET_INTERSECTION, args, NULL);
}

extern ReQL_t *
reql_set_union(ReQL_t **args) {
  return reql_term(REQL_SET_UNION, args, NULL);
}

extern ReQL_t *
reql_skip(ReQL_t **args) {
  return reql_term(REQL_SKIP, args, NULL);
}

extern ReQL_t *
reql_slice(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_SLICE, args, kwargs);
}

extern ReQL_t *
reql_splice_at(ReQL_t **args) {
  return reql_term(REQL_SPLICE_AT, args, NULL);
}

extern ReQL_t *
reql_split(ReQL_t **args) {
  return reql_term(REQL_SPLIT, args, NULL);
}

extern ReQL_t *
reql_status(ReQL_t **args) {
  return reql_term(REQL_STATUS, args, NULL);
}

extern ReQL_t *
reql_sub(ReQL_t **args) {
  return reql_term(REQL_SUB, args, NULL);
}

extern ReQL_t *
reql_sum(ReQL_t **args) {
  return reql_term(REQL_SUM, args, NULL);
}

extern ReQL_t *
reql_sunday(ReQL_t **args) {
  return reql_term(REQL_SUNDAY, args, NULL);
}

extern ReQL_t *
reql_sync(ReQL_t **args) {
  return reql_term(REQL_SYNC, args, NULL);
}

extern ReQL_t *
reql_table(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_TABLE, args, kwargs);
}

extern ReQL_t *
reql_table_create(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_TABLE_CREATE, args, kwargs);
}

extern ReQL_t *
reql_table_drop(ReQL_t **args) {
  return reql_term(REQL_TABLE_DROP, args, NULL);
}

extern ReQL_t *
reql_table_list(ReQL_t **args) {
  return reql_term(REQL_TABLE_LIST, args, NULL);
}

extern ReQL_t *
reql_thursday(ReQL_t **args) {
  return reql_term(REQL_THURSDAY, args, NULL);
}

extern ReQL_t *
reql_time(ReQL_t **args) {
  return reql_term(REQL_TIME, args, NULL);
}

extern ReQL_t *
reql_timezone(ReQL_t **args) {
  return reql_term(REQL_TIMEZONE, args, NULL);
}

extern ReQL_t *
reql_time_of_day(ReQL_t **args) {
  return reql_term(REQL_TIME_OF_DAY, args, NULL);
}

extern ReQL_t *
reql_to_epoch_time(ReQL_t **args) {
  return reql_term(REQL_TO_EPOCH_TIME, args, NULL);
}

extern ReQL_t *
reql_to_geojson(ReQL_t **args) {
  return reql_term(REQL_TO_GEOJSON, args, NULL);
}

extern ReQL_t *
reql_to_iso8601(ReQL_t **args) {
  return reql_term(REQL_TO_ISO8601, args, NULL);
}

extern ReQL_t *
reql_to_json_string(ReQL_t **args) {
  return reql_term(REQL_TO_JSON_STRING, args, NULL);
}

extern ReQL_t *
reql_tuesday(ReQL_t **args) {
  return reql_term(REQL_TUESDAY, args, NULL);
}

extern ReQL_t *
reql_type_of(ReQL_t **args) {
  return reql_term(REQL_TYPE_OF, args, NULL);
}

extern ReQL_t *
reql_ungroup(ReQL_t **args) {
  return reql_term(REQL_UNGROUP, args, NULL);
}

extern ReQL_t *
reql_union(ReQL_t **args) {
  return reql_term(REQL_UNION, args, NULL);
}

extern ReQL_t *
reql_upcase(ReQL_t **args) {
  return reql_term(REQL_UPCASE, args, NULL);
}

extern ReQL_t *
reql_update(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term(REQL_UPDATE, args, kwargs);
}

extern ReQL_t *
reql_uuid(ReQL_t **args) {
  return reql_term(REQL_UUID, args, NULL);
}

extern ReQL_t *
reql_var(ReQL_t **args) {
  return reql_term(REQL_VAR, args, NULL);
}

extern ReQL_t *
reql_wait(ReQL_t **args) {
  return reql_term(REQL_WAIT, args, NULL);
}

extern ReQL_t *
reql_wednesday(ReQL_t **args) {
  return reql_term(REQL_WEDNESDAY, args, NULL);
}

extern ReQL_t *
reql_without(ReQL_t **args) {
  return reql_term(REQL_WITHOUT, args, NULL);
}

extern ReQL_t *
reql_with_fields(ReQL_t **args) {
  return reql_term(REQL_WITH_FIELDS, args, NULL);
}

extern ReQL_t *
reql_year(ReQL_t **args) {
  return reql_term(REQL_YEAR, args, NULL);
}

extern ReQL_t *
reql_zip(ReQL_t **args) {
  return reql_term(REQL_ZIP, args, NULL);
}
