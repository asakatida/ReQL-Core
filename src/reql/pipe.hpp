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

#ifndef REQL_REQL_PIPE_HPP_
#define REQL_REQL_PIPE_HPP_

#include <atomic>
#include <condition_variable>
#include <exception>
#include <functional>
#include <mutex>
#include <thread>

namespace _ReQL {

template <class elem_t>
class Queue_t {
public:
  void push(elem_t &&value) {
    if (head->idx >= Buffer::size) {
    }
  }

  bool empty() {
    return buffer->idx == 0;
  }

  void pop(elem_t &ref) {
    elem_t value;
    ref = std::move(value);
  }

  class Buffer_t {
  public:
    static const int size = 10;

    elem_t buffer[size];
    Buffer_t * next;
    int idx;
  };

  Buffer_t * head;
  Buffer_t * buffer;
};

template <class elem_t>
class Pipe_t {
public:
  Pipe_t() {
    close();
  }

  class Closed : std::exception {};

  template <class func_t>
  Pipe_t(func_t func) : p_thread([func, this] {
    try {
      while (true) {
        this->push(func());
      }
    } catch (Closed &) {
    }
  }) {}

  ~Pipe_t() { close(); p_thread.join(); }

  template <class output_t, class func_t>
  auto map(func_t func) {
    return Pipe_t<output_t>([func, this] {
      elem_t res;
      this->pop(res);
      return func(res);
    });
  }

  template <class func_t>
  auto filter(func_t func) {
    return Pipe_t<elem_t>([func, this] {
      elem_t res;
      this->pop(res);
      while (!func(res)) {
        this->pop(res);
      }
      return res;
    });
  }

  class Sink_t {
  public:
    Sink_t() {}

    template <class func_t>
    Sink_t(func_t func, Pipe_t<elem_t> *other) : p_thread([func, other] {
      while (true) {
        elem_t res;
        other->pop(res);
        func(std::move(res));
      }
    }) {}

    Sink_t(Sink_t &&other) : p_thread(std::move(other.p_thread)) {}

    ~Sink_t() { p_thread.join(); }

    std::thread p_thread;
  };

  template <class func_t>
  Sink_t sink(func_t func) {
    Sink_t sink(func, this);
    return sink;
  }

  bool closed() {
    std::lock_guard<std::mutex> lock(p_mutex);
    return p_flag;
  }

  bool interupted() {
    std::lock_guard<std::mutex> lock(p_mutex);
    return p_flag & (1 << 7);
  }

  bool failed() {
    std::lock_guard<std::mutex> lock(p_mutex);
    return p_flag & (1 << 6);
  }

  void close() {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (!p_flag) {
      p_flag |= 1;
    }
  }

  void interupt() {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (!p_flag) {
      p_flag |= 1 << 7 | 1;
    }
  }

  void fail() {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (!p_flag) {
      p_flag |= 1 << 6 | 1;
    }
  }

  Pipe_t &push(elem_t &&value) {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (p_flag) {
      throw Closed();
    }
    p_queue.push(std::move(value));
    p_cond.notify_one();
    return *this;
  }

  Pipe_t &operator <<(elem_t &&value) {
    return push(std::move(value));
  }

  Pipe_t &pop(elem_t &value) {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (p_queue.empty()) {
      if (p_flag) {
        throw Closed();
      }
      p_cond.wait(p_mutex, [this]() {
        return !p_queue.empty();
      });
    }
    p_queue.pop(value);
    return *this;
  }

  Pipe_t &operator >>(elem_t &value) {
    return pop(value);
  }

  std::condition_variable_any p_cond;
  char p_flag;
  std::mutex p_mutex;
  Queue_t<elem_t> p_queue;
  std::thread p_thread;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PIPE_HPP_
