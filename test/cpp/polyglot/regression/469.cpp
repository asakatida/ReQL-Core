// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Issue 177", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
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

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::array arr0(1);

    Types::object map1;

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
    Types::object map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("NULL", 4);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("null", 4);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test5") {
    Types::object map0;

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

  SECTION("test6") {
    Types::object map0;

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

  SECTION("test7") {
    Types::object map0;

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

  SECTION("test8") {
    Types::object map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("ARRAY", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("[1]", 3);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test9") {
    Types::object map0;

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

  SECTION("test10") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test11") {
    Types::object map0;

    std::string src1("db", 2);
    Query var1(src1);

    Types::object map2;

    std::string src3("id", 2);
    Query var3(src3);

    Types::object map4;

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

    Types::array arr12(1);

    double num13(0);
    Query var13(num13);

    arr12.insert(arr12.end(), var13);

    Query var12(arr12);

    map0.insert({src11, var12});

    std::string src14("id", 2);
    Query var14(src14);

    Types::object map15;

    std::string src16("func", 4);
    Query var16(src16);

    std::string src17("uuid", 4);
    Query var17(src17);

    map15.insert({src16, var17});

    Query var15(map15);

    map0.insert({src14, var15});

    std::string src18("indexes", 7);
    Query var18(src18);

    Types::array arr19(1);

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

  SECTION("test12") {
    Types::object map0;

    std::string src1("table", 5);
    Query var1(src1);

    Types::object map2;

    std::string src3("db", 2);
    Query var3(src3);

    Types::object map4;

    std::string src5("id", 2);
    Query var5(src5);

    Types::object map6;

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

    Types::array arr14(1);

    double num15(0);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    Query var14(arr14);

    map2.insert({src13, var14});

    std::string src16("id", 2);
    Query var16(src16);

    Types::object map17;

    std::string src18("func", 4);
    Query var18(src18);

    std::string src19("uuid", 4);
    Query var19(src19);

    map17.insert({src18, var19});

    Query var17(map17);

    map2.insert({src16, var17});

    std::string src20("indexes", 7);
    Query var20(src20);

    Types::array arr21(1);

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

  SECTION("test13") {
    Types::object map0;

    std::string src1("type", 4);
    Query var1(src1);

    std::string src2("STREAM", 6);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test14") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
