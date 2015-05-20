// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests of conversion to and from the RQL null type", "[cpp][ast]") {

  SECTION("test0") {
    Query var0;
  }

  SECTION("test1") {
    std::string src0("NULL", 4);
    Query var0(src0);
  }

  SECTION("test2") {
    std::string src0("null", 4);
    Query var0(src0);
  }

  SECTION("test3") {
    Query var0;
  }
}
