// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests of conversion to and from the RQL null type", "[cpp][ast]") {

  SECTION("test0") {
    Result var0;
  }

  SECTION("test1") {
    std::string src0("NULL", 4);
    Result var0(src0);
  }

  SECTION("test2") {
    std::string src0("None", 4);
    Result var0(src0);
  }

  SECTION("test3") {
    Result var0;
  }
}
