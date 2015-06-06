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

#include "./cpp/types.hpp"

namespace ReQL {

class Parser {
public:
  virtual ~Parser();

  virtual void startObject() = 0;
  virtual void startKeyValue() = 0;
  virtual void endKeyValue(Types::string key) = 0;
  virtual void endObject() = 0;

  virtual void startArray() = 0;
  virtual void startElement() = 0;
  virtual void endElement() = 0;
  virtual void endArray() = 0;

  virtual void addValue() = 0;
  virtual void addValue(bool value) = 0;
  virtual void addValue(double value) = 0;
  virtual void addValue(Types::string value) = 0;

  void parse(_C::ReQL_Obj_t *val);
};

}  // namespace ReQL

#endif  // REQL_CPP_RESULT_HPP_
