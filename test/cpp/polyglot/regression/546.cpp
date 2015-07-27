// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Regression tests for issue 218", "[cpp][ast]") {

  SECTION("test0") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test1") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test2") {
    double num0(1);
    Query var0(num0);
  }
}
