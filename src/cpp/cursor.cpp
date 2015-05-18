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
#include "./cpp/wrapper.hpp"

#include <map>
#include <string>
#include <vector>

namespace ReQL {

class ResultBuilder : public Parser {
public:
  ResultBuilder() : Parser(), p_stack(), p_keys(), p_result() {}
  ~ResultBuilder();

  Result result() { return p_result; }

  void parse(Wrapper val) { parse_c(val.get()); }

private:
  void startObject() {
    p_stack.push_back(Result(std::map<Types::string, Result>()));
  }

  void addKey(Types::string key) {
    p_keys.push_back(key);
  }

  void addKeyValue(Types::string key) {
    Result object = p_stack.back();
    p_stack.pop_back();
    object.insert(key, Result());
    p_stack.push_back(object);
  }

  void addKeyValue(Types::string key, bool value) {
    Result object = p_stack.back();
    p_stack.pop_back();
    object.insert(key, Result(value));
    p_stack.push_back(object);
  }

  void addKeyValue(Types::string key, double value) {
    Result object = p_stack.back();
    p_stack.pop_back();
    object.insert(key, Result(value));
    p_stack.push_back(object);
  }

  void addKeyValue(Types::string key, Types::string value) {
    Result object = p_stack.back();
    p_stack.pop_back();
    object.insert(key, Result(value));
    p_stack.push_back(object);
  }

  void endObject() {
    end();
  }

  void startArray() {
    p_stack.push_back(Result(std::vector<Result>()));
  }

  void addElement() {
    addElement(Result());
  }

  void addElement(bool value) {
    addElement(Result(value));
  }

  void addElement(double value) {
    addElement(Result(value));
  }

  void addElement(Types::string value) {
    addElement(Result(value));
  }

  void addElement(Result val) {
    if (p_stack.empty()) {
      p_result = std::move(val);
      return;
    }
    Result array = p_stack.back();
    p_stack.pop_back();
    return addElement(array, val);
  }

  void addElement(Result array, Result val) {
    if (array.type() == _C::REQL_R_ARRAY) {
      array.insert(val);
      p_stack.push_back(array);
    } else {
      throw ReQLDriverError();
    }
  }

  void endArray() {
    end();
  }

  void end() {
    Result last = p_stack.back();
    p_stack.pop_back();
    if (p_stack.empty()) {
      p_result = std::move(last);
      return;
    }
    Result object = p_stack.back();
    p_stack.pop_back();
    if (object.type() == _C::REQL_R_OBJECT) {
      Types::string key = p_keys.back();
      p_keys.pop_back();
      object.insert(key, last);
      p_stack.push_back(object);
    } else if (object.type() == _C::REQL_R_ARRAY) {
      addElement(object, last);
    } else {
      throw ReQLDriverError();
    }
  }

  std::vector<Result> p_stack;
  std::vector<Types::string> p_keys;
  Result p_result;
};

ResultBuilder::~ResultBuilder() {}

Cursor::Cursor() : _C::Types::cursor(new _C::ReQL_Cur_t) {}

Cursor::Cursor(Cursor &&other) : _C::Types::cursor(std::move(other)) {}

Cursor &
Cursor::operator=(Cursor &&other) {
  if (this != &other) {
    close();
    _C::Types::cursor::operator=(std::move(other));
  }
  return *this;
}

Cursor::~Cursor() {
  close();
}

bool Cursor::isOpen() const {
  return reql_cur_open(get());
}

Result
Cursor::next() {
  ResultBuilder builder;
  next(builder);
  return builder.result();
}

void
Cursor::next(Parser &p) {
  _C::ReQL_Obj_t *res = reql_cursor_next(get());
  if (res != nullptr) {
    p.parse(Wrapper(res));
  }
}

void
Cursor::close() {
  reql_close_cur(get());
}

}  // namespace ReQL
