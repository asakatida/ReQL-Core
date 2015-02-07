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

#include "ReQL-expr.hpp"

#include "ReQL.hpp"

namespace ReQL {

Expr::Expr() {}

Expr::Expr(_ReQL_AST_Function f, std::vector<Query> args, std::map<std::string, Query> kwargs) {
  query = ReQL();
}

Expr::Expr(std::string val) : query(val) {}

Expr::Expr(double val) : query(val) {}

Expr::Expr(bool val) : query(val) {}

Expr::Expr(std::vector<Query> val) {
  std::vector<ReQL> array;

  for (std::vector<Query>::const_iterator it=val.cbegin(); it!=val.cend(); ++it) {
    array.insert(array.end(), it->query);
  }
}

Expr::Expr(std::map<std::string, Query> val) {
  std::map<std::string, ReQL> object;

  for (std::map<std::string, Query>::const_iterator it=val.cbegin(); it!=val.cend(); ++it) {
    object.insert(object.end(), {it->first, it->second.query});
  }
}

Expr::Expr(const Expr &other) {
  query = other.query;
}

Expr::Expr(const Expr &&other) {
  query = std::move(other.query);
}

}
