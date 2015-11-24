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
#include <thread>

#ifdef __MINGW32__
#include <winsock2.h>
#include <ws2tcpip.h>
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
    throw std::exception();
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
    throw std::exception();
  }

  freeaddrinfo(result);

  return sock;
}

template <class str_t>
class Socket_t {
public:
  Socket_t() : p_sock(-1) {}

  Socket_t(const str_t &addr, const str_t &port) : p_sock(connect(addr, port)) {}

  Socket_t(const int sock) : p_sock(sock) {}

  ~Socket_t() {
    close();
  }

  bool isOpen() const {
    return p_sock.load() >= 0;
  }

  void close() {
    int sock = p_sock.exchange(-1);
    if (sock >= 0) {
      ::close(sock);
    }
  }

  ImmutableString read() {
    int sock = load();
    wait_read();
    ssize_t size = getsockopt(sock, SOL_SOCKET, SO_NREAD, nullptr, nullptr);
    if (size < 0) {
      throw std::exception();
    }
    std::unique_ptr<char> buffer(new char[static_cast<size_t>(size)]);
    size = recvfrom(sock, buffer.get(), static_cast<size_t>(size), 0, nullptr, nullptr);
    if (size < 0) {
      throw std::exception();
    }
    return str_t(buffer.get(), static_cast<size_t>(size));
  }

  void write(const str_t &out) {
    int sock = load();
    wait_write();
    send(sock, out.c_str(), out.size(), 0);
  }

private:
  bool poll(bool read, bool write) {
    int sock = load();
    timeval to = {0, 0};
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sock, &set);
    auto sts = ::select(sock + 1,
                        read ? &set : nullptr,
                        write ? &set : nullptr,
                        &set, &to);
    if (sts == EAGAIN) return false;
    if (sts >= sock) return true;
  }

  void wait_read() {
    while (!poll(true, false)) {
      std::this_thread::yield();
    }
  }

  void wait_write() {
    while (!poll(false, true)) {
      std::this_thread::yield();
    }
  }

  int load() {
    int sock = p_sock.load();
    if (sock < 0) {
      throw std::exception();
    }
    return sock;
  }

  std::atomic<int> p_sock;
};

}  // namespace _ReQL

#endif  // REQL_REQL_SOCKET_HPP_
