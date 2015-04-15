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

#include "./c/dev/ast.h"
#include "./c/dev/json.h"

#include <stdlib.h>

extern void
reql_ast_add(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_ADD);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_and(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_AND);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_append(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_APPEND);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_april(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_APRIL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_args(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_ARGS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_asc(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_ASC);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_august(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_AUGUST);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_avg(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_AVG);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_between(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_BETWEEN);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_between_deprecated(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_BETWEEN_DEPRECATED);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_binary(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_BINARY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_bracket(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_BRACKET);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_branch(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_BRANCH);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_ceil(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_CEIL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_changes(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_CHANGES);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_change_at(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_CHANGE_AT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_circle(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_CIRCLE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_coerce_to(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_COERCE_TO);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_concat_map(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_CONCAT_MAP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_config(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_CONFIG);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_contains(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_CONTAINS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_count(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_COUNT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_date(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DATE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_datum(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DATUM);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_day(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_day_of_week(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DAY_OF_WEEK);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_day_of_year(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DAY_OF_YEAR);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_db(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DB);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_db_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DB_CREATE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_db_drop(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DB_DROP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_db_list(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DB_LIST);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_december(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DECEMBER);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_default(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DEFAULT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_delete(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DELETE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_delete_at(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DELETE_AT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_desc(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DESC);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_difference(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DIFFERENCE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_distance(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DISTANCE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_distinct(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DISTINCT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_div(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DIV);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_downcase(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DOWNCASE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_during(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_DURING);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_EPOCH_TIME);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_eq(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_EQ);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_eq_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_EQ_JOIN);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_error(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_ERROR);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_february(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_FEBRUARY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_fill(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_FILL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_filter(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_FILTER);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_floor(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_FLOOR);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_for_each(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_FOR_EACH);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_friday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_FRIDAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_func(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_FUNC);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_funcall(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_FUNCALL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_ge(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GEOJSON);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_get(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GET);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_get_all(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GET_ALL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_get_field(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GET_FIELD);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_get_intersecting(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GET_INTERSECTING);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_get_nearest(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GET_NEAREST);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_group(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GROUP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_gt(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_GT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_has_fields(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_HAS_FIELDS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_hours(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_HOURS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_http(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_HTTP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_implicit_var(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_IMPLICIT_VAR);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_includes(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INCLUDES);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_index_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INDEX_CREATE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_index_drop(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INDEX_DROP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_index_list(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INDEX_LIST);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_index_rename(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INDEX_RENAME);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_index_status(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INDEX_STATUS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_index_wait(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INDEX_WAIT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_info(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INFO);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_inner_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INNER_JOIN);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_insert(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INSERT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_insert_at(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INSERT_AT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_intersects(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_INTERSECTS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_in_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_IN_TIMEZONE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_ISO8601);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_is_empty(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_IS_EMPTY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_january(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_JANUARY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_javascript(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_JAVASCRIPT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_json(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_JSON);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_july(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_JULY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_june(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_JUNE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_keys(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_KEYS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_le(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_LE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_limit(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_LIMIT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_line(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_LINE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_literal(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_LITERAL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_lt(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_LT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_make_array(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MAKE_ARRAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_make_obj(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MAKE_OBJ);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_map(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MAP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_march(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MARCH);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_match(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MATCH);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_max(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MAX);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_maxval(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MAXVAL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_may(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_merge(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MERGE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_min(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MIN);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_minutes(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MINUTES);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_minval(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MINVAL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_mod(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MOD);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_monday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MONDAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_month(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MONTH);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_mul(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_MUL);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_ne(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_NE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_not(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_NOT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_november(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_NOVEMBER);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_now(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_NOW);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_nth(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_NTH);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_object(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_OBJECT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_october(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_OCTOBER);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_offsets_of(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_OFFSETS_OF);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_or(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_OR);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_order_by(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_ORDER_BY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_outer_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_OUTER_JOIN);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_pluck(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_PLUCK);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_point(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_POINT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_polygon(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_POLYGON);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_polygon_sub(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_POLYGON_SUB);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_prepend(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_PREPEND);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_random(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_RANDOM);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_range(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_RANGE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_rebalance(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_REBALANCE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_reconfigure(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_RECONFIGURE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_reduce(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_REDUCE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_replace(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_REPLACE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_round(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_ROUND);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_sample(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SAMPLE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_saturday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SATURDAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_seconds(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SECONDS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_september(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SEPTEMBER);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_set_difference(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SET_DIFFERENCE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_set_insert(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SET_INSERT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_set_intersection(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SET_INTERSECTION);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_set_union(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SET_UNION);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_skip(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SKIP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_slice(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SLICE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_splice_at(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SPLICE_AT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_split(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SPLIT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_status(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_STATUS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_sub(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SUB);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_sum(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SUM);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_sunday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SUNDAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_sync(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_SYNC);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_table(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TABLE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_table_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TABLE_CREATE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_table_drop(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TABLE_DROP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_table_list(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TABLE_LIST);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_thursday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_THURSDAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_time(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TIME);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TIMEZONE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_time_of_day(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TIME_OF_DAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_to_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TO_EPOCH_TIME);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_to_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TO_GEOJSON);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_to_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TO_ISO8601);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_to_json_string(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TO_JSON_STRING);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_tuesday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TUESDAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_type_of(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_TYPE_OF);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_ungroup(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_UNGROUP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_union(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_UNION);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_upcase(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_UPCASE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_update(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_UPDATE);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_uuid(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_UUID);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_var(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_VAR);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_wait(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_WAIT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_wednesday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_WEDNESDAY);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_without(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_WITHOUT);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_with_fields(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_WITH_FIELDS);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_year(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_YEAR);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}

extern void
reql_ast_zip(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k) {
  reql_set_term_type(t, REQL_ZIP);
  reql_set_args(t, a);
  reql_set_kwargs(t, k);
}
