// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp r.js inside reduce crashes server (#545)", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
