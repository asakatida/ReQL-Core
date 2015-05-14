// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp 2767 -- Evaulate secondary index function with pristine env.", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("deleted", 7);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Result var5(src5);

    double num6(1);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Result var7(src7);

    double num8(0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Result var9(src9);

    double num10(0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Result var11(src11);

    double num12(0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test2") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::vector<Result> arr3(5);

    double num4(1);
    Result var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(2);
    Result var5(num5);

    arr3.insert(arr3.end(), var5);

    double num6(3);
    Result var6(num6);

    arr3.insert(arr3.end(), var6);

    double num7(4);
    Result var7(num7);

    arr3.insert(arr3.end(), var7);

    double num8(5);
    Result var8(num8);

    arr3.insert(arr3.end(), var8);

    Result var3(arr3);

    map1.insert({src2, var3});

    std::string src9("id", 2);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map1.insert({src9, var10});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test3") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::vector<Result> arr3(5);

    double num4(1);
    Result var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(2);
    Result var5(num5);

    arr3.insert(arr3.end(), var5);

    double num6(3);
    Result var6(num6);

    arr3.insert(arr3.end(), var6);

    double num7(4);
    Result var7(num7);

    arr3.insert(arr3.end(), var7);

    double num8(5);
    Result var8(num8);

    arr3.insert(arr3.end(), var8);

    Result var3(arr3);

    map1.insert({src2, var3});

    std::string src9("id", 2);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map1.insert({src9, var10});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test4") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::vector<Result> arr3(5);

    double num4(1);
    Result var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(2);
    Result var5(num5);

    arr3.insert(arr3.end(), var5);

    double num6(3);
    Result var6(num6);

    arr3.insert(arr3.end(), var6);

    double num7(4);
    Result var7(num7);

    arr3.insert(arr3.end(), var7);

    double num8(5);
    Result var8(num8);

    arr3.insert(arr3.end(), var8);

    Result var3(arr3);

    map1.insert({src2, var3});

    std::string src9("id", 2);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map1.insert({src9, var10});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }
}
