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

#include "ReQL-ast-Python.h"

#include <stdlib.h>

extern PyObject *
reql_py_add(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.add", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_and(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.and", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_append(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.append", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_april(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.april", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_args(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.args", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_asc(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.asc", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_august(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.august", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_avg(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.avg", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_between(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.between", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_between_deprecated(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.between_deprecated", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_binary(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.binary", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_bracket(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.bracket", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_branch(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.branch", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_ceil(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ceil", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_changes(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.changes", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_change_at(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.change_at", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_circle(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.circle", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_coerce_to(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.coerce_to", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_concat_map(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.concat_map", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_config(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.config", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_contains(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.contains", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_count(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.count", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_date(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.date", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_datum(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.datum", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_day(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_day_of_week(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day_of_week", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_day_of_year(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.day_of_year", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_db(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_db_create(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_create", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_db_drop(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_drop", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_db_list(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.db_list", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_december(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.december", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_default(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.default", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_delete(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.delete", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_delete_at(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.delete_at", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_desc(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.desc", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_difference(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.difference", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_distance(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.distance", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_distinct(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.distinct", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_div(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.div", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_downcase(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.downcase", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_during(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.during", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_epoch_time(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.epoch_time", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_eq(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.eq", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_eq_join(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.eq_join", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_error(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.error", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_february(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.february", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_fill(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.fill", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_filter(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.filter", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_floor(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.floor", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_for_each(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.for_each", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_friday(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.friday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_func(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.func", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_funcall(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.funcall", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_ge(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ge", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_geojson(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.geojson", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get_all(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_all", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get_field(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_field", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get_intersecting(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_intersecting", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_get_nearest(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.get_nearest", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_group(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.group", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_gt(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.gt", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_has_fields(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.has_fields", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_hours(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.hours", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_http(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.http", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_implicit_var(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.implicit_var", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_includes(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.includes", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_create(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_create", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_drop(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_drop", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_list(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_list", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_rename(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_rename", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_status(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_status", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_index_wait(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.index_wait", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_info(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.info", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_inner_join(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.inner_join", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_insert(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.insert", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_insert_at(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.insert_at", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_intersects(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.intersects", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_in_timezone(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.in_timezone", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_iso8601(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.iso8601", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_is_empty(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.is_empty", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_january(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.january", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_javascript(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.javascript", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_json(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.json", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_july(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.july", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_june(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.june", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_keys(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.keys", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_le(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.le", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_limit(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.limit", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_line(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.line", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_literal(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.literal", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_lt(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.lt", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_make_array(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.make_array", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_make_obj(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.make_obj", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_map(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.map", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_march(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.march", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_match(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.match", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_max(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.max", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_maxval(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.maxval", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_may(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.may", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_merge(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.merge", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_min(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.min", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_minutes(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.minutes", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_minval(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.minval", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_mod(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.mod", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_monday(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.monday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_month(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.month", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_mul(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.mul", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_ne(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ne", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_not(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.not", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_november(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.november", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_now(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.now", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_nth(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.nth", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_object(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.object", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_october(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.october", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_offsets_of(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.offsets_of", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_or(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.or", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_order_by(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.order_by", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_outer_join(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.outer_join", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_pluck(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.pluck", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_point(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.point", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_polygon(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.polygon", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_polygon_sub(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.polygon_sub", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_prepend(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.prepend", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_random(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.random", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_range(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.range", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_rebalance(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.rebalance", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_reconfigure(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.reconfigure", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_reduce(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.reduce", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_replace(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.replace", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_round(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.round", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sample(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sample", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_saturday(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.saturday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_seconds(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.seconds", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_september(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.september", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_set_difference(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_difference", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_set_insert(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_insert", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_set_intersection(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_intersection", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_set_union(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.set_union", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_skip(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.skip", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_slice(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.slice", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_splice_at(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.splice_at", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_split(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.split", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_status(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.status", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sub(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sub", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sum(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sum", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sunday(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sunday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_sync(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.sync", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_table(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_table_create(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_create", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_table_drop(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_drop", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_table_list(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.table_list", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_thursday(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.thursday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_time(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.time", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_timezone(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.timezone", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_time_of_day(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.time_of_day", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_to_epoch_time(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_epoch_time", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_to_geojson(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_geojson", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_to_iso8601(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_iso8601", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_to_json_string(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.to_json_string", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_tuesday(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.tuesday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_type_of(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.type_of", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_ungroup(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.ungroup", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_union(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.union", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_upcase(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.upcase", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_update(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.update", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_uuid(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.uuid", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_var(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.var", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_wait(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.wait", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_wednesday(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.wednesday", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_without(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.without", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_with_fields(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.with_fields", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_year(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.year", kwlist, &val)) {
    return self;
  }

  return val;
}

extern PyObject *
reql_py_zip(PyObject *self, PyObject *args, PyObject *kwargs) {
  PyObject *val;

  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "o:r.zip", kwlist, &val)) {
    return self;
  }

  return val;
}
