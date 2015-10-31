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

static const ReQL_Byte json_char_0x00[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x30};
static const ReQL_Byte json_char_0x01[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x31};
static const ReQL_Byte json_char_0x02[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x32};
static const ReQL_Byte json_char_0x03[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x33};
static const ReQL_Byte json_char_0x04[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x34};
static const ReQL_Byte json_char_0x05[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x35};
static const ReQL_Byte json_char_0x06[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x36};
static const ReQL_Byte json_char_0x07[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x37};
static const ReQL_Byte json_char_backspace[2] = {
  char_reverse_solidus, 0x62};
static const ReQL_Byte json_char_tab[2] = {
  char_reverse_solidus, 0x74};
static const ReQL_Byte json_char_linefeed[2] = {
  char_reverse_solidus, 0x6E};
static const ReQL_Byte json_char_0x0B[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x42};
static const ReQL_Byte json_char_formfeed[2] = {
  char_reverse_solidus, 0x66};
static const ReQL_Byte json_char_carriage_return[2] = {
  char_reverse_solidus, 0x72};
static const ReQL_Byte json_char_0x0E[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x45};
static const ReQL_Byte json_char_0x0F[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x46};
static const ReQL_Byte json_char_0x10[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x30};
static const ReQL_Byte json_char_0x11[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x31};
static const ReQL_Byte json_char_0x12[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x32};
static const ReQL_Byte json_char_0x13[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x33};
static const ReQL_Byte json_char_0x14[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x34};
static const ReQL_Byte json_char_0x15[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x35};
static const ReQL_Byte json_char_0x16[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x36};
static const ReQL_Byte json_char_0x17[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x37};
static const ReQL_Byte json_char_0x18[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x38};
static const ReQL_Byte json_char_0x19[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x39};
static const ReQL_Byte json_char_0x1A[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x41};
static const ReQL_Byte json_char_0x1B[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x42};
static const ReQL_Byte json_char_0x1C[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x43};
static const ReQL_Byte json_char_0x1D[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x44};
static const ReQL_Byte json_char_0x1E[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x45};
static const ReQL_Byte json_char_0x1F[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x46};
static const ReQL_Byte json_char_quotation[2] = {
  char_reverse_solidus, char_quotation};
static const ReQL_Byte json_char_reverse_solidus[2] = {
  char_reverse_solidus, char_reverse_solidus};

static const ReQL_Byte *
reql_json_string_esc(const ReQL_Byte chr) {
  switch (chr) {
    case 0x00: return json_char_0x00;
    case 0x01: return json_char_0x01;
    case 0x02: return json_char_0x02;
    case 0x03: return json_char_0x03;
    case 0x04: return json_char_0x04;
    case 0x05: return json_char_0x05;
    case 0x06: return json_char_0x06;
    case 0x07: return json_char_0x07;
    case 0x08: return json_char_backspace;
    case 0x09: return json_char_tab;
    case 0x0A: return json_char_linefeed;
    case 0x0B: return json_char_0x0B;
    case 0x0C: return json_char_formfeed;
    case 0x0D: return json_char_carriage_return;
    case 0x0E: return json_char_0x0E;
    case 0x0F: return json_char_0x0F;
    case 0x10: return json_char_0x10;
    case 0x11: return json_char_0x11;
    case 0x12: return json_char_0x12;
    case 0x13: return json_char_0x13;
    case 0x14: return json_char_0x14;
    case 0x15: return json_char_0x15;
    case 0x16: return json_char_0x16;
    case 0x17: return json_char_0x17;
    case 0x18: return json_char_0x18;
    case 0x19: return json_char_0x19;
    case 0x1A: return json_char_0x1A;
    case 0x1B: return json_char_0x1B;
    case 0x1C: return json_char_0x1C;
    case 0x1D: return json_char_0x1D;
    case 0x1E: return json_char_0x1E;
    case 0x1F: return json_char_0x1F;
    case 0x22: return json_char_quotation;
    case 0x5C: return json_char_reverse_solidus;
    default: return nullptr;
  }
}

static ReQL_Size
reql_json_string_esc_size(const ReQL_Byte chr) {
  switch (chr) {
    case 0x00: return 6;
    case 0x01: return 6;
    case 0x02: return 6;
    case 0x03: return 6;
    case 0x04: return 6;
    case 0x05: return 6;
    case 0x06: return 6;
    case 0x07: return 6;
    case 0x08: return 2;
    case 0x09: return 2;
    case 0x0A: return 2;
    case 0x0B: return 6;
    case 0x0C: return 2;
    case 0x0D: return 2;
    case 0x0E: return 6;
    case 0x0F: return 6;
    case 0x10: return 6;
    case 0x11: return 6;
    case 0x12: return 6;
    case 0x13: return 6;
    case 0x14: return 6;
    case 0x15: return 6;
    case 0x16: return 6;
    case 0x17: return 6;
    case 0x18: return 6;
    case 0x19: return 6;
    case 0x1A: return 6;
    case 0x1B: return 6;
    case 0x1C: return 6;
    case 0x1D: return 6;
    case 0x1E: return 6;
    case 0x1F: return 6;
    case 0x22: return 2;
    case 0x5C: return 2;
    default: return 0;
  }
}

#endif  // REQL_REQL_CHAR_H_
