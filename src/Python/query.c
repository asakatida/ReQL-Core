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

#include "./Python/types.h"
#include "./reql/core.h"

#include <stdlib.h>

static ReQL_Obj_t *
reql_py_build(ReQLQuery *query) {
  if (query == NULL) {
    return NULL;
  }
  if (query->reql_func != NULL || query->reql_func_kwargs != NULL) {
    return query->reql_build((PyObject *)query);
  }
  return query->reql_build(query->reql_data);
}

extern void
Query_dealloc(ReQLQuery* self) {
  Py_CLEAR(self->reql_data);
  reql_py_dealloc((PyObject*)self);
}

extern PyObject *
Query_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
  return PyType_GenericNew(type, args, kwargs);
}

extern int
Query_init(ReQLQuery *self, PyObject *args, PyObject *kwargs) {
  static char *kwlist[] = {NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "", kwlist)) {
    return -1;
  }

  return 0;
}

extern PyObject *
reql_py_run(PyObject *self, PyObject *args, PyObject *kwargs) {
  return NULL;
}

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

static void
reql_py_destroy(ReQL_Obj_t *obj) {
  if (obj == NULL) {
    return;
  }
  PyGILState_STATE gil = PyGILState_Ensure();
  switch (reql_datum_type(obj)) {
    case REQL_R_ARRAY: {
      PyMem_Free(reql_string_buf(obj));
      break;
    }
    case REQL_R_BOOL: {
      break;
    }
    case REQL_R_JSON: {
      break;
    }
    case REQL_R_NULL: {
      break;
    }
    case REQL_R_NUM: {
      break;
    }
    case REQL_R_OBJECT: {
      PyMem_Free(reql_string_buf(obj));
      break;
    }
    case REQL_R_REQL: {
      break;
    }
    case REQL_R_STR: {
      PyMem_Free(reql_string_buf(obj));
      break;
    }
  }
  PyMem_Free(obj);
  PyGILState_Release(gil);
}

static ReQL_Obj_t *
reql_py_clean_on_error(ReQL_Obj_t *obj) {
  if (PyErr_Occurred() == NULL) {
    return obj;
  }
  reql_py_destroy(obj);
  return NULL;
}

static ReQL_Obj_t *
reql_py_build_array(PyObject *data) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  if (data == NULL) {
    reql_array_init(obj, NULL, 0);
    return reql_py_clean_on_error(obj);
  }
  Py_ssize_t size = PyObject_Length(data);
  PyGILState_STATE gil = PyGILState_Ensure();
  ReQL_Obj_t **buf = PyMem_New(ReQL_Obj_t *, size);
  if (buf == NULL) {
    PyErr_NoMemory();
    PyMem_Free(obj);
    PyGILState_Release(gil);
    return NULL;
  }
  PyGILState_Release(gil);
  reql_array_init(obj, buf, (ReQL_Size)size);
  PyObject *iterator = PyObject_GetIter(data);
  if (!iterator) {
    return NULL;
  }
  PyObject *item;
  while ((item = PyIter_Next(iterator)) != NULL) {
    reql_array_append(obj, reql_py_build((ReQLQuery *)item));
    Py_DECREF(item);
  }
  Py_DECREF(iterator);
  return reql_py_clean_on_error(obj);
}

static ReQL_Obj_t *
reql_py_build_bool(PyObject *data) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_bool_init(obj, PyObject_IsTrue(data) ? 1 == 1 : 0 == 1);
  return reql_py_clean_on_error(obj);
}

static ReQL_Obj_t *
reql_py_build_null(PyObject *data) {
  (void)data;
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_null_init(obj);
  return reql_py_clean_on_error(obj);
}

static ReQL_Obj_t *
reql_py_build_number(PyObject *data) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_number_init(obj, PyFloat_AsDouble(data));
  return reql_py_clean_on_error(obj);
}

static ReQL_Obj_t *
reql_py_build_object(PyObject *data) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  if (data == NULL) {
    reql_object_init(obj, NULL, 0);
    return reql_py_clean_on_error(obj);
  }
  Py_ssize_t size = PyObject_Length(data);
  PyGILState_STATE gil = PyGILState_Ensure();
  ReQL_Pair_t *buf = PyMem_New(ReQL_Pair_t, size);
  if (buf == NULL) {
    PyErr_NoMemory();
    PyMem_Free(obj);
    PyGILState_Release(gil);
    return NULL;
  }
  PyGILState_Release(gil);
  reql_object_init(obj, buf, (ReQL_Size)size);
  PyObject *keys = PyMapping_Keys(data);
  if (!keys) {
    return NULL;
  }
  PyObject *iterator = PyObject_GetIter(keys);
  if (!iterator) {
    Py_DECREF(keys);
    return NULL;
  }
  PyObject *key;
  while ((key = PyIter_Next(iterator)) != NULL) {
    PyObject *val = PyDict_GetItem(data, key);
    reql_object_add(obj, reql_py_build((ReQLQuery *)key), reql_py_build((ReQLQuery *)val));
    Py_DECREF(val);
    Py_DECREF(key);
  }
  Py_DECREF(iterator);
  Py_DECREF(keys);
  return reql_py_clean_on_error(obj);
}

