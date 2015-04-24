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

#ifndef REQL_NEW_HPP_
#define REQL_NEW_HPP_

#include <map>
#include <string>
#include <vector>

namespace ReQL {
extern "C" {

#include "./ReQL.h"
#include "./c/dev/ast.h"

}

class ReQL {
public:
  ReQL();
  explicit ReQL(const double &val);
  explicit ReQL(const bool &val);
  explicit ReQL(const std::string &val);
  explicit ReQL(const std::vector<ReQL> &array);
  explicit ReQL(const std::map<ReQL, ReQL> &object);
  ReQL(const ReQL_AST_Function &f, const std::vector<ReQL> &args, const std::map<ReQL, ReQL> &kwargs);
  explicit ReQL(const ReQL &other);

  ReQL &operator=(const ReQL &other);
  ReQL &operator=(ReQL &&other);

  ReQL_Obj_t *data() const;

  bool operator<(const ReQL &other) const;

private:
  ReQL_Datum_t type() const;
  void copy(const ReQL &other);

  ReQL_AST_Function p_func;
  std::vector<ReQL> p_r_array;
  std::map<ReQL, ReQL> p_r_object;
  std::string p_str;
  std::unique_ptr<ReQL_Obj_t> p_args;
  std::unique_ptr<ReQL_Obj_t*> p_array;
  std::unique_ptr<uint8_t> p_buf;
  std::unique_ptr<ReQL_Obj_t> p_kwargs;
  std::unique_ptr<ReQL_Pair_t> p_object;
  std::unique_ptr<ReQL_Obj_t> p_query;
};

}  // namespace ReQL

#endif  // REQL_NEW_HPP_
