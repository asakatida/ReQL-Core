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

#include "ReQL-expr-CPP.hpp"

#include "ReQL-CPP.hpp"
#include "ReQL.hpp"

using namespace ReQL;

Expr::Expr() {
  query = (struct _ReQL_Op_s *)_reql_expr_null();
}

Expr::Expr(std::string val) {
  query = (struct _ReQL_Op_s *)_reql_expr_string((char *)val.c_str(), val.size());
}

Expr::Expr(double val) {
  query = (struct _ReQL_Op_s *)_reql_expr_number(val);
}

Expr::Expr(bool val) {
  query = (struct _ReQL_Op_s *)_reql_expr_bool(val);
}

Expr::Expr(std::vector<Query> val) {
  _ReQL_Op obj = _reql_json_array(NULL);

  for (auto iter=val.cbegin(); iter!=val.cend(); ++iter) {
    _reql_array_append(obj, _reql_expr_copy((_ReQL_Op)iter->query));
  }

  query = (struct _ReQL_Op_s *)_reql_expr(obj);
}

Expr::Expr(std::map<std::string, Query> val) {
  _ReQL_Op obj = _reql_json_object(NULL);

  for (auto iter=val.cbegin(); iter!=val.cend(); ++iter) {
    std::string key_str = iter->first;
    _ReQL_Op key = _reql_json_string(NULL, (char *)key_str.c_str(), key_str.size());
    _reql_object_add(obj, key, _reql_expr_copy((_ReQL_Op)iter->second.query));
  }

  query = (struct _ReQL_Op_s *)_reql_expr(obj);
}

Expr expr() {
  return Expr();
}

Expr ReQL::expr(std::string val) {
  return Expr(val);
}

Expr expr(double val) {
  return Expr(val);
}

Expr expr(bool val) {
  return Expr(val);
}

Expr expr(std::vector<Query> val) {
  return Expr(val);
}

Expr expr(std::map<std::string, Query> val) {
  return Expr(val);
}
