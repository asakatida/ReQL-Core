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

#ifndef REQL_AST_H_
#define REQL_AST_H_

#include "./c/json.h"

typedef void (*ReQL_AST_Function) (ReQL_Obj_t *, ReQL_Obj_t *, ReQL_Obj_t *);

/**
 */
extern void
reql_ast_add(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_and(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_append(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_april(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_args(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_asc(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_august(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_avg(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_between(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_between_deprecated(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_binary(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_bracket(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_branch(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_ceil(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_changes(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_change_at(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_circle(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_coerce_to(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_concat_map(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_config(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_contains(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_count(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_date(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_datum(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_day(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_day_of_week(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_day_of_year(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_db(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_db_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_db_drop(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_db_list(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_december(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_default(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_delete(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_delete_at(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_desc(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_difference(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_distance(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_distinct(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_div(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_downcase(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_during(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_eq(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_eq_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_error(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_february(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_fill(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_filter(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_floor(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_for_each(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_friday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_func(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_funcall(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_ge(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_get(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_get_all(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_get_field(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_get_intersecting(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_get_nearest(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_group(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_gt(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_has_fields(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_hours(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_http(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_implicit_var(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_includes(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_index_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_index_drop(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_index_list(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_index_rename(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_index_status(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_index_wait(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_info(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_inner_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_insert(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_insert_at(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_intersects(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_in_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_is_empty(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_january(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_javascript(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_json(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_july(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_june(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_keys(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_le(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_limit(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_line(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_literal(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_lt(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_make_array(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_make_obj(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_map(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_march(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_match(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_max(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_maxval(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_may(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_merge(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_min(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_minutes(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_minval(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_mod(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_monday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_month(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_mul(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_ne(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_not(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_november(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_now(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_nth(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_object(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_october(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_offsets_of(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_or(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_order_by(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_outer_join(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_pluck(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_point(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_polygon(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_polygon_sub(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_prepend(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_random(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_range(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_rebalance(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_reconfigure(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_reduce(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_replace(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_round(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_sample(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_saturday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_seconds(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_september(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_set_difference(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_set_insert(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_set_intersection(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_set_union(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_skip(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_slice(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_splice_at(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_split(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_status(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_sub(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_sum(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_sunday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_sync(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_table(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_table_create(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_table_drop(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_table_list(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_thursday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_time(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_timezone(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_time_of_day(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_to_epoch_time(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_to_geojson(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_to_iso8601(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_to_json_string(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_tuesday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_type_of(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_ungroup(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_union(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_upcase(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_update(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_uuid(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_var(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_wait(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_wednesday(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_without(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_with_fields(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_year(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

/**
 */
extern void
reql_ast_zip(ReQL_Obj_t *t, ReQL_Obj_t *a, ReQL_Obj_t *k);

#endif  // REQL_AST_H_
