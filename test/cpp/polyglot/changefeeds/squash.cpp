// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test changefeed squashing", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("STREAM", 6);
    Result var0(src0);
  }

  SECTION("test1") {
    Result var0;
  }

  SECTION("test2") {
    Result var0;
  }

  SECTION("test3") {
    Result var0;
  }

  SECTION("test4") {
    Result var0;
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

    std::string src2("old_val", 7);
    Result var2(src2);

    Result var3;

    map1.insert({src2, var3});

    std::string src4("new_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(100);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("old_val", 7);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("id", 2);
    Result var11(src11);

    double num12(100);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("new_val", 7);
    Result var13(src13);

    std::map<std::string, Result> map14;

    std::string src15("a", 1);
    Result var15(src15);

    double num16(1);
    Result var16(num16);

    map14.insert({src15, var16});

    std::string src17("id", 2);
    Result var17(src17);

    double num18(100);
    Result var18(num18);

    map14.insert({src17, var18});

    Result var14(map14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test8") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("old_val", 7);
    Result var2(src2);

    Result var3;

    map1.insert({src2, var3});

    std::string src4("new_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(100);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("old_val", 7);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("id", 2);
    Result var11(src11);

    double num12(100);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("new_val", 7);
    Result var13(src13);

    std::map<std::string, Result> map14;

    std::string src15("a", 1);
    Result var15(src15);

    double num16(1);
    Result var16(num16);

    map14.insert({src15, var16});

    std::string src17("id", 2);
    Result var17(src17);

    double num18(100);
    Result var18(num18);

    map14.insert({src17, var18});

    Result var14(map14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test9") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("old_val", 7);
    Result var2(src2);

    Result var3;

    map1.insert({src2, var3});

    std::string src4("new_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("a", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Result var8(src8);

    double num9(100);
    Result var9(num9);

    map5.insert({src8, var9});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test10") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("old_val", 7);
    Result var2(src2);

    Result var3;

    map1.insert({src2, var3});

    std::string src4("new_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("a", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Result var8(src8);

    double num9(100);
    Result var9(num9);

    map5.insert({src8, var9});

    Result var5(map5);

    map1.insert({src4, var5});

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
