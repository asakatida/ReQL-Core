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

#include "./cpp/error.hpp"
#include "./cpp/parser.hpp"

#include "./reql/connection.hpp"

#include <cstdint>
#include <memory>
#include <string>

namespace ReQL {

class Connection {
public:
  Connection();
  Connection(const std::string &host);
  Connection(const std::string &host, const std::uint16_t &port);
  Connection(const std::string &host, const std::uint16_t &port, const std::string &key);

  Connection(const Connection &other);
  Connection(Connection &&other);

  Connection &operator=(const Connection &other);
  Connection &operator=(Connection &&other);

  bool isOpen() const;

  void close();

  void reconnect();

private:

  friend class Query;
  std::shared_ptr<_ReQL::Conn_t<ReQLError, ReQLError, Result, ReQLError>> p_conn;
};

}  // namespace ReQL

#endif  // REQL_CPP_CONNECTION_HPP_
