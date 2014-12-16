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

#include <stdlib.h>

#include "ReQL-ast-Lua.h"

static const struct luaL_Reg libReQL[] = {
  {"connect", _reql_lua_connect},
  {"__call", _reql_lua_expr},
  {"is_instance", _reql_lua_is_instance},
  {"add", _reql_lua_add},
  {"all", _reql_lua_all},
  {"any", _reql_lua_any},
  {"append", _reql_lua_append},
  {"april", _reql_lua_april},
  {"args", _reql_lua_args},
  {"asc", _reql_lua_asc},
  {"august", _reql_lua_august},
  {"avg", _reql_lua_avg},
  {"between", _reql_lua_between},
  {"binary", _reql_lua_binary},
  {"bracket", _reql_lua_bracket},
  {"branch", _reql_lua_branch},
  {"changes", _reql_lua_changes},
  {"change_at", _reql_lua_change_at},
  {"circle", _reql_lua_circle},
  {"coerce_to", _reql_lua_coerce_to},
  {"concat_map", _reql_lua_concat_map},
  {"contains", _reql_lua_contains},
  {"count", _reql_lua_count},
  {"date", _reql_lua_date},
  {"datum", _reql_lua_datum},
  {"day", _reql_lua_day},
  {"day_of_week", _reql_lua_day_of_week},
  {"day_of_year", _reql_lua_day_of_year},
  {"db", _reql_lua_db},
  {"db_config", _reql_lua_db_config},
  {"db_create", _reql_lua_db_create},
  {"db_drop", _reql_lua_db_drop},
  {"db_list", _reql_lua_db_list},
  {"december", _reql_lua_december},
  {"default", _reql_lua_default},
  {"delete", _reql_lua_delete},
  {"delete_at", _reql_lua_delete_at},
  {"desc", _reql_lua_desc},
  {"difference", _reql_lua_difference},
  {"distance", _reql_lua_distance},
  {"distinct", _reql_lua_distinct},
  {"div", _reql_lua_div},
  {"downcase", _reql_lua_downcase},
  {"during", _reql_lua_during},
  {"epoch_time", _reql_lua_epoch_time},
  {"eq", _reql_lua_eq},
  {"eq_join", _reql_lua_eq_join},
  {"error_", _reql_lua_error},
  {"february", _reql_lua_february},
  {"fill", _reql_lua_fill},
  {"filter", _reql_lua_filter},
  {"for_each", _reql_lua_for_each},
  {"friday", _reql_lua_friday},
  {"func", _reql_lua_func},
  {"funcall", _reql_lua_funcall},
  {"ge", _reql_lua_ge},
  {"geojson", _reql_lua_geojson},
  {"get", _reql_lua_get},
  {"get_all", _reql_lua_get_all},
  {"get_field", _reql_lua_get_field},
  {"get_intersecting", _reql_lua_get_intersecting},
  {"get_nearest", _reql_lua_get_nearest},
  {"group", _reql_lua_group},
  {"gt", _reql_lua_gt},
  {"has_fields", _reql_lua_has_fields},
  {"hours", _reql_lua_hours},
  {"http", _reql_lua_http},
  {"implicit_var", _reql_lua_implicit_var},
  {"includes", _reql_lua_includes},
  {"indexes_of", _reql_lua_indexes_of},
  {"index_create", _reql_lua_index_create},
  {"index_drop", _reql_lua_index_drop},
  {"index_list", _reql_lua_index_list},
  {"index_rename", _reql_lua_index_rename},
  {"index_status", _reql_lua_index_status},
  {"index_wait", _reql_lua_index_wait},
  {"info", _reql_lua_info},
  {"inner_join", _reql_lua_inner_join},
  {"insert", _reql_lua_insert},
  {"insert_at", _reql_lua_insert_at},
  {"intersects", _reql_lua_intersects},
  {"in_timezone", _reql_lua_in_timezone},
  {"iso8601", _reql_lua_iso8601},
  {"is_empty", _reql_lua_is_empty},
  {"january", _reql_lua_january},
  {"javascript", _reql_lua_javascript},
  {"json", _reql_lua_json},
  {"july", _reql_lua_july},
  {"june", _reql_lua_june},
  {"keys", _reql_lua_keys},
  {"le", _reql_lua_le},
  {"limit", _reql_lua_limit},
  {"line", _reql_lua_line},
  {"literal", _reql_lua_literal},
  {"lt", _reql_lua_lt},
  {"make_array", _reql_lua_make_array},
  {"make_obj", _reql_lua_make_obj},
  {"map", _reql_lua_map},
  {"march", _reql_lua_march},
  {"match", _reql_lua_match},
  {"max", _reql_lua_max},
  {"may", _reql_lua_may},
  {"merge", _reql_lua_merge},
  {"min", _reql_lua_min},
  {"minutes", _reql_lua_minutes},
  {"mod", _reql_lua_mod},
  {"monday", _reql_lua_monday},
  {"month", _reql_lua_month},
  {"mul", _reql_lua_mul},
  {"ne", _reql_lua_ne},
  {"not_", _reql_lua_not},
  {"november", _reql_lua_november},
  {"now", _reql_lua_now},
  {"nth", _reql_lua_nth},
  {"object", _reql_lua_object},
  {"october", _reql_lua_october},
  {"order_by", _reql_lua_order_by},
  {"outer_join", _reql_lua_outer_join},
  {"pluck", _reql_lua_pluck},
  {"point", _reql_lua_point},
  {"polygon", _reql_lua_polygon},
  {"polygon_sub", _reql_lua_polygon_sub},
  {"prepend", _reql_lua_prepend},
  {"random", _reql_lua_random},
  {"range", _reql_lua_range},
  {"rebalance", _reql_lua_rebalance},
  {"reconfigure", _reql_lua_reconfigure},
  {"reduce", _reql_lua_reduce},
  {"replace", _reql_lua_replace},
  {"sample", _reql_lua_sample},
  {"saturday", _reql_lua_saturday},
  {"seconds", _reql_lua_seconds},
  {"september", _reql_lua_september},
  {"set_difference", _reql_lua_set_difference},
  {"set_insert", _reql_lua_set_insert},
  {"set_intersection", _reql_lua_set_intersection},
  {"set_union", _reql_lua_set_union},
  {"skip", _reql_lua_skip},
  {"slice", _reql_lua_slice},
  {"splice_at", _reql_lua_splice_at},
  {"split", _reql_lua_split},
  {"sub", _reql_lua_sub},
  {"sum", _reql_lua_sum},
  {"sunday", _reql_lua_sunday},
  {"sync", _reql_lua_sync},
  {"table", _reql_lua_table},
  {"table_config", _reql_lua_table_config},
  {"table_create", _reql_lua_table_create},
  {"table_drop", _reql_lua_table_drop},
  {"table_list", _reql_lua_table_list},
  {"table_status", _reql_lua_table_status},
  {"table_wait", _reql_lua_table_wait},
  {"thursday", _reql_lua_thursday},
  {"time", _reql_lua_time},
  {"timezone", _reql_lua_timezone},
  {"time_of_day", _reql_lua_time_of_day},
  {"to_epoch_time", _reql_lua_to_epoch_time},
  {"to_geojson", _reql_lua_to_geojson},
  {"to_iso8601", _reql_lua_to_iso8601},
  {"to_json_string", _reql_lua_to_json_string},
  {"tuesday", _reql_lua_tuesday},
  {"type_of", _reql_lua_type_of},
  {"ungroup", _reql_lua_ungroup},
  {"union", _reql_lua_union},
  {"upcase", _reql_lua_upcase},
  {"update", _reql_lua_update},
  {"uuid", _reql_lua_uuid},
  {"var", _reql_lua_var},
  {"wednesday", _reql_lua_wednesday},
  {"without", _reql_lua_without},
  {"with_fields", _reql_lua_with_fields},
  {"year", _reql_lua_year},
  {"zip", _reql_lua_zip},
  {NULL, NULL}
};

extern int luaopen_libReQL(lua_State *L) {
  luaL_newlib(L, libReQL);
  return 1;
}
