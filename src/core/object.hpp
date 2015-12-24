/*
Copyright 2015 Adam Grandquist

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

#ifndef REQL_REQL_OBJECT_HPP_
#define REQL_REQL_OBJECT_HPP_

#include "./reql/core/string.hpp"

#include <iostream>

namespace _ReQL {

template <class map_t>
struct Obj_t : public map_t {
  Obj_t(const map_t &value) : map_t(value) {}
  Obj_t(map_t &&value) : map_t(std::move(value)) {}
};

template <class map_t>
Obj_t<map_t>
make_object(const map_t &map) {
  return map;
}

template <class map_t>
std::ostream &
operator <<(std::ostream &stream, const Obj_t<map_t> &value) {
  stream << '{';
  auto first = true;
  for (auto &&pair : value) {
    if (!first) stream << ',';
    stream << make_string(pair.first) << ':' << pair.second;
    first = false;
  }
  return stream << '}';
}

}  // namespace _ReQL

#endif  // REQL_REQL_OBJECT_HPP_
