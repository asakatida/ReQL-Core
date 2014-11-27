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

typedef _ReQL_Op_t* _ReQL_Op_p;

typedef _ReQL_Op_p (*_ReQL_AST_Function) (_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

static int _reql_lua_ast_class(lua_State *L, _ReQL_AST_Function f) {
  int size = lua_gettop(L), i;
  _ReQL_Op_t *args = _reql_expr_c_array(size);

  for (i=0; i<size; ++i) {
    _reql_c_array_insert(args, _reql_from_lua(L, i, 20), i);
  }

  _reql_to_lua(L, f(args, NULL));

  return 1;
}

/**
 */
static int _reql_lua_add(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_add);
}

/**
 */
static int _reql_lua_all(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_all);
}

/**
 */
static int _reql_lua_any(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_any);
}

/**
 */
static int _reql_lua_append(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_append);
}

/**
 */
static int _reql_lua_april(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_april);
}

/**
 */
static int _reql_lua_args(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_args);
}

/**
 */
static int _reql_lua_asc(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_asc);
}

/**
 */
static int _reql_lua_august(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_august);
}

/**
 */
static int _reql_lua_avg(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_avg);
}

/**
 */
static int _reql_lua_between(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_between);
}

/**
 */
static int _reql_lua_binary(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_binary);
}

/**
 */
static int _reql_lua_bracket(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_bracket);
}

/**
 */
static int _reql_lua_branch(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_branch);
}

/**
 */
static int _reql_lua_changes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_changes);
}

/**
 */
static int _reql_lua_change_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_change_at);
}

/**
 */
static int _reql_lua_circle(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_circle);
}

/**
 */
static int _reql_lua_coerce_to(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_coerce_to);
}

/**
 */
static int _reql_lua_concat_map(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_concat_map);
}

/**
 */
static int _reql_lua_contains(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_contains);
}

/**
 */
static int _reql_lua_count(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_count);
}

/**
 */
static int _reql_lua_date(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_date);
}

/**
 */
static int _reql_lua_datum(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_datum);
}

/**
 */
static int _reql_lua_day(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_day);
}

/**
 */
static int _reql_lua_day_of_week(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_day_of_week);
}

/**
 */
static int _reql_lua_day_of_year(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_day_of_year);
}

/**
 */
static int _reql_lua_db(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_db);
}

/**
 */
static int _reql_lua_db_create(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_db_create);
}

/**
 */
static int _reql_lua_db_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_db_drop);
}

/**
 */
static int _reql_lua_db_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_db_list);
}

/**
 */
static int _reql_lua_december(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_december);
}

/**
 */
static int _reql_lua_default(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_default_);
}

/**
 */
static int _reql_lua_delete(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_delete_);
}

/**
 */
static int _reql_lua_delete_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_delete_at);
}

/**
 */
static int _reql_lua_desc(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_desc);
}

/**
 */
static int _reql_lua_difference(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_difference);
}

/**
 */
static int _reql_lua_distance(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_distance);
}

/**
 */
static int _reql_lua_distinct(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_distinct);
}

/**
 */
static int _reql_lua_div(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_div);
}

/**
 */
static int _reql_lua_downcase(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_downcase);
}

/**
 */
static int _reql_lua_during(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_during);
}

/**
 */
static int _reql_lua_epoch_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_epoch_time);
}

/**
 */
static int _reql_lua_eq(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_eq);
}

/**
 */
static int _reql_lua_eq_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_eq_join);
}

/**
 */
static int _reql_lua_error(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_error);
}

/**
 */
static int _reql_lua_february(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_february);
}

/**
 */
static int _reql_lua_fill(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_fill);
}

/**
 */
static int _reql_lua_filter(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_filter);
}

/**
 */
static int _reql_lua_for_each(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_for_each);
}

/**
 */
static int _reql_lua_friday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_friday);
}

/**
 */
static int _reql_lua_func(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_func);
}

