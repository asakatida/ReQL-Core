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

namespace ReQL {

Result::Result() : type(REQL_R_JSON) {}

Result::Result(const Result &other) {
  value.copy(other.value, type);
}

Result::Result(Result &&other) {
  value.move(std::move(other.value), type);
}

Result::~Result() {
  value.release(type);
}

Result &
Result::operator=(const Result &other) {
  if (this != &other) {
    value.copy(other.value, type);
  }
  return *this;
}

Result &
Result::operator=(Result &&other) {
  if (this != &other) {
    value.move(std::move(other.value), type);
  }
  return *this;
}
  
Result::JSON_Value::JSON_Value() {
  std::memset(this, 0, sizeof(Result::JSON_Value));
}

void
Result::JSON_Value::copy(const Result::JSON_Value &other, ReQL_Datum_t type) {
  switch (type) {
    case REQL_R_ARRAY: {
      array = other.array;
      break;
    }
    case REQL_R_BOOL: {
      boolean = other.boolean;
      break;
    }
    case REQL_R_NUM: {
      num = other.num;
      break;
    }
    case REQL_R_OBJECT: {
      object = other.object;
      break;
    }
    case REQL_R_STR: {
      string = other.string;
      break;
    }
    case REQL_R_NULL:
    case REQL_R_JSON:
    case REQL_R_REQL: break;
  }
}

void
Result::JSON_Value::move(Result::JSON_Value &&other, ReQL_Datum_t type) {
  switch (type) {
    case REQL_R_ARRAY: {
      array = std::move(other.array);
      break;
    }
    case REQL_R_BOOL: {
      boolean = std::move(other.boolean);
      break;
    }
    case REQL_R_NUM: {
      num = std::move(other.num);
      break;
    }
    case REQL_R_OBJECT: {
      object = std::move(other.object);
      break;
    }
    case REQL_R_STR: {
      string = std::move(other.string);
      break;
    }
    case REQL_R_NULL:
    case REQL_R_JSON:
    case REQL_R_REQL: break;
  }
}

void
Result::JSON_Value::release(ReQL_Datum_t type) {
  switch (type) {
    case REQL_R_ARRAY: {
      array.~vector();
      break;
    }
    case REQL_R_OBJECT: {
      object.~map();
      break;
    }
    case REQL_R_STR: {
      string.~basic_string();
      break;
    }
    case REQL_R_BOOL:
    case REQL_R_JSON:
    case REQL_R_NULL:
    case REQL_R_NUM:
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
        std::string key_string((char *)reql_string_buf(key), reql_size(key));

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
            addKeyValue(key_string, std::string((char *)reql_string_buf(value), reql_size(value)));
            break;
          }
        }
      }
      
      endObject();
      break;
    }
    case REQL_R_STR: {
      addElement(std::string((char *)reql_string_buf(val), reql_size(val)));
      break;
    }
  }
}

class ResultBuilder : public Parser {
public:
  Result result() { return p_result; }

private:
  void startObject() {
    p_stack.push_back(Result());
    p_stack.end()->type = REQL_R_OBJECT;
    p_stack.end()->value.object = std::map<std::string, Result>();
  }

  void addKey(std::string key) {
    p_keys.push_back(key);
  }

  void addKeyValue(std::string key) {
    Result res;
    res.type = REQL_R_NULL;
    p_stack.end()->value.object.insert({key, res});
  }

  void addKeyValue(std::string key, bool value) {
    Result res;
    res.type = REQL_R_BOOL;
    res.value.boolean = value;
    p_stack.end()->value.object.insert({key, res});
  }

  void addKeyValue(std::string key, double value) {
    Result res;
    res.type = REQL_R_NUM;
    res.value.num = value;
    p_stack.end()->value.object.insert({key, res});
  }

  void addKeyValue(std::string key, std::string value) {
    Result res;
    res.type = REQL_R_NULL;
    p_stack.end()->value.object.insert({key, res});
  }

  void endObject() {
    end();
  }

  void startArray() {
    p_stack.push_back(Result());
    p_stack.end()->type = REQL_R_ARRAY;
    p_stack.end()->value.array = std::vector<Result>();
  }

  void addElement() {
    Result res;
    res.type = REQL_R_NULL;
    addElement(std::move(res));
  }

  void addElement(bool value) {
    Result res;
    res.type = REQL_R_BOOL;
    res.value.boolean = value;
    addElement(std::move(res));
  }

  void addElement(double value) {
    Result res;
    res.type = REQL_R_NUM;
    res.value.num = value;
    addElement(std::move(res));
  }

  void addElement(std::string value) {
    Result res;
    res.type = REQL_R_STR;
    res.value.string = value;
    addElement(std::move(res));
  }

  void endArray() {
    end();
  }

  void addElement(Result &&val) {
    if (p_stack.empty()) {
      p_result = std::move(val);
    } else {
      std::vector<Result> *array = &p_stack.end()->value.array;
      array->insert(array->end(), std::move(val));
    }
  }

  void end() {
    Result last = *p_stack.end();
    p_stack.pop_back();
    if (p_stack.empty()) {
      p_result = last;
    } else if (p_stack.end()->type == REQL_R_OBJECT) {
      std::string key = *p_keys.end();
      p_keys.pop_back();
      p_stack.end()->value.object.insert({key, last});
    } else {
      addElement(std::move(last));
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

  reql_conn_set_addr(data(), (char *)host.c_str());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const std::string &host, const std::uint16_t &port) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  reql_conn_set_addr(data(), (char *)host.c_str());
  reql_conn_set_port(data(), (char *)std::to_string(port).c_str());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const std::string &host, const std::uint16_t &port, const std::string &key) : conn(new ReQL_Conn_t) {
  reql_connection_init(data());

  if (key.size() > UINT32_MAX) {
  }

  std::uint32_t key_len = (std::uint32_t)key.size();

  reql_conn_set_addr(data(), (char *)host.c_str());
  reql_conn_set_port(data(), (char *)std::to_string(port).c_str());
  reql_conn_set_auth(data(), key_len, (char *)key.c_str());

  std::uint8_t buf[500];

  if (reql_connect(data(), buf, 500)) {
  }
}

Connection::Connection(const Connection &other) {
}

Connection::Connection(Connection &&other) {
  conn = std::move(other.conn);
}

Connection::~Connection() {
  reql_ensure_conn_close(data());
}

Connection &Connection::operator=(const Connection &other) {
  return *this;
}

Connection &Connection::operator=(Connection &&other) {
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

  ReQL kwargs;

  reql_run(cur.data(), p_query.data(), conn.data(), kwargs.data());

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
