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

#include "ReQL-expr.h"

#ifndef _REQL_CURSOR_H
#define _REQL_CURSOR_H

typedef enum {
  _REQL_CLIENT_ERROR = 16,
  _REQL_COMPILE_ERROR = 17,
  _REQL_RUNTIME_ERROR = 18,
  _REQL_SUCCESS_ATOM = 1,
  _REQL_SUCCESS_FEED = 5,
  _REQL_SUCCESS_PARTIAL = 3,
  _REQL_SUCCESS_SEQUENCE = 2,
  _REQL_WAIT_COMPLETE = 4
} _ReQL_Response_t;

struct _ReQL_Cur_s {
  char done;
  uint64_t token;
  struct _ReQL_Conn_s *conn;
  _ReQL_Obj_t *response;
  struct _ReQL_Cur_s *next;
  struct _ReQL_Cur_s *prev;
  void *mutex;
};
typedef struct _ReQL_Cur_s _ReQL_Cur_t;
typedef _ReQL_Cur_t* _ReQL_Cur;

extern void
_reql_cursor_init(_ReQL_Cur cur);
extern void
_reql_set_cur_response(_ReQL_Cur_t *cur, _ReQL_Obj_t *res);
extern _ReQL_Obj_t *
_reql_get_cur_res(_ReQL_Cur_t *cur);
extern void
_reql_cursor_next(_ReQL_Cur cur);
extern void
_reql_close_cur(_ReQL_Cur cur);

#endif
