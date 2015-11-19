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

#include <algorithm>
#include <vector>

namespace ReQL {

Cursor::Cursor() {}

Cursor::Cursor(_Cursor *cur) : p_cur(cur) {}

Cursor::Cursor(Cursor &&other) : p_cur(std::move(other.p_cur)) {}

Cursor &
Cursor::operator=(Cursor &&other) {
  if (this != &other) {
    //p_cur = std::move(other.p_cur);
  }
  return *this;
}

bool Cursor::isOpen() const {
  return false; //  p_cur.isOpen;
}

Query
Cursor::next() {
  return Query();
}

std::vector<Query>
Cursor::toVector() {
  return std::vector<Query>();
}

void
Cursor::close() {
  //  p_cur = _Cursor();
}

}  // namespace ReQL
