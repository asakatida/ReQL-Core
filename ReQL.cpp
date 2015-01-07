/*
Copyright 2014 Adam Grandquist

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

#include "ReQL.hpp"

namespace ReQL {

Connection::Connection() {
  conn = new _ReQL_Conn_t();
  _reql_connection_init(conn);

  char buf[500];

  if (_reql_connect(conn, buf, 500)) {
  }
}

Connection::Connection(std::string host) {
  conn = new _ReQL_Conn_t();
  _reql_connection_init(conn);

  _reql_conn_set_addr(conn, (char *)host.c_str());

  char buf[500];

  if (_reql_connect(conn, buf, 500)) {
  }
}

Connection::Connection(std::string host, std::uint16_t port) {
  conn = new _ReQL_Conn_t();
  _reql_connection_init(conn);

  std::string _port = std::to_string(port);

  _reql_conn_set_addr(conn, (char *)host.c_str());
  _reql_conn_set_port(conn, (char *)_port.c_str());

  char buf[500];

  if (_reql_connect(conn, buf, 500)) {
  }
}

Connection::Connection(std::string host, std::uint16_t port, std::string key) {
  conn = new _ReQL_Conn_t();
  _reql_connection_init(conn);

  if (key.size() > UINT32_MAX) {
  }

  std::uint32_t key_len = (std::uint32_t)key.size();

  std::string _port = std::to_string(port);

  _reql_conn_set_addr(conn, (char *)host.c_str());
  _reql_conn_set_port(conn, (char *)_port.c_str());
  _reql_conn_set_auth(conn, key_len, (char *)key.c_str());

  char buf[500];

  if (_reql_connect(conn, buf, 500)) {
  }
}

Connection::~Connection() {
  delete conn;
}

int Connection::close() {
  _reql_close_conn(conn);
  return 0;
}

Connection connect() {
  return Connection();
}

Connection connect(std::string host) {
  return Connection(host);
}

Connection connect(std::string host, std::uint16_t port) {
  return Connection(host, port);
}

Connection connect(std::string host, std::uint16_t port, std::string key) {
  return Connection(host, port, key);
}

}
