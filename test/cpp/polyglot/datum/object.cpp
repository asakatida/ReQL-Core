// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests conversion to and from the RQL object type", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;
    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("b", 1);
    Result var3(src3);

    std::vector<Result> arr4(3);

    std::map<std::string, Result> map5;

    std::string src6("c", 1);
    Result var6(src6);

    double num7(2);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    arr4.insert(arr4.end(), var5);

    std::string src8("a", 1);
    Result var8(src8);

    arr4.insert(arr4.end(), var8);

    double num9(4);
    Result var9(num9);

    arr4.insert(arr4.end(), var9);

    Result var4(arr4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    std::string src0("OBJECT", 6);
    Result var0(src0);
  }

  SECTION("test6") {
    std::string src0("{\n\t\"a\":\t1\n}", 17);
    Result var0(src0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test8") {
    std::vector<Result> arr0(1);

    std::vector<Result> arr1(2);

    std::string src2("a", 1);
    Result var2(src2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err_regex", 9);
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

  SECTION("test13") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test15") {
    std::map<std::string, Result> map0;
    Result var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Result var3(src3);

    double num4(2);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test17") {
    std::map<std::string, Result> map0;

    std::string src1("cd", 2);
    Result var1(src1);

    double num2(3);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test19") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test20") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test21") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
