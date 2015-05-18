// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

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

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(2);

    std::vector<Result> arr5(5);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Result> arr9(2);

    double num10(1);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(0);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Result> arr12(2);

    double num13(1);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(1);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Result> arr15(2);

    double num16(0);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(1);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    Result var15(arr15);

    arr5.insert(arr5.end(), var15);

    std::vector<Result> arr18(2);

    double num19(0);
    Result var19(num19);

    arr18.insert(arr18.end(), var19);

    double num20(0);
    Result var20(num20);

    arr18.insert(arr18.end(), var20);

    Result var18(arr18);

    arr5.insert(arr5.end(), var18);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    std::vector<Result> arr21(5);

    std::vector<Result> arr22(2);

    double num23(0.1);
    Result var23(num23);

    arr22.insert(arr22.end(), var23);

    double num24(0.1);
    Result var24(num24);

    arr22.insert(arr22.end(), var24);

    Result var22(arr22);

    arr21.insert(arr21.end(), var22);

    std::vector<Result> arr25(2);

    double num26(0.9);
    Result var26(num26);

    arr25.insert(arr25.end(), var26);

    double num27(0.1);
    Result var27(num27);

    arr25.insert(arr25.end(), var27);

    Result var25(arr25);

    arr21.insert(arr21.end(), var25);

    std::vector<Result> arr28(2);

    double num29(0.9);
    Result var29(num29);

    arr28.insert(arr28.end(), var29);

    double num30(0.9);
    Result var30(num30);

    arr28.insert(arr28.end(), var30);

    Result var28(arr28);

    arr21.insert(arr21.end(), var28);

    std::vector<Result> arr31(2);

    double num32(0.1);
    Result var32(num32);

    arr31.insert(arr31.end(), var32);

    double num33(0.9);
    Result var33(num33);

    arr31.insert(arr31.end(), var33);

    Result var31(arr31);

    arr21.insert(arr21.end(), var31);

    std::vector<Result> arr34(2);

    double num35(0.1);
    Result var35(num35);

    arr34.insert(arr34.end(), var35);

    double num36(0.1);
    Result var36(num36);

    arr34.insert(arr34.end(), var36);

    Result var34(arr34);

    arr21.insert(arr21.end(), var34);

    Result var21(arr21);

    arr4.insert(arr4.end(), var21);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src37("type", 4);
    Result var37(src37);

    std::string src38("Polygon", 7);
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

    std::string src1("$reql_type$", 11);
    Result var1(src1);

    std::string src2("GEOMETRY", 8);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("coordinates", 11);
    Result var3(src3);

    std::vector<Result> arr4(2);

    std::vector<Result> arr5(5);

    std::vector<Result> arr6(2);

    double num7(0);
    Result var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Result var8(num8);

    arr6.insert(arr6.end(), var8);

    Result var6(arr6);

    arr5.insert(arr5.end(), var6);

    std::vector<Result> arr9(2);

    double num10(1);
    Result var10(num10);

    arr9.insert(arr9.end(), var10);

    double num11(0);
    Result var11(num11);

    arr9.insert(arr9.end(), var11);

    Result var9(arr9);

    arr5.insert(arr5.end(), var9);

    std::vector<Result> arr12(2);

    double num13(1);
    Result var13(num13);

    arr12.insert(arr12.end(), var13);

    double num14(1);
    Result var14(num14);

    arr12.insert(arr12.end(), var14);

    Result var12(arr12);

    arr5.insert(arr5.end(), var12);

    std::vector<Result> arr15(2);

    double num16(0);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(1);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    Result var15(arr15);

    arr5.insert(arr5.end(), var15);

    std::vector<Result> arr18(2);

    double num19(0);
    Result var19(num19);

    arr18.insert(arr18.end(), var19);

    double num20(0);
    Result var20(num20);

    arr18.insert(arr18.end(), var20);

    Result var18(arr18);

    arr5.insert(arr5.end(), var18);

    Result var5(arr5);

    arr4.insert(arr4.end(), var5);

    std::vector<Result> arr21(5);

    std::vector<Result> arr22(2);

    double num23(0);
    Result var23(num23);

    arr22.insert(arr22.end(), var23);

    double num24(0);
    Result var24(num24);

    arr22.insert(arr22.end(), var24);

    Result var22(arr22);

    arr21.insert(arr21.end(), var22);

    std::vector<Result> arr25(2);

    double num26(0.1);
    Result var26(num26);

    arr25.insert(arr25.end(), var26);

    double num27(0.9);
    Result var27(num27);

    arr25.insert(arr25.end(), var27);

    Result var25(arr25);

    arr21.insert(arr21.end(), var25);

    std::vector<Result> arr28(2);

    double num29(0.9);
    Result var29(num29);

    arr28.insert(arr28.end(), var29);

    double num30(0.9);
    Result var30(num30);

    arr28.insert(arr28.end(), var30);

    Result var28(arr28);

    arr21.insert(arr21.end(), var28);

    std::vector<Result> arr31(2);

    double num32(0.9);
    Result var32(num32);

    arr31.insert(arr31.end(), var32);

    double num33(0.1);
    Result var33(num33);

    arr31.insert(arr31.end(), var33);

    Result var31(arr31);

    arr21.insert(arr21.end(), var31);

    std::vector<Result> arr34(2);

    double num35(0);
    Result var35(num35);

    arr34.insert(arr34.end(), var35);

    double num36(0);
    Result var36(num36);

    arr34.insert(arr34.end(), var36);

    Result var34(arr34);

    arr21.insert(arr21.end(), var34);

    Result var21(arr21);

    arr4.insert(arr4.end(), var21);

    Result var4(arr4);

    map0.insert({src3, var4});

    std::string src37("type", 4);
    Result var37(src37);

    std::string src38("Polygon", 7);
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
