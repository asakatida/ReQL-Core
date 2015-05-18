// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests of conversion to and from the RQL null type", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    reql_null_init(var0.get());
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[4]);
    const uint8_t src0[] = "NULL";
    reql_string_init(var0.get(), buf0.get(), 4);
    reql_string_append(var0.get(), src0, 4);
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[4]);
    const uint8_t src0[] = "null";
    reql_string_init(var0.get(), buf0.get(), 4);
    reql_string_append(var0.get(), src0, 4);
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    reql_null_init(var0.get());
  }
}
