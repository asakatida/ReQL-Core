// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests for match", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("end", 3);
    Query var1(src1);

    double num2(5);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("groups", 6);
    Query var3(src3);

    Types::array arr4(2);

    Query var5;

    arr4.insert(arr4.end(), var5);

    Types::object map6;

    std::string src7("end", 3);
    Query var7(src7);

    double num8(5);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("start", 5);
    Query var9(src9);

    double num10(2);
    Query var10(num10);

    map6.insert({src9, var10});

    std::string src11("str", 3);
    Query var11(src11);

    std::string src12("cde", 3);
    Query var12(src12);

    map6.insert({src11, var12});

    Query var6(map6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src13("start", 5);
    Query var13(src13);

    double num14(1);
    Query var14(num14);

    map0.insert({src13, var14});

    std::string src15("str", 3);
    Query var15(src15);

    std::string src16("bcde", 4);
    Query var16(src16);

    map0.insert({src15, var16});

    Query var0(map0);
  }

  SECTION("test1") {
    Query var0;
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("end", 3);
    Query var1(src1);

    double num2(5);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("groups", 6);
    Query var3(src3);

    Types::array arr4(2);

    Query var5;

    arr4.insert(arr4.end(), var5);

    Types::object map6;

    std::string src7("end", 3);
    Query var7(src7);

    double num8(5);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("start", 5);
    Query var9(src9);

    double num10(2);
    Query var10(num10);

    map6.insert({src9, var10});

    std::string src11("str", 3);
    Query var11(src11);

    std::string src12("cde", 3);
    Query var12(src12);

    map6.insert({src11, var12});

    Query var6(map6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src13("start", 5);
    Query var13(src13);

    double num14(1);
    Query var14(num14);

    map0.insert({src13, var14});

    std::string src15("str", 3);
    Query var15(src15);

    std::string src16("bcde", 4);
    Query var16(src16);

    map0.insert({src15, var16});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::array arr0(2);

    std::string src1("aca", 3);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("ada", 3);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(3);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test5") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    std::string src3("abc", 3);
    Query var3(src3);

    map1.insert({src2, var3});

    std::string src4("id", 2);
    Query var4(src4);

    double num5(0);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    std::string src8("ab", 2);
    Query var8(src8);

    map6.insert({src7, var8});

    std::string src9("id", 2);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("a", 1);
    Query var12(src12);

    std::string src13("bc", 2);
    Query var13(src13);

    map11.insert({src12, var13});

    std::string src14("id", 2);
    Query var14(src14);

    double num15(2);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Query var0(arr0);
  }

  SECTION("test6") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    std::string src3("abc", 3);
    Query var3(src3);

    map1.insert({src2, var3});

    std::string src4("id", 2);
    Query var4(src4);

    double num5(0);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    std::string src8("ab", 2);
    Query var8(src8);

    map6.insert({src7, var8});

    std::string src9("id", 2);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test7") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    std::string src3("ab", 2);
    Query var3(src3);

    map1.insert({src2, var3});

    std::string src4("id", 2);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test8") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
