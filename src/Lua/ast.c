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

#include "./Lua/ast.h"

static int
reql_lua_ast_class(lua_State *L, ReQL_AST_Function f) {
  uint32_t size = lua_gettop(L), i;

  ReQL_Obj_t *args = lua_newuserdata(L, sizeof(ReQL_Obj_t));
  ReQL_Obj_t **arr = lua_newuserdata(L, sizeof(ReQL_Obj_t *) * size);

  reql_array_init(args, arr, size);

  for (i=0; i < size; ++i) {
    reql_array_insert(args, reql_from_lua(L, i, 20), i);
  }

  ReQL_Obj_t *val = lua_newuserdata(L, sizeof(ReQL_Obj_t));

  f(val, args);

  return 1;
}

static int
reql_lua_get_opts(lua_State *L, ReQL_AST_Function_Kwargs f) {
  const int argn = lua_gettop(L);
  ReQL_Obj_t *kwargs = NULL;

  if (lua_istable(L, argn)) {
    lua_pushcfunction(L, reql_lua_is_instance);
    lua_pushvalue(L, argn);
    lua_pushliteral(L, "ReQLOp");
    lua_call(L, 2, 1);
    int extra = 1;
    if (!lua_toboolean(L, argn + 1)) {
      ++extra;
      kwargs = reql_from_lua(L, argn, 20);
    }
    lua_pop(L, extra);
  }

  uint32_t size = lua_gettop(L), i;

  ReQL_Obj_t *args = lua_newuserdata(L, sizeof(ReQL_Obj_t));
  ReQL_Obj_t **arr = lua_newuserdata(L, sizeof(ReQL_Obj_t *) * size);

  reql_array_init(args, arr, size);

  for (i=0; i < size; ++i) {
    reql_array_insert(args, reql_from_lua(L, i, 20), i);
  }

  ReQL_Obj_t *val = lua_newuserdata(L, sizeof(ReQL_Obj_t));

  f(val, args, kwargs);

  return 1;
}

extern int
reql_lua_add(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_add);
}

extern int
reql_lua_and(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_and);
}

extern int
reql_lua_append(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_append);
}

extern int
reql_lua_april(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_april);
}

extern int
reql_lua_args(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_args);
}

extern int
reql_lua_asc(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_asc);
}

extern int
reql_lua_august(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_august);
}

extern int
reql_lua_avg(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_avg);
}

extern int
reql_lua_between(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_between);
}

extern int
reql_lua_between_deprecated(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_between_deprecated);
}

extern int
reql_lua_binary(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_binary);
}

extern int
reql_lua_bracket(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_bracket);
}

extern int
reql_lua_branch(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_branch);
}

extern int
reql_lua_ceil(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_ceil);
}

extern int
reql_lua_changes(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_changes);
}

extern int
reql_lua_change_at(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_change_at);
}

extern int
reql_lua_circle(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_circle);
}

extern int
reql_lua_coerce_to(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_coerce_to);
}

extern int
reql_lua_concat_map(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_concat_map);
}

extern int
reql_lua_config(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_config);
}

extern int
reql_lua_contains(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_contains);
}

extern int
reql_lua_count(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_count);
}

extern int
reql_lua_date(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_date);
}

extern int
reql_lua_datum(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_datum);
}

extern int
reql_lua_day(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_day);
}

extern int
reql_lua_day_of_week(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_day_of_week);
}

extern int
reql_lua_day_of_year(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_day_of_year);
}

extern int
reql_lua_db(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_db);
}

extern int
reql_lua_db_create(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_db_create);
}

extern int
reql_lua_db_drop(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_db_drop);
}

extern int
reql_lua_db_list(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_db_list);
}

extern int
reql_lua_december(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_december);
}

extern int
reql_lua_default(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_default);
}

extern int
reql_lua_delete(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_delete);
}

extern int
reql_lua_delete_at(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_delete_at);
}

extern int
reql_lua_desc(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_desc);
}

