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

#ifndef REQL_C_DEV_CHAR_H_
#define REQL_C_DEV_CHAR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "./c/types.h"

enum {
  char_left_square_bracket = 0x5B,
  char_right_square_bracket = 0x5D,
  char_left_curly_bracket = 0x7B,
  char_right_curly_bracket = 0x7D,
  char_colon = 0x3A,
  char_comma = 0x2C,
  char_quotation = 0x22,
  char_reverse_solidus = 0x5C,
};

static const ReQL_Byte left_square_bracket = char_left_square_bracket;
static const ReQL_Byte right_square_bracket = char_right_square_bracket;
static const ReQL_Byte left_curly_bracket = char_left_curly_bracket;
static const ReQL_Byte right_curly_bracket = char_right_curly_bracket;
static const ReQL_Byte colon = char_colon;
static const ReQL_Byte comma = char_comma;
static const ReQL_Byte quotation = char_quotation;
static const ReQL_Byte reverse_solidus = char_reverse_solidus;

static const ReQL_Byte json_true[4] = {0x74, 0x72, 0x75, 0x65};
static const ReQL_Byte json_false[5] = {0x66, 0x61, 0x6C, 0x73, 0x65};
static const ReQL_Byte json_null[4] = {0x6E, 0x75, 0x6C, 0x6C};

extern const ReQL_Byte *
reql_json_string_esc(const ReQL_Byte chr);

extern ReQL_Size
reql_json_string_esc_size(const ReQL_Byte chr);

#ifdef __cplusplus
}
#endif

#endif  // REQL_C_DEV_CHAR_H_
