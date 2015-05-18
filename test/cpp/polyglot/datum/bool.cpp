// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests of conversion to and from the RQL bool type", "[cpp][ast]") {

  SECTION("test0") {
    Query var0(true);
  }

  SECTION("test1") {
    Query var0(false);
  }

  SECTION("test2") {
    std::string src0("BOOL", 4);
    Query var0(src0);
  }

  SECTION("test3") {
    std::string src0("true", 4);
    Query var0(src0);
  }

  SECTION("test4") {
    Query var0(true);
  }
}