/**
 */
static int _reql_lua_funcall(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_funcall);
}

/**
 */
static int _reql_lua_ge(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ge);
}

/**
 */
static int _reql_lua_geojson(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_geojson);
}

/**
 */
static int _reql_lua_get(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get);
}

/**
 */
static int _reql_lua_get_all(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get_all);
}

/**
 */
static int _reql_lua_get_field(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get_field);
}

/**
 */
static int _reql_lua_get_intersecting(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get_intersecting);
}

/**
 */
static int _reql_lua_get_nearest(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_get_nearest);
}

/**
 */
static int _reql_lua_group(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_group);
}

/**
 */
static int _reql_lua_gt(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_gt);
}

/**
 */
static int _reql_lua_has_fields(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_has_fields);
}

/**
 */
static int _reql_lua_hours(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_hours);
}

/**
 */
static int _reql_lua_http(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_http);
}

/**
 */
static int _reql_lua_implicit_var(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_implicit_var);
}

/**
 */
static int _reql_lua_includes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_includes);
}

/**
 */
static int _reql_lua_indexes_of(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_indexes_of);
}

/**
 */
static int _reql_lua_index_create(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_create);
}

/**
 */
static int _reql_lua_index_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_drop);
}

/**
 */
static int _reql_lua_index_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_list);
}

/**
 */
static int _reql_lua_index_rename(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_rename);
}

/**
 */
static int _reql_lua_index_status(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_status);
}

/**
 */
static int _reql_lua_index_wait(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_index_wait);
}

/**
 */
static int _reql_lua_info(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_info);
}

/**
 */
static int _reql_lua_inner_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_inner_join);
}

/**
 */
static int _reql_lua_insert(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_insert);
}

/**
 */
static int _reql_lua_insert_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_insert_at);
}

/**
 */
static int _reql_lua_intersects(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_intersects);
}

/**
 */
static int _reql_lua_in_timezone(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_in_timezone);
}

/**
 */
static int _reql_lua_iso8601(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_iso8601);
}

/**
 */
static int _reql_lua_is_empty(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_is_empty);
}

/**
 */
static int _reql_lua_january(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_january);
}

/**
 */
static int _reql_lua_javascript(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_javascript);
}

/**
 */
static int _reql_lua_json(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_json);
}

/**
 */
static int _reql_lua_july(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_july);
}

/**
 */
static int _reql_lua_june(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_june);
}

/**
 */
static int _reql_lua_keys(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_keys);
}

/**
 */
static int _reql_lua_le(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_le);
}

/**
 */
static int _reql_lua_limit(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_limit);
}

/**
 */
static int _reql_lua_line(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_line);
}

/**
 */
static int _reql_lua_literal(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_literal);
}

/**
 */
static int _reql_lua_lt(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_lt);
}

/**
 */
static int _reql_lua_make_array(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_make_array);
}

/**
 */
static int _reql_lua_make_obj(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_make_obj);
}

/**
 */
static int _reql_lua_map(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_map);
}

/**
 */
static int _reql_lua_march(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_march);
}

/**
 */
static int _reql_lua_match(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_match);
}

/**
 */
static int _reql_lua_max(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_max);
}

/**
 */
static int _reql_lua_may(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_may);
}

/**
 */
static int _reql_lua_merge(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_merge);
}

/**
 */
static int _reql_lua_min(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_min);
}

/**
 */
static int _reql_lua_minutes(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_minutes);
}

/**
 */
static int _reql_lua_mod(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_mod);
}

/**
 */
static int _reql_lua_monday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_monday);
}

/**
 */
static int _reql_lua_month(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_month);
}

/**
 */
static int _reql_lua_mul(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_mul);
}

/**
 */
static int _reql_lua_ne(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ne);
}

/**
 */
static int _reql_lua_not_(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_not_);
}

/**
 */
static int _reql_lua_november(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_november);
}

/**
 */
