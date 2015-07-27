// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test basic timezone manipulation", "[cpp][ast]") {

  SECTION("test14") {
    Types::array arr0(3);

    Types::array arr1(2);

    std::string src2("+00:00", 6);
    Query var2(src2);

    arr1.insert(arr1.end(), var2);

    double num3(29);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Types::array arr4(2);

    std::string src5("+00:00", 6);
    Query var5(src5);

    arr4.insert(arr4.end(), var5);

    double num6(29);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    Types::array arr7(2);

    std::string src8("+00:00", 6);
    Query var8(src8);

    arr7.insert(arr7.end(), var8);

    double num9(29);
    Query var9(num9);

    arr7.insert(arr7.end(), var9);

    Query var7(arr7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test15") {
    Types::array arr0(3);

    Types::array arr1(2);

    std::string src2("-00:59", 6);
    Query var2(src2);

    arr1.insert(arr1.end(), var2);

    double num3(29);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Types::array arr4(2);

    std::string src5("-01:00", 6);
    Query var5(src5);

    arr4.insert(arr4.end(), var5);

    double num6(29);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    Types::array arr7(2);

    std::string src8("-01:01", 6);
    Query var8(src8);

    arr7.insert(arr7.end(), var8);

    double num9(29);
    Query var9(num9);

    arr7.insert(arr7.end(), var9);

    Query var7(arr7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test16") {
    Types::array arr0(3);

    Types::array arr1(2);

    std::string src2("+00:59", 6);
    Query var2(src2);

    arr1.insert(arr1.end(), var2);

    double num3(30);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Types::array arr4(2);

    std::string src5("+01:00", 6);
    Query var5(src5);

    arr4.insert(arr4.end(), var5);

    double num6(30);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    Types::array arr7(2);

    std::string src8("+01:01", 6);
    Query var8(src8);

    arr7.insert(arr7.end(), var8);

    double num9(30);
    Query var9(num9);

    arr7.insert(arr7.end(), var9);

    Query var7(arr7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test17") {
    Types::array arr0(1);

    double num1(0);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test18") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test19") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test20") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test21") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test22") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test23") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test24") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test25") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test26") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test27") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test28") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test29") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test30") {
    std::string src0("2015-07-08T00:00:00-08:00", 25);
    Query var0(src0);
  }

  SECTION("test31") {
    std::string src0("2015-07-09T00:00:00-07:00", 25);
    Query var0(src0);
  }
}
