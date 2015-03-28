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

#ifndef REQL_CONNECTION_HPP_
#define REQL_CONNECTION_HPP_

#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include "./cpp/ast.hpp"

namespace ReQL {

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
    ~Result();

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
    ReQL_Datum_t p_type;
    union JSON_Value {
      JSON_Value();
      explicit JSON_Value(const bool val);
      explicit JSON_Value(const double val);
      explicit JSON_Value(const std::string val);
      explicit JSON_Value(const std::map<std::string, Result> val);
      explicit JSON_Value(const std::vector<Result> val);

      void copy(const Result &other, const ReQL_Datum_t type);
      void move(Result &&other, const ReQL_Datum_t type);
      void release(const ReQL_Datum_t type);

      ~JSON_Value();

      std::unique_ptr<bool> p_boolean;
      std::unique_ptr<double> p_num;
      std::unique_ptr<std::map<std::string, Result>> p_object;
      std::unique_ptr<std::string> p_string;
      std::unique_ptr<std::vector<Result>> p_array;
    } p_value;
  };

  class Parser {
  public:
    Parser();
    virtual ~Parser();

    void parse(ReQL_Obj_t *val);
    void parse();

    virtual void assign(ReQL_Obj_t *val);

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

  private:
    ReQL_Obj_t *p_val;
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
    void next(Parser p);
    std::vector<Result> toVector();
    void toVector(Parser p);

    ReQL_Cur_t *data() const;

    void close();

  private:
    std::unique_ptr<ReQL_Cur_t> p_cur;
  };

  class Connection {
  public:
    Connection();
    explicit Connection(const std::string &host);
    Connection(const std::string &host, const std::uint16_t &port);
    Connection(const std::string &host, const std::uint16_t &port, const std::string &key);

    explicit Connection(const Connection &other);
    explicit Connection(Connection &&other);

    Connection &operator=(const Connection &other);
    Connection &operator=(Connection &&other);

    ~Connection();

    bool isOpen() const;

    ReQL_Conn_t *data() const;

    void close();

  private:
    std::unique_ptr<ReQL_Conn_t> p_conn;
  };

  class Query : public AST {
  public:
    Query();
    Query(const ReQL_AST_Function &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
    explicit Query(const std::string &val);
    explicit Query(const double &val);
    explicit Query(const bool &val);
    explicit Query(const std::vector<Query> &val);
    explicit Query(const std::map<std::string, Query> &val);
    
    Query(const Query &other);
    Query(const AST &other);
    Query(Query &&other);
    
    bool operator<(const Query &other) const;
    
    Query &operator=(const Query &other);
    Query &operator=(Query &&other);
    
    Cursor run(const Connection &conn) const;
  };
  
}  // namespace ReQL

#endif  // REQL_CONNECTION_HPP_
