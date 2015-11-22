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
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

namespace _ReQL {

template <class elem_t>
class Pipe_t;

template <class elem_t>
class Static_Pipe_t {
public:
  Static_Pipe_t() {
    close();
  }

  class Closed : std::exception {};

  template <class func_t>
  Static_Pipe_t(func_t func) : p_thread([func, this] {
    try {
      while (true) {
        this->push(func());
      }
    } catch (Closed &) {
    } catch (std::exception &) {
      close();
    }
  }) {}

  template <class func_t, class input_t>
  Static_Pipe_t(func_t func, std::shared_ptr<Static_Pipe_t<input_t>> &pipe) : Static_Pipe_t([func, pipe] {
    input_t res;
    pipe->pop(res);
    return func(std::move(res));
  }) {}

  ~Static_Pipe_t() { close(); p_thread.join(); }

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

  Static_Pipe_t &push(elem_t &&value) {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (p_flag) {
      throw Closed();
    }
    p_queue.push(std::move(value));
    p_cond.notify_one();
    return *this;
  }

  Static_Pipe_t &pop(elem_t &value) {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (p_queue.empty()) {
      if (p_flag) {
        throw Closed();
      }
      p_cond.wait(p_mutex, [this]() {
        return !p_queue.empty();
      });
    }
    value = p_queue.back();
    p_queue.pop();
    return *this;
  }

  std::condition_variable_any p_cond;
  char p_flag;
  std::mutex p_mutex;
  std::queue<elem_t> p_queue;
  std::thread p_thread;
};

template <class elem_t>
class Pipe_t {
public:
  Pipe_t() : p_pipe(new Static_Pipe_t<elem_t>) {}

  template <class func_t, class input_t>
  Pipe_t(func_t func, Pipe_t<input_t> &other) : p_pipe(new Static_Pipe_t<elem_t>(func, other.p_pipe)) {}

  Pipe_t(const Pipe_t &other) : p_pipe(other.p_pipe) {}

  Pipe_t(Pipe_t &&other) : p_pipe(std::move(other.p_pipe)) {}

  template <class func_t>
  Pipe_t(func_t func) : p_pipe(new Static_Pipe_t<elem_t>(func)) {}

  Pipe_t &operator =(const Pipe_t &other) {
    if (this != &other) {
      p_pipe = other.p_pipe;
    }
    return *this;
  }

  Pipe_t &operator =(Pipe_t &&other) {
    if (this != &other) {
      p_pipe = std::move(other.p_pipe);
    }
    return *this;
  }

  class Sink_t {
  public:
    Sink_t() {}

    template <class func_t>
    Sink_t(func_t func, std::shared_ptr<Static_Pipe_t<elem_t>> &pipe) : p_thread([func, pipe] {
      while (true) {
        elem_t res;
        pipe->pop(res);
        func(std::move(res));
      }
    }) {}

    Sink_t(Sink_t &&other) : p_thread(std::move(other.p_thread)) {}

    ~Sink_t() { p_thread.join(); }

    Sink_t &operator =(Sink_t &&other) {
      if (this != &other) {
        p_thread = std::move(other.p_thread);
      }
      return *this;
    }

    std::thread p_thread;
  };

  template <class func_t>
  Sink_t sink(func_t func) {
    return Sink_t(func, p_pipe);
  }

  Pipe_t &operator <<(elem_t &&value) {
    p_pipe->push(std::move(value));
    return *this;
  }

  Pipe_t &operator >>(elem_t &value) {
    p_pipe->pop(value);
    return *this;
  }

  bool isOpen() const {
    return !p_pipe->closed();
  }

  void close() {
    return p_pipe->close();
  }

  std::shared_ptr<Static_Pipe_t<elem_t> > p_pipe;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PIPE_HPP_
