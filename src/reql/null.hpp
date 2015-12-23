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

#ifndef REQL_REQL_NULL_HPP_
#define REQL_REQL_NULL_HPP_

#include <iostream>

namespace _ReQL {

template <class blank>
struct Null_Impl_t {};

typedef Null_Impl_t<void> Null_t;

template <class blank>
std::ostream &
operator <<(std::ostream &stream, const Null_Impl_t<blank> &) {
  return stream << "null";
}

}  // namespace _ReQL

#endif  // REQL_REQL_NULL_HPP_
