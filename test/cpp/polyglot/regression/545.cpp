// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp r.js inside reduce crashes server (#545)", "[cpp][ast]") {

  SECTION("test0") {
    Result var0;
  }

  SECTION("test1") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(3);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
