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

namespace _ReQL {

template <class elem_t>
class Queue {
public:
  void push(elem_t &&value) {
  }
  bool empty() {
  }
  void pop(elem_t &ref) {
  }
};

template <class elem_t>
class Pipe {
public:
  Pipe() {
    close();
  }

  class Closed : std::exception {};

  template <class func_t>
  Pipe(func_t func) : p_thread([func, this] {
    try {
      while (true) {
        *this << func();
      }
    } catch (Closed &) {
    }
  }) {}

  ~Pipe() { close(); p_thread.join(); }

  template <class output_t, class func_t>
  auto map(func_t func) {
    return Pipe<output_t>([func, this] {
      elem_t res;
      *this >> res;
      return func(res);
    });
  }

  class Sink {
  public:
    Sink() {}

    template <class func_t>
    Sink(func_t func, Pipe<elem_t> &other) : p_thread([func, &other] {
      elem_t res;
      other >> res;
      func(res);
    }) {}

    Sink(Sink &&other) : p_thread(std::move(other.p_thread)) {}

    ~Sink() { p_thread.join(); }

    Sink &operator =(Sink &&other) {
      if (this != &other) {
        p_thread.join();
        p_thread = std::move(other.p_thread);
      }
      return *this;
    }
    
    std::thread p_thread;
  };
  
  template <class func_t>
  auto sink(func_t func) {
    return Sink(func, *this);
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

  Pipe &operator <<(elem_t &&value) {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (p_flag) {
      throw Closed();
    }
    p_queue.push(std::move(value));
    p_cond.notify_one();
    return *this;
  }

  Pipe &operator >>(elem_t &value) {
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

  std::condition_variable_any p_cond;
  char p_flag;
  std::mutex p_mutex;
  Queue<elem_t> p_queue;
  std::thread p_thread;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PIPE_HPP_
