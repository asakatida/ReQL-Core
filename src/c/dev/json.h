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

#ifndef REQL_C_DEV_JSON_H_
#define REQL_C_DEV_JSON_H_

#include "./c/json.h"

extern void
reql_set_term_type(ReQL_Obj_t *obj, const ReQL_Term_t type);

extern void
reql_set_args(ReQL_Obj_t *obj, ReQL_Obj_t *args);

extern ReQL_Obj_t *
reql_args(const ReQL_Obj_t *obj);

extern void
reql_set_kwargs(ReQL_Obj_t *obj, ReQL_Obj_t *kwargs);

extern ReQL_Obj_t *
reql_kwargs(const ReQL_Obj_t *obj);

extern char
reql_op_eq(const ReQL_Obj_t *l, const ReQL_Obj_t *r);

#endif  // REQL_C_DEV_JSON_H_
