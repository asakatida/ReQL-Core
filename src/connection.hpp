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

#ifndef REQL_CPP_CONNECTION_HPP_
#define REQL_CPP_CONNECTION_HPP_

#include "./reql/result.hpp"

#include "./reql/core/connection.hpp"

#include <cstdint>
#include <memory>
#include <string>

namespace ReQL {

template <class result_t>
struct Connection {
  Connection() { p_conn->connect(); }

  Connection(const std::string &host) { p_conn->connect(host); }

  Connection(const std::string &host, const std::uint16_t &port) {
    p_conn->connect(host, std::to_string(port));
  }

  Connection(const std::string &host, const std::uint16_t &port, const std::string &key) {
    p_conn->connect(host, std::to_string(port), key);
  }

  Connection(const Connection &other) : p_conn(other.p_conn) {}

  Connection(Connection &&other) : p_conn(std::move(other.p_conn)) {}

  Connection &operator=(const Connection &other) {
    if (this != &other) {
      p_conn = other.p_conn;
    }
    return *this;
  }

  Connection &operator=(Connection &&other) {
    if (this != &other) {
      p_conn = std::move(other.p_conn);
    }
    return *this;
  }

  bool isOpen() const {
    return p_conn->isOpen();
  }

  void close() {
    p_conn->close();
  }

  void reconnect() {
    p_conn->close();
    p_conn->connect();
  }

  std::shared_ptr<_ReQL::Conn_t<result_t> > p_conn;
};

}  // namespace ReQL

#endif  // REQL_CPP_CONNECTION_HPP_
