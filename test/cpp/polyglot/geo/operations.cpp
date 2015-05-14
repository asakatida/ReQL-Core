// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test basic geometry operators", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("89011.262538353315904", 21);
    Result var0(src0);
  }

  SECTION("test1") {
    std::string src0("110968.30443995493988", 21);
    Result var0(src0);
  }

  SECTION("test2") {
    Result var0(true);
  }

  SECTION("test3") {
    std::string src0("89011.262538353315904", 21);
    Result var0(src0);
  }

  SECTION("test4") {
    Result var0(true);
  }

  SECTION("test5") {
    Result var0(true);
  }

  SECTION("test6") {
    Result var0(true);
  }

  SECTION("test7") {
    Result var0(true);
  }

  SECTION("test8") {
    Result var0(true);
  }

  SECTION("test9") {
    Result var0(true);
  }

  SECTION("test10") {
    Result var0(true);
  }

  SECTION("test11") {
    std::string src0("0.01393875509649327056", 22);
    Result var0(src0);
  }

  SECTION("test12") {
    std::string src0("0", 1);
    Result var0(src0);
  }

  SECTION("test13") {
    std::string src0("40007862.91725089401", 20);
    Result var0(src0);
  }

  SECTION("test14") {
    std::string src0("40007862.91725089401", 20);
    Result var0(src0);
  }

  SECTION("test15") {
    std::string src0("0", 1);
    Result var0(src0);
  }

  SECTION("test16") {
    std::string src0("0", 1);
    Result var0(src0);
  }

  SECTION("test17") {
    Result var0(true);
  }

  SECTION("test18") {
    std::string src0("492471.49900552548934", 21);
    Result var0(src0);
  }

  SECTION("test19") {
    std::string src0("492471.49900552548934", 21);
    Result var0(src0);
  }

  SECTION("test20") {
    std::string src0("0", 1);
    Result var0(src0);
  }

  SECTION("test21") {
    std::string src0("0", 1);
    Result var0(src0);
  }

  SECTION("test22") {
    Result var0(false);
  }

  SECTION("test23") {
    Result var0(true);
  }

  SECTION("test24") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(2);

    std::vector<Result> arr3(5);

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

    double num8(1);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(0);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(1);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(1);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(1);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr3.insert(arr3.end(), var13);

    std::vector<Result> arr16(2);

    double num17(0);
    Result var17(num17);

    arr16.insert(arr16.end(), var17);

    double num18(0);
    Result var18(num18);

    arr16.insert(arr16.end(), var18);

    Result var16(arr16);

    arr3.insert(arr3.end(), var16);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    std::vector<Result> arr19(5);

    std::vector<Result> arr20(2);

    double num21(0.1);
    Result var21(num21);

    arr20.insert(arr20.end(), var21);

    double num22(0.1);
    Result var22(num22);

    arr20.insert(arr20.end(), var22);

    Result var20(arr20);

    arr19.insert(arr19.end(), var20);

    std::vector<Result> arr23(2);

    double num24(0.9);
    Result var24(num24);

    arr23.insert(arr23.end(), var24);

    double num25(0.1);
    Result var25(num25);

    arr23.insert(arr23.end(), var25);

    Result var23(arr23);

    arr19.insert(arr19.end(), var23);

    std::vector<Result> arr26(2);

    double num27(0.9);
    Result var27(num27);

    arr26.insert(arr26.end(), var27);

    double num28(0.9);
    Result var28(num28);

    arr26.insert(arr26.end(), var28);

    Result var26(arr26);

    arr19.insert(arr19.end(), var26);

    std::vector<Result> arr29(2);

    double num30(0.1);
    Result var30(num30);

    arr29.insert(arr29.end(), var30);

    double num31(0.9);
    Result var31(num31);

    arr29.insert(arr29.end(), var31);

    Result var29(arr29);

    arr19.insert(arr19.end(), var29);

    std::vector<Result> arr32(2);

    double num33(0.1);
    Result var33(num33);

    arr32.insert(arr32.end(), var33);

    double num34(0.1);
    Result var34(num34);

    arr32.insert(arr32.end(), var34);

    Result var32(arr32);

    arr19.insert(arr19.end(), var32);

    Result var19(arr19);

    arr2.insert(arr2.end(), var19);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src35("type", 4);
    Result var35(src35);

    std::string src36("Polygon", 7);
    Result var36(src36);

    map0.insert({src35, var36});

    std::string src37("$reql_type$", 11);
    Result var37(src37);

    std::string src38("GEOMETRY", 8);
    Result var38(src38);

    map0.insert({src37, var38});

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

  SECTION("test28") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test29") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test30") {
    std::map<std::string, Result> map0;

    std::string src1("coordinates", 11);
    Result var1(src1);

    std::vector<Result> arr2(2);

    std::vector<Result> arr3(5);

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

    double num8(1);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(0);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr3.insert(arr3.end(), var7);

    std::vector<Result> arr10(2);

    double num11(1);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(1);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr3.insert(arr3.end(), var10);

    std::vector<Result> arr13(2);

    double num14(0);
    Result var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(1);
    Result var15(num15);

    arr13.insert(arr13.end(), var15);

    Result var13(arr13);

    arr3.insert(arr3.end(), var13);

    std::vector<Result> arr16(2);

    double num17(0);
    Result var17(num17);

    arr16.insert(arr16.end(), var17);

    double num18(0);
    Result var18(num18);

    arr16.insert(arr16.end(), var18);

    Result var16(arr16);

    arr3.insert(arr3.end(), var16);

    Result var3(arr3);

    arr2.insert(arr2.end(), var3);

    std::vector<Result> arr19(5);

    std::vector<Result> arr20(2);

    double num21(0);
    Result var21(num21);

    arr20.insert(arr20.end(), var21);

    double num22(0);
    Result var22(num22);

    arr20.insert(arr20.end(), var22);

    Result var20(arr20);

    arr19.insert(arr19.end(), var20);

    std::vector<Result> arr23(2);

    double num24(0.1);
    Result var24(num24);

    arr23.insert(arr23.end(), var24);

    double num25(0.9);
    Result var25(num25);

    arr23.insert(arr23.end(), var25);

    Result var23(arr23);

    arr19.insert(arr19.end(), var23);

    std::vector<Result> arr26(2);

    double num27(0.9);
    Result var27(num27);

    arr26.insert(arr26.end(), var27);

    double num28(0.9);
    Result var28(num28);

    arr26.insert(arr26.end(), var28);

    Result var26(arr26);

    arr19.insert(arr19.end(), var26);

    std::vector<Result> arr29(2);

    double num30(0.9);
    Result var30(num30);

    arr29.insert(arr29.end(), var30);

    double num31(0.1);
    Result var31(num31);

    arr29.insert(arr29.end(), var31);

    Result var29(arr29);

    arr19.insert(arr19.end(), var29);

    std::vector<Result> arr32(2);

    double num33(0);
    Result var33(num33);

    arr32.insert(arr32.end(), var33);

    double num34(0);
    Result var34(num34);

    arr32.insert(arr32.end(), var34);

    Result var32(arr32);

    arr19.insert(arr19.end(), var32);

    Result var19(arr19);

    arr2.insert(arr2.end(), var19);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src35("type", 4);
    Result var35(src35);

    std::string src36("Polygon", 7);
    Result var36(src36);

    map0.insert({src35, var36});

    std::string src37("$reql_type$", 11);
    Result var37(src37);

    std::string src38("GEOMETRY", 8);
    Result var38(src38);

    map0.insert({src37, var38});

    Result var0(map0);
  }

  SECTION("test31") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test32") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
