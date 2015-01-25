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

#include "ReQL-expr-Python.h"

extern PyObject *
_reql_py_expr(PyObject *self, PyObject *args) {
  PyObject *val;
  int nesting_depth = 20;

  if (!PyArg_ParseTuple(args, "o|i:r.expr", &val, &nesting_depth)) {
    return NULL;
  }

  if (nesting_depth <= 0) {
    return NULL;
  }

  if (PyCallable_Check(val)) {
    return NULL;
  }

  if (PyUnicode_Check(val)) {
    return _reql_to_py(_reql_py_new_datum(_reql_from_py(val)));
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
      return NULL;
    }

    PyObject *reql_val = PyDict_New();

    if (!reql_val) {
      return NULL;
    }

    PyObject *key;
    while ((key = PyIter_Next(iterator))) {
      _reql_py_expr(self, Py_BuildValue("Oi", key, nesting_depth));
      Py_DECREF(key);
    }

    Py_DECREF(iterator);
    Py_DECREF(keys);

    if (PyErr_Occurred()) {
      return NULL;
    }

    return reql_val;
  }

  if (PyIter_Check(val)) {
    PyObject *iterator = PyObject_GetIter(val);

    if (!iterator) {
      return NULL;
    }

    PyObject *reql_val = PyList_New(0);

    if (!reql_val) {
      return NULL;
    }

    PyObject *item;
    while ((item = PyIter_Next(iterator))) {
      _reql_py_expr(self, Py_BuildValue("Oi", item, nesting_depth));
      Py_DECREF(item);
    }

    Py_DECREF(iterator);

    if (PyErr_Occurred()) {
      return NULL;
    }

    return reql_val;
  }

  return _reql_to_py(_reql_from_py(val));
}

extern _ReQL_Obj_t *
_reql_from_py(PyObject *query) {
  return NULL;
}

extern PyObject *
_reql_to_py(_ReQL_Obj_t *query) {
  return NULL;
}
