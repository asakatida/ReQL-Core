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

#include "./cpp/expr.hpp"

#include "./cpp/error.hpp"
#include "./cpp/query.hpp"

#include <map>
#include <string>
#include <vector>

namespace ReQL {

Expr::Expr() {}

Expr::Expr(const ReQL_AST_Function_Kwargs &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) : p_query(f, args, kwargs) {}

Expr::Expr(const ReQL_AST_Function &f, const std::vector<Query> &args) : p_query(f, args) {}

Expr::Expr(const std::string &val) : p_query(val) {}

Expr::Expr(const double &val) : p_query(val) {}

Expr::Expr(const bool &val) : p_query(val) {}

Expr::Expr(const std::vector<Query> &val) : p_query(val) {}

Expr::Expr(const std::map<std::string, Query> &val) : p_query(val) {}

Expr::Expr(const Expr &other) : p_query(other.p_query) {}

Expr::Expr(Expr &&other) : p_query(std::move(other.p_query)) {}

ReQL_Obj_t *
Expr::_data() const {
  return _internal().get();
}

ReQL_Datum_t
Expr::_type() const {
  return _internal()._type();
}

const ReQL &
Expr::_internal() const {
  return p_query;
}

}  // namespace ReQL
