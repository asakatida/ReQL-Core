// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test basic timezone manipulation", "[cpp][ast]") {

  SECTION("test14") {
    std::vector<Result> arr0(3);

    std::vector<Result> arr1(2);

    std::string src2("+00:00", 6);
    Result var2(src2);

    arr1.insert(arr1.end(), var2);

    double num3(29);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    std::string src5("+00:00", 6);
    Result var5(src5);

    arr4.insert(arr4.end(), var5);

    double num6(29);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Result> arr7(2);

    std::string src8("+00:00", 6);
    Result var8(src8);

    arr7.insert(arr7.end(), var8);

    double num9(29);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test15") {
    std::vector<Result> arr0(3);

    std::vector<Result> arr1(2);

    std::string src2("-00:59", 6);
    Result var2(src2);

    arr1.insert(arr1.end(), var2);

    double num3(29);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    std::string src5("-01:00", 6);
    Result var5(src5);

    arr4.insert(arr4.end(), var5);

    double num6(29);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Result> arr7(2);

    std::string src8("-01:01", 6);
    Result var8(src8);

    arr7.insert(arr7.end(), var8);

    double num9(29);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test16") {
    std::vector<Result> arr0(3);

    std::vector<Result> arr1(2);

    std::string src2("+00:59", 6);
    Result var2(src2);

    arr1.insert(arr1.end(), var2);

    double num3(30);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    std::string src5("+01:00", 6);
    Result var5(src5);

    arr4.insert(arr4.end(), var5);

    double num6(30);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Result> arr7(2);

    std::string src8("+01:01", 6);
    Result var8(src8);

    arr7.insert(arr7.end(), var8);

    double num9(30);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test17") {
    std::vector<Result> arr0(1);

    double num1(0);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
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

  SECTION("test22") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test23") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test24") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test25") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test26") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test27") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test28") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test29") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
