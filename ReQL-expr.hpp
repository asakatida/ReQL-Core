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

#include "ReQL-new.hpp"

#ifndef REQL_EXPR_HPP
#define REQL_EXPR_HPP

namespace ReQL {

class Query;

class Expr {
public:
  bool operator<(const Expr &other) const;

  explicit Expr(const Expr &other);
  explicit Expr(Expr &&other);

  Expr &operator=(const Expr &other);
  Expr &operator=(Expr &&other);

protected:
  explicit Expr();
  explicit Expr(const ReQL_AST_Function &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
  explicit Expr(const std::string &val);
  explicit Expr(const double &val);
  explicit Expr(const bool &val);
  explicit Expr(const std::vector<Query> &val);
  explicit Expr(const std::map<std::string, Query> &val);

  ReQL p_query;
private:
  void copy(const Expr &other);

  ReQL_AST_Function p_func;
  std::vector<Expr> p_array;
  std::map<Expr, Expr> p_object;
};

}
#endif
