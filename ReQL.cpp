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

#include "ReQL.hpp"

#include <cstring>
#include <limits>

namespace ReQL {

Result::Result() : p_type(REQL_R_NULL), p_value() {}

Result::Result(const bool &val) : p_type(REQL_R_BOOL), p_value(val) {}

Result::Result(const double &val) : p_type(REQL_R_NUM), p_value(val) {}

Result::Result(const std::string &val) : p_type(REQL_R_STR), p_value(val) {}

Result::Result(const std::map<std::string, Result> &val) : p_type(REQL_R_OBJECT), p_value(val) {}

Result::Result(const std::vector<Result> &val) : p_type(REQL_R_ARRAY), p_value(val) {}

Result::Result(const Result &other) {
  p_value.copy(other.p_value, p_type);
}

Result::Result(Result &&other) {
  p_value.move(std::move(other.p_value), p_type);
}

Result::~Result() {
  p_value.release(p_type);
}

Result &
Result::operator=(const Result &other) {
  if (this != &other) {
    p_type = other.p_type;
    p_value.copy(other.p_value, p_type);
  }
  return *this;
}

Result &
Result::operator=(Result &&other) {
  if (this != &other) {
    p_type = std::move(other.p_type);
    p_value.move(std::move(other.p_value), p_type);
  }
  return *this;
}

void
Result::insert(Result &&elem) {
  if (p_type != REQL_R_ARRAY) {
    throw;
  }
  p_value.p_array->push_back(std::move(elem));
}

void
Result::insert(std::string &key, Result &&value) {
  if (p_type != REQL_R_OBJECT) {
    throw;
  }
  p_value.p_object->insert({key, std::move(value)});
}

ReQL_Datum_t
Result::type() const {
  return p_type;
}

bool
Result::boolean() const {
  if (p_type != REQL_R_BOOL) {
    throw;
  }
  return *p_value.p_boolean;
}

double
Result::number() const {
  if (p_type != REQL_R_NUM) {
    throw;
  }
  return *p_value.p_num;
}

std::map<std::string, Result>
Result::object() const {
  if (p_type != REQL_R_OBJECT) {
    throw;
  }
  return *p_value.p_object;
}

std::string
Result::string() const {
  if (p_type != REQL_R_STR) {
    throw;
  }
  return *p_value.p_string;
}

std::vector<Result>
Result::array() const {
  if (p_type != REQL_R_ARRAY) {
    throw;
  }
  return *p_value.p_array;
}

Result::JSON_Value::JSON_Value() {
  std::memset(this, 0, sizeof(Result::JSON_Value));
}

Result::JSON_Value::JSON_Value(const bool &val) : p_boolean(new bool(val)) {}

Result::JSON_Value::JSON_Value(const double &val) : p_num(new double(val)) {}

Result::JSON_Value::JSON_Value(const std::string &val) : p_string(new std::string(val)) {}

Result::JSON_Value::JSON_Value(const std::map<std::string, Result> &val) : p_object(new std::map<std::string, Result>(val)) {}

Result::JSON_Value::JSON_Value(const std::vector<Result> &val) : p_array(new std::vector<Result>(val)) {}

void
Result::JSON_Value::copy(const Result::JSON_Value &other, const ReQL_Datum_t &type) {
  release(type);
  switch (type) {
    case REQL_R_ARRAY: {
      p_array = new std::vector<Result>(*other.p_array);
      break;
    }
    case REQL_R_BOOL: {
      p_boolean = new bool(*other.p_boolean);
      break;
    }
    case REQL_R_NUM: {
      p_num = new double(*other.p_num);
      break;
    }
    case REQL_R_OBJECT: {
      p_object = new std::map<std::string, Result>(*other.p_object);
      break;
    }
    case REQL_R_STR: {
      p_string = new std::string(*other.p_string);
      break;
    }
    case REQL_R_NULL:
    case REQL_R_JSON:
    case REQL_R_REQL: break;
  }
}

void
Result::JSON_Value::move(Result::JSON_Value &&other, const ReQL_Datum_t &type) {
  release(type);
  switch (type) {
    case REQL_R_ARRAY: {
      p_array = std::move(other.p_array);
      break;
    }
    case REQL_R_BOOL: {
      p_boolean = std::move(other.p_boolean);
      break;
    }
    case REQL_R_NUM: {
      p_num = std::move(other.p_num);
      break;
    }
    case REQL_R_OBJECT: {
      p_object = std::move(other.p_object);
      break;
    }
    case REQL_R_STR: {
      p_string = std::move(other.p_string);
      break;
    }
    case REQL_R_NULL:
    case REQL_R_JSON:
    case REQL_R_REQL: break;
  }
}

void
Result::JSON_Value::release(const ReQL_Datum_t &type) {
  switch (type) {
    case REQL_R_ARRAY: {
      if (p_array != nullptr) {
        delete p_array; p_array = nullptr;
      }
      break;
    }
    case REQL_R_OBJECT: {
      if (p_object != nullptr) {
        delete p_object; p_object = nullptr;
      }
      break;
    }
    case REQL_R_STR: {
      if (p_string != nullptr) {
        delete p_string; p_string = nullptr;
      }
      break;
    }
    case REQL_R_BOOL: {
      if (p_boolean != nullptr) {
        delete p_boolean; p_boolean = nullptr;
      }
      break;
    }
    case REQL_R_NUM: {
      if (p_num != nullptr) {
        delete p_num; p_num = nullptr;
      }
      break;
    }
    case REQL_R_JSON:
    case REQL_R_NULL:
    case REQL_R_REQL: break;
  }
}

Result::JSON_Value::~JSON_Value() {
  std::memset(this, 0, sizeof(Result::JSON_Value));
}

void
Parser::parse(ReQL_Obj_t *val) {
  switch (reql_datum_type(val)) {
    case REQL_R_ARRAY: {
      startArray();

      ReQL_Iter_t it = reql_new_iter(val);
      ReQL_Obj_t *elem = NULL;

      while ((elem = reql_iter_next(&it)) != NULL) {
        parse(elem);
      }

      endArray();
      break;
    }
    case REQL_R_BOOL: {
      addElement(static_cast<bool>(reql_to_bool(val)));
      break;
    }
    case REQL_R_JSON:
    case REQL_R_REQL: break;
    case REQL_R_NULL: {
      addElement();
      break;
    }
    case REQL_R_NUM: {
      addElement(reql_to_number(val));
      break;
    }
    case REQL_R_OBJECT: {
      startObject();

      ReQL_Iter_t it = reql_new_iter(val);
      ReQL_Obj_t *key = NULL;
      ReQL_Obj_t *value = NULL;

      while ((key = reql_iter_next(&it)) != NULL) {
        value = reql_object_get(val, key);
        std::string key_string(reinterpret_cast<char*>(reql_string_buf(key)), reql_size(key));

        switch (reql_datum_type(value)) {
          case REQL_R_BOOL: {
            addKeyValue(key_string, static_cast<bool>(reql_to_bool(val)));
            break;
          }
          case REQL_R_ARRAY:
          case REQL_R_OBJECT: {
            addKey(key_string);
            parse(value);
            break;
          }
          case REQL_R_NULL: {
            addKeyValue(key_string);
            break;
          }
          case REQL_R_NUM: {
            addKeyValue(key_string, reql_to_number(value));
            break;
          }
          case REQL_R_JSON:
          case REQL_R_REQL: break;
          case REQL_R_STR: {
            addKeyValue(key_string, std::string(reinterpret_cast<char*>(reql_string_buf(value)), reql_size(value)));
            break;
          }
        }
      }

      endObject();
      break;
    }
    case REQL_R_STR: {
      addElement(std::string(reinterpret_cast<char*>(reql_string_buf(val)), reql_size(val)));
      break;
    }
  }
}

class ResultBuilder : public Parser {
public:
  Result result() { return p_result; }

private:
  void startObject() {
    p_stack.push_back(std::move(Result(std::map<std::string, Result>())));
  }

