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

#include "ReQL-CPP.hpp"

#include "ReQL.hpp"

#include <cstdlib>

using namespace ReQL;

Connection::Connection() {
  conn = (struct _ReQL_Conn_s *)new _ReQL_Conn_t();
  conn = (struct _ReQL_Conn_s *)_reql_new_connection((_ReQL_Conn_t *)conn);

  if (!conn) {
    return;
  }

  char *buf;

  if (_reql_connect((_ReQL_Conn_t *)conn, &buf)) {
  }

  free(buf);
}

Connection::Connection(std::string host) {
  conn = (struct _ReQL_Conn_s *)new _ReQL_Conn_t();
  conn = (struct _ReQL_Conn_s *)_reql_new_connection((_ReQL_Conn_t *)conn);

  if (!conn) {
    return;
  }

  char *buf;

  if (_reql_connect((_ReQL_Conn_t *)conn, &buf)) {
  }

  free(buf);
}

Connection::Connection(std::string host, std::string port) {
  conn = (struct _ReQL_Conn_s *)new _ReQL_Conn_t();
  conn = (struct _ReQL_Conn_s *)_reql_new_connection((_ReQL_Conn_t *)conn);

  if (!conn) {
    return;
  }

  char *buf;

  if (_reql_connect((_ReQL_Conn_t *)conn, &buf)) {
  }

  free(buf);
}

Connection::Connection(std::string host, std::string port, std::string key) {
  conn = (struct _ReQL_Conn_s *)new _ReQL_Conn_t();
  conn = (struct _ReQL_Conn_s *)_reql_new_connection((_ReQL_Conn_t *)conn);

  if (!conn) {
    return;
  }

  char *buf;

  if (_reql_connect((_ReQL_Conn_t *)conn, &buf)) {
  }

  free(buf);
}

Connection connect() {
  return Connection();
}

Connection connect(std::string host) {
  return Connection(host);
}

Connection connect(std::string host, std::string port) {
  return Connection(host, port);
}

Connection connect(std::string host, std::string port, std::string key) {
  return Connection(host, port, key);
}
