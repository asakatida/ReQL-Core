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

Expr::Expr() : p_query(ReQL_Datum()) {}

Expr::Expr(ReQL_AST_Function f, std::vector<Query> args, std::map<std::string, Query> kwargs) {
  std::size_t args_size = args.size();

  if (args_size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  std::size_t kwargs_size = args.size();

  if (kwargs_size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  ReQL_Term query(static_cast<std::uint32_t>(args_size), static_cast<std::uint32_t>(kwargs_size));

  for (auto it=args.cbegin(); it!=args.cend(); ++it) {
    p_array.insert(p_array.cend(), *it);
    query.add_arg(it->p_query);
  }

  for (auto it=kwargs.cbegin(); it!=kwargs.cend(); ++it) {
    Expr key(it->first);
    p_object.insert(p_object.cend(), {key, it->second});
    query.add_kwarg(key.p_query, it->second.p_query);
  }

  query.finalize(f);

  p_query = std::move(query);
}

Expr::Expr(std::string val) : p_query(std::move(ReQL_String(val))) {}

Expr::Expr(double val) : p_query(std::move(ReQL_Datum(val))) {}

Expr::Expr(bool val) : p_query(std::move(ReQL_Datum(val))) {}

Expr::Expr(std::vector<Query> val) {
  std::size_t size = val.size();

  if (size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }
  
  ReQL_Array query(static_cast<std::uint32_t>(size));

  for (auto it=val.cbegin(); it!=val.cend(); ++it) {
    p_array.insert(p_array.cend(), *it);
    query.add_elem(it->p_query);
  }

  p_query = std::move(query);
}

Expr::Expr(std::map<std::string, Query> val) {
  std::size_t size = val.size();

  if (size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }
  
  ReQL_Object query(static_cast<std::uint32_t>(size));

  for (auto it=val.cbegin(); it!=val.cend(); ++it) {
    Expr key(it->first);
    p_object.insert(p_object.cend(), {key, it->second});
    query.add_key(key.p_query, it->second.p_query);
  }

  p_query = std::move(query);
}

bool Expr::operator<(const Expr &other) const {
  return p_query < other.p_query;
}

Expr::Expr(const Expr &other) {
}

Expr::Expr(const Expr &&other) {
}

Expr &Expr::operator=(const Expr &other) {
  return *this;
}

Expr &Expr::operator=(Expr &&other) {
  return *this;
}
  
}
