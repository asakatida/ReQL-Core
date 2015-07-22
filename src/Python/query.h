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

#ifndef REQL_PYTHON_QUERY_H_
#define REQL_PYTHON_QUERY_H_

#ifdef __cplusplus
extern "C" {
#endif

#define Py_LIMITED_API
#include "Python.h"

#include "./Python/types.h"

extern void
Query_dealloc(ReQLQuery* self);

extern PyObject *
Query_new(PyTypeObject *type, PyObject *args, PyObject *kwargs);

extern int
Query_init(ReQLQuery *self, PyObject *args, PyObject *kwargs);

extern PyObject *
reql_py_run(PyObject *self, PyObject *args, PyObject *kwargs);

extern PyObject *
reql_py_expr(PyObject *self, PyObject *args);

/**
 */
extern PyObject *
reql_py_add(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_add_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_and(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_and_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_append(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_append_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_april(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_april_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_args(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_args_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_asc(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_asc_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_august(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_august_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_avg(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_avg_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_between(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_between_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_between_deprecated(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_between_deprecated_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_binary(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_binary_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_bracket(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_bracket_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_branch(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_branch_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_ceil(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_ceil_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_changes(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_changes_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_change_at(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_change_at_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_circle(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_circle_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_coerce_to(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_coerce_to_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_concat_map(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_concat_map_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_config(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_config_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_contains(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_contains_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_count(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_count_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_date(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_date_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_datum(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_datum_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_day(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_day_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_day_of_week(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_day_of_week_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_day_of_year(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_day_of_year_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_db(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_db_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_db_create(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_db_create_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_db_drop(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_db_drop_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_db_list(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_db_list_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_december(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_december_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_default(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_default_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_delete(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_delete_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_delete_at(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_delete_at_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_desc(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_desc_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_difference(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_difference_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_distance(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_distance_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_distinct(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_distinct_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_div(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_div_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_downcase(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_downcase_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_during(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_during_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_epoch_time(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_epoch_time_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_eq(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_eq_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_eq_join(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_eq_join_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_error(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_error_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_february(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_february_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_fill(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_fill_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_filter(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_filter_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_floor(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_floor_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_for_each(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_for_each_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_friday(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_friday_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_func(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_func_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_funcall(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_funcall_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_ge(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_ge_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_geojson(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_geojson_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_get(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_get_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_get_all(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_get_all_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_get_field(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_get_field_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_get_intersecting(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_get_intersecting_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_get_nearest(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_get_nearest_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_group(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_group_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_gt(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_gt_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_has_fields(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_has_fields_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_hours(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_hours_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_http(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_http_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_implicit_var(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_implicit_var_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_includes(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_includes_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_index_create(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_index_create_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_index_drop(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_index_drop_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_index_list(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_index_list_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_index_rename(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_index_rename_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_index_status(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_index_status_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_index_wait(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_index_wait_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_info(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_info_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_inner_join(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_inner_join_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_insert(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_insert_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_insert_at(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_insert_at_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_intersects(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_intersects_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_in_timezone(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_in_timezone_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_iso8601(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_iso8601_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_is_empty(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_is_empty_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_january(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_january_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_javascript(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_javascript_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_json(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_json_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_july(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_july_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_june(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_june_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_keys(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_keys_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_le(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_le_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_limit(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_limit_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_line(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_line_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_literal(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_literal_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_lt(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_lt_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_make_array(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_make_array_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_make_obj(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_make_obj_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_map(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_map_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_march(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_march_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_match(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_match_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_max(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_max_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_maxval(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_maxval_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_may(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_may_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_merge(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_merge_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_min(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_min_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_minutes(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_minutes_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_minval(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_minval_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_mod(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_mod_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_monday(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_monday_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_month(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_month_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_mul(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_mul_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_ne(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_ne_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_not(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_not_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_november(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_november_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_now(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_now_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_nth(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_nth_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_object(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_object_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_october(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_october_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_offsets_of(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_offsets_of_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_or(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_or_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_order_by(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_order_by_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_outer_join(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_outer_join_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_pluck(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_pluck_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_point(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_point_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_polygon(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_polygon_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_polygon_sub(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_polygon_sub_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_prepend(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_prepend_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_random(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_random_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_range(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_range_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_rebalance(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_rebalance_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_reconfigure(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_reconfigure_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_reduce(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_reduce_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_replace(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_replace_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_round(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_round_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_sample(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_sample_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_saturday(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_saturday_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_seconds(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_seconds_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_september(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_september_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_set_difference(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_set_difference_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_set_insert(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_set_insert_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_set_intersection(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_set_intersection_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_set_union(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_set_union_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_skip(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_skip_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_slice(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_slice_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_splice_at(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_splice_at_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_split(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_split_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_status(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_status_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_sub(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_sub_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_sum(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_sum_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_sunday(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_sunday_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_sync(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_sync_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_table(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_table_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_table_create(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_table_create_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_table_drop(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_table_drop_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_table_list(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_table_list_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_thursday(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_thursday_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_time(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_time_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_timezone(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_timezone_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_time_of_day(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_time_of_day_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_to_epoch_time(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_to_epoch_time_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_to_geojson(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_to_geojson_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_to_iso8601(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_to_iso8601_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_to_json_string(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_to_json_string_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_tuesday(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_tuesday_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_type_of(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_type_of_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_ungroup(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_ungroup_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_union(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_union_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_upcase(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_upcase_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_update(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_update_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_uuid(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_uuid_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_var(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_var_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_wait(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_wait_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_wednesday(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_wednesday_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_without(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_without_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_with_fields(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_with_fields_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_year(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_year_method(PyObject *self, PyObject *args, PyObject *kwargs);

/**
 */
extern PyObject *
reql_py_zip(PyObject *args, PyObject *kwargs);
extern PyObject *
reql_py_zip_method(PyObject *self, PyObject *args, PyObject *kwargs);

#ifdef __cplusplus
}
#endif

#endif  // REQL_PYTHON_QUERY_H_