extern int
reql_lua_difference(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_difference);
}

extern int
reql_lua_distance(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_distance);
}

extern int
reql_lua_distinct(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_distinct);
}

extern int
reql_lua_div(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_div);
}

extern int
reql_lua_downcase(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_downcase);
}

extern int
reql_lua_during(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_during);
}

extern int
reql_lua_epoch_time(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_epoch_time);
}

extern int
reql_lua_eq(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_eq);
}

extern int
reql_lua_eq_join(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_eq_join);
}

extern int
reql_lua_error(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_error);
}

extern int
reql_lua_february(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_february);
}

extern int
reql_lua_fill(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_fill);
}

extern int
reql_lua_filter(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_filter);
}

extern int
reql_lua_floor(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_floor);
}

extern int
reql_lua_for_each(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_for_each);
}

extern int
reql_lua_friday(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_friday);
}

extern int
reql_lua_func(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_func);
}

extern int
reql_lua_funcall(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_funcall);
}

extern int
reql_lua_ge(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_ge);
}

extern int
reql_lua_geojson(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_geojson);
}

extern int
reql_lua_get(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_get);
}

extern int
reql_lua_get_all(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_get_all);
}

extern int
reql_lua_get_field(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_get_field);
}

extern int
reql_lua_get_intersecting(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_get_intersecting);
}

extern int
reql_lua_get_nearest(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_get_nearest);
}

extern int
reql_lua_group(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_group);
}

extern int
reql_lua_gt(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_gt);
}

extern int
reql_lua_has_fields(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_has_fields);
}

extern int
reql_lua_hours(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_hours);
}

extern int
reql_lua_http(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_http);
}

extern int
reql_lua_implicit_var(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_implicit_var);
}

extern int
reql_lua_includes(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_includes);
}

extern int
reql_lua_index_create(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_index_create);
}

extern int
reql_lua_index_drop(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_index_drop);
}

extern int
reql_lua_index_list(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_index_list);
}

extern int
reql_lua_index_rename(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_index_rename);
}

extern int
reql_lua_index_status(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_index_status);
}

extern int
reql_lua_index_wait(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_index_wait);
}

extern int
reql_lua_info(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_info);
}

extern int
reql_lua_inner_join(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_inner_join);
}

extern int
reql_lua_insert(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_insert);
}

extern int
reql_lua_insert_at(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_insert_at);
}

extern int
reql_lua_intersects(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_intersects);
}

extern int
reql_lua_in_timezone(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_in_timezone);
}

extern int
reql_lua_iso8601(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_iso8601);
}

extern int
reql_lua_is_empty(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_is_empty);
}

extern int
reql_lua_january(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_january);
}

extern int
reql_lua_javascript(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_javascript);
}

extern int
reql_lua_json(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_json);
}

extern int
reql_lua_july(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_july);
}

extern int
reql_lua_june(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_june);
}

extern int
reql_lua_keys(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_keys);
}

extern int
reql_lua_le(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_le);
}

extern int
reql_lua_limit(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_limit);
}

extern int
reql_lua_line(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_line);
}

extern int
reql_lua_literal(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_literal);
}

extern int
reql_lua_lt(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_lt);
}

extern int
reql_lua_make_array(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_make_array);
}

extern int
reql_lua_make_obj(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_make_obj);
}

extern int
reql_lua_map(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_map);
}

extern int
reql_lua_march(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_march);
}

extern int
reql_lua_match(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_match);
}

extern int
reql_lua_max(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_max);
}

extern int
reql_lua_maxval(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_maxval);
}

extern int
reql_lua_may(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_may);
}

extern int
reql_lua_merge(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_merge);
}

extern int
reql_lua_min(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_min);
}

extern int
reql_lua_minutes(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_minutes);
}

extern int
reql_lua_minval(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_minval);
}

extern int
reql_lua_mod(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_mod);
}

extern int
reql_lua_monday(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_monday);
}

extern int
reql_lua_month(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_month);
}

