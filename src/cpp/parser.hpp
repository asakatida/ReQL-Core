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

class Result {
public:
  Result();
  Result(bool value);
  Result(double value);
  Result(const wchar_t *value, const size_t size);
  Result(std::vector<Result> value);
  Result(std::map<std::wstring, Result> value);

  Result(const Result &other);
  Result(Result &&other);

  Result &operator =(const Result &other);
  Result &operator =(Result &&other);

  enum JSONtype {
    array,
    boolean,
    number,
    null,
    object,
    string
  };

  JSONtype type() const noexcept;

  std::vector<Result> getArray() const;
  bool getBoolean() const;
  double getNumber() const;
  std::map<std::string, Result> getObject() const;
  std::string getString() const;

private:
  union JSON {
    JSON();
    JSON(bool value);
    JSON(double value);
    JSON(std::wstring value);
    JSON(std::vector<Result> value);
    JSON(std::map<std::wstring, Result> value);

    JSON(const JSON &other, JSONtype type);
    JSON(JSON &&other, JSONtype type);

    JSON &copy(const JSON &other, JSONtype type);
    JSON &move(JSON &&other, JSONtype type);

    ~JSON();

    std::vector<Result> array;
    bool boolean;
    double number;
    std::map<std::wstring, Result> object;
    std::wstring string;
  } p_value;

  JSONtype p_type;
};

}  // namespace ReQL

#endif  // REQL_CPP_RESULT_HPP_
