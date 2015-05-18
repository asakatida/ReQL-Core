// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests RQL json parsing", "[cpp][ast]") {

  SECTION("test0") {
    std::vector<Result> arr0(3);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test1") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;
    Result var0(map0);
  }

  SECTION("test3") {
    std::string src0("foo", 3);
    Result var0(src0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    std::string src0("[1,2,3]", 7);
    Result var0(src0);
  }

  SECTION("test6") {
    std::string src0("[1,2,3]", 7);
    Result var0(src0);
  }

  SECTION("test7") {
    std::string src0("{\"foo\":4}", 11);
    Result var0(src0);
  }

  SECTION("test8") {
    std::string src0("{\"foo\":4}", 11);
    Result var0(src0);
  }

  SECTION("test11") {
    std::vector<Result> arr0(2);

    std::string src1("func", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("sorted", 6);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
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
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("TIME", 4);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("epoch_time", 10);
    Result var3(src3);

    double num4(1410393600);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("timezone", 8);
    Result var5(src5);

    std::string src6("+00:00", 6);
    Result var6(src6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test17") {
    std::string src0("{\"$reql_type$\":\"TIME\",\"epoch_time\":1410393600,\"timezone\":\"+00:00\"}", 76);
    Result var0(src0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(2);

    double num5(0);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(0);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src7("type", 4);
    Result var7(src7);

    std::string src8("Point", 5);
    Result var8(src8);

    map0.insert({src7, var8});

    Result var0(map0);
  }

  SECTION("test19") {
    std::string src0("{\"$reql_type$\":\"GEOMETRY\",\"coordinates\":[0,0],\"type\":\"Point\"}", 71);
    Result var0(src0);
  }

  SECTION("test21") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("s", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test22") {
    std::string src0("{\"$reql_type$\":\"BINARY\",\"data\":\"Zm9v\"}", 46);
    Result var0(src0);
  }
}
