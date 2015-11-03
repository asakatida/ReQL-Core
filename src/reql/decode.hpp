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

#include "./reql/char.hpp"

#include "./reql/cursor.hpp"
#include "./reql/query.hpp"
#include "./reql/types.hpp"

#include <cctype>
#include <locale>
#include <string>

template <class s>
class Parser {
public:
  Parser(ReQL_Parse_t *parser, ReQL_Cur_t *cursor) : p_parser(parser), p_cursor(cursor) {}

  void startParse() {}
  void endParse() {}

  void startObject() {}
  void startKeyValue() {}
  void endKeyValue(const s &) {}
  void endObject() {}

  void startArray() {}
  void startElement() {}
  void endElement() {}
  void endArray() {}

  void addValue() {}
  void addValue(bool) {}
  void addValue(double) {}
  void addValue(const s &) {}

  void error(std::exception &err) { throw err; }

private:
  ReQL_Parse_t *p_parser;
  ReQL_Cur_t *p_cursor;
};

template <class iter>
static void
reql_space(iter &it, const iter &end) {
  while (std::isspace(static_cast<char>(*it), std::locale("en_US.UTF8"))) {
    if (it == end) {
      throw std::exception();
    }
    ++it;
  }
}

template <class iter>
static auto
reql_next_char(iter &it, const iter &end, const typename iter::value_type &expect) {
  reql_space(it, end);
  if (*it == expect) {
    ++it;
    return true;
  }
  return false;
}

template <class s>
static void
reql_decode_(s &json, typename s::iterator it, typename s::iterator end, Parser<s> &p) {
  reql_space(it, end);
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
          return p.addValue(s(&*start, static_cast<size_t>(track - start)));
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
        if (reql_next_char(it, end, ']')) {
          return p.endArray();
        }
        p.startElement();
        reql_decode_(json, it, end, p);
        p.endElement();
        if (!reql_next_char(it, end, ',')) {
          if (reql_next_char(it, end, ']')) {
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
      if (reql_next_char(it, end, '}')) {
        return p.endObject();
      }
      while (it != end) {
        p.startKeyValue();
        reql_decode_(json, it, end, p);
        if (!reql_next_char(it, end, ':')) {
          throw std::exception();
        }
        reql_decode_(json, it, end, p);
        if (!reql_next_char(it, end, ',')) {
          if (reql_next_char(it, end, '}')) {
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
      if (memcmp(reinterpret_cast<const void *>(&*it), json_false, 5) != 0) {
        throw std::exception();
      }
      return p.addValue(false);
      break;
    }
    case 'n': {
      if (it + 4 >= end) {
        throw std::exception();
      }
      if (memcmp(reinterpret_cast<const void *>(&*it), json_null, 4) != 0) {
        throw std::exception();
      }
      return p.addValue();
    }
    case 't': {
      if (it + 4 >= end) {
        throw std::exception();
      }
      if (memcmp(reinterpret_cast<const void *>(&*it), json_true, 4) != 0) {
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
      double num = strtod(reinterpret_cast<const char *>(&*it), &end_ptr);
      if (end_ptr == nullptr) {
        throw std::exception();
      }
      return p.addValue(num);
    }
  }
  throw std::exception();
}

template <class s>
void
reql_decode(s json, Parser<s> p) {
  p.startParse();
  try {
    reql_decode_(json, json.begin(), json.end(), p);
  } catch (std::exception &e) {
    return p.error(e);
  }
  p.endParse();
}

#endif  // REQL_REQL_DECODE_HPP_
