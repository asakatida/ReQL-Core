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

//#define Py_LIMITED_API

#include <Python.h>

#include "ReQL.h"

#ifndef _REQL_NEW_PYTHON
#define _REQL_NEW_PYTHON

extern _ReQL_Op
_reql_py_new_array(uint32_t size);
extern _ReQL_Op
_reql_py_new_bool(PyObject *val);
extern _ReQL_Op
_reql_py_new_datum(_ReQL_Op val);
extern _ReQL_Op
_reql_py_new_make_array(_ReQL_Op val);
extern _ReQL_Op
_reql_py_new_make_obj(_ReQL_Op val);
extern _ReQL_Op
_reql_py_new_null();
extern _ReQL_Op
_reql_py_new_number(PyObject *val);
extern _ReQL_Op
_reql_py_new_object(uint32_t idx);
extern _ReQL_Op
_reql_py_new_string(PyObject *val);

#endif
