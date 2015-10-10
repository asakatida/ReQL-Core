// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests that manipulation data in tables 129", "[cpp][ast]") {

  SECTION("test0") {
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

    std::string src2("partial", 7);
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
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    double num0(2500);
    Query var0(num0);
  }

  SECTION("test7") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test9") {
    double num0(2500);
    Query var0(num0);
  }

  SECTION("test10") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test11") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test12") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test13") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test14") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test15") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test16") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test17") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test18") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test19") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test22") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(2);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    double num5(2);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    double num8(3);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Query var9(src9);

    double num10(3);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test23") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("a", 1);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map4.insert({src5, var6});

    std::string src7("b", 1);
    Query var7(src7);

    double num8(2);
    Query var8(num8);

    map4.insert({src7, var8});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map9;

    std::string src10("a", 1);
    Query var10(src10);

    double num11(3);
    Query var11(num11);

    map9.insert({src10, var11});

    std::string src12("b", 1);
    Query var12(src12);

    double num13(3);
    Query var13(num13);

    map9.insert({src12, var13});

    Query var9(map9);

    arr0.insert(arr0.end(), var9);

    Query var0(arr0);
  }

  SECTION("test28") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
