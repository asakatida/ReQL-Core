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

#ifndef REQL_REQL_BTREE_HPP_
#define REQL_REQL_BTREE_HPP_

#include "./reql/decode.hpp"
#include "./reql/parser.hpp"
#include "./reql/protocol.hpp"
#include "./reql/query.hpp"
#include "./reql/response.hpp"
#include "./reql/types.hpp"

#include <atomic>
#include <functional>
#include <memory>
#include <mutex>

namespace _ReQL {

template <class result_t, class str_t>
class BTree_t {
public:
  BTree_t() {}

  BTree_t(const str_t &addr, const str_t &port, const str_t &auth) :
    p_protocol(addr, port, auth, [this](Response_t<str_t, Protocol_t<str_t> > &&response) {
      p_root->push(std::move(response));
    }) {}

  bool isOpen() const {
    return p_protocol.isOpen();
  }

  template <class query_t>
  void run(const query_t &query, std::function<void(result_t &&result)> func) {
    Query_t<str_t> q(p_next_token++, query);
    p_protocol << q;
    create(q.token(), func);
  }

  template <class kwargs_t, class query_t>
  void run(const query_t &query, const kwargs_t &kwargs, std::function<void(result_t &&result)> func) {
    Query_t<str_t> q(p_next_token++, query, kwargs);
    p_protocol << q;
    create(q.token(), func);
  }

  template <class kwargs_t, class query_t>
  void noReply(const query_t &query, const kwargs_t &kwargs) {
    Query_t<str_t> q(p_next_token++, query, kwargs);
    p_protocol << q;
  }

  void noReplyWait() {
    Query_t<str_t> query(p_next_token++, REQL_NOREPLY_WAIT);
    p_protocol << query;
    create(query.token());
  }

  void stop(ReQL_Token token) {
    p_protocol.stop(token);
    p_root.close(token);
  }

private:
  class BNode_t {
  public:
    enum Response_e {
      REQL_CLIENT_ERROR = 16,
      REQL_COMPILE_ERROR = 17,
      REQL_RUNTIME_ERROR = 18,
      REQL_SUCCESS_ATOM = 1,
      REQL_SUCCESS_PARTIAL = 3,
      REQL_SUCCESS_SEQUENCE = 2,
      REQL_WAIT_COMPLETE = 4
    };

    BNode_t(const ReQL_Token &key, std::function<void(result_t &&result)> &func) : p_cur([func](Response_t<str_t, Protocol_t<str_t> > &&response) {
      Parser_t<result_t> parser;
      decode(response.json(), parser);
      switch (parser.r_type()) {
        case REQL_SUCCESS_ATOM:
        case REQL_SUCCESS_SEQUENCE:
        case REQL_WAIT_COMPLETE: {
          break;
        }
        case REQL_SUCCESS_PARTIAL: {
          response.next();
          break;
        }
        case REQL_CLIENT_ERROR:
        case REQL_COMPILE_ERROR:
        case REQL_RUNTIME_ERROR:
        default: {
        }
      }
      func(std::move(parser.get()));
    }), p_key(key) {}

    void create(const ReQL_Token &key, std::function<void(result_t &&result)> &func) {
      if (key == p_key) {
        return;
      }
      if (key < p_key) {
        if (p_left.get()) {
          return p_left->create(key, func);
        }
        p_left.reset(new BNode_t(key, func));
        return;
      }
      if (p_right.get()) {
        return p_right->create(key, func);
      }
      p_right.reset(new BNode_t(key, func));
    }

    void push(Response_t<str_t, Protocol_t<str_t> > &&response) {
      if (response == p_key) {
        p_cur(std::move(response));
        return;
      }
      if (response < p_key) {
        return p_left->push(std::move(response));
      }
      return p_right->push(std::move(response));
    }

    void close(const ReQL_Token &key) {
      if (key == p_key) {
        return p_cur.close();
      }
      if (key < p_key) {
        return p_left->close(key);
      }
      return p_right->close(key);
    }

  private:
    std::function<void(Response_t<str_t, Protocol_t<str_t> > &&)> p_cur;
    ReQL_Token p_key;
    std::unique_ptr<BNode_t> p_left;
    std::unique_ptr<BNode_t> p_right;
  };
  
  void create(const ReQL_Token &key, std::function<void(result_t &&result)> func) {
    std::lock_guard<std::mutex> lock(p_mutex);
    if (!p_root.get()) {
      p_root.reset(new BNode_t(key, func));
    } else {
      p_root->create(key, func);
    }
  }

  std::mutex p_mutex;
  std::atomic<ReQL_Token> p_next_token;
  Protocol_t<str_t> p_protocol;
  std::unique_ptr<BNode_t> p_root;
  std::thread p_thread;
};

}  // namespace _ReQL

#endif  // REQL_REQL_BTREE_HPP_
