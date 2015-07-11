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

#ifndef REQL_REQL_TYPES_H_
#define REQL_REQL_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>

typedef uint8_t ReQL_Byte;
typedef uint32_t ReQL_Size;
typedef uint64_t ReQL_Token;

typedef struct ReQL_Conn_s ReQL_Conn_t;
typedef struct ReQL_Cur_s ReQL_Cur_t;
typedef struct ReQL_Iter_s ReQL_Iter_t;
typedef struct ReQL_Obj_s ReQL_Obj_t;
typedef struct ReQL_Pair_s ReQL_Pair_t;
typedef struct ReQL_String_s ReQL_String_t;

typedef int(*ReQL_Each_Function)(ReQL_Obj_t *, void *);
typedef void(*ReQL_End_Function)(void *);
typedef void(*ReQL_Error_Function)(ReQL_Obj_t *, void *);

/**
 * @brief JSON types.
 */
enum ReQL_Datum_e {
  REQL_R_REQL,
  REQL_R_ARRAY = 5,
  REQL_R_BOOL = 2,
  REQL_R_JSON = 7,
  REQL_R_NULL = 1,
  REQL_R_NUM = 3,
  REQL_R_OBJECT = 6,
  REQL_R_STR = 4
};
typedef enum ReQL_Datum_e ReQL_Datum_t;

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

struct ReQL_String_s {
  ReQL_Size size;
  ReQL_Size alloc_size;
  ReQL_Byte *str;
};

/**
 * @brief A single key and associated value for objects.
 */
struct ReQL_Pair_s {
  ReQL_Obj_t *key;
  ReQL_Obj_t *val;
};

/**
 * @brief Iterator for easy enumeration.
 *
 * Supports objects and arrays.
 */
struct ReQL_Iter_s {
  ReQL_Size idx;
  const ReQL_Obj_t *obj;
};

/**
 * @brief Represents a single node in a query tree.
 */
struct ReQL_Obj_s {
  int tt;
  union {
    struct {
      ReQL_Datum_t dt;
      union {
        struct {
          ReQL_Size size;
          ReQL_Size alloc_size;
          union {
            ReQL_Byte *str;
            ReQL_Obj_t **array;
            ReQL_Pair_t *pair;
          } data;
        } var;
        double number;
        char boolean;
      } json;
    } datum;
    struct {
      ReQL_Obj_t *args;
      ReQL_Obj_t *kwargs;
    } args;
  } obj;
  ReQL_Obj_t *owner;
};

struct ReQL_Cur_s {
  struct {
    pthread_mutex_t *mutex;
    pthread_t thread;
  } condition;
  ReQL_Token token;
  ReQL_Obj_t *response;
  ReQL_Conn_t *conn;
  ReQL_Cur_t *next;
  ReQL_Cur_t *prev;
  struct {
    void *data[3];
    ReQL_Each_Function each;
    ReQL_End_Function end;
    ReQL_Error_Function error;
  } cb;
};

/**
 * @brief connection object
 */
struct ReQL_Conn_s {
  ReQL_Size auth_size;
  int socket;

  ReQL_Token max_token;

  ReQL_Token timeout_s;
  ReQL_Token timeout_us;

  char *port;
  char *addr;

  char *auth;
  ReQL_Cur_t *cursors;

  struct {
    pthread_mutex_t *mutex;
    pthread_t thread;
  } condition;
};

#ifdef __cplusplus
}
#endif

#endif  // REQL_REQL_TYPES_H_
