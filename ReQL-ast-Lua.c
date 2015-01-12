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

#include "ReQL-ast-Lua.h"

int _reql_lua_ast_class(lua_State *L, _ReQL_AST_Function f, _ReQL_Op kwargs) {
  uint32_t size = lua_gettop(L), i;

  _ReQL_Op args = lua_newuserdata(L, sizeof(_ReQL_Op_t));
  _ReQL_Op *arr = lua_newuserdata(L, sizeof(_ReQL_Op) * size);

  _reql_array_init(args, arr, size);

  for (i=0; i<size; ++i) {
    _reql_array_insert(args, _reql_from_lua(L, i, 20), i);
  }

  _ReQL_Op val = lua_newuserdata(L, sizeof(_ReQL_Op_t));

  f(val, args, kwargs);

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

extern int
_reql_lua_add(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_add, NULL);
}

extern int
_reql_lua_all(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_all, NULL);
}

extern int
_reql_lua_any(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_any, NULL);
}

extern int
_reql_lua_append(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_append, NULL);
}

extern int
_reql_lua_april(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_april, NULL);
}

extern int
_reql_lua_args(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_args, NULL);
}

extern int
_reql_lua_asc(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_asc, NULL);
}

extern int
_reql_lua_august(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_august, NULL);
}

extern int
_reql_lua_avg(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_avg, NULL);
}

extern int
_reql_lua_between(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_between, NULL);
}

extern int
_reql_lua_binary(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_binary, NULL);
}

extern int
_reql_lua_bracket(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_bracket, NULL);
}

extern int
_reql_lua_branch(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_branch, NULL);
}

extern int
_reql_lua_changes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_changes, NULL);
}

extern int
_reql_lua_change_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_change_at, NULL);
}

extern int
_reql_lua_circle(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_circle);
}

extern int
_reql_lua_coerce_to(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_coerce_to, NULL);
}

extern int
_reql_lua_concat_map(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_concat_map, NULL);
}

extern int
_reql_lua_config(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_config, NULL);
}

extern int
_reql_lua_contains(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_contains, NULL);
}

extern int
_reql_lua_count(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_count, NULL);
}

extern int
_reql_lua_date(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_date, NULL);
}

extern int
_reql_lua_datum(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_datum, NULL);
}

extern int
_reql_lua_day(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_day, NULL);
}

extern int
_reql_lua_day_of_week(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_day_of_week, NULL);
}

extern int
_reql_lua_day_of_year(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_day_of_year, NULL);
}

extern int
_reql_lua_db(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db, NULL);
}

extern int
_reql_lua_db_create(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db_create, NULL);
}

extern int
_reql_lua_db_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db_drop, NULL);
}

extern int
_reql_lua_db_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db_list, NULL);
}

extern int
_reql_lua_december(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_december, NULL);
}

extern int
_reql_lua_default(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_default, NULL);
}

extern int
_reql_lua_delete(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_delete);
}

extern int
_reql_lua_delete_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_delete_at, NULL);
}

extern int
_reql_lua_desc(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_desc, NULL);
}

extern int
_reql_lua_difference(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_difference, NULL);
}

extern int
_reql_lua_distance(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_distance, NULL);
}

extern int
_reql_lua_distinct(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_distinct);
}

extern int
_reql_lua_div(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_div, NULL);
}

extern int
_reql_lua_downcase(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_downcase, NULL);
}

extern int
_reql_lua_during(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_during, NULL);
}

extern int
_reql_lua_epoch_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_epoch_time, NULL);
}

extern int
_reql_lua_eq(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_eq, NULL);
}

extern int
_reql_lua_eq_join(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_eq_join);
}

extern int
_reql_lua_error(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_error, NULL);
}

extern int
_reql_lua_february(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_february, NULL);
}

extern int
_reql_lua_fill(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_fill, NULL);
}

extern int
_reql_lua_filter(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_filter);
}

extern int
_reql_lua_for_each(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_for_each, NULL);
}

