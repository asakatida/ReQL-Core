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

#ifndef REQL_C_CURSOR_H_
#define REQL_C_CURSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  ReQL_Error,
  ReQL_Start_Object,
  ReQL_Start_Key_Value,
  ReQL_End_Key_Value,
  ReQL_End_Object,
  ReQL_Start_Array,
  ReQL_Start_Element,
  ReQL_End_Element,
  ReQL_End_Array,
  ReQL_Null,
  ReQL_Bool,
  ReQL_Number,
  ReQL_String
} ReQL_Parse_Event;

typedef struct ReQL_Cursor_s ReQL_Cursor_t;
typedef struct ReQL_Result_s ReQL_Result_t;
typedef int(*ReQL_Each)(ReQL_Result_t *result, void *obj);
typedef int(*ReQL_Parse)(ReQL_Result_t *result, ReQL_Parse_Event e, void *obj);

extern void
reql_cursor_close(ReQL_Cursor_t *cur);

extern void *
reql_cursor_data(ReQL_Cursor_t *cur);

extern void
reql_cursor_drain(ReQL_Cursor_t *cur);

extern void
reql_cursor_each(ReQL_Cursor_t *cur, ReQL_Each cb, void *obj);

extern void
reql_cursor_each_async(ReQL_Cursor_t *cur, ReQL_Each cb, void *obj);

extern void
reql_result_parse(ReQL_Result_t *result, ReQL_Parse cb, void *obj);

extern ReQL_Result_t *
reql_result_get(ReQL_Result_t *result, char *key, unsigned long key_size);

extern ReQL_Result_t **
reql_result_keys(ReQL_Result_t *result);

extern unsigned long
reql_result_size(ReQL_Result_t *result);

extern ReQL_Result_t **
reql_result_to_array(ReQL_Result_t *result);

extern int
reql_result_to_bool(ReQL_Result_t *result);

extern double
reql_result_to_number(ReQL_Result_t *result);

extern char *
reql_result_to_string(ReQL_Result_t *result);

#ifdef __cplusplus
}
#endif

#endif  // REQL_C_CURSOR_H_
