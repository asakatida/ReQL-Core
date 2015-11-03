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

#include "./reql/query.hpp"

#include "./reql/error.hpp"
#include "./reql/types.hpp"

extern ReQL_Term_t
reql_term_type(const ReQL_ReQL_t *obj) {
  return obj->tt;
}

static auto
reql_term_args(const ReQL_ReQL_t &obj) {
  return obj.args(obj.data);
}

static auto
reql_term_kwargs(const ReQL_ReQL_t &obj) {
  return obj.kwargs(obj.data);
}

extern ReQL_Datum_t
reql_datum_type(const ReQL_Any_t *obj) {
  return obj->dt;
}

template <class T>
static auto
reql_size_(const T &obj) {
  return obj.size(obj.data);
}

extern ReQL_Size
reql_size(const ReQL_String_t *obj) {
  return reql_size_(*obj);
}

static void
reql_term_init(ReQL_ReQL_t &obj,
               const ReQL_Term_t tt,
               ReQL_Array_t (*args)(void *),
               ReQL_Obj_t (*kwargs)(void *),
               void *data) {
  obj.tt = tt;
  obj.args = args;
  obj.kwargs = kwargs;
  obj.data = data;
}

extern void
reql_string_init(ReQL_String_t *obj,
                 ReQL_Byte *(*buffer)(void *),
                 ReQL_Size (*size)(void *),
                 void *data) {
  obj->buffer = buffer;
  obj->size = size;
  obj->data = data;
}

extern ReQL_Byte *
reql_string_buf(const ReQL_String_t *obj) {
  return obj->buffer(obj->data);
}

template <class iter, class val>
static val
reql_iter_next_(iter &obj) {
  if (reql_size_(*obj.obj) > obj.idx) {
    val next = obj.obj->get(obj.obj->data, obj.idx);
    ++obj.idx;

    if (next == nullptr) {
      return reql_iter_next_<iter, val>(obj);
    }

    return next;
  }
  return nullptr;
}

extern void
reql_array_iter_init(ReQL_Array_Iter_t *iter, const ReQL_Array_t *obj) {
  iter->idx = 0;
  iter->obj = obj;
}

extern ReQL_Any_t *
reql_array_iter_next(ReQL_Array_Iter_t *obj) {
  return reql_iter_next_<ReQL_Array_Iter_t, ReQL_Any_t *>(*obj);
}

extern void
reql_object_iter_init(ReQL_Object_Iter_t *iter, const ReQL_Obj_t *obj) {
  iter->idx = 0;
  iter->obj = obj;
}

extern ReQL_Pair_t *
reql_object_iter_next(ReQL_Object_Iter_t *obj) {
  return reql_iter_next_<ReQL_Object_Iter_t, ReQL_Pair_t *>(*obj);
}

extern void
reql_array_init(ReQL_Array_t *obj,
                ReQL_Any_t *(*get)(void *, ReQL_Size),
                ReQL_Size (*size)(void *),
                void *data) {
  obj->get = get;
  obj->size = size;
  obj->data = data;
}

extern void
reql_object_init(ReQL_Obj_t *obj,
                 ReQL_Pair_t *(*get)(void *, ReQL_Size),
                 ReQL_Size (*size)(void *),
                 void *data) {
  obj->get = get;
  obj->size = size;
  obj->data = data;
}

extern void
reql_ast_add(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_ADD, a, nullptr, d);
}

extern void
reql_ast_and(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_AND, a, nullptr, d);
}

extern void
reql_ast_append(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_APPEND, a, nullptr, d);
}

extern void
reql_ast_april(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_APRIL, a, nullptr, d);
}

extern void
reql_ast_args(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_ARGS, a, nullptr, d);
}

extern void
reql_ast_asc(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_ASC, a, nullptr, d);
}

extern void
reql_ast_august(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_AUGUST, a, nullptr, d);
}

extern void
reql_ast_avg(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_AVG, a, nullptr, d);
}

extern void
reql_ast_between(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_BETWEEN, a, nullptr, d);
}

extern void
reql_ast_between_deprecated(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_BETWEEN_DEPRECATED, a, nullptr, d);
}

extern void
reql_ast_binary(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_BINARY, a, nullptr, d);
}

extern void
reql_ast_bracket(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_BRACKET, a, nullptr, d);
}

extern void
reql_ast_branch(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_BRANCH, a, nullptr, d);
}

extern void
reql_ast_ceil(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_CEIL, a, nullptr, d);
}

extern void
reql_ast_changes(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_CHANGES, a, nullptr, d);
}

