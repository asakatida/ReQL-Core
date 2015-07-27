/*
Copyright 2015 Adam Grandquist

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

#include "Python.h"
#include "structmember.h"

#include "./Python/types.h"

#include "./Python/connection.h"
#include "./Python/query.h"

#include <stdlib.h>

extern void
reql_py_dealloc(PyObject* self) {
#if PY_MAJOR_VERSION < 3
  Py_TYPE(self)->tp_free(self);
#else
  ((freefunc)(PyType_GetSlot(Py_TYPE(self), Py_tp_free)))(self);
#endif
}

static PyMemberDef Connection_members[] = {
  {NULL}  /* Sentinel */
};

static PyMethodDef Connection_methods[] = {
  {"close", (PyCFunction)NULL, METH_NOARGS, ""},
  {"noreply_wait", (PyCFunction)NULL, METH_NOARGS, ""},
  {"reconnect", (PyCFunction)NULL, METH_NOARGS, ""},
  {"repl", (PyCFunction)NULL, METH_NOARGS, ""},
  {"use", (PyCFunction)NULL, METH_NOARGS, ""},
  {NULL}  /* Sentinel */
};

static PyTypeObject ReQLConnectionType = {
  PyVarObject_HEAD_INIT(NULL, 0)
  "libReQL.Connection",      /*tp_name*/
  sizeof(ReQLConnection),    /*tp_basicsize*/
  0,                         /*tp_itemsize*/
  (destructor)Connection_dealloc, /*tp_dealloc*/
  0,                         /*tp_print*/
  0,                         /*tp_getattr*/
  0,                         /*tp_setattr*/
  0,                         /*tp_compare*/
  0,                         /*tp_repr*/
  0,                         /*tp_as_number*/
  0,                         /*tp_as_sequence*/
  0,                         /*tp_as_mapping*/
  0,                         /*tp_hash */
  0,                         /*tp_call*/
  0,                         /*tp_str*/
  0,                         /*tp_getattro*/
  0,                         /*tp_setattro*/
  0,                         /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
  "",                        /* tp_doc */
  0,                         /* tp_traverse */
  0,                         /* tp_clear */
  0,                         /* tp_richcompare */
  0,                         /* tp_weaklistoffset */
  0,                         /* tp_iter */
  0,                         /* tp_iternext */
  Connection_methods,        /* tp_methods */
  Connection_members,        /* tp_members */
  0,                         /* tp_getset */
  0,                         /* tp_base */
  0,                         /* tp_dict */
  0,                         /* tp_descr_get */
  0,                         /* tp_descr_set */
  0,                         /* tp_dictoffset */
  (initproc)Connection_init, /* tp_init */
  0,                         /* tp_alloc */
  Connection_new,            /* tp_new */
};

PyTypeObject *
reql_py_connection_type() {
  return &ReQLConnectionType;
}

