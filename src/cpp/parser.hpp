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

#ifndef REQL_CPP_RESULT_HPP_
#define REQL_CPP_RESULT_HPP_

#include <string>

namespace ReQL {

class Result {
};

class Parser {
public:
  typedef Result result_t;

  result_t get() const;

  int r_type() const;

  void startObject();
  void startKeyValue();
  void endKeyValue(std::string key);
  void endObject();

  void startArray();
  void startElement();
  void endElement();
  void endArray();

  void addValue();
  void addValue(bool value);
  void addValue(double value);
  void addValue(std::string value);

  result_t p_result;
};

}  // namespace ReQL

#endif  // REQL_CPP_RESULT_HPP_
