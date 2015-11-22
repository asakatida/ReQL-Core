// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test basic geometry operators", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("89011.26253835332", 17);
    Query var0(src0);
  }

  SECTION("test1") {
    std::string src0("110968.30443995494", 18);
    Query var0(src0);
  }

  SECTION("test2") {
    Query var0(true);
  }

  SECTION("test3") {
    std::string src0("89011.26253835332", 17);
    Query var0(src0);
  }

  SECTION("test4") {
    Query var0(true);
  }

  SECTION("test5") {
    Query var0(true);
  }

  SECTION("test6") {
    Query var0(true);
  }

  SECTION("test7") {
    Query var0(true);
  }

  SECTION("test8") {
    Query var0(true);
  }

  SECTION("test9") {
    Query var0(true);
  }

  SECTION("test10") {
    Query var0(true);
  }

  SECTION("test11") {
    std::string src0("0.01393875509649327", 19);
    Query var0(src0);
  }

  SECTION("test12") {
    std::string src0("0", 1);
    Query var0(src0);
  }

  SECTION("test13") {
    std::string src0("40007862.917250897", 18);
    Query var0(src0);
  }

  SECTION("test14") {
    std::string src0("40007862.917250897", 18);
    Query var0(src0);
  }

  SECTION("test15") {
    std::string src0("0", 1);
    Query var0(src0);
  }

  SECTION("test16") {
    std::string src0("0", 1);
    Query var0(src0);
  }

  SECTION("test17") {
    Query var0(true);
  }

  SECTION("test18") {
    std::string src0("492471.4990055255", 17);
    Query var0(src0);
  }

  SECTION("test19") {
    std::string src0("492471.4990055255", 17);
    Query var0(src0);
  }

  SECTION("test20") {
    std::string src0("0", 1);
    Query var0(src0);
  }

  SECTION("test21") {
    std::string src0("0", 1);
    Query var0(src0);
  }

  SECTION("test22") {
    Query var0(false);
  }

  SECTION("test23") {
    Query var0(true);
  }

  SECTION("test24") {
    std::map<std::string, Query> map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GEOMETRY", 8);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Query var3(src3);

    std::vector<Query> arr4(2);

    std::vector<Query> arr5(5);

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

    double num10(1);
    Query var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(0);
    Query var11(num11);

    arr9.insert(arr9.end(), var11);

    Query var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Query> arr12(2);

    double num13(1);
    Query var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(1);
    Query var14(num14);

    arr12.insert(arr12.end(), var14);

    Query var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Query> arr15(2);

    double num16(0);
    Query var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(1);
    Query var17(num17);

    arr15.insert(arr15.end(), var17);

    Query var15(arr15);

    arr5.insert(arr5.end(), var15);

    std::vector<Query> arr18(2);

    double num19(0);
    Query var19(num19);

    arr18.insert(arr18.end(), var19);

    double num20(0);
    Query var20(num20);

    arr18.insert(arr18.end(), var20);

    Query var18(arr18);

    arr5.insert(arr5.end(), var18);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    std::vector<Query> arr21(5);

    std::vector<Query> arr22(2);

    double num23(0.1);
    Query var23(num23);

    arr22.insert(arr22.end(), var23);

    double num24(0.1);
    Query var24(num24);

    arr22.insert(arr22.end(), var24);

    Query var22(arr22);

    arr21.insert(arr21.end(), var22);

    std::vector<Query> arr25(2);

    double num26(0.9);
    Query var26(num26);

    arr25.insert(arr25.end(), var26);

    double num27(0.1);
    Query var27(num27);

    arr25.insert(arr25.end(), var27);

    Query var25(arr25);

    arr21.insert(arr21.end(), var25);

    std::vector<Query> arr28(2);

    double num29(0.9);
    Query var29(num29);

    arr28.insert(arr28.end(), var29);

    double num30(0.9);
    Query var30(num30);

    arr28.insert(arr28.end(), var30);

    Query var28(arr28);

    arr21.insert(arr21.end(), var28);

    std::vector<Query> arr31(2);

    double num32(0.1);
    Query var32(num32);

    arr31.insert(arr31.end(), var32);

    double num33(0.9);
    Query var33(num33);

    arr31.insert(arr31.end(), var33);

    Query var31(arr31);

    arr21.insert(arr21.end(), var31);

    std::vector<Query> arr34(2);

    double num35(0.1);
    Query var35(num35);

    arr34.insert(arr34.end(), var35);

    double num36(0.1);
    Query var36(num36);

    arr34.insert(arr34.end(), var36);

    Query var34(arr34);

    arr21.insert(arr21.end(), var34);

    Query var21(arr21);

    arr4.insert(arr4.end(), var21);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src37("type", 4);
    Query var37(src37);

    std::string src38("Polygon", 7);
    Query var38(src38);

    map0.insert({src37, var38});

    Query var0(map0);
  }

  SECTION("test25") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test26") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test27") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test28") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test29") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test30") {
    std::map<std::string, Query> map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GEOMETRY", 8);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Query var3(src3);

    std::vector<Query> arr4(2);

    std::vector<Query> arr5(5);

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

    double num10(1);
    Query var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(0);
    Query var11(num11);

    arr9.insert(arr9.end(), var11);

    Query var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Query> arr12(2);

    double num13(1);
    Query var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(1);
    Query var14(num14);

    arr12.insert(arr12.end(), var14);

    Query var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Query> arr15(2);

    double num16(0);
    Query var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(1);
    Query var17(num17);

    arr15.insert(arr15.end(), var17);

    Query var15(arr15);

    arr5.insert(arr5.end(), var15);

    std::vector<Query> arr18(2);

    double num19(0);
    Query var19(num19);

    arr18.insert(arr18.end(), var19);

    double num20(0);
    Query var20(num20);

    arr18.insert(arr18.end(), var20);

    Query var18(arr18);

    arr5.insert(arr5.end(), var18);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    std::vector<Query> arr21(5);

    std::vector<Query> arr22(2);

    double num23(0);
    Query var23(num23);

    arr22.insert(arr22.end(), var23);

    double num24(0);
    Query var24(num24);

    arr22.insert(arr22.end(), var24);

    Query var22(arr22);

    arr21.insert(arr21.end(), var22);

    std::vector<Query> arr25(2);

    double num26(0.1);
    Query var26(num26);

    arr25.insert(arr25.end(), var26);

    double num27(0.9);
    Query var27(num27);

    arr25.insert(arr25.end(), var27);

    Query var25(arr25);

    arr21.insert(arr21.end(), var25);

    std::vector<Query> arr28(2);

    double num29(0.9);
    Query var29(num29);

    arr28.insert(arr28.end(), var29);

    double num30(0.9);
    Query var30(num30);

    arr28.insert(arr28.end(), var30);

    Query var28(arr28);

    arr21.insert(arr21.end(), var28);

    std::vector<Query> arr31(2);

    double num32(0.9);
    Query var32(num32);

    arr31.insert(arr31.end(), var32);

    double num33(0.1);
    Query var33(num33);

    arr31.insert(arr31.end(), var33);

    Query var31(arr31);

    arr21.insert(arr21.end(), var31);

    std::vector<Query> arr34(2);

    double num35(0);
    Query var35(num35);

    arr34.insert(arr34.end(), var35);

    double num36(0);
    Query var36(num36);

    arr34.insert(arr34.end(), var36);

    Query var34(arr34);

    arr21.insert(arr21.end(), var34);

    Query var21(arr21);

    arr4.insert(arr4.end(), var21);

    Query var4(arr4);

    map0.insert({src3, var4});

    std::string src37("type", 4);
    Query var37(src37);

    std::string src38("Polygon", 7);
    Query var38(src38);

    map0.insert({src37, var38});

    Query var0(map0);
  }

  SECTION("test31") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test32") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
