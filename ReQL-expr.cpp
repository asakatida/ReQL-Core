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

Expr::Expr(ReQL_AST_Function f, std::vector<Query> args, std::map<std::string, Query> kwargs) : p_array(args) {
  std::vector<ReQL> array;

  for (std::vector<Query>::const_iterator it=args.cbegin(); it!=args.cend(); ++it) {
    array.insert(array.end(), it->p_query);
  }
  
  std::map<ReQL, ReQL> object;

  for (std::map<std::string, Query>::const_iterator it=kwargs.cbegin(); it!=kwargs.cend(); ++it) {
    Query key(it->first);
    p_object.insert(p_object.end(), {key, it->second});
    object.insert(object.end(), {key.p_query, it->second.p_query});
  }
  
  p_query = std::move(ReQL(f, array, object));
}

Expr::Expr(std::string val) : p_query(val) {}

Expr::Expr(double val) : p_query(val) {}

Expr::Expr(bool val) : p_query(val) {}

Expr::Expr(std::vector<Query> val) : p_array(val) {
  std::vector<ReQL> array;

  for (std::vector<Query>::const_iterator it=val.cbegin(); it!=val.cend(); ++it) {
    array.insert(array.end(), it->p_query);
  }

  p_query = std::move(ReQL(array));
}

Expr::Expr(std::map<std::string, Query> val) {
  std::map<ReQL, ReQL> object;

  for (std::map<std::string, Query>::const_iterator it=val.cbegin(); it!=val.cend(); ++it) {
    Query key(it->first);
    p_object.insert(p_object.end(), {key, it->second});
    object.insert(object.end(), {key.p_query, it->second.p_query});
  }

  p_query = std::move(ReQL(object));
}

Expr::Expr(const Expr &other) {
  p_query = other.p_query;
}

Expr::Expr(const Expr &&other) {
  p_query = std::move(other.p_query);
}

}
