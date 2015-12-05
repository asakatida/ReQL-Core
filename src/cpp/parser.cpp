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

#include "./cpp/parser.hpp"

#include "./cpp/error.hpp"
#include "./cpp/query.hpp"

#include <algorithm>

namespace ReQL {

Result::Result() : p_value(), p_type(null) {}

Result::Result(bool value) : p_value(value), p_type(boolean) {}

Result::Result(double value) : p_value(value), p_type(number) {}

Result::Result(const char *value, const size_t size) :
  p_value(std::string(value, size)), p_type(string) {}

Result::Result(std::vector<Result> value) :
  p_value(value), p_type(array) {}

Result::Result(std::map<std::string, Result> value) :
  p_value(
    std::accumulate(
      value.cbegin(),
      value.cend(),
      std::map<std::string, Result>(),
      [](auto object, auto next) {
        object.insert({std::string(next.first.c_str(), next.first.size()), next.second});
        return object;
      }
    )
  ),
  p_type(object) {}

Result::Result(const Result &other) :
  p_value(other.p_value, other.p_type), p_type(other.p_type) {}

Result::Result(Result &&other) :
  p_value(std::move(other.p_value), other.p_type), p_type(std::move(other.p_type)) {}

Result &Result::operator =(const Result &other) {
  if (this != &other) {
    p_value.copy(other.p_value, other.p_type);
    p_type = other.p_type;
  }
  return *this;
}

Result &Result::operator =(Result &&other) {
  if (this != &other) {
    p_value.move(std::move(other.p_value), other.p_type);
    p_type = std::move(other.p_type);
  }
  return *this;
}

Result::JSON::JSON() {}

Result::JSON::JSON(bool value) : boolean(value) {}

Result::JSON::JSON(double value) : number(value) {}

Result::JSON::JSON(std::string value) : string(value) {}

Result::JSON::JSON(std::vector<Result> value) : array(value) {}

Result::JSON::JSON(std::map<std::string, Result> value) : object(value) {}

Result::JSON::JSON(const JSON &other, JSONtype type) { copy(other, type); }

Result::JSON::JSON(JSON &&other, JSONtype type) { move(std::move(other), type); }

Result::JSON::~JSON() {}

Result::JSON &Result::JSON::copy(const JSON &other, JSONtype type) {
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

Result::JSON &Result::JSON::move(JSON &&other, JSONtype type) {
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

}  // namespace ReQL
