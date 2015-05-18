// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Test basic time arithmetic", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("Sat May 30 23:34:00 1998", 24);
    Result var0(src0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("more", 4);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::string src3("Tue Jul 31 09:20:40 2001", 24);
    Result var3(src3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src4("stuff", 5);
    Result var4(src4);

    std::string src5("Sat May 30 23:34:00 1998", 24);
    Result var5(src5);

    map0.insert({src4, var5});

    Result var0(map0);
  }

  SECTION("test2") {
    std::vector<Result> arr0(3);

    std::string src1("Thu Mar 30 13:47:20 1995", 24);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("Sat May 30 23:34:00 1998", 24);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map3;

    std::string src4("stuff", 5);
    Result var4(src4);

    std::string src5("Tue Jul 31 09:20:40 2001", 24);
    Result var5(src5);

    map3.insert({src4, var5});

    Result var3(map3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("nested", 6);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("time", 4);
    Result var3(src3);

    std::string src4("Sat May 30 23:34:00 1998", 24);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::vector<Result> arr0(3);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    std::string src2("two", 3);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::vector<Result> arr3(3);

    std::string src4("a", 1);
    Result var4(src4);

    arr3.insert(arr3.end(), var4);

    std::string src5("Sat May 30 23:34:00 1998", 24);
    Result var5(src5);

    arr3.insert(arr3.end(), var5);

    double num6(3);
    Result var6(num6);

    arr3.insert(arr3.end(), var6);

    Result var3(arr3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test5") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test6") {
    double num0(-1);
    Result var0(num0);
  }

  SECTION("test7") {
    double num0(1.444);
    Result var0(num0);
  }

  SECTION("test8") {
    std::string src0("1970-01-01T00:00:01.444+00:00", 29);
    Result var0(src0);
  }

  SECTION("test9") {
    double num0(1.444);
    Result var0(num0);
  }

  SECTION("test10") {
    double num0(10000);
    Result var0(num0);
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

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test13") {
    double num0(253440000000);
    Result var0(num0);
  }

  SECTION("test14") {
    double num0(1400);
    Result var0(num0);
  }

  SECTION("test15") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test16") {
    double num0(-17990000000);
    Result var0(num0);
  }
}
