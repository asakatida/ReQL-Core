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

/**
 */
int _reql_lua_add(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_add, NULL);
}

/**
 */
int _reql_lua_all(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_all, NULL);
}

/**
 */
int _reql_lua_any(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_any, NULL);
}

/**
 */
int _reql_lua_append(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_append, NULL);
}

/**
 */
int _reql_lua_april(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_april, NULL);
}

/**
 */
int _reql_lua_args(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_args, NULL);
}

/**
 */
int _reql_lua_asc(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_asc, NULL);
}

/**
 */
int _reql_lua_august(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_august, NULL);
}

/**
 */
int _reql_lua_avg(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_avg, NULL);
}

/**
 */
int _reql_lua_between(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_between, NULL);
}

/**
 */
int _reql_lua_binary(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_binary, NULL);
}

/**
 */
int _reql_lua_bracket(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_bracket, NULL);
}

/**
 */
int _reql_lua_branch(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_branch, NULL);
}

/**
 */
int _reql_lua_changes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_changes, NULL);
}

/**
 */
int _reql_lua_change_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_change_at, NULL);
}

/**
 */
int _reql_lua_circle(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_circle);
}

/**
 */
int _reql_lua_coerce_to(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_coerce_to, NULL);
}

/**
 */
int _reql_lua_concat_map(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_concat_map, NULL);
}

/**
 */
int _reql_lua_contains(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_contains, NULL);
}

/**
 */
int _reql_lua_count(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_count, NULL);
}

/**
 */
int _reql_lua_date(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_date, NULL);
}

/**
 */
int _reql_lua_datum(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_datum, NULL);
}

/**
 */
int _reql_lua_day(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_day, NULL);
}

/**
 */
int _reql_lua_day_of_week(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_day_of_week, NULL);
}

/**
 */
int _reql_lua_day_of_year(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_day_of_year, NULL);
}

/**
 */
int _reql_lua_db(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db, NULL);
}

/**
 */
int _reql_lua_db_config(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db_config, NULL);
}

/**
 */
int _reql_lua_db_create(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db_create, NULL);
}

/**
 */
int _reql_lua_db_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db_drop, NULL);
}

/**
 */
int _reql_lua_db_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_db_list, NULL);
}

/**
 */
int _reql_lua_december(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_december, NULL);
}

/**
 */
int _reql_lua_default(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_default, NULL);
}

/**
 */
int _reql_lua_delete(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_delete);
}

/**
 */
int _reql_lua_delete_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_delete_at, NULL);
}

/**
 */
int _reql_lua_desc(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_desc, NULL);
}

/**
 */
int _reql_lua_difference(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_difference, NULL);
}

/**
 */
int _reql_lua_distance(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_distance, NULL);
}

/**
 */
int _reql_lua_distinct(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_distinct);
}

/**
 */
int _reql_lua_div(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_div, NULL);
}

/**
 */
int _reql_lua_downcase(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_downcase, NULL);
}

/**
 */
int _reql_lua_during(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_during, NULL);
}

/**
 */
int _reql_lua_epoch_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_epoch_time, NULL);
}

/**
 */
int _reql_lua_eq(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_eq, NULL);
}

/**
 */
int _reql_lua_eq_join(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_eq_join);
}

/**
 */
int _reql_lua_error(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_error, NULL);
}

/**
 */
int _reql_lua_february(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_february, NULL);
}

/**
 */
int _reql_lua_fill(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_fill, NULL);
}

/**
 */
int _reql_lua_filter(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_filter);
}

/**
 */
int _reql_lua_for_each(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_for_each, NULL);
}

/**
 */
int _reql_lua_friday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_friday, NULL);
}

/**
 */
int _reql_lua_func(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_func, NULL);
}

/**
 */
int _reql_lua_funcall(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_funcall, NULL);
}

/**
 */
int _reql_lua_ge(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_ge, NULL);
}

/**
 */
int _reql_lua_geojson(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_geojson, NULL);
}

/**
 */
int _reql_lua_get(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_get, NULL);
}

/**
 */
int _reql_lua_get_all(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_get_all);
}

/**
 */
int _reql_lua_get_field(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_get_field, NULL);
}

/**
 */
int _reql_lua_get_intersecting(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_get_intersecting);
}

