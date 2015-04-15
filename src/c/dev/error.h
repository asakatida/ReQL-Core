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

#ifndef REQL_C_DEV_ERROR_H_
#define REQL_C_DEV_ERROR_H_

typedef enum {
  REQL_E_NO,
  REQL_E_JSON
} ReQL_Error_Type_t;

extern char *
reql_error_msg();

extern char *
reql_error_trace();

extern ReQL_Error_Type_t
reql_error_type();

extern void
reql_error_init(ReQL_Error_Type_t err, char *msg, char *trace);

#endif  // REQL_C_DEV_ERROR_H_
