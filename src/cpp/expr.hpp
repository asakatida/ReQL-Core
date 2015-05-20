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

#ifndef REQL_CPP_EXPR_HPP_
#define REQL_CPP_EXPR_HPP_

#include "./cpp/new.hpp"

namespace ReQL {
namespace _Internal {

class Expr {
public:
  Expr(const Expr &other);
  Expr(Expr &&other);

  _C::ReQL_Obj_t *_data() const;
  _C::ReQL_Datum_t _type() const;
  const ReQL &_internal() const;

protected:
  Expr();
  Expr(const _C::ReQL_AST_Function &f, const Types::array &args);
  Expr(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs);
  explicit Expr(const Types::string &val);
  explicit Expr(const double &val);
  explicit Expr(const bool &val);
  explicit Expr(const Types::array &val);
  explicit Expr(const Types::object &val);
  explicit Expr(_C::ReQL_Obj_t *val);

  ReQL p_query;
};

}  // namespace _Internal
}  // namespace ReQL

#endif  // REQL_CPP_EXPR_HPP_
