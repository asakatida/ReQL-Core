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

#ifndef REQL_REQL_ARRAY_HPP_
#define REQL_REQL_ARRAY_HPP_

#include <iostream>
#include <tuple>

namespace _ReQL {

template <class vect_t>
struct Array_t : public vect_t {
  Array_t(const vect_t &other) : vect_t(other) {}
  Array_t(vect_t &&other) : vect_t(std::move(other)) {}
};

template <class vect_t>
Array_t<vect_t>
make_array(const vect_t &vect) {
  return vect;
}

template <class..._ts>
typename std::enable_if<sizeof...(_ts) >= 2, Array_t<std::tuple<_ts...> > >::type
make_array(_ts...Ts) {
  return std::make_tuple(Ts...);
}

template <class vect_t>
std::ostream &
operator <<(std::ostream &stream, const Array_t<vect_t> &value) {
  stream << '[';
  auto first = true;
  for (auto &&elem : value) {
    if (!first) stream << ',';
    stream << elem;
    first = false;
  }
  return stream << ']';
}

template<std::size_t s, class..._ts>
typename std::enable_if<s == 0, std::ostream &>::type
unpack(std::ostream &stream, const std::tuple<_ts...> &) {
  return stream;
}

template<std::size_t s, class..._ts>
typename std::enable_if<s == 1, std::ostream &>::type
unpack(std::ostream &stream, const std::tuple<_ts...> &iterable) {
  return stream << std::get<0>(iterable);
}

template<std::size_t s, class..._ts>
typename std::enable_if<s >= 2, std::ostream &>::type
unpack(std::ostream &stream, const std::tuple<_ts...> &iterable) {
  return unpack<s-1, _ts...>(stream, iterable) << ',' << std::get<s-1>(iterable);
}

template <class..._ts>
std::ostream &
operator <<(std::ostream &stream, const Array_t<std::tuple<_ts...>> &value) {
  return unpack<sizeof...(_ts), _ts...>(stream << '[', value) << ']';
}

}  // namespace _ReQL

#endif  // REQL_REQL_ARRAY_HPP_
