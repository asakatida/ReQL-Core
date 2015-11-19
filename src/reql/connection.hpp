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

#ifndef REQL_REQL_CONNECTION_HPP_
#define REQL_REQL_CONNECTION_HPP_

#include "./reql/btree.hpp"
#include "./reql/types.hpp"

#include <memory>

namespace _ReQL {

static const char *DEFAULT_ADDR = "localhost";
static const char *DEFAULT_PORT = "30030";

template <class result_t, class str_t>
class Conn_t {
public:
  Conn_t() {}

  Conn_t(str_t &addr, str_t &port, str_t &auth) : p_cursors(addr, port, auth) {}

  void _connect() {
    return _connect(str_t(DEFAULT_ADDR));
  }

  void _connect(const str_t &addr) {
    return _connect(addr, str_t(DEFAULT_PORT), str_t(""));
  }

  void _connect(const str_t &addr, const str_t &port, const str_t &auth) {
    p_cursors = std::move(BTree_t<result_t, str_t>(addr, port, auth));
  }

  Conn_t(Conn_t &&other) : p_cursors(std::move(other.p_cursors)) {}

  Conn_t &operator =(Conn_t &&other) {
    if (this != &other) {
      p_cursors = std::move(other.p_cursors);
    }
    return *this;
  }

  bool isOpen() const {
    return p_cursors.isOpen();
  }

  template <class query_t>
  Cur_t<result_t, str_t> *run(const query_t &query) {
    return p_cursors.run(query);
  }

  template <class kwargs_t, class query_t>
  Cur_t<result_t, str_t> *run(const query_t &query, const kwargs_t &kwargs) {
    return p_cursors.run(query, kwargs);
  }

  template <class kwargs_t, class query_t>
  void noReply(const query_t &query, const kwargs_t &kwargs) {
    p_cursors.noReply(query, kwargs);
  }

  void noReplyWait() {
    p_cursors.noReplyWait();
  }

  void stop(ReQL_Token token) {
    p_cursors.stop(token);
  }

  BTree_t<result_t, str_t> p_cursors;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CONNECTION_HPP_
