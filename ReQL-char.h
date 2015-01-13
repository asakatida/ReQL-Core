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

#include <stdint.h>

#ifndef _REQL_CHAR_H
#define _REQL_CHAR_H

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

static const uint8_t left_square_bracket = char_left_square_bracket;
static const uint8_t right_square_bracket = char_right_square_bracket;
static const uint8_t left_curly_bracket = char_left_curly_bracket;
static const uint8_t right_curly_bracket = char_right_curly_bracket;
static const uint8_t colon = char_colon;
static const uint8_t comma = char_comma;
static const uint8_t quotation = char_quotation;
static const uint8_t reverse_solidus = char_reverse_solidus;

static const uint8_t json_true[4] = {0x74, 0x72, 0x75, 0x65};
static const uint8_t json_false[5] = {0x66, 0x61, 0x6C, 0x73, 0x65};
static const uint8_t json_null[4] = {0x6E, 0x75, 0x6C, 0x6C};

extern const uint8_t *
_reql_json_string_esc(uint8_t chr);
extern const uint32_t
_reql_json_string_esc_size(uint8_t chr);

static const uint8_t json_char_0x00[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x30};
static const uint8_t json_char_0x01[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x31};
static const uint8_t json_char_0x02[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x32};
static const uint8_t json_char_0x03[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x33};
static const uint8_t json_char_0x04[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x34};
static const uint8_t json_char_0x05[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x35};
static const uint8_t json_char_0x06[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x36};
static const uint8_t json_char_0x07[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x37};
static const uint8_t json_char_backspace[2] = {
  char_reverse_solidus, 0x62};
static const uint8_t json_char_tab[2] = {
  char_reverse_solidus, 0x74};
static const uint8_t json_char_linefeed[2] = {
  char_reverse_solidus, 0x6E};
static const uint8_t json_char_0x0B[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x42};
static const uint8_t json_char_formfeed[2] = {
  char_reverse_solidus, 0x66};
static const uint8_t json_char_carriage_return[2] = {
  char_reverse_solidus, 0x72};
static const uint8_t json_char_0x0E[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x45};
static const uint8_t json_char_0x0F[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x30, 0x46};
static const uint8_t json_char_0x10[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x30};
static const uint8_t json_char_0x11[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x31};
static const uint8_t json_char_0x12[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x32};
static const uint8_t json_char_0x13[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x33};
static const uint8_t json_char_0x14[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x34};
static const uint8_t json_char_0x15[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x35};
static const uint8_t json_char_0x16[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x36};
static const uint8_t json_char_0x17[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x37};
static const uint8_t json_char_0x18[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x38};
static const uint8_t json_char_0x19[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x39};
static const uint8_t json_char_0x1A[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x41};
static const uint8_t json_char_0x1B[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x42};
static const uint8_t json_char_0x1C[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x43};
static const uint8_t json_char_0x1D[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x44};
static const uint8_t json_char_0x1E[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x45};
static const uint8_t json_char_0x1F[6] = {
  char_reverse_solidus, 0x75, 0x30, 0x30, 0x31, 0x46};
static const uint8_t json_char_quotation[2] = {
  char_reverse_solidus, char_quotation};
static const uint8_t json_char_reverse_solidus[2] = {
  char_reverse_solidus, char_reverse_solidus};

#endif
