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

#ifndef REQL_REQL_PARSER_HPP_
#define REQL_REQL_PARSER_HPP_

#include "./reql/string.hpp"

#include <map>
#include <vector>

namespace _ReQL {

template <class result_t>
class Parser_t {
public:
  int r_type() {
    return 0;
  }

  result_t get() {
    return result_t();
  }

  void startParse() {}

  void endParse() {}

  void error(std::exception &e) {
    throw e;
  }

  void addValue() {
    p_stack.push_back(result_t());
  }

  template <class value_t>
  void addValue(value_t value) {
    p_stack.push_back(result_t(value));
  }

  void startArray() {
    p_arrays.push_back(std::vector<result_t>());
  }

  void startElement() {
  }

  void endElement() {
  }

  void endArray() {
    p_stack.push_back(result_t(p_arrays.back()));
    p_arrays.pop_back();
  }

  void startObject() {
    p_objects.push_back(std::map<ImmutableString, result_t>());
  }

  void startKeyValue() {
  }

  void endObject() {
    p_stack.push_back(result_t(p_objects.back()));
    p_objects.pop_back();
  }

  std::vector<std::vector<result_t>> p_arrays;
  std::vector<std::map<ImmutableString, result_t>> p_objects;
  result_t p_result;
  std::vector<result_t> p_stack;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PARSER_HPP_
