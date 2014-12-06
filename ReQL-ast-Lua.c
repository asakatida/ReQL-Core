/*
Copyright 2014 Adam Grandquist

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

#include "ReQL-ast-Lua.h"

int _reql_lua_ast_class(lua_State *L, _ReQL_AST_Function f, _ReQL_Op kwargs) {
  int size = lua_gettop(L), i;
  _ReQL_Op args = _reql_expr_c_array(size);

  for (i=0; i<size; ++i) {
    _reql_c_array_insert(args, _reql_from_lua(L, i, 20), i);
  }

  _reql_to_lua(L, f(args, kwargs));

  return 1;
}

int _reql_lua_get_opts(lua_State *L, _ReQL_AST_Function f) {
  const int argn = lua_gettop(L);
  _ReQL_Op kwargs = NULL;

  if (lua_istable(L, argn)) {
    lua_pushcfunction(L, _reql_lua_is_instance);
    lua_pushvalue(L, argn);
    lua_pushliteral(L, "ReQLOp");
    lua_call(L, 2, 1);
    int extra = 1;
    if (!lua_toboolean(L, argn + 1)) {
      ++extra;
      kwargs = _reql_from_lua(L, argn, 20);
    }
    lua_pop(L, extra);
  }

  return _reql_lua_ast_class(L, f, kwargs);
}

/**
 */
int _reql_lua_add(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_add, NULL);
}

/**
 */
int _reql_lua_all(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_all, NULL);
}

/**
 */
int _reql_lua_any(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_any, NULL);
}

/**
 */
int _reql_lua_append(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_append, NULL);
}

/**
 */
int _reql_lua_april(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_april, NULL);
}

/**
 */
int _reql_lua_args(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_args, NULL);
}

/**
 */
int _reql_lua_asc(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_asc, NULL);
}

/**
 */
int _reql_lua_august(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_august, NULL);
}

/**
 */
int _reql_lua_avg(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_avg, NULL);
}

/**
 */
int _reql_lua_between(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_between, NULL);
}

/**
 */
int _reql_lua_binary(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_binary, NULL);
}

/**
 */
int _reql_lua_bracket(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_bracket, NULL);
}

/**
 */
int _reql_lua_branch(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_branch, NULL);
}

/**
 */
int _reql_lua_changes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_changes, NULL);
}

/**
 */
int _reql_lua_change_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_change_at, NULL);
}

/**
 */
int _reql_lua_circle(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_circle, NULL);
}

/**
 */
int _reql_lua_coerce_to(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_coerce_to, NULL);
}

/**
 */
int _reql_lua_concat_map(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_concat_map, NULL);
}

/**
 */
int _reql_lua_contains(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_contains, NULL);
}

/**
 */
int _reql_lua_count(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_count, NULL);
}

/**
 */
int _reql_lua_date(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_date, NULL);
}

/**
 */
int _reql_lua_datum(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_datum, NULL);
}

/**
 */
int _reql_lua_day(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_day, NULL);
}

/**
 */
int _reql_lua_day_of_week(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_day_of_week, NULL);
}

/**
 */
int _reql_lua_day_of_year(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_day_of_year, NULL);
}

/**
 */
int _reql_lua_db(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_db, NULL);
}

/**
 */
int _reql_lua_db_create(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_db_create, NULL);
}

/**
 */
int _reql_lua_db_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_db_drop, NULL);
}

/**
 */
int _reql_lua_db_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_db_list, NULL);
}

/**
 */
int _reql_lua_december(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_december, NULL);
}

/**
 */
int _reql_lua_default(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_default, NULL);
}

/**
 */
int _reql_lua_delete(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_delete, NULL);
}

/**
 */
int _reql_lua_delete_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_delete_at, NULL);
}

/**
 */
int _reql_lua_desc(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_desc, NULL);
}

/**
 */
int _reql_lua_difference(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_difference, NULL);
}

/**
 */
int _reql_lua_distance(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_distance, NULL);
}

/**
 */
int _reql_lua_distinct(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_distinct, NULL);
}

/**
 */
int _reql_lua_div(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_div, NULL);
}

/**
 */
int _reql_lua_downcase(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_downcase, NULL);
}

/**
 */
int _reql_lua_during(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_during, NULL);
}

/**
 */
int _reql_lua_epoch_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_epoch_time, NULL);
}

/**
 */
int _reql_lua_eq(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_eq, NULL);
}

/**
 */
int _reql_lua_eq_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_eq_join, NULL);
}

/**
 */
