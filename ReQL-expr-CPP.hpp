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

#include <map>
#include <string>
#include <vector>

#ifndef _REQL_EXPR_CPP
#define _REQL_EXPR_CPP

namespace ReQL {

class Expr {
public:
  struct _ReQL_Op_s *query;

  Expr();
  explicit Expr(std::string);
  explicit Expr(double);
  explicit Expr(bool);
  explicit Expr(std::vector<Expr>);
  explicit Expr(std::map<std::string, Expr>);
};

Expr expr();
Expr expr(std::string);
Expr expr(double);
Expr expr(bool);
Expr expr(std::vector<Expr>);
Expr expr(std::map<std::string, Expr>);

}
#endif
