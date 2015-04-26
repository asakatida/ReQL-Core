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

#include <map>
#include <string>
#include <vector>

namespace ReQL {

Connection::Connection() : p_conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500) != 0) {
    throw;
  }
}

Connection::Connection(const std::string &host) : p_conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  reql_conn_set_addr(data(), const_cast<char *>(host.c_str()));

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500) != 0) {
    throw;
  }
}

Connection::Connection(const std::string &host, const std::uint16_t &port) : p_conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  reql_conn_set_addr(data(), const_cast<char *>(host.c_str()));
  reql_conn_set_port(data(), const_cast<char *>(std::to_string(port).c_str()));

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500) != 0) {
    throw;
  }
}

Connection::Connection(const std::string &host, const std::uint16_t &port, const std::string &key) : p_conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  std::size_t auth_size = key.size();

  if (auth_size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  reql_conn_set_addr(data(), const_cast<char *>(host.c_str()));
  reql_conn_set_port(data(), const_cast<char *>(std::to_string(port).c_str()));
  reql_conn_set_auth(data(), static_cast<std::uint32_t>(auth_size), const_cast<char *>(key.c_str()));

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500) != 0) {
    throw;
  }
}

Connection::Connection(const Connection &other) : p_conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  ReQL_Conn_t *o_conn = other.data();

  reql_conn_set_addr(data(), o_conn->addr);
  reql_conn_set_port(data(), o_conn->port);
  reql_conn_set_auth(data(), o_conn->auth_size, o_conn->auth);

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500) != 0) {
    throw;
  }
}

Connection::Connection(Connection &&other) {
  p_conn = std::move(other.p_conn);
}

Connection::~Connection() {
  reql_ensure_conn_close(data());
}

Connection &Connection::operator=(const Connection &other) {
  if (this != &other) {
    reql_ensure_conn_close(data());
    reql_connection_init(data());

    ReQL_Conn_t *o_conn = other.data();

    reql_conn_set_addr(data(), o_conn->addr);
    reql_conn_set_port(data(), o_conn->port);
    reql_conn_set_auth(data(), o_conn->auth_size, o_conn->auth);

    std::uint8_t buf[500];

    if (reql_connect(data(), buf, 500)) {
      throw;
    }
  }
  return *this;
}

Connection &Connection::operator=(Connection &&other) {
  if (this != &other) {
    p_conn = std::move(other.p_conn);
  }
  return *this;
}

void
Connection::close() {
  reql_close_conn(data());
}

bool
Connection::isOpen() const {
  return reql_conn_open(data());
}

ReQL_Conn_t *
Connection::data() const {
  return p_conn.get();
}

}  // namespace ReQL
