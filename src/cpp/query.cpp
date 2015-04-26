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

#include "./cpp/query.hpp"

#include <map>
#include <string>
#include <vector>

namespace ReQL {

Query::Query() : AST() {}

Query::Query(const ReQL_AST_Function &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) : AST(f, args, kwargs) {}

Query::Query(const std::string &val) : AST(val) {}

Query::Query(const double &val) : AST(val) {}

Query::Query(const bool &val) : AST(val) {}

Query::Query(const std::vector<Query> &val) : AST(val) {}

Query::Query(const std::map<std::string, Query> &val) : AST(val) {}

Query::Query(const Query &other) : AST(other) {}

Query::Query(const AST &other) : AST(other) {}

Query::Query(Query &&other) : AST(std::move(other)) {}

Cursor Query::run(const Connection &conn) const {
  if (!conn.isOpen()) {
    throw;
  }

  Cursor cur;

  reql_run(cur.data(), data(), conn.data(), nullptr);

  return cur;
}

Query &Query::operator=(const Query &other) {
  if (this != &other) {
    copy(other);
  }
  return *this;
}

Query &Query::operator=(Query &&other) {
  if (this != &other) {
    move(std::move(other));
  }
  return *this;
}

bool Query::operator<(const Query &other) const {
  return Expr::operator<(other);
}

}  // namespace ReQL
