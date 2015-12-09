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
#include "./reql/socket.hpp"

#include <atomic>
#include <cstdint>
#include <sstream>
#include <string>
#include <thread>

namespace _ReQL {

template <class auth_e, class handshake_e, class socket_e>
class Protocol_t {
public:
  template <class addr_t, class auth_t, class func_t, class port_t>
  void connect(const addr_t &addr, const port_t &port, const auth_t &auth, func_t func) {
    p_sock.connect(addr, port);
    Handshake_t<auth_e, handshake_e>(p_sock, auth);
    std::thread([func, this] {
      size_t buff_size;
      std::ostringstream buffer;
      while (true) {
        while (buff_size < 12) {
          auto string = p_sock.read();
          buff_size += string.size();
          buffer << string;
        }
        auto string = buffer.str();
        buffer.clear();
        buffer << string.substr(12);
        auto token = get_token(string.c_str());
        auto size = get_size(string.c_str() + 8);
        while (buff_size < size) {
          auto string = p_sock.read();
          buff_size += string.size();
          buffer << string;
        }
        string = buffer.str();
        buffer.clear();
        buffer << string.substr(size);
        run(token, make_query(REQL_CONTINUE));
        func(string.substr(0, size), token);
      }
    }).detach();
  }

  void disconnect() {
    p_sock.disconnect();
  }

  bool connected() const {
    return p_sock.connected();
  }

  template <class query_t>
  std::uint64_t operator <<(query_t query) {
    auto token = p_next_token++;
    run(token, query);
    return token;
  }

  void stop(std::uint64_t token) {
    run(token, make_query(REQL_STOP));
  }

private:
  template <class query_t>
  void run(std::uint64_t token, query_t query) {
    std::ostringstream stream("\0\0\0\0\0\0\0\0\0\0\0\0", std::ios_base::ate);
    stream << std::boolalpha
           << std::setprecision(std::numeric_limits<double>::digits10 + 1)
           << query;

    auto size = stream.str().size() - 12;

    char token_bytes[8];
    make_token(token_bytes, token);

    char size_bytes[4];
    make_size(size_bytes, static_cast<std::uint32_t>(size));

    stream.seekp(0);
    stream << std::string(token_bytes, 8)
           << std::string(size_bytes, 4);

    p_sock.write(stream.str());
  }

  static std::uint32_t get_size(const char *buf) {
    return (static_cast<std::uint32_t>(buf[0]) << 0) |
    (static_cast<std::uint32_t>(buf[1]) << 8) |
    (static_cast<std::uint32_t>(buf[2]) << 16) |
    (static_cast<std::uint32_t>(buf[3]) << 24);
  }

  static void make_size(char *buf, const std::uint32_t magic) {
    buf[0] = static_cast<char>((magic >> 0) & 0xFF);
    buf[1] = static_cast<char>((magic >> 8) & 0xFF);
    buf[2] = static_cast<char>((magic >> 16) & 0xFF);
    buf[3] = static_cast<char>((magic >> 24) & 0xFF);
  }

  static std::uint64_t get_token(const char *buf) {
    return (static_cast<std::uint64_t>(buf[0]) << 0) |
    (static_cast<std::uint64_t>(buf[1]) << 8) |
    (static_cast<std::uint64_t>(buf[2]) << 16) |
    (static_cast<std::uint64_t>(buf[3]) << 24) |
    (static_cast<std::uint64_t>(buf[4]) << 32) |
    (static_cast<std::uint64_t>(buf[5]) << 40) |
    (static_cast<std::uint64_t>(buf[6]) << 48) |
    (static_cast<std::uint64_t>(buf[7]) << 56);
  }

  static void make_token(char *buf, const std::uint64_t magic) {
    buf[0] = static_cast<char>((magic >> 0) & 0xFF);
    buf[1] = static_cast<char>((magic >> 8) & 0xFF);
    buf[2] = static_cast<char>((magic >> 16) & 0xFF);
    buf[3] = static_cast<char>((magic >> 24) & 0xFF);
    buf[4] = static_cast<char>((magic >> 32) & 0xFF);
    buf[5] = static_cast<char>((magic >> 40) & 0xFF);
    buf[6] = static_cast<char>((magic >> 48) & 0xFF);
    buf[7] = static_cast<char>((magic >> 56) & 0xFF);
  }

  std::atomic<std::uint64_t> p_next_token;
  Socket_t<socket_e> p_sock;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PROTOCOL_HPP_