int _reql_lua_error(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_error, NULL);
}

/**
 */
int _reql_lua_february(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_february, NULL);
}

/**
 */
int _reql_lua_fill(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_fill, NULL);
}

/**
 */
int _reql_lua_filter(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_filter, NULL);
}

/**
 */
int _reql_lua_for_each(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_for_each, NULL);
}

/**
 */
int _reql_lua_friday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_friday, NULL);
}

/**
 */
int _reql_lua_func(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_func, NULL);
}

/**
 */
int _reql_lua_funcall(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_funcall, NULL);
}

/**
 */
int _reql_lua_ge(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ge, NULL);
}

/**
 */
int _reql_lua_geojson(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_geojson, NULL);
}

/**
 */
int _reql_lua_get(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get, NULL);
}

/**
 */
int _reql_lua_get_all(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get_all, NULL);
}

/**
 */
int _reql_lua_get_field(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get_field, NULL);
}

/**
 */
int _reql_lua_get_intersecting(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get_intersecting, NULL);
}

/**
 */
int _reql_lua_get_nearest(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get_nearest, NULL);
}

/**
 */
int _reql_lua_group(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_group, NULL);
}

/**
 */
int _reql_lua_gt(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_gt, NULL);
}

/**
 */
int _reql_lua_has_fields(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_has_fields, NULL);
}

/**
 */
int _reql_lua_hours(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_hours, NULL);
}

/**
 */
int _reql_lua_http(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_http, NULL);
}

/**
 */
int _reql_lua_implicit_var(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_implicit_var, NULL);
}

/**
 */
int _reql_lua_includes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_includes, NULL);
}

/**
 */
int _reql_lua_indexes_of(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_indexes_of, NULL);
}

/**
 */
int _reql_lua_index_create(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_create, NULL);
}

/**
 */
int _reql_lua_index_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_drop, NULL);
}

/**
 */
int _reql_lua_index_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_list, NULL);
}

/**
 */
int _reql_lua_index_rename(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_rename, NULL);
}

/**
 */
int _reql_lua_index_status(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_status, NULL);
}

/**
 */
int _reql_lua_index_wait(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_wait, NULL);
}

/**
 */
int _reql_lua_info(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_info, NULL);
}

/**
 */
int _reql_lua_inner_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_inner_join, NULL);
}

/**
 */
int _reql_lua_insert(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_insert, NULL);
}

/**
 */
int _reql_lua_insert_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_insert_at, NULL);
}

/**
 */
int _reql_lua_intersects(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_intersects, NULL);
}

/**
 */
int _reql_lua_in_timezone(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_in_timezone, NULL);
}

/**
 */
int _reql_lua_iso8601(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_iso8601, NULL);
}

/**
 */
int _reql_lua_is_empty(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_is_empty, NULL);
}

/**
 */
int _reql_lua_january(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_january, NULL);
}

/**
 */
int _reql_lua_javascript(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_javascript, NULL);
}

/**
 */
int _reql_lua_json(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_json, NULL);
}

/**
 */
int _reql_lua_july(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_july, NULL);
}

/**
 */
int _reql_lua_june(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_june, NULL);
}

/**
 */
int _reql_lua_keys(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_keys, NULL);
}

/**
 */
int _reql_lua_le(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_le, NULL);
}

/**
 */
int _reql_lua_limit(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_limit, NULL);
}

/**
 */
int _reql_lua_line(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_line, NULL);
}

/**
 */
int _reql_lua_literal(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_literal, NULL);
}

/**
 */
int _reql_lua_lt(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_lt, NULL);
}

/**
 */
int _reql_lua_make_array(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_make_array, NULL);
}

/**
 */
int _reql_lua_make_obj(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_make_obj, NULL);
}

/**
 */
int _reql_lua_map(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_map, NULL);
}

/**
 */
int _reql_lua_march(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_march, NULL);
}

/**
 */
int _reql_lua_match(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_match, NULL);
}

/**
 */
int _reql_lua_max(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_max, NULL);
}

/**
 */
int _reql_lua_may(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_may, NULL);
}

/**
 */
int _reql_lua_merge(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_merge, NULL);
}

/**
 */
int _reql_lua_min(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_min, NULL);
}

/**
 */
int _reql_lua_minutes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_minutes, NULL);
}

/**
 */
int _reql_lua_mod(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_mod, NULL);
}

/**
 */
int _reql_lua_monday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_monday, NULL);
}

/**
 */
int _reql_lua_month(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_month, NULL);
}

/**
 */
