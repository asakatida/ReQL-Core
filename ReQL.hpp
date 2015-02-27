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

#include "ReQL-ast.hpp"

#ifndef REQL_HPP
#define REQL_HPP

namespace ReQL {

class Result {
public:
  Result();
  Result(const Result &other);
  Result(Result &&other);
  ~Result();

  ReQL_Datum_t type;
  union JSON_Value {
    JSON_Value();

    void copy(const JSON_Value &other, ReQL_Datum_t type);
    void move(JSON_Value &&other, ReQL_Datum_t type);
    void release(ReQL_Datum_t type);

    ~JSON_Value();

    bool boolean;
    double num;
    std::map<std::string, Result> object;
    std::string string;
    std::vector<Result> array;
  } value;
};

class Parser {
public:
  void parse(ReQL_Obj_t *val);

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
  virtual void addNull() = 0;
  virtual void endArray() = 0;
};

class Cursor {
public:
  Cursor();

  Cursor(const Cursor &other);
  Cursor(Cursor &&other);

  Cursor &operator=(const Cursor &other);
  Cursor &operator=(Cursor &&other);

  ~Cursor();

  bool isOpen() const;

  Result next();
  void next(Parser &p);
  std::vector<Result> toVector();
  void toVector(Parser &p);

  ReQL_Cur_t *data() const;

  void close();

private:
  std::unique_ptr<ReQL_Cur_t> cur;
};

class Connection {
public:
  Connection();
  Connection(const std::string &host);
  Connection(const std::string &host, const std::uint16_t &port);
  Connection(const std::string &host, const std::uint16_t &port, const std::string &key);

  Connection(const Connection &other);
  Connection(Connection &&other);

  Connection &operator=(const Connection &other);
  Connection &operator=(Connection &&other);

  ~Connection();

  bool isOpen() const;

  ReQL_Conn_t *data() const;

  void close();

private:
  std::unique_ptr<ReQL_Conn_t> conn;
};

class Query : public AST {
public:
  Query() : AST() {};
  Query(const ReQL_AST_Function &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) : AST(f, args, kwargs) {};
  Query(const std::string &val) : AST(val) {};
  Query(const double &val) : AST(val) {};
  Query(const bool &val) : AST(val) {};
  Query(const std::vector<Query> &val) : AST(val) {};
  Query(const std::map<std::string, Query> &val) : AST(val) {};

  Query(const Query &other) : AST(other) {};
  Query(Query &&other) : AST(std::move(other)) {};

  bool operator<(const Query &other) const;

  Query &operator=(const Query &other);
  Query &operator=(Query &&other);

  Cursor run(const Connection &conn) const;
};

}

#endif
