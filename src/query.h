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

#ifndef REQL_C_QUERY_H_
#define REQL_C_QUERY_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "./connection.h"
#include "./cursor.h"

typedef struct ReQL_s ReQL_t;

typedef ReQL_t *(*ReQL_Function)(ReQL_t **args, const unsigned int nargs);

extern ReQL_t *
reql_array(ReQL_t **val);

extern ReQL_t *
reql_bool(const int val);

extern ReQL_t *
reql_c_string(const char *val);

extern int
_reql_release(ReQL_t *reql);

#define reql_release(val) if (_reql_release(val) != 0) { (val) = NULL; }

extern void
reql_retain(ReQL_t *reql);

extern ReQL_t *
reql_function(ReQL_Function val, const unsigned int nargs);

extern ReQL_t *
reql_json_object(ReQL_t **val);

extern ReQL_t *
reql_null(void);

extern ReQL_t *
reql_number(const double val);

extern ReQL_t *
reql_string(const char *val, const unsigned long size);

extern ReQL_Cursor_t *
reql_run(ReQL_t *query, ReQL_t *kwargs, ReQL_Connection_t *conn);

extern int
reql_noreply(ReQL_t *query, ReQL_t *kwargs, ReQL_Connection_t *conn);

/**
 */
extern ReQL_t *
reql_add(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_and(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_append(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_april(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_args(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_asc(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_august(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_avg(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_between(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_between_deprecated(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_binary(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_bracket(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_branch(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_ceil(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_changes(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_change_at(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_circle(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_coerce_to(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_concat_map(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_config(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_contains(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_count(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_date(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_datum(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_day(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_day_of_week(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_day_of_year(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_db(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_db_create(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_db_drop(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_db_list(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_december(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_default(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_delete(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_delete_at(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_desc(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_difference(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_distance(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_distinct(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_div(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_downcase(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_during(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_epoch_time(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_eq(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_eq_join(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_error(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_february(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_fill(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_filter(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_floor(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_for_each(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_friday(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_func(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_funcall(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_ge(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_geojson(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_get(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_get_all(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_get_field(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_get_intersecting(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_get_nearest(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_group(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_gt(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_has_fields(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_hours(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_http(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_implicit_var(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_includes(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_index_create(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_index_drop(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_index_list(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_index_rename(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_index_status(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_index_wait(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_info(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_inner_join(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_insert(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_insert_at(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_intersects(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_in_timezone(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_iso8601(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_is_empty(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_january(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_javascript(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_json(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_july(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_june(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_keys(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_le(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_limit(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_line(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_literal(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_lt(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_make_array(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_make_obj(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_map(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_march(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_match(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_max(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_maxval(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_may(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_merge(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_min(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_minutes(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_minval(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_mod(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_monday(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_month(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_mul(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_ne(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_not(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_november(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_now(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_nth(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_object(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_october(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_offsets_of(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_or(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_order_by(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_outer_join(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_pluck(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_point(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_polygon(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_polygon_sub(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_prepend(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_random(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_range(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_rebalance(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_reconfigure(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_reduce(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_replace(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_round(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_sample(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_saturday(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_seconds(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_september(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_set_difference(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_set_insert(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_set_intersection(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_set_union(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_skip(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_slice(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_splice_at(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_split(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_status(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_sub(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_sum(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_sunday(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_sync(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_table(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_table_create(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_table_drop(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_table_list(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_thursday(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_time(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_timezone(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_time_of_day(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_to_epoch_time(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_to_geojson(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_to_iso8601(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_to_json_string(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_tuesday(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_type_of(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_ungroup(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_union(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_upcase(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_update(ReQL_t **args, ReQL_t **kwargs);

/**
 */
extern ReQL_t *
reql_uuid(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_values(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_var(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_wait(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_wednesday(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_without(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_with_fields(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_year(ReQL_t **args);

/**
 */
extern ReQL_t *
reql_zip(ReQL_t **args);

#ifdef __cplusplus
}
#endif

#endif  // REQL_C_QUERY_H_
