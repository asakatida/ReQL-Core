// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Use pseudotype name properly in `info`", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("PTYPE<GEOMETRY>", 15);
    Query var0(src0);
  }

  SECTION("test1") {
    std::string src0("PTYPE<GEOMETRY>", 15);
    Query var0(src0);
  }
}
