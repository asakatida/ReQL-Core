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

#include "./c/types.h"
#include "./reql/core.h"

#include <stdlib.h>
#include <string.h>

#define NEW_REQL ReQL_t *reql = malloc(sizeof(ReQL_t));\
if (reql == NULL) {\
  return NULL;\
}

#define SET_DATA(size, obj) if (size == 0) {\
  reql->data = NULL;\
} else {\
  reql->data = malloc(size);\
  if (reql->data == NULL) {\
    free(reql);\
    return NULL;\
  }\
  memcpy(reql->data, obj, size);\
}

#define NEW_REQL_OBJ ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));\
if (obj == NULL) {\
  return NULL;\
}

#define REQL_BUILD(val) (val)->cb(val)

static ReQL_Obj_t *
reql_array_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  if (reql->data == NULL) {
    reql_array_init(obj, NULL, 0);
    return obj;
  }
  ReQL_Obj_t **buf = malloc(sizeof(ReQL_Obj_t*) * reql->size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_array_init(obj, buf, (ReQL_Size)reql->size);
  unsigned long i;
  for (i = 0; i < reql->size; ++i) {
    reql_array_append(obj, REQL_BUILD(((ReQL_t**)reql->data)[i]));
  }
  return obj;
}

static void
reql_array_destroy(ReQL_t *reql) {
  free(reql->data); reql->data = NULL;
}

extern ReQL_t *
reql_array(ReQL_t **val) {
  NEW_REQL;
  reql->size = 0;
  while (val[reql->size++] != NULL) {}
  --reql->size;
  SET_DATA(sizeof(ReQL_t*) * reql->size, val);
  reql->free = reql_array_destroy;
  reql->cb = reql_array_;
  return reql;
}

static ReQL_Obj_t *
reql_bool_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  reql_bool_init(obj, reql->size ? 1 == 1 : 0 == 1);
  return obj;
}

static void
reql_bool_destroy(ReQL_t *reql) {
  (void)reql;
}

extern ReQL_t *
reql_bool(const int val) {
  NEW_REQL;
  reql->data = NULL;
  reql->size = (size_t)val;
  reql->free = reql_bool_destroy;
  reql->cb = reql_bool_;
  return reql;
}

extern ReQL_t *
reql_c_string(const char *val) {
  size_t size = strlen(val);
  return reql_string(val, (unsigned long)size);
}

static ReQL_Obj_t *
reql_destroy_cb(ReQL_t *reql) {
  (void)reql;
  return NULL;
}

static void
reql_destroy_(ReQL_t *reql) {
  if (reql) {
    reql->cb = reql_destroy_cb;
    reql->free(reql);
    pthread_mutex_destroy(reql->mutex);
    free(reql->mutex);
    free(reql);
  }
}

extern void
reql_destroy(ReQL_t **reql) {
  if (reql) {
    reql_destroy_(*reql); *reql = NULL;
  }
}

static ReQL_Obj_t *
reql_function_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  return obj;
}

static void
reql_function_destroy(ReQL_t *reql) {
}

extern ReQL_t *
reql_function(ReQL_t *(*val)(ReQL_t **args), const int nargs) {
  NEW_REQL;
  reql->data = val;
  reql->size = (size_t)nargs;
  reql->free = reql_function_destroy;
  reql->cb = reql_function_;
  return reql;
}

static ReQL_Obj_t *
reql_json_object_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  if (reql->data == NULL) {
    reql_object_init(obj, NULL, 0);
    return obj;
  }
  ReQL_Pair_t *buf = malloc(sizeof(ReQL_Pair_t) * reql->size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_object_init(obj, buf, (ReQL_Size)reql->size);
  unsigned long i;
  for (i = 1; i < reql->size; i += 2) {
    reql_object_add(obj,
                    REQL_BUILD(((ReQL_t**)reql->data)[i-1]),
                    REQL_BUILD(((ReQL_t**)reql->data)[i]));
  }
  return obj;
}

static void
reql_json_object_destroy(ReQL_t *reql) {
  free(reql->data); reql->data = NULL;
}

