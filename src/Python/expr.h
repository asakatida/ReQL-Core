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

#ifndef REQL_EXPR_PYTHON_H_
#define REQL_EXPR_PYTHON_H_

#include "ReQL-new-Python.h"

extern PyObject *
reql_py_expr(PyObject *self, PyObject *args);
extern ReQL_Obj_t *
reql_from_py(PyObject *query);
extern PyObject *
reql_to_py(ReQL_Obj_t *query);

#endif  // REQL_EXPR_PYTHON_H_
