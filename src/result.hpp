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

struct Result {
  Result() : p_value(), p_type(null) {}

  Result(bool value) : p_value(value), p_type(boolean) {}

  Result(double value) : p_value(value), p_type(number) {}

  Result(const wchar_t *value, const size_t size) :
    p_value(std::wstring(value, size)), p_type(string) {}

  Result(std::vector<Result> value) :
    p_value(value), p_type(array) {}

  Result(std::map<std::wstring, Result> value) :
    p_value(value),
    p_type(object) {}

  Result(const Result &other) :
    p_value(other.p_value, other.p_type), p_type(other.p_type) {}

  Result(Result &&other) :
    p_value(std::move(other.p_value), other.p_type), p_type(std::move(other.p_type)) {}

  Result &operator =(const Result &other) {
    if (this != &other) {
      p_value.copy(other.p_value, other.p_type);
      p_type = other.p_type;
    }
    return *this;
  }

  Result &operator =(Result &&other) {
    if (this != &other) {
      p_value.move(std::move(other.p_value), other.p_type);
      p_type = std::move(other.p_type);
    }
    return *this;
  }

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

  union JSON {
    JSON() {}
    JSON(bool value) : boolean(value) {}
    JSON(double value) : number(value) {}
    JSON(std::wstring value) : string(value) {}
    JSON(std::vector<Result> value) : array(value) {}
    JSON(std::map<std::wstring, Result> value) : object(value) {}

    JSON(const JSON &other, JSONtype type) { copy(other, type); }
    JSON(JSON &&other, JSONtype type) { move(std::move(other), type); }

    JSON &copy(const JSON &other, JSONtype type) {
      if (this != &other) {
        switch (type) {
          case JSONtype::array: {
            array = other.array;
            break;
          }
          case JSONtype::boolean: {
            boolean = other.boolean;
            break;
          }
          case JSONtype::number: {
            number = other.number;
            break;
          }
          case JSONtype::null: {
            break;
          }
          case JSONtype::object: {
            object = other.object;
            break;
          }
          case JSONtype::string: {
            string = other.string;
            break;
          }
        }
      }
      return *this;
    }

    JSON &move(JSON &&other, JSONtype type) {
      if (this != &other) {
        switch (type) {
          case JSONtype::array: {
            array = std::move(other.array);
            break;
          }
          case JSONtype::boolean: {
            boolean = std::move(other.boolean);
            break;
          }
          case JSONtype::number: {
            number = std::move(other.number);
            break;
          }
          case JSONtype::null: {
            break;
          }
          case JSONtype::object: {
            object = std::move(other.object);
            break;
          }
          case JSONtype::string: {
            string = std::move(other.string);
            break;
          }
        }
      }
      return *this;
    }

    ~JSON() {}

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
