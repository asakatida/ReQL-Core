// Copyright 2015 Adam Grandquist

#ifndef REQL_TEST_HPP_
#define REQL_TEST_HPP_

#include "./catch.hpp"

#include "./ReQL.hpp"

#include <string>

namespace ReQL {

class ReQL_Conn_c : public std::unique_ptr<ReQL_Conn_t> {
public:
  ReQL_Conn_c();
  ~ReQL_Conn_c();
};

class ReQL_Cur_c : public std::unique_ptr<ReQL_Cur_t> {
public:
  ReQL_Cur_c();
  ~ReQL_Cur_c();
};

class ReQL_Obj_c : public std::unique_ptr<ReQL_Obj_t> {
public:
  ReQL_Obj_c();
  ~ReQL_Obj_c();
};

class ReQL_Res_c : public ReQL_Obj_t {
public:
  ReQL_Res_c(const ReQL_Obj_t &ptr);
  ReQL_Res_c(const ReQL_Obj_t *ptr);
  ~ReQL_Res_c();
};

std::string inspect(const Query &query);
std::string inspect(const ReQL_Obj_t *query);

}  // namespace ReQL

#endif  // REQL_TEST_HPP_
