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

#include <limits>

namespace ReQL {

Expr::Expr() : p_query(ReQL_Datum()) {}

Expr::Expr(const ReQL_AST_Function &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) : p_func(f) {
  std::size_t args_size = args.size();

  if (args_size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  std::size_t kwargs_size = kwargs.size();

  if (kwargs_size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  ReQL_Term query(static_cast<std::uint32_t>(args_size), static_cast<std::uint32_t>(kwargs_size));

  for (auto it=args.cbegin(); it!=args.cend(); ++it) {
    p_array.insert(p_array.end(), *it);
    query.add_arg(it->p_query);
  }

  for (auto it=kwargs.cbegin(); it!=kwargs.cend(); ++it) {
    Expr key(it->first);
    p_object.insert(p_object.end(), {key, it->second});
    query.add_kwarg(key.p_query, it->second.p_query);
  }

  query.finalize(p_func);

  p_query = std::move(query);
}

Expr::Expr(const std::string &val) : p_query(std::move(ReQL_String(val))) {}

Expr::Expr(const double &val) : p_query(std::move(ReQL_Datum(val))) {}

Expr::Expr(const bool &val) : p_query(std::move(ReQL_Datum(val))) {}

Expr::Expr(const std::vector<Query> &val) {
  std::size_t size = val.size();

  if (size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  ReQL_Array query(static_cast<std::uint32_t>(size));

  for (auto it=val.cbegin(); it!=val.cend(); ++it) {
    p_array.insert(p_array.end(), *it);
    query.add_elem(it->p_query);
  }

  p_query = std::move(query);
}

Expr::Expr(const std::map<std::string, Query> &val) {
  std::size_t size = val.size();

  if (size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  ReQL_Object query(static_cast<std::uint32_t>(size));

  for (auto it=val.cbegin(); it!=val.cend(); ++it) {
    Expr key(it->first);
    p_object.insert(p_object.end(), {key, it->second});
    query.add_key(key.p_query, it->second.p_query);
  }

  p_query = std::move(query);
}

bool Expr::operator<(const Expr &other) const {
  return p_query < other.p_query;
}

Expr::Expr(const Expr &other) : p_func(other.p_func), p_array(other.p_array), p_object(other.p_object) {
  copy(other);
}

Expr::Expr(Expr &&other) {
  p_array = std::move(other.p_array);
  p_func = std::move(other.p_func);
  p_object = std::move(other.p_object);
  p_query = std::move(other.p_query);
}

Expr &Expr::operator=(const Expr &other) {
  if (this != &other) {
    p_array = other.p_array;
    p_func = other.p_func;
    p_object = other.p_object;

    copy(other);
  }

  return *this;
}

void
Expr::copy(const Expr &other) {
  switch (other.p_query.type()) {
    case REQL_R_ARRAY: {
      ReQL_Array query(static_cast<std::uint32_t>(p_array.size()));

      for (auto it=p_array.cbegin(); it!=p_array.cend(); ++it) {
        query.add_elem(it->p_query);
      }

      p_query = std::move(query);
      break;
    }
    case REQL_R_BOOL: {
      p_query = std::move(ReQL_Datum(reql_to_bool(other.p_query.data()) ? true : false));
      break;
    }
    case REQL_R_NULL: {
      p_query = std::move(ReQL_Datum());
      break;
    }
    case REQL_R_NUM: {
      p_query = std::move(ReQL_Datum(reql_to_number(other.p_query.data())));
      break;
    }
    case REQL_R_OBJECT: {
      ReQL_Object query(static_cast<std::uint32_t>(p_object.size()));

      for (auto it=p_object.cbegin(); it!=p_object.cend(); ++it) {
        query.add_key(it->first.p_query, it->second.p_query);
      }

      p_query = std::move(query);
      break;
    }
    case REQL_R_STR: {
      std::string str((char*)reql_string_buf(other.p_query.data()), static_cast<std::size_t>(reql_size(other.p_query.data())));
      p_query = std::move(ReQL_String(str));
      break;
    }
    case REQL_R_JSON: throw;
    case REQL_R_REQL: {
      ReQL_Term query(static_cast<std::uint32_t>(p_array.size()), static_cast<std::uint32_t>(p_object.size()));

      for (auto it=p_array.cbegin(); it!=p_array.cend(); ++it) {
        query.add_arg(it->p_query);
      }

      for (auto it=p_object.cbegin(); it!=p_object.cend(); ++it) {
        query.add_kwarg(it->first.p_query, it->second.p_query);
      }

      query.finalize(p_func);

      p_query = std::move(query);
      break;
    }
  }
}

Expr &Expr::operator=(Expr &&other) {
  if (this != &other) {
    p_array = std::move(other.p_array);
    p_func = std::move(other.p_func);
    p_object = std::move(other.p_object);
    p_query = std::move(other.p_query);
  }

  return *this;
}

}
