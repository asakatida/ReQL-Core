/*
Copyright 2014 Adam Grandquist

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

#ifndef _REQL_HPP
#define _REQL_HPP

namespace ReQL {

class Cursor {
public:
  _ReQL_Cur_t *cur;

  Cursor();

  ~Cursor();

  bool isOpen();

  int close();
};

class Connection {
public:
  _ReQL_Conn_t *conn;

  Connection();
  Connection(std::string);
  Connection(std::string, std::uint16_t);
  Connection(std::string, std::uint16_t, std::string);

  ~Connection();

  bool isOpen();

  int close();
};

Connection connect();
Connection connect(std::string);
Connection connect(std::string, std::uint16_t);
Connection connect(std::string, std::uint16_t, std::string);

class Query : public AST {
public:
  Query() : AST() {};
  Query(_ReQL_AST_Function f, std::vector<Query> args, std::map<std::string, Query> kwargs) : AST(f, args, kwargs) {};
  explicit Query(_ReQL_Obj_t *val) : AST(val) {};
  Query(std::string val) : AST(val) {};
  Query(double val) : AST(val) {};
  Query(bool val) : AST(val) {};
  Query(std::vector<Query> val) : AST(val) {};
  Query(std::map<std::string, Query> val) : AST(val) {};

  Query(const Query &other) : AST(other) {};
  Query(const Query &&other) : AST(other) {};

  Query &operator=(const Query &other);
  Query &operator=(const Query &&other);

  Cursor run(Connection);
};

}

#endif
