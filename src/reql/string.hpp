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

#ifndef REQL_REQL_STRING_HPP_
#define REQL_REQL_STRING_HPP_

#include <iostream>

namespace _ReQL {

template <class str_t>
struct String_t : public str_t {
  String_t(const str_t &value) : str_t(value) {}
  String_t(str_t &&value) : str_t(std::move(value)) {}
};

template <class str_t>
String_t<str_t>
make_string(const str_t &str) {
  return str;
}

template <class str_t>
std::ostream &
operator <<(std::ostream &stream, const String_t<str_t> &value) {
  const char *json_esc[] = {
    "\\u0000", "\\u0001", "\\u0002", "\\u0003",  // 0x03
    "\\u0004", "\\u0005", "\\u0006", "\\u0007",  // 0x07
    "\\b", "\\t", "\\n", "\\u000B",  // 0x0B
    "\\f", "\\r", "\\u000E", "\\u000F",  // 0x0F
    "\\u0010", "\\u0011", "\\u0012", "\\u0013",  // 0x13
    "\\u0014", "\\u0015", "\\u0016", "\\u0017",  // 0x17
    "\\u0018", "\\u0019", "\\u001A", "\\u001B",  // 0x1B
    "\\u001C", "\\u001D", "\\u001E", "\\u001F",  // 0x1F
    "\x20", "\x21", "\\\"", "\x23", "\x24", "\x25", "\x26", "\x27",  // 0x28
    "\x28", "\x29", "\x2A", "\x2B", "\x2C", "\x2D", "\x2E", "\x2F",  // 0x2F
    "\x30", "\x31", "\x32", "\x33", "\x34", "\x35", "\x36", "\x37",  // 0x37
    "\x38", "\x39", "\x3A", "\x3B", "\x3C", "\x3D", "\x3E", "\x3F",  // 0x3F
    "\x40", "\x41", "\x42", "\x43", "\x44", "\x45", "\x46", "\x47",  // 0x47
    "\x48", "\x49", "\x4A", "\x4B", "\x4C", "\x4D", "\x4E", "\x4F",  // 0x4F
    "\x50", "\x51", "\x52", "\x53", "\x54", "\x55", "\x56", "\x57",  // 0x57
    "\x58", "\x59", "\x5A", "\x5B", "\\\\"  // 0x5C
  };

  const char *hex = "0123456789ABCDEF";

  stream << '"';
  for (const auto chr : value) {
    auto idx = static_cast<const unsigned int>(chr);
    if (idx > 0xFFFF) {
    } else if (idx > 0xFF) {
      stream << "\\u"
      << hex[(idx >> 12) & 0xF]
      << hex[(idx >> 8) & 0xF]
      << hex[(idx >> 4) & 0xF]
      << hex[(idx >> 0) & 0xF];
    } else if (idx > 0x5C) {
      stream << static_cast<const char>(idx);
    } else {
      stream << json_esc[idx];
    }
  }
  return stream << '"';
}

}  // namespace _ReQL

#endif  // REQL_REQL_STRING_HPP_
