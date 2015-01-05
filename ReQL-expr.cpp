/*
Copyright 2014 Adam Grandquist

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

#include "ReQL-expr.hpp"

#include "ReQL.hpp"

namespace ReQL {

Expr::Expr() {
  _ReQL_Op _val = new _ReQL_Op_t();

  _reql_null_init(_val);

  query = new _ReQL_Op_t();

  _reql_ast_datum(query, _val, NULL);
}

Expr::Expr(std::string val) {
  _ReQL_Op _val = new _ReQL_Op_t();

  uint8_t *_str = new uint8_t[val.size()]();

  val.copy((char *)_str, val.size());

  _reql_string_init(_val, _str, static_cast<uint32_t>(val.size()));

  query = new _ReQL_Op_t();

  _reql_ast_datum(query, _val, NULL);
}

Expr::Expr(double val) {
  _ReQL_Op _val = new _ReQL_Op_t();

  _reql_number_init(_val, val);

  query = new _ReQL_Op_t();

  _reql_ast_datum(query, _val, NULL);
}

Expr::Expr(bool val) {
  _ReQL_Op _val = new _ReQL_Op_t();

  _reql_bool_init(_val, val);

  query = new _ReQL_Op_t();

  _reql_ast_datum(query, _val, NULL);
}

Expr::Expr(std::vector<Query> val) {
  _ReQL_Op _val = new _ReQL_Op_t();
  _ReQL_Op *arr = new _ReQL_Op[val.size()];

  _reql_array_init(_val, arr, static_cast<std::uint32_t>(val.size()));

  for (auto iter=val.cbegin(); iter!=val.cend(); ++iter) {
    _reql_array_append(_val, iter->query);
  }

  query = new _ReQL_Op_t();

  _reql_ast_make_array(query, _val, NULL);
}

Expr::Expr(std::map<std::string, Query> val) {
  _ReQL_Op _val = new _ReQL_Op_t();
  _ReQL_Pair pair = new _ReQL_Pair_t[val.size()];

  _reql_object_init(_val, pair, static_cast<std::uint32_t>(val.size()));

  for (auto iter=val.cbegin(); iter!=val.cend(); ++iter) {
    Query key(iter->first);
    _reql_object_add(_val, key.query, iter->second.query);
  }

  query = new _ReQL_Op_t();

  _reql_ast_make_obj(query, NULL, _val);
}

Expr::~Expr() {
  delete query;
}

Query expr() {
  return Query();
}

Query expr(std::string val) {
  return Query(val);
}

Query expr(double val) {
  return Query(val);
}

Query expr(bool val) {
  return Query(val);
}

Query expr(std::vector<Query> val) {
  return Query(val);
}

Query expr(std::map<std::string, Query> val) {
  return Query(val);
}

}