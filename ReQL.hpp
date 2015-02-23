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

class Cursor {
public:
  Cursor();

  Cursor(const Cursor &other);
  Cursor(Cursor &&other);

  Cursor &operator=(const Cursor &other);
  Cursor &operator=(Cursor &&other);

  ~Cursor();

  bool isOpen() const;

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
