// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test geoJSON conversion", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Query> map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GEOMETRY", 8);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Query var3(src3);

    std::vector<Query> arr4(2);

    double num5(0);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(0);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src7("type", 4);
    Query var7(src7);

    std::string src8("Point", 5);
    Query var8(src8);

    map0.insert({src7, var8});

    Query var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Query> map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GEOMETRY", 8);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Query var3(src3);

    std::vector<Query> arr4(2);

    std::vector<Query> arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(0);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    std::vector<Query> arr8(2);

    double num9(0);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(1);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src11("type", 4);
    Query var11(src11);

    std::string src12("LineString", 10);
    Query var12(src12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Query> map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GEOMETRY", 8);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Query var3(src3);

    std::vector<Query> arr4(1);

    std::vector<Query> arr5(4);

    std::vector<Query> arr6(2);

    double num7(0);
    Query var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Query var8(num8);

    arr6.insert(arr6.end(), var8);

    Query var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Query> arr9(2);

    double num10(0);
    Query var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(1);
    Query var11(num11);

    arr9.insert(arr9.end(), var11);

    Query var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Query> arr12(2);

    double num13(1);
    Query var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(0);
    Query var14(num14);

    arr12.insert(arr12.end(), var14);

    Query var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Query> arr15(2);

    double num16(0);
    Query var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(0);
    Query var17(num17);

    arr15.insert(arr15.end(), var17);

    Query var15(arr15);

    arr5.insert(arr5.end(), var15);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src18("type", 4);
    Query var18(src18);

    std::string src19("Polygon", 7);
    Query var19(src19);

    map0.insert({src18, var19});

    Query var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Query> map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GEOMETRY", 8);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Query var3(src3);

    std::vector<Query> arr4(2);

    double num5(0);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(0);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src7("crs", 3);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    std::string src9("type", 4);
    Query var9(src9);

    std::string src10("Point", 5);
    Query var10(src10);

    map0.insert({src9, var10});

    Query var0(map0);
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
}
