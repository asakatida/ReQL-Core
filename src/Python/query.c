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
#include "structmember.h"

#include "./Python/query.h"

#include "./reql/core.h"

#include <stdlib.h>

typedef struct {
  PyObject_HEAD
  PyObject *reql_data;
} ReQLQuery;

static void
Query_dealloc(ReQLQuery* self) {
  Py_CLEAR(self->reql_data);
  Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
Query_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
  return type->tp_alloc(type, 0);
}

static int
Query_init(ReQLQuery *self, PyObject *args, PyObject *kwargs) {
  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "", kwlist)) {
    return -1;
  }

  return 0;
}

static PyObject *
Query_name(ReQLQuery* self) {
  return NULL;
}

static PyMemberDef Query_members[] = {
  {"_data", T_OBJECT_EX, offsetof(ReQLQuery, reql_data), 0, ""},
  {NULL}  /* Sentinel */
};

static PyObject *
reql_py_add_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_and_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_append_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_april_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_args_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_asc_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_august_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_avg_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_between_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_between_deprecated_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_binary_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_bracket_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_branch_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_ceil_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_changes_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_change_at_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_circle_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_coerce_to_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_concat_map_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_config_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_contains_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_count_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_date_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_datum_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_day_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_day_of_week_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_day_of_year_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_db_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_db_create_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_db_drop_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_db_list_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_december_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_default_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_delete_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_delete_at_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_desc_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_difference_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_distance_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_distinct_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_div_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_downcase_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_during_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_epoch_time_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_eq_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_eq_join_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_error_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_february_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_fill_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_filter_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_floor_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_for_each_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_friday_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_func_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_funcall_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_ge_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_geojson_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_get_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_get_all_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_get_field_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_get_intersecting_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_get_nearest_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_group_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_gt_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_has_fields_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_hours_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_http_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_implicit_var_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_includes_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_index_create_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_index_drop_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_index_list_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_index_rename_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_index_status_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_index_wait_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_info_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_inner_join_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_insert_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_insert_at_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_intersects_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_in_timezone_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_iso8601_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_is_empty_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_january_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_javascript_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_json_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_july_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_june_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_keys_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_le_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_limit_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_line_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_literal_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_lt_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_make_array_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_make_obj_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_map_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_march_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_match_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_max_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_maxval_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_may_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_merge_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_min_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_minutes_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_minval_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_mod_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_monday_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_month_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_mul_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_ne_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_not_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_november_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_now_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_nth_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_object_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_october_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_offsets_of_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_or_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_order_by_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_outer_join_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_pluck_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_point_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_polygon_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_polygon_sub_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_prepend_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_random_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_range_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_rebalance_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_reconfigure_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_reduce_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_replace_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_round_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_sample_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_saturday_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_seconds_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_september_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_set_difference_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_set_insert_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_set_intersection_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_set_union_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_skip_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_slice_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_splice_at_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_split_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_status_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_sub_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_sum_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_sunday_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_sync_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_table_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_table_create_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_table_drop_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_table_list_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_thursday_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_time_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_timezone_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_time_of_day_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_to_epoch_time_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_to_geojson_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_to_iso8601_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_to_json_string_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_tuesday_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_type_of_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_ungroup_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_union_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_upcase_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_update_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_uuid_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_var_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_wait_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_wednesday_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_without_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_with_fields_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_year_method(PyObject *self, PyObject *args, PyObject *kwargs);
static PyObject *
reql_py_zip_method(PyObject *self, PyObject *args, PyObject *kwargs);

static PyMethodDef Query_methods[] = {
  {"name", (PyCFunction)Query_name, METH_NOARGS, ""},
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

static PyTypeObject ReQLQueryType = {
  PyObject_HEAD_INIT(NULL)
  0,                         /*ob_size*/
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

static ReQL_Obj_t *
reql_py_alloc_term() {
  PyGILState_STATE gil = PyGILState_Ensure();
  void *obj = PyMem_Malloc(sizeof(ReQL_Obj_t));
  PyGILState_Release(gil);

  if (obj == NULL) {
    PyErr_NoMemory();
  }

  return obj;
}

extern ReQL_Obj_t *
reql_py_new_array(uint32_t size) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }

  PyGILState_STATE gil = PyGILState_Ensure();
  ReQL_Obj_t **arr = PyMem_New(ReQL_Obj_t *, size);
  if (arr == NULL) {
    PyErr_NoMemory();
    PyMem_Free(obj);
    PyGILState_Release(gil);
    return NULL;
  }
  PyGILState_Release(gil);

  reql_array_init(obj, arr, size);
  return obj;
}

