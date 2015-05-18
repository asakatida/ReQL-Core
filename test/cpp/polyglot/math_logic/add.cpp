// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests for basic usage of the add operation", "[cpp][ast]") {

  SECTION("test0") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test1") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test2") {
    double num0(10.25);
    Query var0(num0);
  }

  SECTION("test3") {
    std::string src0("", 0);
    Query var0(src0);
  }

  SECTION("test4") {
    std::string src0("abcdef", 6);
    Query var0(src0);
  }

  SECTION("test5") {
    Types::array arr0(8);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(5);
    Query var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(6);
    Query var6(num6);

    arr0.insert(arr0.end(), var6);

    double num7(7);
    Query var7(num7);

    arr0.insert(arr0.end(), var7);

    double num8(8);
    Query var8(num8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test8") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
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

  SECTION("test10") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
