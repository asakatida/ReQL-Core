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

#include "./reql/ast.h"

#include "./reql/expr.h"

#include <stdlib.h>

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
