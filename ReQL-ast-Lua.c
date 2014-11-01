/**
 * @author Adam Grandquist
 */

#include <lauxlib.h>
#include <lualib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ReQL-ast.h"

#include "ReQL-ast-Lua.h"

/* start generated terms */

/**
 */
static int _reql_lua_add(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_all(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_any(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_append(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_april(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_args(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_asc(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_august(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_avg(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_between(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_binary(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_bracket(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_branch(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_changes(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_change_at(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_circle(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_coerce_to(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_concat_map(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_contains(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_count(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_date(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_datum(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_day(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_day_of_week(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_day_of_year(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_db(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_db_create(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_db_drop(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_db_list(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_december(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_default_(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_delete_(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_delete_at(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_desc(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_difference(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_distance(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_distinct(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_div(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_downcase(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_during(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_epoch_time(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_eq(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_eq_join(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_error(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_february(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_fill(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_filter(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_for_each(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_friday(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_func(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_funcall(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_ge(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_geojson(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_get(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_get_all(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_get_field(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_get_intersecting(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_get_nearest(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_group(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_gt(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_has_fields(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_hours(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_http(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_implicit_var(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_includes(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_indexes_of(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_index_create(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_index_drop(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_index_list(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_index_rename(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_index_status(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_index_wait(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_info(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_inner_join(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_insert(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_insert_at(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_intersects(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_in_timezone(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_iso8601(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_is_empty(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_january(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_javascript(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_json(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_july(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_june(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_keys(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_le(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_limit(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_line(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_literal(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_lt(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_make_array(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_make_obj(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_map(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_march(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_match(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_max(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_may(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_merge(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_min(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_minutes(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_mod(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_monday(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_month(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_mul(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_ne(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_not_(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_november(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_now(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_nth(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_object(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_october(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_order_by(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_outer_join(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_pluck(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_point(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_polygon(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_polygon_sub(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_prepend(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_random(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_range(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_reduce(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_replace(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_sample(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_saturday(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_seconds(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_september(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_set_difference(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_set_insert(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_set_intersection(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_set_union(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_skip(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_slice(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_splice_at(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_split(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_sub(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_sum(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_sunday(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_sync(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_table(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_table_create(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_table_drop(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_table_list(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_thursday(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_time(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_timezone(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_time_of_day(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_to_epoch_time(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_to_geojson(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_to_iso8601(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_to_json_string(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_tuesday(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_type_of(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_ungroup(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_union_(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_upcase(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_update(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_uuid(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_var(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_wednesday(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_without(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_with_fields(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_year(lua_State *L) {
  return 1;
}

/**
 */
static int _reql_lua_zip(lua_State *L) {
  return 1;
}
/* end generated terms */