int _reql_lua_mul(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_mul, NULL);
}

/**
 */
int _reql_lua_ne(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ne, NULL);
}

/**
 */
int _reql_lua_not(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_not, NULL);
}

/**
 */
int _reql_lua_november(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_november, NULL);
}

/**
 */
int _reql_lua_now(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_now, NULL);
}

/**
 */
int _reql_lua_nth(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_nth, NULL);
}

/**
 */
int _reql_lua_object(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_object, NULL);
}

/**
 */
int _reql_lua_october(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_october, NULL);
}

/**
 */
int _reql_lua_order_by(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_order_by, NULL);
}

/**
 */
int _reql_lua_outer_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_outer_join, NULL);
}

/**
 */
int _reql_lua_pluck(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_pluck, NULL);
}

/**
 */
int _reql_lua_point(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_point, NULL);
}

/**
 */
int _reql_lua_polygon(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_polygon, NULL);
}

/**
 */
int _reql_lua_polygon_sub(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_polygon_sub, NULL);
}

/**
 */
int _reql_lua_prepend(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_prepend, NULL);
}

/**
 */
int _reql_lua_random(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_random, NULL);
}

/**
 */
int _reql_lua_range(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_range, NULL);
}

/**
 */
int _reql_lua_reduce(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_reduce, NULL);
}

/**
 */
int _reql_lua_replace(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_replace, NULL);
}

/**
 */
int _reql_lua_sample(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sample, NULL);
}

/**
 */
int _reql_lua_saturday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_saturday, NULL);
}

/**
 */
int _reql_lua_seconds(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_seconds, NULL);
}

/**
 */
int _reql_lua_september(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_september, NULL);
}

/**
 */
int _reql_lua_set_difference(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_set_difference, NULL);
}

/**
 */
int _reql_lua_set_insert(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_set_insert, NULL);
}

/**
 */
int _reql_lua_set_intersection(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_set_intersection, NULL);
}

/**
 */
int _reql_lua_set_union(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_set_union, NULL);
}

/**
 */
int _reql_lua_skip(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_skip, NULL);
}

/**
 */
int _reql_lua_slice(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_slice, NULL);
}

/**
 */
int _reql_lua_splice_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_splice_at, NULL);
}

/**
 */
int _reql_lua_split(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_split, NULL);
}

/**
 */
int _reql_lua_sub(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sub, NULL);
}

/**
 */
int _reql_lua_sum(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sum, NULL);
}

/**
 */
int _reql_lua_sunday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sunday, NULL);
}

/**
 */
int _reql_lua_sync(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sync, NULL);
}

/**
 */
int _reql_lua_table(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_table, NULL);
}

/**
 */
int _reql_lua_table_create(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_table_create, NULL);
}

/**
 */
int _reql_lua_table_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_table_drop, NULL);
}

/**
 */
int _reql_lua_table_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_table_list, NULL);
}

/**
 */
int _reql_lua_thursday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_thursday, NULL);
}

/**
 */
int _reql_lua_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_time, NULL);
}

/**
 */
int _reql_lua_timezone(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_timezone, NULL);
}

/**
 */
int _reql_lua_time_of_day(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_time_of_day, NULL);
}

/**
 */
int _reql_lua_to_epoch_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_to_epoch_time, NULL);
}

/**
 */
int _reql_lua_to_geojson(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_to_geojson, NULL);
}

/**
 */
int _reql_lua_to_iso8601(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_to_iso8601, NULL);
}

/**
 */
int _reql_lua_to_json_string(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_to_json_string, NULL);
}

/**
 */
int _reql_lua_tuesday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_tuesday, NULL);
}

/**
 */
int _reql_lua_type_of(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_type_of, NULL);
}

/**
 */
int _reql_lua_ungroup(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ungroup, NULL);
}

/**
 */
int _reql_lua_union(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_union, NULL);
}

/**
 */
int _reql_lua_upcase(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_upcase, NULL);
}

/**
 */
int _reql_lua_update(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_update, NULL);
}

/**
 */
int _reql_lua_uuid(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_uuid, NULL);
}

/**
 */
int _reql_lua_var(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_var, NULL);
}

/**
 */
int _reql_lua_wednesday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_wednesday, NULL);
}

/**
 */
int _reql_lua_without(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_without, NULL);
}

/**
 */
int _reql_lua_with_fields(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_with_fields, NULL);
}

/**
 */
int _reql_lua_year(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_year, NULL);
}

/**
 */
int _reql_lua_zip(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_zip, NULL);
}
