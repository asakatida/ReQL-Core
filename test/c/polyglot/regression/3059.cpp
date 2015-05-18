// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Use pseudotype name properly in `info`", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[15]);
    const uint8_t src0[] = "PTYPE<GEOMETRY>";
    reql_string_init(var0.get(), buf0.get(), 15);
    reql_string_append(var0.get(), src0, 15);
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[15]);
    const uint8_t src0[] = "PTYPE<GEOMETRY>";
    reql_string_init(var0.get(), buf0.get(), 15);
    reql_string_append(var0.get(), src0, 15);
  }
}
