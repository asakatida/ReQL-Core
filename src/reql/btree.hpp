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

#include "./reql/protocol.hpp"
#include "./reql/pipe.hpp"
#include "./reql/response.hpp"
#include "./reql/types.hpp"

#include <atomic>
#include <memory>
#include <mutex>

namespace _ReQL {

template <class result_t, class str_t>
class BTree_t {
public:
  BTree_t() {}

  class BNode {
  public:
    BNode() {}

    BNode(const ReQL_Token &key) : p_key(key) {}

    BNode(BNode &&other) :
      p_key(std::move(other.p_key)),
      p_left(std::move(other.p_left)),
      p_parent(std::move(other.p_parent)),
      p_right(std::move(other.p_right)),
      p_val(std::move(other.p_val)) {}

    ~BNode() {
      if (p_left) {
        delete p_left;
      }
      if (p_right) {
        delete p_right;
      }
    }

    auto create(const ReQL_Token &key) {
      if (key == p_key) {
        if (p_val.get()) {
          throw std::exception();
        }
        return std::shared_ptr<Cur_t<result_t, str_t>>(new Cur_t<result_t, str_t>(p_val));
      }
      if (key < p_key) {
        if (p_left) {
          return p_left->create(key);
        }
        p_left = new BNode(key);
        return p_left->create(key);
      }
      if (p_right) {
        return p_right->create(key);
      }
      p_right = new BNode(key);
      return p_right->create(key);
    }

    void push(Response_t<str_t> &&response) {
      if (response.p_token == p_key) {
        p_val->push(std::move(response));
        return;
      }
      if (response.p_token < p_key) {
        return p_left->push(std::move(response));
      }
      return p_right->push(std::move(response));
    }

    void close(Protocol_t<str_t> &protocol) {
      if (p_left) {
        p_left->close(protocol);
        delete p_left; p_left = nullptr;
      }
      if (p_right) {
        p_right->close(protocol);
        delete p_right; p_right = nullptr;
      }
      protocol.stop(p_key);
      p_val->close();
    }


    ReQL_Token p_key;
    BNode *p_left;
    BNode *p_parent;
    BNode *p_right;
    std::shared_ptr<Pipe_t<Response_t<str_t>>> p_val;
  };

  BTree_t(const str_t &addr, const str_t &port, const str_t &auth) :
    p_protocol(addr, port, auth),
    p_sink([this](Response_t<str_t> &&response) {
      p_root.push(std::move(response));
    }, Pipe_t<Response_t<str_t>>([this]() {
      Response_t<str_t> response;
      p_protocol >> response;
      return response;
    })) {}

  BTree_t(BTree_t &&other) :
    p_next_token(other.p_next_token.exchange(-1)),
    p_protocol(std::move(other.p_protocol)),
    p_root(std::move(other.p_root)),
    p_sink(std::move(other.p_sink)) {}

  BTree_t &operator =(BTree_t &&other) {
    if (this != &other) {
    }
    return *this;
  }

  auto create(const ReQL_Token &key) {
    std::lock_guard<std::mutex> lock(p_mutex);
    return p_root.create(key);
  }

  bool isOpen() const {
    return p_protocol.isOpen();
  }

  template <class query_t>
  auto run(const query_t &query) {
    Query_t<str_t> q(p_next_token++, query);
    p_protocol << q;
    return create(q.token);
  }

  template <class kwargs_t, class query_t>
  auto run(const query_t &query, const kwargs_t &kwargs) {
    Query_t<str_t> q(p_next_token++, query, kwargs);
    p_protocol << q;
    return create(q.token);
  }

  template <class kwargs_t, class query_t>
  void noReply(const query_t &query, const kwargs_t &kwargs) {
    Query_t<str_t> q(p_next_token++, query, kwargs);
    p_protocol << q;
  }

  void noReplyWait() {
    Query_t<str_t> query(p_next_token++, REQL_NOREPLY_WAIT);
    p_protocol << query;
    create(query.token);
  }

  void stop(ReQL_Token token) {
    Query_t<str_t> query(token, REQL_STOP);
    p_protocol << query;
  }

  BTree_t &push(Response_t<str_t> &&response) {
    p_root[response.p_token].push(std::move(response));
    return *this;
  }

  std::mutex p_mutex;
  std::atomic<ReQL_Token> p_next_token;
  Protocol_t<str_t> p_protocol;
  BNode p_root;
  typename Pipe_t<Response_t<str_t>>::Sink_t p_sink;
};

}  // namespace _ReQL

#endif  // REQL_REQL_BTREE_HPP_
