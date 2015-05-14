// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test pseudo literal strings in JSON.", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("b", 1);
    Result var3(src3);

    double num4(2);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
