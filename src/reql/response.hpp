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

template <class proto_t>
class Response_t {
public:
  Response_t(ImmutableString &&json, ReQL_Token token, proto_t *proto) :
    p_json(std::move(json)), p_proto(proto), p_token(token) {}

  bool operator ==(ReQL_Token token) const {
    return p_token == token;
  }

  bool operator <(ReQL_Token token) const {
    return p_token < token;
  }

  const ImmutableString json() const {
    return p_json;
  }

  void next() const {
    p_proto->cont(p_token);
  }

private:
  const ImmutableString p_json;
  proto_t *p_proto;
  const ReQL_Token p_token;
};

}  // namespace _ReQL

#endif  // REQL_REQL_RESPONSE_HPP_
