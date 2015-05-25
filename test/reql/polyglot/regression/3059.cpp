// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("c Use pseudotype name properly in `info` 315", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[15]);
    const uint8_t src0[] = "PTYPE<GEOMETRY>";
    reql_string_init(var0.get(), buf0.get(), 15);
    reql_string_append(var0.get(), src0, 15);
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[15]);
    const uint8_t src0[] = "PTYPE<GEOMETRY>";
    reql_string_init(var0.get(), buf0.get(), 15);
    reql_string_append(var0.get(), src0, 15);
  }
}
