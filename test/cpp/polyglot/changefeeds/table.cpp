// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test changefeeds on a table", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("bag", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Types::object map3;

    std::string src4("id", 2);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("version", 7);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Query var8(src8);

    Types::object map9;

    std::string src10("id", 2);
    Query var10(src10);

    double num11(1);
    Query var11(num11);

    map9.insert({src10, var11});

    Query var9(map9);

    map1.insert({src8, var9});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test5") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Query var3;

    map1.insert({src2, var3});

    std::string src4("old_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("version", 7);
    Query var8(src8);

    double num9(1);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test7") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test8") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Types::object map3;

    std::string src4("version", 7);
    Query var4(src4);

    double num5(5);
    Query var5(num5);

    map3.insert({src4, var5});

    Query var3(map3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test10") {
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

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test13") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test14") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("bag", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test15") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Types::object map3;

    std::string src4("id", 2);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("version", 7);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Query var8(src8);

    Types::object map9;

    std::string src10("id", 2);
    Query var10(src10);

    double num11(1);
    Query var11(num11);

    map9.insert({src10, var11});

    Query var9(map9);

    map1.insert({src8, var9});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test17") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test18") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Query var3;

    map1.insert({src2, var3});

    std::string src4("old_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("version", 7);
    Query var8(src8);

    double num9(1);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test19") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test20") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test21") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    Types::object map3;

    std::string src4("version", 7);
    Query var4(src4);

    double num5(5);
    Query var5(num5);

    map3.insert({src4, var5});

    Query var3(map3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }
}
