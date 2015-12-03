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

#ifndef REQL_REQL_DECODE_HPP_
#define REQL_REQL_DECODE_HPP_

#include "./reql/parser.hpp"
#include "./reql/types.hpp"

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <locale>
#include <sstream>
#include <string>

namespace _ReQL {

static void
isspace(const char *it, const char *end) {
  while (std::isspace(*it, std::locale("en_US.UTF8"))) {
    if (it >= end) {
      throw std::exception();
    }
    ++it;
  }
}

static bool
isnext(const char *it, const char *end, const char expect) {
  isspace(it, end);
  if (*it == expect) {
    ++it;
    return true;
  }
  return false;
}

static char
strtoh(const char *it, const char *end) {
  if (it + 4 >= end) {
    throw std::exception();
  }
  if (!(*(it) == '0' && *(++it) == '0')) {
    throw std::exception();
  }
  char hex = *(++it);
  if (hex >= '0' && hex <= '9') {
    hex -= '0';
  } else if (hex >= 'a' && hex <= 'f') {
    hex -= 'a' - 10;
  } else if (hex >= 'a' && hex <= 'f') {
    hex -= 'A' - 10;
  } else {
    throw std::exception();
  }
  char res = hex << 8;
  hex = *(++it);
  if (hex >= '0' && hex <= '9') {
    hex -= '0';
  } else if (hex >= 'a' && hex <= 'f') {
    hex -= 'a' - 10;
  } else if (hex >= 'a' && hex <= 'f') {
    hex -= 'A' - 10;
  } else {
    throw std::exception();
  }
  return res | hex;
}

template <class result_t>
static void
decode(const char *it, const char *end, Parser_t<result_t> &p) {
  isspace(it, end);
  switch (*it) {
    case '"': {
      ++it;
      std::stringstream stream;
      auto esc = false;
      while (it < end) {
        if (esc) {
          switch (*it) {
            case 'b': {
              stream << '\b';
              break;
            }
            case 'f': {
              stream << '\f';
              break;
            }
            case 'n': {
              stream << '\n';
              break;
            }
            case 'r': {
              stream << '\r';
              break;
            }
            case 't': {
              stream << '\t';
              break;
            }
            case 'u': {
              stream << strtoh(++it, end);
              break;
            }
            default: {
              stream << *it;
            }
          }
          esc = false;
        } else if (*it == '\\') {
          esc = true;
        } else if (*it == '"') {
          ++it;
          auto string = stream.str();
          return p.addValue(string.c_str(), string.size());
        } else {
          stream << *it;
        }
        ++it;
      }
      throw std::exception();
    }
    case '[': {
      p.startArray();
      ++it;
      while (it < end) {
        if (isnext(it, end, ']')) {
          return p.endArray();
        }
        decode(it, end, p);
        if (!isnext(it, end, ',')) {
          if (isnext(it, end, ']')) {
            return p.endArray();
          } else {
            throw std::exception();
          }
        }
      }
      throw std::exception();
    }
    case '{': {
      p.startObject();
      ++it;
      if (isnext(it, end, '}')) {
        return p.endObject();
      }
      while (it < end) {
        isspace(it, end);
        if (!(*it == '"')) {
          throw std::exception();
        }
        p.startKeyValue();
        decode(it, end, p);
        if (!isnext(it, end, ':')) {
          throw std::exception();
        }
        decode(it, end, p);
        if (!isnext(it, end, ',')) {
          if (isnext(it, end, '}')) {
            return p.endObject();
          } else {
            throw std::exception();
          }
        }
      }
      throw std::exception();
    }
    case 'f': {
      if (it + 5 >= end) {
        throw std::exception();
      }
      if (std::memcmp(reinterpret_cast<const void *>(&*it), "false", 5) != 0) {
        throw std::exception();
      }
      return p.addValue(false);
      break;
    }
    case 'n': {
      if (it + 4 >= end) {
        throw std::exception();
      }
      if (std::memcmp(reinterpret_cast<const void *>(&*it), "null", 4) != 0) {
        throw std::exception();
      }
      return p.addValue();
    }
    case 't': {
      if (it + 4 >= end) {
        throw std::exception();
      }
      if (std::memcmp(reinterpret_cast<const void *>(&*it), "true", 4) != 0) {
        throw std::exception();
      }
      return p.addValue(true);
    }
    case '-':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
      char *end_ptr = nullptr;
      double num = std::strtod(it, &end_ptr);
      if (end_ptr == nullptr) {
        throw std::exception();
      }
      return p.addValue(num);
    }
  }
  throw std::exception();
}

}  // namespace _ReQL

#endif  // REQL_REQL_DECODE_HPP_