  void addKey(std::string key) {
    p_keys.push_back(key);
  }

  void addKeyValue(std::string key) {
    p_stack.end()->insert(key, std::move(Result()));
  }

  void addKeyValue(std::string key, bool value) {
    p_stack.end()->insert(key, std::move(Result(value)));
  }

  void addKeyValue(std::string key, double value) {
    p_stack.end()->insert(key, std::move(Result(value)));
  }

  void addKeyValue(std::string key, std::string value) {
    p_stack.end()->insert(key, std::move(Result(value)));
  }

  void endObject() {
    end();
  }

  void startArray() {
    p_stack.push_back(Result(std::vector<Result>()));
  }

  void addElement() {
    addElement(std::move(Result()));
  }

  void addElement(bool value) {
    addElement(std::move(Result(value)));
  }

  void addElement(double value) {
    addElement(std::move(Result(value)));
  }

  void addElement(std::string value) {
    addElement(std::move(Result(value)));
  }

  void endArray() {
    end();
  }

  void addElement(Result &&val) {
    if (p_stack.empty()) {
      p_result = std::move(val);
    } else if (p_stack.end()->type() == REQL_R_ARRAY) {
      p_stack.end()->insert(std::move(val));
    } else {
      throw;
    }
  }

  void end() {
    Result last = *p_stack.end().base();
    p_stack.pop_back();
    if (p_stack.empty()) {
      p_result = last;
    } else if (p_stack.end()->type() == REQL_R_OBJECT) {
      p_stack.end()->insert(*p_keys.end(), std::move(last));
      p_keys.pop_back();
    } else if (p_stack.end()->type() == REQL_R_ARRAY) {
      addElement(std::move(last));
    } else {
      throw;
    }
  }

