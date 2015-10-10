// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests conversion to and from the RQL object type", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;
    Query var0(map0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    Types::object map2;

    std::string src3("b", 1);
    Query var3(src3);

    Types::array arr4(3);

    Types::object map5;

    std::string src6("c", 1);
    Query var6(src6);

    double num7(2);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    arr4.insert(arr4.end(), var5);

    std::string src8("a", 1);
    Query var8(src8);

    arr4.insert(arr4.end(), var8);

    double num9(4);
    Query var9(num9);

    arr4.insert(arr4.end(), var9);

    Query var4(arr4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    std::string src0("OBJECT", 6);
    Query var0(src0);
  }

  SECTION("test6") {
    std::string src0("{\"a\":1}", 9);
    Query var0(src0);
  }

  SECTION("test7") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test8") {
    Types::array arr0(1);

    Types::array arr1(2);

    std::string src2("a", 1);
    Query var2(src2);

    arr1.insert(arr1.end(), var2);

    double num3(1);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err_regex", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err_regex", 9);
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

  SECTION("test15") {
    Types::object map0;
    Query var0(map0);
  }

  SECTION("test16") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test17") {
    Types::object map0;

    std::string src1("cd", 2);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
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
}