extern void
reql_ast_change_at(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_CHANGE_AT, a, nullptr, d);
}

extern void
reql_ast_circle(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_CIRCLE, a, k, d);
}

extern void
reql_ast_coerce_to(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_COERCE_TO, a, nullptr, d);
}

extern void
reql_ast_concat_map(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_CONCAT_MAP, a, nullptr, d);
}

extern void
reql_ast_config(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_CONFIG, a, nullptr, d);
}

extern void
reql_ast_contains(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_CONTAINS, a, nullptr, d);
}

extern void
reql_ast_count(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_COUNT, a, nullptr, d);
}

extern void
reql_ast_date(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DATE, a, nullptr, d);
}

extern void
reql_ast_datum(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DATUM, a, nullptr, d);
}

extern void
reql_ast_day(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DAY, a, nullptr, d);
}

extern void
reql_ast_day_of_week(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DAY_OF_WEEK, a, nullptr, d);
}

extern void
reql_ast_day_of_year(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DAY_OF_YEAR, a, nullptr, d);
}

extern void
reql_ast_db(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DB, a, nullptr, d);
}

extern void
reql_ast_db_create(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DB_CREATE, a, nullptr, d);
}

extern void
reql_ast_db_drop(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DB_DROP, a, nullptr, d);
}

extern void
reql_ast_db_list(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DB_LIST, a, nullptr, d);
}

extern void
reql_ast_december(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DECEMBER, a, nullptr, d);
}

extern void
reql_ast_default(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DEFAULT, a, nullptr, d);
}

extern void
reql_ast_delete(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_DELETE, a, k, d);
}

extern void
reql_ast_delete_at(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DELETE_AT, a, nullptr, d);
}

extern void
reql_ast_desc(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DESC, a, nullptr, d);
}

extern void
reql_ast_difference(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DIFFERENCE, a, nullptr, d);
}

extern void
reql_ast_distance(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DISTANCE, a, nullptr, d);
}

extern void
reql_ast_distinct(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_DISTINCT, a, k, d);
}

extern void
reql_ast_div(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DIV, a, nullptr, d);
}

extern void
reql_ast_downcase(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DOWNCASE, a, nullptr, d);
}

extern void
reql_ast_during(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_DURING, a, nullptr, d);
}

extern void
reql_ast_epoch_time(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_EPOCH_TIME, a, nullptr, d);
}

extern void
reql_ast_eq(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_EQ, a, nullptr, d);
}

extern void
reql_ast_eq_join(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_EQ_JOIN, a, k, d);
}

extern void
reql_ast_error(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_ERROR, a, nullptr, d);
}

extern void
reql_ast_february(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_FEBRUARY, a, nullptr, d);
}

extern void
reql_ast_fill(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_FILL, a, nullptr, d);
}

extern void
reql_ast_filter(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_FILTER, a, k, d);
}

extern void
reql_ast_floor(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_FLOOR, a, nullptr, d);
}

extern void
reql_ast_for_each(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_FOR_EACH, a, nullptr, d);
}

extern void
reql_ast_friday(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_FRIDAY, a, nullptr, d);
}

extern void
reql_ast_func(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_FUNC, a, nullptr, d);
}

extern void
reql_ast_funcall(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_FUNCALL, a, nullptr, d);
}

extern void
reql_ast_ge(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_GE, a, nullptr, d);
}

extern void
reql_ast_geojson(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_GEOJSON, a, nullptr, d);
}

extern void
reql_ast_get(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_GET, a, nullptr, d);
}

extern void
reql_ast_get_all(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_GET_ALL, a, k, d);
}

extern void
reql_ast_get_field(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_GET_FIELD, a, nullptr, d);
}

extern void
reql_ast_get_intersecting(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_GET_INTERSECTING, a, k, d);
}

extern void
reql_ast_get_nearest(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_GET_NEAREST, a, k, d);
}

extern void
reql_ast_group(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_GROUP, a, k, d);
}

extern void
reql_ast_gt(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_GT, a, nullptr, d);
}

extern void
reql_ast_has_fields(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_HAS_FIELDS, a, nullptr, d);
}

extern void
reql_ast_hours(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_HOURS, a, nullptr, d);
}

extern void
reql_ast_http(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_HTTP, a, k, d);
}

extern void
reql_ast_implicit_var(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_IMPLICIT_VAR, a, nullptr, d);
}

extern void
reql_ast_includes(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INCLUDES, a, nullptr, d);
}

extern void
reql_ast_index_create(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_INDEX_CREATE, a, k, d);
}

extern void
reql_ast_index_drop(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INDEX_DROP, a, nullptr, d);
}

