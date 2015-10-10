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

#include "./Lua/connection.h"
#include "./Lua/cursor.h"
#include "./Lua/query.h"

#include "./reql/core.h"

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <stdlib.h>

static const struct luaL_Reg libReQL[] = {
  {"connect", reql_lua_connect},
  {"__call", reql_lua_expr},
  {"is_instance", reql_lua_is_instance},
  {"add", reql_lua_add},
  {"and_", reql_lua_and},
  {"append", reql_lua_append},
  {"april", reql_lua_april},
  {"args", reql_lua_args},
  {"asc", reql_lua_asc},
  {"august", reql_lua_august},
  {"avg", reql_lua_avg},
  {"between", reql_lua_between},
  {"between_deprecated", reql_lua_between_deprecated},
  {"binary", reql_lua_binary},
  {"bracket", reql_lua_bracket},
  {"branch", reql_lua_branch},
  {"ceil", reql_lua_ceil},
  {"changes", reql_lua_changes},
  {"change_at", reql_lua_change_at},
  {"circle", reql_lua_circle},
  {"coerce_to", reql_lua_coerce_to},
  {"concat_map", reql_lua_concat_map},
  {"config", reql_lua_config},
  {"contains", reql_lua_contains},
  {"count", reql_lua_count},
  {"date", reql_lua_date},
  {"datum", reql_lua_datum},
  {"day", reql_lua_day},
  {"day_of_week", reql_lua_day_of_week},
  {"day_of_year", reql_lua_day_of_year},
  {"db", reql_lua_db},
  {"db_create", reql_lua_db_create},
  {"db_drop", reql_lua_db_drop},
  {"db_list", reql_lua_db_list},
  {"december", reql_lua_december},
  {"default", reql_lua_default},
  {"delete", reql_lua_delete},
  {"delete_at", reql_lua_delete_at},
  {"desc", reql_lua_desc},
  {"difference", reql_lua_difference},
  {"distance", reql_lua_distance},
  {"distinct", reql_lua_distinct},
  {"div", reql_lua_div},
  {"downcase", reql_lua_downcase},
  {"during", reql_lua_during},
  {"epoch_time", reql_lua_epoch_time},
  {"eq", reql_lua_eq},
  {"eq_join", reql_lua_eq_join},
  {"error_", reql_lua_error},
  {"february", reql_lua_february},
  {"fill", reql_lua_fill},
  {"filter", reql_lua_filter},
  {"floor", reql_lua_floor},
  {"for_each", reql_lua_for_each},
  {"friday", reql_lua_friday},
  {"func", reql_lua_func},
  {"funcall", reql_lua_funcall},
  {"ge", reql_lua_ge},
  {"geojson", reql_lua_geojson},
  {"get", reql_lua_get},
  {"get_all", reql_lua_get_all},
  {"get_field", reql_lua_get_field},
  {"get_intersecting", reql_lua_get_intersecting},
  {"get_nearest", reql_lua_get_nearest},
  {"group", reql_lua_group},
  {"gt", reql_lua_gt},
  {"has_fields", reql_lua_has_fields},
  {"hours", reql_lua_hours},
  {"http", reql_lua_http},
  {"implicit_var", reql_lua_implicit_var},
  {"includes", reql_lua_includes},
  {"index_create", reql_lua_index_create},
  {"index_drop", reql_lua_index_drop},
  {"index_list", reql_lua_index_list},
  {"index_rename", reql_lua_index_rename},
  {"index_status", reql_lua_index_status},
  {"index_wait", reql_lua_index_wait},
  {"info", reql_lua_info},
  {"inner_join", reql_lua_inner_join},
  {"insert", reql_lua_insert},
  {"insert_at", reql_lua_insert_at},
  {"intersects", reql_lua_intersects},
  {"in_timezone", reql_lua_in_timezone},
  {"iso8601", reql_lua_iso8601},
  {"is_empty", reql_lua_is_empty},
  {"january", reql_lua_january},
  {"javascript", reql_lua_javascript},
  {"json", reql_lua_json},
  {"july", reql_lua_july},
  {"june", reql_lua_june},
  {"keys", reql_lua_keys},
  {"le", reql_lua_le},
  {"limit", reql_lua_limit},
  {"line", reql_lua_line},
  {"literal", reql_lua_literal},
  {"lt", reql_lua_lt},
  {"make_array", reql_lua_make_array},
  {"make_obj", reql_lua_make_obj},
  {"map", reql_lua_map},
  {"march", reql_lua_march},
  {"match", reql_lua_match},
  {"max", reql_lua_max},
  {"maxval", reql_lua_maxval},
  {"may", reql_lua_may},
  {"merge", reql_lua_merge},
  {"min", reql_lua_min},
  {"minutes", reql_lua_minutes},
  {"minval", reql_lua_minval},
  {"mod", reql_lua_mod},
  {"monday", reql_lua_monday},
  {"month", reql_lua_month},
  {"mul", reql_lua_mul},
  {"ne", reql_lua_ne},
  {"not_", reql_lua_not},
  {"november", reql_lua_november},
  {"now", reql_lua_now},
  {"nth", reql_lua_nth},
  {"object", reql_lua_object},
  {"october", reql_lua_october},
  {"offsets_of", reql_lua_offsets_of},
  {"or_", reql_lua_or},
  {"order_by", reql_lua_order_by},
  {"outer_join", reql_lua_outer_join},
  {"pluck", reql_lua_pluck},
  {"point", reql_lua_point},
  {"polygon", reql_lua_polygon},
  {"polygon_sub", reql_lua_polygon_sub},
  {"prepend", reql_lua_prepend},
  {"random", reql_lua_random},
  {"range", reql_lua_range},
  {"rebalance", reql_lua_rebalance},
  {"reconfigure", reql_lua_reconfigure},
  {"reduce", reql_lua_reduce},
  {"replace", reql_lua_replace},
  {"round", reql_lua_round},
  {"sample", reql_lua_sample},
  {"saturday", reql_lua_saturday},
  {"seconds", reql_lua_seconds},
  {"september", reql_lua_september},
  {"set_difference", reql_lua_set_difference},
  {"set_insert", reql_lua_set_insert},
  {"set_intersection", reql_lua_set_intersection},
  {"set_union", reql_lua_set_union},
  {"skip", reql_lua_skip},
  {"slice", reql_lua_slice},
  {"splice_at", reql_lua_splice_at},
  {"split", reql_lua_split},
  {"status", reql_lua_status},
  {"sub", reql_lua_sub},
  {"sum", reql_lua_sum},
  {"sunday", reql_lua_sunday},
  {"sync", reql_lua_sync},
  {"table", reql_lua_table},
  {"table_create", reql_lua_table_create},
  {"table_drop", reql_lua_table_drop},
  {"table_list", reql_lua_table_list},
  {"thursday", reql_lua_thursday},
  {"time", reql_lua_time},
  {"timezone", reql_lua_timezone},
  {"time_of_day", reql_lua_time_of_day},
  {"to_epoch_time", reql_lua_to_epoch_time},
  {"to_geojson", reql_lua_to_geojson},
  {"to_iso8601", reql_lua_to_iso8601},
  {"to_json_string", reql_lua_to_json_string},
  {"tuesday", reql_lua_tuesday},
  {"type_of", reql_lua_type_of},
  {"ungroup", reql_lua_ungroup},
  {"union", reql_lua_union},
  {"upcase", reql_lua_upcase},
  {"update", reql_lua_update},
  {"uuid", reql_lua_uuid},
  {"values", reql_lua_values},
  {"var", reql_lua_var},
  {"wait", reql_lua_wait},
  {"wednesday", reql_lua_wednesday},
  {"without", reql_lua_without},
  {"with_fields", reql_lua_with_fields},
  {"year", reql_lua_year},
  {"zip", reql_lua_zip},
  {NULL, NULL}
};

extern int luaopen_libReQL(lua_State *L) {
#if LUA_VERSION_NUM < 502
  luaL_register(L, "libReQL", libReQL);
#else
  luaL_newlib(L, libReQL);
#endif
  return 1;
}
