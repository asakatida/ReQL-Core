// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Regression tests for issue", "[cpp][ast]") {

  SECTION("test3") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    std::map<std::string, Query> map4;

    std::string src5("a", 1);
    Query var5(src5);

    std::map<std::string, Query> map6;

    std::string src7("a", 1);
    Query var7(src7);

    std::map<std::string, Query> map8;

    std::string src9("a", 1);
    Query var9(src9);

    std::map<std::string, Query> map10;

    std::string src11("a", 1);
    Query var11(src11);

    std::map<std::string, Query> map12;

    std::string src13("a", 1);
    Query var13(src13);

    std::map<std::string, Query> map14;
    Query var14(map14);

    map12.insert({src13, var14});

    Query var12(map12);

    map10.insert({src11, var12});

    Query var10(map10);

    map8.insert({src9, var10});

    Query var8(map8);

    map6.insert({src7, var8});

    Query var6(map6);

    map4.insert({src5, var6});

    Query var4(map4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
