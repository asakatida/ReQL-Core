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

#include "./reql/encode.hpp"

#include "./reql/char.hpp"

#include "./reql/query.h"
#include "./reql/types.h"

static auto
reql_escape_string(std::string &json, const ReQL_Byte *str, const ReQL_Size size) {
  json.append(&char_quotation, 1);
  ReQL_Size i, ext_size;
  ReQL_Byte chr;
  for (i=0; i < size; ++i) {
    chr = str[i];
    if ((ext_size = reql_json_string_esc_size(chr)) != 0) {
      json.append(reql_json_string_esc(chr), ext_size);
    } else {
      json.append(reinterpret_cast<const char *>(&chr), 1);
    }
  }
  return json.append(&char_quotation, 1);
}

static const std::string
reql_encode_(const ReQL_Obj_t *obj) {
  std::string json;
  switch (reql_datum_type(obj)) {
    case REQL_R_ARRAY: {
      json.append(&char_left_square_bracket, 1);
      ReQL_Iter_t iter = reql_new_iter(obj);

      auto first = true;
      ReQL_Obj_t *elem = nullptr;

      while ((elem = reql_iter_next(&iter)) != nullptr) {
        if (!first) {
          json.append(&char_comma, 1);
        }
        json.append(reql_encode_(elem));
        first = false;
      }
      return json.append(&char_right_square_bracket, 1);
    }
    case REQL_R_BOOL: {
      if (reql_to_bool(obj) == 1) {
        return json.append(json_true, 4);
      }
      return json.append(json_false, 5);
    }
    case REQL_R_JSON: throw std::exception();
    case REQL_R_NULL: return json.append(json_null, 4);
    case REQL_R_NUM: {
      return std::to_string(reql_to_number(obj));
    }
    case REQL_R_OBJECT: {
      json.append(&char_left_curly_bracket, 1);
      ReQL_Iter_t iter = reql_new_iter(obj);

      auto first = true;
      ReQL_Obj_t *key = nullptr;

      while ((key = reql_iter_next(&iter)) != nullptr) {
        if (!first) {
          json.append(&char_comma, 1);
        }
        json.append(reql_encode_(key)).append(&char_colon, 1).append(reql_encode_(reql_object_get(obj, key)));
        first = false;
      }
      return json.append(&char_right_curly_bracket, 1);
    }
    case REQL_R_REQL: {
      json.append(&char_left_square_bracket, 1).append(std::to_string(reql_term_type(obj)));
      if (obj->obj.args.args != nullptr) {
        json.append(&char_comma, 1).append(reql_encode_(obj->obj.args.args));
      }
      if (obj->obj.args.kwargs != nullptr) {
        if (obj->obj.args.args == nullptr) {
          json.append(",[]", 3);
        }
        json.append(&char_comma, 1).append(reql_encode_(obj->obj.args.kwargs));
      }
      return json.append(&char_right_square_bracket, 1);
    }
    case REQL_R_STR: return reql_escape_string(json, reql_string_buf(obj), reql_size(obj));
  }
}

const std::string
reql_encode(const ReQL_Obj_t *val) {
  return reql_encode_(val);
}
