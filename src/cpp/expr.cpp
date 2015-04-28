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

#include "./cpp/expr.hpp"

#include "./cpp/query.hpp"

#include <map>
#include <string>
#include <vector>

namespace ReQL {

Expr::Expr() {}

Expr::Expr(const ReQL_AST_Function_Kwargs &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) : p_func(nullptr), p_func_kwargs(f) {
  if (args.size() > std::numeric_limits<std::uint32_t>::max()) {
    throw;
  }

  if (kwargs.size() > std::numeric_limits<std::uint32_t>::max()) {
    throw;
  }

  std::vector<ReQL> r_args;

  for (auto it=args.cbegin(); it != args.cend(); ++it) {
    p_array.push_back(*it);
    r_args.push_back(it->p_query);
  }

  std::map<ReQL, ReQL> r_kwargs;

  for (auto it=kwargs.cbegin(); it != kwargs.cend(); ++it) {
    Expr key(it->first);
    p_object.insert(p_object.end(), {key, it->second});
    r_kwargs.insert(r_kwargs.end(), {key.p_query, it->second.p_query});
  }

  p_query = ReQL(f, r_args, r_kwargs);
}

Expr::Expr(const ReQL_AST_Function &f, const std::vector<Query> &args) : p_func(f), p_func_kwargs(nullptr) {
  if (args.size() > std::numeric_limits<std::uint32_t>::max()) {
    throw;
  }

  std::vector<ReQL> r_args;

  for (auto it=args.cbegin(); it != args.cend(); ++it) {
    p_array.push_back(*it);
    r_args.push_back(it->p_query);
  }

  p_query = ReQL(f, r_args);
}

Expr::Expr(const std::string &val) : p_query(val) {}

Expr::Expr(const double &val) : p_query(val) {}

Expr::Expr(const bool &val) : p_query(val) {}

Expr::Expr(const std::vector<Query> &val) {
  if (val.size() > std::numeric_limits<std::uint32_t>::max()) {
    throw;
  }

  std::vector<ReQL> r_array;

  for (auto it=val.cbegin(); it != val.cend(); ++it) {
    p_array.push_back(*it);
    r_array.push_back(it->p_query);
  }

  p_query = ReQL(r_array);
}

Expr::Expr(const std::map<std::string, Query> &val) {
  if (val.size() > std::numeric_limits<std::uint32_t>::max()) {
    throw;
  }

  std::map<ReQL, ReQL> r_object;

  for (auto it=val.cbegin(); it != val.cend(); ++it) {
    Expr key(it->first);
    p_object.insert(p_object.end(), {key, it->second});
    r_object.insert(r_object.end(), {key.p_query, it->second.p_query});
  }

  p_query = ReQL(r_object);
}

bool
Expr::operator<(const Expr &other) const {
  return p_query < other.p_query;
}

Expr::Expr(const Expr &other) : p_func(other.p_func), p_func_kwargs(other.p_func_kwargs), p_array(other.p_array), p_object(other.p_object) {
  copy(other);
}

Expr::Expr(Expr &&other) {
  move(std::move(other));
}

Expr &
Expr::operator=(const Expr &other) {
  if (this != &other) {
    copy(other);
  }

  return *this;
}

void
Expr::copy(const Expr &other) {
  p_array = other.p_array;
  p_func = other.p_func;
  p_func_kwargs = other.p_func_kwargs;
  p_object = other.p_object;
  p_query = other.p_query;
}

void
Expr::move(Expr &&other) {
  p_array = std::move(other.p_array);
  p_func = std::move(other.p_func);
  p_func_kwargs = std::move(other.p_func_kwargs);
  p_object = std::move(other.p_object);
  p_query = std::move(other.p_query);
}

Expr &
Expr::operator=(Expr &&other) {
  if (this != &other) {
    move(std::move(other));
  }

  return *this;
}

ReQL_Obj_t *
Expr::data() const {
  return p_query.data();
}

}  // namespace ReQL
