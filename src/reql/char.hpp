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

#ifndef REQL_REQL_CHAR_H_
#define REQL_REQL_CHAR_H_

#include "./reql/types.h"

static const ReQL_Byte char_left_square_bracket = '[';
static const ReQL_Byte char_right_square_bracket = ']';
static const ReQL_Byte char_left_curly_bracket = '{';
static const ReQL_Byte char_right_curly_bracket = '}';
static const ReQL_Byte char_colon = ':';
static const ReQL_Byte char_comma = ',';
static const ReQL_Byte char_quotation = '"';
static const ReQL_Byte char_reverse_solidus = '\\';

static const ReQL_Byte json_true[] = "true";
static const ReQL_Byte json_false[] = "false";
static const ReQL_Byte json_null[] = "null";

const ReQL_Byte *
reql_json_string_esc(const ReQL_Byte chr);

ReQL_Size
reql_json_string_esc_size(const ReQL_Byte chr);

#endif  // REQL_REQL_CHAR_H_
