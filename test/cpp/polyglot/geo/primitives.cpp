// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test geometric primitive constructors", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::vector<Result> arr3(4);

    std::vector<Result> arr4(2);

    double num5(0);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(-9.04369477050382e-06);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr3.insert(arr3.end(), var4);

    std::vector<Result> arr7(2);

    double num8(-7.779638566553426e-06);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(4.5218473852518965e-06);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(7.779638566553426e-06);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(4.5218473852518965e-06);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(-9.04369477050382e-06);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr3.insert(arr3.end(), var13);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src16("type", 4);
    Result var16(src16);

    std::string src17("Polygon", 7);
    Result var17(src17);

    map0.insert({src16, var17});

    std::string src18("$reql_type$", 11);
    Result var18(src18);

    std::string src19("GEOMETRY", 8);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::vector<Result> arr3(4);

    std::vector<Result> arr4(2);

    double num5(0);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(-9.04369477050382e-06);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr3.insert(arr3.end(), var4);

    std::vector<Result> arr7(2);

    double num8(-7.779638566553426e-06);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(4.5218473852518965e-06);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(7.779638566553426e-06);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(4.5218473852518965e-06);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(-9.04369477050382e-06);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr3.insert(arr3.end(), var13);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src16("type", 4);
    Result var16(src16);

    std::string src17("Polygon", 7);
    Result var17(src17);

    map0.insert({src16, var17});

    std::string src18("$reql_type$", 11);
    Result var18(src18);

    std::string src19("GEOMETRY", 8);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(4);

    std::vector<Result> arr3(2);

    double num4(0);
    Result var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(-9.04369477050382e-06);
    Result var5(num5);

    arr3.insert(arr3.end(), var5);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    std::vector<Result> arr6(2);

    double num7(-7.779638566553426e-06);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(4.5218473852518965e-06);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr2.insert(arr2.end(), var6);

    std::vector<Result> arr9(2);

    double num10(7.779638566553426e-06);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(4.5218473852518965e-06);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr2.insert(arr2.end(), var9);

    std::vector<Result> arr12(2);

    double num13(0);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(-9.04369477050382e-06);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr2.insert(arr2.end(), var12);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src15("type", 4);
    Result var15(src15);

    std::string src16("LineString", 10);
    Result var16(src16);

    map0.insert({src15, var16});

    std::string src17("$reql_type$", 11);
    Result var17(src17);

    std::string src18("GEOMETRY", 8);
    Result var18(src18);

    map0.insert({src17, var18});

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

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::vector<Result> arr3(4);

    std::vector<Result> arr4(2);

    double num5(0);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(-9.04369477050382e-06);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr3.insert(arr3.end(), var4);

    std::vector<Result> arr7(2);

    double num8(-7.779638566553426e-06);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(4.5218473852518965e-06);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(7.779638566553426e-06);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(4.5218473852518965e-06);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(-9.04369477050382e-06);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr3.insert(arr3.end(), var13);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src16("type", 4);
    Result var16(src16);

    std::string src17("Polygon", 7);
    Result var17(src17);

    map0.insert({src16, var17});

    std::string src18("$reql_type$", 11);
    Result var18(src18);

    std::string src19("GEOMETRY", 8);
    Result var19(src19);

    map0.insert({src18, var19});

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

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::vector<Result> arr3(4);

    std::vector<Result> arr4(2);

    double num5(0);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(-5.729577951308232);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr3.insert(arr3.end(), var4);

    std::vector<Result> arr7(2);

    double num8(-4.966092947444857);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(2.861205754495701);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(4.966092947444857);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(2.861205754495701);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(-5.729577951308232);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr3.insert(arr3.end(), var13);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src16("type", 4);
    Result var16(src16);

    std::string src17("Polygon", 7);
    Result var17(src17);

    map0.insert({src16, var17});

    std::string src18("$reql_type$", 11);
    Result var18(src18);

    std::string src19("GEOMETRY", 8);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::vector<Result> arr3(4);

    std::vector<Result> arr4(2);

    double num5(0);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(-9.04369477050382e-06);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr3.insert(arr3.end(), var4);

    std::vector<Result> arr7(2);

    double num8(-7.779638566553426e-06);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(4.5218473852518965e-06);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(7.779638566553426e-06);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(4.5218473852518965e-06);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(-9.04369477050382e-06);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr3.insert(arr3.end(), var13);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src16("type", 4);
    Result var16(src16);

    std::string src17("Polygon", 7);
    Result var17(src17);

    map0.insert({src16, var17});

    std::string src18("$reql_type$", 11);
    Result var18(src18);

    std::string src19("GEOMETRY", 8);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::vector<Result> arr3(4);

    std::vector<Result> arr4(2);

    double num5(0);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(-9.04369477050382e-06);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr3.insert(arr3.end(), var4);

    std::vector<Result> arr7(2);

    double num8(-7.779638566553426e-06);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(4.5218473852518965e-06);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(7.779638566553426e-06);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(4.5218473852518965e-06);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(-9.04369477050382e-06);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr3.insert(arr3.end(), var13);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src16("type", 4);
    Result var16(src16);

    std::string src17("Polygon", 7);
    Result var17(src17);

    map0.insert({src16, var17});

    std::string src18("$reql_type$", 11);
    Result var18(src18);

    std::string src19("GEOMETRY", 8);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }
}
