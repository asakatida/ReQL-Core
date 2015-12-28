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

#include "./cursor.h"

#include "./types.h"

#include "./core/connection.hpp"

struct ReQL_Cursor_s {};

struct ReQL_Result_s {};

extern void
reql_cursor_close(ReQL_Cursor_t *cur) {
  (void)cur;
}

extern void
reql_cursor_drain(ReQL_Cursor_t *cur) {
  (void)cur;
}

extern void
reql_cursor_each(ReQL_Cursor_t *cur, ReQL_Each cb, void *obj) {
  (void)cur;
  (void)cb;
  (void)obj;
}

extern void
reql_cursor_each_async(ReQL_Cursor_t *cur, ReQL_Each cb, void *obj) {
  (void)cur;
  (void)cb;
  (void)obj;
}

extern void
reql_result_parse(ReQL_Result_t *result, ReQL_Parse cb, void *obj) {
  (void)result;
  (void)cb;
  (void)obj;
}

extern ReQL_Result_t *
reql_result_get(ReQL_Result_t *result, const wchar_t *key, unsigned long key_size) {
  (void)result;
  (void)key;
  (void)key_size;
  return nullptr;
}

extern ReQL_Result_t **
reql_result_to_array(ReQL_Result_t *result) {
  (void)result;
  return nullptr;
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
  return nullptr;
}
