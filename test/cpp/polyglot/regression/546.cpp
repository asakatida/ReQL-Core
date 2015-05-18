// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Regression tests for issue 183", "[cpp][ast]") {

  SECTION("test0") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test1") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test2") {
    double num0(1);
    Result var0(num0);
  }
}
