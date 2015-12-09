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

#include "./cpp/cursor.hpp"

#include "./cpp/error.hpp"
#include "./cpp/query.hpp"

#include <array>
#include <mutex>
#include <queue>

namespace ReQL {

Cursor::Cursor() {}

Cursor::Cursor(const std::shared_ptr<_ReQL::Cursor_t<Result> > &cur) : p_cur(cur) {}

Cursor::Cursor(Cursor &&other) {
  p_cur = std::move(other.p_cur);
}

Cursor &
Cursor::operator=(Cursor &&other) {
  if (this != &other) {
    p_cur = std::move(other.p_cur);
  }
  return *this;
}

Cursor &
Cursor::begin() noexcept {
  return *this;
}

Cursor &
Cursor::cbegin() noexcept {
  return *this;
}
/*
const Cursor &
Cursor::end() const {
  return *p_end;
}

const Cursor &
Cursor::cend() const {
  return *p_end;
}
*/
void
Cursor::swap(Cursor &other) {
  std::swap(p_cur, other.p_cur);
}

void swap(Cursor &c1, Cursor &c2) {
  c1.swap(c2);
}

}  // namespace ReQL
