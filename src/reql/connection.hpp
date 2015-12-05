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

#include "./reql/decode.hpp"
#include "./reql/protocol.hpp"
#include "./reql/query.hpp"

#include <condition_variable>
#include <cstdint>
#include <functional>
#include <forward_list>
#include <iterator>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

namespace _ReQL {

template <class result_t>
class Cursor_t : public std::iterator<std::input_iterator_tag, result_t> {
public:
  Cursor_t &begin() noexcept {
    return *this;
  }

  Cursor_t &cbegin() noexcept {
    return *this;
  }

  const Cursor_t &end() const {
    return *p_end;
  }

  const Cursor_t &cend() const {
    return *p_end;
  }

  Cursor_t &operator ++() {
    std::unique_lock<std::mutex> lock(p_mutex);
    if (p_queue.empty()) {
      p_cond.wait(lock, [this] {
        return !p_queue->empty();
      });
    }
    p_result = p_queue.back();
    p_queue.pop();
    return *this;
  }

  const result_t &operator *() const;

  const result_t &operator ->() const;

  bool operator ==(const Cursor_t &other) const;

  bool operator !=(const Cursor_t &other) const;

  Cursor_t() : p_token(-1) {}

  Cursor_t(std::uint64_t token) : p_token(token), p_end(new Cursor_t) {}

  void operator ()(const std::string &json) {}

  std::condition_variable p_cond;
  const Cursor_t *p_end;
  std::mutex p_mutex;
  std::queue<result_t> p_queue;
  result_t p_result;
  const std::uint64_t p_token;
};

static const char *DEFAULT_ADDR = "localhost";
static const char *DEFAULT_PORT = "28015";

template <class auth_e, class handshake_e, class result_t, class socket_e>
class Conn_t {
public:
  void connect() {
    return connect(std::string(DEFAULT_ADDR));
  }

  void connect(const std::string &addr) {
    return connect(addr, std::string(DEFAULT_PORT), std::string(""));
  }

  void connect(const std::string &addr, const std::string &port) {
    return connect(addr, port, std::string(""));
  }

  void connect(const std::string &addr, const std::string &port, const std::string &auth) {
    p_protocol.connect(addr, port, auth, [this](const std::string &json, const std::uint64_t token) {
      std::lock_guard<std::mutex> lock(p_mutex);
      p_root[token](json);
    });
  }

  bool isOpen() const {
    return p_protocol.connected();
  }

  void close() {
    p_protocol.disconnect();
  }

  template <class query_t>
  auto run(const query_t &query) {
    return create(p_protocol << make_query(query));
  }

  template <class kwargs_t, class query_t>
  auto run(const query_t &query, const kwargs_t &kwargs) {
    return create(p_protocol << make_query(query, kwargs));
  }

  template <typename kwargs_t, typename query_t>
  void noReply(const query_t &query, const kwargs_t &kwargs) {
    p_protocol << make_query(query, kwargs);
  }

  void noReplyWait() {
    (p_protocol << make_query((REQL_NOREPLY_WAIT)))([](const result_t &) {});
  }

  void stop(const std::uint64_t token) {
    p_protocol.stop(token);
  }

private:
  enum Response_e {
    CLIENT_ERROR = 16,
    COMPILE_ERROR = 17,
    RUNTIME_ERROR = 18,
    SERVER_INFO = 5,
    SUCCESS_ATOM = 1,
    SUCCESS_PARTIAL = 3,
    SUCCESS_SEQUENCE = 2,
    WAIT_COMPLETE = 4
  };

  auto create(const std::uint64_t token) {
    Cursor_t<result_t> cursor(token);
    std::lock_guard<std::mutex> lock(p_mutex);
    p_root.insert({token, cursor});
    auto _ = [this, cursor](const std::string &json) {/*
      std::thread([this, token, func, json] {
        Decoder_t<result_t> decoder;
        decoder.decode(json.c_str(), json.c_str() + json.size());
        switch (decoder.r_type()) {
          case SERVER_INFO:
          case SUCCESS_ATOM: {
            func(decoder.get()[0]);
            break;
          }
          case SUCCESS_PARTIAL: p_protocol.cont(token);
          case SUCCESS_SEQUENCE: {
            for (auto &&elem : decoder.get()) {
              func(elem);
            }
            break;
          }
          case WAIT_COMPLETE: {
            func(result_t());
            break;
          }
          case CLIENT_ERROR:
          case COMPILE_ERROR:
          case RUNTIME_ERROR: {
            func(result_t(decoder.get()));
            break;
          }
          default: {
          }
        }
      }).detach();*/
    };
    return cursor;
  }

  std::mutex p_mutex;
  Protocol_t<auth_e, handshake_e, socket_e> p_protocol;
  std::map<std::uint64_t, Cursor_t<result_t> > p_root;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CONNECTION_HPP_
