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

Cursor::Cursor() : cur(new ReQL_Cur_t) {
  reql_cursor_init(data());
}

Cursor::~Cursor() {
}

bool Cursor::isOpen() const {
  return false;
}

ReQL_Cur_t *
Cursor::data() const {
  return cur.get();
}

void
Cursor::close() {
}

Connection::Connection() : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const std::string &host) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  reql_conn_set_addr(data(), (char *)host.c_str());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const std::string &host, const std::uint16_t &port) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  reql_conn_set_addr(data(), (char *)host.c_str());
  reql_conn_set_port(data(), (char *)std::to_string(port).c_str());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const std::string &host, const std::uint16_t &port, const std::string &key) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  if (key.size() > UINT32_MAX) {
  }

  std::uint32_t key_len = (std::uint32_t)key.size();

  reql_conn_set_addr(data(), (char *)host.c_str());
  reql_conn_set_port(data(), (char *)std::to_string(port).c_str());
  reql_conn_set_auth(data(), key_len, (char *)key.c_str());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const Connection &other) {
}

Connection::Connection(Connection &&other) {
  conn = std::move(other.conn);
}

Connection::~Connection() {
  reql_ensure_conn_close(data());
}

Connection &Connection::operator=(const Connection &other) {
  return *this;
}

Connection &Connection::operator=(Connection &&other) {
  conn = std::move(other.conn);
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
  return conn.get();
}

Cursor Query::run(const Connection &conn) const {
  if (!conn.isOpen()) {
  }

  Cursor cur;

  ReQL kwargs;

  reql_run(cur.data(), p_query.data(), conn.data(), kwargs.data());

  return cur;
}

Query &Query::operator=(const Query &other) {
  Expr::operator=(other);
  return *this;
}

Query &Query::operator=(Query &&other) {
  Expr::operator=(std::move(other));
  return *this;
}

bool Query::operator<(const Query &other) const {
  return Expr::operator<(other);
}

}
