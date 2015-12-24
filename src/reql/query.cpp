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

#include "./reql/query.h"

#include "./reql/types.h"

#include "./reql/core/query.hpp"

struct ReQL_s {};

extern ReQL_t *
reql_array(ReQL_t **val) {
  (void)val;
  return nullptr;
}

extern ReQL_t *
reql_bool(const int val) {
  (void)val;
  return nullptr;
}

extern ReQL_t *
reql_c_string(const wchar_t *val) {
  (void)val;
  return nullptr;
}

extern int
_reql_release(ReQL_t *reql) {
  (void)reql;
  return -1;
}

extern void
reql_retain(ReQL_t *reql) {
  (void)reql;
}

extern ReQL_t *
reql_function(ReQL_Function val, const unsigned int nargs) {
  (void)val;
  (void)nargs;
  return nullptr;
}

extern ReQL_t *
reql_json_object(ReQL_t **val) {
  (void)val;
  return nullptr;
}

extern ReQL_t *
reql_null() {
  return nullptr;
}

extern ReQL_t *
reql_number(double val) {
  (void)val;
  return nullptr;
}

extern ReQL_t *
reql_string(const wchar_t *val, const unsigned long size) {
  (void)val;
  (void)size;
  return nullptr;
}

extern ReQL_Cursor_t *
reql_run(ReQL_t *query, ReQL_t *kwargs, ReQL_Connection_t *conn) {
  (void)query;
  (void)kwargs;
  (void)conn;
  return nullptr;
}

extern int
reql_noreply(ReQL_t *query, ReQL_t *kwargs, ReQL_Connection_t *conn) {
  (void)query;
  (void)kwargs;
  (void)conn;
  return -1;
}

extern ReQL_t *
reql_add(ReQL_t **args) {
  (void)args;
  return nullptr;
}

extern ReQL_t *
reql_zip(ReQL_t **args) {
  (void)args;
  return nullptr;
}
