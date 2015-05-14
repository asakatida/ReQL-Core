// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test geoJSON conversion", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(2);

    double num3(0);
    Result var3(num3);

    arr2.insert(arr2.end(), var3);

    double num4(0);
    Result var4(num4);

    arr2.insert(arr2.end(), var4);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src5("type", 4);
    Result var5(src5);

    std::string src6("Point", 5);
    Result var6(src6);

    map0.insert({src5, var6});

    std::string src7("$reql_type$", 11);
    Result var7(src7);

    std::string src8("GEOMETRY", 8);
    Result var8(src8);

    map0.insert({src7, var8});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(2);

    std::vector<Result> arr3(2);

    double num4(0);
    Result var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(0);
    Result var5(num5);

    arr3.insert(arr3.end(), var5);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(1);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr2.insert(arr2.end(), var6);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src9("type", 4);
    Result var9(src9);

    std::string src10("LineString", 10);
    Result var10(src10);

    map0.insert({src9, var10});

    std::string src11("$reql_type$", 11);
    Result var11(src11);

    std::string src12("GEOMETRY", 8);
    Result var12(src12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::vector<Result> arr3(4);

    std::vector<Result> arr4(2);

    double num5(0);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(0);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr3.insert(arr3.end(), var4);

    std::vector<Result> arr7(2);

    double num8(0);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(1);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(1);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(0);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(0);
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

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

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

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(2);

    double num3(0);
    Result var3(num3);

    arr2.insert(arr2.end(), var3);

    double num4(0);
    Result var4(num4);

    arr2.insert(arr2.end(), var4);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src5("type", 4);
    Result var5(src5);

    std::string src6("Point", 5);
    Result var6(src6);

    map0.insert({src5, var6});

    std::string src7("$reql_type$", 11);
    Result var7(src7);

    std::string src8("GEOMETRY", 8);
    Result var8(src8);

    map0.insert({src7, var8});

    std::string src9("crs", 3);
    Result var9(src9);

    Result var10;

    map0.insert({src9, var10});

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
}
