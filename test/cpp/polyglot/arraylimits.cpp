// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests array limit variations", "[cpp][ast]") {

  SECTION("test0") {
    Types::array arr0(8);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(1);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(1);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(1);
    Query var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(1);
    Query var6(num6);

    arr0.insert(arr0.end(), var6);

    double num7(1);
    Query var7(num7);

    arr0.insert(arr0.end(), var7);

    double num8(1);
    Query var8(num8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test8") {
    double num0(100001);
    Query var0(num0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    Query var0;
  }

  SECTION("test11") {
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

    double num6(1);
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

  SECTION("test12") {
    Types::object map0;

    std::string src1("array", 5);
    Query var1(src1);

    Types::array arr2(10);

    double num3(1);
    Query var3(num3);

    arr2.insert(arr2.end(), var3);

    double num4(2);
    Query var4(num4);

    arr2.insert(arr2.end(), var4);

    double num5(3);
    Query var5(num5);

    arr2.insert(arr2.end(), var5);

    double num6(4);
    Query var6(num6);

    arr2.insert(arr2.end(), var6);

    double num7(5);
    Query var7(num7);

    arr2.insert(arr2.end(), var7);

    double num8(6);
    Query var8(num8);

    arr2.insert(arr2.end(), var8);

    double num9(7);
    Query var9(num9);

    arr2.insert(arr2.end(), var9);

    double num10(8);
    Query var10(num10);

    arr2.insert(arr2.end(), var10);

    double num11(9);
    Query var11(num11);

    arr2.insert(arr2.end(), var11);

    double num12(10);
    Query var12(num12);

    arr2.insert(arr2.end(), var12);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src13("id", 2);
    Query var13(src13);

    double num14(1);
    Query var14(num14);

    map0.insert({src13, var14});

    Query var0(map0);
  }
}
