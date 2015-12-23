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

#ifndef REQL_CPP_QUERY_HPP_
#define REQL_CPP_QUERY_HPP_

#include "./reql/connection.hpp"
#include "./reql/cursor.hpp"

#include "./reql/core/array.hpp"
#include "./reql/core/null.hpp"
#include "./reql/core/object.hpp"
#include "./reql/core/query.hpp"
#include "./reql/core/string.hpp"
#include "./reql/core/term.hpp"

#include <map>
#include <string>
#include <vector>

namespace ReQL {

template <class elem_t>
std::vector<elem_t>
prepend(const elem_t &first, const std::vector<elem_t> &array) {
  std::vector<elem_t> new_array(array.size() + 1);
  new_array.push_back(first);
  new_array.insert(new_array.end(), array.cbegin(), array.cend());
  return new_array;
}

struct Query {
  Query() : p_build([](auto &) {
    return _ReQL::expr(_ReQL::Null_t());
  }) {}

  Query(const _ReQL::Term_t tt, const std::vector<Query> &args) :
    p_array(args),
    p_build([](auto &query) {
      std::vector<std::string> array;
      array.reserve(query.p_array.size());

      for (auto &&elem : query.p_array) {
        array.push_back(elem.build());
      }

      return _ReQL::expr(make_reql(query.p_tt, array));
    }),
    p_tt(tt) {}

  Query(const _ReQL::Term_t tt, const Query *other, const std::vector<Query> &args) :
    Query(tt, prepend(*other, args)) {}

  Query(const _ReQL::Term_t tt, const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) :
    p_array(args),
    p_build([](auto &query) {
      std::vector<std::string> array;
      array.reserve(query.p_array.size());

      for (auto &&elem : query.p_array) {
        array.push_back(elem.build());
      }

      std::map<std::wstring, std::string> object;

      for (auto &&pair : query.p_object) {
        object.insert({pair.first, pair.second.build()});
      }

      return _ReQL::expr(make_reql(query.p_tt, array, object));
    }),
    p_object(kwargs),
    p_tt(tt) {}

  Query(const _ReQL::Term_t tt, const Query *other, const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) :
    Query(tt, prepend(*other, args), kwargs) {}

  Query(const std::wstring &val) :
    p_build([](auto &query) {
      return _ReQL::expr(_ReQL::make_string(query.p_string));
    }),
    p_string(val) {}

  Query(const double val) :
    p_build([](auto &query) {
      return _ReQL::expr(query.p_number);
    }),
    p_number(val) {}

  Query(const bool val) :
    p_bool(val),
    p_build([](auto &query) {
      return _ReQL::expr(query.p_bool);
    }) {}

  Query(const std::vector<Query> &val) :
    p_array(val),
    p_build([](auto &query) {
      std::vector<std::string> array;
      array.reserve(query.p_array.size());

      for (auto &&elem : query.p_array) {
        array.push_back(elem.build());
      }

      return _ReQL::expr(_ReQL::make_array(array));
    }) {}

  Query(const std::map<std::wstring, Query> &val) :
    p_build([](auto &query) {
      std::map<std::wstring, std::string> object;

      for (auto &&pair : query.p_object) {
        object.insert({pair.first, pair.second.build()});
      }

      return _ReQL::expr(_ReQL::make_object(object));
    }),
    p_object(val) {}

  Query(const Query &other) :
    p_array(other.p_array),
    p_bool(other.p_bool),
    p_build(other.p_build),
    p_number(other.p_number),
    p_object(other.p_object),
    p_string(other.p_string),
    p_tt(other.p_tt) {}

  Query(Query &&other) :
    p_array(std::move(other.p_array)),
    p_bool(std::move(other.p_bool)),
    p_build(std::move(other.p_build)),
    p_number(std::move(other.p_number)),
    p_object(std::move(other.p_object)),
    p_string(std::move(other.p_string)),
    p_tt(std::move(other.p_tt)) {}

  Query &operator=(const Query &other) {
    if (this != &other) {
      p_array = other.p_array;
      p_bool = other.p_bool;
      p_build = other.p_build;
      p_number = other.p_number;
      p_object = other.p_object;
      p_string = other.p_string;
      p_tt = other.p_tt;
    }
    return *this;
  }

  Query &operator=(Query &&other) {
    if (this != &other) {
      p_array = std::move(other.p_array);
      p_bool = std::move(other.p_bool);
      p_build = std::move(other.p_build);
      p_number = std::move(other.p_number);
      p_object = std::move(other.p_object);
      p_string = std::move(other.p_string);
      p_tt = std::move(other.p_tt);
    }
    return *this;
  }

  void no_reply(Connection<Result> &conn) const {
    auto query = build();
    std::map<std::wstring, Query> kwargs;
    auto opts = to_object(kwargs);
    conn.p_conn->noReply(query, opts);
  }

  void no_reply(Connection<Result> &conn, const std::map<std::wstring, Query> &kwargs) const {
    conn.p_conn->noReply(build(), to_object(kwargs));
  }

  static auto
  to_object(const std::map<std::wstring, Query> &kwargs) {
    std::map<std::wstring, std::string> _kwargs;
    std::accumulate(
          kwargs.cbegin(),
          kwargs.cend(),
          _kwargs,
          [](auto val, auto pair) {
      val.insert({pair.first, pair.second.build()}); return val;
    });
    return _kwargs;
  }

  Cursor<Result> run(Connection<Result> &conn) const {
    return conn.p_conn->run(build());
  }

  Cursor<Result> run(Connection<Result> &conn, const std::map<std::wstring, Query> &kwargs) const {
    return conn.p_conn->run(build(), to_object(kwargs));
  }

  std::string build() const {
    return p_build(*this);
  }

  typedef std::string (*QueryBuilder)(const Query &query);

  std::vector<Query> p_array;
  bool p_bool;
  QueryBuilder p_build;
  double p_number;
  std::map<std::wstring, Query> p_object;
  std::wstring p_string;
  _ReQL::Term_t p_tt;

  /**
   */
  friend Query add(const std::vector<Query> &args) {
    return Query(_ReQL::REQL_ADD, args);
  }
  Query add(const std::vector<Query> &args) const {
    return Query(_ReQL::REQL_ADD, this, args);
  }

  /**
   */
  friend Query zip(const std::vector<Query> &args) {
    return Query(_ReQL::REQL_ZIP, args);
  }
  Query zip(const std::vector<Query> &args) const {
    return Query(_ReQL::REQL_ZIP, this, args);
  }
};

}  // namespace ReQL

#endif  // REQL_CPP_QUERY_HPP_
