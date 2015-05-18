// Copyright 2015 Adam Grandquist

#ifndef REQL_TEST_HPP_
#define REQL_TEST_HPP_

#include "./catch.hpp"

#include "./ReQL.hpp"

namespace ReQL {

class ReQL_Conn_c : public _C::CTypes::connection {
public:
  ReQL_Conn_c();
  ~ReQL_Conn_c();
};

class ReQL_Cur_c : public _C::CTypes::cursor {
public:
  ReQL_Cur_c();
  ~ReQL_Cur_c();
};

class ReQL_Obj_c : public _C::CTypes::object {
public:
  ReQL_Obj_c();
  ~ReQL_Obj_c();
};

class ReQL_Res_c : public _C::ReQL_Obj_t {
public:
  ReQL_Res_c(const _C::ReQL_Obj_t &ptr);
  ReQL_Res_c(const _C::ReQL_Obj_t *ptr);
  ~ReQL_Res_c();
};

std::string inspect(const Query &query);
std::string inspect(const _C::ReQL_Obj_t *query);

}  // namespace ReQL

#endif  // REQL_TEST_HPP_
