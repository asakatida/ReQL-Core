// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Issue", "[cpp][ast]") {

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

    std::string src2("ready", 5);
    Result var2(src2);

    Result var3(true);

    map1.insert({src2, var3});

    std::string src4("index", 5);
    Result var4(src4);

    std::string src5("x", 1);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("value", 5);
    Result var1(src1);

    std::string src2("None", 4);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("type", 4);
    Result var3(src3);

    std::string src4("NULL", 4);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("value", 5);
    Result var1(src1);

    std::string src2("True", 4);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("type", 4);
    Result var3(src3);

    std::string src4("BOOL", 4);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("value", 5);
    Result var1(src1);

    std::string src2("1", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("type", 4);
    Result var3(src3);

    std::string src4("NUMBER", 6);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("value", 5);
    Result var1(src1);

    std::string src2("\"1\"", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("type", 4);
    Result var3(src3);

    std::string src4("STRING", 6);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("value", 5);
    Result var1(src1);

    std::string src2("[1]", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("type", 4);
    Result var3(src3);

    std::string src4("ARRAY", 5);
    Result var4(src4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("value", 5);
    Result var1(src1);

    std::string src2("{\n\t\"a\":\t1\n}", 17);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("type", 4);
    Result var3(src3);

    std::string src4("OBJECT", 6);
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

    std::string src1("indexes", 7);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::string src3("x", 1);
    Result var3(src3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src4("primary_key", 11);
    Result var4(src4);

    std::string src5("id", 2);
    Result var5(src5);

    map0.insert({src4, var5});

    std::string src6("name", 4);
    Result var6(src6);

    std::string src7("t469", 4);
    Result var7(src7);

    map0.insert({src6, var7});

    std::string src8("type", 4);
    Result var8(src8);

    std::string src9("TABLE", 5);
    Result var9(src9);

    map0.insert({src8, var9});

    std::string src10("db", 2);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("id", 2);
    Result var12(src12);

    std::map<std::string, Result> map13;

    std::string src14("func", 4);
    Result var14(src14);

    std::string src15("uuid", 4);
    Result var15(src15);

    map13.insert({src14, var15});

    Result var13(map13);

    map11.insert({src12, var13});

    std::string src16("name", 4);
    Result var16(src16);

    std::string src17("d469", 4);
    Result var17(src17);

    map11.insert({src16, var17});

    std::string src18("type", 4);
    Result var18(src18);

    std::string src19("DB", 2);
    Result var19(src19);

    map11.insert({src18, var19});

    Result var11(map11);

    map0.insert({src10, var11});

    std::string src20("doc_count_estimates", 19);
    Result var20(src20);

    std::vector<Result> arr21(1);

    double num22(0);
    Result var22(num22);

    arr21.insert(arr21.end(), var22);

    Result var21(arr21);

    map0.insert({src20, var21});

    std::string src23("id", 2);
    Result var23(src23);

    std::map<std::string, Result> map24;

    std::string src25("func", 4);
    Result var25(src25);

    std::string src26("uuid", 4);
    Result var26(src26);

    map24.insert({src25, var26});

    Result var24(map24);

    map0.insert({src23, var24});

    Result var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("table", 5);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("indexes", 7);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::string src5("x", 1);
    Result var5(src5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map2.insert({src3, var4});

    std::string src6("primary_key", 11);
    Result var6(src6);

    std::string src7("id", 2);
    Result var7(src7);

    map2.insert({src6, var7});

    std::string src8("name", 4);
    Result var8(src8);

    std::string src9("t469", 4);
    Result var9(src9);

    map2.insert({src8, var9});

    std::string src10("type", 4);
    Result var10(src10);

    std::string src11("TABLE", 5);
    Result var11(src11);

    map2.insert({src10, var11});

    std::string src12("db", 2);
    Result var12(src12);

    std::map<std::string, Result> map13;

    std::string src14("id", 2);
    Result var14(src14);

    std::map<std::string, Result> map15;

    std::string src16("func", 4);
    Result var16(src16);

    std::string src17("uuid", 4);
    Result var17(src17);

    map15.insert({src16, var17});

    Result var15(map15);

    map13.insert({src14, var15});

    std::string src18("name", 4);
    Result var18(src18);

    std::string src19("d469", 4);
    Result var19(src19);

    map13.insert({src18, var19});

    std::string src20("type", 4);
    Result var20(src20);

    std::string src21("DB", 2);
    Result var21(src21);

    map13.insert({src20, var21});

    Result var13(map13);

    map2.insert({src12, var13});

    std::string src22("doc_count_estimates", 19);
    Result var22(src22);

    std::vector<Result> arr23(1);

    double num24(0);
    Result var24(num24);

    arr23.insert(arr23.end(), var24);

    Result var23(arr23);

    map2.insert({src22, var23});

    std::string src25("id", 2);
    Result var25(src25);

    std::map<std::string, Result> map26;

    std::string src27("func", 4);
    Result var27(src27);

    std::string src28("uuid", 4);
    Result var28(src28);

    map26.insert({src27, var28});

    Result var26(map26);

    map2.insert({src25, var26});

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
