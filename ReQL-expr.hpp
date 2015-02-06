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

#ifndef _REQL_EXPR_CPP
#define _REQL_EXPR_CPP

namespace ReQL {

class Query;

class Expr {
protected:
  Expr();
  Expr(_ReQL_AST_Function f, std::vector<Query> args, std::map<std::string, Query> kwargs);
  explicit Expr(_ReQL_Obj_t *val);
  explicit Expr(std::string);
  explicit Expr(double);
  explicit Expr(bool);
  explicit Expr(std::vector<Query>);
  explicit Expr(std::map<std::string, Query>);

  Expr(const Expr &other);
  Expr(const Expr &&other);

  ~Expr();

  _ReQL_Obj_t *query;
  std::vector<Query> sub_query;
};

Query
expr();
Query
expr(_ReQL_Obj_t *);
Query
expr(std::string);
Query
expr(double);
Query
expr(bool);
Query
expr(std::vector<Query>);
Query
expr(std::map<std::string, Query>);

}
#endif
