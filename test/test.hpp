// Copyright 2015 Adam Grandquist

#ifndef REQL_TEST_HPP_
#define REQL_TEST_HPP_

#include "./ReQL.hpp"

#include <string>

namespace ReQL {

std::string inspect(const Query &query);
std::string inspect(const ReQL_Obj_t *query);

}  // namespace ReQL

#endif  // REQL_TEST_HPP_
