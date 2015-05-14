// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests the RQL `map` function", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("STREAM", 6);
    Result var0(src0);
  }

  SECTION("test1") {
    std::string src0("STREAM", 6);
    Result var0(src0);
  }

  SECTION("test2") {
    std::string src0("ARRAY", 5);
    Result var0(src0);
  }

  SECTION("test3") {
    std::vector<Result> arr0(3);

    double num1(0);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(0);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(0);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test4") {
    std::vector<Result> arr0(3);

    double num1(0);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(0);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(0);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test5") {
    std::vector<Result> arr0(1);

    std::vector<Result> arr1(1);

    double num2(1);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test6") {
    std::vector<Result> arr0(1);

    std::vector<Result> arr1(2);

    double num2(1);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test7") {
    std::vector<Result> arr0(1);

    std::vector<Result> arr1(3);

    double num2(1);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    double num4(1);
    Result var4(num4);

    arr1.insert(arr1.end(), var4);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
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

  SECTION("test10") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test11") {
    std::vector<Result> arr0(2);

    std::vector<Result> arr1(2);

    double num2(1);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    double num5(2);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(2);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test12") {
    std::vector<Result> arr0(2);

    std::vector<Result> arr1(2);

    double num2(0);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(0);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    double num5(1);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(1);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test13") {
    std::vector<Result> arr0(4);

    std::vector<Result> arr1(2);

    double num2(0);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    double num5(1);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(2);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Result> arr7(2);

    double num8(2);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(3);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr0.insert(arr0.end(), var7);

    std::vector<Result> arr10(2);

    double num11(3);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(4);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr0.insert(arr0.end(), var10);

    Result var0(arr0);
  }

  SECTION("test14") {
    std::vector<Result> arr0(3);

    std::vector<Result> arr1(2);

    double num2(0);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(0);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    double num5(1);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(1);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Result> arr7(2);

    double num8(2);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(2);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test15") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test17") {
    std::vector<Result> arr0(3);

    std::vector<Result> arr1(1);

    double num2(0);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr3(1);

    double num4(1);
    Result var4(num4);

    arr3.insert(arr3.end(), var4);

    Result var3(arr3);

    arr0.insert(arr0.end(), var3);

    std::vector<Result> arr5(1);

    double num6(2);
    Result var6(num6);

    arr5.insert(arr5.end(), var6);

    Result var5(arr5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test18") {
    std::vector<Result> arr0(3);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test19") {
    std::vector<Result> arr0(3);

    std::vector<Result> arr1(2);

    double num2(0);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(0);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    double num5(1);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(1);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Result> arr7(2);

    double num8(2);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(2);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }
}
