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

#include "./cpp/cursor.hpp"

#include "./cpp/error.hpp"
#include "./cpp/query.hpp"

#include <algorithm>
#include <vector>

namespace ReQL {

class ResultBuilder : public Parser {
public:
  ResultBuilder() {}
  ~ResultBuilder();

  Query result() { return p_result; }

private:
  void startObject() {
    p_objects.push_back(std::map<std::string, Query>());
  }

  void startKeyValue() {
  }

  void endKeyValue(std::string key) {
    if (p_objects.empty()) {
      throw ReQLDriverError();
    }
    std::map<std::string, Query> object = p_objects.back();
    p_objects.pop_back();
    object.insert({key, p_result});
    p_objects.push_back(object);
  }

  void endObject() {
    if (p_objects.empty()) {
      throw ReQLDriverError();
    }
    std::map<std::string, Query> object = p_objects.back();
    p_objects.pop_back();
    p_result = Query(object);
  }

  void startArray() {
    p_arrays.push_back(std::vector<Query>());
  }

  void startElement() {
  }

  void endElement() {
    if (p_arrays.empty()) {
      throw ReQLDriverError();
    }
    std::vector<Query> array = p_arrays.back();
    p_arrays.pop_back();
    array.push_back(p_result);
    p_arrays.push_back(array);
  }

  void endArray() {
    if (p_arrays.empty()) {
      throw ReQLDriverError();
    }
    std::vector<Query> array = p_arrays.back();
    p_arrays.pop_back();
    p_result = Query(array);
  }

  void addValue() {
    p_result = Query();
  }

  void addValue(bool value) {
    p_result = Query(value);
  }

  void addValue(double value) {
    p_result = Query(value);
  }

  void addValue(std::string value) {
    p_result = Query(value);
  }

  std::vector<std::map<std::string, Query>> p_objects;
  std::vector<std::vector<Query>> p_arrays;
  Query p_result;
};

ResultBuilder::~ResultBuilder() {}

Cursor::Cursor() {}

Cursor::Cursor(_Cursor *cur) : p_cur(cur) {}

Cursor::Cursor(Cursor &&other) : p_cur(std::move(other.p_cur)) {}

Cursor &
Cursor::operator=(Cursor &&other) {
  if (this != &other) {
    //p_cur = std::move(other.p_cur);
  }
  return *this;
}

bool Cursor::isOpen() const {
  return false; //  p_cur.isOpen;
}

Query
Cursor::next() {
  return Query();
}

std::vector<Query>
Cursor::toVector() {
  return std::vector<Query>();
}

void
Cursor::close() {
  //  p_cur = _Cursor();
}

}  // namespace ReQL
