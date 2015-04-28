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

#ifndef REQL_CPP_QUERY_HPP_
#define REQL_CPP_QUERY_HPP_

#include <map>
#include <string>
#include <vector>

#include "./cpp/ast.hpp"
#include "./cpp/connection.hpp"
#include "./cpp/cursor.hpp"

namespace ReQL {

class Query : public AST {
public:
  Query();
  Query(const ReQL_AST_Function &f, const std::vector<Query> &args);
  Query(const ReQL_AST_Function_Kwargs &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
  explicit Query(const std::string &val);
  explicit Query(const double &val);
  explicit Query(const bool &val);
  explicit Query(const std::vector<Query> &val);
  explicit Query(const std::map<std::string, Query> &val);

  Query(const Query &other);
  Query(const AST &other);
  Query(Query &&other);

  bool operator<(const Query &other) const;

  Query &operator=(const Query &other);
  Query &operator=(Query &&other);

  Cursor run(const Connection &conn) const;
};

}  // namespace ReQL

#endif  // REQL_CPP_QUERY_HPP_
