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

#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <thread>

namespace _ReQL {

static const char *DEFAULT_ADDR = "localhost";
static const char *DEFAULT_PORT = "28015";

template <class auth_e, class handshake_e, class result_t, class socket_e>
class Conn_t {
public:
  Conn_t() :
    p_mutex(std::make_shared<std::mutex>()),
    p_protocol(std::make_shared<Protocol_t<auth_e, handshake_e, socket_e> >()),
    p_root(std::make_shared<std::map<std::uint64_t, std::function<void(const std::string &)> > >()) {}

  Conn_t(const Conn_t &other) = default;

  Conn_t(Conn_t &&other) = default;

  ~Conn_t() {}

  Conn_t &operator =(const Conn_t &other) = default;

  Conn_t &operator =(Conn_t &&other) = default;

  void connect() {
    return connect(std::string(DEFAULT_ADDR));
  }

  template <class addr_t>
  void connect(const addr_t &addr) {
    return connect(addr, std::string(DEFAULT_PORT), std::string(""));
  }

  template <class addr_t, class auth_t, class port_t>
  void connect(const addr_t &addr, const port_t &port, const auth_t &auth) {
    p_protocol->connect(addr, port, auth, [this](const std::string &json, const ReQL_Token token) {
      std::lock_guard<std::mutex> lock(*p_mutex);
      (*p_root)[token](json);
    });
  }

  bool isOpen() const {
    return p_protocol->connected();
  }

  void close() {
    p_protocol->disconnect();
  }

  template <class query_t, class func_t>
  void run(const query_t &query, func_t func) {
    create((*p_protocol) << Query_t<std::string>(query), func);
  }

  template <class kwargs_t, class query_t, class func_t>
  void run(const query_t &query, const kwargs_t &kwargs, func_t func) {
    create((*p_protocol) << Query_t<std::string>(query, kwargs), func);
  }

  template <class kwargs_t, class query_t>
  void noReply(const query_t &query, const kwargs_t &kwargs) {
    (*p_protocol) << Query_t<std::string>(query, kwargs);
  }

  void noReplyWait() {
    ReQL_Token token = p_protocol << Query_t<std::string>(REQL_NOREPLY_WAIT);
    create(token, [](const result_t &) {});
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

  template <class func_t>
  void create(const std::uint64_t token, func_t func) {
    std::lock_guard<std::mutex> lock(*p_mutex);
    p_root->insert({token, [this, token, func](const std::string &json) {
      std::thread([this, token, func, json] {
        Decoder_t<result_t> decoder;
        decoder.decode(json.c_str(), json.c_str() + json.size());
        switch (decoder.r_type()) {
          case SERVER_INFO:
          case SUCCESS_ATOM: {
            func(decoder.get()[0]);
            break;
          }
          case SUCCESS_PARTIAL: p_protocol->cont(token); [[clang::fallthrough]];
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
      }).detach();
    }});
  }

  std::shared_ptr<std::mutex> p_mutex;
  std::shared_ptr<Protocol_t<auth_e, handshake_e, socket_e> > p_protocol;
  std::shared_ptr<std::map<std::uint64_t, std::function<void(const std::string &)> > > p_root;
};

}  // namespace _ReQL

#endif  // REQL_REQL_CONNECTION_HPP_
