// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test basic time arithmetic", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("Sat May 30 23:34:00 1998", 24);
    Query var0(src0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("more", 4);
    Query var1(src1);

    Types::array arr2(1);

    std::string src3("Tue Jul 31 09:20:40 2001", 24);
    Query var3(src3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src4("stuff", 5);
    Query var4(src4);

    std::string src5("Sat May 30 23:34:00 1998", 24);
    Query var5(src5);

    map0.insert({src4, var5});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::array arr0(3);

    std::string src1("Thu Mar 30 13:47:20 1995", 24);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("Sat May 30 23:34:00 1998", 24);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Types::object map3;

    std::string src4("stuff", 5);
    Query var4(src4);

    std::string src5("Tue Jul 31 09:20:40 2001", 24);
    Query var5(src5);

    map3.insert({src4, var5});

    Query var3(map3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("nested", 6);
    Query var1(src1);

    Types::object map2;

    std::string src3("time", 4);
    Query var3(src3);

    std::string src4("Sat May 30 23:34:00 1998", 24);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::array arr0(3);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    std::string src2("two", 3);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Types::array arr3(3);

    std::string src4("a", 1);
    Query var4(src4);

    arr3.insert(arr3.end(), var4);

    std::string src5("Sat May 30 23:34:00 1998", 24);
    Query var5(src5);

    arr3.insert(arr3.end(), var5);

    double num6(3);
    Query var6(num6);

    arr3.insert(arr3.end(), var6);

    Query var3(arr3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test5") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test6") {
    double num0(-1);
    Query var0(num0);
  }

  SECTION("test7") {
    double num0(1.444);
    Query var0(num0);
  }

  SECTION("test8") {
    std::string src0("1970-01-01T00:00:01.444+00:00", 29);
    Query var0(src0);
  }

  SECTION("test9") {
    double num0(1.444);
    Query var0(num0);
  }

  SECTION("test10") {
    double num0(10000);
    Query var0(num0);
  }

  SECTION("test11") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test12") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test13") {
    double num0(253440000000);
    Query var0(num0);
  }

  SECTION("test14") {
    double num0(1400);
    Query var0(num0);
  }

  SECTION("test15") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    double num0(-17990000000);
    Query var0(num0);
  }
}
