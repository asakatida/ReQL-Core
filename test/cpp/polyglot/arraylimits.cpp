// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

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

    double num8(1);
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

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("array", 5);
    Result var3(src3);

    std::vector<Result> arr4(10);

    double num5(1);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(2);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    double num7(3);
    Result var7(num7);

    arr4.insert(arr4.end(), var7);

    double num8(4);
    Result var8(num8);

    arr4.insert(arr4.end(), var8);

    double num9(5);
    Result var9(num9);

    arr4.insert(arr4.end(), var9);

    double num10(6);
    Result var10(num10);

    arr4.insert(arr4.end(), var10);

    double num11(7);
    Result var11(num11);

    arr4.insert(arr4.end(), var11);

    double num12(8);
    Result var12(num12);

    arr4.insert(arr4.end(), var12);

    double num13(9);
    Result var13(num13);

    arr4.insert(arr4.end(), var13);

    double num14(10);
    Result var14(num14);

    arr4.insert(arr4.end(), var14);

    Result var4(arr4);

    map0.insert({src3, var4});

    Result var0(map0);
  }
}