static ReQL_Obj_t *
reql_py_build_string(PyObject *data) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  if (data == NULL) {
    reql_string_init(obj, NULL, NULL, 0);
    return reql_py_clean_on_error(obj);
  }
  PyObject *val = PyUnicode_AsUTF8String(data);
  if (val == NULL) {
    return NULL;
  }
  Py_ssize_t size = 0;
  char *str = NULL;
  if (PyBytes_AsStringAndSize(val, &str, &size)) {
    return NULL;
  }
  if (str == NULL || size > UINT32_MAX) {
    return NULL;
  }
  PyGILState_STATE gil = PyGILState_Ensure();
  ReQL_Byte *buf = PyMem_New(ReQL_Byte, size);
  if (buf == NULL) {
    PyErr_NoMemory();
    PyMem_Free(obj);
    PyGILState_Release(gil);
    return NULL;
  }
  PyGILState_Release(gil);
  reql_string_init(obj, buf, (ReQL_Byte *)str, (ReQL_Size)size);
  return reql_py_clean_on_error(obj);
}

static ReQL_Obj_t *
reql_py_build_term(PyObject *data) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  ReQLQuery *query = (ReQLQuery *)data;
  ReQL_Obj_t *r_args = NULL;
  if (query->reql_data != NULL) {
    r_args = reql_py_build((ReQLQuery *)query->reql_data);
    if (r_args == NULL) {
      PyGILState_STATE gil = PyGILState_Ensure();
      PyMem_Free(obj);
      PyGILState_Release(gil);
      return NULL;
    }
  }
  query->reql_func(obj, r_args);
  return reql_py_clean_on_error(obj);
}

static ReQL_Obj_t *
reql_py_build_term_kwargs(PyObject *data) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  ReQLQuery *query = (ReQLQuery *)data;
  PyObject *args_data = query->reql_data;
  if (args_data == NULL) {
    query->reql_func_kwargs(obj, NULL, NULL);
    return reql_py_clean_on_error(obj);
  }
  ReQL_Obj_t *r_args = NULL;
  ReQL_Obj_t *r_kwargs = NULL;
  Py_ssize_t size = PySequence_Size(args_data);
  switch (size) {
    case 2: {
      ReQLQuery *kwargs = (ReQLQuery *)PySequence_GetItem(args_data, 1);
      r_kwargs = reql_py_build((ReQLQuery *)kwargs);
      if (r_kwargs == NULL) {
        PyGILState_STATE gil = PyGILState_Ensure();
        PyMem_Free(obj);
        PyGILState_Release(gil);
        return NULL;
      }
    }
    case 1: {
      ReQLQuery *args = (ReQLQuery *)PySequence_GetItem(args_data, 0);
      r_args = reql_py_build((ReQLQuery *)args);
      if (r_args == NULL) {
        PyGILState_STATE gil = PyGILState_Ensure();
        PyMem_Free(obj);
        PyGILState_Release(gil);
        reql_py_destroy(r_kwargs);
        return NULL;
      }
      break;
    }
    default: {
      PyGILState_STATE gil = PyGILState_Ensure();
      PyMem_Free(obj);
      PyGILState_Release(gil);
      return NULL;
    }
  }
  query->reql_func_kwargs(obj, r_args, r_kwargs);
  return reql_py_clean_on_error(obj);
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
    ReQLQuery *result = PyObject_New(ReQLQuery, reql_py_query_type());
    if (result == NULL) {
      return NULL;
    }
    return (PyObject *)result;
  }

  if (PyUnicode_Check(val)) {
    ReQLQuery *result = PyObject_New(ReQLQuery, reql_py_query_type());
    if (result == NULL) {
      return NULL;
    }
    return (PyObject *)result;
  }

  if (PyBytes_Check(val)) {
    ReQLQuery *result = PyObject_New(ReQLQuery, reql_py_query_type());
    if (result == NULL) {
      return NULL;
    }
    return (PyObject *)result;
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

    ReQLQuery *result = PyObject_New(ReQLQuery, reql_py_query_type());
    if (result == NULL) {
      return NULL;
    }
    return (PyObject *)result;
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

    ReQLQuery *result = PyObject_New(ReQLQuery, reql_py_query_type());
    if (result == NULL) {
      return NULL;
    }
    return (PyObject *)result;
  }

  ReQLQuery *result = PyObject_New(ReQLQuery, reql_py_query_type());
  if (result == NULL) {
    return NULL;
  }
  return (PyObject *)result;
}

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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

extern PyObject *
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