static PyMethodDef Query_methods[] = {
  {"run", (PyCFunction)reql_py_run, METH_VARARGS | METH_KEYWORDS, ""},
  {"add", (PyCFunction)reql_py_add_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"and", (PyCFunction)reql_py_and_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"append", (PyCFunction)reql_py_append_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"april", (PyCFunction)reql_py_april_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"args", (PyCFunction)reql_py_args_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"asc", (PyCFunction)reql_py_asc_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"august", (PyCFunction)reql_py_august_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"avg", (PyCFunction)reql_py_avg_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"between", (PyCFunction)reql_py_between_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"between_deprecated", (PyCFunction)reql_py_between_deprecated_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"binary", (PyCFunction)reql_py_binary_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"bracket", (PyCFunction)reql_py_bracket_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"branch", (PyCFunction)reql_py_branch_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"ceil", (PyCFunction)reql_py_ceil_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"changes", (PyCFunction)reql_py_changes_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"change_at", (PyCFunction)reql_py_change_at_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"circle", (PyCFunction)reql_py_circle_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"coerce_to", (PyCFunction)reql_py_coerce_to_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"concat_map", (PyCFunction)reql_py_concat_map_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"config", (PyCFunction)reql_py_config_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"contains", (PyCFunction)reql_py_contains_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"count", (PyCFunction)reql_py_count_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"date", (PyCFunction)reql_py_date_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"datum", (PyCFunction)reql_py_datum_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"day", (PyCFunction)reql_py_day_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"day_of_week", (PyCFunction)reql_py_day_of_week_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"day_of_year", (PyCFunction)reql_py_day_of_year_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"db", (PyCFunction)reql_py_db_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"db_create", (PyCFunction)reql_py_db_create_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"db_drop", (PyCFunction)reql_py_db_drop_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"db_list", (PyCFunction)reql_py_db_list_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"december", (PyCFunction)reql_py_december_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"default", (PyCFunction)reql_py_default_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"delete", (PyCFunction)reql_py_delete_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"delete_at", (PyCFunction)reql_py_delete_at_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"desc", (PyCFunction)reql_py_desc_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"difference", (PyCFunction)reql_py_difference_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"distance", (PyCFunction)reql_py_distance_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"distinct", (PyCFunction)reql_py_distinct_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"div", (PyCFunction)reql_py_div_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"downcase", (PyCFunction)reql_py_downcase_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"during", (PyCFunction)reql_py_during_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"epoch_time", (PyCFunction)reql_py_epoch_time_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"eq", (PyCFunction)reql_py_eq_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"eq_join", (PyCFunction)reql_py_eq_join_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"error", (PyCFunction)reql_py_error_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"february", (PyCFunction)reql_py_february_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"fill", (PyCFunction)reql_py_fill_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"filter", (PyCFunction)reql_py_filter_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"floor", (PyCFunction)reql_py_floor_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"for_each", (PyCFunction)reql_py_for_each_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"friday", (PyCFunction)reql_py_friday_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"func", (PyCFunction)reql_py_func_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"funcall", (PyCFunction)reql_py_funcall_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"ge", (PyCFunction)reql_py_ge_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"geojson", (PyCFunction)reql_py_geojson_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"get", (PyCFunction)reql_py_get_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"get_all", (PyCFunction)reql_py_get_all_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"get_field", (PyCFunction)reql_py_get_field_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"get_intersecting", (PyCFunction)reql_py_get_intersecting_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"get_nearest", (PyCFunction)reql_py_get_nearest_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"group", (PyCFunction)reql_py_group_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"gt", (PyCFunction)reql_py_gt_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"has_fields", (PyCFunction)reql_py_has_fields_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"hours", (PyCFunction)reql_py_hours_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"http", (PyCFunction)reql_py_http_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"implicit_var", (PyCFunction)reql_py_implicit_var_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"includes", (PyCFunction)reql_py_includes_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"index_create", (PyCFunction)reql_py_index_create_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"index_drop", (PyCFunction)reql_py_index_drop_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"index_list", (PyCFunction)reql_py_index_list_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"index_rename", (PyCFunction)reql_py_index_rename_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"index_status", (PyCFunction)reql_py_index_status_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"index_wait", (PyCFunction)reql_py_index_wait_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"info", (PyCFunction)reql_py_info_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"inner_join", (PyCFunction)reql_py_inner_join_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"insert", (PyCFunction)reql_py_insert_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"insert_at", (PyCFunction)reql_py_insert_at_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"intersects", (PyCFunction)reql_py_intersects_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"in_timezone", (PyCFunction)reql_py_in_timezone_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"iso8601", (PyCFunction)reql_py_iso8601_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"is_empty", (PyCFunction)reql_py_is_empty_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"january", (PyCFunction)reql_py_january_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"javascript", (PyCFunction)reql_py_javascript_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"json", (PyCFunction)reql_py_json_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"july", (PyCFunction)reql_py_july_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"june", (PyCFunction)reql_py_june_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"keys", (PyCFunction)reql_py_keys_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"le", (PyCFunction)reql_py_le_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"limit", (PyCFunction)reql_py_limit_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"line", (PyCFunction)reql_py_line_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"literal", (PyCFunction)reql_py_literal_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"lt", (PyCFunction)reql_py_lt_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"make_array", (PyCFunction)reql_py_make_array_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"make_obj", (PyCFunction)reql_py_make_obj_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"map", (PyCFunction)reql_py_map_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"march", (PyCFunction)reql_py_march_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"match", (PyCFunction)reql_py_match_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"max", (PyCFunction)reql_py_max_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"maxval", (PyCFunction)reql_py_maxval_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"may", (PyCFunction)reql_py_may_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"merge", (PyCFunction)reql_py_merge_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"min", (PyCFunction)reql_py_min_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"minutes", (PyCFunction)reql_py_minutes_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"minval", (PyCFunction)reql_py_minval_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"mod", (PyCFunction)reql_py_mod_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"monday", (PyCFunction)reql_py_monday_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"month", (PyCFunction)reql_py_month_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"mul", (PyCFunction)reql_py_mul_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"ne", (PyCFunction)reql_py_ne_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"not", (PyCFunction)reql_py_not_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"november", (PyCFunction)reql_py_november_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"now", (PyCFunction)reql_py_now_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"nth", (PyCFunction)reql_py_nth_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"object", (PyCFunction)reql_py_object_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"october", (PyCFunction)reql_py_october_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"offsets_of", (PyCFunction)reql_py_offsets_of_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"or", (PyCFunction)reql_py_or_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"order_by", (PyCFunction)reql_py_order_by_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"outer_join", (PyCFunction)reql_py_outer_join_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"pluck", (PyCFunction)reql_py_pluck_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"point", (PyCFunction)reql_py_point_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"polygon", (PyCFunction)reql_py_polygon_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"polygon_sub", (PyCFunction)reql_py_polygon_sub_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"prepend", (PyCFunction)reql_py_prepend_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"random", (PyCFunction)reql_py_random_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"range", (PyCFunction)reql_py_range_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"rebalance", (PyCFunction)reql_py_rebalance_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"reconfigure", (PyCFunction)reql_py_reconfigure_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"reduce", (PyCFunction)reql_py_reduce_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"replace", (PyCFunction)reql_py_replace_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"round", (PyCFunction)reql_py_round_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"sample", (PyCFunction)reql_py_sample_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"saturday", (PyCFunction)reql_py_saturday_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"seconds", (PyCFunction)reql_py_seconds_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"september", (PyCFunction)reql_py_september_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"set_difference", (PyCFunction)reql_py_set_difference_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"set_insert", (PyCFunction)reql_py_set_insert_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"set_intersection", (PyCFunction)reql_py_set_intersection_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"set_union", (PyCFunction)reql_py_set_union_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"skip", (PyCFunction)reql_py_skip_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"slice", (PyCFunction)reql_py_slice_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"splice_at", (PyCFunction)reql_py_splice_at_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"split", (PyCFunction)reql_py_split_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"status", (PyCFunction)reql_py_status_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"sub", (PyCFunction)reql_py_sub_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"sum", (PyCFunction)reql_py_sum_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"sunday", (PyCFunction)reql_py_sunday_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"sync", (PyCFunction)reql_py_sync_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"table", (PyCFunction)reql_py_table_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"table_create", (PyCFunction)reql_py_table_create_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"table_drop", (PyCFunction)reql_py_table_drop_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"table_list", (PyCFunction)reql_py_table_list_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"thursday", (PyCFunction)reql_py_thursday_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"time", (PyCFunction)reql_py_time_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"timezone", (PyCFunction)reql_py_timezone_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"time_of_day", (PyCFunction)reql_py_time_of_day_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"to_epoch_time", (PyCFunction)reql_py_to_epoch_time_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"to_geojson", (PyCFunction)reql_py_to_geojson_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"to_iso8601", (PyCFunction)reql_py_to_iso8601_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"to_json_string", (PyCFunction)reql_py_to_json_string_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"tuesday", (PyCFunction)reql_py_tuesday_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"type_of", (PyCFunction)reql_py_type_of_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"ungroup", (PyCFunction)reql_py_ungroup_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"union", (PyCFunction)reql_py_union_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"upcase", (PyCFunction)reql_py_upcase_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"update", (PyCFunction)reql_py_update_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"uuid", (PyCFunction)reql_py_uuid_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"var", (PyCFunction)reql_py_var_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"wait", (PyCFunction)reql_py_wait_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"wednesday", (PyCFunction)reql_py_wednesday_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"without", (PyCFunction)reql_py_without_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"with_fields", (PyCFunction)reql_py_with_fields_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"year", (PyCFunction)reql_py_year_method, METH_VARARGS | METH_KEYWORDS, ""},
  {"zip", (PyCFunction)reql_py_zip_method, METH_VARARGS | METH_KEYWORDS, ""},
  {NULL}  /* Sentinel */
};

