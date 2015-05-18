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

namespace ReQL {

class ResultBuilder : public Parser {
public:
  ResultBuilder() {}
  ~ResultBuilder();

  Query result() { return p_result; }

  void parse(Query val) { parse_c(val._internal().get()); }

private:
  void startObject() {
    p_objects.push_back(Types::object());
  }

  void startKeyValue() {
  }

  void endKeyValue(Types::string key) {
    if (p_objects.empty()) {
      throw ReQLDriverError();
    }
    Types::object object = p_objects.back();
    p_objects.pop_back();
    object.insert({key, p_result});
    p_objects.push_back(object);
  }

  void endObject() {
    if (p_objects.empty()) {
      throw ReQLDriverError();
    }
    Types::object object = p_objects.back();
    p_objects.pop_back();
    p_result = Query(object);
  }

  void startArray() {
    p_arrays.push_back(Types::array());
  }

  void startElement() {
  }

  void endElement() {
    if (p_arrays.empty()) {
      throw ReQLDriverError();
    }
    Types::array array = p_arrays.back();
    p_arrays.pop_back();
    array.push_back(p_result);
    p_arrays.push_back(array);
  }

  void endArray() {
    if (p_arrays.empty()) {
      throw ReQLDriverError();
    }
    Types::array array = p_arrays.back();
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

  void addValue(Types::string value) {
    p_result = Query(value);
  }

  std::vector<Types::object> p_objects;
  std::vector<Types::array> p_arrays;
  Query p_result;
};

ResultBuilder::~ResultBuilder() {}

Cursor::Cursor() : _C::CTypes::cursor(new _C::ReQL_Cur_t) {}

Cursor::Cursor(Cursor &&other) : _C::CTypes::cursor(std::move(other)) {}

Cursor &
Cursor::operator=(Cursor &&other) {
  if (this != &other) {
    close();
    _C::CTypes::cursor::operator=(std::move(other));
  }
  return *this;
}

Cursor::~Cursor() {
  close();
}

bool Cursor::isOpen() const {
  return reql_cur_open(get());
}

Query
Cursor::next() {
  return Query(reql_cursor_next(get()));
}

void
Cursor::next(Parser &p) {
  _C::ReQL_Obj_t *res = reql_cursor_next(get());
  if (res != nullptr) {
    p.parse_c(res);
  }
}

void
Cursor::close() {
  reql_close_cur(get());
}

}  // namespace ReQL
