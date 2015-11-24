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

#include "./reql/socket.hpp"
#include "./reql/stream.hpp"
#include "./reql/types.hpp"

namespace _ReQL {

static const ReQL_Size VERSION = 0x400c2d20;
static const ReQL_Size PROTOCOL = 0x7e6970c7;

template <class str_t>
class Handshake_t {
public:
  Handshake_t(Socket_t<str_t> &sock, const str_t &auth) {
    ReQL_Byte magic[3][4];

    make_size(magic[0], VERSION);
    make_size(magic[1], static_cast<ReQL_Size>(auth.size()));
    make_size(magic[2], PROTOCOL);

    Stream_t<str_t> stream;
    stream << str_t(magic[0], 4)
    << str_t(magic[1], 4)
    << auth
    << str_t(magic[2], 4);

    sock.write(stream.str());

    auto response = sock.read();

    if (response.size() != 8) {
      throw;
    }

    if (!(response == "SUCCESS")) {
      throw;
    }
  }
};

}  // namespace _ReQL

#endif  // REQL_REQL_HANDSHAKE_HPP_
