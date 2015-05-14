// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests RQL range generation", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("STREAM", 6);
    Result var0(src0);
  }

  SECTION("test1") {
    std::vector<Result> arr0(4);

    double num1(0);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(2);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(3);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test2") {
    std::vector<Result> arr0(4);

    double num1(0);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(2);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(3);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test3") {
    std::vector<Result> arr0(3);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test4") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test5") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test6") {
    std::vector<Result> arr0(3);

    double num1(-5);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(-4);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(-3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test7") {
    std::vector<Result> arr0(7);

    double num1(-5);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(-4);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(-3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(-2);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(-1);
    Result var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(0);
    Result var6(num6);

    arr0.insert(arr0.end(), var6);

    double num7(1);
    Result var7(num7);

    arr0.insert(arr0.end(), var7);

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

    std::string src2("err_regex", 9);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err_regex", 9);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err_regex", 9);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test13") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test14") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test15") {
    double num0(4);
    Result var0(num0);
  }
}
