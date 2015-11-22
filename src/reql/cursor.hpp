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

#ifndef REQL_REQL_CURSOR_HPP_
#define REQL_REQL_CURSOR_HPP_

#include "./reql/decode.hpp"
#include "./reql/parser.hpp"
#include "./reql/protocol.hpp"
#include "./reql/response.hpp"
#include "./reql/types.hpp"

#include <functional>
#include <memory>

namespace _ReQL {

template <class result_t, class str_t>
class Cur_t {
public:
  enum Response_e {
    REQL_CLIENT_ERROR = 16,
    REQL_COMPILE_ERROR = 17,
    REQL_RUNTIME_ERROR = 18,
    REQL_SUCCESS_ATOM = 1,
    REQL_SUCCESS_PARTIAL = 3,
    REQL_SUCCESS_SEQUENCE = 2,
    REQL_WAIT_COMPLETE = 4
  };

  Cur_t(std::function<void(result_t &&result)> &func) : p_func(func) {}

  Cur_t &operator <<(Response_t<str_t, Protocol_t<str_t> > &&response) {
    Parser_t<result_t> parser;
    decode(response.json(), parser);
    switch (parser.r_type()) {
      case REQL_SUCCESS_ATOM:
      case REQL_SUCCESS_SEQUENCE:
      case REQL_WAIT_COMPLETE: {
        break;
      }
      case REQL_SUCCESS_PARTIAL: {
        response.next();
        break;
      }
      case REQL_CLIENT_ERROR:
      case REQL_COMPILE_ERROR:
      case REQL_RUNTIME_ERROR:
      default: {
      }
    }
    p_func(std::move(parser.get()));
    return *this;
  }

private:
  std::function<void(result_t &&result)> p_func;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CURSOR_HPP_
