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
  Connection(std::string, std::string);
  Connection(std::string, std::string, std::string);

  int close();
};

Connection connect();
Connection connect(std::string);
Connection connect(std::string, std::string);
Connection connect(std::string, std::string, std::string);

class Query : public AST {
};

}

#endif
