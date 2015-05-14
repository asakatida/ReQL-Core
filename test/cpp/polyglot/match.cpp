// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests for match", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("groups", 6);
    Result var1(src1);

    std::vector<Result> arr2(2);

    Result var3;

    arr2.insert(arr2.end(), var3);

    std::map<std::string, Result> map4;

    std::string src5("end", 3);
    Result var5(src5);

    double num6(5);
    Result var6(num6);

    map4.insert({src5, var6});

    std::string src7("start", 5);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map4.insert({src7, var8});

    std::string src9("str", 3);
    Result var9(src9);

    std::string src10("cde", 3);
    Result var10(src10);

    map4.insert({src9, var10});

    Result var4(map4);

    arr2.insert(arr2.end(), var4);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src11("end", 3);
    Result var11(src11);

    double num12(5);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("str", 3);
    Result var13(src13);

    std::string src14("bcde", 4);
    Result var14(src14);

    map0.insert({src13, var14});

    std::string src15("start", 5);
    Result var15(src15);

    double num16(1);
    Result var16(num16);

    map0.insert({src15, var16});

    Result var0(map0);
  }

  SECTION("test1") {
    Result var0;
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("groups", 6);
    Result var1(src1);

    std::vector<Result> arr2(2);

    Result var3;

    arr2.insert(arr2.end(), var3);

    std::map<std::string, Result> map4;

    std::string src5("end", 3);
    Result var5(src5);

    double num6(5);
    Result var6(num6);

    map4.insert({src5, var6});

    std::string src7("start", 5);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map4.insert({src7, var8});

    std::string src9("str", 3);
    Result var9(src9);

    std::string src10("cde", 3);
    Result var10(src10);

    map4.insert({src9, var10});

    Result var4(map4);

    arr2.insert(arr2.end(), var4);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src11("end", 3);
    Result var11(src11);

    double num12(5);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("str", 3);
    Result var13(src13);

    std::string src14("bcde", 4);
    Result var14(src14);

    map0.insert({src13, var14});

    std::string src15("start", 5);
    Result var15(src15);

    double num16(1);
    Result var16(num16);

    map0.insert({src15, var16});

    Result var0(map0);
  }

  SECTION("test3") {
    std::vector<Result> arr0(2);

    std::string src1("aca", 3);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("ada", 3);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(3);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test5") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::string src3("abc", 3);
    Result var3(src3);

    map1.insert({src2, var3});

    std::string src4("id", 2);
    Result var4(src4);

    double num5(0);
    Result var5(num5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    std::string src8("ab", 2);
    Result var8(src8);

    map6.insert({src7, var8});

    std::string src9("id", 2);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("a", 1);
    Result var12(src12);

    std::string src13("bc", 2);
    Result var13(src13);

    map11.insert({src12, var13});

    std::string src14("id", 2);
    Result var14(src14);

    double num15(2);
    Result var15(num15);

    map11.insert({src14, var15});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    Result var0(arr0);
  }

  SECTION("test6") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::string src3("abc", 3);
    Result var3(src3);

    map1.insert({src2, var3});

    std::string src4("id", 2);
    Result var4(src4);

    double num5(0);
    Result var5(num5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    std::string src8("ab", 2);
    Result var8(src8);

    map6.insert({src7, var8});

    std::string src9("id", 2);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test7") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::string src3("ab", 2);
    Result var3(src3);

    map1.insert({src2, var3});

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test8") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