extern void
reql_ast_index_list(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INDEX_LIST, a, nullptr, d);
}

extern void
reql_ast_index_rename(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_INDEX_RENAME, a, k, d);
}

extern void
reql_ast_index_status(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INDEX_STATUS, a, nullptr, d);
}

extern void
reql_ast_index_wait(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INDEX_WAIT, a, nullptr, d);
}

extern void
reql_ast_info(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INFO, a, nullptr, d);
}

extern void
reql_ast_inner_join(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INNER_JOIN, a, nullptr, d);
}

extern void
reql_ast_insert(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INSERT, a, nullptr, d);
}

extern void
reql_ast_insert_at(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INSERT_AT, a, nullptr, d);
}

extern void
reql_ast_intersects(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_INTERSECTS, a, nullptr, d);
}

extern void
reql_ast_in_timezone(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_IN_TIMEZONE, a, nullptr, d);
}

extern void
reql_ast_iso8601(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_ISO8601, a, k, d);
}

extern void
reql_ast_is_empty(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_IS_EMPTY, a, nullptr, d);
}

extern void
reql_ast_january(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_JANUARY, a, nullptr, d);
}

extern void
reql_ast_javascript(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_JAVASCRIPT, a, k, d);
}

extern void
reql_ast_json(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_JSON, a, nullptr, d);
}

extern void
reql_ast_july(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_JULY, a, nullptr, d);
}

extern void
reql_ast_june(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_JUNE, a, nullptr, d);
}

extern void
reql_ast_keys(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_KEYS, a, nullptr, d);
}

extern void
reql_ast_le(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_LE, a, nullptr, d);
}

extern void
reql_ast_limit(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_LIMIT, a, nullptr, d);
}

extern void
reql_ast_line(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_LINE, a, nullptr, d);
}

extern void
reql_ast_literal(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_LITERAL, a, nullptr, d);
}

extern void
reql_ast_lt(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_LT, a, nullptr, d);
}

extern void
reql_ast_make_array(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MAKE_ARRAY, a, nullptr, d);
}

extern void
reql_ast_make_obj(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MAKE_OBJ, a, nullptr, d);
}

extern void
reql_ast_map(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MAP, a, nullptr, d);
}

extern void
reql_ast_march(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MARCH, a, nullptr, d);
}

extern void
reql_ast_match(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MATCH, a, nullptr, d);
}

extern void
reql_ast_max(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MAX, a, nullptr, d);
}

extern void
reql_ast_maxval(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MAXVAL, a, nullptr, d);
}

extern void
reql_ast_may(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MAY, a, nullptr, d);
}

extern void
reql_ast_merge(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MERGE, a, nullptr, d);
}

extern void
reql_ast_min(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MIN, a, nullptr, d);
}

extern void
reql_ast_minutes(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MINUTES, a, nullptr, d);
}

extern void
reql_ast_minval(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MINVAL, a, nullptr, d);
}

extern void
reql_ast_mod(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MOD, a, nullptr, d);
}

extern void
reql_ast_monday(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MONDAY, a, nullptr, d);
}

extern void
reql_ast_month(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MONTH, a, nullptr, d);
}

extern void
reql_ast_mul(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_MUL, a, nullptr, d);
}

extern void
reql_ast_ne(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_NE, a, nullptr, d);
}

extern void
reql_ast_not(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_NOT, a, nullptr, d);
}

extern void
reql_ast_november(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_NOVEMBER, a, nullptr, d);
}

extern void
reql_ast_now(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_NOW, a, nullptr, d);
}

extern void
reql_ast_nth(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_NTH, a, nullptr, d);
}

extern void
reql_ast_object(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_OBJECT, a, nullptr, d);
}

extern void
reql_ast_october(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_OCTOBER, a, nullptr, d);
}

extern void
reql_ast_offsets_of(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_OFFSETS_OF, a, nullptr, d);
}

extern void
reql_ast_or(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_OR, a, nullptr, d);
}

extern void
reql_ast_order_by(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_ORDER_BY, a, k, d);
}

extern void
reql_ast_outer_join(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_OUTER_JOIN, a, nullptr, d);
}

extern void
reql_ast_pluck(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_PLUCK, a, nullptr, d);
}

extern void
reql_ast_point(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_POINT, a, nullptr, d);
}

extern void
reql_ast_polygon(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_POLYGON, a, nullptr, d);
}

extern void
reql_ast_polygon_sub(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_POLYGON_SUB, a, nullptr, d);
}

extern void
reql_ast_prepend(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_PREPEND, a, nullptr, d);
}