extern ReQL_Obj_t *
reql_py_new_bool(PyObject *val) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_bool_init(obj, PyObject_IsTrue(val));
  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  return NULL;
}

extern ReQL_Obj_t *
reql_py_new_datum(ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_ast_datum(obj, arg);
  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  return NULL;
}

extern ReQL_Obj_t *
reql_py_new_make_array(ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_ast_make_array(obj, arg);
  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  return NULL;
}

extern ReQL_Obj_t *
reql_py_new_make_obj(ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_ast_make_obj(obj, arg);
  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  return NULL;
}

extern ReQL_Obj_t *
reql_py_new_null() {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_null_init(obj);
  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  return NULL;
}

extern ReQL_Obj_t *
reql_py_new_number(PyObject *val) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  reql_number_init(obj, PyFloat_AsDouble(val));
  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  return NULL;
}

extern ReQL_Obj_t *
reql_py_new_object(uint32_t size) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  PyGILState_STATE gil = PyGILState_Ensure();
  ReQL_Pair_t *pair = PyMem_New(ReQL_Pair_t, size);
  if (pair == NULL) {
    PyErr_NoMemory();
    PyMem_Free(obj);
    PyGILState_Release(gil);
    return NULL;
  }
  PyGILState_Release(gil);

  reql_object_init(obj, pair, size);
  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  return NULL;
}

extern ReQL_Obj_t *
reql_py_new_string(PyObject *val) {
  val = PyUnicode_AsUTF8String(val);

  if (val == NULL) {
    return NULL;
  }

  Py_ssize_t size = 0;

  ReQL_Byte *str = NULL;
  if (PyBytes_AsStringAndSize(val, (char **)&str, &size)) {
    return NULL;
  }

  if (str == NULL || size > UINT32_MAX) {
    return NULL;
  }

  ReQL_Obj_t *obj = reql_py_alloc_term();

  ReQL_Byte *buf = malloc(sizeof(ReQL_Byte) * size);

  reql_string_init(obj, buf, str, (ReQL_Size)size);

  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  return NULL;
}

extern PyObject *
reql_py_expr(PyObject *self, PyObject *args) {
  PyObject *val;
  int nesting_depth = 20;

  if (!PyArg_ParseTuple(args, "o|i:r.expr", &val, &nesting_depth)) {
    return NULL;
  }

  if (nesting_depth <= 0) {
    return NULL;
  }

  if (PyCallable_Check(val)) {
    return (PyObject *)PyObject_New(ReQLQuery, &ReQLQueryType);
  }

  if (PyUnicode_Check(val)) {
    return (PyObject *)PyObject_New(ReQLQuery, &ReQLQueryType);
  }

  if (PyBytes_Check(val)) {
    return NULL;
  }

  --nesting_depth;

  if (PyMapping_Check(val)) {
    PyObject *keys = PyMapping_Keys(val);

    if (!keys) {
      return NULL;
    }

    PyObject *iterator = PyObject_GetIter(keys);

    if (!iterator) {
      Py_DECREF(keys);
      return NULL;
    }

    PyObject *reql_val = PyDict_New();

    if (!reql_val) {
      Py_DECREF(iterator);
      Py_DECREF(keys);
      return NULL;
    }

    PyObject *key;
    while ((key = PyIter_Next(iterator))) {
      reql_py_expr(self, Py_BuildValue("Oi", key, nesting_depth));
      Py_DECREF(key);
    }

    Py_DECREF(reql_val);
    Py_DECREF(iterator);
    Py_DECREF(keys);

    if (PyErr_Occurred()) {
      return NULL;
    }

    return (PyObject *)PyObject_New(ReQLQuery, &ReQLQueryType);
  }

  PyObject *iterator = PyObject_GetIter(val);

  if (iterator) {
    PyObject *reql_val = PyList_New(0);

    if (!reql_val) {
      Py_DECREF(iterator);
      return NULL;
    }

    PyObject *item;
    while ((item = PyIter_Next(iterator))) {
      reql_py_expr(self, Py_BuildValue("Oi", item, nesting_depth));
      Py_DECREF(item);
    }

    Py_DECREF(reql_val);
    Py_DECREF(iterator);

    if (PyErr_Occurred()) {
      return NULL;
    }

    return (PyObject *)PyObject_New(ReQLQuery, &ReQLQueryType);
  }

  return (PyObject *)PyObject_New(ReQLQuery, &ReQLQueryType);
}

