// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test geometric primitive constructors", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::vector<Result> arr5(4);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(-9.04369477050382e-06);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Result> arr9(2);

    double num10(-7.779638566553426e-06);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(4.5218473852518965e-06);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Result> arr12(2);

    double num13(7.779638566553426e-06);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(4.5218473852518965e-06);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Result> arr15(2);

    double num16(0);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(-9.04369477050382e-06);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    Result var15(arr15);

    arr5.insert(arr5.end(), var15);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src18("type", 4);
    Result var18(src18);

    std::string src19("Polygon", 7);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::vector<Result> arr5(4);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(-9.04369477050382e-06);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Result> arr9(2);

    double num10(-7.779638566553426e-06);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(4.5218473852518965e-06);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Result> arr12(2);

    double num13(7.779638566553426e-06);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(4.5218473852518965e-06);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Result> arr15(2);

    double num16(0);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(-9.04369477050382e-06);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    Result var15(arr15);

    arr5.insert(arr5.end(), var15);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src18("type", 4);
    Result var18(src18);

    std::string src19("Polygon", 7);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(4);

    std::vector<Result> arr5(2);

    double num6(0);
    Result var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(-9.04369477050382e-06);
    Result var7(num7);

    arr5.insert(arr5.end(), var7);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    std::vector<Result> arr8(2);

    double num9(-7.779638566553426e-06);
    Result var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(4.5218473852518965e-06);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    Result var8(arr8);

    arr4.insert(arr4.end(), var8);

    std::vector<Result> arr11(2);

    double num12(7.779638566553426e-06);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(4.5218473852518965e-06);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr4.insert(arr4.end(), var11);

    std::vector<Result> arr14(2);

    double num15(0);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(-9.04369477050382e-06);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr4.insert(arr4.end(), var14);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src17("type", 4);
    Result var17(src17);

    std::string src18("LineString", 10);
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

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::vector<Result> arr5(4);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(-9.04369477050382e-06);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Result> arr9(2);

    double num10(-7.779638566553426e-06);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(4.5218473852518965e-06);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Result> arr12(2);

    double num13(7.779638566553426e-06);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(4.5218473852518965e-06);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Result> arr15(2);

    double num16(0);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(-9.04369477050382e-06);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    Result var15(arr15);

    arr5.insert(arr5.end(), var15);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src18("type", 4);
    Result var18(src18);

    std::string src19("Polygon", 7);
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

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::vector<Result> arr5(4);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(-5.729577951308232);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Result> arr9(2);

    double num10(-4.966092947444857);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(2.861205754495701);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Result> arr12(2);

    double num13(4.966092947444857);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(2.861205754495701);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Result> arr15(2);

    double num16(0);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(-5.729577951308232);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    Result var15(arr15);

    arr5.insert(arr5.end(), var15);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src18("type", 4);
    Result var18(src18);

    std::string src19("Polygon", 7);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::vector<Result> arr5(4);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(-9.04369477050382e-06);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Result> arr9(2);

    double num10(-7.779638566553426e-06);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(4.5218473852518965e-06);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Result> arr12(2);

    double num13(7.779638566553426e-06);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(4.5218473852518965e-06);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Result> arr15(2);

    double num16(0);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(-9.04369477050382e-06);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    Result var15(arr15);

    arr5.insert(arr5.end(), var15);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src18("type", 4);
    Result var18(src18);

    std::string src19("Polygon", 7);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::vector<Result> arr5(4);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(-9.04369477050382e-06);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Result> arr9(2);

    double num10(-7.779638566553426e-06);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(4.5218473852518965e-06);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Result> arr12(2);

    double num13(7.779638566553426e-06);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(4.5218473852518965e-06);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Result> arr15(2);

    double num16(0);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(-9.04369477050382e-06);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    Result var15(arr15);

    arr5.insert(arr5.end(), var15);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src18("type", 4);
    Result var18(src18);

    std::string src19("Polygon", 7);
    Result var19(src19);

    map0.insert({src18, var19});

    Result var0(map0);
  }
}
