// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests the RQL `map` function", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("STREAM", 6);
    Query var0(src0);
  }

  SECTION("test1") {
    std::string src0("STREAM", 6);
    Query var0(src0);
  }

  SECTION("test2") {
    std::string src0("ARRAY", 5);
    Query var0(src0);
  }

  SECTION("test3") {
    std::vector<Query> arr0(3);

    double num1(0);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(0);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(0);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test4") {
    std::vector<Query> arr0(3);

    double num1(0);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(0);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(0);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test5") {
    std::vector<Query> arr0(1);

    std::vector<Query> arr1(1);

    double num2(1);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test6") {
    std::vector<Query> arr0(1);

    std::vector<Query> arr1(2);

    double num2(1);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test7") {
    std::vector<Query> arr0(1);

    std::vector<Query> arr1(3);

    double num2(1);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    double num4(1);
    Query var4(num4);

    arr1.insert(arr1.end(), var4);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test8") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    std::vector<Query> arr0;
    Query var0(arr0);
  }

  SECTION("test11") {
    std::vector<Query> arr0(2);

    std::vector<Query> arr1(2);

    double num2(1);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Query> arr4(2);

    double num5(2);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(2);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test12") {
    std::vector<Query> arr0(2);

    std::vector<Query> arr1(2);

    double num2(0);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(0);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Query> arr4(2);

    double num5(1);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(1);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test13") {
    std::vector<Query> arr0(4);

    std::vector<Query> arr1(2);

    double num2(0);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Query> arr4(2);

    double num5(1);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(2);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Query> arr7(2);

    double num8(2);
    Query var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(3);
    Query var9(num9);

    arr7.insert(arr7.end(), var9);

    Query var7(arr7);

    arr0.insert(arr0.end(), var7);

    std::vector<Query> arr10(2);

    double num11(3);
    Query var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(4);
    Query var12(num12);

    arr10.insert(arr10.end(), var12);

    Query var10(arr10);

    arr0.insert(arr0.end(), var10);

    Query var0(arr0);
  }

  SECTION("test14") {
    std::vector<Query> arr0(3);

    std::vector<Query> arr1(2);

    double num2(0);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(0);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Query> arr4(2);

    double num5(1);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(1);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Query> arr7(2);

    double num8(2);
    Query var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(2);
    Query var9(num9);

    arr7.insert(arr7.end(), var9);

    Query var7(arr7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test15") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test17") {
    std::vector<Query> arr0(3);

    std::vector<Query> arr1(1);

    double num2(0);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Query> arr3(1);

    double num4(1);
    Query var4(num4);

    arr3.insert(arr3.end(), var4);

    Query var3(arr3);

    arr0.insert(arr0.end(), var3);

    std::vector<Query> arr5(1);

    double num6(2);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    Query var5(arr5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test18") {
    std::vector<Query> arr0(3);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test19") {
    std::vector<Query> arr0(3);

    std::vector<Query> arr1(2);

    double num2(0);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(0);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Query> arr4(2);

    double num5(1);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(1);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Query> arr7(2);

    double num8(2);
    Query var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(2);
    Query var9(num9);

    arr7.insert(arr7.end(), var9);

    Query var7(arr7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }
}