extern int
reql_lua_mul(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_mul);
}

extern int
reql_lua_ne(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_ne);
}

extern int
reql_lua_not(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_not);
}

extern int
reql_lua_november(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_november);
}

extern int
reql_lua_now(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_now);
}

extern int
reql_lua_nth(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_nth);
}

extern int
reql_lua_object(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_object);
}

extern int
reql_lua_october(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_october);
}

extern int
reql_lua_offsets_of(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_offsets_of);
}

extern int
reql_lua_or(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_or);
}

extern int
reql_lua_order_by(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_order_by);
}

extern int
reql_lua_outer_join(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_outer_join);
}

extern int
reql_lua_pluck(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_pluck);
}

extern int
reql_lua_point(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_point);
}

extern int
reql_lua_polygon(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_polygon);
}

extern int
reql_lua_polygon_sub(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_polygon_sub);
}

extern int
reql_lua_prepend(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_prepend);
}

extern int
reql_lua_random(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_random);
}

extern int
reql_lua_range(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_range);
}

extern int
reql_lua_rebalance(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_rebalance);
}

extern int
reql_lua_reconfigure(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_reconfigure);
}

extern int
reql_lua_reduce(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_reduce);
}

extern int
reql_lua_replace(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_replace);
}

extern int
reql_lua_round(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_round);
}

extern int
reql_lua_sample(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_sample);
}

extern int
reql_lua_saturday(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_saturday);
}

extern int
reql_lua_seconds(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_seconds);
}

extern int
reql_lua_september(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_september);
}

extern int
reql_lua_set_difference(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_set_difference);
}

extern int
reql_lua_set_insert(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_set_insert);
}

extern int
reql_lua_set_intersection(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_set_intersection);
}

extern int
reql_lua_set_union(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_set_union);
}

extern int
reql_lua_skip(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_skip);
}

extern int
reql_lua_slice(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_slice);
}

extern int
reql_lua_splice_at(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_splice_at);
}

extern int
reql_lua_split(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_split);
}

extern int
reql_lua_status(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_status);
}

extern int
reql_lua_sub(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_sub);
}

extern int
reql_lua_sum(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_sum);
}

extern int
reql_lua_sunday(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_sunday);
}

extern int
reql_lua_sync(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_sync);
}

extern int
reql_lua_table(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_table);
}

extern int
reql_lua_table_create(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_table_create);
}

extern int
reql_lua_table_drop(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_table_drop);
}

extern int
reql_lua_table_list(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_table_list);
}

extern int
reql_lua_thursday(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_thursday);
}

extern int
reql_lua_time(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_time);
}

extern int
reql_lua_timezone(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_timezone);
}

extern int
reql_lua_time_of_day(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_time_of_day);
}

extern int
reql_lua_to_epoch_time(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_to_epoch_time);
}

extern int
reql_lua_to_geojson(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_to_geojson);
}

extern int
reql_lua_to_iso8601(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_to_iso8601);
}

extern int
reql_lua_to_json_string(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_to_json_string);
}

extern int
reql_lua_tuesday(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_tuesday);
}

extern int
reql_lua_type_of(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_type_of);
}

extern int
reql_lua_ungroup(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_ungroup);
}

extern int
reql_lua_union(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_union);
}

extern int
reql_lua_upcase(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_upcase);
}

extern int
reql_lua_update(lua_State *L) {
  return reql_lua_get_opts(L, reql_ast_update);
}

extern int
reql_lua_uuid(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_uuid);
}

extern int
reql_lua_var(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_var);
}

extern int
reql_lua_wait(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_wait);
}

extern int
reql_lua_wednesday(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_wednesday);
}

extern int
reql_lua_without(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_without);
}

extern int
reql_lua_with_fields(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_with_fields);
}

extern int
reql_lua_year(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_year);
}

extern int
reql_lua_zip(lua_State *L) {
  return reql_lua_ast_class(L, reql_ast_zip);
}
