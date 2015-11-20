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

#include <memory>
#include <vector>

namespace ReQL {

class Cursor {
public:
  Cursor();

  Cursor(_Cursor cur);

  Cursor(Cursor &&other);

  Cursor &operator=(Cursor &&other);

  bool isOpen() const;

  Query next();
  std::vector<Query> toVector();

  void close();

  _Cursor p_cur;
};

}  // namespace ReQL

#endif  // REQL_CPP_CURSOR_HPP_
