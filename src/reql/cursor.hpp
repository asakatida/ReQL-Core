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

#ifndef REQL_REQL_CURSOR_HPP_
#define REQL_REQL_CURSOR_HPP_

#include "./reql/decode.hpp"
#include "./reql/pipe.hpp"

#include <atomic>

namespace _ReQL {

enum Response_t {
  REQL_CLIENT_ERROR = 16,
  REQL_COMPILE_ERROR = 17,
  REQL_RUNTIME_ERROR = 18,
  REQL_SUCCESS_ATOM = 1,
  REQL_SUCCESS_PARTIAL = 3,
  REQL_SUCCESS_SEQUENCE = 2,
  REQL_WAIT_COMPLETE = 4
};

template <class cur_t>
void *
cur_loop(void *data) {
  cur_t *cur = reinterpret_cast<cur_t *>(data);

  while (cur->isOpen()) {
    if (!cur->p_result) {
      sched_yield();
      continue;
    }
    switch (cur->p_r_type) {
      case REQL_SUCCESS_ATOM:
      case REQL_SUCCESS_SEQUENCE:
      case REQL_WAIT_COMPLETE: {
        cur->p_open.store(false);
        break;
      }
      case REQL_SUCCESS_PARTIAL: {
        if (cur->p_conn && cur->p_conn->isOpen()) {
          cur->p_conn->cont(cur->p_token);
        }
        break;
      }
      case REQL_CLIENT_ERROR:
      case REQL_COMPILE_ERROR:
      case REQL_RUNTIME_ERROR:
      default: {
        cur->p_open.store(false);
      }
    }
  }

  return nullptr;
}

template <class _conn_t, class parser_t, class event_t>
class Cur_t {
  typedef _conn_t conn_t;

  Cur_t(conn_t *conn, ReQL_Token token) : p_token(token), p_conn(conn), p_open(true) {
    p_thread = std::thread(cur_loop, this);
  }

  Cur_t(Cur_t &&other) : p_open(other.p_open.load()), p_mutex(std::move(other.p_mutex)), p_thread(std::move(other.p_thread)), p_token(std::move(other.p_token)), p_conn(std::move(other.p_conn)), p_events(std::move(other.p_events)), p_results(std::move(other.p_results)) {}

  ~Cur_t() {
    close();
    p_thread.join();
  }

  Cur_t &operator =(Cur_t &&other) {
    if (this != &other) {
      p_conn.store(other.p_conn.exchange(nullptr));
    }
    return *this;
  }

  void close() {
    if (p_open.exchange(false)) {
    }
    lock();
    if (p_conn && p_conn->isOpen()) {
      p_conn->stop(p_token);
    }
    p_conn = nullptr;
    unlock();
  }

  template <class str_t>
  void set(const str_t &res) {
    decode(res, parser_t(p_results));
  }

  void unlock() {
  }

  Pipe<typename parser_t::result_t> p_ostream;
  Pipe<ImmutableString> p_istream;
  const ReQL_Token p_token;
  std::atomic<conn_t *> p_conn;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CURSOR_HPP_