extern ReQL_t *
reql_json_object(ReQL_t **val) {
  NEW_REQL;
  reql->size = 0;
  while (val[reql->size++] != NULL) {}
  --reql->size;
  SET_DATA(sizeof(ReQL_t*) * reql->size, val);
  reql->free = reql_json_object_destroy;
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

static void
reql_null_destroy(ReQL_t *reql) {
  (void)reql;
}

extern ReQL_t *
reql_null() {
  NEW_REQL;
  reql->data = NULL;
  reql->size = 0;
  reql->free = reql_null_destroy;
  reql->cb = reql_null_;
  return reql;
}

static ReQL_Obj_t *
reql_number_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  reql_number_init(obj, *(double *)reql->data);
  return obj;
}

static void
reql_number_destroy(ReQL_t *reql) {
  free(reql->data); reql->data = NULL;
}

extern ReQL_t *
reql_number(double val) {
  NEW_REQL;
  SET_DATA(sizeof(double), &val);
  reql->free = reql_number_destroy;
  reql->cb = reql_number_;
  return reql;
}

static ReQL_Obj_t *
reql_string_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  if (reql->data == NULL) {
    reql_string_init(obj, NULL, NULL, 0);
    return obj;
  }
  ReQL_Byte *buf = malloc(sizeof(ReQL_Byte) * reql->size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_string_init(obj, buf, (ReQL_Byte *)reql->data, (ReQL_Size)reql->size);
  return obj;
}

static void
reql_string_destroy(ReQL_t *reql) {
  free(reql->data); reql->data = NULL;
}

extern ReQL_t *
reql_string(const char *val, const unsigned long size) {
  NEW_REQL;
  reql->size = (size_t)size;
  SET_DATA(sizeof(char) * reql->size, val);
  reql->free = reql_string_destroy;
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
    r_args = REQL_BUILD(args);
  }
  data->func(obj, r_args);
  return obj;
}

static void
reql_term_destroy(ReQL_t *reql) {
  ReQL_Args_t *data = (ReQL_Args_t *)reql->data; reql->data = NULL;
  free(data);
}

static ReQL_t *
reql_term(ReQL_AST_Function func, ReQL_t **args) {
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
  data->func = func;
  reql->data = data;
  reql->free = reql_term_destroy;
  reql->cb = reql_term_;
  return reql;
}

static ReQL_Obj_t *
reql_term_kwargs_(ReQL_t *reql) {
  NEW_REQL_OBJ;
  ReQL_Kwargs_t *data = (ReQL_Kwargs_t *)reql->data;
  ReQL_t *args = data->args;
  ReQL_Obj_t *r_args = NULL;
  if (args != NULL) {
    r_args = REQL_BUILD(args);
  }
  ReQL_t *kwargs = data->kwargs;
  ReQL_Obj_t *r_kwargs = NULL;
  if (kwargs != NULL) {
    r_kwargs = REQL_BUILD(kwargs);
  }
  data->func(obj, r_args, r_kwargs);
  return obj;
}

static void
reql_term_kwargs_destroy(ReQL_t *reql) {
}

static ReQL_t *
reql_term_kwargs(ReQL_AST_Function_Kwargs func, ReQL_t **args, ReQL_t **kwargs) {
  NEW_REQL;
  ReQL_Kwargs_t *data = malloc(sizeof(ReQL_Kwargs_t));
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
  data->func = func;
  reql->data = data;
  reql->free = reql_term_kwargs_destroy;
  reql->cb = reql_term_kwargs_;
  return reql;
}

extern ReQL_t *
reql_add(ReQL_t **args) {
  return reql_term(reql_ast_add, args);
}

extern ReQL_t *
reql_and(ReQL_t **args) {
  return reql_term(reql_ast_and, args);
}

extern ReQL_t *
reql_append(ReQL_t **args) {
  return reql_term(reql_ast_append, args);
}

extern ReQL_t *
reql_april(ReQL_t **args) {
  return reql_term(reql_ast_april, args);
}

