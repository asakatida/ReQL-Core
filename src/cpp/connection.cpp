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

#include "./cpp/connection.hpp"

#include "./cpp/error.hpp"

#include <algorithm>
#include <string>

namespace ReQL {

Connection::Connection() {
  p_conn._connect();
}

Connection::Connection(const std::string &host) {
  p_conn._connect(host);
}

Connection::Connection(const std::string &host, const std::uint16_t &port) {
  p_conn._connect(host, std::to_string(port), "");
}

Connection::Connection(const std::string &host, const std::uint16_t &port, const std::string &key) {
  p_conn._connect(host, std::to_string(port), key);
}

Connection::Connection(Connection &&other) : p_conn(std::move(other.p_conn)) {}

Connection &Connection::operator=(Connection &&other) {
  if (this != &other) {
    p_conn = std::move(other.p_conn);
  }
  return *this;
}

void
Connection::close() {
  p_conn = _Connection();
}

bool
Connection::isOpen() const {
  return p_conn.isOpen();
}

}  // namespace ReQL
