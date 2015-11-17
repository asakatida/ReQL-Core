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

#ifndef REQL_REQL_STRING_HPP_
#define REQL_REQL_STRING_HPP_

#include "./reql/types.hpp"

#include <atomic>
#include <memory>
#include <numeric>

namespace _ReQL {

template <class char_t>
class _String {
public:
  typedef ReQL_Size size_type;
  typedef char_t value_type;

  _String() {}

  _String(const value_type value) : p_size(1), p_value(new value_type[1]) {
    *p_value = value;
  }

  _String(const value_type *value) {
    while (value[p_size++]) {} --p_size;
    memcpy(value);
  }

  _String(const value_type *value, const size_type size) : p_size(size), p_value(new value_type[size]) {
    memcpy(p_value.load(), value);
  }

  _String(const _String &other) : p_size(other.p_size), p_value(new value_type[other.p_size]) {
    p_size = other.p_size;
    memcpy(other.c_str());
  }

  _String(_String &&other) : p_size(other.p_size), p_value(other.p_value.exchange(nullptr)) {}

  template <class str_t>
  _String(const str_t &str) : p_size(str.size()), p_value(new value_type[p_size]) {
    memcpy(p_value.load(), str.c_str());
  }

  template <class iter_t>
  _String(iter_t begin, const iter_t &end) : p_size(std::accumulate(begin, end, 0, [](const size_type size, const _String &s) {
    return size + s.size();
  })), p_value(new value_type[p_size]) {
    auto value = p_value.load();
    for (; begin != end; ++begin) {
      auto str = *begin;
      memcpy(value, str.c_str(), str.size());
      value += str.size();
    }
  }

  _String &operator =(const _String &other) {
    if (this != &other) {
      p_size = other.p_size;
      memcpy(other.c_str());
    }
    return *this;
  }

  _String &operator =(_String &&other) {
    if (this != &other) {
      p_size = other.p_size;
      exchange(other.p_value.exchange(nullptr));
    }
    return *this;
  }

  ~_String() {
    exchange(nullptr);
  }

  size_type size() const { return p_size; }
  value_type *c_str() const { return p_value.load(); }

private:
  value_type *exchange(value_type *value) {
    auto old = p_value.exchange(value);
    if (old) {
      delete [] old;
    }
    return value;
  }

  void memcpy(const value_type *in) {
    memcpy(exchange(new value_type[p_size]), in, p_size);
  }

  void memcpy(value_type *out, const value_type *in) {
    memcpy(out, in, p_size);
  }

  void memcpy(value_type *out, const value_type *in, const size_type size) {
    std::memcpy(out, in, sizeof(value_type) * size);
  }

  size_type p_size;
  std::atomic<value_type *> p_value;
};

typedef _String<char> ImutableString;

}  // namespace _ReQL

#endif  // REQL_REQL_STRING_HPP_