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

#include "./cpp/result.hpp"

#include "./cpp/error.hpp"
#include "./cpp/wrapper.hpp"

#include <map>
#include <string>
#include <vector>

namespace ReQL {

namespace _C {

extern "C" {

#include "./c/dev/json.h"

}

}  // namespace _C

Result::Result() : p_type(_C::REQL_R_NULL) {}

Result::Result(const bool val) : p_type(_C::REQL_R_BOOL), p_boolean(val) {}

Result::Result(const double val) : p_type(_C::REQL_R_NUM), p_num(val) {}

Result::Result(const Types::string val) : p_type(_C::REQL_R_STR), p_string(val) {}

Result::Result(const std::map<Types::string, Result> val) : p_type(_C::REQL_R_OBJECT), p_object(val) {}

Result::Result(const std::vector<Result> val) : p_type(_C::REQL_R_ARRAY), p_array(val) {}

Result::Result(const Result &other) : p_type(other.p_type) {
  copy(other);
}

Result::Result(Result &&other) : p_type(std::move(other.p_type)) {
  move(std::move(other));
}

Result &
Result::operator=(const Result &other) {
  if (this != &other) {
    p_type = other.p_type;
    copy(other);
  }
  return *this;
}

Result &
Result::operator=(Result &&other) {
  if (this != &other) {
    p_type = std::move(other.p_type);
    move(std::move(other));
  }
  return *this;
}

void
Result::insert(Result elem) {
  if (p_type != _C::REQL_R_ARRAY) {
    throw ReQLDriverError();
  }
  p_array.push_back(elem);
}

void
Result::insert(Types::string key, Result value) {
  if (p_type != _C::REQL_R_OBJECT) {
    throw ReQLDriverError();
  }
  p_object.insert({key, value});
}

_C::ReQL_Datum_t
Result::type() const {
  return p_type;
}

bool
Result::boolean() const {
  if (p_type != _C::REQL_R_BOOL) {
    throw ReQLDriverError();
  }
  return p_boolean;
}

double
Result::number() const {
  if (p_type != _C::REQL_R_NUM) {
    throw ReQLDriverError();
  }
  return p_num;
}

std::map<Types::string, Result>
Result::object() const {
  if (p_type != _C::REQL_R_OBJECT) {
    throw ReQLDriverError();
  }
  return p_object;
}

Types::string
Result::string() const {
  if (p_type != _C::REQL_R_STR) {
    throw ReQLDriverError();
  }
  return p_string;
}

std::vector<Result>
Result::array() const {
  if (p_type != _C::REQL_R_ARRAY) {
    throw ReQLDriverError();
  }
  return p_array;
}

void
Result::copy(const Result &other) {
  switch (p_type) {
    case _C::REQL_R_ARRAY: {
      p_array = other.array();
      break;
    }
    case _C::REQL_R_BOOL: {
      p_boolean = other.boolean();
      break;
    }
    case _C::REQL_R_NUM: {
      p_num = other.number();
      break;
    }
    case _C::REQL_R_OBJECT: {
      p_object = other.object();
      break;
    }
    case _C::REQL_R_STR: {
      p_string = other.string();
      break;
    }
    case _C::REQL_R_NULL: {
      break;
    }
    case _C::REQL_R_REQL:
    case _C::REQL_R_JSON: throw ReQLDriverError();
  }
}

void
Result::move(Result &&other) {
  switch (p_type) {
    case _C::REQL_R_ARRAY: {
      p_array = std::move(other.p_array);
      break;
    }
    case _C::REQL_R_BOOL: {
      p_boolean = std::move(other.p_boolean);
      break;
    }
    case _C::REQL_R_NUM: {
      p_num = std::move(other.p_num);
      break;
    }
    case _C::REQL_R_OBJECT: {
      p_object = std::move(other.p_object);
      break;
    }
    case _C::REQL_R_STR: {
      p_string = std::move(other.p_string);
      break;
    }
    case _C::REQL_R_NULL: {
      break;
    }
    case _C::REQL_R_JSON:
    case _C::REQL_R_REQL: throw ReQLDriverError();
  }
}

Parser::~Parser() {}

void
Parser::parse(Wrapper val) {
  parse_c(val.get());
}

void
Parser::parse_c(_C::ReQL_Obj_t *val) {
  switch (reql_datum_type(val)) {
    case _C::REQL_R_ARRAY: {
      startArray();

      _C::ReQL_Iter_t it = reql_new_iter(val);
      _C::ReQL_Obj_t *elem = NULL;

      while ((elem = reql_iter_next(&it)) != NULL) {
        parse_c(elem);
      }

      endArray();
      break;
    }
    case _C::REQL_R_BOOL: {
      addElement(static_cast<bool>(reql_to_bool(val)));
      break;
    }
    case _C::REQL_R_JSON:
    case _C::REQL_R_REQL: break;
    case _C::REQL_R_NULL: {
      addElement();
      break;
    }
    case _C::REQL_R_NUM: {
      addElement(reql_to_number(val));
      break;
    }
    case _C::REQL_R_OBJECT: {
      startObject();

      _C::ReQL_Iter_t it = reql_new_iter(val);
      _C::ReQL_Obj_t *key = NULL;
      _C::ReQL_Obj_t *value = NULL;

      while ((key = reql_iter_next(&it)) != NULL) {
        value = reql_object_get(val, key);
        Types::string key_string(reinterpret_cast<char*>(reql_string_buf(key)), reql_size(key));

        switch (reql_datum_type(value)) {
          case _C::REQL_R_BOOL: {
            addKeyValue(key_string, static_cast<bool>(reql_to_bool(val)));
            break;
          }
          case _C::REQL_R_ARRAY:
          case _C::REQL_R_OBJECT: {
            addKey(key_string);
            parse_c(value);
            break;
          }
          case _C::REQL_R_NULL: {
            addKeyValue(key_string);
            break;
          }
          case _C::REQL_R_NUM: {
            addKeyValue(key_string, reql_to_number(value));
            break;
          }
          case _C::REQL_R_JSON:
          case _C::REQL_R_REQL: break;
          case _C::REQL_R_STR: {
            addKeyValue(key_string, Types::string(reinterpret_cast<char*>(reql_string_buf(value)), reql_size(value)));
            break;
          }
        }
      }

      endObject();
      break;
    }
    case _C::REQL_R_STR: {
      addElement(Types::string(reinterpret_cast<char*>(reql_string_buf(val)), reql_size(val)));
      break;
    }
  }
}

}  // namespace ReQL
