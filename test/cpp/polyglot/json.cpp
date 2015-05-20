// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests RQL json parsing", "[cpp][ast]") {

  SECTION("test0") {
    Types::array arr0(3);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test1") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test2") {
    Types::object map0;
    Query var0(map0);
  }

  SECTION("test3") {
    std::string src0("foo", 3);
    Query var0(src0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    std::string src0("[1,2,3]", 7);
    Query var0(src0);
  }

  SECTION("test6") {
    std::string src0("[1,2,3]", 7);
    Query var0(src0);
  }

  SECTION("test7") {
    std::string src0("{\"foo\":4}", 11);
    Query var0(src0);
  }

  SECTION("test8") {
    std::string src0("{\"foo\":4}", 11);
    Query var0(src0);
  }

  SECTION("test11") {
    Types::array arr0(2);

    std::string src1("func", 4);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("sorted", 6);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
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
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("TIME", 4);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("epoch_time", 10);
    Query var3(src3);

    double num4(1410393600);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("timezone", 8);
    Query var5(src5);

    std::string src6("+00:00", 6);
    Query var6(src6);

    map0.insert({src5, var6});

    Query var0(map0);
  }

  SECTION("test17") {
    std::string src0("{\"$reql_type$\":\"TIME\",\"epoch_time\":1410393600,\"timezone\":\"+00:00\"}", 76);
    Query var0(src0);
  }

  SECTION("test18") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GEOMETRY", 8);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Query var3(src3);

    Types::array arr4(2);

    double num5(0);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(0);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src7("type", 4);
    Query var7(src7);

    std::string src8("Point", 5);
    Query var8(src8);

    map0.insert({src7, var8});

    Query var0(map0);
  }

  SECTION("test19") {
    std::string src0("{\"$reql_type$\":\"GEOMETRY\",\"coordinates\":[0,0],\"type\":\"Point\"}", 71);
    Query var0(src0);
  }

  SECTION("test21") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("s", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test22") {
    std::string src0("{\"$reql_type$\":\"BINARY\",\"data\":\"Zm9v\"}", 46);
    Query var0(src0);
  }
}
