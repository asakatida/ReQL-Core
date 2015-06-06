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
#include "./reql/expr.h"

#include <pthread.h>

typedef int(^ReQL_Each_Function)(ReQL_Obj_t *, void *);
typedef int(^ReQL_End_Function)(void *);
typedef int(^ReQL_Error_Function)(ReQL_Obj_t *, void *);

enum ReQL_Response_e {
  REQL_CLIENT_ERROR = 16,
  REQL_COMPILE_ERROR = 17,
  REQL_RUNTIME_ERROR = 18,
  REQL_SUCCESS_ATOM = 1,
  REQL_SUCCESS_PARTIAL = 3,
  REQL_SUCCESS_SEQUENCE = 2,
  REQL_WAIT_COMPLETE = 4
};
typedef enum ReQL_Response_e ReQL_Response_t;

struct ReQL_Cur_s {
  struct {
    pthread_mutex_t *mutex;
  } condition;
  ReQL_Token token;
  struct ReQL_Conn_s *conn;
  ReQL_Iter_t it;
  ReQL_Obj_t *response;
  ReQL_Obj_t *old_res;
  struct ReQL_Cur_s *next;
  struct ReQL_Cur_s *prev;
  struct {
    void *each_data;
    ReQL_Each_Function each;
    void *end_data;
    ReQL_End_Function end;
    void *error_data;
    ReQL_Error_Function error;
  } cb;
};
typedef struct ReQL_Cur_s ReQL_Cur_t;

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
reql_cur_init(ReQL_Cur_t *cur, struct ReQL_Conn_s *conn, ReQL_Token token);

extern void
reql_cur_set_response(ReQL_Cur_t *cur, ReQL_Obj_t *res);

#ifdef __cplusplus
}
#endif

#endif  // REQL_REQL_CURSOR_H_
