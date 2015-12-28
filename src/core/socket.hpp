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

#include "./core/error.hpp"

#include <algorithm>
#include <atomic>
#include <cerrno>
#include <condition_variable>
#include <list>
#include <memory>

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

static const size_t READ_BUFFER_SIZE = 4048;
static const size_t MAX_POOL_SIZE = 16;

template <class elem_t>
class Observer_t;

template <class elem_t>
class Producer_t {
public:
  Producer_t() :
    p_active(std::make_shared<std::atomic_flag>(true)),
    p_cond(std::make_shared<std::condition_variable>()),
    p_list(std::make_shared<std::list<elem_t> >()),
    p_mutex(std::make_shared<std::mutex>()) {}

  Producer_t(Producer_t &&other) :
    p_active(std::move(other.p_active)),
    p_cond(std::move(other.p_cond)),
    p_list(std::move(other.p_list)),
    p_mutex(std::move(other.p_mutex)) {}

  ~Producer_t() {
    if (p_active) p_active->clear();
    if (p_cond) p_cond->notify_all();
  }

  void push(elem_t &&elem) {
    std::lock_guard<std::mutex> lock(*p_mutex);
    p_cond->notify_all();
    p_list->push_back(std::move(elem));
  }

  friend class Observer_t<elem_t>;

private:

  std::shared_ptr<std::atomic_flag> p_active;
  std::shared_ptr<std::condition_variable> p_cond;
  std::shared_ptr<std::list<elem_t> > p_list;
  std::shared_ptr<std::mutex> p_mutex;
};

template <class elem_t>
class Observer_t {
public:
  Observer_t(Producer_t<elem_t> &producer) :
    p_active(producer.p_active),
    p_cond(producer.p_cond),
    p_list(producer.p_list),
    p_mutex(producer.p_mutex) {}

  Observer_t(const Observer_t &other) :
    p_active(other.p_active),
    p_cond(other.p_cond),
    p_list(other.p_list),
    p_mutex(other.p_mutex) {}

  Observer_t(Observer_t &&other) :
    p_active(std::move(other.p_active)),
    p_cond(std::move(other.p_cond)),
    p_list(std::move(other.p_list)),
    p_mutex(std::move(other.p_mutex)) {}

  elem_t pop() {
    std::unique_lock<std::mutex> lock(*p_mutex);
    p_cond->wait(lock, [this] {
      auto active = p_active->test_and_set();
      if (active) {
        return !p_list->empty();
      }
      p_active->clear();
      return true;
    });
    return _pop();
  }

  std::unique_ptr<elem_t> pop_no_wait() {
    std::unique_lock<std::mutex> lock(*p_mutex);
    if (!p_list->empty()) {
      return std::make_unique<elem_t>(_pop());
    }
    return std::unique_ptr<elem_t>();
  }

private:

  elem_t _pop() {
    auto last = p_list->back();
    p_list->pop_back();
    return last;
  }

  const std::shared_ptr<std::atomic_flag> p_active;
  const std::shared_ptr<std::condition_variable> p_cond;
  const std::shared_ptr<std::list<elem_t> > p_list;
  const std::shared_ptr<std::mutex> p_mutex;
};

template <class elem_t>
struct Lazy_Queue_t {
  virtual bool complete()  = 0;

  virtual elem_t head() = 0;

  virtual Lazy_Queue_t &tail() = 0;
};

template <class elem_t>
struct Never_Queue_t final : Lazy_Queue_t<elem_t> {
  virtual bool complete() const override { return true; }

  virtual elem_t head() override {
    throw_error("");  // TODO
  }

  virtual Lazy_Queue_t<elem_t> &tail() override {
    throw_error("");  // TODO
  }
};

template <class elem_t>
struct Infinite_Queue_t : Lazy_Queue_t<elem_t> {
  virtual bool complete() const override final { return false; }

  virtual elem_t head() override final {
    if (p_first) {
      p_value = head_impl();
      p_first = false;
    }
    return p_value;
  }

  virtual elem_t head_impl() = 0;

  virtual Lazy_Queue_t<elem_t> &tail() override final {
    return *this;
  }

  bool p_first = true;
  elem_t p_value;
};

template <class elem_t>
struct Once_Queue_t : Lazy_Queue_t<elem_t> {
  virtual bool complete() const override final { return p_complete; }

  virtual elem_t head() override final {
    if (p_complete) throw_error("");  // TODO
    p_value = head_impl();
    p_complete = true;
    return p_value;
  }

  virtual elem_t head_impl() = 0;

  virtual Lazy_Queue_t<elem_t> &tail() override final {
    throw_error("");  // TODO
  }

  bool p_complete = false;
  elem_t p_value;
};

