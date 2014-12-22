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
_ReQL_Op _reql_bool(_ReQL_Op obj, int val);
int _reql_to_bool(_ReQL_Op obj, int *val);
_ReQL_Op _reql_expr_null();
_ReQL_Op _reql_null(_ReQL_Op obj);
int _reql_to_null(_ReQL_Op obj);
_ReQL_Op _reql_expr_number(double val);
_ReQL_Op _reql_number(_ReQL_Op obj, double val);
int _reql_to_number(_ReQL_Op obj, double *val);
_ReQL_Op _reql_expr_string(const char *val, unsigned long str_len);
_ReQL_Op _reql_string(_ReQL_Op obj, const char *val, unsigned long str_len);
_ReQL_Op _reql_expr_string_nc(char *val, unsigned long str_len);
_ReQL_Op _reql_string_nc(_ReQL_Op obj, char *val, unsigned long str_len);
int _reql_to_string(_ReQL_Op obj, const char **val, unsigned long *str_len);

_ReQL_Op _reql_build(_ReQL_Op query);

#endif
