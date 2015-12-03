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

#include <map>
#include <vector>
#include <string>

namespace _ReQL {

template <class result_t>
class Parser_t {
public:
  int r_type() { return p_r_type; }

  std::vector<result_t> get() { return p_result; }

  void addValue() { p_stack.push_back(result_t()); }

  void addValue(const bool value) { p_stack.push_back(result_t(value)); }

  void addValue(const double value) {
    if (p_is_r_type) {
      p_r_type = static_cast<int>(value);
      p_is_r_type = false;
    }
    p_stack.push_back(result_t(value));
  }

  void addValue(const char *value, size_t size) {
    if (p_level == 1 && p_is_key && size == 1) {
      switch (value[0]) {
        case 'b': {
          p_is_backtrace = true;
          break;
        }
        case 'n': {
          p_is_notes = true;
          break;
        }
        case 'p': {
          p_is_profile = true;
          break;
        }
        case 'r': {
          p_is_response = true;
          break;
        }
        case 't': {
          p_is_r_type = true;
          break;
        }
        default: {
          throw std::exception();
          break;
        }
      }
    }
    p_stack.push_back(result_t(value, size));
    p_is_key = false;
  }

  void startArray() {
    p_arrays.push_back(std::vector<result_t>());
    ++p_level;
  }

  void endArray() {
    p_stack.push_back(result_t(p_arrays.back()));
    p_arrays.pop_back();
    --p_level;
  }

  void startObject() {
    p_objects.push_back(std::map<std::string, result_t>());
    p_is_key = false;
    ++p_level;
  }

  void startKeyValue() { p_is_key = true; }

  void endObject() {
    p_stack.push_back(result_t(p_objects.back()));
    p_objects.pop_back();
    --p_level;
  }

private:
  std::vector<std::vector<result_t> > p_arrays;
  std::vector<result_t> p_backtrace;
  bool p_is_backtrace;
  bool p_is_key;
  bool p_is_notes;
  bool p_is_profile;
  bool p_is_r_type;
  bool p_is_response;
  size_t p_level;
  std::vector<int> p_notes;
  std::vector<std::map<std::string, result_t> > p_objects;
  int p_r_type;
  std::vector<result_t> p_result;
  std::vector<result_t> p_stack;
};

}  // namespace _ReQL

#endif  // REQL_REQL_PARSER_HPP_
