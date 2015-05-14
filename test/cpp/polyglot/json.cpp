// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

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

    std::string src1("timezone", 8);
    Result var1(src1);

    std::string src2("+00:00", 6);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("TIME", 4);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("epoch_time", 10);
    Result var5(src5);

    double num6(1410393600);
    Result var6(num6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test17") {
    std::string src0("{\"$reql_type$\":\"TIME\",\"epoch_time\":1410393600,\"timezone\":\"+00:00\"}", 76);
    Result var0(src0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("Point", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    map0.insert({src5, var6});

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
