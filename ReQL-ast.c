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

#include "ReQL-ast.h"

#include <stdlib.h>

extern void
reql_ast_add(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ADD);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_all(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ALL);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_any(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ANY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_append(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_APPEND);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_april(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_APRIL);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_args(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ARGS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_asc(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ASC);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_august(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_AUGUST);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_avg(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_AVG);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_between(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_BETWEEN);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_binary(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_BINARY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_bracket(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_BRACKET);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_branch(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_BRANCH);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_changes(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_CHANGES);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_change_at(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_CHANGE_AT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_circle(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_CIRCLE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_coerce_to(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_COERCE_TO);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_concat_map(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_CONCAT_MAP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_config(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_CONFIG);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_contains(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_CONTAINS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_count(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_COUNT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_date(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DATE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_datum(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DATUM);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_day(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_day_of_week(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DAY_OF_WEEK);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_day_of_year(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DAY_OF_YEAR);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_db(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DB);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_db_create(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DB_CREATE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_db_drop(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DB_DROP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_db_list(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DB_LIST);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_december(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DECEMBER);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_default(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DEFAULT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_delete(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DELETE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_delete_at(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DELETE_AT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_desc(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DESC);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_difference(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DIFFERENCE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_distance(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DISTANCE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_distinct(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DISTINCT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_div(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DIV);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_downcase(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DOWNCASE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_during(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_DURING);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_epoch_time(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_EPOCH_TIME);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_eq(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_EQ);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_eq_join(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_EQ_JOIN);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_error(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ERROR);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_february(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_FEBRUARY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_fill(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_FILL);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_filter(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_FILTER);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_for_each(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_FOR_EACH);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_friday(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_FRIDAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_func(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_FUNC);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_funcall(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_FUNCALL);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_ge(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_geojson(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GEOJSON);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_get(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GET);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_get_all(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GET_ALL);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_get_field(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GET_FIELD);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_get_intersecting(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GET_INTERSECTING);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_get_nearest(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GET_NEAREST);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_group(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GROUP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_gt(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_GT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_has_fields(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_HAS_FIELDS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_hours(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_HOURS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_http(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_HTTP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_implicit_var(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_IMPLICIT_VAR);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_includes(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INCLUDES);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_indexes_of(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INDEXES_OF);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_index_create(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INDEX_CREATE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_index_drop(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INDEX_DROP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_index_list(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INDEX_LIST);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_index_rename(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INDEX_RENAME);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_index_status(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INDEX_STATUS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_index_wait(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INDEX_WAIT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_info(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INFO);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_inner_join(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INNER_JOIN);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_insert(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INSERT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_insert_at(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INSERT_AT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_intersects(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_INTERSECTS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_in_timezone(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_IN_TIMEZONE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_iso8601(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ISO8601);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_is_empty(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_IS_EMPTY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_january(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_JANUARY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_javascript(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_JAVASCRIPT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_json(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_JSON);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_july(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_JULY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_june(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_JUNE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_keys(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_KEYS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_le(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_LE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_limit(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_LIMIT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_line(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_LINE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_literal(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_LITERAL);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_lt(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_LT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_make_array(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MAKE_ARRAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_make_obj(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MAKE_OBJ);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_map(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MAP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_march(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MARCH);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_match(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MATCH);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_max(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MAX);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_may(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_merge(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MERGE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_min(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MIN);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_minutes(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MINUTES);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_mod(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MOD);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_monday(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MONDAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_month(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MONTH);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_mul(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_MUL);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_ne(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_NE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_not(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_NOT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_november(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_NOVEMBER);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_now(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_NOW);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_nth(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_NTH);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_object(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_OBJECT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_october(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_OCTOBER);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_order_by(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ORDER_BY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_outer_join(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_OUTER_JOIN);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_pluck(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_PLUCK);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_point(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_POINT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_polygon(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_POLYGON);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_polygon_sub(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_POLYGON_SUB);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_prepend(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_PREPEND);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_random(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_RANDOM);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_range(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_RANGE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_rebalance(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_REBALANCE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_reconfigure(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_RECONFIGURE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_reduce(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_REDUCE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_replace(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_REPLACE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_sample(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SAMPLE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_saturday(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SATURDAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_seconds(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SECONDS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_september(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SEPTEMBER);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_set_difference(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SET_DIFFERENCE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_set_insert(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SET_INSERT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_set_intersection(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SET_INTERSECTION);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_set_union(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SET_UNION);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_skip(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SKIP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_slice(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SLICE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_splice_at(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SPLICE_AT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_split(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SPLIT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_status(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_STATUS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_sub(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SUB);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_sum(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SUM);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_sunday(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SUNDAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_sync(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_SYNC);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_table(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TABLE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_table_create(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TABLE_CREATE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_table_drop(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TABLE_DROP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_table_list(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TABLE_LIST);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_thursday(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_THURSDAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_time(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TIME);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_timezone(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TIMEZONE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_time_of_day(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TIME_OF_DAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_to_epoch_time(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TO_EPOCH_TIME);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_to_geojson(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TO_GEOJSON);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_to_iso8601(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TO_ISO8601);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_to_json_string(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TO_JSON_STRING);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_tuesday(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TUESDAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_type_of(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_TYPE_OF);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_ungroup(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_UNGROUP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_union(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_UNION);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_upcase(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_UPCASE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_update(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_UPDATE);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_uuid(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_UUID);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_var(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_VAR);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_wait(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_WAIT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_wednesday(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_WEDNESDAY);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_without(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_WITHOUT);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_with_fields(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_WITH_FIELDS);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_year(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_YEAR);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}

extern void
reql_ast_zip(ReQL_Obj_t *term, ReQL_Obj_t *args, ReQL_Obj_t *kwargs) {
  reql_obj_set_term_type(term, REQL_ZIP);
  reql_obj_set_args(term, args);
  reql_obj_set_kwargs(term, kwargs);
}
