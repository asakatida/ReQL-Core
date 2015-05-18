// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests that manipulation data in tables 11", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test6") {
    double num0(2500);
    Result var0(num0);
  }

  SECTION("test7") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test9") {
    double num0(2500);
    Result var0(num0);
  }

  SECTION("test10") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test11") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test12") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test13") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test14") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test15") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test16") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test17") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test18") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test19") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test22") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(2);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    double num5(2);
    Result var5(num5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    double num8(3);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Result var9(src9);

    double num10(3);
    Result var10(num10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test23") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("a", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map4.insert({src5, var6});

    std::string src7("b", 1);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map4.insert({src7, var8});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map9;

    std::string src10("a", 1);
    Result var10(src10);

    double num11(3);
    Result var11(num11);

    map9.insert({src10, var11});

    std::string src12("b", 1);
    Result var12(src12);

    double num13(3);
    Result var13(num13);

    map9.insert({src12, var13});

    Result var9(map9);

    arr0.insert(arr0.end(), var9);

    Result var0(arr0);
  }

  SECTION("test28") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
