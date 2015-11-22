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

#ifndef REQL_LUA_QUERY_HPP_
#define REQL_LUA_QUERY_HPP_

#include "./reql/core.hpp"

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#if LUA_VERSION_NUM < 502
#define lua_rawlen lua_objlen
#endif

extern int
reql_lua_expr(lua_State *L);
extern int
reql_lua_is_instance(lua_State *L);

/**
 */
extern int
reql_lua_add(lua_State *L);

/**
 */
extern int
reql_lua_and(lua_State *L);

/**
 */
extern int
reql_lua_append(lua_State *L);

/**
 */
extern int
reql_lua_april(lua_State *L);

/**
 */
extern int
reql_lua_args(lua_State *L);

/**
 */
extern int
reql_lua_asc(lua_State *L);

/**
 */
extern int
reql_lua_august(lua_State *L);

/**
 */
extern int
reql_lua_avg(lua_State *L);

/**
 */
extern int
reql_lua_between(lua_State *L);

/**
 */
extern int
reql_lua_between_deprecated(lua_State *L);

/**
 */
extern int
reql_lua_binary(lua_State *L);

/**
 */
extern int
reql_lua_bracket(lua_State *L);

/**
 */
extern int
reql_lua_branch(lua_State *L);

/**
 */
extern int
reql_lua_ceil(lua_State *L);

/**
 */
extern int
reql_lua_changes(lua_State *L);

/**
 */
extern int
reql_lua_change_at(lua_State *L);

/**
 */
extern int
reql_lua_circle(lua_State *L);

/**
 */
extern int
reql_lua_coerce_to(lua_State *L);

/**
 */
extern int
reql_lua_concat_map(lua_State *L);

/**
 */
extern int
reql_lua_config(lua_State *L);

/**
 */
extern int
reql_lua_contains(lua_State *L);

/**
 */
extern int
reql_lua_count(lua_State *L);

/**
 */
extern int
reql_lua_date(lua_State *L);

/**
 */
extern int
reql_lua_datum(lua_State *L);

/**
 */
extern int
reql_lua_day(lua_State *L);

/**
 */
extern int
reql_lua_day_of_week(lua_State *L);

/**
 */
extern int
reql_lua_day_of_year(lua_State *L);

/**
 */
extern int
reql_lua_db(lua_State *L);

/**
 */
extern int
reql_lua_db_create(lua_State *L);

/**
 */
extern int
reql_lua_db_drop(lua_State *L);

/**
 */
extern int
reql_lua_db_list(lua_State *L);

/**
 */
extern int
reql_lua_december(lua_State *L);

/**
 */
extern int
reql_lua_default(lua_State *L);

/**
 */
extern int
reql_lua_delete(lua_State *L);

/**
 */
extern int
reql_lua_delete_at(lua_State *L);

/**
 */
extern int
reql_lua_desc(lua_State *L);

/**
 */
extern int
reql_lua_difference(lua_State *L);

/**
 */
extern int
reql_lua_distance(lua_State *L);

/**
 */
extern int
reql_lua_distinct(lua_State *L);

/**
 */
extern int
reql_lua_div(lua_State *L);

/**
 */
extern int
reql_lua_downcase(lua_State *L);

/**
 */
extern int
reql_lua_during(lua_State *L);

/**
 */
extern int
reql_lua_epoch_time(lua_State *L);

/**
 */
extern int
reql_lua_eq(lua_State *L);

/**
 */
extern int
reql_lua_eq_join(lua_State *L);

/**
 */
extern int
reql_lua_error(lua_State *L);

/**
 */
extern int
reql_lua_february(lua_State *L);

/**
 */
extern int
reql_lua_fill(lua_State *L);

/**
 */
extern int
reql_lua_filter(lua_State *L);

/**
 */
extern int
reql_lua_floor(lua_State *L);

/**
 */
extern int
reql_lua_for_each(lua_State *L);

/**
 */
extern int
reql_lua_friday(lua_State *L);

/**
 */
extern int
reql_lua_func(lua_State *L);

/**
 */
extern int
reql_lua_funcall(lua_State *L);

/**
 */
extern int
reql_lua_ge(lua_State *L);

/**
 */
extern int
reql_lua_geojson(lua_State *L);

