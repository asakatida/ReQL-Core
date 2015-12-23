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

#ifndef REQL_REQL_QUERY_HPP_
#define REQL_REQL_QUERY_HPP_

#include "./reql/object.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

namespace _ReQL {

template <class wrap_t>
std::string
expr(const wrap_t &value) {
  std::ostringstream stream;
  stream << std::boolalpha
         << std::setprecision(std::numeric_limits<double>::digits10 + 1)
         << value;
  return stream.str();
}

enum Query_t {
  REQL_CONTINUE = 2,
  REQL_NOREPLY_WAIT = 4,
  REQL_START = 1,
  REQL_STOP = 3
};

template <class map_t, class query_t>
auto
make_query(const query_t &query, const map_t &kwargs) {
  return make_array(REQL_START, query, make_object(kwargs));
}

template <class query_t>
auto
make_query(const query_t &query) {
  return make_array(REQL_START, query, "{}");
}

}  // namespace _ReQL

#endif  // REQL_REQL_QUERY_HPP_
