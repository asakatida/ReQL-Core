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
  typedef str_t string_type;

  Stream &operator <<(const Stream &other) {
    p_stream.insert(p_stream.cend(), other.p_stream.cbegin(), other.p_stream.cend());
    return *this;
  }

  template <class object_t>
  Stream &operator <<(const object_t &value) {
    p_stream.push_back(string_type(value));
    return *this;
  }

  Stream &operator <<(const int value) {
    p_stream.push_back(std::to_string(value));
    return *this;
  }

  Stream &operator <<(const typename string_type::value_type *value) {
    p_stream.push_back(string_type(value));
    return *this;
  }

  Stream &operator <<(const double value) {
    p_stream.push_back(std::to_string(value));
    return *this;
  }

  string_type str() const {
    auto size = std::accumulate(p_stream.cbegin(), p_stream.cend(), 0, [](const size_t size, const string_type &s) {
      return size + s.size();
    });
    const std::unique_ptr<typename string_type::value_type> value(new typename string_type::value_type[size]);
    std::accumulate(p_stream.cbegin(), p_stream.cend(), value.get(), [](typename string_type::value_type *value, const string_type &s) {
      memcpy(value, s.c_str(), s.size());
      return value + s.size();
    });
    return string_type(value.get(), size);
  }

  std::deque<string_type> p_stream;
};

typedef _ReQL::Stream<ImmutableString> _Stream;

}  // namespace _ReQL

#endif  // REQL_REQL_STREAM_HPP_
