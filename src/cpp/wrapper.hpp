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

#ifndef REQL_CPP_WRAPPER_HPP_
#define REQL_CPP_WRAPPER_HPP_

#include <map>
#include <string>
#include <vector>

namespace ReQL {
extern "C" {

#include "./ReQL.h"

}

class Wrapper : public std::unique_ptr<ReQL_Obj_t> {
public:
  Wrapper(ReQL_Obj_t *obj);
  Wrapper(const Wrapper &other);
  Wrapper(Wrapper &&other);
  virtual ~Wrapper();

private:
  std::vector<Wrapper> p_array;
};

}  // namespace ReQL

#endif  // REQL_CPP_WRAPPER_HPP_
