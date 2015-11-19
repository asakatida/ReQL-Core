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

namespace _ReQL {

template <class char_t, class Traits = std::char_traits<char_t>, class Allocator = std::allocator<char_t>>
class _String {
public:
  typedef Traits traits_type;
  typedef typename traits_type::char_type value_type;
  typedef Allocator allocator_type;
  typedef typename std::allocator_traits<allocator_type>::size_type size_type;
  typedef typename std::allocator_traits<allocator_type>::difference_type difference_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef typename std::allocator_traits<Allocator>::pointer pointer;
  typedef typename std::allocator_traits<Allocator>::const_pointer const_pointer;
  typedef pointer iterator;
  typedef const_pointer const_iterator;

  _String() {}

  _String(const value_type value) : p_size(1), p_value(new value_type[1]) {
    *p_value = value;
  }

  _String(const value_type *value) : p_size(traits_type::length(value) - 1), p_value(new value_type[p_size]) {
    memcpy(p_value.load(), value);
  }

  _String(const value_type *value, const size_type size) : p_size(size), p_value(new value_type[size]) {
    memcpy(p_value.load(), value);
  }

  _String(const _String &other) : p_size(other.p_size), p_value(new value_type[other.p_size]) {
    memcpy(p_value.load(), other.c_str());
  }

  _String(_String &&other) : p_size(other.p_size), p_value(other.p_value.exchange(nullptr)) {}

  template <class str_t>
  _String(const str_t &str) : p_size(str.size()), p_value(new value_type[p_size]) {
    memcpy(p_value.load(), str.c_str());
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
      p_size = std::move(other.p_size);
      exchange(other.p_value.exchange(nullptr));
    }
    return *this;
  }

  ~_String() {
    exchange(nullptr);
  }

  bool empty() const {
    return !p_size;
  }

  _String substr(const size_type pos) const {
    return _String(p_value.load() + pos, p_size - pos);
  }

  size_type size() const { return p_size; }

  size_type length() const { return p_size; }

  size_type capacity() const { return p_size; }

  value_type *c_str() const { return p_value.load(); }

  value_type *data() const { return p_value.load(); }

  reference at(const size_type pos) {
    if (pos >= size()) {
      throw std::out_of_range("");
    }
    return p_value.load()[pos];
  }

  const_reference at(const size_type pos) const {
    if (pos >= size()) {
      throw std::out_of_range("");
    }
    return p_value.load()[pos];
  }

  reference operator [](const size_type pos) {
    if (pos == size()) {
      return value_type();
    }
    return at(pos);
  }

  const_reference operator [](const size_type pos) const {
    if (pos == size()) {
      return value_type();
    }
    return at(pos);
  }

  bool operator <(const _String &other) const {
    return p_value < other.p_value;
  }

  char_t &front() {
    return p_value.load();
  }

  const char_t &front() const {
    return p_value.load();
  }

  iterator begin() {
    return p_value.load();
  }

  const_iterator cbegin() const {
    return p_value.load();
  }

  iterator end() {
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

  void memcpy(const value_type *in) {
    memcpy(exchange(new value_type[p_size]), in, p_size);
  }

  void memcpy(value_type *out, const value_type *in) const {
    memcpy(out, in, p_size);
  }

  void memcpy(value_type *out, const value_type *in, const size_type size) const {
    std::memcpy(out, in, sizeof(value_type) * size);
  }

  size_type p_size;
  std::atomic<value_type *> p_value;
};

template <class value_type>
bool operator ==(const _String<value_type> self, const value_type *other) {
  if (std::char_traits<value_type>::length(other) - 1 == self.size()) {
    return !std::memcmp(self.data(), other, sizeof(value_type) * self.size());
  }
  return false;
}

typedef _String<ReQL_Byte> ImmutableString;

}  // namespace _ReQL

#endif  // REQL_REQL_STRING_HPP_
