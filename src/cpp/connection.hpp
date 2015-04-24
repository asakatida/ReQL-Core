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

#ifndef REQL_CONNECTION_HPP_
#define REQL_CONNECTION_HPP_

#include <map>
#include <string>
#include <vector>

namespace ReQL {
extern "C" {

#include "./ReQL.h"

}

class Connection {
public:
  Connection();
  explicit Connection(const std::string &host);
  Connection(const std::string &host, const std::uint16_t &port);
  Connection(const std::string &host, const std::uint16_t &port, const std::string &key);

  explicit Connection(const Connection &other);
  explicit Connection(Connection &&other);

  Connection &operator=(const Connection &other);
  Connection &operator=(Connection &&other);

  ~Connection();

  bool isOpen() const;

  ReQL_Conn_t *data() const;

  void close();

private:
  std::unique_ptr<ReQL_Conn_t> p_conn;
};

}  // namespace ReQL

#endif  // REQL_CONNECTION_HPP_
