// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test changefeed squashing", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("STREAM", 6);
    Query var0(src0);
  }

  SECTION("test1") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test6") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test7") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    std::map<std::string, Query> map3;

    std::string src4("id", 2);
    Query var4(src4);

    double num5(100);
    Query var5(num5);

    map3.insert({src4, var5});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src6("old_val", 7);
    Query var6(src6);

    Query var7;

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map8;

    std::string src9("new_val", 7);
    Query var9(src9);

    std::map<std::string, Query> map10;

    std::string src11("a", 1);
    Query var11(src11);

    double num12(1);
    Query var12(num12);

    map10.insert({src11, var12});

    std::string src13("id", 2);
    Query var13(src13);

    double num14(100);
    Query var14(num14);

    map10.insert({src13, var14});

    Query var10(map10);

    map8.insert({src9, var10});

    std::string src15("old_val", 7);
    Query var15(src15);

    std::map<std::string, Query> map16;

    std::string src17("id", 2);
    Query var17(src17);

    double num18(100);
    Query var18(num18);

    map16.insert({src17, var18});

    Query var16(map16);

    map8.insert({src15, var16});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test8") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    std::map<std::string, Query> map3;

    std::string src4("id", 2);
    Query var4(src4);

    double num5(100);
    Query var5(num5);

    map3.insert({src4, var5});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src6("old_val", 7);
    Query var6(src6);

    Query var7;

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map8;

    std::string src9("new_val", 7);
    Query var9(src9);

    std::map<std::string, Query> map10;

    std::string src11("a", 1);
    Query var11(src11);

    double num12(1);
    Query var12(num12);

    map10.insert({src11, var12});

    std::string src13("id", 2);
    Query var13(src13);

    double num14(100);
    Query var14(num14);

    map10.insert({src13, var14});

    Query var10(map10);

    map8.insert({src9, var10});

    std::string src15("old_val", 7);
    Query var15(src15);

    std::map<std::string, Query> map16;

    std::string src17("id", 2);
    Query var17(src17);

    double num18(100);
    Query var18(num18);

    map16.insert({src17, var18});

    Query var16(map16);

    map8.insert({src15, var16});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test9") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    std::map<std::string, Query> map3;

    std::string src4("a", 1);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("id", 2);
    Query var6(src6);

    double num7(100);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Query var8(src8);

    Query var9;

    map1.insert({src8, var9});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test10") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("new_val", 7);
    Query var2(src2);

    std::map<std::string, Query> map3;

    std::string src4("a", 1);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("id", 2);
    Query var6(src6);

    double num7(100);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Query var8(src8);

    Query var9;

    map1.insert({src8, var9});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test11") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