extern int
_reql_lua_friday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_friday, NULL);
}

extern int
_reql_lua_func(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_func, NULL);
}

extern int
_reql_lua_funcall(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_funcall, NULL);
}

extern int
_reql_lua_ge(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_ge, NULL);
}

extern int
_reql_lua_geojson(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_geojson, NULL);
}

extern int
_reql_lua_get(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_get, NULL);
}

extern int
_reql_lua_get_all(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_get_all);
}

extern int
_reql_lua_get_field(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_get_field, NULL);
}

extern int
_reql_lua_get_intersecting(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_get_intersecting);
}

extern int
_reql_lua_get_nearest(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_get_nearest);
}

extern int
_reql_lua_group(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_group);
}

extern int
_reql_lua_gt(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_gt, NULL);
}

extern int
_reql_lua_has_fields(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_has_fields, NULL);
}

extern int
_reql_lua_hours(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_hours, NULL);
}

extern int
_reql_lua_http(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_http);
}

extern int
_reql_lua_implicit_var(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_implicit_var, NULL);
}

extern int
_reql_lua_includes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_includes, NULL);
}

extern int
_reql_lua_indexes_of(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_indexes_of, NULL);
}

extern int
_reql_lua_index_create(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_index_create);
}

extern int
_reql_lua_index_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_index_drop, NULL);
}

extern int
_reql_lua_index_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_index_list, NULL);
}

extern int
_reql_lua_index_rename(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_index_rename);
}

extern int
_reql_lua_index_status(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_index_status, NULL);
}

extern int
_reql_lua_index_wait(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_index_wait, NULL);
}

extern int
_reql_lua_info(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_info, NULL);
}

extern int
_reql_lua_inner_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_inner_join, NULL);
}

extern int
_reql_lua_insert(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_insert, NULL);
}

extern int
_reql_lua_insert_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_insert_at, NULL);
}

extern int
_reql_lua_intersects(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_intersects, NULL);
}

extern int
_reql_lua_in_timezone(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_in_timezone, NULL);
}

extern int
_reql_lua_iso8601(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_iso8601);
}

extern int
_reql_lua_is_empty(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_is_empty, NULL);
}

extern int
_reql_lua_january(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_january, NULL);
}

extern int
_reql_lua_javascript(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_javascript);
}

extern int
_reql_lua_json(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_json, NULL);
}

extern int
_reql_lua_july(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_july, NULL);
}

extern int
_reql_lua_june(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_june, NULL);
}

extern int
_reql_lua_keys(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_keys, NULL);
}

extern int
_reql_lua_le(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_le, NULL);
}

extern int
_reql_lua_limit(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_limit, NULL);
}

extern int
_reql_lua_line(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_line, NULL);
}

extern int
_reql_lua_literal(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_literal, NULL);
}

extern int
_reql_lua_lt(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_lt, NULL);
}

extern int
_reql_lua_make_array(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_make_array, NULL);
}

extern int
_reql_lua_make_obj(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_make_obj, NULL);
}

extern int
_reql_lua_map(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_map, NULL);
}

extern int
_reql_lua_march(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_march, NULL);
}

extern int
_reql_lua_match(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_match, NULL);
}

extern int
_reql_lua_max(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_max, NULL);
}

extern int
_reql_lua_may(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_may, NULL);
}

extern int
_reql_lua_merge(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_merge, NULL);
}

extern int
_reql_lua_min(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_min, NULL);
}

extern int
_reql_lua_minutes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_minutes, NULL);
}

extern int
_reql_lua_mod(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_mod, NULL);
}

extern int
_reql_lua_monday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_monday, NULL);
}

extern int
_reql_lua_month(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_month, NULL);
}

extern int
_reql_lua_mul(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_mul, NULL);
}

extern int
_reql_lua_ne(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_ne, NULL);
}

extern int
_reql_lua_not(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_not, NULL);
}

extern int
_reql_lua_november(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_november, NULL);
}

extern int
_reql_lua_now(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_now, NULL);
}

