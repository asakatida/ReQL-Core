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

#ifndef REQL_CPP_NEW_HPP_
#define REQL_CPP_NEW_HPP_

#include "./cpp/types.hpp"

#include <map>
#include <memory>
#include <vector>

namespace ReQL {

namespace _Internal {

class ReQL : public _C::CTypes::object {
public:
  ReQL();
  explicit ReQL(const double &val);
  explicit ReQL(const bool &val);
  explicit ReQL(const Types::string &val);
  explicit ReQL(const Types::array &array);
  explicit ReQL(const Types::object &object);
  explicit ReQL(_C::ReQL_Obj_t *object);
  ReQL(const _C::ReQL_AST_Function &f, const Types::array &args);
  ReQL(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs);
  ReQL(const ReQL &other);
  ReQL(ReQL &&other);

  ~ReQL();

  ReQL &operator=(const ReQL &other);
  ReQL &operator=(ReQL &&other);

  bool operator<(const ReQL &other) const;

  _C::ReQL_Datum_t _type() const;

private:
  ReQL(int dummy);

  void removeOwner();

  _C::ReQL_Term_t p_tt;
  std::vector<ReQL> p_r_array;
  std::map<ReQL, ReQL> p_r_object;
  Types::string p_str;
  std::unique_ptr<ReQL> p_args;
  _C::CTypes::array p_array;
  _C::CTypes::string p_buf;
  std::unique_ptr<ReQL> p_kwargs;
  _C::CTypes::pairs p_object;
};

}  // namespace _Internal

}  // namespace ReQL

#endif  // REQL_CPP_NEW_HPP_
