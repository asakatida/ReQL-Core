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

#include <map>
#include <vector>

#ifndef REQL_EXPR_HPP
#define REQL_EXPR_HPP

namespace ReQL {

class Query;

class Expr {
protected:
  Expr();
  Expr(ReQL_AST_Function f, std::vector<Query> args, std::map<std::string, Query> kwargs);
  explicit Expr(ReQL_Obj_t *val);
  explicit Expr(std::string);
  explicit Expr(double);
  explicit Expr(bool);
  explicit Expr(std::vector<Query>);
  explicit Expr(std::map<std::string, Query>);

  Expr(const Expr &other);
  Expr(const Expr &&other);

  ReQL p_query;
  std::vector<Query> p_array;
  std::map<Query, Query> p_object;
};

}
#endif
