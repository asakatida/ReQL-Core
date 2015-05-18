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

namespace ReQL {

Connection::Connection() : _C::Types::connection(new _C::ReQL_Conn_t) {
  reql_connection_init(get());

  _C::ReQL_Byte buf[500];

  if (reql_connect(get(), buf, 500) != 0) {
    throw ReQLDriverError();
  }
}

Connection::Connection(const Types::string &host) : _C::Types::connection(new _C::ReQL_Conn_t) {
  reql_connection_init(get());

  reql_conn_set_addr(get(), const_cast<char *>(host.c_str()));

  _C::ReQL_Byte buf[500];

  if (reql_connect(get(), buf, 500) != 0) {
    throw ReQLDriverError();
  }
}

Connection::Connection(const Types::string &host, const std::uint16_t &port) : _C::Types::connection(new _C::ReQL_Conn_t) {
  reql_connection_init(get());

  reql_conn_set_addr(get(), const_cast<char *>(host.c_str()));
  reql_conn_set_port(get(), const_cast<char *>(std::to_string(port).c_str()));

  _C::ReQL_Byte buf[500];

  if (reql_connect(get(), buf, 500) != 0) {
    throw ReQLDriverError();
  }
}

Connection::Connection(const Types::string &host, const std::uint16_t &port, const Types::string &key) : _C::Types::connection(new _C::ReQL_Conn_t) {
  reql_connection_init(get());

  std::size_t auth_size = key.size();

  if (auth_size > std::numeric_limits<_C::ReQL_Size>::max()) {
    return;
  }

  reql_conn_set_addr(get(), const_cast<char *>(host.c_str()));
  reql_conn_set_port(get(), const_cast<char *>(std::to_string(port).c_str()));
  reql_conn_set_auth(get(), static_cast<_C::ReQL_Size>(auth_size), const_cast<char *>(key.c_str()));

  _C::ReQL_Byte buf[500];

  if (reql_connect(get(), buf, 500) != 0) {
    throw ReQLDriverError();
  }
}

Connection::Connection(Connection &&other) : _C::Types::connection(std::move(other)) {}

Connection::~Connection() {
  reql_ensure_conn_close(get());
}

Connection &Connection::operator=(Connection &&other) {
  if (this != &other) {
    _C::Types::connection::operator=(std::move(other));
  }
  return *this;
}

void
Connection::close() {
  reql_close_conn(get());
}

bool
Connection::isOpen() const {
  return reql_conn_open(get());
}

}  // namespace ReQL
