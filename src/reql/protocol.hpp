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

#ifndef REQL_REQL_PROTOCOL_HPP_
#define REQL_REQL_PROTOCOL_HPP_

#include "./reql/handshake.hpp"
#include "./reql/query.hpp"
#include "./reql/response.hpp"
#include "./reql/socket.hpp"
#include "./reql/stream.hpp"
#include "./reql/types.hpp"

namespace _ReQL {

template <class str_t>
class Protocol_t {
public:
  Protocol_t() {}

  Protocol_t(const str_t &addr, const str_t &port, const str_t &auth) : p_sock(addr, port) {
    Handshake_t<str_t>(p_sock, auth);
  }

  bool isOpen() const {
    return p_sock.isOpen();
  }

  Protocol_t &operator <<(Query_t<str_t> &query) {
    auto wire_query = query.str();
    auto size = wire_query.size();

    if (size > UINT32_MAX) {
      throw std::exception();
    }

    Stream<str_t> stream;

    ReQL_Byte token_bytes[8];
    make_token(token_bytes, query.token);

    ReQL_Byte size_bytes[4];
    make_size(size_bytes, static_cast<ReQL_Size>(size));

    stream << str_t(token_bytes, 8) << str_t(size_bytes, 4) << wire_query;

    p_sock.write(stream.str());

    return *this;
  }

  Protocol_t &operator >>(Response_t<str_t> &result) {
    auto header = p_sock.read(12);
    auto token = get_token(header.c_str());
    header = header.substr(8);
    result = Response_t<str_t>(p_sock.read(get_size(header.c_str())), token);
    return *this;
  }

  void stop(ReQL_Token t) {
    Query_t<str_t> query(t, REQL_STOP);
    (*this) << query;
  }

  void cont(ReQL_Token t) {
    Query_t<str_t> query(t, REQL_CONTINUE);
    (*this) << query;
  }

  Socket_t<str_t> p_sock;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PROTOCOL_HPP_
