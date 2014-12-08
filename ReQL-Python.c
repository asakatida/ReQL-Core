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

#include "ReQL-ast-Python.h"

static PyMethodDef libReQLMethods[] = {
  {"expr", (PyCFunction)_reql_py_expr, METH_VARARGS, NULL},
  {"add", (PyCFunction)_reql_py_add, METH_VARARGS | METH_KEYWORDS, NULL},
  {"all", (PyCFunction)_reql_py_all, METH_VARARGS | METH_KEYWORDS, NULL},
  {"any", (PyCFunction)_reql_py_any, METH_VARARGS | METH_KEYWORDS, NULL},
  {"append", (PyCFunction)_reql_py_append, METH_VARARGS | METH_KEYWORDS, NULL},
  {"april", (PyCFunction)_reql_py_april, METH_VARARGS | METH_KEYWORDS, NULL},
  {"args", (PyCFunction)_reql_py_args, METH_VARARGS | METH_KEYWORDS, NULL},
  {"asc", (PyCFunction)_reql_py_asc, METH_VARARGS | METH_KEYWORDS, NULL},
  {"august", (PyCFunction)_reql_py_august, METH_VARARGS | METH_KEYWORDS, NULL},
  {"avg", (PyCFunction)_reql_py_avg, METH_VARARGS | METH_KEYWORDS, NULL},
  {"between", (PyCFunction)_reql_py_between, METH_VARARGS | METH_KEYWORDS, NULL},
  {"binary", (PyCFunction)_reql_py_binary, METH_VARARGS | METH_KEYWORDS, NULL},
  {"bracket", (PyCFunction)_reql_py_bracket, METH_VARARGS | METH_KEYWORDS, NULL},
  {"branch", (PyCFunction)_reql_py_branch, METH_VARARGS | METH_KEYWORDS, NULL},
  {"changes", (PyCFunction)_reql_py_changes, METH_VARARGS | METH_KEYWORDS, NULL},
  {"change_at", (PyCFunction)_reql_py_change_at, METH_VARARGS | METH_KEYWORDS, NULL},
  {"circle", (PyCFunction)_reql_py_circle, METH_VARARGS | METH_KEYWORDS, NULL},
  {"coerce_to", (PyCFunction)_reql_py_coerce_to, METH_VARARGS | METH_KEYWORDS, NULL},
  {"concat_map", (PyCFunction)_reql_py_concat_map, METH_VARARGS | METH_KEYWORDS, NULL},
  {"contains", (PyCFunction)_reql_py_contains, METH_VARARGS | METH_KEYWORDS, NULL},
  {"count", (PyCFunction)_reql_py_count, METH_VARARGS | METH_KEYWORDS, NULL},
  {"date", (PyCFunction)_reql_py_date, METH_VARARGS | METH_KEYWORDS, NULL},
  {"datum", (PyCFunction)_reql_py_datum, METH_VARARGS | METH_KEYWORDS, NULL},
  {"day", (PyCFunction)_reql_py_day, METH_VARARGS | METH_KEYWORDS, NULL},
  {"day_of_week", (PyCFunction)_reql_py_day_of_week, METH_VARARGS | METH_KEYWORDS, NULL},
  {"day_of_year", (PyCFunction)_reql_py_day_of_year, METH_VARARGS | METH_KEYWORDS, NULL},
  {"db", (PyCFunction)_reql_py_db, METH_VARARGS | METH_KEYWORDS, NULL},
  {"db_create", (PyCFunction)_reql_py_db_create, METH_VARARGS | METH_KEYWORDS, NULL},
  {"db_drop", (PyCFunction)_reql_py_db_drop, METH_VARARGS | METH_KEYWORDS, NULL},
  {"db_list", (PyCFunction)_reql_py_db_list, METH_VARARGS | METH_KEYWORDS, NULL},
  {"december", (PyCFunction)_reql_py_december, METH_VARARGS | METH_KEYWORDS, NULL},
  {"default", (PyCFunction)_reql_py_default, METH_VARARGS | METH_KEYWORDS, NULL},
  {"delete", (PyCFunction)_reql_py_delete, METH_VARARGS | METH_KEYWORDS, NULL},
  {"delete_at", (PyCFunction)_reql_py_delete_at, METH_VARARGS | METH_KEYWORDS, NULL},
  {"desc", (PyCFunction)_reql_py_desc, METH_VARARGS | METH_KEYWORDS, NULL},
  {"difference", (PyCFunction)_reql_py_difference, METH_VARARGS | METH_KEYWORDS, NULL},
  {"distance", (PyCFunction)_reql_py_distance, METH_VARARGS | METH_KEYWORDS, NULL},
  {"distinct", (PyCFunction)_reql_py_distinct, METH_VARARGS | METH_KEYWORDS, NULL},
  {"div", (PyCFunction)_reql_py_div, METH_VARARGS | METH_KEYWORDS, NULL},
  {"downcase", (PyCFunction)_reql_py_downcase, METH_VARARGS | METH_KEYWORDS, NULL},
  {"during", (PyCFunction)_reql_py_during, METH_VARARGS | METH_KEYWORDS, NULL},
  {"epoch_time", (PyCFunction)_reql_py_epoch_time, METH_VARARGS | METH_KEYWORDS, NULL},
  {"eq", (PyCFunction)_reql_py_eq, METH_VARARGS | METH_KEYWORDS, NULL},
  {"eq_join", (PyCFunction)_reql_py_eq_join, METH_VARARGS | METH_KEYWORDS, NULL},
  {"error", (PyCFunction)_reql_py_error, METH_VARARGS | METH_KEYWORDS, NULL},
  {"february", (PyCFunction)_reql_py_february, METH_VARARGS | METH_KEYWORDS, NULL},
  {"fill", (PyCFunction)_reql_py_fill, METH_VARARGS | METH_KEYWORDS, NULL},
  {"filter", (PyCFunction)_reql_py_filter, METH_VARARGS | METH_KEYWORDS, NULL},
  {"for_each", (PyCFunction)_reql_py_for_each, METH_VARARGS | METH_KEYWORDS, NULL},
  {"friday", (PyCFunction)_reql_py_friday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"func", (PyCFunction)_reql_py_func, METH_VARARGS | METH_KEYWORDS, NULL},
  {"funcall", (PyCFunction)_reql_py_funcall, METH_VARARGS | METH_KEYWORDS, NULL},
  {"ge", (PyCFunction)_reql_py_ge, METH_VARARGS | METH_KEYWORDS, NULL},
  {"geojson", (PyCFunction)_reql_py_geojson, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get", (PyCFunction)_reql_py_get, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get_all", (PyCFunction)_reql_py_get_all, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get_field", (PyCFunction)_reql_py_get_field, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get_intersecting", (PyCFunction)_reql_py_get_intersecting, METH_VARARGS | METH_KEYWORDS, NULL},
  {"get_nearest", (PyCFunction)_reql_py_get_nearest, METH_VARARGS | METH_KEYWORDS, NULL},
  {"group", (PyCFunction)_reql_py_group, METH_VARARGS | METH_KEYWORDS, NULL},
  {"gt", (PyCFunction)_reql_py_gt, METH_VARARGS | METH_KEYWORDS, NULL},
  {"has_fields", (PyCFunction)_reql_py_has_fields, METH_VARARGS | METH_KEYWORDS, NULL},
  {"hours", (PyCFunction)_reql_py_hours, METH_VARARGS | METH_KEYWORDS, NULL},
  {"http", (PyCFunction)_reql_py_http, METH_VARARGS | METH_KEYWORDS, NULL},
  {"implicit_var", (PyCFunction)_reql_py_implicit_var, METH_VARARGS | METH_KEYWORDS, NULL},
  {"includes", (PyCFunction)_reql_py_includes, METH_VARARGS | METH_KEYWORDS, NULL},
  {"indexes_of", (PyCFunction)_reql_py_indexes_of, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_create", (PyCFunction)_reql_py_index_create, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_drop", (PyCFunction)_reql_py_index_drop, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_list", (PyCFunction)_reql_py_index_list, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_rename", (PyCFunction)_reql_py_index_rename, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_status", (PyCFunction)_reql_py_index_status, METH_VARARGS | METH_KEYWORDS, NULL},
  {"index_wait", (PyCFunction)_reql_py_index_wait, METH_VARARGS | METH_KEYWORDS, NULL},
  {"info", (PyCFunction)_reql_py_info, METH_VARARGS | METH_KEYWORDS, NULL},
  {"inner_join", (PyCFunction)_reql_py_inner_join, METH_VARARGS | METH_KEYWORDS, NULL},
  {"insert", (PyCFunction)_reql_py_insert, METH_VARARGS | METH_KEYWORDS, NULL},
  {"insert_at", (PyCFunction)_reql_py_insert_at, METH_VARARGS | METH_KEYWORDS, NULL},
  {"intersects", (PyCFunction)_reql_py_intersects, METH_VARARGS | METH_KEYWORDS, NULL},
  {"timezone", (PyCFunction)_reql_py_in_timezone, METH_VARARGS | METH_KEYWORDS, NULL},
  {"iso8601", (PyCFunction)_reql_py_iso8601, METH_VARARGS | METH_KEYWORDS, NULL},
  {"is_empty", (PyCFunction)_reql_py_is_empty, METH_VARARGS | METH_KEYWORDS, NULL},
  {"january", (PyCFunction)_reql_py_january, METH_VARARGS | METH_KEYWORDS, NULL},
  {"javascript", (PyCFunction)_reql_py_javascript, METH_VARARGS | METH_KEYWORDS, NULL},
  {"json", (PyCFunction)_reql_py_json, METH_VARARGS | METH_KEYWORDS, NULL},
  {"july", (PyCFunction)_reql_py_july, METH_VARARGS | METH_KEYWORDS, NULL},
  {"june", (PyCFunction)_reql_py_june, METH_VARARGS | METH_KEYWORDS, NULL},
  {"keys", (PyCFunction)_reql_py_keys, METH_VARARGS | METH_KEYWORDS, NULL},
  {"le", (PyCFunction)_reql_py_le, METH_VARARGS | METH_KEYWORDS, NULL},
  {"limit", (PyCFunction)_reql_py_limit, METH_VARARGS | METH_KEYWORDS, NULL},
  {"line", (PyCFunction)_reql_py_line, METH_VARARGS | METH_KEYWORDS, NULL},
  {"literal", (PyCFunction)_reql_py_literal, METH_VARARGS | METH_KEYWORDS, NULL},
  {"lt", (PyCFunction)_reql_py_lt, METH_VARARGS | METH_KEYWORDS, NULL},
  {"make_array", (PyCFunction)_reql_py_make_array, METH_VARARGS | METH_KEYWORDS, NULL},
  {"make_obj", (PyCFunction)_reql_py_make_obj, METH_VARARGS | METH_KEYWORDS, NULL},
  {"map", (PyCFunction)_reql_py_map, METH_VARARGS | METH_KEYWORDS, NULL},
  {"march", (PyCFunction)_reql_py_march, METH_VARARGS | METH_KEYWORDS, NULL},
  {"match", (PyCFunction)_reql_py_match, METH_VARARGS | METH_KEYWORDS, NULL},
  {"max", (PyCFunction)_reql_py_max, METH_VARARGS | METH_KEYWORDS, NULL},
  {"may", (PyCFunction)_reql_py_may, METH_VARARGS | METH_KEYWORDS, NULL},
  {"merge", (PyCFunction)_reql_py_merge, METH_VARARGS | METH_KEYWORDS, NULL},
  {"min", (PyCFunction)_reql_py_min, METH_VARARGS | METH_KEYWORDS, NULL},
  {"minutes", (PyCFunction)_reql_py_minutes, METH_VARARGS | METH_KEYWORDS, NULL},
  {"mod", (PyCFunction)_reql_py_mod, METH_VARARGS | METH_KEYWORDS, NULL},
  {"monday", (PyCFunction)_reql_py_monday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"month", (PyCFunction)_reql_py_month, METH_VARARGS | METH_KEYWORDS, NULL},
  {"mul", (PyCFunction)_reql_py_mul, METH_VARARGS | METH_KEYWORDS, NULL},
  {"ne", (PyCFunction)_reql_py_ne, METH_VARARGS | METH_KEYWORDS, NULL},
  {"not_", (PyCFunction)_reql_py_not, METH_VARARGS | METH_KEYWORDS, NULL},
  {"november", (PyCFunction)_reql_py_november, METH_VARARGS | METH_KEYWORDS, NULL},
  {"now", (PyCFunction)_reql_py_now, METH_VARARGS | METH_KEYWORDS, NULL},
  {"nth", (PyCFunction)_reql_py_nth, METH_VARARGS | METH_KEYWORDS, NULL},
  {"object", (PyCFunction)_reql_py_object, METH_VARARGS | METH_KEYWORDS, NULL},
  {"october", (PyCFunction)_reql_py_october, METH_VARARGS | METH_KEYWORDS, NULL},
  {"order_by", (PyCFunction)_reql_py_order_by, METH_VARARGS | METH_KEYWORDS, NULL},
  {"outer_join", (PyCFunction)_reql_py_outer_join, METH_VARARGS | METH_KEYWORDS, NULL},
  {"pluck", (PyCFunction)_reql_py_pluck, METH_VARARGS | METH_KEYWORDS, NULL},
  {"point", (PyCFunction)_reql_py_point, METH_VARARGS | METH_KEYWORDS, NULL},
  {"polygon", (PyCFunction)_reql_py_polygon, METH_VARARGS | METH_KEYWORDS, NULL},
  {"polygon_sub", (PyCFunction)_reql_py_polygon_sub, METH_VARARGS | METH_KEYWORDS, NULL},
  {"prepend", (PyCFunction)_reql_py_prepend, METH_VARARGS | METH_KEYWORDS, NULL},
  {"random", (PyCFunction)_reql_py_random, METH_VARARGS | METH_KEYWORDS, NULL},
  {"range", (PyCFunction)_reql_py_range, METH_VARARGS | METH_KEYWORDS, NULL},
  {"reduce", (PyCFunction)_reql_py_reduce, METH_VARARGS | METH_KEYWORDS, NULL},
  {"replace", (PyCFunction)_reql_py_replace, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sample", (PyCFunction)_reql_py_sample, METH_VARARGS | METH_KEYWORDS, NULL},
  {"saturday", (PyCFunction)_reql_py_saturday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"seconds", (PyCFunction)_reql_py_seconds, METH_VARARGS | METH_KEYWORDS, NULL},
  {"september", (PyCFunction)_reql_py_september, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_difference", (PyCFunction)_reql_py_set_difference, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_insert", (PyCFunction)_reql_py_set_insert, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_intersection", (PyCFunction)_reql_py_set_intersection, METH_VARARGS | METH_KEYWORDS, NULL},
  {"set_union", (PyCFunction)_reql_py_set_union, METH_VARARGS | METH_KEYWORDS, NULL},
  {"skip", (PyCFunction)_reql_py_skip, METH_VARARGS | METH_KEYWORDS, NULL},
  {"slice", (PyCFunction)_reql_py_slice, METH_VARARGS | METH_KEYWORDS, NULL},
  {"splice_at", (PyCFunction)_reql_py_splice_at, METH_VARARGS | METH_KEYWORDS, NULL},
  {"split", (PyCFunction)_reql_py_split, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sub", (PyCFunction)_reql_py_sub, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sum", (PyCFunction)_reql_py_sum, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sunday", (PyCFunction)_reql_py_sunday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"sync", (PyCFunction)_reql_py_sync, METH_VARARGS | METH_KEYWORDS, NULL},
  {"table", (PyCFunction)_reql_py_table, METH_VARARGS | METH_KEYWORDS, NULL},
  {"table_create", (PyCFunction)_reql_py_table_create, METH_VARARGS | METH_KEYWORDS, NULL},
  {"table_drop", (PyCFunction)_reql_py_table_drop, METH_VARARGS | METH_KEYWORDS, NULL},
  {"table_list", (PyCFunction)_reql_py_table_list, METH_VARARGS | METH_KEYWORDS, NULL},
  {"thursday", (PyCFunction)_reql_py_thursday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"time", (PyCFunction)_reql_py_time, METH_VARARGS | METH_KEYWORDS, NULL},
  {"timezone", (PyCFunction)_reql_py_timezone, METH_VARARGS | METH_KEYWORDS, NULL},
  {"time_of_day", (PyCFunction)_reql_py_time_of_day, METH_VARARGS | METH_KEYWORDS, NULL},
  {"to_epoch_time", (PyCFunction)_reql_py_to_epoch_time, METH_VARARGS | METH_KEYWORDS, NULL},
  {"to_geojson", (PyCFunction)_reql_py_to_geojson, METH_VARARGS | METH_KEYWORDS, NULL},
  {"to_iso8601", (PyCFunction)_reql_py_to_iso8601, METH_VARARGS | METH_KEYWORDS, NULL},
  {"to_json_string", (PyCFunction)_reql_py_to_json_string, METH_VARARGS | METH_KEYWORDS, NULL},
  {"tuesday", (PyCFunction)_reql_py_tuesday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"type_of", (PyCFunction)_reql_py_type_of, METH_VARARGS | METH_KEYWORDS, NULL},
  {"ungroup", (PyCFunction)_reql_py_ungroup, METH_VARARGS | METH_KEYWORDS, NULL},
  {"union", (PyCFunction)_reql_py_union, METH_VARARGS | METH_KEYWORDS, NULL},
  {"upcase", (PyCFunction)_reql_py_upcase, METH_VARARGS | METH_KEYWORDS, NULL},
  {"update", (PyCFunction)_reql_py_update, METH_VARARGS | METH_KEYWORDS, NULL},
  {"uuid", (PyCFunction)_reql_py_uuid, METH_VARARGS | METH_KEYWORDS, NULL},
  {"var", (PyCFunction)_reql_py_var, METH_VARARGS | METH_KEYWORDS, NULL},
  {"wednesday", (PyCFunction)_reql_py_wednesday, METH_VARARGS | METH_KEYWORDS, NULL},
  {"without", (PyCFunction)_reql_py_without, METH_VARARGS | METH_KEYWORDS, NULL},
  {"with_fields", (PyCFunction)_reql_py_with_fields, METH_VARARGS | METH_KEYWORDS, NULL},
  {"year", (PyCFunction)_reql_py_year, METH_VARARGS | METH_KEYWORDS, NULL},
  {"zip", (PyCFunction)_reql_py_zip, METH_VARARGS | METH_KEYWORDS, NULL},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef libReQLModule = {
  PyModuleDef_HEAD_INIT,
  "libReQL",
  NULL,
  0,
  libReQLMethods
};

PyMODINIT_FUNC
PyInit_libreql(void) {
  PyObject* m;
  m = PyModule_Create(&libReQLModule);

  if (!m) {
    return NULL;
  }

  return m;
}