/**
 */
int _reql_lua_get_nearest(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_get_nearest);
}

/**
 */
int _reql_lua_group(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_group);
}

/**
 */
int _reql_lua_gt(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_gt, NULL);
}

/**
 */
int _reql_lua_has_fields(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_has_fields, NULL);
}

/**
 */
int _reql_lua_hours(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_hours, NULL);
}

/**
 */
int _reql_lua_http(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_http);
}

/**
 */
int _reql_lua_implicit_var(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_implicit_var, NULL);
}

/**
 */
int _reql_lua_includes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_includes, NULL);
}

/**
 */
int _reql_lua_indexes_of(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_indexes_of, NULL);
}

/**
 */
int _reql_lua_index_create(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_index_create);
}

/**
 */
int _reql_lua_index_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_index_drop, NULL);
}

/**
 */
int _reql_lua_index_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_index_list, NULL);
}

/**
 */
int _reql_lua_index_rename(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_index_rename);
}

/**
 */
int _reql_lua_index_status(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_index_status, NULL);
}

/**
 */
int _reql_lua_index_wait(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_index_wait, NULL);
}

/**
 */
int _reql_lua_info(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_info, NULL);
}

/**
 */
int _reql_lua_inner_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_inner_join, NULL);
}

/**
 */
int _reql_lua_insert(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_insert, NULL);
}

/**
 */
int _reql_lua_insert_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_insert_at, NULL);
}

/**
 */
int _reql_lua_intersects(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_intersects, NULL);
}

/**
 */
int _reql_lua_in_timezone(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_in_timezone, NULL);
}

/**
 */
int _reql_lua_iso8601(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_iso8601);
}

/**
 */
int _reql_lua_is_empty(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_is_empty, NULL);
}

/**
 */
int _reql_lua_january(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_january, NULL);
}

/**
 */
int _reql_lua_javascript(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_javascript);
}

/**
 */
int _reql_lua_json(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_json, NULL);
}

/**
 */
int _reql_lua_july(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_july, NULL);
}

/**
 */
int _reql_lua_june(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_june, NULL);
}

/**
 */
int _reql_lua_keys(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_keys, NULL);
}

/**
 */
int _reql_lua_le(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_le, NULL);
}

/**
 */
int _reql_lua_limit(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_limit, NULL);
}

/**
 */
int _reql_lua_line(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_line, NULL);
}

/**
 */
int _reql_lua_literal(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_literal, NULL);
}

/**
 */
int _reql_lua_lt(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_lt, NULL);
}

/**
 */
int _reql_lua_make_array(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_make_array, NULL);
}

/**
 */
int _reql_lua_make_obj(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_make_obj, NULL);
}

/**
 */
int _reql_lua_map(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_map, NULL);
}

/**
 */
int _reql_lua_march(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_march, NULL);
}

/**
 */
int _reql_lua_match(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_match, NULL);
}

/**
 */
int _reql_lua_max(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_max, NULL);
}

/**
 */
int _reql_lua_may(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_may, NULL);
}

/**
 */
int _reql_lua_merge(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_merge, NULL);
}

/**
 */
int _reql_lua_min(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_min, NULL);
}

/**
 */
int _reql_lua_minutes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_minutes, NULL);
}

/**
 */
int _reql_lua_mod(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_mod, NULL);
}

/**
 */
int _reql_lua_monday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_monday, NULL);
}

/**
 */
int _reql_lua_month(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_month, NULL);
}

/**
 */
int _reql_lua_mul(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_mul, NULL);
}

/**
 */
int _reql_lua_ne(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_ne, NULL);
}

/**
 */
int _reql_lua_not(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_not, NULL);
}

/**
 */
int _reql_lua_november(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_november, NULL);
}

/**
 */
int _reql_lua_now(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_now, NULL);
}

/**
 */
int _reql_lua_nth(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_nth, NULL);
}

/**
 */
int _reql_lua_object(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_object, NULL);
}

/**
 */
int _reql_lua_october(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_october, NULL);
}

/**
 */
int _reql_lua_order_by(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_order_by);
}

/**
 */
int _reql_lua_outer_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_outer_join, NULL);
}

/**
 */
