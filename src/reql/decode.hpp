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

#include "./reql/types.hpp"

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <locale>
#include <string>

namespace _ReQL {

template <class str_t>
static void
isspace(typename str_t::iterator it, typename str_t::const_iterator &end) {
  while (std::isspace(static_cast<char>(*it), std::locale("en_US.UTF8"))) {
    if (it == end) {
      throw std::exception();
    }
    ++it;
  }
}

template <class str_t>
static auto
isnext(typename str_t::iterator it, typename str_t::const_iterator &end, const typename str_t::value_type &expect) {
  isspace<str_t>(it, end);
  if (*it == expect) {
    ++it;
    return true;
  }
  return false;
}

template <class parser_t, class str_t>
static void
decode(const str_t &json, typename str_t::iterator it, typename str_t::const_iterator end, parser_t &p) {
  isspace<str_t>(it, end);
  switch (*it) {
    case '"': {
      ++it;
      auto esc = false;
      auto start = it;
      auto track = it;
      while (it != end) {
        auto res = *it;
        if (esc) {
          switch (res) {
            case 'b': {
              res = '\b';
              break;
            }
            case 'f': {
              res = '\f';
              break;
            }
            case 'n': {
              res = '\n';
              break;
            }
            case 'r': {
              res = '\r';
              break;
            }
            case 't': {
              res = '\t';
              break;
            }
            case 'u': {
              if (it + 4 >= end) {
                throw std::exception();
              }
              if (!(*(++it) == '0' && *(++it) == '0')) {
                throw std::exception();
              }
              ++it;
              if (!(ishexnumber(*(it + 1)) && ishexnumber(*it))) {
                throw std::exception();
              }
              auto hex = *it;
              if (hex >= '0' && hex <= '9') {
                hex -= '0';
              } else if (hex >= 'a' && hex <= 'f') {
                hex -= 'a' - 10;
              } else {
                hex -= 'A' - 10;
              }
              res = hex * 16;
              ++it;
              hex = *it;
              if (hex >= '0' && hex <= '9') {
                hex -= '0';
              } else if (hex >= 'a' && hex <= 'f') {
                hex -= 'a' - 10;
              } else {
                hex -= 'A' - 10;
              }
              res += hex;
              break;
            }
          }
          esc = false;
        } else if (*it == '\\') {
          esc = true;
        } else if (*it == '"') {
          ++it;
          return p.addValue(std::string(start, static_cast<size_t>(track - start)));
        }
        ++track;
        ++it;
      }
      throw std::exception();
    }
    case '[': {
      p.startArray();
      ++it;
      while (it != end) {
        if (isnext<str_t>(it, end, ']')) {
          return p.endArray();
        }
        p.startElement();
        decode(json, it, end, p);
        p.endElement();
        if (!isnext<str_t>(it, end, ',')) {
          if (isnext<str_t>(it, end, ']')) {
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
      if (isnext<str_t>(it, end, '}')) {
        return p.endObject();
      }
      while (it != end) {
        p.startKeyValue();
        decode(json, it, end, p);
        if (!isnext<str_t>(it, end, ':')) {
          throw std::exception();
        }
        decode(json, it, end, p);
        if (!isnext<str_t>(it, end, ',')) {
          if (isnext<str_t>(it, end, '}')) {
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
      double num = std::strtod(reinterpret_cast<const char *>(&*it), &end_ptr);
      if (end_ptr == nullptr) {
        throw std::exception();
      }
      return p.addValue(num);
    }
  }
  throw std::exception();
}

template <class parser_t, class str_t>
void
decode(str_t &json, parser_t &p) {
  p.startParse();
  try {
    decode(json, json.begin(), json.cend(), p);
  } catch (std::exception &e) {
    return p.error(e);
  }
  p.endParse();
}

}  // namespace _ReQL

#endif  // REQL_REQL_DECODE_HPP_