/**
 */
extern int
reql_lua_get(lua_State *L);

/**
 */
extern int
reql_lua_get_all(lua_State *L);

/**
 */
extern int
reql_lua_get_field(lua_State *L);

/**
 */
extern int
reql_lua_get_intersecting(lua_State *L);

/**
 */
extern int
reql_lua_get_nearest(lua_State *L);

/**
 */
extern int
reql_lua_group(lua_State *L);

/**
 */
extern int
reql_lua_gt(lua_State *L);

/**
 */
extern int
reql_lua_has_fields(lua_State *L);

/**
 */
extern int
reql_lua_hours(lua_State *L);

/**
 */
extern int
reql_lua_http(lua_State *L);

/**
 */
extern int
reql_lua_implicit_var(lua_State *L);

/**
 */
extern int
reql_lua_includes(lua_State *L);

/**
 */
extern int
reql_lua_index_create(lua_State *L);

/**
 */
extern int
reql_lua_index_drop(lua_State *L);

/**
 */
extern int
reql_lua_index_list(lua_State *L);

/**
 */
extern int
reql_lua_index_rename(lua_State *L);

/**
 */
extern int
reql_lua_index_status(lua_State *L);

/**
 */
extern int
reql_lua_index_wait(lua_State *L);

/**
 */
extern int
reql_lua_info(lua_State *L);

/**
 */
extern int
reql_lua_inner_join(lua_State *L);

/**
 */
extern int
reql_lua_insert(lua_State *L);

/**
 */
extern int
reql_lua_insert_at(lua_State *L);

/**
 */
extern int
reql_lua_intersects(lua_State *L);

/**
 */
extern int
reql_lua_in_timezone(lua_State *L);

/**
 */
extern int
reql_lua_iso8601(lua_State *L);

/**
 */
extern int
reql_lua_is_empty(lua_State *L);

/**
 */
extern int
reql_lua_january(lua_State *L);

/**
 */
extern int
reql_lua_javascript(lua_State *L);

/**
 */
extern int
reql_lua_json(lua_State *L);

/**
 */
extern int
reql_lua_july(lua_State *L);

/**
 */
extern int
reql_lua_june(lua_State *L);

/**
 */
extern int
reql_lua_keys(lua_State *L);

/**
 */
extern int
reql_lua_le(lua_State *L);

/**
 */
extern int
reql_lua_limit(lua_State *L);

/**
 */
extern int
reql_lua_line(lua_State *L);

/**
 */
extern int
reql_lua_literal(lua_State *L);

/**
 */
extern int
reql_lua_lt(lua_State *L);

/**
 */
extern int
reql_lua_make_array(lua_State *L);

/**
 */
extern int
reql_lua_make_obj(lua_State *L);

/**
 */
extern int
reql_lua_map(lua_State *L);

/**
 */
extern int
reql_lua_march(lua_State *L);

/**
 */
extern int
reql_lua_match(lua_State *L);

/**
 */
extern int
reql_lua_max(lua_State *L);

/**
 */
extern int
reql_lua_maxval(lua_State *L);

/**
 */
extern int
reql_lua_may(lua_State *L);

/**
 */
extern int
reql_lua_merge(lua_State *L);

/**
 */
extern int
reql_lua_min(lua_State *L);

/**
 */
extern int
reql_lua_minutes(lua_State *L);

/**
 */
extern int
reql_lua_minval(lua_State *L);

/**
 */
extern int
reql_lua_mod(lua_State *L);

/**
 */
extern int
reql_lua_monday(lua_State *L);

/**
 */
extern int
reql_lua_month(lua_State *L);

/**
 */
extern int
reql_lua_mul(lua_State *L);

/**
 */
extern int
reql_lua_ne(lua_State *L);

/**
 */
extern int
reql_lua_not(lua_State *L);

/**
 */
extern int
reql_lua_november(lua_State *L);

/**
 */
extern int
reql_lua_now(lua_State *L);

/**
 */
extern int
reql_lua_nth(lua_State *L);

/**
 */
extern int
reql_lua_object(lua_State *L);

/**
 */
extern int
reql_lua_october(lua_State *L);

/**
 */
extern int
reql_lua_offsets_of(lua_State *L);