  std::vector<Result> p_stack;
  std::vector<std::string> p_keys;
  Result p_result;
};

Cursor::Cursor() : cur(new ReQL_Cur_t) {
  reql_cursor_init(data());
}

Cursor::~Cursor() {
}

bool Cursor::isOpen() const {
  return reql_cur_open(data());
}

Result
Cursor::next() {
  ResultBuilder builder;
  next(builder);
  return builder.result();
}

void
Cursor::next(Parser &p) {
  p.parse(reql_cursor_next(data()));
}

ReQL_Cur_t *
Cursor::data() const {
  return cur.get();
}

void
Cursor::close() {
}

Connection::Connection() : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const std::string &host) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  reql_conn_set_addr(data(), const_cast<char *>(host.c_str()));

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const std::string &host, const std::uint16_t &port) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  reql_conn_set_addr(data(), const_cast<char *>(host.c_str()));
  reql_conn_set_port(data(), const_cast<char *>(std::to_string(port).c_str()));

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const std::string &host, const std::uint16_t &port, const std::string &key) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  std::size_t auth_size = key.size();

  if (auth_size > std::numeric_limits<std::uint32_t>::max()) {
    return;
  }

  reql_conn_set_addr(data(), const_cast<char *>(host.c_str()));
  reql_conn_set_port(data(), const_cast<char *>(std::to_string(port).c_str()));
  reql_conn_set_auth(data(), static_cast<std::uint32_t>(auth_size), const_cast<char *>(key.c_str()));

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const Connection &other) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  ReQL_Conn_t *o_conn = other.data();

  reql_conn_set_addr(data(), o_conn->addr);
  reql_conn_set_port(data(), o_conn->port);
  reql_conn_set_auth(data(), o_conn->auth_size, o_conn->auth);

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(Connection &&other) {
  conn = std::move(other.conn);
}

Connection::~Connection() {
  reql_ensure_conn_close(data());
}

Connection &Connection::operator=(const Connection &other) {
  if (this != &other) {
    reql_ensure_conn_close(data());
    reql_connection_init(data());

    ReQL_Conn_t *o_conn = other.data();

    reql_conn_set_addr(data(), o_conn->addr);
    reql_conn_set_port(data(), o_conn->port);
    reql_conn_set_auth(data(), o_conn->auth_size, o_conn->auth);

    std::uint8_t buf[500];

    if (reql_connect(data(), buf, 500)) {
    }
  }
  return *this;
}

Connection &Connection::operator=(Connection &&other) {
  reql_ensure_conn_close(data());
  conn = std::move(other.conn);
  return *this;
}

void
Connection::close() {
  reql_close_conn(data());
}

bool
Connection::isOpen() const {
  return reql_conn_open(data());
}

ReQL_Conn_t *
Connection::data() const {
  return conn.get();
}

Cursor Query::run(const Connection &conn) const {
  if (!conn.isOpen()) {
  }

  Cursor cur;

  reql_run(cur.data(), p_query.data(), conn.data(), nullptr);

  return cur;
}

Query &Query::operator=(const Query &other) {
  Expr::operator=(other);
  return *this;
}

Query &Query::operator=(Query &&other) {
  Expr::operator=(std::move(other));
  return *this;
}

bool Query::operator<(const Query &other) const {
  return Expr::operator<(other);
}

}
