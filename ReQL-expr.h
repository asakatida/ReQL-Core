/*
Copyright 2014 Adam Grandquist

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

#include "ReQL-ast.h"

#ifndef _REQL_EXPR_H
#define _REQL_EXPR_H

_ReQL_Op _reql_expr(_ReQL_Op val);

_ReQL_Op _reql_expr_bool(int val);
_ReQL_Op _reql_json_bool(_ReQL_Op obj, int val);
_ReQL_Op _reql_bool(_ReQL_Op obj, int val);
int _reql_to_bool(_ReQL_Op obj, int *val);
_ReQL_Op _reql_expr_null();
_ReQL_Op _reql_json_null(_ReQL_Op obj);
_ReQL_Op _reql_null(_ReQL_Op obj);
int _reql_to_null(_ReQL_Op obj);
_ReQL_Op _reql_expr_number(double val);
_ReQL_Op _reql_json_number(_ReQL_Op obj, double val);
_ReQL_Op _reql_number(_ReQL_Op obj, double val);
int _reql_to_number(_ReQL_Op obj, double *val);
_ReQL_Op _reql_expr_string(const char *val, unsigned long str_len);
_ReQL_Op _reql_json_string(_ReQL_Op obj, const char *val, unsigned long str_len);
_ReQL_Op _reql_string(_ReQL_Op obj, const char *val, unsigned long str_len);
_ReQL_Op _reql_expr_string_nc(char *val, unsigned long str_len);
_ReQL_Op _reql_json_string_nc(_ReQL_Op obj, char *val, unsigned long str_len);
_ReQL_Op _reql_string_nc(_ReQL_Op obj, char *val, unsigned long str_len);
int _reql_to_string(_ReQL_Op obj, const char **val, unsigned long *str_len);

_ReQL_Op _reql_expr_c_array(unsigned long size);
_ReQL_Op _reql_json_c_array(_ReQL_Op obj, unsigned long size);
_ReQL_Op _reql_c_array(_ReQL_Op obj, unsigned long size);
int _reql_to_c_array(_ReQL_Op obj, unsigned long *size);
int _reql_c_array_insert(_ReQL_Op obj, _ReQL_Op val, unsigned long idx);
_ReQL_Op _reql_c_array_index(_ReQL_Op obj, unsigned long idx);

_ReQL_Op _reql_expr_array();
_ReQL_Op _reql_json_array(_ReQL_Op obj);
_ReQL_Op _reql_array(_ReQL_Op obj);
_ReQL_Op _reql_to_array(_ReQL_Op obj);
int _reql_array_append(_ReQL_Op arr, _ReQL_Op val);
int _reql_array_next(_ReQL_Op *arr, _ReQL_Op *val);
_ReQL_Op _reql_array_pop(_ReQL_Op obj);
_ReQL_Op _reql_array_last(_ReQL_Op obj);

_ReQL_Op _reql_expr_object();
_ReQL_Op _reql_json_object(_ReQL_Op obj);
_ReQL_Op _reql_object(_ReQL_Op obj);
_ReQL_Op _reql_to_object(_ReQL_Op obj);
void _reql_object_add(_ReQL_Op obj, _ReQL_Op key, _ReQL_Op val);
int _reql_object_next(_ReQL_Op *obj, _ReQL_Op *key, _ReQL_Op *val);

int _reql_op_eq(_ReQL_Op l, _ReQL_Op r);
void _reql_expr_free(_ReQL_Op obj);
_ReQL_Op _reql_expr_copy(_ReQL_Op obj);

_ReQL_Op _reql_build(_ReQL_Op query);

#endif
