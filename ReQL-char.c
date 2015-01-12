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

#include "ReQL-char.h"

#include <stdlib.h>

extern const uint8_t *
_reql_json_string_esc(uint8_t chr) {
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
    default: return NULL;
  }
}

extern const uint32_t
_reql_json_string_esc_size(uint8_t chr) {
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
