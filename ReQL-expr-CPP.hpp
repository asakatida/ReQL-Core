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

#include <map>
#include <string>
#include <vector>

#ifndef _REQL_EXPR_CPP
#define _REQL_EXPR_CPP

class ReQL_expr {
public:
  struct _ReQL_Op_s *val;

  ReQL_expr();
  ReQL_expr(std::string);
  ReQL_expr(double);
  ReQL_expr(bool);
  ReQL_expr(std::vector<ReQL_expr>);
  ReQL_expr(std::map<std::string, ReQL_expr>);
};

ReQL_expr expr();
ReQL_expr expr(std::string);
ReQL_expr expr(double);
ReQL_expr expr(bool);
ReQL_expr expr(std::vector<ReQL_expr>);
ReQL_expr expr(std::map<std::string, ReQL_expr>);

#endif
