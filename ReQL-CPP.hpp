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

#include "ReQL-ast-CPP.hpp"

#ifndef _REQL_HPP
#define _REQL_HPP

namespace ReQL {

class Connection {
public:
  struct _ReQL_Conn_s *conn;

  Connection();
  Connection(std::string);
  Connection(std::string, std::uint16_t);
  Connection(std::string, std::uint16_t, std::string);

  int close();
};

Connection connect();
Connection connect(std::string);
Connection connect(std::string, std::uint16_t);
Connection connect(std::string, std::uint16_t, std::string);

class Query : public AST {
public:
  Query() : AST() {};
  explicit Query(std::string val) : AST(val) {};
  explicit Query(double val) : AST(val) {};
  explicit Query(bool val) : AST(val) {};
  explicit Query(std::vector<Query> val) : AST(val) {};
  explicit Query(std::map<std::string, Query> val) : AST(val) {};
};

}

#endif
