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

#ifndef REQL_NEW_PYTHON_H_
#define REQL_NEW_PYTHON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ReQL.h"

#define Py_LIMITED_API

#include <Python.h>

extern ReQL_Obj_t *
reql_py_new_array(uint32_t size);
extern ReQL_Obj_t *
reql_py_new_bool(PyObject *val);
extern ReQL_Obj_t *
reql_py_new_datum(ReQL_Obj_t *val);
extern ReQL_Obj_t *
reql_py_new_make_array(ReQL_Obj_t *val);
extern ReQL_Obj_t *
reql_py_new_make_obj(ReQL_Obj_t *val);
extern ReQL_Obj_t *
reql_py_new_null();
extern ReQL_Obj_t *
reql_py_new_number(PyObject *val);
extern ReQL_Obj_t *
reql_py_new_object(uint32_t idx);
extern ReQL_Obj_t *
reql_py_new_string(PyObject *val);

#ifdef __cplusplus
}
#endif

#endif  // REQL_NEW_PYTHON_H_
