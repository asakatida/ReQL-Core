// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Test changefeed squashing", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("STREAM", 6);
    Result var0(src0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test6") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test7") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(100);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("old_val", 7);
    Result var6(src6);

    Result var7;

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("new_val", 7);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("a", 1);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map10.insert({src11, var12});

    std::string src13("id", 2);
    Result var13(src13);

    double num14(100);
    Result var14(num14);

    map10.insert({src13, var14});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src15("old_val", 7);
    Result var15(src15);

    std::map<std::string, Result> map16;

    std::string src17("id", 2);
    Result var17(src17);

    double num18(100);
    Result var18(num18);

    map16.insert({src17, var18});

    Result var16(map16);

    map8.insert({src15, var16});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test8") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(100);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("old_val", 7);
    Result var6(src6);

    Result var7;

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("new_val", 7);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("a", 1);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map10.insert({src11, var12});

    std::string src13("id", 2);
    Result var13(src13);

    double num14(100);
    Result var14(num14);

    map10.insert({src13, var14});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src15("old_val", 7);
    Result var15(src15);

    std::map<std::string, Result> map16;

    std::string src17("id", 2);
    Result var17(src17);

    double num18(100);
    Result var18(num18);

    map16.insert({src17, var18});

    Result var16(map16);

    map8.insert({src15, var16});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test9") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("a", 1);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    std::string src6("id", 2);
    Result var6(src6);

    double num7(100);
    Result var7(num7);

    map3.insert({src6, var7});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Result var8(src8);

    Result var9;

    map1.insert({src8, var9});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test10") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("new_val", 7);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("a", 1);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    std::string src6("id", 2);
    Result var6(src6);

    double num7(100);
    Result var7(num7);

    map3.insert({src6, var7});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src8("old_val", 7);
    Result var8(src8);

    Result var9;

    map1.insert({src8, var9});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
