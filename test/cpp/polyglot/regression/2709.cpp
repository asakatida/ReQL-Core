// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp 2709 -- Guarantee failed with [max_els >= min_els]", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("inserted", 8);
    Query var1(src1);

    double num2(999);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    double num0(999);
    Query var0(num0);
  }

  SECTION("test2") {
    double num0(999);
    Query var0(num0);
  }
}
