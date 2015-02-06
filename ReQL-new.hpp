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

namespace ReQL {
extern "C" {
#include "ReQL.h"
}
}

#ifndef _REQL_NEW_CPP
#define _REQL_NEW_CPP

namespace ReQL {

class ReQL {
public:
  ReQL();
  ReQL(_ReQL_AST_Function f, std::vector<ReQL> args, std::map<std::string, ReQL> kwargs);
  ReQL(std::string val);
  ReQL(double val);
  ReQL(bool val);
  ReQL(std::vector<ReQL> val);
  ReQL(std::map<std::string, ReQL> val);

  ReQL(const ReQL &other);
  ReQL(const ReQL &&other);

  ReQL &operator=(const ReQL &other);
  ReQL &operator=(const ReQL &&other);

  ~ReQL();
  
private:
  _ReQL_Pair_t *object;
  _ReQL_Obj_t **array;
  _ReQL_Obj_t *query;
  _ReQL_Obj_t *args;
  _ReQL_Obj_t *kwargs;
};

}

#endif
