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

#include "ReQL.hpp"

namespace ReQL {

Cursor::Cursor() {
  cur = new ReQL_Cur_t();
  reql_cursor_init(cur);
}

Cursor::~Cursor() {
  delete cur;
}

bool Cursor::isOpen() {
  return false;
}

int Cursor::close() {
  return -1;
}

Connection::Connection() {
  conn = new ReQL_Conn_t();
  reql_connection_init(conn);

  std::uint8_t buf[500];

  if (reql_connect(conn, buf, 500)) {
  }
}

Connection::Connection(std::string host) {
  conn = new ReQL_Conn_t();
  reql_connection_init(conn);

  reql_conn_set_addr(conn, (char *)host.c_str());

  std::uint8_t buf[500];

  if (reql_connect(conn, buf, 500)) {
  }
}

Connection::Connection(std::string host, std::uint16_t port) {
  conn = new ReQL_Conn_t();
  reql_connection_init(conn);

  reql_conn_set_addr(conn, (char *)host.c_str());
  reql_conn_set_port(conn, (char *)std::to_string(port).c_str());

  std::uint8_t buf[500];

  if (reql_connect(conn, buf, 500)) {
  }
}

Connection::Connection(std::string host, std::uint16_t port, std::string key) {
  conn = new ReQL_Conn_t();
  reql_connection_init(conn);

  if (key.size() > UINT32_MAX) {
  }

  std::uint32_t key_len = (std::uint32_t)key.size();

  reql_conn_set_addr(conn, (char *)host.c_str());
  reql_conn_set_port(conn, (char *)std::to_string(port).c_str());
  reql_conn_set_auth(conn, key_len, (char *)key.c_str());

  std::uint8_t buf[500];

  if (reql_connect(conn, buf, 500)) {
  }
}

Connection::~Connection() {
  reql_ensure_conn_close(conn);
  delete conn;
}

int Connection::close() {
  reql_close_conn(conn);
  return 0;
}

bool Connection::isOpen() {
  return reql_conn_open(conn);
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

Cursor Query::run(Connection conn) {
  return Cursor();
}

Query &Query::operator=(const Query &other) {
  query = other.query;
  return *this;
}

Query &Query::operator=(const Query &&other) {
  query = std::move(other.query);
  return *this;
}

}
