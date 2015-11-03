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

#include "./reql/error.hpp"

static ReQL_Error_Type_t p_err = REQL_E_NO;
static const char *p_msg = "";
static const char *p_trace = "";

extern const char *
reql_error_msg() {
  return p_msg;
}

extern const char *
reql_error_trace() {
  return p_trace;
}

extern ReQL_Error_Type_t
reql_error_type() {
  return p_err;
}

extern void
reql_error_init(ReQL_Error_Type_t err, const char *msg, const char *trace) {
  p_err = err;
  p_msg = msg;
  p_trace = trace;
}
