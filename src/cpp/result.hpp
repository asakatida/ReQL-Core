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

#include <map>
#include <string>
#include <vector>

namespace ReQL {
extern "C" {

#include "./ReQL.h"

}

class Result {
public:
  Result();
  explicit Result(const bool val);
  explicit Result(const double val);
  explicit Result(const std::string val);
  explicit Result(const std::map<std::string, Result> val);
  explicit Result(const std::vector<Result> val);
  Result(const Result &other);
  Result(Result &&other);

  Result &operator=(const Result &other);
  Result &operator=(Result &&other);

  void insert(Result elem);
  void insert(std::string key, Result value);

  ReQL_Datum_t type() const;
  bool boolean() const;
  double number() const;
  std::map<std::string, Result> object() const;
  std::string string() const;
  std::vector<Result> array() const;

private:
  void copy(const Result &other);
  void move(Result &&other);

  ReQL_Datum_t p_type;
  bool p_boolean;
  double p_num;
  std::map<std::string, Result> p_object;
  std::string p_string;
  std::vector<Result> p_array;
};

class Wrapper;

class Parser {
public:
  virtual ~Parser();
  void parse(Wrapper val);

  virtual void startObject() = 0;
  virtual void addKey(std::string key) = 0;
  virtual void addKeyValue(std::string key) = 0;
  virtual void addKeyValue(std::string key, bool value) = 0;
  virtual void addKeyValue(std::string key, double value) = 0;
  virtual void addKeyValue(std::string key, std::string value) = 0;
  virtual void endObject() = 0;

  virtual void startArray() = 0;
  virtual void addElement() = 0;
  virtual void addElement(bool value) = 0;
  virtual void addElement(double value) = 0;
  virtual void addElement(std::string value) = 0;
  virtual void endArray() = 0;

  void parse_c(ReQL_Obj_t *val);
};

}  // namespace ReQL

#endif  // REQL_CPP_RESULT_HPP_
