/*
Copyright 2014 Adam Grandquist

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

typedef enum {
  _REQL_E_NO,
  _REQL_E_JSON
} _ReQL_Error_Type_t;

struct _ReQL_Error_s {
  _ReQL_Error_Type_t err;
  char *msg;
  char *trace;
};

typedef struct _ReQL_Error_s _ReQL_Error_t;

int _reql_error();

char *_reql_error_msg();
char *_reql_error_trace();
_ReQL_Error_Type_t _reql_error_type();

void _reql_error_init(_ReQL_Error_Type_t err, char *msg, char *trace);