static int _reql_lua_now(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_now);
}

/**
 */
static int _reql_lua_nth(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_nth);
}

/**
 */
static int _reql_lua_object(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_object);
}

/**
 */
static int _reql_lua_october(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_october);
}

/**
 */
static int _reql_lua_order_by(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_order_by);
}

/**
 */
static int _reql_lua_outer_join(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_outer_join);
}

/**
 */
static int _reql_lua_pluck(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_pluck);
}

/**
 */
static int _reql_lua_point(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_point);
}

/**
 */
static int _reql_lua_polygon(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_polygon);
}

/**
 */
static int _reql_lua_polygon_sub(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_polygon_sub);
}

/**
 */
static int _reql_lua_prepend(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_prepend);
}

/**
 */
static int _reql_lua_random(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_random);
}

/**
 */
static int _reql_lua_range(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_range);
}

/**
 */
static int _reql_lua_reduce(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_reduce);
}

/**
 */
static int _reql_lua_replace(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_replace);
}

/**
 */
static int _reql_lua_sample(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sample);
}

/**
 */
static int _reql_lua_saturday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_saturday);
}

/**
 */
static int _reql_lua_seconds(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_seconds);
}

/**
 */
static int _reql_lua_september(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_september);
}

/**
 */
static int _reql_lua_set_difference(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_set_difference);
}

/**
 */
static int _reql_lua_set_insert(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_set_insert);
}

/**
 */
static int _reql_lua_set_intersection(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_set_intersection);
}

/**
 */
static int _reql_lua_set_union(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_set_union);
}

/**
 */
static int _reql_lua_skip(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_skip);
}

/**
 */
static int _reql_lua_slice(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_slice);
}

/**
 */
static int _reql_lua_splice_at(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_splice_at);
}

/**
 */
static int _reql_lua_split(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_split);
}

/**
 */
static int _reql_lua_sub(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sub);
}

/**
 */
static int _reql_lua_sum(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sum);
}

/**
 */
static int _reql_lua_sunday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sunday);
}

/**
 */
static int _reql_lua_sync(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_sync);
}

/**
 */
static int _reql_lua_table(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_table);
}

/**
 */
static int _reql_lua_table_create(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_table_create);
}

/**
 */
static int _reql_lua_table_drop(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_table_drop);
}

/**
 */
static int _reql_lua_table_list(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_table_list);
}

/**
 */
static int _reql_lua_thursday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_thursday);
}

/**
 */
static int _reql_lua_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_time);
}

/**
 */
static int _reql_lua_timezone(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_timezone);
}

/**
 */
static int _reql_lua_time_of_day(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_time_of_day);
}

/**
 */
static int _reql_lua_to_epoch_time(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_to_epoch_time);
}

/**
 */
static int _reql_lua_to_geojson(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_to_geojson);
}

/**
 */
static int _reql_lua_to_iso8601(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_to_iso8601);
}

/**
 */
static int _reql_lua_to_json_string(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_to_json_string);
}

/**
 */
static int _reql_lua_tuesday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_tuesday);
}

/**
 */
static int _reql_lua_type_of(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_type_of);
}

/**
 */
static int _reql_lua_ungroup(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_ungroup);
}

/**
 */
static int _reql_lua_union_(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_union_);
}

/**
 */
static int _reql_lua_upcase(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_upcase);
}

/**
 */
static int _reql_lua_update(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_update);
}

/**
 */
static int _reql_lua_uuid(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_uuid);
}

/**
 */
static int _reql_lua_var(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_var);
}

/**
 */
static int _reql_lua_wednesday(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_wednesday);
}

/**
 */
static int _reql_lua_without(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_without);
}

/**
 */
static int _reql_lua_with_fields(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_with_fields);
}

/**
 */
static int _reql_lua_year(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_year);
}

/**
 */
static int _reql_lua_zip(lua_State *L) {
  return _reql_lua_ast_class(L, _reql_zip);
}
