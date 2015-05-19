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

#include <algorithm>

namespace ReQL {
namespace _Internal {

Expr::Expr() {}

Expr::Expr(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs) : p_query(f, args, kwargs) {}

Expr::Expr(const _C::ReQL_AST_Function &f, const Types::array &args) : p_query(f, args) {}

Expr::Expr(const Types::string &val) : p_query(val) {}

Expr::Expr(const double &val) : p_query(val) {}

Expr::Expr(const bool &val) : p_query(val) {}

Expr::Expr(const Types::array &val) : p_query(val) {}

Expr::Expr(const Types::object &val) : p_query(val) {}

Expr::Expr(const _C::ReQL_Obj_t *val) : p_query(val) {}
  
Expr::Expr(const Expr &other) : p_query(other.p_query) {}

Expr::Expr(Expr &&other) : p_query(std::move(other.p_query)) {}

_C::ReQL_Obj_t *
Expr::_data() const {
  return _internal().get();
}

_C::ReQL_Datum_t
Expr::_type() const {
  return _internal()._type();
}

const ReQL &
Expr::_internal() const {
  return p_query;
}

}  // namespace _Internal
}  // namespace ReQL