extern void
reql_ast_random(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_RANDOM, a, k, d);
}

extern void
reql_ast_range(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_RANGE, a, nullptr, d);
}

extern void
reql_ast_rebalance(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_REBALANCE, a, nullptr, d);
}

extern void
reql_ast_reconfigure(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_RECONFIGURE, a, nullptr, d);
}

extern void
reql_ast_reduce(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_REDUCE, a, nullptr, d);
}

extern void
reql_ast_replace(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_REPLACE, a, k, d);
}

extern void
reql_ast_round(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_ROUND, a, nullptr, d);
}

extern void
reql_ast_sample(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SAMPLE, a, nullptr, d);
}

extern void
reql_ast_saturday(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SATURDAY, a, nullptr, d);
}

extern void
reql_ast_seconds(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SECONDS, a, nullptr, d);
}

extern void
reql_ast_september(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SEPTEMBER, a, nullptr, d);
}

extern void
reql_ast_set_difference(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SET_DIFFERENCE, a, nullptr, d);
}

extern void
reql_ast_set_insert(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SET_INSERT, a, nullptr, d);
}

extern void
reql_ast_set_intersection(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SET_INTERSECTION, a, nullptr, d);
}

extern void
reql_ast_set_union(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SET_UNION, a, nullptr, d);
}

extern void
reql_ast_skip(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SKIP, a, nullptr, d);
}

extern void
reql_ast_slice(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_SLICE, a, k, d);
}

extern void
reql_ast_splice_at(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SPLICE_AT, a, nullptr, d);
}

extern void
reql_ast_split(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SPLIT, a, nullptr, d);
}

extern void
reql_ast_status(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_STATUS, a, nullptr, d);
}

extern void
reql_ast_sub(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SUB, a, nullptr, d);
}

extern void
reql_ast_sum(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SUM, a, nullptr, d);
}

extern void
reql_ast_sunday(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SUNDAY, a, nullptr, d);
}

extern void
reql_ast_sync(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_SYNC, a, nullptr, d);
}

extern void
reql_ast_table(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_TABLE, a, k, d);
}

extern void
reql_ast_table_create(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_TABLE_CREATE, a, k, d);
}

extern void
reql_ast_table_drop(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TABLE_DROP, a, nullptr, d);
}

extern void
reql_ast_table_list(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TABLE_LIST, a, nullptr, d);
}

extern void
reql_ast_thursday(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_THURSDAY, a, nullptr, d);
}

extern void
reql_ast_time(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TIME, a, nullptr, d);
}

extern void
reql_ast_timezone(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TIMEZONE, a, nullptr, d);
}

extern void
reql_ast_time_of_day(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TIME_OF_DAY, a, nullptr, d);
}

extern void
reql_ast_to_epoch_time(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TO_EPOCH_TIME, a, nullptr, d);
}

extern void
reql_ast_to_geojson(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TO_GEOJSON, a, nullptr, d);
}

extern void
reql_ast_to_iso8601(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TO_ISO8601, a, nullptr, d);
}

extern void
reql_ast_to_json_string(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TO_JSON_STRING, a, nullptr, d);
}

extern void
reql_ast_tuesday(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TUESDAY, a, nullptr, d);
}

extern void
reql_ast_type_of(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_TYPE_OF, a, nullptr, d);
}

extern void
reql_ast_ungroup(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_UNGROUP, a, nullptr, d);
}

extern void
reql_ast_union(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_UNION, a, nullptr, d);
}

extern void
reql_ast_upcase(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_UPCASE, a, nullptr, d);
}

extern void
reql_ast_update(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    ReQL_Obj_t (*k)(void *),
    void *d) {
  reql_term_init(*t, REQL_UPDATE, a, k, d);
}

extern void
reql_ast_uuid(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_UUID, a, nullptr, d);
}

extern void
reql_ast_values(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_VALUES, a, nullptr, d);
}

extern void
reql_ast_var(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_VAR, a, nullptr, d);
}

extern void
reql_ast_wait(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_WAIT, a, nullptr, d);
}

extern void
reql_ast_wednesday(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_WEDNESDAY, a, nullptr, d);
}

extern void
reql_ast_without(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_WITHOUT, a, nullptr, d);
}

extern void
reql_ast_with_fields(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_WITH_FIELDS, a, nullptr, d);
}

extern void
reql_ast_year(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_YEAR, a, nullptr, d);
}

extern void
reql_ast_zip(
    ReQL_ReQL_t *t,
    ReQL_Array_t (*a)(void *),
    void *d) {
  reql_term_init(*t, REQL_ZIP, a, nullptr, d);
}
