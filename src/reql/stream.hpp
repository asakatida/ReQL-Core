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

#ifndef REQL_REQL_STREAM_HPP_
#define REQL_REQL_STREAM_HPP_

#include "./reql/string.hpp"

#include <algorithm>
#include <deque>
#include <string>

namespace _ReQL {

template <class str_t>
class Stream {
public:
  Stream &operator <<(const Stream &other) {
    p_stream.insert(p_stream.cend(), other.p_stream.cbegin(), other.p_stream.cend());
    return *this;
  }

  template <class object_t>
  Stream &operator <<(const object_t &value) {
    p_stream.push_back(str_t(value));
    return *this;
  }

  Stream &operator <<(const int value) {
    p_stream.push_back(std::to_string(value));
    return *this;
  }

  Stream &operator <<(const typename str_t::value_type value) {
    p_stream.push_back(std::to_string(value));
    return *this;
  }

  Stream &operator <<(const double value) {
    p_stream.push_back(std::to_string(value));
    return *this;
  }

  str_t str() {
    typename str_t::size_type size = 0;
    std::for_each(p_stream.cbegin(), p_stream.cend(), [&size](const str_t &_s){
      size += _s.size();
    });
    str_t s;
    s.reserve(size);
    std::for_each(p_stream.cbegin(), p_stream.cend(), [&s](const str_t &_s){
      s.append(_s);
    });
    return s;
  }

  std::deque<str_t> p_stream;
};

}  // namespace _ReQL

#endif  // REQL_REQL_STREAM_HPP_
