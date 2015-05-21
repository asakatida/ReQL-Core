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

#include "./cpp/parser.hpp"

#include "./cpp/error.hpp"
#include "./cpp/query.hpp"

namespace ReQL {

Parser::~Parser() {}

void
Parser::parse(Query &val) {
  parse_c(val._internal().get());
}

void
Parser::parse_c(_C::ReQL_Obj_t *val) {
  switch (reql_datum_type(val)) {
    case _C::REQL_R_ARRAY: {
      startArray();

      _C::ReQL_Iter_t it = reql_new_iter(val);
      _C::ReQL_Obj_t *elem = nullptr;

      while ((elem = reql_iter_next(&it)) != nullptr) {
        startElement();
        parse_c(elem);
        endElement();
      }

      endArray();
      break;
    }
    case _C::REQL_R_BOOL: {
      addValue(static_cast<bool>(reql_to_bool(val)));
      break;
    }
    case _C::REQL_R_JSON:
    case _C::REQL_R_REQL: throw ReQLDriverError();
    case _C::REQL_R_NULL: {
      addValue();
      break;
    }
    case _C::REQL_R_NUM: {
      addValue(reql_to_number(val));
      break;
    }
    case _C::REQL_R_OBJECT: {
      startObject();

      _C::ReQL_Iter_t it = reql_new_iter(val);
      _C::ReQL_Obj_t *key = nullptr;
      _C::ReQL_Obj_t *value = nullptr;

      while ((key = reql_iter_next(&it)) != nullptr) {
        startKeyValue();
        value = reql_object_get(val, key);
        parse_c(value);
        endKeyValue(to_string(key));
      }

      endObject();
      break;
    }
    case _C::REQL_R_STR: {
      addValue(to_string(val));
      break;
    }
  }
}

Types::string
Parser::to_string(_C::ReQL_Obj_t *value) {
  return Types::string(reinterpret_cast<char*>(reql_string_buf(value)), reql_size(value));
}

}  // namespace ReQL
