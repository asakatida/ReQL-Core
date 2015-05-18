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

class Result {
public:
  Result();
  explicit Result(const bool val);
  explicit Result(const double val);
  explicit Result(const Types::string val);
  explicit Result(const std::map<Types::string, Result> val);
  explicit Result(const std::vector<Result> val);
  Result(const Result &other);
  Result(Result &&other);

  Result &operator=(const Result &other);
  Result &operator=(Result &&other);

  void insert(Result elem);
  void insert(Types::string key, Result value);

  _C::ReQL_Datum_t type() const;
  bool boolean() const;
  double number() const;
  std::map<Types::string, Result> object() const;
  Types::string string() const;
  std::vector<Result> array() const;

private:
  void copy(const Result &other);
  void move(Result &&other);

  _C::ReQL_Datum_t p_type;
  bool p_boolean;
  double p_num;
  std::map<Types::string, Result> p_object;
  Types::string p_string;
  std::vector<Result> p_array;
};

class Wrapper;

class Parser {
public:
  virtual ~Parser();
  void parse(Wrapper val);

  virtual void startObject() = 0;
  virtual void addKey(Types::string key) = 0;
  virtual void addKeyValue(Types::string key) = 0;
  virtual void addKeyValue(Types::string key, bool value) = 0;
  virtual void addKeyValue(Types::string key, double value) = 0;
  virtual void addKeyValue(Types::string key, Types::string value) = 0;
  virtual void endObject() = 0;

  virtual void startArray() = 0;
  virtual void addElement() = 0;
  virtual void addElement(bool value) = 0;
  virtual void addElement(double value) = 0;
  virtual void addElement(Types::string value) = 0;
  virtual void endArray() = 0;

  void parse_c(_C::ReQL_Obj_t *val);
};

}  // namespace ReQL

#endif  // REQL_CPP_RESULT_HPP_
