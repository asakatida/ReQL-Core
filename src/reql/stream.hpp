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
#include <sstream>
#include <string>

namespace _ReQL {

class Stream_t {
public:
  Stream_t &operator <<(const Stream_t &other) {
    p_stream.insert(p_stream.cend(), other.p_stream.cbegin(), other.p_stream.cend());
    return *this;
  }

  Stream_t &operator <<(const int value) {
    std::stringstream stream;
    stream << value;
    std::string str = stream.str();
    p_stream.push_back(ImmutableString(str.c_str(), str.size()));
    return *this;
  }

  Stream_t &operator <<(const char *value) {
    p_stream.push_back(ImmutableString(value));
    return *this;
  }

  Stream_t &operator <<(const ImmutableString &value) {
    p_stream.push_back(value);
    return *this;
  }

  Stream_t &operator <<(ImmutableString &&value) {
    p_stream.push_back(std::move(value));
    return *this;
  }

  Stream_t &operator <<(const double value) {
    std::stringstream stream;
    stream << value;
    std::string str = stream.str();
    p_stream.push_back(ImmutableString(str.c_str(), str.size()));
    return *this;
  }

  ImmutableString str() const {
    size_t size = 0;
    size = std::accumulate(p_stream.cbegin(),
                           p_stream.cend(),
                           size,
                           [](const size_t _size, const ImmutableString &s) {
      return _size + s.size();
    });
    const std::unique_ptr<char> value(new char[size]);
    std::accumulate(p_stream.cbegin(),
                    p_stream.cend(),
                    value.get(),
                    [](char *_value, const ImmutableString &s) {
      memcpy(_value, s.c_str(), s.size());
      return _value + s.size();
    });
    return ImmutableString(value.get(), size);
  }

private:
  std::deque<ImmutableString> p_stream;
};

typedef Stream_t _Stream;

}  // namespace _ReQL

#endif  // REQL_REQL_STREAM_HPP_
