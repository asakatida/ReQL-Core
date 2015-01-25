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

#ifndef _REQL_EXPR_PYTHON
#define _REQL_EXPR_PYTHON

extern PyObject *
_reql_py_expr(PyObject *self, PyObject *args);
extern _ReQL_Obj_t *
_reql_from_py(PyObject *query);
extern PyObject *
_reql_to_py(_ReQL_Obj_t *query);

#endif
