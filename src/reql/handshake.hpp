/*
Copyright 2015 Adam Grandquist

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

#ifndef REQL_REQL_HANDSHAKE_HPP_
#define REQL_REQL_HANDSHAKE_HPP_

#include "./reql/types.hpp"

#include <sstream>
#include <string>

namespace _ReQL {

static const ReQL_Size VERSION = 0x400c2d20;
static const ReQL_Size PROTOCOL = 0x7e6970c7;

template <class auth_e, class handshake_e>
class Handshake_t {
public:
  template <class socket_t>
  Handshake_t(socket_t &sock, const std::string &auth) {
    char magic[3][4];

    make_size(magic[0], VERSION);
    make_size(magic[1], static_cast<ReQL_Size>(auth.size()));
    make_size(magic[2], PROTOCOL);

    std::stringstream stream;
    stream << std::string(magic[0], 4)
           << std::string(magic[1], 4)
           << auth
           << std::string(magic[2], 4);

    sock.write(stream.str());

    auto response = sock.read();

    if (response.size() != 8) {
      throw auth_e("");  // TODO
    }

    if (!(response == "SUCCESS")) {
      throw auth_e("");  // TODO
    }
  }

private:
  static void make_size(char *buf, const ReQL_Size magic) {
    buf[0] = static_cast<char>((magic >> 0) & 0xFF);
    buf[1] = static_cast<char>((magic >> 8) & 0xFF);
    buf[2] = static_cast<char>((magic >> 16) & 0xFF);
    buf[3] = static_cast<char>((magic >> 24) & 0xFF);
  }
};

}  // namespace _ReQL

#endif  // REQL_REQL_HANDSHAKE_HPP_
