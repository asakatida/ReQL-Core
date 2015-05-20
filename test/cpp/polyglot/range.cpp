// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests RQL range generation", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("STREAM", 6);
    Query var0(src0);
  }

  SECTION("test1") {
    Types::array arr0(4);

    double num1(0);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(2);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(3);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test2") {
    Types::array arr0(4);

    double num1(0);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(2);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(3);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test3") {
    Types::array arr0(3);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test4") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test5") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test6") {
    Types::array arr0(3);

    double num1(-5);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(-4);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(-3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test7") {
    Types::array arr0(7);

    double num1(-5);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(-4);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(-3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(-2);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(-1);
    Query var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(0);
    Query var6(num6);

    arr0.insert(arr0.end(), var6);

    double num7(1);
    Query var7(num7);

    arr0.insert(arr0.end(), var7);

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

    std::string src2("err_regex", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test11") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err_regex", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test12") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err_regex", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test13") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test14") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test15") {
    double num0(4);
    Query var0(num0);
  }
}
