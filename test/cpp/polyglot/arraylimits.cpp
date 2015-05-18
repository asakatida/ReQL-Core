// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests array limit variations", "[cpp][ast]") {

  SECTION("test0") {
    std::vector<Result> arr0(8);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(1);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(1);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(1);
    Result var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(1);
    Result var6(num6);

    arr0.insert(arr0.end(), var6);

    double num7(1);
    Result var7(num7);

    arr0.insert(arr0.end(), var7);

    double num8(1);
    Result var8(num8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

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

  SECTION("test8") {
    double num0(100001);
    Result var0(num0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test10") {
    Result var0;
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("deleted", 7);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Result var5(src5);

    double num6(1);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("array", 5);
    Result var1(src1);

    std::vector<Result> arr2(10);

    double num3(1);
    Result var3(num3);

    arr2.insert(arr2.end(), var3);

    double num4(2);
    Result var4(num4);

    arr2.insert(arr2.end(), var4);

    double num5(3);
    Result var5(num5);

    arr2.insert(arr2.end(), var5);

    double num6(4);
    Result var6(num6);

    arr2.insert(arr2.end(), var6);

    double num7(5);
    Result var7(num7);

    arr2.insert(arr2.end(), var7);

    double num8(6);
    Result var8(num8);

    arr2.insert(arr2.end(), var8);

    double num9(7);
    Result var9(num9);

    arr2.insert(arr2.end(), var9);

    double num10(8);
    Result var10(num10);

    arr2.insert(arr2.end(), var10);

    double num11(9);
    Result var11(num11);

    arr2.insert(arr2.end(), var11);

    double num12(10);
    Result var12(num12);

    arr2.insert(arr2.end(), var12);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src13("id", 2);
    Result var13(src13);

    double num14(1);
    Result var14(num14);

    map0.insert({src13, var14});

    Result var0(map0);
  }
}
