// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test `include_states`", "[cpp][ast]") {

  SECTION("test0") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("state", 5);
    Result var2(src2);

    std::string src3("ready", 5);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test1") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("state", 5);
    Result var2(src2);

    std::string src3("initializing", 12);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("new_val", 7);
    Result var5(src5);

    Result var6;

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map7;

    std::string src8("state", 5);
    Result var8(src8);

    std::string src9("ready", 5);
    Result var9(src9);

    map7.insert({src8, var9});

    Result var7(map7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test2") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("state", 5);
    Result var2(src2);

    std::string src3("initializing", 12);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("state", 5);
    Result var5(src5);

    std::string src6("ready", 5);
    Result var6(src6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test3") {
    Result var0;
  }

  SECTION("test4") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("state", 5);
    Result var2(src2);

    std::string src3("initializing", 12);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("new_val", 7);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("id", 2);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map6.insert({src7, var8});

    Result var6(map6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map9;

    std::string src10("state", 5);
    Result var10(src10);

    std::string src11("ready", 5);
    Result var11(src11);

    map9.insert({src10, var11});

    Result var9(map9);

    arr0.insert(arr0.end(), var9);

    Result var0(arr0);
  }

  SECTION("test5") {
    Result var0;
  }

  SECTION("test6") {
    Result var0;
  }

  SECTION("test7") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("state", 5);
    Result var2(src2);

    std::string src3("ready", 5);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("old_val", 7);
    Result var5(src5);

    Result var6;

    map4.insert({src5, var6});

    std::string src7("new_val", 7);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("id", 2);
    Result var9(src9);

    double num10(2);
    Result var10(num10);

    map8.insert({src9, var10});

    Result var8(map8);

    map4.insert({src7, var8});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test8") {
    Result var0;
  }

  SECTION("test9") {
    Result var0;
  }

  SECTION("test10") {
    std::vector<Result> arr0(4);

    std::map<std::string, Result> map1;

    std::string src2("state", 5);
    Result var2(src2);

    std::string src3("initializing", 12);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("new_val", 7);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("id", 2);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map6.insert({src7, var8});

    Result var6(map6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map9;

    std::string src10("state", 5);
    Result var10(src10);

    std::string src11("ready", 5);
    Result var11(src11);

    map9.insert({src10, var11});

    Result var9(map9);

    arr0.insert(arr0.end(), var9);

    std::map<std::string, Result> map12;

    std::string src13("old_val", 7);
    Result var13(src13);

    std::map<std::string, Result> map14;

    std::string src15("id", 2);
    Result var15(src15);

    double num16(2);
    Result var16(num16);

    map14.insert({src15, var16});

    Result var14(map14);

    map12.insert({src13, var14});

    std::string src17("new_val", 7);
    Result var17(src17);

    std::map<std::string, Result> map18;

    std::string src19("a", 1);
    Result var19(src19);

    double num20(1);
    Result var20(num20);

    map18.insert({src19, var20});

    std::string src21("id", 2);
    Result var21(src21);

    double num22(2);
    Result var22(num22);

    map18.insert({src21, var22});

    Result var18(map18);

    map12.insert({src17, var18});

    Result var12(map12);

    arr0.insert(arr0.end(), var12);

    Result var0(arr0);
  }

  SECTION("test11") {
    Result var0;
  }

  SECTION("test12") {
    Result var0;
  }

  SECTION("test13") {
    Result var0;
  }

  SECTION("test14") {
    std::vector<Result> arr0(5);

    std::map<std::string, Result> map1;

    std::string src2("state", 5);
    Result var2(src2);

    std::string src3("initializing", 12);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("new_val", 7);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("id", 2);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map6.insert({src7, var8});

    Result var6(map6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map9;

    std::string src10("new_val", 7);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("a", 1);
    Result var12(src12);

    double num13(1);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("id", 2);
    Result var14(src14);

    double num15(2);
    Result var15(num15);

    map11.insert({src14, var15});

    Result var11(map11);

    map9.insert({src10, var11});

    Result var9(map9);

    arr0.insert(arr0.end(), var9);

    std::map<std::string, Result> map16;

    std::string src17("state", 5);
    Result var17(src17);

    std::string src18("ready", 5);
    Result var18(src18);

    map16.insert({src17, var18});

    Result var16(map16);

    arr0.insert(arr0.end(), var16);

    std::map<std::string, Result> map19;

    std::string src20("old_val", 7);
    Result var20(src20);

    Result var21;

    map19.insert({src20, var21});

    std::string src22("new_val", 7);
    Result var22(src22);

    std::map<std::string, Result> map23;

    std::string src24("id", 2);
    Result var24(src24);

    double num25(3);
    Result var25(num25);

    map23.insert({src24, var25});

    Result var23(map23);

    map19.insert({src22, var23});

    Result var19(map19);

    arr0.insert(arr0.end(), var19);

    Result var0(arr0);
  }

  SECTION("test15") {
    std::vector<Result> arr0(5);

    std::map<std::string, Result> map1;

    std::string src2("state", 5);
    Result var2(src2);

    std::string src3("initializing", 12);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("new_val", 7);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("id", 2);
    Result var9(src9);

    double num10(2);
    Result var10(num10);

    map6.insert({src9, var10});

    Result var6(map6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map11;

    std::string src12("new_val", 7);
    Result var12(src12);

    std::map<std::string, Result> map13;

    std::string src14("id", 2);
    Result var14(src14);

    double num15(1);
    Result var15(num15);

    map13.insert({src14, var15});

    Result var13(map13);

    map11.insert({src12, var13});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    std::map<std::string, Result> map16;

    std::string src17("state", 5);
    Result var17(src17);

    std::string src18("ready", 5);
    Result var18(src18);

    map16.insert({src17, var18});

    Result var16(map16);

    arr0.insert(arr0.end(), var16);

    std::map<std::string, Result> map19;

    std::string src20("old_val", 7);
    Result var20(src20);

    Result var21;

    map19.insert({src20, var21});

    std::string src22("new_val", 7);
    Result var22(src22);

    std::map<std::string, Result> map23;

    std::string src24("id", 2);
    Result var24(src24);

    double num25(3);
    Result var25(num25);

    map23.insert({src24, var25});

    Result var23(map23);

    map19.insert({src22, var23});

    Result var19(map19);

    arr0.insert(arr0.end(), var19);

    Result var0(arr0);
  }
}
