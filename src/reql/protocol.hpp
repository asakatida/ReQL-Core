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

#include <thread>

namespace _ReQL {

template <class auth_e, class handshake_e, class socket_e>
class Protocol_t {
public:
  Protocol_t() {}

  class Buffer_t {
  public:
    Buffer_t &operator <<(ImmutableString &&string) {
      p_size += string.size();
      p_stream << std::move(string);
      return *this;
    }

    bool operator <(const size_t request) {
      return p_size < request;
    }

    ImmutableString operator [](const size_t request) {
      auto string = p_stream.str();
      p_stream = _Stream();
      p_stream << std::move(string.substr(request));
      return ImmutableString(string.data(), request);
    }
  private:

    size_t p_size;
    _Stream p_stream;
  };

  template <class addr_t, class auth_t, class func_t, class port_t>
  Protocol_t(const addr_t &addr, const port_t &port, const auth_t &auth, func_t func) : p_sock(addr, port) {
    Handshake_t<auth_e, handshake_e>(p_sock, auth);
    p_thread = std::thread([func, this] {
      Buffer_t buffer;
      while (true) {
        while (buffer < 12) {
          buffer << std::move(p_sock.read());
        }
        auto token = get_token(buffer[8].c_str());
        auto size = get_size(buffer[4].c_str());
        while (buffer < size) {
          buffer << std::move(p_sock.read());
        }
        func(Response_t<Protocol_t>(buffer[size], token, this));
      }
    });
  }

  bool isOpen() const {
    return p_sock.isOpen();
  }

  Protocol_t &operator <<(Query_t<ImmutableString> query) {
    auto wire_query = query.str();
    auto size = wire_query.size();

    if (size > UINT32_MAX) {
      throw std::exception();
    }

    _Stream stream;

    char token_bytes[8];
    make_token(token_bytes, query.token());

    char size_bytes[4];
    make_size(size_bytes, static_cast<ReQL_Size>(size));

    stream << ImmutableString(token_bytes, 8) << ImmutableString(size_bytes, 4) << wire_query;

    p_sock.write(stream.str());

    return *this;
  }

  ~Protocol_t() {
    p_sock.close();
    if (p_thread.joinable()) {
      p_thread.join();
    }
  }

  void stop(ReQL_Token t) {
    (*this) << Query_t<ImmutableString>(t, REQL_STOP);
  }

  void cont(ReQL_Token t) {
    (*this) << Query_t<ImmutableString>(t, REQL_CONTINUE);
  }

private:
  Socket_t<socket_e> p_sock;
  std::thread p_thread;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PROTOCOL_HPP_
