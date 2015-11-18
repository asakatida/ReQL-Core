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

#ifndef REQL_REQL_CONNECTION_HPP_
#define REQL_REQL_CONNECTION_HPP_

#include "./reql/pipe.hpp"
#include "./reql/query.hpp"
#include "./reql/stream.hpp"
#include "./reql/types.hpp"

#include <atomic>
#include <map>
#include <mutex>
#include <thread>

#ifdef __MINGW32__
#include <stdint.h>
#include <io.h>

typedef unsigned __LONG32 ULONG;
typedef short SHORT;
typedef unsigned char UCHAR;

#include <nettypes.h>
#include <netprov.h>
#else
#include <netdb.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#endif

namespace _ReQL {

template <class byte_t>
ReQL_Size
get_size(const byte_t *buf) {
  return (static_cast<ReQL_Size>(buf[0])<<0) | (static_cast<ReQL_Size>(buf[1])<<8) | (static_cast<ReQL_Size>(buf[2])<<16) | (static_cast<ReQL_Size>(buf[3])<<24);
}

template <class byte_t>
ReQL_Token
get_token(const byte_t *buf) {
  return (static_cast<ReQL_Token>(buf[0])<<0) | (static_cast<ReQL_Token>(buf[1])<<8) | (static_cast<ReQL_Token>(buf[2])<<16) | (static_cast<ReQL_Token>(buf[3])<<24) | (static_cast<ReQL_Token>(buf[4])<<32) | (static_cast<ReQL_Token>(buf[5])<<40) | (static_cast<ReQL_Token>(buf[6])<<48) | (static_cast<ReQL_Token>(buf[7])<<56);
}

template <class sock_t>
class Socket_t {
public:
  Socket_t() : p_sock(-1) {}

  template <class str_t>
  Socket_t(str_t &addr, str_t &port) : p_sock(-1) {
    struct addrinfo hints;
    struct addrinfo *result, *rp;

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(addr.c_str(), port.c_str(), &hints, &result) != 0) {
      throw;
    }

    sock_t sock = -1;

    for (rp = result; rp != nullptr; rp = rp->ai_next) {
      sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

      if (sock == -1) continue;

      if (connect(sock, rp->ai_addr, rp->ai_addrlen) != -1) break;

      ::close(sock);
    }

    if (rp == nullptr) {
      freeaddrinfo(result);
      throw;
    }

    freeaddrinfo(result);

    p_sock.store(sock);
  }

  Socket_t(const sock_t sock) : p_sock(sock) {}

  Socket_t(Socket_t &&other) : p_sock(other.p_sock.exchange(-1)) {}

  ~Socket_t() {
    sock_t sock = p_sock.exchange(-1);
    if (sock >= 0) {
      ::close(sock);
    }
  }

  void set_timeout(unsigned long s, unsigned long us) const {
#ifdef __MINGW32__
    const struct timeval timeout = {static_cast<long>(s), static_cast<long>(us)};

    if (setsockopt(p_sock.load(), SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<const char *>(&timeout), sizeof(struct timeval))) {
      throw;
    }

    if (setsockopt(p_sock.load(), SOL_SOCKET, SO_SNDTIMEO, reinterpret_cast<const char *>(&timeout), sizeof(struct timeval))) {
      throw;
    }
#else
    const struct timeval timeout = {static_cast<__darwin_time_t>(s), static_cast<__darwin_suseconds_t>(us)};

    if (setsockopt(p_sock.load(), SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval))) {
      throw;
    }

    if (setsockopt(p_sock.load(), SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(struct timeval))) {
      throw;
    }
#endif
  }

  void set_timeout(unsigned long s) const {
    set_timeout(s, 0);
  }

  void set_timeout() const {
    set_timeout(0, 1);
  }

  template <class str_t>
  str_t read() const {
    char buffer[200];
    auto size = recv(p_sock.load(), buffer, 200, 0);
    return str_t(buffer, size);
  }

  template <class str_t>
  str_t read(size_t size) const {
    std::unique_ptr<char> buffer(new char[size]);
    size = recvfrom(p_sock.load(), buffer.get(), size, 0, nullptr, nullptr);
    return str_t(buffer.get(), size);
  }

  template <class str_t>
  void write(const str_t &out) const {
    send(p_sock.load(), out.c_str(), out.size(), 0);
  }

  std::atomic<sock_t> p_sock;
};

template <class sock_t>
class Handshake_t {
public:
  template <class in_func_t, class out_func_t>
  Handshake_t(const sock_t &sock, in_func_t in, out_func_t out) {
  }
};

template <class sock_t>
class Protocol_t {
public:
  Protocol_t() {}

