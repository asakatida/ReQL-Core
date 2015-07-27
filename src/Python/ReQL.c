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

#define Py_LIMITED_API
#include "Python.h"

#include "./Python/connection.h"
#include "./Python/query.h"

#include <stdlib.h>

#if PY_MAJOR_VERSION < 3
#define ReQLModule
#define ReQLInitFuncName initlibReQL
#define ReQLInitCall Py_InitModule("libReQL", libReQLMethods)
#else
#define ReQLModule static struct PyModuleDef libReQLModule = {\
  PyModuleDef_HEAD_INIT,\
  "libReQL",\
  NULL,\
  0,\
  libReQLMethods\
}
#define ReQLInitFuncName PyInit_libreql
#define ReQLInitCall PyModule_Create(&libReQLModule)
#endif

static PyMethodDef libReQLMethods[] = {
  {"expr", reql_py_expr, METH_VARARGS, NULL},
  {"connect", (PyCFunction)reql_py_connect, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_loop_type", (PyCFunction)NULL, METH_VARARGS, NULL},
  {"add", (PyCFunction)reql_py_add, METH_VARARGS | METH_KEYWORDS, NULL},
  {"and_", (PyCFunction)reql_py_and, METH_VARARGS | METH_KEYWORDS, NULL},
  {"append", (PyCFunction)reql_py_append, METH_VARARGS | METH_KEYWORDS, NULL},
  {"april", (PyCFunction)reql_py_april, METH_VARARGS | METH_KEYWORDS, NULL},
  {"args", (PyCFunction)reql_py_args, METH_VARARGS | METH_KEYWORDS, NULL},
  {"asc", (PyCFunction)reql_py_asc, METH_VARARGS | METH_KEYWORDS, NULL},
  {"august", (PyCFunction)reql_py_august, METH_VARARGS | METH_KEYWORDS, NULL},
  {"avg", (PyCFunction)reql_py_avg, METH_VARARGS | METH_KEYWORDS, NULL},
  {"between", (PyCFunction)reql_py_between, METH_VARARGS | METH_KEYWORDS, NULL},
  {"between_deprecated", (PyCFunction)reql_py_between_deprecated, METH_VARARGS | METH_KEYWORDS, NULL},
  {"binary", (PyCFunction)reql_py_binary, METH_VARARGS | METH_KEYWORDS, NULL},
  {"bracket", (PyCFunction)reql_py_bracket, METH_VARARGS | METH_KEYWORDS, NULL},
  {"branch", (PyCFunction)reql_py_branch, METH_VARARGS | METH_KEYWORDS, NULL},
  {"ceil", (PyCFunction)reql_py_ceil, METH_VARARGS | METH_KEYWORDS, NULL},
  {"changes", (PyCFunction)reql_py_changes, METH_VARARGS | METH_KEYWORDS, NULL},
  {"change_at", (PyCFunction)reql_py_change_at, METH_VARARGS | METH_KEYWORDS, NULL},
  {"circle", (PyCFunction)reql_py_circle, METH_VARARGS | METH_KEYWORDS, NULL},
  {"coerce_to", (PyCFunction)reql_py_coerce_to, METH_VARARGS | METH_KEYWORDS, NULL},
  {"concat_map", (PyCFunction)reql_py_concat_map, METH_VARARGS | METH_KEYWORDS, NULL},
  {"config", (PyCFunction)reql_py_config, METH_VARARGS | METH_KEYWORDS, NULL},
  {"contains", (PyCFunction)reql_py_contains, METH_VARARGS | METH_KEYWORDS, NULL},
  {"count", (PyCFunction)reql_py_count, METH_VARARGS | METH_KEYWORDS, NULL},
  {"date", (PyCFunction)reql_py_date, METH_VARARGS | METH_KEYWORDS, NULL},
  {"datum", (PyCFunction)reql_py_datum, METH_VARARGS | METH_KEYWORDS, NULL},
  {"day", (PyCFunction)reql_py_day, METH_VARARGS | METH_KEYWORDS, NULL},
  {"day_of_week", (PyCFunction)reql_py_day_of_week, METH_VARARGS | METH_KEYWORDS, NULL},
  {"day_of_year", (PyCFunction)reql_py_day_of_year, METH_VARARGS | METH_KEYWORDS, NULL},
  {"db", (PyCFunction)reql_py_db, METH_VARARGS | METH_KEYWORDS, NULL},
  {"db_create", (PyCFunction)reql_py_db_create, METH_VARARGS | METH_KEYWORDS, NULL},
  {"db_drop", (PyCFunction)reql_py_db_drop, METH_VARARGS | METH_KEYWORDS, NULL},
  {"db_list", (PyCFunction)reql_py_db_list, METH_VARARGS | METH_KEYWORDS, NULL},
  {"december", (PyCFunction)reql_py_december, METH_VARARGS | METH_KEYWORDS, NULL},
  {"default", (PyCFunction)reql_py_default, METH_VARARGS | METH_KEYWORDS, NULL},
  {"delete", (PyCFunction)reql_py_delete, METH_VARARGS | METH_KEYWORDS, NULL},
  {"delete_at", (PyCFunction)reql_py_delete_at, METH_VARARGS | METH_KEYWORDS, NULL},
  {"desc", (PyCFunction)reql_py_desc, METH_VARARGS | METH_KEYWORDS, NULL},
  {"difference", (PyCFunction)reql_py_difference, METH_VARARGS | METH_KEYWORDS, NULL},
  {"distance", (PyCFunction)reql_py_distance, METH_VARARGS | METH_KEYWORDS, NULL},
  {"distinct", (PyCFunction)reql_py_distinct, METH_VARARGS | METH_KEYWORDS, NULL},
  {"div", (PyCFunction)reql_py_div, METH_VARARGS | METH_KEYWORDS, NULL},
  {"downcase", (PyCFunction)reql_py_downcase, METH_VARARGS | METH_KEYWORDS, NULL},
  {"during", (PyCFunction)reql_py_during, METH_VARARGS | METH_KEYWORDS, NULL},
  {"epoch_time", (PyCFunction)reql_py_epoch_time, METH_VARARGS | METH_KEYWORDS, NULL},
  {"eq", (PyCFunction)reql_py_eq, METH_VARARGS | METH_KEYWORDS, NULL},
  {"eq_join", (PyCFunction)reql_py_eq_join, METH_VARARGS | METH_KEYWORDS, NULL},
  {"error", (PyCFunction)reql_py_error, METH_VARARGS | METH_KEYWORDS, NULL},
  {"february", (PyCFunction)reql_py_february, METH_VARARGS | METH_KEYWORDS, NULL},
  {"fill", (PyCFunction)reql_py_fill, METH_VARARGS | METH_KEYWORDS, NULL},
  {"filter", (PyCFunction)reql_py_filter, METH_VARARGS | METH_KEYWORDS, NULL},
  {"floor", (PyCFunction)reql_py_floor, METH_VARARGS | METH_KEYWORDS, NULL},
  {"for_each", (PyCFunction)reql_py_for_each, METH_VARARGS | METH_KEYWORDS, NULL},
  {"friday", (PyCFunction)reql_py_friday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"func", (PyCFunction)reql_py_func, METH_VARARGS | METH_KEYWORDS, NULL},
  {"funcall", (PyCFunction)reql_py_funcall, METH_VARARGS | METH_KEYWORDS, NULL},
  {"ge", (PyCFunction)reql_py_ge, METH_VARARGS | METH_KEYWORDS, NULL},
  {"geojson", (PyCFunction)reql_py_geojson, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get", (PyCFunction)reql_py_get, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get_all", (PyCFunction)reql_py_get_all, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get_field", (PyCFunction)reql_py_get_field, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get_intersecting", (PyCFunction)reql_py_get_intersecting, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get_nearest", (PyCFunction)reql_py_get_nearest, METH_VARARGS | METH_KEYWORDS, NULL},
  {"group", (PyCFunction)reql_py_group, METH_VARARGS | METH_KEYWORDS, NULL},
  {"gt", (PyCFunction)reql_py_gt, METH_VARARGS | METH_KEYWORDS, NULL},
  {"has_fields", (PyCFunction)reql_py_has_fields, METH_VARARGS | METH_KEYWORDS, NULL},
  {"hours", (PyCFunction)reql_py_hours, METH_VARARGS | METH_KEYWORDS, NULL},
  {"http", (PyCFunction)reql_py_http, METH_VARARGS | METH_KEYWORDS, NULL},
  {"implicit_var", (PyCFunction)reql_py_implicit_var, METH_VARARGS | METH_KEYWORDS, NULL},
  {"includes", (PyCFunction)reql_py_includes, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_create", (PyCFunction)reql_py_index_create, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_drop", (PyCFunction)reql_py_index_drop, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_list", (PyCFunction)reql_py_index_list, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_rename", (PyCFunction)reql_py_index_rename, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_status", (PyCFunction)reql_py_index_status, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_wait", (PyCFunction)reql_py_index_wait, METH_VARARGS | METH_KEYWORDS, NULL},
  {"info", (PyCFunction)reql_py_info, METH_VARARGS | METH_KEYWORDS, NULL},
  {"inner_join", (PyCFunction)reql_py_inner_join, METH_VARARGS | METH_KEYWORDS, NULL},
  {"insert", (PyCFunction)reql_py_insert, METH_VARARGS | METH_KEYWORDS, NULL},
  {"insert_at", (PyCFunction)reql_py_insert_at, METH_VARARGS | METH_KEYWORDS, NULL},
  {"intersects", (PyCFunction)reql_py_intersects, METH_VARARGS | METH_KEYWORDS, NULL},
  {"in_timezone", (PyCFunction)reql_py_in_timezone, METH_VARARGS | METH_KEYWORDS, NULL},
  {"iso8601", (PyCFunction)reql_py_iso8601, METH_VARARGS | METH_KEYWORDS, NULL},
  {"is_empty", (PyCFunction)reql_py_is_empty, METH_VARARGS | METH_KEYWORDS, NULL},
  {"january", (PyCFunction)reql_py_january, METH_VARARGS | METH_KEYWORDS, NULL},
  {"javascript", (PyCFunction)reql_py_javascript, METH_VARARGS | METH_KEYWORDS, NULL},
  {"json", (PyCFunction)reql_py_json, METH_VARARGS | METH_KEYWORDS, NULL},
  {"july", (PyCFunction)reql_py_july, METH_VARARGS | METH_KEYWORDS, NULL},
  {"june", (PyCFunction)reql_py_june, METH_VARARGS | METH_KEYWORDS, NULL},
  {"keys", (PyCFunction)reql_py_keys, METH_VARARGS | METH_KEYWORDS, NULL},
  {"le", (PyCFunction)reql_py_le, METH_VARARGS | METH_KEYWORDS, NULL},
  {"limit", (PyCFunction)reql_py_limit, METH_VARARGS | METH_KEYWORDS, NULL},
  {"line", (PyCFunction)reql_py_line, METH_VARARGS | METH_KEYWORDS, NULL},
  {"literal", (PyCFunction)reql_py_literal, METH_VARARGS | METH_KEYWORDS, NULL},
  {"lt", (PyCFunction)reql_py_lt, METH_VARARGS | METH_KEYWORDS, NULL},
  {"make_array", (PyCFunction)reql_py_make_array, METH_VARARGS | METH_KEYWORDS, NULL},
  {"make_obj", (PyCFunction)reql_py_make_obj, METH_VARARGS | METH_KEYWORDS, NULL},
  {"map", (PyCFunction)reql_py_map, METH_VARARGS | METH_KEYWORDS, NULL},
  {"march", (PyCFunction)reql_py_march, METH_VARARGS | METH_KEYWORDS, NULL},
  {"match", (PyCFunction)reql_py_match, METH_VARARGS | METH_KEYWORDS, NULL},
  {"max", (PyCFunction)reql_py_max, METH_VARARGS | METH_KEYWORDS, NULL},
  {"maxval", (PyCFunction)reql_py_maxval, METH_VARARGS | METH_KEYWORDS, NULL},
  {"may", (PyCFunction)reql_py_may, METH_VARARGS | METH_KEYWORDS, NULL},
  {"merge", (PyCFunction)reql_py_merge, METH_VARARGS | METH_KEYWORDS, NULL},
  {"min", (PyCFunction)reql_py_min, METH_VARARGS | METH_KEYWORDS, NULL},
  {"minutes", (PyCFunction)reql_py_minutes, METH_VARARGS | METH_KEYWORDS, NULL},
  {"minval", (PyCFunction)reql_py_minval, METH_VARARGS | METH_KEYWORDS, NULL},
  {"mod", (PyCFunction)reql_py_mod, METH_VARARGS | METH_KEYWORDS, NULL},
  {"monday", (PyCFunction)reql_py_monday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"month", (PyCFunction)reql_py_month, METH_VARARGS | METH_KEYWORDS, NULL},
  {"mul", (PyCFunction)reql_py_mul, METH_VARARGS | METH_KEYWORDS, NULL},
  {"ne", (PyCFunction)reql_py_ne, METH_VARARGS | METH_KEYWORDS, NULL},
  {"not_", (PyCFunction)reql_py_not, METH_VARARGS | METH_KEYWORDS, NULL},
  {"november", (PyCFunction)reql_py_november, METH_VARARGS | METH_KEYWORDS, NULL},
  {"now", (PyCFunction)reql_py_now, METH_VARARGS | METH_KEYWORDS, NULL},
  {"nth", (PyCFunction)reql_py_nth, METH_VARARGS | METH_KEYWORDS, NULL},
  {"object", (PyCFunction)reql_py_object, METH_VARARGS | METH_KEYWORDS, NULL},
  {"october", (PyCFunction)reql_py_october, METH_VARARGS | METH_KEYWORDS, NULL},
  {"offsets_of", (PyCFunction)reql_py_offsets_of, METH_VARARGS | METH_KEYWORDS, NULL},
  {"or_", (PyCFunction)reql_py_or, METH_VARARGS | METH_KEYWORDS, NULL},
  {"order_by", (PyCFunction)reql_py_order_by, METH_VARARGS | METH_KEYWORDS, NULL},
  {"outer_join", (PyCFunction)reql_py_outer_join, METH_VARARGS | METH_KEYWORDS, NULL},
  {"pluck", (PyCFunction)reql_py_pluck, METH_VARARGS | METH_KEYWORDS, NULL},
  {"point", (PyCFunction)reql_py_point, METH_VARARGS | METH_KEYWORDS, NULL},
  {"polygon", (PyCFunction)reql_py_polygon, METH_VARARGS | METH_KEYWORDS, NULL},
  {"polygon_sub", (PyCFunction)reql_py_polygon_sub, METH_VARARGS | METH_KEYWORDS, NULL},
  {"prepend", (PyCFunction)reql_py_prepend, METH_VARARGS | METH_KEYWORDS, NULL},
  {"random", (PyCFunction)reql_py_random, METH_VARARGS | METH_KEYWORDS, NULL},
  {"range", (PyCFunction)reql_py_range, METH_VARARGS | METH_KEYWORDS, NULL},
  {"rebalance", (PyCFunction)reql_py_rebalance, METH_VARARGS | METH_KEYWORDS, NULL},
  {"reconfigure", (PyCFunction)reql_py_reconfigure, METH_VARARGS | METH_KEYWORDS, NULL},
  {"reduce", (PyCFunction)reql_py_reduce, METH_VARARGS | METH_KEYWORDS, NULL},
  {"replace", (PyCFunction)reql_py_replace, METH_VARARGS | METH_KEYWORDS, NULL},
  {"round", (PyCFunction)reql_py_round, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sample", (PyCFunction)reql_py_sample, METH_VARARGS | METH_KEYWORDS, NULL},
  {"saturday", (PyCFunction)reql_py_saturday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"seconds", (PyCFunction)reql_py_seconds, METH_VARARGS | METH_KEYWORDS, NULL},
  {"september", (PyCFunction)reql_py_september, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_difference", (PyCFunction)reql_py_set_difference, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_insert", (PyCFunction)reql_py_set_insert, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_intersection", (PyCFunction)reql_py_set_intersection, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_union", (PyCFunction)reql_py_set_union, METH_VARARGS | METH_KEYWORDS, NULL},
  {"skip", (PyCFunction)reql_py_skip, METH_VARARGS | METH_KEYWORDS, NULL},
  {"slice", (PyCFunction)reql_py_slice, METH_VARARGS | METH_KEYWORDS, NULL},
  {"splice_at", (PyCFunction)reql_py_splice_at, METH_VARARGS | METH_KEYWORDS, NULL},
  {"split", (PyCFunction)reql_py_split, METH_VARARGS | METH_KEYWORDS, NULL},
  {"status", (PyCFunction)reql_py_status, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sub", (PyCFunction)reql_py_sub, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sum", (PyCFunction)reql_py_sum, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sunday", (PyCFunction)reql_py_sunday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sync", (PyCFunction)reql_py_sync, METH_VARARGS | METH_KEYWORDS, NULL},
  {"table", (PyCFunction)reql_py_table, METH_VARARGS | METH_KEYWORDS, NULL},
  {"table_create", (PyCFunction)reql_py_table_create, METH_VARARGS | METH_KEYWORDS, NULL},
  {"table_drop", (PyCFunction)reql_py_table_drop, METH_VARARGS | METH_KEYWORDS, NULL},
  {"table_list", (PyCFunction)reql_py_table_list, METH_VARARGS | METH_KEYWORDS, NULL},
  {"thursday", (PyCFunction)reql_py_thursday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"time", (PyCFunction)reql_py_time, METH_VARARGS | METH_KEYWORDS, NULL},
  {"timezone", (PyCFunction)reql_py_timezone, METH_VARARGS | METH_KEYWORDS, NULL},
  {"time_of_day", (PyCFunction)reql_py_time_of_day, METH_VARARGS | METH_KEYWORDS, NULL},
  {"to_epoch_time", (PyCFunction)reql_py_to_epoch_time, METH_VARARGS | METH_KEYWORDS, NULL},
  {"to_geojson", (PyCFunction)reql_py_to_geojson, METH_VARARGS | METH_KEYWORDS, NULL},
  {"to_iso8601", (PyCFunction)reql_py_to_iso8601, METH_VARARGS | METH_KEYWORDS, NULL},
  {"to_json_string", (PyCFunction)reql_py_to_json_string, METH_VARARGS | METH_KEYWORDS, NULL},
  {"tuesday", (PyCFunction)reql_py_tuesday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"type_of", (PyCFunction)reql_py_type_of, METH_VARARGS | METH_KEYWORDS, NULL},
  {"ungroup", (PyCFunction)reql_py_ungroup, METH_VARARGS | METH_KEYWORDS, NULL},
  {"union", (PyCFunction)reql_py_union, METH_VARARGS | METH_KEYWORDS, NULL},
  {"upcase", (PyCFunction)reql_py_upcase, METH_VARARGS | METH_KEYWORDS, NULL},
  {"update", (PyCFunction)reql_py_update, METH_VARARGS | METH_KEYWORDS, NULL},
  {"uuid", (PyCFunction)reql_py_uuid, METH_VARARGS | METH_KEYWORDS, NULL},
  {"var", (PyCFunction)reql_py_var, METH_VARARGS | METH_KEYWORDS, NULL},
  {"wait", (PyCFunction)reql_py_wait, METH_VARARGS | METH_KEYWORDS, NULL},
  {"wednesday", (PyCFunction)reql_py_wednesday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"without", (PyCFunction)reql_py_without, METH_VARARGS | METH_KEYWORDS, NULL},
  {"with_fields", (PyCFunction)reql_py_with_fields, METH_VARARGS | METH_KEYWORDS, NULL},
  {"year", (PyCFunction)reql_py_year, METH_VARARGS | METH_KEYWORDS, NULL},
  {"zip", (PyCFunction)reql_py_zip, METH_VARARGS | METH_KEYWORDS, NULL},
  {NULL, NULL, 0, NULL}
};

ReQLModule;

PyMODINIT_FUNC
ReQLInitFuncName(void) {
  PyObject* m;
  m = ReQLInitCall;

  if (!m) {
  }

#if PY_MAJOR_VERSION < 3
#else
  return m;
#endif
}
