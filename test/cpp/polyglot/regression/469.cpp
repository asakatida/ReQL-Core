// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Issue 95", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Query> map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("index", 5);
    Query var2(src2);

    std::string src3("x", 1);
    Query var3(src3);

    map1.insert({src2, var3});

    std::string src4("ready", 5);
    Query var4(src4);

    Query var5(true);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test4") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("MINVAL", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("MAXVAL", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("NULL", 4);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("BOOL", 4);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("true", 4);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("NUMBER", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("1", 1);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("STRING", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("\"1\"", 5);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test10") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("ARRAY", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("[\n\t1\n]", 9);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test11") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("OBJECT", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("{\n\t\"a\":\t1\n}", 17);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test13") {
    std::map<std::string, Query> map0;

    std::string src1("db", 2);
    Query var1(src1);

    std::map<std::string, Query> map2;

    std::string src3("id", 2);
    Query var3(src3);

    std::map<std::string, Query> map4;

    std::string src5("func", 4);
    Query var5(src5);

    std::string src6("uuid", 4);
    Query var6(src6);

    map4.insert({src5, var6});

    Query var4(map4);

    map2.insert({src3, var4});

    std::string src7("name", 4);
    Query var7(src7);

    std::string src8("d469", 4);
    Query var8(src8);

    map2.insert({src7, var8});

    std::string src9("type", 4);
    Query var9(src9);

    std::string src10("DB", 2);
    Query var10(src10);

    map2.insert({src9, var10});

    Query var2(map2);

    map0.insert({src1, var2});

    std::string src11("doc_count_estimates", 19);
    Query var11(src11);

    std::vector<Query> arr12(1);

    double num13(0);
    Query var13(num13);

    arr12.insert(arr12.end(), var13);

    Query var12(arr12);

    map0.insert({src11, var12});

    std::string src14("id", 2);
    Query var14(src14);

    std::map<std::string, Query> map15;

    std::string src16("func", 4);
    Query var16(src16);

    std::string src17("uuid", 4);
    Query var17(src17);

    map15.insert({src16, var17});

    Query var15(map15);

    map0.insert({src14, var15});

    std::string src18("indexes", 7);
    Query var18(src18);

    std::vector<Query> arr19(1);

    std::string src20("x", 1);
    Query var20(src20);

    arr19.insert(arr19.end(), var20);

    Query var19(arr19);

    map0.insert({src18, var19});

    std::string src21("name", 4);
    Query var21(src21);

    std::string src22("t469", 4);
    Query var22(src22);

    map0.insert({src21, var22});

    std::string src23("primary_key", 11);
    Query var23(src23);

    std::string src24("id", 2);
    Query var24(src24);

    map0.insert({src23, var24});

    std::string src25("type", 4);
    Query var25(src25);

    std::string src26("TABLE", 5);
    Query var26(src26);

    map0.insert({src25, var26});

    Query var0(map0);
  }

  SECTION("test14") {
    std::map<std::string, Query> map0;

    std::string src1("table", 5);
    Query var1(src1);

    std::map<std::string, Query> map2;

    std::string src3("db", 2);
    Query var3(src3);

    std::map<std::string, Query> map4;

    std::string src5("id", 2);
    Query var5(src5);

    std::map<std::string, Query> map6;

    std::string src7("func", 4);
    Query var7(src7);

    std::string src8("uuid", 4);
    Query var8(src8);

    map6.insert({src7, var8});

    Query var6(map6);

    map4.insert({src5, var6});

    std::string src9("name", 4);
    Query var9(src9);

    std::string src10("d469", 4);
    Query var10(src10);

    map4.insert({src9, var10});

    std::string src11("type", 4);
    Query var11(src11);

    std::string src12("DB", 2);
    Query var12(src12);

    map4.insert({src11, var12});

    Query var4(map4);

    map2.insert({src3, var4});

    std::string src13("doc_count_estimates", 19);
    Query var13(src13);

    std::vector<Query> arr14(1);

    double num15(0);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    Query var14(arr14);

    map2.insert({src13, var14});

    std::string src16("id", 2);
    Query var16(src16);

    std::map<std::string, Query> map17;

    std::string src18("func", 4);
    Query var18(src18);

    std::string src19("uuid", 4);
    Query var19(src19);

    map17.insert({src18, var19});

    Query var17(map17);

    map2.insert({src16, var17});

    std::string src20("indexes", 7);
    Query var20(src20);

    std::vector<Query> arr21(1);

    std::string src22("x", 1);
    Query var22(src22);

    arr21.insert(arr21.end(), var22);

    Query var21(arr21);

    map2.insert({src20, var21});

    std::string src23("name", 4);
    Query var23(src23);

    std::string src24("t469", 4);
    Query var24(src24);

    map2.insert({src23, var24});

    std::string src25("primary_key", 11);
    Query var25(src25);

    std::string src26("id", 2);
    Query var26(src26);

    map2.insert({src25, var26});

    std::string src27("type", 4);
    Query var27(src27);

    std::string src28("TABLE", 5);
    Query var28(src28);

    map2.insert({src27, var28});

    Query var2(map2);

    map0.insert({src1, var2});

    std::string src29("type", 4);
    Query var29(src29);

    std::string src30("SELECTION<STREAM>", 17);
    Query var30(src30);

    map0.insert({src29, var30});

    Query var0(map0);
  }

  SECTION("test15") {
    std::map<std::string, Query> map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("STREAM", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Query> map0;

    std::string src1("index", 5);
    Query var1(src1);

    std::string src2("id", 2);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("left_bound", 10);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("left_bound_type", 15);
    Query var5(src5);

    std::string src6("closed", 6);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("right_bound", 11);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("right_bound_type", 16);
    Query var9(src9);

    std::string src10("open", 4);
    Query var10(src10);

    map0.insert({src9, var10});

    std::string src11("sorting", 7);
    Query var11(src11);

    std::string src12("UNORDERED", 9);
    Query var12(src12);

    map0.insert({src11, var12});

    std::string src13("table", 5);
    Query var13(src13);

    std::map<std::string, Query> map14;

    std::string src15("db", 2);
    Query var15(src15);

    std::map<std::string, Query> map16;

    std::string src17("id", 2);
    Query var17(src17);

    std::map<std::string, Query> map18;

    std::string src19("func", 4);
    Query var19(src19);

    std::string src20("uuid", 4);
    Query var20(src20);

    map18.insert({src19, var20});

    Query var18(map18);

    map16.insert({src17, var18});

    std::string src21("name", 4);
    Query var21(src21);

    std::string src22("d469", 4);
    Query var22(src22);

    map16.insert({src21, var22});

    std::string src23("type", 4);
    Query var23(src23);

    std::string src24("DB", 2);
    Query var24(src24);

    map16.insert({src23, var24});

    Query var16(map16);

    map14.insert({src15, var16});

    std::string src25("doc_count_estimates", 19);
    Query var25(src25);

    std::vector<Query> arr26(1);

    double num27(0);
    Query var27(num27);

    arr26.insert(arr26.end(), var27);

    Query var26(arr26);

    map14.insert({src25, var26});

    std::string src28("id", 2);
    Query var28(src28);

    std::map<std::string, Query> map29;

    std::string src30("func", 4);
    Query var30(src30);

    std::string src31("uuid", 4);
    Query var31(src31);

    map29.insert({src30, var31});

    Query var29(map29);

    map14.insert({src28, var29});

    std::string src32("indexes", 7);
    Query var32(src32);

    std::vector<Query> arr33(1);

    std::string src34("x", 1);
    Query var34(src34);

    arr33.insert(arr33.end(), var34);

    Query var33(arr33);

    map14.insert({src32, var33});

    std::string src35("name", 4);
    Query var35(src35);

    std::string src36("t469", 4);
    Query var36(src36);

    map14.insert({src35, var36});

    std::string src37("primary_key", 11);
    Query var37(src37);

    std::string src38("id", 2);
    Query var38(src38);

    map14.insert({src37, var38});

    std::string src39("type", 4);
    Query var39(src39);

    std::string src40("TABLE", 5);
    Query var40(src40);

    map14.insert({src39, var40});

    Query var14(map14);

    map0.insert({src13, var14});

    std::string src41("type", 4);
    Query var41(src41);

    std::string src42("TABLE_SLICE", 11);
    Query var42(src42);

    map0.insert({src41, var42});

    Query var0(map0);
  }

  SECTION("test17") {
    std::map<std::string, Query> map0;

    std::string src1("index", 5);
    Query var1(src1);

    std::string src2("a", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("left_bound", 10);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("left_bound_type", 15);
    Query var5(src5);

    std::string src6("closed", 6);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("right_bound", 11);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("right_bound_type", 16);
    Query var9(src9);

    std::string src10("open", 4);
    Query var10(src10);

    map0.insert({src9, var10});

    std::string src11("sorting", 7);
    Query var11(src11);

    std::string src12("UNORDERED", 9);
    Query var12(src12);

    map0.insert({src11, var12});

    std::string src13("table", 5);
    Query var13(src13);

    std::map<std::string, Query> map14;

    std::string src15("db", 2);
    Query var15(src15);

    std::map<std::string, Query> map16;

    std::string src17("id", 2);
    Query var17(src17);

    std::map<std::string, Query> map18;

    std::string src19("func", 4);
    Query var19(src19);

    std::string src20("uuid", 4);
    Query var20(src20);

    map18.insert({src19, var20});

    Query var18(map18);

    map16.insert({src17, var18});

    std::string src21("name", 4);
    Query var21(src21);

    std::string src22("d469", 4);
    Query var22(src22);

    map16.insert({src21, var22});

    std::string src23("type", 4);
    Query var23(src23);

    std::string src24("DB", 2);
    Query var24(src24);

    map16.insert({src23, var24});

    Query var16(map16);

    map14.insert({src15, var16});

    std::string src25("doc_count_estimates", 19);
    Query var25(src25);

    std::vector<Query> arr26(1);

    double num27(0);
    Query var27(num27);

    arr26.insert(arr26.end(), var27);

    Query var26(arr26);

    map14.insert({src25, var26});

    std::string src28("id", 2);
    Query var28(src28);

    std::map<std::string, Query> map29;

    std::string src30("func", 4);
    Query var30(src30);

    std::string src31("uuid", 4);
    Query var31(src31);

    map29.insert({src30, var31});

    Query var29(map29);

    map14.insert({src28, var29});

    std::string src32("indexes", 7);
    Query var32(src32);

    std::vector<Query> arr33(1);

    std::string src34("x", 1);
    Query var34(src34);

    arr33.insert(arr33.end(), var34);

    Query var33(arr33);

    map14.insert({src32, var33});

    std::string src35("name", 4);
    Query var35(src35);

    std::string src36("t469", 4);
    Query var36(src36);

    map14.insert({src35, var36});

    std::string src37("primary_key", 11);
    Query var37(src37);

    std::string src38("id", 2);
    Query var38(src38);

    map14.insert({src37, var38});

    std::string src39("type", 4);
    Query var39(src39);

    std::string src40("TABLE", 5);
    Query var40(src40);

    map14.insert({src39, var40});

    Query var14(map14);

    map0.insert({src13, var14});

    std::string src41("type", 4);
    Query var41(src41);

    std::string src42("TABLE_SLICE", 11);
    Query var42(src42);

    map0.insert({src41, var42});

    Query var0(map0);
  }

  SECTION("test18") {
    std::map<std::string, Query> map0;

    std::string src1("index", 5);
    Query var1(src1);

    std::string src2("a", 1);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("left_bound", 10);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("left_bound_type", 15);
    Query var5(src5);

    std::string src6("closed", 6);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("right_bound", 11);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("right_bound_type", 16);
    Query var9(src9);

    std::string src10("open", 4);
    Query var10(src10);

    map0.insert({src9, var10});

    std::string src11("sorting", 7);
    Query var11(src11);

    std::string src12("ASCENDING", 9);
    Query var12(src12);

    map0.insert({src11, var12});

    std::string src13("table", 5);
    Query var13(src13);

    std::map<std::string, Query> map14;

    std::string src15("db", 2);
    Query var15(src15);

    std::map<std::string, Query> map16;

    std::string src17("id", 2);
    Query var17(src17);

    std::map<std::string, Query> map18;

    std::string src19("func", 4);
    Query var19(src19);

    std::string src20("uuid", 4);
    Query var20(src20);

    map18.insert({src19, var20});

    Query var18(map18);

    map16.insert({src17, var18});

    std::string src21("name", 4);
    Query var21(src21);

    std::string src22("d469", 4);
    Query var22(src22);

    map16.insert({src21, var22});

    std::string src23("type", 4);
    Query var23(src23);

    std::string src24("DB", 2);
    Query var24(src24);

    map16.insert({src23, var24});

    Query var16(map16);

    map14.insert({src15, var16});

    std::string src25("doc_count_estimates", 19);
    Query var25(src25);

    std::vector<Query> arr26(1);

    double num27(0);
    Query var27(num27);

    arr26.insert(arr26.end(), var27);

    Query var26(arr26);

    map14.insert({src25, var26});

    std::string src28("id", 2);
    Query var28(src28);

    std::map<std::string, Query> map29;

    std::string src30("func", 4);
    Query var30(src30);

    std::string src31("uuid", 4);
    Query var31(src31);

    map29.insert({src30, var31});

    Query var29(map29);

    map14.insert({src28, var29});

    std::string src32("indexes", 7);
    Query var32(src32);

    std::vector<Query> arr33(1);

    std::string src34("x", 1);
    Query var34(src34);

    arr33.insert(arr33.end(), var34);

    Query var33(arr33);

    map14.insert({src32, var33});

    std::string src35("name", 4);
    Query var35(src35);

    std::string src36("t469", 4);
    Query var36(src36);

    map14.insert({src35, var36});

    std::string src37("primary_key", 11);
    Query var37(src37);

    std::string src38("id", 2);
    Query var38(src38);

    map14.insert({src37, var38});

    std::string src39("type", 4);
    Query var39(src39);

    std::string src40("TABLE", 5);
    Query var40(src40);

    map14.insert({src39, var40});

    Query var14(map14);

    map0.insert({src13, var14});

    std::string src41("type", 4);
    Query var41(src41);

    std::string src42("TABLE_SLICE", 11);
    Query var42(src42);

    map0.insert({src41, var42});

    Query var0(map0);
  }

  SECTION("test19") {
    std::map<std::string, Query> map0;

    std::string src1("index", 5);
    Query var1(src1);

    std::string src2("id", 2);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("left_bound_type", 15);
    Query var3(src3);

    std::string src4("unbounded", 9);
    Query var4(src4);

    map0.insert({src3, var4});

    std::string src5("right_bound_type", 16);
    Query var5(src5);

    std::string src6("unbounded", 9);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("sorting", 7);
    Query var7(src7);

    std::string src8("UNORDERED", 9);
    Query var8(src8);

    map0.insert({src7, var8});

    std::string src9("table", 5);
    Query var9(src9);

    std::map<std::string, Query> map10;

    std::string src11("db", 2);
    Query var11(src11);

    std::map<std::string, Query> map12;

    std::string src13("id", 2);
    Query var13(src13);

    std::map<std::string, Query> map14;

    std::string src15("func", 4);
    Query var15(src15);

    std::string src16("uuid", 4);
    Query var16(src16);

    map14.insert({src15, var16});

    Query var14(map14);

    map12.insert({src13, var14});

    std::string src17("name", 4);
    Query var17(src17);

    std::string src18("d469", 4);
    Query var18(src18);

    map12.insert({src17, var18});

    std::string src19("type", 4);
    Query var19(src19);

    std::string src20("DB", 2);
    Query var20(src20);

    map12.insert({src19, var20});

    Query var12(map12);

    map10.insert({src11, var12});

    std::string src21("doc_count_estimates", 19);
    Query var21(src21);

    std::vector<Query> arr22(1);

    double num23(0);
    Query var23(num23);

    arr22.insert(arr22.end(), var23);

    Query var22(arr22);

    map10.insert({src21, var22});

    std::string src24("id", 2);
    Query var24(src24);

    std::map<std::string, Query> map25;

    std::string src26("func", 4);
    Query var26(src26);

    std::string src27("uuid", 4);
    Query var27(src27);

    map25.insert({src26, var27});

    Query var25(map25);

    map10.insert({src24, var25});

    std::string src28("indexes", 7);
    Query var28(src28);

    std::vector<Query> arr29(1);

    std::string src30("x", 1);
    Query var30(src30);

    arr29.insert(arr29.end(), var30);

    Query var29(arr29);

    map10.insert({src28, var29});

    std::string src31("name", 4);
    Query var31(src31);

    std::string src32("t469", 4);
    Query var32(src32);

    map10.insert({src31, var32});

    std::string src33("primary_key", 11);
    Query var33(src33);

    std::string src34("id", 2);
    Query var34(src34);

    map10.insert({src33, var34});

    std::string src35("type", 4);
    Query var35(src35);

    std::string src36("TABLE", 5);
    Query var36(src36);

    map10.insert({src35, var36});

    Query var10(map10);

    map0.insert({src9, var10});

    std::string src37("type", 4);
    Query var37(src37);

    std::string src38("TABLE_SLICE", 11);
    Query var38(src38);

    map0.insert({src37, var38});

    Query var0(map0);
  }

  SECTION("test20") {
    std::map<std::string, Query> map0;

    std::string src1("index", 5);
    Query var1(src1);

    std::string src2("id", 2);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("left_bound_type", 15);
    Query var3(src3);

    std::string src4("unachievable", 12);
    Query var4(src4);

    map0.insert({src3, var4});

    std::string src5("right_bound_type", 16);
    Query var5(src5);

    std::string src6("unachievable", 12);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("sorting", 7);
    Query var7(src7);

    std::string src8("UNORDERED", 9);
    Query var8(src8);

    map0.insert({src7, var8});

    std::string src9("table", 5);
    Query var9(src9);

    std::map<std::string, Query> map10;

    std::string src11("db", 2);
    Query var11(src11);

    std::map<std::string, Query> map12;

    std::string src13("id", 2);
    Query var13(src13);

    std::map<std::string, Query> map14;

    std::string src15("func", 4);
    Query var15(src15);

    std::string src16("uuid", 4);
    Query var16(src16);

    map14.insert({src15, var16});

    Query var14(map14);

    map12.insert({src13, var14});

    std::string src17("name", 4);
    Query var17(src17);

    std::string src18("d469", 4);
    Query var18(src18);

    map12.insert({src17, var18});

    std::string src19("type", 4);
    Query var19(src19);

    std::string src20("DB", 2);
    Query var20(src20);

    map12.insert({src19, var20});

    Query var12(map12);

    map10.insert({src11, var12});

    std::string src21("doc_count_estimates", 19);
    Query var21(src21);

    std::vector<Query> arr22(1);

    double num23(0);
    Query var23(num23);

    arr22.insert(arr22.end(), var23);

    Query var22(arr22);

    map10.insert({src21, var22});

    std::string src24("id", 2);
    Query var24(src24);

    std::map<std::string, Query> map25;

    std::string src26("func", 4);
    Query var26(src26);

    std::string src27("uuid", 4);
    Query var27(src27);

    map25.insert({src26, var27});

    Query var25(map25);

    map10.insert({src24, var25});

    std::string src28("indexes", 7);
    Query var28(src28);

    std::vector<Query> arr29(1);

    std::string src30("x", 1);
    Query var30(src30);

    arr29.insert(arr29.end(), var30);

    Query var29(arr29);

    map10.insert({src28, var29});

    std::string src31("name", 4);
    Query var31(src31);

    std::string src32("t469", 4);
    Query var32(src32);

    map10.insert({src31, var32});

    std::string src33("primary_key", 11);
    Query var33(src33);

    std::string src34("id", 2);
    Query var34(src34);

    map10.insert({src33, var34});

    std::string src35("type", 4);
    Query var35(src35);

    std::string src36("TABLE", 5);
    Query var36(src36);

    map10.insert({src35, var36});

    Query var10(map10);

    map0.insert({src9, var10});

    std::string src37("type", 4);
    Query var37(src37);

    std::string src38("TABLE_SLICE", 11);
    Query var38(src38);

    map0.insert({src37, var38});

    Query var0(map0);
  }

  SECTION("test21") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
