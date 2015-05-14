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

    std::vector<Result> arr6(2);

    std::vector<Result> arr7(5);

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

    double num12(1);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(0);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(1);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(1);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(1);
    Result var19(num19);

    arr17.insert(arr17.end(), var19);

    Result var17(arr17);

    arr7.insert(arr7.end(), var17);

    std::vector<Result> arr20(2);

    double num21(0);
    Result var21(num21);

    arr20.insert(arr20.end(), var21);

    double num22(0);
    Result var22(num22);

    arr20.insert(arr20.end(), var22);

    Result var20(arr20);

    arr7.insert(arr7.end(), var20);

    Result var7(arr7);

    arr6.insert(arr6.end(), var7);

    std::vector<Result> arr23(5);

    std::vector<Result> arr24(2);

    double num25(0.1);
    Result var25(num25);

    arr24.insert(arr24.end(), var25);

    double num26(0.1);
    Result var26(num26);

    arr24.insert(arr24.end(), var26);

    Result var24(arr24);

    arr23.insert(arr23.end(), var24);

    std::vector<Result> arr27(2);

    double num28(0.9);
    Result var28(num28);

    arr27.insert(arr27.end(), var28);

    double num29(0.1);
    Result var29(num29);

    arr27.insert(arr27.end(), var29);

    Result var27(arr27);

    arr23.insert(arr23.end(), var27);

    std::vector<Result> arr30(2);

    double num31(0.9);
    Result var31(num31);

    arr30.insert(arr30.end(), var31);

    double num32(0.9);
    Result var32(num32);

    arr30.insert(arr30.end(), var32);

    Result var30(arr30);

    arr23.insert(arr23.end(), var30);

    std::vector<Result> arr33(2);

    double num34(0.1);
    Result var34(num34);

    arr33.insert(arr33.end(), var34);

    double num35(0.9);
    Result var35(num35);

    arr33.insert(arr33.end(), var35);

    Result var33(arr33);

    arr23.insert(arr23.end(), var33);

    std::vector<Result> arr36(2);

    double num37(0.1);
    Result var37(num37);

    arr36.insert(arr36.end(), var37);

    double num38(0.1);
    Result var38(num38);

    arr36.insert(arr36.end(), var38);

    Result var36(arr36);

    arr23.insert(arr23.end(), var36);

    Result var23(arr23);

    arr6.insert(arr6.end(), var23);

    Result var6(arr6);

    map0.insert({src5, var6});

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

    std::vector<Result> arr6(2);

    std::vector<Result> arr7(5);

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

    double num12(1);
    Result var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(0);
    Result var13(num13);

    arr11.insert(arr11.end(), var13);

    Result var11(arr11);

    arr7.insert(arr7.end(), var11);

    std::vector<Result> arr14(2);

    double num15(1);
    Result var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(1);
    Result var16(num16);

    arr14.insert(arr14.end(), var16);

    Result var14(arr14);

    arr7.insert(arr7.end(), var14);

    std::vector<Result> arr17(2);

    double num18(0);
    Result var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(1);
    Result var19(num19);

    arr17.insert(arr17.end(), var19);

    Result var17(arr17);

    arr7.insert(arr7.end(), var17);

    std::vector<Result> arr20(2);

    double num21(0);
    Result var21(num21);

    arr20.insert(arr20.end(), var21);

    double num22(0);
    Result var22(num22);

    arr20.insert(arr20.end(), var22);

    Result var20(arr20);

    arr7.insert(arr7.end(), var20);

    Result var7(arr7);

    arr6.insert(arr6.end(), var7);

    std::vector<Result> arr23(5);

    std::vector<Result> arr24(2);

    double num25(0);
    Result var25(num25);

    arr24.insert(arr24.end(), var25);

    double num26(0);
    Result var26(num26);

    arr24.insert(arr24.end(), var26);

    Result var24(arr24);

    arr23.insert(arr23.end(), var24);

    std::vector<Result> arr27(2);

    double num28(0.1);
    Result var28(num28);

    arr27.insert(arr27.end(), var28);

    double num29(0.9);
    Result var29(num29);

    arr27.insert(arr27.end(), var29);

    Result var27(arr27);

    arr23.insert(arr23.end(), var27);

    std::vector<Result> arr30(2);

    double num31(0.9);
    Result var31(num31);

    arr30.insert(arr30.end(), var31);

    double num32(0.9);
    Result var32(num32);

    arr30.insert(arr30.end(), var32);

    Result var30(arr30);

    arr23.insert(arr23.end(), var30);

    std::vector<Result> arr33(2);

    double num34(0.9);
    Result var34(num34);

    arr33.insert(arr33.end(), var34);

    double num35(0.1);
    Result var35(num35);

    arr33.insert(arr33.end(), var35);

    Result var33(arr33);

    arr23.insert(arr23.end(), var33);

    std::vector<Result> arr36(2);

    double num37(0);
    Result var37(num37);

    arr36.insert(arr36.end(), var37);

    double num38(0);
    Result var38(num38);

    arr36.insert(arr36.end(), var38);

    Result var36(arr36);

    arr23.insert(arr23.end(), var36);

    Result var23(arr23);

    arr6.insert(arr6.end(), var23);

    Result var6(arr6);

    map0.insert({src5, var6});

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