extern int
_reql_lua_nth(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_nth, NULL);
}

extern int
_reql_lua_object(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_object, NULL);
}

extern int
_reql_lua_october(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_october, NULL);
}

extern int
_reql_lua_order_by(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_order_by);
}

extern int
_reql_lua_outer_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_outer_join, NULL);
}

extern int
_reql_lua_pluck(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_pluck, NULL);
}

extern int
_reql_lua_point(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_point, NULL);
}

extern int
_reql_lua_polygon(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_polygon, NULL);
}

extern int
_reql_lua_polygon_sub(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_polygon_sub, NULL);
}

extern int
_reql_lua_prepend(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_prepend, NULL);
}

extern int
_reql_lua_random(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_random);
}

extern int
_reql_lua_range(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_range, NULL);
}

extern int
_reql_lua_rebalance(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_rebalance, NULL);
}

extern int
_reql_lua_reconfigure(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_reconfigure, NULL);
}

extern int
_reql_lua_reduce(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_reduce, NULL);
}

extern int
_reql_lua_replace(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_replace);
}

extern int
_reql_lua_sample(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sample, NULL);
}

extern int
_reql_lua_saturday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_saturday, NULL);
}

extern int
_reql_lua_seconds(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_seconds, NULL);
}

extern int
_reql_lua_september(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_september, NULL);
}

extern int
_reql_lua_set_difference(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_set_difference, NULL);
}

extern int
_reql_lua_set_insert(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_set_insert, NULL);
}

extern int
_reql_lua_set_intersection(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_set_intersection, NULL);
}

extern int
_reql_lua_set_union(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_set_union, NULL);
}

extern int
_reql_lua_skip(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_skip, NULL);
}

extern int
_reql_lua_slice(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_slice);
}

extern int
_reql_lua_splice_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_splice_at, NULL);
}

extern int
_reql_lua_split(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_split, NULL);
}

extern int
_reql_lua_status(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_status, NULL);
}

extern int
_reql_lua_sub(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sub, NULL);
}

extern int
_reql_lua_sum(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sum, NULL);
}

extern int
_reql_lua_sunday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sunday, NULL);
}

extern int
_reql_lua_sync(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sync, NULL);
}

extern int
_reql_lua_table(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_table);
}

extern int
_reql_lua_table_create(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_table_create);
}

extern int
_reql_lua_table_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_table_drop, NULL);
}

extern int
_reql_lua_table_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_table_list, NULL);
}

extern int
_reql_lua_thursday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_thursday, NULL);
}

extern int
_reql_lua_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_time, NULL);
}

extern int
_reql_lua_timezone(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_timezone, NULL);
}

extern int
_reql_lua_time_of_day(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_time_of_day, NULL);
}

extern int
_reql_lua_to_epoch_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_to_epoch_time, NULL);
}

extern int
_reql_lua_to_geojson(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_to_geojson, NULL);
}

extern int
_reql_lua_to_iso8601(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_to_iso8601, NULL);
}

extern int
_reql_lua_to_json_string(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_to_json_string, NULL);
}

extern int
_reql_lua_tuesday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_tuesday, NULL);
}

extern int
_reql_lua_type_of(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_type_of, NULL);
}

extern int
_reql_lua_ungroup(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_ungroup, NULL);
}

extern int
_reql_lua_union(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_union, NULL);
}

extern int
_reql_lua_upcase(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_upcase, NULL);
}

extern int
_reql_lua_update(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_update);
}

extern int
_reql_lua_uuid(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_uuid, NULL);
}

extern int
_reql_lua_var(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_var, NULL);
}

extern int
_reql_lua_wait(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_wait, NULL);
}

extern int
_reql_lua_wednesday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_wednesday, NULL);
}

extern int
_reql_lua_without(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_without, NULL);
}

extern int
_reql_lua_with_fields(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_with_fields, NULL);
}

extern int
_reql_lua_year(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_year, NULL);
}

extern int
_reql_lua_zip(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_zip, NULL);
}
