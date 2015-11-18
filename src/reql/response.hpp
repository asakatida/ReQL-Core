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

#ifndef REQL_REQL_RESPONSE_HPP_
#define REQL_REQL_RESPONSE_HPP_

#include "./reql/types.hpp"

namespace _ReQL {

template <class str_t>
class Response_t {
public:
  Response_t() {}

  Response_t(str_t &&json, ReQL_Token token) : p_json(std::move(json)), p_token(token) {}

  Response_t(Response_t &&other) : p_json(std::move(other.p_json)), p_token(other.p_token) {}

  Response_t &operator =(Response_t &&other) {
    if (this != &other) {
      p_json = std::move(other.p_json);
      p_token = other.p_token;
    }
    return *this;
  }

  void next() {}

  void done() {}

  str_t p_json;
  ReQL_Token p_token;
};

}  // namespace _ReQL

#endif  // REQL_REQL_RESPONSE_HPP_