  template <class str_t>
  Protocol_t(str_t &addr, str_t &port, str_t &auth) : p_sock(addr, port) {
    Handshake_t<sock_t>(p_sock, auth);
  }

  template <class str_t>
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

  template <class str_t>
  Protocol_t &operator >>(str_t &result) {
    return *this;
  }

  void stop(ReQL_Token t) {
    Query_t<ImmutableString> query(t, REQL_STOP);
    (*this) << query;
  }

  void cont(ReQL_Token t) {
    Query_t<ImmutableString> query(t, REQL_CONTINUE);
    (*this) << query;
  }

  sock_t p_sock;
};

template <class conn_t>
void *
conn_loop(void *data) {
  conn_t *conn = reinterpret_cast<conn_t *>(data);
  ReQL_Token token = 0;
  ReQL_Size size = 0;

  std::basic_string<ReQL_Byte> response;

  try {
    while (conn->isOpen()) {
      conn->lock();
      if (conn->p_cursors.size() == 0) {
        conn->unlock();
        sched_yield();
        continue;
      }
      conn->unlock();

      response.append(conn->recv());

      if (size > 0) {
        if (response.length() >= size) {
          conn->lock();
          for (auto &&pair : conn->p_cursors) {
            if (0 == token) {
            }
          }
          conn->unlock();

          response = response.substr(size);
          response.reserve(12);
          size = 0;
        }
      } else if (response.length() >= 12) {
        token = get_token(response.c_str());
        size = get_size(&response.c_str()[8]);
        response = response.substr(12);
        response.reserve(size);
      }
    }
  } catch (std::exception &e) {
    conn->close();
    throw e;
  }

  conn->close();

  return nullptr;
}

template <class cur_t>
class Conn_t {
public:
  template <class conn_t>
  friend void *conn_loop(void *data);

  class Token {
  public:
    Token() {}

    Token(ReQL_Token token, ImmutableString &&json) : p_token(token), p_json(std::move(json)) {}

    ReQL_Token p_token;
    ImmutableString p_json;
  };

  Conn_t(std::string &addr, std::string &port, std::string &auth) : p_socket(-1) {

    p_socket.store(sock);

    set_timeout(20, 0);

    ReQL_Byte iov_base[3][4];

    make_size(iov_base[0], VERSION);
    make_size(iov_base[1], auth.size());
    make_size(iov_base[2], PROTOCOL);

    struct iovec magic[4];

    magic[0].iov_base = iov_base[0];
    magic[0].iov_len = 4;

    magic[1].iov_base = iov_base[1];
    magic[1].iov_len = 4;

    magic[2].iov_base = const_cast<char *>(auth.c_str());
    magic[2].iov_len = auth.size();

    magic[3].iov_base = iov_base[2];
    magic[3].iov_len = 4;

    send(magic, 4, auth.size() + 12);
    auto response = recv();

    if (response.size() != 8) {
      throw;
    }

    if (response != "SUCCESS") {
      throw;
    }

    set_timeout();

    p_sink = Pipe<Token>([]() {
    }).sink([](Token &) {
    });
  }

  Conn_t(Conn_t &&other) : p_max_token(std::move(other.p_max_token)), p_cursors(std::move(other.p_cursors)), p_socket(std::move(other.p_socket)) {}

  ~Conn_t() {
    close();
    p_cursors.close();
  }

  Conn_t &operator =(Conn_t &&other) {
    if (this != &other) {
      p_cursors = std::move(other.p_cursors);
      p_max_token.store(other.p_max_token.load());
      p_socket = std::move(other.p_socket);
    }
    return *this;
  }

  bool isOpen() const {
    return p_socket.load() >= 0;
  }

  template <class query_t>
  cur_t run(const query_t &query) {
    return run(query, Obj_t<std::map<String_t<std::string>, String_t<std::string>>>(std::map<String_t<std::string>, String_t<std::string>>()));
  }

  template <class kwargs_t, class query_t>
  cur_t run(const query_t &query, const kwargs_t &kwargs) {
    auto wire_query = start(query, kwargs);

    const auto t = token();
    send(wire_query, t);

    cur_t cur(reinterpret_cast<typename cur_t::conn_t *>(this), t);
    return cur;
  }

  template <class kwargs_t, class query_t>
  void noReply(const query_t &query, const kwargs_t &kwargs) {
    send(start(query, kwargs), token());
  }

  void noReplyWait() {
    const auto t = token();
    cur_t cur(this, t);
    send(constant(REQL_NOREPLY_WAIT), t);
    cur.drain();
  }

