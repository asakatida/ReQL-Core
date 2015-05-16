// Copyright 2015 Adam Grandquist

#ifndef REQL_TEST_HPP_
#define REQL_TEST_HPP_

#include "./catch.hpp"

#include "./ReQL.hpp"

#include <string>

namespace ReQL {

class ReQL_Obj_c : public ReQL_Obj_t {
public:
  ReQL_Obj_c(const ReQL_Obj_t &ptr);
  ReQL_Obj_c(const ReQL_Obj_t *ptr);
  ~ReQL_Obj_c();
};

std::string inspect(const Query &query);
std::string inspect(const ReQL_Obj_t *query);

}  // namespace ReQL

#endif  // REQL_TEST_HPP_
