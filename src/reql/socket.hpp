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

#ifndef REQL_REQL_SOCKET_HPP_
#define REQL_REQL_SOCKET_HPP_

#include <atomic>
#include <memory>

#ifdef __MINGW32__
#include <cstdint>
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

template <class str_t>
int connect(const str_t &addr, const str_t &port) {
  struct addrinfo hints;
  struct addrinfo *result, *rp;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;
  hints.ai_protocol = IPPROTO_TCP;

  if (getaddrinfo(addr.c_str(), port.c_str(), &hints, &result) != 0) {
    throw;
  }

  int sock = -1;

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

  return sock;
}

template <class str_t>
class Socket_t {
public:
  Socket_t() : Socket_t(-1) {}

  Socket_t(const str_t &addr, const str_t &port) : Socket_t(connect(addr, port)) {}

  Socket_t(const int sock) : p_sock(sock) {}

  Socket_t(Socket_t &&other) : Socket_t(other.p_sock.exchange(-1)) {}

  ~Socket_t() {
    int sock = p_sock.exchange(-1);
    if (sock >= 0) {
      ::close(sock);
    }
  }

  Socket_t &operator =(Socket_t &&other) {
    if (this != &other) {
      p_sock.store(other.p_sock.exchange(-1));
    }
    return *this;
  }

  bool isOpen() const {
    return p_sock.load() >= 0;
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

  str_t read() const {
    char buffer[200];
    auto size = recv(p_sock.load(), buffer, 200, 0);
    return str_t(buffer, size);
  }

  str_t read(size_t size) const {
    std::unique_ptr<char> buffer(new char[size]);
    size = recvfrom(p_sock.load(), buffer.get(), size, 0, nullptr, nullptr);
    return str_t(buffer.get(), size);
  }

  void write(const str_t &out) const {
    send(p_sock.load(), out.c_str(), out.size(), 0);
  }

  std::atomic<int> p_sock;
};

}  // namespace _ReQL

#endif  // REQL_REQL_SOCKET_HPP_
