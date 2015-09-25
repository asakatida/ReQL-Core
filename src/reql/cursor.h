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

#ifndef REQL_REQL_CURSOR_H_
#define REQL_REQL_CURSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "./reql/connection.h"
#include "./reql/query.h"

extern void
reql_cur_set_end_cb(ReQL_Cur_t *cur, ReQL_End_Function cb, void *arg);

extern void
reql_cur_set_error_cb(ReQL_Cur_t *cur, ReQL_Error_Function cb, void *arg);

extern void
reql_cur_destroy(ReQL_Cur_t *cur);

extern void
reql_cur_drain(ReQL_Cur_t *cur);

extern ReQL_Obj_t *
reql_cur_next(ReQL_Cur_t *cur);

extern void
reql_cur_each(ReQL_Cur_t *cur, ReQL_Each_Function cb, void *arg);

extern ReQL_Obj_t *
reql_cur_to_array(ReQL_Cur_t *cur);

extern char
reql_cur_open(ReQL_Cur_t *cur);

extern void
reql_cur_close(ReQL_Cur_t *cur);

extern void
reql_cur_init(ReQL_Cur_t *cur, ReQL_Conn_t *conn, ReQL_Token token);

extern void
reql_cur_set_response(ReQL_Cur_t *cur, ReQL_Obj_t *res);

#ifdef __cplusplus
}
#endif

#endif  // REQL_REQL_CURSOR_H_
