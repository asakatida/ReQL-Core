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

#ifndef REQL_CPP_CURSOR_HPP_
#define REQL_CPP_CURSOR_HPP_

#include "./reql/result.hpp"

#include "./reql/core/connection.hpp"

#include <iterator>

namespace ReQL {

template <class result_t>
struct Cursor : public std::iterator<std::input_iterator_tag, result_t> {
  Cursor(const Cursor &other) : p_cur(other.p_cur) {}

  Cursor(Cursor &&other) : p_cur(std::move(other.p_cur)) {}

  Cursor &operator=(const Cursor &other) {
    if (this != &other) {
      p_cur = other.p_cur;
    }
    return *this;
  }

  Cursor &operator=(Cursor &&other) {
    if (this != &other) {
      p_cur = std::move(other.p_cur);
    }
    return *this;
  }

  Cursor &begin() noexcept {
    return *this;
  }

  Cursor &cbegin() noexcept {
    return *this;
  }

  const Cursor &end() const {
    return *this;
  }

  const Cursor &cend() const {
    return *this;
  }

  Cursor &operator ++() {
    ++(*p_cur);
    return *this;
  }

  const result_t &operator *() const {
    return *(*p_cur);
  }

  const result_t &operator ->() const {
    return *(*p_cur);
  }

  bool operator ==(const Cursor &other) const {
    return p_cur == other.p_cur;
  }

  bool operator !=(const Cursor &other) const {
    return p_cur != other.p_cur;
  }

  friend void swap(Cursor &c1, Cursor &c2) {
    c1.swap(c2);
  }

  Cursor(const std::shared_ptr<_ReQL::Cursor_t<result_t> > &cur) : p_cur(cur) {}

  void swap(Cursor &other) {
    std::swap(p_cur, other.p_cur);
  }

  std::shared_ptr<_ReQL::Cursor_t<result_t> > p_cur;
};

}  // namespace ReQL

#endif  // REQL_CPP_CURSOR_HPP_
