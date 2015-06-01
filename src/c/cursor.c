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

#include "./c/cursor.h"

#include "./reql/core.h"

#include <stdlib.h>

struct ReQL_Cursor_s {
  ReQL_Cur_t *cursor;
};

struct ReQL_Result_s {
  ReQL_Obj_t *object;
};

static ReQL_Result_t *
reql_result(ReQL_Obj_t *obj) {
  if (obj == NULL) {
    return NULL;
  }
  ReQL_Result_t *res = malloc(sizeof(ReQL_Result_t));
  if (res == NULL) {
    return NULL;
  }
  res->object = obj;
  return res;
}

extern void
reql_cursor_close(ReQL_Cursor_t *cur) {
  reql_cur_close(cur->cursor);
}

extern void *
reql_cursor_data(ReQL_Cursor_t *cur) {
  return cur->cursor;
}

extern void
reql_cursor_drain(ReQL_Cursor_t *cur) {
  reql_cur_drain(cur->cursor);
}

extern void
reql_cursor_each(ReQL_Cursor_t *cur, ReQL_Each cb, void *obj) {
  ReQL_Result_t *res = NULL;
  while ((res = reql_cursor_next(cur)) != NULL) {
    cb(res, obj);
    reql_result_destroy(res);
  }
}

extern void
reql_cursor_each_async(ReQL_Cursor_t *cur, ReQL_Each cb, void *obj) {
  (void)cur;
  (void)cb;
  (void)obj;
}

extern ReQL_Result_t *
reql_cursor_next(ReQL_Cursor_t *cur) {
  ReQL_Obj_t *next = reql_cur_next(cur->cursor);
  ReQL_Result_t *res = reql_result(next);
  if (res == NULL) {
    reql_json_destroy(next);
  }
  return res;
}

extern void
reql_result_destroy(ReQL_Result_t *result) {
  reql_json_destroy(result->object);
  free(result);
}

extern ReQL_Result_t *
reql_result_object_get(ReQL_Result_t *result, char *key, unsigned long key_size) {
  (void)result;
  (void)key;
  (void)key_size;
  return NULL;
}

extern ReQL_Result_t *
reql_result_object_keys(ReQL_Result_t *result) {
  (void)result;
  return NULL;
}

extern unsigned long
reql_result_size(ReQL_Result_t *result) {
  (void)result;
  return 0;
}

extern ReQL_Result_t *
reql_result_to_array(ReQL_Result_t *result) {
  (void)result;
  return NULL;
}

extern int
reql_result_to_bool(ReQL_Result_t *result) {
  (void)result;
  return 0;
}

extern double
reql_result_to_number(ReQL_Result_t *result) {
  (void)result;
  return 0;
}

extern char *
reql_result_to_string(ReQL_Result_t *result) {
  (void)result;
  return NULL;
}