/**
 */
extern int
reql_lua_or(lua_State *L);

/**
 */
extern int
reql_lua_order_by(lua_State *L);

/**
 */
extern int
reql_lua_outer_join(lua_State *L);

/**
 */
extern int
reql_lua_pluck(lua_State *L);

/**
 */
extern int
reql_lua_point(lua_State *L);

/**
 */
extern int
reql_lua_polygon(lua_State *L);

/**
 */
extern int
reql_lua_polygon_sub(lua_State *L);

/**
 */
extern int
reql_lua_prepend(lua_State *L);

/**
 */
extern int
reql_lua_random(lua_State *L);

/**
 */
extern int
reql_lua_range(lua_State *L);

/**
 */
extern int
reql_lua_rebalance(lua_State *L);

/**
 */
extern int
reql_lua_reconfigure(lua_State *L);

/**
 */
extern int
reql_lua_reduce(lua_State *L);

/**
 */
extern int
reql_lua_replace(lua_State *L);

/**
 */
extern int
reql_lua_round(lua_State *L);

/**
 */
extern int
reql_lua_sample(lua_State *L);

/**
 */
extern int
reql_lua_saturday(lua_State *L);

/**
 */
extern int
reql_lua_seconds(lua_State *L);

/**
 */
extern int
reql_lua_september(lua_State *L);

/**
 */
extern int
reql_lua_set_difference(lua_State *L);

/**
 */
extern int
reql_lua_set_insert(lua_State *L);

/**
 */
extern int
reql_lua_set_intersection(lua_State *L);

/**
 */
extern int
reql_lua_set_union(lua_State *L);

/**
 */
extern int
reql_lua_skip(lua_State *L);

/**
 */
extern int
reql_lua_slice(lua_State *L);

/**
 */
extern int
reql_lua_splice_at(lua_State *L);

/**
 */
extern int
reql_lua_split(lua_State *L);

/**
 */
extern int
reql_lua_status(lua_State *L);

/**
 */
extern int
reql_lua_sub(lua_State *L);

/**
 */
extern int
reql_lua_sum(lua_State *L);

/**
 */
extern int
reql_lua_sunday(lua_State *L);

/**
 */
extern int
reql_lua_sync(lua_State *L);

/**
 */
extern int
reql_lua_table(lua_State *L);

/**
 */
extern int
reql_lua_table_create(lua_State *L);

/**
 */
extern int
reql_lua_table_drop(lua_State *L);

/**
 */
extern int
reql_lua_table_list(lua_State *L);

/**
 */
extern int
reql_lua_thursday(lua_State *L);

/**
 */
extern int
reql_lua_time(lua_State *L);

/**
 */
extern int
reql_lua_timezone(lua_State *L);

/**
 */
extern int
reql_lua_time_of_day(lua_State *L);

/**
 */
extern int
reql_lua_to_epoch_time(lua_State *L);

/**
 */
extern int
reql_lua_to_geojson(lua_State *L);

/**
 */
extern int
reql_lua_to_iso8601(lua_State *L);

/**
 */
extern int
reql_lua_to_json_string(lua_State *L);

/**
 */
extern int
reql_lua_tuesday(lua_State *L);

/**
 */
extern int
reql_lua_type_of(lua_State *L);

/**
 */
extern int
reql_lua_ungroup(lua_State *L);

/**
 */
extern int
reql_lua_union(lua_State *L);

/**
 */
extern int
reql_lua_upcase(lua_State *L);

/**
 */
extern int
reql_lua_update(lua_State *L);

/**
 */
extern int
reql_lua_uuid(lua_State *L);

/**
 */
extern int
reql_lua_values(lua_State *L);

/**
 */
extern int
reql_lua_var(lua_State *L);

/**
 */
extern int
reql_lua_wait(lua_State *L);

/**
 */
extern int
reql_lua_wednesday(lua_State *L);

/**
 */
extern int
reql_lua_without(lua_State *L);

/**
 */
extern int
reql_lua_with_fields(lua_State *L);

/**
 */
extern int
reql_lua_year(lua_State *L);

/**
 */
extern int
reql_lua_zip(lua_State *L);

#endif  // REQL_LUA_QUERY_HPP_
