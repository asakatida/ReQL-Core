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

#include "ReQL-new-Python.h"

static void *
reql_py_mem_check(void *obj) {
  if (obj == NULL) {
    PyGILState_STATE gil = PyGILState_Ensure();
    PyMem_Free(obj);
    PyGILState_Release(gil);
    return PyErr_NoMemory();
  }

  return obj;
}

static void *
reql_py_err_check(void *obj) {
  if (PyErr_Occurred() == NULL) {
    return obj;
  }

  PyGILState_STATE gil = PyGILState_Ensure();
  PyMem_Free(obj);
  PyGILState_Release(gil);
  return NULL;
}

static void *
reql_py_alloc(size_t size) {
  PyGILState_STATE gil = PyGILState_Ensure();
  void *obj = PyMem_Malloc(size);
  PyGILState_Release(gil);

  return reql_py_mem_check(obj);
}

static ReQL_Obj_t **
reql_py_alloc_arr(size_t size) {
  PyGILState_STATE gil = PyGILState_Ensure();
  ReQL_Obj_t **obj = PyMem_New(ReQL_Obj_t *, size);
  PyGILState_Release(gil);

  return reql_py_mem_check(obj);
}

static ReQL_Pair_t *
reql_py_alloc_pair(size_t size) {
  PyGILState_STATE gil = PyGILState_Ensure();
  ReQL_Pair_t *obj = PyMem_New(ReQL_Pair_t, size);
  PyGILState_Release(gil);

  return reql_py_mem_check(obj);
}

static ReQL_Obj_t *
reql_py_alloc_term() {
  return reql_py_alloc(sizeof(ReQL_Obj_t));
}

extern ReQL_Obj_t *
reql_py_new_array(uint32_t size) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  ReQL_Obj_t **arr = reql_py_alloc_arr(size);
  if (arr == NULL) {
    return NULL;
  }
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
  return reql_py_err_check(obj);
}

extern ReQL_Obj_t *
reql_py_new_datum(ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_ast_datum(obj, arg, NULL);
  return reql_py_err_check(obj);
}

extern ReQL_Obj_t *
reql_py_new_make_array(ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_ast_make_array(obj, arg, NULL);
  return reql_py_err_check(obj);
}

extern ReQL_Obj_t *
reql_py_new_make_obj(ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_ast_make_obj(obj, NULL, arg);
  return reql_py_err_check(obj);
}

extern ReQL_Obj_t *
reql_py_new_null() {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  reql_null_init(obj);
  return reql_py_err_check(obj);
}

extern ReQL_Obj_t *
reql_py_new_number(PyObject *val) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  reql_number_init(obj, PyFloat_AsDouble(val));
  return reql_py_err_check(obj);
}

extern ReQL_Obj_t *
reql_py_new_object(uint32_t size) {
  ReQL_Obj_t *obj = reql_py_alloc_term();
  if (obj == NULL) {
    return NULL;
  }
  ReQL_Pair_t *pair = reql_py_alloc_pair(size);
  if (pair == NULL) {
    return NULL;
  }
  reql_object_init(obj, pair, size);
  return reql_py_err_check(obj);
}

extern ReQL_Obj_t *
reql_py_new_string(PyObject *val) {
  Py_ssize_t size = 0;

  uint8_t *str = (uint8_t *)PyUnicode_AsUTF8AndSize(val, &size);
  if (str == NULL || size > UINT32_MAX) {
    return NULL;
  }

  ReQL_Obj_t *obj = reql_py_alloc_term();

  reql_string_init(obj, str, (uint32_t)size);

  return reql_py_err_check(obj);
}
