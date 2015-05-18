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

#include "./cpp/types.hpp"

namespace ReQL {

class Connection : public _C::CTypes::connection {
public:
  Connection();
  explicit Connection(const Types::string &host);
  Connection(const Types::string &host, const std::uint16_t &port);
  Connection(const Types::string &host, const std::uint16_t &port, const Types::string &key);

  Connection(Connection &&other);

  Connection &operator=(Connection &&other);

  ~Connection();

  bool isOpen() const;

  void close();
};

}  // namespace ReQL

#endif  // REQL_CPP_CONNECTION_HPP_