int _reql_lua_pluck(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_pluck, NULL);
}

/**
 */
int _reql_lua_point(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_point, NULL);
}

/**
 */
int _reql_lua_polygon(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_polygon, NULL);
}

/**
 */
int _reql_lua_polygon_sub(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_polygon_sub, NULL);
}

/**
 */
int _reql_lua_prepend(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_prepend, NULL);
}

/**
 */
int _reql_lua_random(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_random);
}

/**
 */
int _reql_lua_range(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_range, NULL);
}

/**
 */
int _reql_lua_rebalance(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_rebalance, NULL);
}

/**
 */
int _reql_lua_reconfigure(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_reconfigure, NULL);
}

/**
 */
int _reql_lua_reduce(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_reduce, NULL);
}

/**
 */
int _reql_lua_replace(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_replace);
}

/**
 */
int _reql_lua_sample(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sample, NULL);
}

/**
 */
int _reql_lua_saturday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_saturday, NULL);
}

/**
 */
int _reql_lua_seconds(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_seconds, NULL);
}

/**
 */
int _reql_lua_september(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_september, NULL);
}

/**
 */
int _reql_lua_set_difference(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_set_difference, NULL);
}

/**
 */
int _reql_lua_set_insert(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_set_insert, NULL);
}

/**
 */
int _reql_lua_set_intersection(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_set_intersection, NULL);
}

/**
 */
int _reql_lua_set_union(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_set_union, NULL);
}

/**
 */
int _reql_lua_skip(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_skip, NULL);
}

/**
 */
int _reql_lua_slice(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_slice);
}

/**
 */
int _reql_lua_splice_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_splice_at, NULL);
}

/**
 */
int _reql_lua_split(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_split, NULL);
}

/**
 */
int _reql_lua_sub(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sub, NULL);
}

/**
 */
int _reql_lua_sum(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sum, NULL);
}

/**
 */
int _reql_lua_sunday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sunday, NULL);
}

/**
 */
int _reql_lua_sync(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_sync, NULL);
}

/**
 */
int _reql_lua_table(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_table);
}

/**
 */
int _reql_lua_table_config(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_table_config, NULL);
}

/**
 */
int _reql_lua_table_create(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_table_create);
}

/**
 */
int _reql_lua_table_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_table_drop, NULL);
}

/**
 */
int _reql_lua_table_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_table_list, NULL);
}

/**
 */
int _reql_lua_table_status(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_table_status, NULL);
}

/**
 */
int _reql_lua_table_wait(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_table_wait, NULL);
}

/**
 */
int _reql_lua_thursday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_thursday, NULL);
}

/**
 */
int _reql_lua_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_time, NULL);
}

/**
 */
int _reql_lua_timezone(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_timezone, NULL);
}

/**
 */
int _reql_lua_time_of_day(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_time_of_day, NULL);
}

/**
 */
int _reql_lua_to_epoch_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_to_epoch_time, NULL);
}

/**
 */
int _reql_lua_to_geojson(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_to_geojson, NULL);
}

/**
 */
int _reql_lua_to_iso8601(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_to_iso8601, NULL);
}

/**
 */
int _reql_lua_to_json_string(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_to_json_string, NULL);
}

/**
 */
int _reql_lua_tuesday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_tuesday, NULL);
}

/**
 */
int _reql_lua_type_of(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_type_of, NULL);
}

/**
 */
int _reql_lua_ungroup(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_ungroup, NULL);
}

/**
 */
int _reql_lua_union(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_union, NULL);
}

/**
 */
int _reql_lua_upcase(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_upcase, NULL);
}

/**
 */
int _reql_lua_update(lua_State *L) {
  return _reql_lua_get_opts(L, _reql_ast_update);
}

/**
 */
int _reql_lua_uuid(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_uuid, NULL);
}

/**
 */
int _reql_lua_var(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_var, NULL);
}

/**
 */
int _reql_lua_wednesday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_wednesday, NULL);
}

/**
 */
int _reql_lua_without(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_without, NULL);
}

/**
 */
int _reql_lua_with_fields(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_with_fields, NULL);
}

/**
 */
int _reql_lua_year(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_year, NULL);
}

/**
 */
int _reql_lua_zip(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ast_zip, NULL);
}
