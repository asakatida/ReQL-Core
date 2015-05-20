// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Test `include_states`", "[cpp][ast]") {

  SECTION("test0") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("state", 5);
    Query var2(src2);

    std::string src3("ready", 5);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test1") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("state", 5);
    Query var2(src2);

    std::string src3("initializing", 12);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("new_val", 7);
    Query var5(src5);

    Query var6;

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map7;

    std::string src8("state", 5);
    Query var8(src8);

    std::string src9("ready", 5);
    Query var9(src9);

    map7.insert({src8, var9});

    Query var7(map7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test2") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("state", 5);
    Query var2(src2);

    std::string src3("initializing", 12);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("state", 5);
    Query var5(src5);

    std::string src6("ready", 5);
    Query var6(src6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("state", 5);
    Query var2(src2);

    std::string src3("initializing", 12);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("new_val", 7);
    Query var5(src5);

    Types::object map6;

    std::string src7("id", 2);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    Query var6(map6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map9;

    std::string src10("state", 5);
    Query var10(src10);

    std::string src11("ready", 5);
    Query var11(src11);

    map9.insert({src10, var11});

    Query var9(map9);

    arr0.insert(arr0.end(), var9);

    Query var0(arr0);
  }

  SECTION("test5") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test7") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("state", 5);
    Query var2(src2);

    std::string src3("ready", 5);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("new_val", 7);
    Query var5(src5);

    Types::object map6;

    std::string src7("id", 2);
    Query var7(src7);

    double num8(2);
    Query var8(num8);

    map6.insert({src7, var8});

    Query var6(map6);

    map4.insert({src5, var6});

    std::string src9("old_val", 7);
    Query var9(src9);

    Query var10;

    map4.insert({src9, var10});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test8") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("state", 5);
    Query var2(src2);

    std::string src3("initializing", 12);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("new_val", 7);
    Query var5(src5);

    Types::object map6;

    std::string src7("id", 2);
    Query var7(src7);

    double num8(2);
    Query var8(num8);

    map6.insert({src7, var8});

    Query var6(map6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map9;

    std::string src10("state", 5);
    Query var10(src10);

    std::string src11("ready", 5);
    Query var11(src11);

    map9.insert({src10, var11});

    Query var9(map9);

    arr0.insert(arr0.end(), var9);

    Types::object map12;

    std::string src13("new_val", 7);
    Query var13(src13);

    Types::object map14;

    std::string src15("a", 1);
    Query var15(src15);

    double num16(1);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("id", 2);
    Query var17(src17);

    double num18(2);
    Query var18(num18);

    map14.insert({src17, var18});

    Query var14(map14);

    map12.insert({src13, var14});

    std::string src19("old_val", 7);
    Query var19(src19);

    Types::object map20;

    std::string src21("id", 2);
    Query var21(src21);

    double num22(2);
    Query var22(num22);

    map20.insert({src21, var22});

    Query var20(map20);

    map12.insert({src19, var20});

    Query var12(map12);

    arr0.insert(arr0.end(), var12);

    Query var0(arr0);
  }

  SECTION("test11") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
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

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test14") {
    Types::array arr0(5);

    Types::object map1;

    std::string src2("state", 5);
    Query var2(src2);

    std::string src3("initializing", 12);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("new_val", 7);
    Query var5(src5);

    Types::object map6;

    std::string src7("id", 2);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    Query var6(map6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map9;

    std::string src10("new_val", 7);
    Query var10(src10);

    Types::object map11;

    std::string src12("a", 1);
    Query var12(src12);

    double num13(1);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("id", 2);
    Query var14(src14);

    double num15(2);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    map9.insert({src10, var11});

    Query var9(map9);

    arr0.insert(arr0.end(), var9);

    Types::object map16;

    std::string src17("state", 5);
    Query var17(src17);

    std::string src18("ready", 5);
    Query var18(src18);

    map16.insert({src17, var18});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Types::object map19;

    std::string src20("new_val", 7);
    Query var20(src20);

    Types::object map21;

    std::string src22("id", 2);
    Query var22(src22);

    double num23(3);
    Query var23(num23);

    map21.insert({src22, var23});

    Query var21(map21);

    map19.insert({src20, var21});

    std::string src24("old_val", 7);
    Query var24(src24);

    Query var25;

    map19.insert({src24, var25});

    Query var19(map19);

    arr0.insert(arr0.end(), var19);

    Query var0(arr0);
  }

  SECTION("test15") {
    Types::array arr0(5);

    Types::object map1;

    std::string src2("state", 5);
    Query var2(src2);

    std::string src3("initializing", 12);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("new_val", 7);
    Query var5(src5);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("id", 2);
    Query var9(src9);

    double num10(2);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map11;

    std::string src12("new_val", 7);
    Query var12(src12);

    Types::object map13;

    std::string src14("id", 2);
    Query var14(src14);

    double num15(1);
    Query var15(num15);

    map13.insert({src14, var15});

    Query var13(map13);

    map11.insert({src12, var13});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("state", 5);
    Query var17(src17);

    std::string src18("ready", 5);
    Query var18(src18);

    map16.insert({src17, var18});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Types::object map19;

    std::string src20("new_val", 7);
    Query var20(src20);

    Types::object map21;

    std::string src22("id", 2);
    Query var22(src22);

    double num23(3);
    Query var23(num23);

    map21.insert({src22, var23});

    Query var21(map21);

    map19.insert({src20, var21});

    std::string src24("old_val", 7);
    Query var24(src24);

    Query var25;

    map19.insert({src24, var25});

    Query var19(map19);

    arr0.insert(arr0.end(), var19);

    Query var0(arr0);
  }
}
