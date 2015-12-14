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

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <locale>
#include <map>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

namespace _ReQL {

template <class result_t>
class Decoder_t {
public:
  void
  decode(const char *it, const char *end) {
    isspace(it, end);
    switch (*it) {
      case '"': {
        ++it;
        std::wostringstream stream;
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
                if (it + 4 >= end) {
                  throw std::exception();
                }
                stream << strtoh(++it);
                it += 4;
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
            return addValue(string.c_str(), string.size());
          } else {
            stream << *it;
          }
          ++it;
        }
        throw std::exception();
      }
      case '[': {
        startArray();
        ++it;
        while (it < end) {
          if (isnext(it, end, ']')) {
            return endArray();
          }
          decode(it, end);
          if (!isnext(it, end, ',')) {
            if (isnext(it, end, ']')) {
              return endArray();
            } else {
              throw std::exception();
            }
          }
        }
        throw std::exception();
      }
      case '{': {
        startObject();
        ++it;
        if (isnext(it, end, '}')) {
          return endObject();
        }
        while (it < end) {
          isspace(it, end);
          if (!(*it == '"')) {
            throw std::exception();
          }
          startKeyValue();
          decode(it, end);
          if (!isnext(it, end, ':')) {
            throw std::exception();
          }
          decode(it, end);
          if (!isnext(it, end, ',')) {
            if (isnext(it, end, '}')) {
              return endObject();
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
        return addValue(false);
        break;
      }
      case 'n': {
        if (it + 4 >= end) {
          throw std::exception();
        }
        if (std::memcmp(reinterpret_cast<const void *>(&*it), "null", 4) != 0) {
          throw std::exception();
        }
        return addValue();
      }
      case 't': {
        if (it + 4 >= end) {
          throw std::exception();
        }
        if (std::memcmp(reinterpret_cast<const void *>(&*it), "true", 4) != 0) {
          throw std::exception();
        }
        return addValue(true);
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
        return addValue(num);
      }
    }
    throw std::exception();
  }

  int r_type() { return p_r_type; }

  std::vector<result_t> get() { return p_result; }

  void addValue() { p_stack.push_back(result_t()); }

  void addValue(const bool value) { p_stack.push_back(result_t(value)); }

  void addValue(const double value) {
    if (p_is_r_type) {
      p_r_type = static_cast<int>(value);
      p_is_r_type = false;
    }
    p_stack.push_back(result_t(value));
  }

  void addValue(const wchar_t *value, size_t size) {
    if (p_level == 1 && p_is_key && size == 1) {
      switch (value[0]) {
        case 'b': {
          p_is_backtrace = true;
          break;
        }
        case 'n': {
          p_is_notes = true;
          break;
        }
        case 'p': {
          p_is_profile = true;
          break;
        }
        case 'r': {
          p_is_response = true;
          break;
        }
        case 't': {
          p_is_r_type = true;
          break;
        }
        default: {
          throw std::exception();
          break;
        }
      }
    }
    p_stack.push_back(result_t(value, size));
    p_is_key = false;
  }

  void startArray() {
    p_arrays.push_back(std::vector<result_t>());
    ++p_level;
  }

  void endArray() {
    p_stack.push_back(result_t(p_arrays.back()));
    p_arrays.pop_back();
    --p_level;
  }

  void startObject() {
    p_objects.push_back(std::map<std::wstring, result_t>());
    p_is_key = false;
    ++p_level;
  }

  void startKeyValue() { p_is_key = true; }

  void endObject() {
    p_stack.push_back(result_t(p_objects.back()));
    p_objects.pop_back();
    --p_level;
  }

private:

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
  strtoh(const char hex) {
    if (hex >= '0' && hex <= '9') {
      return hex - '0';
    } else if (hex >= 'a' && hex <= 'f') {
      return hex - ('a' - 10);
    } else if (hex >= 'A' && hex <= 'F') {
      return hex - ('A' - 10);
    } else {
      throw std::exception();
    }
  }

  static wchar_t
  strtoh(const char *it) {
    return (static_cast<wchar_t>(strtoh(*it)) << 12) |
    (static_cast<wchar_t>(strtoh(*(it + 1))) << 8) |
    (static_cast<wchar_t>(strtoh(*(it + 2))) << 4) |
    strtoh(*(it + 3));
  }

  std::vector<std::vector<result_t> > p_arrays;
  std::vector<result_t> p_backtrace;
  bool p_is_backtrace;
  bool p_is_key;
  bool p_is_notes;
  bool p_is_profile;
  bool p_is_r_type;
  bool p_is_response;
  size_t p_level;
  std::vector<int> p_notes;
  std::vector<std::map<std::wstring, result_t> > p_objects;
  int p_r_type;
  std::vector<result_t> p_result;
  std::vector<result_t> p_stack;
  std::queue<std::unique_ptr<const char> > p_queue;
};

}  // namespace _ReQL

#endif  // REQL_REQL_DECODE_HPP_