static PyMemberDef Query_members[] = {
  {"_data", T_OBJECT, offsetof(ReQLQuery, reql_data), 0, ""},
  {NULL}  /* Sentinel */
};

static PyTypeObject ReQLQueryType = {
  PyVarObject_HEAD_INIT(NULL, 0)
  "libReQL.Query",           /*tp_name*/
  sizeof(ReQLQuery),         /*tp_basicsize*/
  0,                         /*tp_itemsize*/
  (destructor)Query_dealloc, /*tp_dealloc*/
  0,                         /*tp_print*/
  0,                         /*tp_getattr*/
  0,                         /*tp_setattr*/
  0,                         /*tp_compare*/
  0,                         /*tp_repr*/
  0,                         /*tp_as_number*/
  0,                         /*tp_as_sequence*/
  0,                         /*tp_as_mapping*/
  0,                         /*tp_hash */
  0,                         /*tp_call*/
  0,                         /*tp_str*/
  0,                         /*tp_getattro*/
  0,                         /*tp_setattro*/
  0,                         /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
  "",                        /* tp_doc */
  0,                         /* tp_traverse */
  0,                         /* tp_clear */
  0,                         /* tp_richcompare */
  0,                         /* tp_weaklistoffset */
  0,                         /* tp_iter */
  0,                         /* tp_iternext */
  Query_methods,             /* tp_methods */
  Query_members,             /* tp_members */
  0,                         /* tp_getset */
  0,                         /* tp_base */
  0,                         /* tp_dict */
  0,                         /* tp_descr_get */
  0,                         /* tp_descr_set */
  0,                         /* tp_dictoffset */
  (initproc)Query_init,      /* tp_init */
  0,                         /* tp_alloc */
  Query_new,                 /* tp_new */
};

PyTypeObject *
reql_py_query_type() {
  return &ReQLQueryType;
}
