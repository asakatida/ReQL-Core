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

#ifndef REQL_C_TYPES_H_
#define REQL_C_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "./reql/core.h"

#include "./c/query.h"

#include <pthread.h>

struct ReQL_s {
  ReQL_Obj_t *(*cb)(struct ReQL_s *obj);
  void (*free)(struct ReQL_s *obj);
  void *data;
  size_t size;
  size_t refc;
  pthread_mutex_t *mutex;
};

struct ReQL_Func_Data_s {
  ReQL_Function func;
};
typedef struct ReQL_Func_Data_s ReQL_Func_Data_t;

struct ReQL_Args_s {
  struct ReQL_s *args;
  ReQL_AST_Function func;
};
typedef struct ReQL_Args_s ReQL_Args_t;

struct ReQL_Kwargs_s {
  struct ReQL_s *args;
  struct ReQL_s *kwargs;
  ReQL_AST_Function_Kwargs func;
};
typedef struct ReQL_Kwargs_s ReQL_Kwargs_t;

struct ReQL_Connection_s {
  ReQL_Conn_t *connection;
};

struct ReQL_Result_s {
  ReQL_Obj_t *object;
};

struct ReQL_Cursor_s {
  ReQL_Cur_t *cursor;
  int (*cb)(struct ReQL_Result_s *res, void *data);
  void *data;
};

struct ReQL_Error_s {
  int code;
};

#ifdef __cplusplus
}
#endif

#endif  // REQL_C_TYPES_H_
