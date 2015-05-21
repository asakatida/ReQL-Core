// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test empty polygon special cases", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 0);
  }
}
