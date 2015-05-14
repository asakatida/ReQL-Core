// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests for match", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("start", 5);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("end", 3);
    Result var3(src3);

    double num4(5);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("groups", 6);
    Result var5(src5);

    std::vector<Result> arr6(2);

    Result var7;

    arr6.insert(arr6.end(), var7);

    std::map<std::string, Result> map8;

    std::string src9("start", 5);
    Result var9(src9);

    double num10(2);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("end", 3);
    Result var11(src11);

    double num12(5);
    Result var12(num12);

    map8.insert({src11, var12});

    std::string src13("str", 3);
    Result var13(src13);

    std::string src14("cde", 3);
    Result var14(src14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    map0.insert({src5, var6});

    std::string src15("str", 3);
    Result var15(src15);

    std::string src16("bcde", 4);
    Result var16(src16);

    map0.insert({src15, var16});

    Result var0(map0);
  }

  SECTION("test1") {
    Result var0;
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("start", 5);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("end", 3);
    Result var3(src3);

    double num4(5);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("groups", 6);
    Result var5(src5);

    std::vector<Result> arr6(2);

    Result var7;

    arr6.insert(arr6.end(), var7);

    std::map<std::string, Result> map8;

    std::string src9("start", 5);
    Result var9(src9);

    double num10(2);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("end", 3);
    Result var11(src11);

    double num12(5);
    Result var12(num12);

    map8.insert({src11, var12});

    std::string src13("str", 3);
    Result var13(src13);

    std::string src14("cde", 3);
    Result var14(src14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    map0.insert({src5, var6});

    std::string src15("str", 3);
    Result var15(src15);

    std::string src16("bcde", 4);
    Result var16(src16);

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

    std::string src3("skipped", 7);
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

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test5") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("id", 2);
    Result var2(src2);

    double num3(0);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("a", 1);
    Result var4(src4);

    std::string src5("abc", 3);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("id", 2);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("a", 1);
    Result var9(src9);

    std::string src10("ab", 2);
    Result var10(src10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("id", 2);
    Result var12(src12);

    double num13(2);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("a", 1);
    Result var14(src14);

    std::string src15("bc", 2);
    Result var15(src15);

    map11.insert({src14, var15});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    Result var0(arr0);
  }

  SECTION("test6") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("id", 2);
    Result var2(src2);

    double num3(0);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("a", 1);
    Result var4(src4);

    std::string src5("abc", 3);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("id", 2);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("a", 1);
    Result var9(src9);

    std::string src10("ab", 2);
    Result var10(src10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test7") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("id", 2);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("a", 1);
    Result var4(src4);

    std::string src5("ab", 2);
    Result var5(src5);

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
