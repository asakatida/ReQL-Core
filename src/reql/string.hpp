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
#include <cstring>
#include <memory>
#include <numeric>
#include <stdexcept>
#include <string>

namespace _ReQL {

template <class char_t, class Traits = std::char_traits<char_t>, class Allocator = std::allocator<char_t> >
class BasicImmutableString {
public:
  typedef Traits traits_type;
  typedef typename traits_type::char_type value_type;
  typedef Allocator allocator_type;
  typedef typename std::allocator_traits<allocator_type>::size_type size_type;
  typedef typename std::allocator_traits<allocator_type>::difference_type difference_type;
  typedef const value_type& const_reference;
  typedef typename std::allocator_traits<Allocator>::const_pointer const_pointer;
  typedef const_pointer const_iterator;

  BasicImmutableString() {}

  BasicImmutableString(const value_type value) : p_size(1), p_value(new value_type[1]) {
    *p_value = value;
  }

  BasicImmutableString(const_pointer value) : p_size(traits_type::length(value) - 1), p_value(new value_type[p_size]) {
    memcpy(p_value.load(), value);
  }

  BasicImmutableString(const_pointer value, const size_type size) : p_size(size), p_value(new value_type[size]) {
    memcpy(p_value.load(), value);
  }

  BasicImmutableString(BasicImmutableString &&other) : p_size(other.p_size), p_value(other.p_value.exchange(nullptr)) {}

  BasicImmutableString(const BasicImmutableString &other) : p_size(other.size()), p_value(new value_type[p_size]) {
    memcpy(p_value.load(), other.c_str());
  }

  template <class str_t>
  BasicImmutableString(const str_t &other) : p_size(other.size()), p_value(new value_type[p_size]) {
    memcpy(p_value.load(), other.c_str());
  }

  BasicImmutableString &operator =(const BasicImmutableString &other) {
    if (this != &other) {
      p_size = other.size();
      memcpy(other.c_str());
    }
    return *this;
  }

  template <class str_t>
  BasicImmutableString &operator =(const str_t &other) {
    if (this != &other) {
      p_size = other.size();
      memcpy(other.c_str());
    }
    return *this;
  }

  BasicImmutableString &operator =(BasicImmutableString &&other) {
    if (this != &other) {
      p_size = std::move(other.p_size);
      exchange(other.p_value.exchange(nullptr));
    }
    return *this;
  }

  ~BasicImmutableString() {
    exchange(nullptr);
  }

  bool empty() const {
    return !p_size;
  }

  BasicImmutableString substr(const size_type pos) const {
    return BasicImmutableString(p_value.load() + pos, p_size - pos);
  }

  size_type size() const { return p_size; }

  size_type length() const { return p_size; }

  size_type capacity() const { return p_size; }

  value_type *c_str() const { return p_value.load(); }

  value_type *data() const { return p_value.load(); }

  const_reference at(const size_type pos) const {
    if (pos >= size()) {
      throw std::out_of_range("");
    }
    return p_value.load()[pos];
  }

  const_reference operator [](const size_type pos) const {
    if (pos == size()) {
      return value_type();
    }
    return at(pos);
  }

  bool operator <(const BasicImmutableString &other) const {
    return p_value < other.p_value;
  }

  const char_t &front() const {
    return p_value.load();
  }

  const_iterator cbegin() const {
    return p_value.load();
  }

  const_iterator cend() const {
    return p_value.load();
  }

private:
  value_type *exchange(value_type *value) {
    auto old = p_value.exchange(value);
    if (old) {
      delete [] old;
    }
    return value;
  }

  void memcpy(const_pointer in) {
    memcpy(exchange(new value_type[p_size]), in, p_size);
  }

  void memcpy(value_type *out, const_pointer in) const {
    memcpy(out, in, p_size);
  }

  void memcpy(value_type *out, const_pointer in, const size_type size) const {
    std::memcpy(out, in, sizeof(value_type) * size);
  }

  size_type p_size;
  std::atomic<value_type *> p_value;
};

template <class value_type>
bool operator ==(const BasicImmutableString<value_type> &self, const value_type *other) {
  if (std::char_traits<value_type>::length(other) - 1 == self.size()) {
    return !std::memcmp(self.data(), other, sizeof(value_type) * self.size());
  }
  return false;
}

typedef BasicImmutableString<char> ImmutableString;

}  // namespace _ReQL

#endif  // REQL_REQL_STRING_HPP_
