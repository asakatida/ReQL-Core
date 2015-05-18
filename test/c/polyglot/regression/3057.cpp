// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test empty polygon special cases", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }
}
