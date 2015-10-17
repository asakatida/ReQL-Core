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

#ifndef REQL_REQL_DECODE_H_
#define REQL_REQL_DECODE_H_

#include "./reql/char.hpp"

#include "./reql/query.h"
#include "./reql/types.h"

#include <cctype>
#include <locale>
#include <string>

template <class iter>
static auto
reql_space(iter &it, const iter &end) {
  while (std::isspace(static_cast<char>(*it), std::locale("en_US.UTF8"))) {
    if (it == end) {
      return -1;
    }
    ++it;
  }
  return 0;
}

template <class iter>
static auto
reql_next_char(iter &it, const iter &end, const typename iter::value_type &expect) {
  if (reql_space(it, end) != 0) {
    return 0;
  }
  if (*it == expect) {
    ++it;
    return 1;
  }
  return 0;
}

template <class s>
static int
reql_decode_(s &json, typename s::iterator it, typename s::iterator end, ReQL_Parse_t *p) {
  if (reql_space(it, end) != 0) {
    return -1;
  }
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
                return -1;
              }
              if (!(*(++it) == '0' && *(++it) == '0')) {
                return -1;
              }
              ++it;
              if (!(ishexnumber(*(it + 1)) && ishexnumber(*it))) {
                return -1;
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
          return p->add_string(p, reinterpret_cast<const char *>(&*start), static_cast<size_t>(track - start));
        }
        ++track;
        ++it;
      }
      break;
    }
    case '[': {
      if (p->start_array(p) != 0) {
        return -1;
      }
      ++it;
      while (it != end) {
        if (reql_next_char(it, end, ']') != 0) {
          return p->end_array(p);
        }
        if (p->start_element(p) != 0) {
          return -1;
        }
        if (reql_decode_(json, it, end, p) != 0) {
          return -1;
        }
        if (p->end_element(p) != 0) {
          return -1;
        }
        if (reql_next_char(it, end, ',') == 0) {
          if (*it != ']') {
            return -1;
          }
        }
      }
      break;
    }
    case '{': {
      p->start_object(p);
      ++it;
      ReQL_Obj_t *elem = nullptr;
      ReQL_Obj_t *top = nullptr;
      ReQL_Size i = 0;
      while (it != end) {
        if (reql_next_char(it, end, '}') != 0) {
          return p->end_object(p);
        }
        if (p->start_key_value(p)) {
          return -1;
        }
        if (reql_decode_(json, it, end, p) != 0) {
          return -1;
        }
        if (reql_next_char(it, end, ':') == 0) {
          return -1;
        }
        if (reql_decode_(json, it, end, p) != 0) {
          return -1;
        }
        if (reql_next_char(it, end, ',') == 0) {
          if (*it != '}') {
            return -1;
          }
        }
      }
      break;
    }
    case 'f': {
      if (it + 5 >= end) {
        return -1;
      }
      if (memcmp(reinterpret_cast<const void *>(&*it), json_false, 5) == 0) {
        return p->add_bool(p, 0);
      }
      break;
    }
    case 'n': {
      if (it + 4 >= end) {
        return -1;
      }
      if (memcmp(reinterpret_cast<const void *>(&*it), json_null, 4) == 0) {
        return p->add_null(p);
      }
      break;
    }
    case 't': {
      if (it + 4 >= end) {
        return -1;
      }
      if (memcmp(reinterpret_cast<const void *>(&*it), json_true, 4) == 0) {
        return p->add_bool(p, 1);
      }
      break;
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
        return -1;
      }
      return p->add_number(p, num);
    }
  }
  return -1;
}

template <class s>
void
reql_decode(s json, ReQL_Parse_t *p) {
  p->start_parse(p);
  if (reql_decode_(json, json.begin(), json.end(), p) != 0) {
    p->error(p);
  } else {
    p->end_parse(p);
  }
}

#endif  // REQL_REQL_DECODE_H_