extern ReQL_t *
reql_args(ReQL_t **args) {
  return reql_term(reql_ast_args, args);
}

extern ReQL_t *
reql_asc(ReQL_t **args) {
  return reql_term(reql_ast_asc, args);
}

extern ReQL_t *
reql_august(ReQL_t **args) {
  return reql_term(reql_ast_august, args);
}

extern ReQL_t *
reql_avg(ReQL_t **args) {
  return reql_term(reql_ast_avg, args);
}

extern ReQL_t *
reql_between(ReQL_t **args) {
  return reql_term(reql_ast_between, args);
}

extern ReQL_t *
reql_between_deprecated(ReQL_t **args) {
  return reql_term(reql_ast_between_deprecated, args);
}

extern ReQL_t *
reql_binary(ReQL_t **args) {
  return reql_term(reql_ast_binary, args);
}

extern ReQL_t *
reql_bracket(ReQL_t **args) {
  return reql_term(reql_ast_bracket, args);
}

extern ReQL_t *
reql_branch(ReQL_t **args) {
  return reql_term(reql_ast_branch, args);
}

extern ReQL_t *
reql_ceil(ReQL_t **args) {
  return reql_term(reql_ast_ceil, args);
}

extern ReQL_t *
reql_changes(ReQL_t **args) {
  return reql_term(reql_ast_changes, args);
}

extern ReQL_t *
reql_change_at(ReQL_t **args) {
  return reql_term(reql_ast_change_at, args);
}

extern ReQL_t *
reql_circle(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_circle, args, kwargs);
}

extern ReQL_t *
reql_coerce_to(ReQL_t **args) {
  return reql_term(reql_ast_coerce_to, args);
}

extern ReQL_t *
reql_concat_map(ReQL_t **args) {
  return reql_term(reql_ast_concat_map, args);
}

extern ReQL_t *
reql_config(ReQL_t **args) {
  return reql_term(reql_ast_config, args);
}

extern ReQL_t *
reql_contains(ReQL_t **args) {
  return reql_term(reql_ast_contains, args);
}

extern ReQL_t *
reql_count(ReQL_t **args) {
  return reql_term(reql_ast_count, args);
}

extern ReQL_t *
reql_date(ReQL_t **args) {
  return reql_term(reql_ast_date, args);
}

extern ReQL_t *
reql_datum(ReQL_t **args) {
  return reql_term(reql_ast_datum, args);
}

extern ReQL_t *
reql_day(ReQL_t **args) {
  return reql_term(reql_ast_day, args);
}

extern ReQL_t *
reql_day_of_week(ReQL_t **args) {
  return reql_term(reql_ast_day_of_week, args);
}

extern ReQL_t *
reql_day_of_year(ReQL_t **args) {
  return reql_term(reql_ast_day_of_year, args);
}

extern ReQL_t *
reql_db(ReQL_t **args) {
  return reql_term(reql_ast_db, args);
}

extern ReQL_t *
reql_db_create(ReQL_t **args) {
  return reql_term(reql_ast_db_create, args);
}

extern ReQL_t *
reql_db_drop(ReQL_t **args) {
  return reql_term(reql_ast_db_drop, args);
}

extern ReQL_t *
reql_db_list(ReQL_t **args) {
  return reql_term(reql_ast_db_list, args);
}

extern ReQL_t *
reql_december(ReQL_t **args) {
  return reql_term(reql_ast_december, args);
}

extern ReQL_t *
reql_default(ReQL_t **args) {
  return reql_term(reql_ast_default, args);
}

extern ReQL_t *
reql_delete(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_delete, args, kwargs);
}

extern ReQL_t *
reql_delete_at(ReQL_t **args) {
  return reql_term(reql_ast_delete_at, args);
}

extern ReQL_t *
reql_desc(ReQL_t **args) {
  return reql_term(reql_ast_desc, args);
}

extern ReQL_t *
reql_difference(ReQL_t **args) {
  return reql_term(reql_ast_difference, args);
}

extern ReQL_t *
reql_distance(ReQL_t **args) {
  return reql_term(reql_ast_distance, args);
}

