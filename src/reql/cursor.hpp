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
#include "./reql/types.hpp"

#include <atomic>
#include <memory>

namespace _ReQL {

template <class parser_t, class str_t>
class Conn_t;

template <class parser_t, class str_t>
class Cur_t {
public:
  Cur_t() : p_token(-1) { close(); }

  enum Response_e {
    REQL_CLIENT_ERROR = 16,
    REQL_COMPILE_ERROR = 17,
    REQL_RUNTIME_ERROR = 18,
    REQL_SUCCESS_ATOM = 1,
    REQL_SUCCESS_PARTIAL = 3,
    REQL_SUCCESS_SEQUENCE = 2,
    REQL_WAIT_COMPLETE = 4
  };

  Cur_t(Pipe<Response_t> &pipe, Conn_t<parser_t, str_t> *conn, ReQL_Token token) :
  p_ostream([this, token](const str_t &elem) {
    parser_t parser;
    decode(elem, parser);
    switch (parser.r_type()) {
      case REQL_SUCCESS_ATOM:
      case REQL_SUCCESS_SEQUENCE:
      case REQL_WAIT_COMPLETE: {
        p_conn.store(nullptr);
        break;
      }
      case REQL_SUCCESS_PARTIAL: {
        break;
      }
      case REQL_CLIENT_ERROR:
      case REQL_COMPILE_ERROR:
      case REQL_RUNTIME_ERROR:
      default: {
        p_conn.store(nullptr);
      }
    }
    return parser.get();
  }, p_istream), p_conn(conn), p_token(token) {}

  Cur_t(Conn_t<parser_t, str_t> *conn, ReQL_Token token) : p_token(token), p_conn(conn) {}

  Cur_t(Cur_t &&other) : p_token(std::move(other.p_token)), p_conn(std::move(other.p_conn)) {}

  ~Cur_t() { close(); }

  Cur_t &operator =(Cur_t &&other) {
    if (this != &other) {
      p_conn.store(other.p_conn.exchange(nullptr));
    }
    return *this;
  }

  bool isOpen() {
    if (p_conn.load()) {
      return p_conn.load()->isOpen();
    }
    return false;
  }

  void push(str_t &&json) {
    p_istream << std::move(json);
  }

  void close() {
    auto conn = p_conn.exchange(nullptr);
    if (conn) {
      if (conn->isOpen()) {
        conn->stop(p_token);
        p_istream.interupt();
      }
    }
  }

  Pipe<Response_t> p_ostream;
  Pipe<str_t> p_istream;
  const ReQL_Token p_token;
  std::atomic<Conn_t<parser_t, str_t> *> p_conn;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CURSOR_HPP_
