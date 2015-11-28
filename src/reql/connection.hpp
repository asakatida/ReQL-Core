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
static const char *DEFAULT_PORT = "28015";

template <class auth_e, class handshake_e, class result_t, class socket_e>
class Conn_t {
public:
  Conn_t() {}

  void _connect() {
    return _connect(ImmutableString(DEFAULT_ADDR));
  }

  template <class addr_t>
  void _connect(const addr_t &addr) {
    return _connect(addr, ImmutableString(DEFAULT_PORT), ImmutableString(""));
  }

  template <class addr_t, class auth_t, class port_t>
  void _connect(const addr_t &addr, const port_t &port, const auth_t &auth) {
    p_cursors = std::make_shared<BTree_t<auth_e, handshake_e, result_t, socket_e>>(addr, port, auth);
  }

  Conn_t(const Conn_t &other) : p_cursors(other.p_cursors) {}

  Conn_t(Conn_t &&other) : p_cursors(std::move(other.p_cursors)) {}

  Conn_t &operator =(const Conn_t &other) {
    if (this != &other) {
      p_cursors = other.p_cursors;
    }
    return *this;
  }

  Conn_t &operator =(Conn_t &&other) {
    if (this != &other) {
      p_cursors = std::move(other.p_cursors);
    }
    return *this;
  }

  bool isOpen() const {
    return p_cursors->isOpen();
  }

  void close() {
    p_cursors = std::make_shared<BTree_t<auth_e, handshake_e, result_t, socket_e>>();
  }

  template <class query_t, class func_t>
  void run(const query_t &query, func_t func) {
    p_cursors->run(query, func);
  }

  template <class kwargs_t, class query_t, class func_t>
  void run(const query_t &query, const kwargs_t &kwargs, func_t func) {
    p_cursors->run(query, kwargs, func);
  }

  template <class kwargs_t, class query_t>
  void noReply(const query_t &query, const kwargs_t &kwargs) {
    p_cursors->noReply(query, kwargs);
  }

  void noReplyWait() {
    p_cursors->noReplyWait();
  }

  void stop(ReQL_Token token) {
    p_cursors->stop(token);
  }

private:
  std::shared_ptr<BTree_t<auth_e, handshake_e, result_t, socket_e> > p_cursors;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CONNECTION_HPP_