extern ReQL_t *
reql_distinct(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_distinct, args, kwargs);
}

extern ReQL_t *
reql_div(ReQL_t **args) {
  return reql_term(reql_ast_div, args);
}

extern ReQL_t *
reql_downcase(ReQL_t **args) {
  return reql_term(reql_ast_downcase, args);
}

extern ReQL_t *
reql_during(ReQL_t **args) {
  return reql_term(reql_ast_during, args);
}

extern ReQL_t *
reql_epoch_time(ReQL_t **args) {
  return reql_term(reql_ast_epoch_time, args);
}

extern ReQL_t *
reql_eq(ReQL_t **args) {
  return reql_term(reql_ast_eq, args);
}

extern ReQL_t *
reql_eq_join(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_eq_join, args, kwargs);
}

extern ReQL_t *
reql_error(ReQL_t **args) {
  return reql_term(reql_ast_error, args);
}

extern ReQL_t *
reql_february(ReQL_t **args) {
  return reql_term(reql_ast_february, args);
}

extern ReQL_t *
reql_fill(ReQL_t **args) {
  return reql_term(reql_ast_fill, args);
}

extern ReQL_t *
reql_filter(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_filter, args, kwargs);
}

extern ReQL_t *
reql_floor(ReQL_t **args) {
  return reql_term(reql_ast_floor, args);
}

extern ReQL_t *
reql_for_each(ReQL_t **args) {
  return reql_term(reql_ast_for_each, args);
}

extern ReQL_t *
reql_friday(ReQL_t **args) {
  return reql_term(reql_ast_friday, args);
}

extern ReQL_t *
reql_func(ReQL_t **args) {
  return reql_term(reql_ast_func, args);
}

extern ReQL_t *
reql_funcall(ReQL_t **args) {
  return reql_term(reql_ast_funcall, args);
}

extern ReQL_t *
reql_ge(ReQL_t **args) {
  return reql_term(reql_ast_ge, args);
}

extern ReQL_t *
reql_geojson(ReQL_t **args) {
  return reql_term(reql_ast_geojson, args);
}

extern ReQL_t *
reql_get(ReQL_t **args) {
  return reql_term(reql_ast_get, args);
}

extern ReQL_t *
reql_get_all(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_get_all, args, kwargs);
}

extern ReQL_t *
reql_get_field(ReQL_t **args) {
  return reql_term(reql_ast_get_field, args);
}

extern ReQL_t *
reql_get_intersecting(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_get_intersecting, args, kwargs);
}

extern ReQL_t *
reql_get_nearest(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_get_nearest, args, kwargs);
}

extern ReQL_t *
reql_group(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_group, args, kwargs);
}

extern ReQL_t *
reql_gt(ReQL_t **args) {
  return reql_term(reql_ast_gt, args);
}

extern ReQL_t *
reql_has_fields(ReQL_t **args) {
  return reql_term(reql_ast_has_fields, args);
}

extern ReQL_t *
reql_hours(ReQL_t **args) {
  return reql_term(reql_ast_hours, args);
}

extern ReQL_t *
reql_http(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_http, args, kwargs);
}

extern ReQL_t *
reql_implicit_var(ReQL_t **args) {
  return reql_term(reql_ast_implicit_var, args);
}

extern ReQL_t *
reql_includes(ReQL_t **args) {
  return reql_term(reql_ast_includes, args);
}

extern ReQL_t *
reql_index_create(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_index_create, args, kwargs);
}

extern ReQL_t *
reql_index_drop(ReQL_t **args) {
  return reql_term(reql_ast_index_drop, args);
}

extern ReQL_t *
reql_index_list(ReQL_t **args) {
  return reql_term(reql_ast_index_list, args);
}

extern ReQL_t *
reql_index_rename(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_index_rename, args, kwargs);
}

extern ReQL_t *
reql_index_status(ReQL_t **args) {
  return reql_term(reql_ast_index_status, args);
}

extern ReQL_t *
reql_index_wait(ReQL_t **args) {
  return reql_term(reql_ast_index_wait, args);
}

