// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test geo constructors", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("Point", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("Point", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(-90);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("Point", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(90);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("Point", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(2);

    double num7(-180);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("Point", 5);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(2);

    double num7(180);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
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

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("LineString", 10);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(2);

    std::vector<Result> arr7(2);

    double num8(0);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(0);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr6.insert(arr6.end(), var7);

    std::vector<Result> arr10(2);

    double num11(0);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(1);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr6.insert(arr6.end(), var10);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test13") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test14") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test15") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("LineString", 10);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(3);

    std::vector<Result> arr7(2);

    double num8(0);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(0);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr6.insert(arr6.end(), var7);

    std::vector<Result> arr10(2);

    double num11(0);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(1);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr6.insert(arr6.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(0);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr6.insert(arr6.end(), var13);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("LineString", 10);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(3);

    std::vector<Result> arr7(2);

    double num8(0);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(0);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr6.insert(arr6.end(), var7);

    std::vector<Result> arr10(2);

    double num11(0);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(1);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr6.insert(arr6.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(0);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr6.insert(arr6.end(), var13);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test17") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test19") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test20") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test21") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test22") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("Polygon", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(1);

    std::vector<Result> arr7(4);

    std::vector<Result> arr8(2);

    double num9(0);
    Result var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(0);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr7.insert(arr7.end(), var8);

    std::vector<Result> arr11(2);

    double num12(0);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(1);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(1);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(0);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(0);
    Result var19(num19);

    arr17.insert(arr17.end(), var19);

    Result var17(arr17);

    arr7.insert(arr7.end(), var17);

    Result var7(arr7);

    arr6.insert(arr6.end(), var7);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test23") {
    std::map<std::string, Result> map0;

    std::string src1("type", 4);
    Result var1(src1);

    std::string src2("Polygon", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("$reql_type$", 11);
    Result var3(src3);

    std::string src4("GEOMETRY", 8);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("coordinates", 11);
    Result var5(src5);

    std::vector<Result> arr6(1);

    std::vector<Result> arr7(4);

    std::vector<Result> arr8(2);

    double num9(0);
    Result var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(0);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr7.insert(arr7.end(), var8);

    std::vector<Result> arr11(2);

    double num12(0);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(1);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(1);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(0);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(0);
    Result var19(num19);

    arr17.insert(arr17.end(), var19);

    Result var17(arr17);

    arr7.insert(arr7.end(), var17);

    Result var7(arr7);

    arr6.insert(arr6.end(), var7);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test24") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test25") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test26") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test27") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
