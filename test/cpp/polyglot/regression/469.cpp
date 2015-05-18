// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Issue 177", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
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

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("index", 5);
    Result var2(src2);

    std::string src3("x", 1);
    Result var3(src3);

    map1.insert({src2, var3});

    std::string src4("ready", 5);
    Result var4(src4);

    Result var5(true);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("NULL", 4);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Result var3(src3);

    std::string src4("null", 4);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("BOOL", 4);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Result var3(src3);

    std::string src4("true", 4);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("NUMBER", 6);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Result var3(src3);

    std::string src4("1", 1);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("STRING", 6);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Result var3(src3);

    std::string src4("\"1\"", 5);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("ARRAY", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Result var3(src3);

    std::string src4("[1]", 3);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("OBJECT", 6);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Result var3(src3);

    std::string src4("{\n\t\"a\":\t1\n}", 17);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("db", 2);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("id", 2);
    Result var3(src3);

    std::map<std::string, Result> map4;

    std::string src5("func", 4);
    Result var5(src5);

    std::string src6("uuid", 4);
    Result var6(src6);

    map4.insert({src5, var6});

    Result var4(map4);

    map2.insert({src3, var4});

    std::string src7("name", 4);
    Result var7(src7);

    std::string src8("d469", 4);
    Result var8(src8);

    map2.insert({src7, var8});

    std::string src9("type", 4);
    Result var9(src9);

    std::string src10("DB", 2);
    Result var10(src10);

    map2.insert({src9, var10});

    Result var2(map2);

    map0.insert({src1, var2});

    std::string src11("doc_count_estimates", 19);
    Result var11(src11);

    std::vector<Result> arr12(1);

    double num13(0);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    Result var12(arr12);

    map0.insert({src11, var12});

    std::string src14("id", 2);
    Result var14(src14);

    std::map<std::string, Result> map15;

    std::string src16("func", 4);
    Result var16(src16);

    std::string src17("uuid", 4);
    Result var17(src17);

    map15.insert({src16, var17});

    Result var15(map15);

    map0.insert({src14, var15});

    std::string src18("indexes", 7);
    Result var18(src18);

    std::vector<Result> arr19(1);

    std::string src20("x", 1);
    Result var20(src20);

    arr19.insert(arr19.end(), var20);

    Result var19(arr19);

    map0.insert({src18, var19});

    std::string src21("name", 4);
    Result var21(src21);

    std::string src22("t469", 4);
    Result var22(src22);

    map0.insert({src21, var22});

    std::string src23("primary_key", 11);
    Result var23(src23);

    std::string src24("id", 2);
    Result var24(src24);

    map0.insert({src23, var24});

    std::string src25("type", 4);
    Result var25(src25);

    std::string src26("TABLE", 5);
    Result var26(src26);

    map0.insert({src25, var26});

    Result var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("table", 5);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("db", 2);
    Result var3(src3);

    std::map<std::string, Result> map4;

    std::string src5("id", 2);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("func", 4);
    Result var7(src7);

    std::string src8("uuid", 4);
    Result var8(src8);

    map6.insert({src7, var8});

    Result var6(map6);

    map4.insert({src5, var6});

    std::string src9("name", 4);
    Result var9(src9);

    std::string src10("d469", 4);
    Result var10(src10);

    map4.insert({src9, var10});

    std::string src11("type", 4);
    Result var11(src11);

    std::string src12("DB", 2);
    Result var12(src12);

    map4.insert({src11, var12});

    Result var4(map4);

    map2.insert({src3, var4});

    std::string src13("doc_count_estimates", 19);
    Result var13(src13);

    std::vector<Result> arr14(1);

    double num15(0);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    Result var14(arr14);

    map2.insert({src13, var14});

    std::string src16("id", 2);
    Result var16(src16);

    std::map<std::string, Result> map17;

    std::string src18("func", 4);
    Result var18(src18);

    std::string src19("uuid", 4);
    Result var19(src19);

    map17.insert({src18, var19});

    Result var17(map17);

    map2.insert({src16, var17});

    std::string src20("indexes", 7);
    Result var20(src20);

    std::vector<Result> arr21(1);

    std::string src22("x", 1);
    Result var22(src22);

    arr21.insert(arr21.end(), var22);

    Result var21(arr21);

    map2.insert({src20, var21});

    std::string src23("name", 4);
    Result var23(src23);

    std::string src24("t469", 4);
    Result var24(src24);

    map2.insert({src23, var24});

    std::string src25("primary_key", 11);
    Result var25(src25);

    std::string src26("id", 2);
    Result var26(src26);

    map2.insert({src25, var26});

    std::string src27("type", 4);
    Result var27(src27);

    std::string src28("TABLE", 5);
    Result var28(src28);

    map2.insert({src27, var28});

    Result var2(map2);

    map0.insert({src1, var2});

    std::string src29("type", 4);
    Result var29(src29);

    std::string src30("SELECTION<STREAM>", 17);
    Result var30(src30);

    map0.insert({src29, var30});

    Result var0(map0);
  }

  SECTION("test13") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("STREAM", 6);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test14") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
