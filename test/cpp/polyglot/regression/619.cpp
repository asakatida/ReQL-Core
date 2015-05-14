// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Regression test for issue 191", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("self", 4);
    Result var1(src1);

    std::string src2("foo", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("self", 4);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("self", 4);
    Result var3(src3);

    double num4(1);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("self", 4);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("self", 4);
    Result var3(src3);

    std::map<std::string, Result> map4;

    std::string src5("self", 4);
    Result var5(src5);

    double num6(1);
    Result var6(num6);

    map4.insert({src5, var6});

    Result var4(map4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