extern ReQL_t *
reql_info(ReQL_t **args) {
  return reql_term(reql_ast_info, args);
}

extern ReQL_t *
reql_inner_join(ReQL_t **args) {
  return reql_term(reql_ast_inner_join, args);
}

extern ReQL_t *
reql_insert(ReQL_t **args) {
  return reql_term(reql_ast_insert, args);
}

extern ReQL_t *
reql_insert_at(ReQL_t **args) {
  return reql_term(reql_ast_insert_at, args);
}

extern ReQL_t *
reql_intersects(ReQL_t **args) {
  return reql_term(reql_ast_intersects, args);
}

extern ReQL_t *
reql_in_timezone(ReQL_t **args) {
  return reql_term(reql_ast_in_timezone, args);
}

extern ReQL_t *
reql_iso8601(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_iso8601, args, kwargs);
}

extern ReQL_t *
reql_is_empty(ReQL_t **args) {
  return reql_term(reql_ast_is_empty, args);
}

extern ReQL_t *
reql_january(ReQL_t **args) {
  return reql_term(reql_ast_january, args);
}

extern ReQL_t *
reql_javascript(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_javascript, args, kwargs);
}

extern ReQL_t *
reql_json(ReQL_t **args) {
  return reql_term(reql_ast_json, args);
}

extern ReQL_t *
reql_july(ReQL_t **args) {
  return reql_term(reql_ast_july, args);
}

extern ReQL_t *
reql_june(ReQL_t **args) {
  return reql_term(reql_ast_june, args);
}

extern ReQL_t *
reql_keys(ReQL_t **args) {
  return reql_term(reql_ast_keys, args);
}

extern ReQL_t *
reql_le(ReQL_t **args) {
  return reql_term(reql_ast_le, args);
}

extern ReQL_t *
reql_limit(ReQL_t **args) {
  return reql_term(reql_ast_limit, args);
}

extern ReQL_t *
reql_line(ReQL_t **args) {
  return reql_term(reql_ast_line, args);
}

extern ReQL_t *
reql_literal(ReQL_t **args) {
  return reql_term(reql_ast_literal, args);
}

extern ReQL_t *
reql_lt(ReQL_t **args) {
  return reql_term(reql_ast_lt, args);
}

extern ReQL_t *
reql_make_array(ReQL_t **args) {
  return reql_term(reql_ast_make_array, args);
}

extern ReQL_t *
reql_make_obj(ReQL_t **args) {
  return reql_term(reql_ast_make_obj, args);
}

extern ReQL_t *
reql_map(ReQL_t **args) {
  return reql_term(reql_ast_map, args);
}

extern ReQL_t *
reql_march(ReQL_t **args) {
  return reql_term(reql_ast_march, args);
}

extern ReQL_t *
reql_match(ReQL_t **args) {
  return reql_term(reql_ast_match, args);
}

extern ReQL_t *
reql_max(ReQL_t **args) {
  return reql_term(reql_ast_max, args);
}

extern ReQL_t *
reql_maxval(ReQL_t **args) {
  return reql_term(reql_ast_maxval, args);
}

extern ReQL_t *
reql_may(ReQL_t **args) {
  return reql_term(reql_ast_may, args);
}

extern ReQL_t *
reql_merge(ReQL_t **args) {
  return reql_term(reql_ast_merge, args);
}

extern ReQL_t *
reql_min(ReQL_t **args) {
  return reql_term(reql_ast_min, args);
}

extern ReQL_t *
reql_minutes(ReQL_t **args) {
  return reql_term(reql_ast_minutes, args);
}

extern ReQL_t *
reql_minval(ReQL_t **args) {
  return reql_term(reql_ast_minval, args);
}

extern ReQL_t *
reql_mod(ReQL_t **args) {
  return reql_term(reql_ast_mod, args);
}

extern ReQL_t *
reql_monday(ReQL_t **args) {
  return reql_term(reql_ast_monday, args);
}

extern ReQL_t *
reql_month(ReQL_t **args) {
  return reql_term(reql_ast_month, args);
}

