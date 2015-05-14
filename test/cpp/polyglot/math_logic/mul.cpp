// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests for the basic usage of the multiplication operation", "[cpp][ast]") {

  SECTION("test0") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test1") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test2") {
    double num0(6.75);
    Result var0(num0);
  }

  SECTION("test3") {
    std::vector<Result> arr0(9);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(1);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(2);
    Result var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(3);
    Result var6(num6);

    arr0.insert(arr0.end(), var6);

    double num7(1);
    Result var7(num7);

    arr0.insert(arr0.end(), var7);

    double num8(2);
    Result var8(num8);

    arr0.insert(arr0.end(), var8);

    double num9(3);
    Result var9(num9);

    arr0.insert(arr0.end(), var9);

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
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
