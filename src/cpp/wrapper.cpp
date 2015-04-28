/*
Copyright 2015 Adam Grandquist

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

#include "./cpp/wrapper.hpp"

namespace ReQL {

Wrapper::Wrapper(ReQL_Obj_t *obj) : std::unique_ptr<ReQL_Obj_t>(obj) {
  switch (reql_datum_type(obj)) {
    case REQL_R_ARRAY: {
      break;
    }
    case REQL_R_BOOL: {
      break;
    }
    case REQL_R_JSON: throw;
    case REQL_R_NULL: {
      break;
    }
    case REQL_R_NUM: {
      break;
    }
    case REQL_R_OBJECT: {
      break;
    }
    case REQL_R_REQL: {
      break;
    }
    case REQL_R_STR: {
      break;
    }
  }
}

Wrapper::~Wrapper() {}

}