  void stop(ReQL_Token t) {
    return send(constant(REQL_STOP), t);
  }

  void cont(ReQL_Token t) {
    return send(constant(REQL_CONTINUE), t);
  }

  void close() {
    p_socket = -1;
  }

  void set_timeout(unsigned long s, unsigned long us) {
#ifdef __MINGW32__
    const struct timeval timeout = {static_cast<long>(s), static_cast<long>(us)};

    if (setsockopt(p_socket.load(), SOL_SOCKET, SO_RCVTIMEO, reinterpret_cast<const char *>(&timeout), sizeof(struct timeval))) {
      throw;
    }

    if (setsockopt(p_socket.load(), SOL_SOCKET, SO_SNDTIMEO, reinterpret_cast<const char *>(&timeout), sizeof(struct timeval))) {
      throw;
    }
#else
    const struct timeval timeout = {static_cast<__darwin_time_t>(s), static_cast<__darwin_suseconds_t>(us)};

    if (setsockopt(p_socket.load(), SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(struct timeval))) {
      throw;
    }

    if (setsockopt(p_socket.load(), SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(struct timeval))) {
      throw;
    }
#endif
  }

  void set_timeout(unsigned long s) {
    set_timeout(s, 0);
  }

  void set_timeout() {
    set_timeout(0, 1);
  }

  template <class kwargs_t, class query_t>
  ImmutableString start(const query_t &query, const kwargs_t &kwargs) {
    _Stream wire_query;
    wire_query << "[" << static_cast<int>(REQL_START) << ",";
    query.toJSON(wire_query);
    wire_query << ",";
    kwargs.toJSON(wire_query);
    wire_query << "]";
    return wire_query.str();
  }

  void send(const ImmutableString &wire_query, ReQL_Token t) {
    auto size = wire_query.size();

    if (size > UINT32_MAX) {
      throw std::exception();
    }

    ReQL_Byte token_bytes[8];
    make_token(token_bytes, t);

    ReQL_Byte size_buf[4];
    make_size(size_buf, static_cast<ReQL_Size>(size));

    struct iovec data[3];

    data[0].iov_base = token_bytes;
    data[0].iov_len = 8;

    data[1].iov_base = size_buf;
    data[1].iov_len = 4;

    data[2].iov_base = const_cast<void *>(reinterpret_cast<const void *>(wire_query.data()));
    data[2].iov_len = size;

    if (writev(p_socket.load(), data, size) != (static_cast<ssize_t>(size) + 12)) {
      throw std::exception();
    }
  }

  auto recv(ReQL_Byte *buf, ReQL_Size max_size) {
    return recvfrom(p_socket.load(), buf, max_size, 0, nullptr, nullptr);
  }

  auto recv() {
    auto buf = new ReQL_Byte[200];
    auto size = recvfrom(p_socket.load(), buf, 0, 0, nullptr, nullptr);
    auto res = std::basic_string<ReQL_Byte>(buf, size);
    delete buf;
    return res;
  }

  auto token() {
    return p_max_token++;
  }

  enum Query_e {
    REQL_CONTINUE = 2,
    REQL_NOREPLY_WAIT = 4,
    REQL_START = 1,
    REQL_STOP = 3
  };

  static ImmutableString constant(const Query_e type) {
    _Stream wire_query;
    wire_query << "[" << static_cast<int>(type) << "]";
    return wire_query.str();
  }

  static void make_size(char *buf, const ReQL_Size magic) {
    buf[0] = (magic >> 0) & 0xFF;
    buf[1] = (magic >> 8) & 0xFF;
    buf[2] = (magic >> 16) & 0xFF;
    buf[3] = (magic >> 24) & 0xFF;
  }

  static void make_token(char *buf, const ReQL_Token magic) {
    buf[0] = (magic >> 0) & 0xFF;
    buf[1] = (magic >> 8) & 0xFF;
    buf[2] = (magic >> 16) & 0xFF;
    buf[3] = (magic >> 24) & 0xFF;
    buf[4] = (magic >> 32) & 0xFF;
    buf[5] = (magic >> 40) & 0xFF;
    buf[6] = (magic >> 48) & 0xFF;
    buf[7] = (magic >> 56) & 0xFF;
  }

  static const ReQL_Size VERSION = 0x400c2d20;
  static const ReQL_Size PROTOCOL = 0x7e6970c7;

  class BTree {
  public:
    void close() {
    }
    std::mutex p_mutex;
  };

  Socket_t<int> p_socket;
  std::atomic<ReQL_Token> p_max_token;
  BTree p_cursors;
  typename Pipe<ImmutableString>::Sink p_sink;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CONNECTION_HPP_
