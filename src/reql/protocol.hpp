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

template <class str_t>
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

  template <class func_t>
  Protocol_t(const str_t &addr, const str_t &port, const str_t &auth, func_t func) : p_sock(addr, port) {
    Handshake_t<str_t>(p_sock, auth);
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
        func(Response_t<str_t, Protocol_t>(buffer[size], token, this));
      }
    });
  }

  bool isOpen() const {
    return p_sock.isOpen();
  }

  Protocol_t &operator <<(Query_t<str_t> query) {
    auto wire_query = query.str();
    auto size = wire_query.size();

    if (size > UINT32_MAX) {
      throw std::exception();
    }

    Stream_t<str_t> stream;

    ReQL_Byte token_bytes[8];
    make_token(token_bytes, query.token());

    ReQL_Byte size_bytes[4];
    make_size(size_bytes, static_cast<ReQL_Size>(size));

    stream << str_t(token_bytes, 8) << str_t(size_bytes, 4) << wire_query;

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
    (*this) << Query_t<str_t>(t, REQL_STOP);
  }

  void cont(ReQL_Token t) {
    (*this) << Query_t<str_t>(t, REQL_CONTINUE);
  }

private:
  Socket_t<str_t> p_sock;
  std::thread p_thread;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PROTOCOL_HPP_
