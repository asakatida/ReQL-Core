// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests of nested arithmetic expressions", "[cpp][ast]") {

  SECTION("test0") {
    double num0(1);
    Query var0(num0);
  }
}