static PyObject *
reql_py_add_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.add", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_add(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.add", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_and_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.and", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_and(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.and", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_append_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.append", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_append(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.append", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_april_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.april", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_april(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.april", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_args_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.args", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_args(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.args", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_asc_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.asc", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_asc(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.asc", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_august_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.august", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_august(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.august", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_avg_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.avg", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_avg(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.avg", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_between_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.between", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_between(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.between", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_between_deprecated_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.between_deprecated", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_between_deprecated(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.between_deprecated", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_binary_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.binary", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_binary(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.binary", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_bracket_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.bracket", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_bracket(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.bracket", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_branch_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.branch", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_branch(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.branch", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_ceil_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ceil", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_ceil(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ceil", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_changes_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.changes", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_changes(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.changes", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_change_at_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.change_at", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_change_at(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.change_at", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_circle_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.circle", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_circle(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.circle", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_coerce_to_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.coerce_to", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_coerce_to(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.coerce_to", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_concat_map_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.concat_map", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_concat_map(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.concat_map", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_config_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.config", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_config(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.config", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_contains_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.contains", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_contains(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.contains", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_count_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.count", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_count(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.count", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_date_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.date", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_date(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.date", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_datum_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.datum", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_datum(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.datum", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_day_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_day(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_day_of_week_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day_of_week", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_day_of_week(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day_of_week", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_day_of_year_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day_of_year", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_day_of_year(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day_of_year", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_db_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_db(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_db_create_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_create", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_db_create(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_create", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_db_drop_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_drop", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_db_drop(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_drop", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_db_list_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_list", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_db_list(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_list", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_december_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.december", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_december(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.december", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_default_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.default", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_default(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.default", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_delete_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.delete", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_delete(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.delete", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_delete_at_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.delete_at", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_delete_at(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.delete_at", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_desc_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.desc", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_desc(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.desc", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_difference_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.difference", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_difference(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.difference", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_distance_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.distance", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_distance(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.distance", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_distinct_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.distinct", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_distinct(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.distinct", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_div_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.div", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_div(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.div", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_downcase_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.downcase", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_downcase(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.downcase", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_during_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.during", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_during(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.during", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_epoch_time_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.epoch_time", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_epoch_time(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.epoch_time", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_eq_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.eq", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_eq(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.eq", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_eq_join_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.eq_join", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_eq_join(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.eq_join", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_error_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.error", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_error(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.error", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_february_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.february", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_february(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.february", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_fill_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.fill", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_fill(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.fill", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_filter_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.filter", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_filter(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.filter", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_floor_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.floor", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_floor(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.floor", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_for_each_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.for_each", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_for_each(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.for_each", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_friday_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.friday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_friday(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.friday", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_func_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.func", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_func(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.func", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_funcall_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.funcall", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_funcall(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.funcall", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_ge_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ge", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_ge(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ge", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_geojson_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.geojson", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_geojson(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.geojson", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_get_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_get_all_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_all", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get_all(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_all", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_get_field_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_field", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get_field(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_field", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_get_intersecting_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_intersecting", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get_intersecting(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_intersecting", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_get_nearest_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_nearest", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get_nearest(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_nearest", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_group_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.group", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_group(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.group", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_gt_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.gt", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_gt(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.gt", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_has_fields_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.has_fields", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_has_fields(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.has_fields", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_hours_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.hours", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_hours(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.hours", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_http_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.http", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_http(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.http", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_implicit_var_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.implicit_var", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_implicit_var(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.implicit_var", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_includes_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.includes", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_includes(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.includes", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_index_create_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_create", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_create(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_create", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_index_drop_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_drop", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_drop(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_drop", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_index_list_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_list", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_list(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_list", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_index_rename_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_rename", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_rename(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_rename", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_index_status_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_status", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_status(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_status", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_index_wait_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_wait", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_wait(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_wait", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_info_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.info", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_info(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.info", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_inner_join_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.inner_join", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_inner_join(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.inner_join", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_insert_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.insert", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_insert(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.insert", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_insert_at_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.insert_at", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_insert_at(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.insert_at", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_intersects_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.intersects", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_intersects(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.intersects", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_in_timezone_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.in_timezone", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_in_timezone(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.in_timezone", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_iso8601_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.iso8601", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_iso8601(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.iso8601", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_is_empty_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.is_empty", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_is_empty(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.is_empty", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_january_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.january", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_january(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.january", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_javascript_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.javascript", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_javascript(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.javascript", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_json_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.json", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_json(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.json", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_july_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.july", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_july(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.july", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_june_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.june", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_june(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.june", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_keys_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.keys", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_keys(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.keys", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_le_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.le", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_le(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.le", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_limit_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.limit", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_limit(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.limit", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_line_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.line", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_line(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.line", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_literal_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.literal", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_literal(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.literal", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_lt_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.lt", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_lt(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.lt", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_make_array_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.make_array", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_make_array(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.make_array", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_make_obj_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.make_obj", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_make_obj(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.make_obj", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_map_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.map", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_map(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.map", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_march_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.march", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_march(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.march", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_match_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.match", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_match(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.match", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_max_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.max", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_max(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.max", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_maxval_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.maxval", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_maxval(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.maxval", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_may_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.may", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_may(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.may", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_merge_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.merge", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_merge(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.merge", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_min_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.min", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_min(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.min", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_minutes_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.minutes", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_minutes(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.minutes", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_minval_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.minval", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_minval(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.minval", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_mod_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.mod", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_mod(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.mod", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_monday_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.monday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_monday(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.monday", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_month_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.month", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_month(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.month", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_mul_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.mul", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_mul(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.mul", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_ne_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ne", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_ne(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ne", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_not_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.not", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_not(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.not", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_november_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.november", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_november(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.november", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_now_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.now", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_now(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.now", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_nth_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.nth", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_nth(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.nth", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_object_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.object", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_object(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.object", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_october_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.october", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_october(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.october", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_offsets_of_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.offsets_of", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_offsets_of(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.offsets_of", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_or_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.or", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_or(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.or", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_order_by_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.order_by", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_order_by(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.order_by", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_outer_join_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.outer_join", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_outer_join(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.outer_join", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_pluck_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.pluck", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_pluck(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.pluck", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_point_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.point", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_point(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.point", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_polygon_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.polygon", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_polygon(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.polygon", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_polygon_sub_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.polygon_sub", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_polygon_sub(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.polygon_sub", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_prepend_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.prepend", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_prepend(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.prepend", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_random_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.random", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_random(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.random", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_range_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.range", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_range(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.range", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_rebalance_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.rebalance", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_rebalance(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.rebalance", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_reconfigure_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.reconfigure", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_reconfigure(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.reconfigure", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_reduce_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.reduce", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_reduce(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.reduce", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_replace_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.replace", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_replace(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.replace", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_round_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.round", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_round(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.round", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_sample_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sample", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sample(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sample", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_saturday_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.saturday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_saturday(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.saturday", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_seconds_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.seconds", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_seconds(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.seconds", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_september_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.september", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_september(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.september", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_set_difference_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_difference", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_set_difference(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_difference", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_set_insert_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_insert", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_set_insert(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_insert", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_set_intersection_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_intersection", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_set_intersection(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_intersection", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_set_union_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_union", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_set_union(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_union", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_skip_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.skip", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_skip(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.skip", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_slice_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.slice", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_slice(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.slice", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_splice_at_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.splice_at", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_splice_at(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.splice_at", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_split_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.split", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_split(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.split", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_status_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.status", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_status(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.status", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_sub_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sub", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sub(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sub", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_sum_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sum", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sum(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sum", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_sunday_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sunday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sunday(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sunday", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_sync_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sync", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sync(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sync", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_table_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_table(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_table_create_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_create", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_table_create(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_create", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_table_drop_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_drop", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_table_drop(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_drop", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_table_list_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_list", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_table_list(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_list", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_thursday_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.thursday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_thursday(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.thursday", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_time_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.time", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_time(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.time", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_timezone_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.timezone", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_timezone(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.timezone", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_time_of_day_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.time_of_day", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_time_of_day(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.time_of_day", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_to_epoch_time_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_epoch_time", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_to_epoch_time(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_epoch_time", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_to_geojson_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_geojson", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_to_geojson(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_geojson", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_to_iso8601_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_iso8601", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_to_iso8601(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_iso8601", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_to_json_string_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_json_string", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_to_json_string(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_json_string", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_tuesday_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.tuesday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_tuesday(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.tuesday", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_type_of_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.type_of", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_type_of(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.type_of", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_ungroup_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ungroup", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_ungroup(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ungroup", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_union_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.union", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_union(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.union", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_upcase_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.upcase", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_upcase(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.upcase", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_update_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.update", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_update(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.update", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_uuid_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.uuid", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_uuid(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.uuid", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_var_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.var", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_var(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.var", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_wait_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.wait", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_wait(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.wait", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_wednesday_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.wednesday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_wednesday(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.wednesday", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_without_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.without", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_without(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.without", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_with_fields_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.with_fields", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_with_fields(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.with_fields", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_year_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.year", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_year(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.year", kwlist, &val)) {
    return NULL;
  }

  return val;
}

static PyObject *
reql_py_zip_method(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.zip", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_zip(PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.zip", kwlist, &val)) {
    return NULL;
  }

  return val;
}
