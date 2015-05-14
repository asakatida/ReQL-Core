// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test geometric primitive constructors", "[cpp][ast]") {

  SECTION("test0") {
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

    double num10(-9.04369477050382e-06);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr7.insert(arr7.end(), var8);

    std::vector<Result> arr11(2);

    double num12(-7.779638566553426e-06);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(4.5218473852518965e-06);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(7.779638566553426e-06);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(4.5218473852518965e-06);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(-9.04369477050382e-06);
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

  SECTION("test1") {
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

    double num10(-9.04369477050382e-06);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr7.insert(arr7.end(), var8);

    std::vector<Result> arr11(2);

    double num12(-7.779638566553426e-06);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(4.5218473852518965e-06);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(7.779638566553426e-06);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(4.5218473852518965e-06);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(-9.04369477050382e-06);
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

  SECTION("test2") {
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

    std::vector<Result> arr6(4);

    std::vector<Result> arr7(2);

    double num8(0);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(-9.04369477050382e-06);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr6.insert(arr6.end(), var7);

    std::vector<Result> arr10(2);

    double num11(-7.779638566553426e-06);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(4.5218473852518965e-06);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr6.insert(arr6.end(), var10);

    std::vector<Result> arr13(2);

    double num14(7.779638566553426e-06);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(4.5218473852518965e-06);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr6.insert(arr6.end(), var13);

    std::vector<Result> arr16(2);

    double num17(0);
    Result var17(num17);

    arr16.insert(arr16.end(), var17);

    double num18(-9.04369477050382e-06);
    Result var18(num18);

    arr16.insert(arr16.end(), var18);

    Result var16(arr16);

    arr6.insert(arr6.end(), var16);

    Result var6(arr6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
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

    double num10(-9.04369477050382e-06);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr7.insert(arr7.end(), var8);

    std::vector<Result> arr11(2);

    double num12(-7.779638566553426e-06);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(4.5218473852518965e-06);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(7.779638566553426e-06);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(4.5218473852518965e-06);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(-9.04369477050382e-06);
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

    double num10(-5.729577951308232);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr7.insert(arr7.end(), var8);

    std::vector<Result> arr11(2);

    double num12(-4.966092947444857);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(2.861205754495701);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(4.966092947444857);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(2.861205754495701);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(-5.729577951308232);
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

  SECTION("test7") {
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

    double num10(-9.04369477050382e-06);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr7.insert(arr7.end(), var8);

    std::vector<Result> arr11(2);

    double num12(-7.779638566553426e-06);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(4.5218473852518965e-06);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(7.779638566553426e-06);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(4.5218473852518965e-06);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(-9.04369477050382e-06);
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

  SECTION("test8") {
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

    double num10(-9.04369477050382e-06);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr7.insert(arr7.end(), var8);

    std::vector<Result> arr11(2);

    double num12(-7.779638566553426e-06);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(4.5218473852518965e-06);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(7.779638566553426e-06);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(4.5218473852518965e-06);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(-9.04369477050382e-06);
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
}
