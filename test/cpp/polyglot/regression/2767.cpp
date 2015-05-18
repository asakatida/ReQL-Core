// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp 2767 -- Evaulate secondary index function with pristine env.", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(1);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    Types::array arr3(5);

    double num4(1);
    Query var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(2);
    Query var5(num5);

    arr3.insert(arr3.end(), var5);

    double num6(3);
    Query var6(num6);

    arr3.insert(arr3.end(), var6);

    double num7(4);
    Query var7(num7);

    arr3.insert(arr3.end(), var7);

    double num8(5);
    Query var8(num8);

    arr3.insert(arr3.end(), var8);

    Query var3(arr3);

    map1.insert({src2, var3});

    std::string src9("id", 2);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map1.insert({src9, var10});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test3") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    Types::array arr3(5);

    double num4(1);
    Query var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(2);
    Query var5(num5);

    arr3.insert(arr3.end(), var5);

    double num6(3);
    Query var6(num6);

    arr3.insert(arr3.end(), var6);

    double num7(4);
    Query var7(num7);

    arr3.insert(arr3.end(), var7);

    double num8(5);
    Query var8(num8);

    arr3.insert(arr3.end(), var8);

    Query var3(arr3);

    map1.insert({src2, var3});

    std::string src9("id", 2);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map1.insert({src9, var10});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test4") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    Types::array arr3(5);

    double num4(1);
    Query var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(2);
    Query var5(num5);

    arr3.insert(arr3.end(), var5);

    double num6(3);
    Query var6(num6);

    arr3.insert(arr3.end(), var6);

    double num7(4);
    Query var7(num7);

    arr3.insert(arr3.end(), var7);

    double num8(5);
    Query var8(num8);

    arr3.insert(arr3.end(), var8);

    Query var3(arr3);

    map1.insert({src2, var3});

    std::string src9("id", 2);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map1.insert({src9, var10});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }
}
