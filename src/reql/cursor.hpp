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
#include "./reql/pipe.hpp"
#include "./reql/response.hpp"
#include "./reql/types.hpp"

#include <atomic>
#include <memory>

namespace _ReQL {

template <class parser_t, class str_t>
class Cur_t {
public:
  Cur_t() {}

  enum Response_e {
    REQL_CLIENT_ERROR = 16,
    REQL_COMPILE_ERROR = 17,
    REQL_RUNTIME_ERROR = 18,
    REQL_SUCCESS_ATOM = 1,
    REQL_SUCCESS_PARTIAL = 3,
    REQL_SUCCESS_SEQUENCE = 2,
    REQL_WAIT_COMPLETE = 4
  };

  Cur_t(Pipe_t<Response_t<str_t>> &pipe) :
    p_pipe([this](Response_t<str_t> &&response) {
      parser_t parser;
      decode(response.p_json, parser);
      switch (parser.r_type()) {
        case REQL_SUCCESS_ATOM:
        case REQL_SUCCESS_SEQUENCE:
        case REQL_WAIT_COMPLETE: {
          response.done();
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
          response.done();
        }
      }
      return parser.get();
    }, pipe) {}

  Cur_t(Cur_t &&other) : p_pipe(std::move(other.p_pipe)) {}

  Cur_t &operator =(Cur_t &&other) {
    if (this != &other) {
      p_pipe = std::move(other.p_pipe);
    }
    return *this;
  }

  bool isOpen() {
    return p_pipe.isOpen();
  }

  Cur_t &operator >>(typename parser_t::result_t &value) {
    p_pipe >> value;
    return *this;
  }

  void close() {
    p_pipe.close();
  }

  Pipe_t<typename parser_t::result_t> p_pipe;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CURSOR_HPP_
