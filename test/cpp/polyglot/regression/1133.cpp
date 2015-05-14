// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Regression tests for issue", "[cpp][ast]") {

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    std::map<std::string, Result> map4;

    std::string src5("a", 1);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("a", 1);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("a", 1);
    Result var11(src11);

    std::map<std::string, Result> map12;

    std::string src13("a", 1);
    Result var13(src13);

    std::map<std::string, Result> map14;
    Result var14(map14);

    map12.insert({src13, var14});

    Result var12(map12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    Result var8(map8);

    map6.insert({src7, var8});

    Result var6(map6);

    map4.insert({src5, var6});

    Result var4(map4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