template <class elem_t>
struct Merge_Queue_t : Lazy_Queue_t<elem_t> {
  virtual bool complete() const override final {
    return left.complete() && right.complete();
  }

  virtual elem_t head() override final {
    if (left.complete()) return right.head();
    return left.head();
  }

  virtual Lazy_Queue_t<elem_t> &tail() override final {
    if (left.complete()) {
      right = right.tail();
    } else {
      left = left.tail();
    }
    return *this;
  }

  Lazy_Queue_t<elem_t> left;
  Lazy_Queue_t<elem_t> right;
};

template <class result_t>
class Socket_t {
public:
  Socket_t(Producer_t<std::string> &write_queue) : p_write_queue(write_queue) {
    for (auto &&__s : p_socks) {
      __s.store(-1);
    }
  }

  template <class addr_t, class port_t>
  static int _connect(const addr_t &addr, const port_t &port) {
    struct addrinfo hints;
    struct addrinfo *result, *rp;

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_TCP;

    int sts = 0;

    if ((sts = getaddrinfo(addr.c_str(), port.c_str(), &hints, &result)) != 0) {
      throw_error(gai_strerror(sts));
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

    throw_error("");  // TODO
  }

  template <class addr_t, class port_t>
  int connect(const addr_t &addr, const port_t &port) {
    int sock = _connect(addr, port);
    int closed_sock;
    for (auto &&__s : p_socks) {
      closed_sock = -1;
      if (__s.compare_exchange_strong(closed_sock, sock)) {
        return sock;
      }
    }
    ::close(sock);
    return -1;
  }

  void disconnect() {
    for (auto &&__s : p_socks) {
      int sock = __s.exchange(-1);
      if (sock >= 0) ::close(sock);
    }
  }

  bool connected() const {
    return std::any_of(std::begin(p_socks), std::end(p_socks), [](const std::atomic_int &sock) {
      return sock >= 0;
    });
  }

  void loop() {
    int max_sock = -1;
    timeval to = {0, 0};
    fd_set _read, _write, _error;
    FD_ZERO(&_read);
    FD_ZERO(&_write);
    FD_ZERO(&_error);
    for (auto &&__s : p_socks) {
      int sock = __s.load();
      if (sock < 0) continue;
      FD_SET(sock, &_read);
      FD_SET(sock, &_write);
      FD_SET(sock, &_error);
      max_sock = std::max(max_sock, sock);
    }
    ++max_sock;
    auto sts = ::select(max_sock, &_read, &_write, &_error, &to);
    if (sts == 0) {
      return;
    } else if (sts < 0) {
      switch (errno) {
        case EAGAIN: {
          return;
        }
        case EBADF:
        case EINTR:
        case EINVAL:{
          throw_error("");  // TODO
        }
        default: {
          throw_error("");  // TODO
        }
      }
      throw std::exception();  // TODO
    }
    for (int i=0; i<max_sock; ++i) {
      if (FD_ISSET(i, &_read)) {
        try {
          p_read_queue.push(read(i));
        } catch (std::exception &) {
          FD_SET(i, &_error);
        }
      }
      if (FD_ISSET(i, &_write)) {
        auto out = p_write_queue.pop_no_wait();
        if (out) {
          try {
            write(i, out.get());
          } catch (std::exception &) {
            FD_SET(i, &_error);
          }
        }
      }
      if (FD_ISSET(i, &_error)) {
        for (auto &&__s : p_socks) {
          int closed_sock = i;
          __s.compare_exchange_strong(closed_sock, -1);
        }
        ::close(i);
      }
    }
  }

  std::string read(int &sock) {
    char buffer[READ_BUFFER_SIZE];
    const ssize_t size = recvfrom(sock, buffer, READ_BUFFER_SIZE, MSG_WAITALL, nullptr, nullptr);
    if (size == 0) {
      throw_error("");  // TODO
    } else if (size < 0) {
      switch (errno) {
        case EAGAIN: {
          return read(sock);
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
          throw_error("");  // TODO
        }
        default: {
          throw_error("");  // TODO
        }
      }
      throw std::exception();
    }
    return std::string(buffer, static_cast<size_t>(size));
  }

  void write(int &sock, const std::string &out) {
    const ssize_t size = send(sock, out.c_str(), out.size(), 0);
    if (size == 0) {
      throw_error("");  // TODO
    } else if (size < 0) {
      switch (errno) {  // TODO
      }
      throw std::exception();
    } else if (static_cast<size_t>(size) < out.size()) {
      return write(sock, out.substr(size));
    }
  }

private:
  std::atomic_int p_socks[MAX_POOL_SIZE];
  Observer_t<std::string> p_write_queue;

public:
  Producer_t<std::string> p_read_queue;
};

}  // namespace _ReQL

#endif  // REQL_REQL_SOCKET_HPP_
