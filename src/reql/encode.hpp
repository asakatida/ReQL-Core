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

#ifndef REQL_REQL_ENCODE_H_
#define REQL_REQL_ENCODE_H_

#include "./reql/char.hpp"

#include <sstream>
#include <string>

#include "./reql/query.h"
#include "./reql/types.h"

template <class s>
static s
to_string(ReQL_Term_t val) {
  std::basic_stringstream<typename s::value_type> ss;
  ss << static_cast<unsigned int>(val);
  return ss.str();
}

template <class s>
static s
to_string(double val) {
  std::basic_stringstream<typename s::value_type> ss;
  ss << val;
  return ss.str();
}

template <class s>
static auto
reql_escape_string(s &json, const typename s::value_type *str, const ReQL_Size size) {
  json.append(&char_quotation, 1);
  ReQL_Size i, ext_size;
  ReQL_Byte chr;
  for (i=0; i < size; ++i) {
    chr = str[i];
    if ((ext_size = reql_json_string_esc_size(chr)) != 0) {
      json.append(reql_json_string_esc(chr), ext_size);
    } else {
      json.append(&chr, 1);
    }
  }
  return json.append(&char_quotation, 1);
}

template <class s>
static const s
reql_encode(const ReQL_Any_t &obj);

template <class s>
static const s
reql_encode(const ReQL_Array_t &obj) {
  s json;
  json.append(&char_left_square_bracket, 1);
  ReQL_Array_Iter_t iter;
  reql_array_iter_init(&iter, &obj);

  auto first = true;
  ReQL_Any_t *elem = nullptr;

  while ((elem = reql_array_iter_next(&iter)) != nullptr) {
    if (!first) {
      json.append(&char_comma, 1);
    }
    json.append(reql_encode<s>(*elem));
    first = false;
  }
  return json.append(&char_right_square_bracket, 1);
}

template <class s>
static const s
reql_encode(const ReQL_Obj_t &obj) {
  s json;
  json.append(&char_left_curly_bracket, 1);
  ReQL_Object_Iter_t iter;
  reql_object_iter_init(&iter, &obj);

  auto first = true;
  ReQL_Pair_t *pair = nullptr;

  while ((pair = reql_object_iter_next(&iter)) != nullptr) {
    if (!first) {
      json.append(&char_comma, 1);
    }
    json.append(pair->key, pair->key_size)
    .append(&char_colon, 1).append(reql_encode<s>(pair->val));
    first = false;
  }
  return json.append(&char_right_curly_bracket, 1);
}

template <class s>
static const s
reql_encode(const ReQL_Any_t &obj) {
  s json;
  switch (reql_datum_type(&obj)) {
    case REQL_R_ARRAY: {
      return json.append(reql_encode<s>(obj.any.array));
    }
    case REQL_R_BOOL: {
      if (obj.any.boolean) {
        return json.append(json_true, 4);
      }
      return json.append(json_false, 5);
    }
    case REQL_R_JSON: throw std::exception();
    case REQL_R_NULL: return json.append(json_null, 4);
    case REQL_R_NUM: {
      return to_string<s>(obj.any.num);
    }
    case REQL_R_OBJECT: {
      return json.append(reql_encode<s>(obj.any.object));
    }
    case REQL_R_REQL: {
      const ReQL_ReQL_t *reql = &obj.any.reql;
      json.append(&char_left_square_bracket, 1).append(to_string<s>(reql_term_type(reql)));
      if (reql->args != nullptr) {
        json.append(&char_comma, 1).append(reql_encode<s>(reql->args(reql->data)));
      }
      if (reql->kwargs != nullptr) {
        if (reql->args == nullptr) {
          json.append(reinterpret_cast<const typename s::value_type *>(",[]"), 3);
        }
        json.append(&char_comma, 1).append(reql_encode<s>(reql->kwargs(reql->data)));
      }
      return json.append(&char_right_square_bracket, 1);
    }
    case REQL_R_STR: return reql_escape_string(json, reql_string_buf(&obj.any.string), reql_size(&obj.any.string));
  }
}

#endif  // REQL_REQL_ENCODE_H_
