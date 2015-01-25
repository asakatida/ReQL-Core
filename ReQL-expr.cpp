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

Expr::Expr() {
  Query _val = expr(_reql_new_null());
  sub_query.push_back(_val);
  query = _reql_new_datum(_val.query);
}

Expr::Expr(_ReQL_Obj_t *val) {
  query = val;
}

Expr::Expr(std::string val) {
  Query _val = expr(_reql_new_string(val));
  sub_query.push_back(_val);
  query = _reql_new_datum(_val.query);
}

Expr::Expr(double val) {
  Query _val = expr(_reql_new_number(val));
  sub_query.push_back(_val);
  query = _reql_new_datum(_val.query);
}

Expr::Expr(bool val) {
  Query _val = expr(_reql_new_bool(val));
  sub_query.push_back(_val);
  query = _reql_new_datum(_val.query);
}

Expr::Expr(std::vector<Query> val) {
  if (val.size() > std::numeric_limits<std::uint32_t>::max()) {
    throw;
  }

  sub_query.assign(val.begin(), val.end());

  Query _val = expr(_reql_new_array(static_cast<std::uint32_t>(val.size())));

  sub_query.push_back(_val);

  for (auto iter=val.cbegin(); iter!=val.cend(); ++iter) {
    _reql_array_append(_val.query, iter->query);
  }

  query = _reql_new_make_array(_val.query);
}

Expr::Expr(std::map<std::string, Query> val) {
  if (val.size() > std::numeric_limits<std::uint32_t>::max()) {
    throw;
  }

  Query _val = expr(_reql_new_object(static_cast<std::uint32_t>(val.size())));

  sub_query.push_back(_val);

  for (auto iter=val.cbegin(); iter!=val.cend(); ++iter) {
    Query key(iter->first);
    sub_query.push_back(key);
    sub_query.push_back(iter->second);
    _reql_object_add(_val.query, key.query, iter->second.query);
  }

  query = _reql_new_make_obj(_val.query);
}

Expr::~Expr() {
  switch (_reql_datum_type(query)) {
    case _REQL_R_ARRAY: {
      delete [] query->obj.datum.json.array;
      break;
    }
    case _REQL_R_OBJECT: {
      delete [] query->obj.datum.json.pair;
      break;
    }
    default:
      break;
  }
  delete query;
}

Query
expr() {
  return Query();
}

Query
expr(_ReQL_Obj_t *val) {
  return Query(val);
}

Query
expr(std::string val) {
  return Query(val);
}

Query
expr(double val) {
  return Query(val);
}

Query
expr(bool val) {
  return Query(val);
}

Query
expr(std::vector<Query> val) {
  return Query(val);
}

Query
expr(std::map<std::string, Query> val) {
  return Query(val);
}

}
