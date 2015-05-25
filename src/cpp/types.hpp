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

#ifndef REQL_CPP_TYPES_HPP_
#define REQL_CPP_TYPES_HPP_

#include <map>
#include <string>
#include <vector>

namespace ReQL {

namespace _C {

#include "./reql/core.h"

namespace CTypes {

typedef std::unique_ptr<ReQL_Byte[]> string;
typedef std::unique_ptr<ReQL_Obj_t> object;
typedef std::unique_ptr<ReQL_Obj_t*[]> array;
typedef std::unique_ptr<ReQL_Pair_t[]> pairs;
typedef std::unique_ptr<ReQL_Conn_t> connection;
typedef std::unique_ptr<ReQL_Cur_t> cursor;

}  // namespace CTypes
}  // namespace _C

class Query;

namespace Types {

typedef std::string string;
typedef std::vector<Query> array;
typedef std::map<string, Query> object;

}  // namespace Types
}  // namespace ReQL

#endif  // REQL_CPP_TYPES_HPP_
