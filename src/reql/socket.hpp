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

#include <cerrno>
#include <memory>
#include <thread>

#ifdef __MINGW32__
#include <winsock2.h>
#include <ws2tcpip.h>
#include <io.h>
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

template <class socket_e>
class Socket_t {
public:
  template <class addr_t, class port_t>
  static int _connect(const addr_t &addr, const port_t &port) {
    struct addrinfo hints;
    struct addrinfo *result, *rp;

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_TCP;

    int sts = 0;

    std::chrono::seconds(0);

    if ((sts = getaddrinfo(addr.c_str(), port.c_str(), &hints, &result)) != 0) {
      throw socket_e(gai_strerror(sts));
    }

    int sock = -1;

    for (rp = result; rp != nullptr; rp = rp->ai_next) {
      sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

      if (sock == -1) continue;

      if (::connect(sock, rp->ai_addr, rp->ai_addrlen) != -1) break;

      ::close(sock);
    }

    freeaddrinfo(result);

    if (rp) {
      return sock;
    }

    throw socket_e("");  // TODO
  }
  
  template <class addr_t, class port_t>
  void connect(const addr_t &addr, const port_t &port) {
    p_sock = std::make_shared<int>(_connect(addr, port));
  }

  void disconnect() {
    p_sock.reset();
  }
  
  bool connected() const {
    return p_sock ? true : false;
  }

  std::string read() {
    int sock = load();
    wait_read();
    ssize_t size = 0;
    socklen_t opt_len = sizeof(ssize_t);
    auto sts = getsockopt(sock, SOL_SOCKET, SO_NREAD, &size, &opt_len);
    if (sts < 0) {
      switch (errno) {
        case EBADF:
        case EFAULT:
        case EINVAL:
        case ENOBUFS:
        case ENOMEM:
        case ENOPROTOOPT:
        case ENOTSOCK: {
          throw socket_e("");  // TODO
        }
        default: {
          throw socket_e("");  // TODO
        }
      }
      throw std::exception();
    }
    std::unique_ptr<char> buffer(new char[static_cast<size_t>(size)]);
    size = recvfrom(sock, buffer.get(), static_cast<size_t>(size), MSG_WAITALL, nullptr, nullptr);
    if (size == 0) {
      throw socket_e("");  // TODO
    } else if (size < 0) {
      switch (errno) {
        case EAGAIN: {
          return std::string();
        }
        case EBADF:
        case ECONNRESET:
        case EFAULT:
        case EINTR:
        case EINVAL:
        case ENOBUFS:
        case ENOTCONN:
        case ENOTSOCK:
        case EOPNOTSUPP:
        case ETIMEDOUT: {
          throw socket_e("");  // TODO
        }
        default: {
          throw socket_e("");  // TODO
        }
      }
      throw std::exception();
    }
    return std::string(buffer.get(), static_cast<size_t>(size));
  }

  void write(const std::string &out) {
    int sock = load();
    wait_write();
    send(sock, out.c_str(), out.size(), 0);
  }

private:
  bool poll(bool read = true) {
    int sock = load();
    timeval to = {0, 0};
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sock, &set);
    auto sts = ::select(sock + 1,
                        read ? &set : nullptr,
                        read ? nullptr : &set,
                        &set, &to);
    if (sts == 0) {
      return false;
    } else if (sts < 0) {
      switch (errno) {
        case EAGAIN:
        case EBADF:
        case EINTR:
        case EINVAL:{
          throw socket_e("");  // TODO
        }
        default: {
          throw socket_e("");  // TODO
        }
      }
      throw std::exception();
    }
    return true;
  }

  void wait_read() {
    while (!poll()) {
      std::this_thread::yield();
    }
  }

  void wait_write() {
    while (!poll(false)) {
      std::this_thread::yield();
    }
  }

  int load() {
    int sock = *p_sock;
    if (sock) {
      return sock;
    }
    throw socket_e("");  // TODO
  }

  static void deleter(int *sock) {
    ::close(*sock);
    delete sock;
  }

  std::shared_ptr<int> p_sock;
};

}  // namespace _ReQL

#endif  // REQL_REQL_SOCKET_HPP_