extern ReQL_t *
reql_mul(ReQL_t **args) {
  return reql_term(reql_ast_mul, args);
}

extern ReQL_t *
reql_ne(ReQL_t **args) {
  return reql_term(reql_ast_ne, args);
}

extern ReQL_t *
reql_not(ReQL_t **args) {
  return reql_term(reql_ast_not, args);
}

extern ReQL_t *
reql_november(ReQL_t **args) {
  return reql_term(reql_ast_november, args);
}

extern ReQL_t *
reql_now(ReQL_t **args) {
  return reql_term(reql_ast_now, args);
}

extern ReQL_t *
reql_nth(ReQL_t **args) {
  return reql_term(reql_ast_nth, args);
}

extern ReQL_t *
reql_object(ReQL_t **args) {
  return reql_term(reql_ast_object, args);
}

extern ReQL_t *
reql_october(ReQL_t **args) {
  return reql_term(reql_ast_october, args);
}

extern ReQL_t *
reql_offsets_of(ReQL_t **args) {
  return reql_term(reql_ast_offsets_of, args);
}

extern ReQL_t *
reql_or(ReQL_t **args) {
  return reql_term(reql_ast_or, args);
}

extern ReQL_t *
reql_order_by(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_order_by, args, kwargs);
}

extern ReQL_t *
reql_outer_join(ReQL_t **args) {
  return reql_term(reql_ast_outer_join, args);
}

extern ReQL_t *
reql_pluck(ReQL_t **args) {
  return reql_term(reql_ast_pluck, args);
}

extern ReQL_t *
reql_point(ReQL_t **args) {
  return reql_term(reql_ast_point, args);
}

extern ReQL_t *
reql_polygon(ReQL_t **args) {
  return reql_term(reql_ast_polygon, args);
}

extern ReQL_t *
reql_polygon_sub(ReQL_t **args) {
  return reql_term(reql_ast_polygon_sub, args);
}

extern ReQL_t *
reql_prepend(ReQL_t **args) {
  return reql_term(reql_ast_prepend, args);
}

extern ReQL_t *
reql_random(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_random, args, kwargs);
}

extern ReQL_t *
reql_range(ReQL_t **args) {
  return reql_term(reql_ast_range, args);
}

extern ReQL_t *
reql_rebalance(ReQL_t **args) {
  return reql_term(reql_ast_rebalance, args);
}

extern ReQL_t *
reql_reconfigure(ReQL_t **args) {
  return reql_term(reql_ast_reconfigure, args);
}

extern ReQL_t *
reql_reduce(ReQL_t **args) {
  return reql_term(reql_ast_reduce, args);
}

extern ReQL_t *
reql_replace(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_replace, args, kwargs);
}

extern ReQL_t *
reql_round(ReQL_t **args) {
  return reql_term(reql_ast_round, args);
}

extern ReQL_t *
reql_sample(ReQL_t **args) {
  return reql_term(reql_ast_sample, args);
}

extern ReQL_t *
reql_saturday(ReQL_t **args) {
  return reql_term(reql_ast_saturday, args);
}

extern ReQL_t *
reql_seconds(ReQL_t **args) {
  return reql_term(reql_ast_seconds, args);
}

extern ReQL_t *
reql_september(ReQL_t **args) {
  return reql_term(reql_ast_september, args);
}

extern ReQL_t *
reql_set_difference(ReQL_t **args) {
  return reql_term(reql_ast_set_difference, args);
}

extern ReQL_t *
reql_set_insert(ReQL_t **args) {
  return reql_term(reql_ast_set_insert, args);
}

extern ReQL_t *
reql_set_intersection(ReQL_t **args) {
  return reql_term(reql_ast_set_intersection, args);
}

extern ReQL_t *
reql_set_union(ReQL_t **args) {
  return reql_term(reql_ast_set_union, args);
}

extern ReQL_t *
reql_skip(ReQL_t **args) {
  return reql_term(reql_ast_skip, args);
}

extern ReQL_t *
reql_slice(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_slice, args, kwargs);
}

