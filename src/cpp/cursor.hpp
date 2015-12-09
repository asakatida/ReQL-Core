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

#include "./cpp/parser.hpp"
#include "./cpp/query.hpp"

#include <array>
#include <condition_variable>
#include <functional>
#include <iterator>
#include <mutex>
#include <queue>

namespace ReQL {

class Cursor : public std::iterator<std::input_iterator_tag, Result> {
public:
  Cursor(const Cursor &other);

  Cursor(Cursor &&other);

  Cursor &operator=(const Cursor &other);

  Cursor &operator=(Cursor &&other);

  Cursor &begin() noexcept;

  Cursor &cbegin() noexcept;

  const Cursor &end() const;

  const Cursor &cend() const;

  Cursor &operator ++();

  const Result &operator *() const;

  const Result &operator ->() const;

  bool operator ==(const Cursor &other) const;

  bool operator !=(const Cursor &other) const;

private:
  friend class Query;
  friend void swap(Cursor &c1, Cursor &c2);

  Cursor();

  Cursor(const std::shared_ptr<_ReQL::Cursor_t<Result> > &cur);

  void swap(Cursor &other);

  std::shared_ptr<_ReQL::Cursor_t<Result> > p_cur;
};

void swap(Cursor &c1, Cursor &c2);

}  // namespace ReQL

#endif  // REQL_CPP_CURSOR_HPP_
