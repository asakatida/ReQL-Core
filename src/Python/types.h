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

#ifndef REQL_PYTHON_TYPES_H_
#define REQL_PYTHON_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#define Py_LIMITED_API
#include "Python.h"

#include "./reql/core.h"

typedef struct {
  PyObject_HEAD
  ReQL_Conn_t *reql_connection;
} ReQLConnection;

typedef struct {
  PyObject_HEAD
  PyObject *reql_data;
  ReQL_AST_Function reql_func;
  ReQL_AST_Function_Kwargs reql_func_kwargs;
  ReQL_Obj_t *(*reql_build)(PyObject *data);
} ReQLQuery;

extern void
reql_py_dealloc(PyObject* self);

PyTypeObject *
reql_py_connection_type();

PyTypeObject *
reql_py_query_type();

#ifdef __cplusplus
}
#endif

#endif  // REQL_PYTHON_TYPES_H_