extern ReQL_t *
reql_splice_at(ReQL_t **args) {
  return reql_term(reql_ast_splice_at, args);
}

extern ReQL_t *
reql_split(ReQL_t **args) {
  return reql_term(reql_ast_split, args);
}

extern ReQL_t *
reql_status(ReQL_t **args) {
  return reql_term(reql_ast_status, args);
}

extern ReQL_t *
reql_sub(ReQL_t **args) {
  return reql_term(reql_ast_sub, args);
}

extern ReQL_t *
reql_sum(ReQL_t **args) {
  return reql_term(reql_ast_sum, args);
}

extern ReQL_t *
reql_sunday(ReQL_t **args) {
  return reql_term(reql_ast_sunday, args);
}

extern ReQL_t *
reql_sync(ReQL_t **args) {
  return reql_term(reql_ast_sync, args);
}

extern ReQL_t *
reql_table(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_table, args, kwargs);
}

extern ReQL_t *
reql_table_create(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_table_create, args, kwargs);
}

extern ReQL_t *
reql_table_drop(ReQL_t **args) {
  return reql_term(reql_ast_table_drop, args);
}

extern ReQL_t *
reql_table_list(ReQL_t **args) {
  return reql_term(reql_ast_table_list, args);
}

extern ReQL_t *
reql_thursday(ReQL_t **args) {
  return reql_term(reql_ast_thursday, args);
}

extern ReQL_t *
reql_time(ReQL_t **args) {
  return reql_term(reql_ast_time, args);
}

extern ReQL_t *
reql_timezone(ReQL_t **args) {
  return reql_term(reql_ast_timezone, args);
}

extern ReQL_t *
reql_time_of_day(ReQL_t **args) {
  return reql_term(reql_ast_time_of_day, args);
}

extern ReQL_t *
reql_to_epoch_time(ReQL_t **args) {
  return reql_term(reql_ast_to_epoch_time, args);
}

extern ReQL_t *
reql_to_geojson(ReQL_t **args) {
  return reql_term(reql_ast_to_geojson, args);
}

extern ReQL_t *
reql_to_iso8601(ReQL_t **args) {
  return reql_term(reql_ast_to_iso8601, args);
}

extern ReQL_t *
reql_to_json_string(ReQL_t **args) {
  return reql_term(reql_ast_to_json_string, args);
}

extern ReQL_t *
reql_tuesday(ReQL_t **args) {
  return reql_term(reql_ast_tuesday, args);
}

extern ReQL_t *
reql_type_of(ReQL_t **args) {
  return reql_term(reql_ast_type_of, args);
}

extern ReQL_t *
reql_ungroup(ReQL_t **args) {
  return reql_term(reql_ast_ungroup, args);
}

extern ReQL_t *
reql_union(ReQL_t **args) {
  return reql_term(reql_ast_union, args);
}

extern ReQL_t *
reql_upcase(ReQL_t **args) {
  return reql_term(reql_ast_upcase, args);
}

extern ReQL_t *
reql_update(ReQL_t **args, ReQL_t **kwargs) {
  return reql_term_kwargs(reql_ast_update, args, kwargs);
}

extern ReQL_t *
reql_uuid(ReQL_t **args) {
  return reql_term(reql_ast_uuid, args);
}

extern ReQL_t *
reql_var(ReQL_t **args) {
  return reql_term(reql_ast_var, args);
}

extern ReQL_t *
reql_wait(ReQL_t **args) {
  return reql_term(reql_ast_wait, args);
}

extern ReQL_t *
reql_wednesday(ReQL_t **args) {
  return reql_term(reql_ast_wednesday, args);
}

extern ReQL_t *
reql_without(ReQL_t **args) {
  return reql_term(reql_ast_without, args);
}

extern ReQL_t *
reql_with_fields(ReQL_t **args) {
  return reql_term(reql_ast_with_fields, args);
}

extern ReQL_t *
reql_year(ReQL_t **args) {
  return reql_term(reql_ast_year, args);
}

extern ReQL_t *
reql_zip(ReQL_t **args) {
  return reql_term(reql_ast_zip, args);
}
