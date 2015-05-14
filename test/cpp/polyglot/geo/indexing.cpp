// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test ReQL interface to geo indexes", "[cpp][ast]") {

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(3);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test6") {
    Result var0;
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

    std::string src2("err_regex", 9);
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

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test17") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test18") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test19") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test20") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test21") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test22") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test23") {
    std::string src0("SELECTION<STREAM>", 17);
    Result var0(src0);
  }

  SECTION("test24") {
    std::string src0("SELECTION<STREAM>", 17);
    Result var0(src0);
  }

  SECTION("test25") {
    std::string src0("STREAM", 6);
    Result var0(src0);
  }

  SECTION("test26") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test27") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test28") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test29") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test30") {
    double num0(1);
    Result var0(num0);
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

    std::string src2("err_regex", 9);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test33") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test37") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test38") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("doc", 3);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("dist", 4);
    Result var6(src6);

    double num7(0);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("doc", 3);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("id", 2);
    Result var11(src11);

    double num12(2);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("dist", 4);
    Result var13(src13);

    double num14(0.055659745396754216);
    Result var14(num14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test39") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("doc", 3);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(2);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("dist", 4);
    Result var6(src6);

    double num7(0);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("doc", 3);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("id", 2);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("dist", 4);
    Result var13(src13);

    double num14(0.11130264976984369);
    Result var14(num14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test40") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("doc", 3);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("dist", 4);
    Result var6(src6);

    double num7(0);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("doc", 3);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("id", 2);
    Result var11(src11);

    double num12(2);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("dist", 4);
    Result var13(src13);

    double num14(0.055659745396754216);
    Result var14(num14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    std::map<std::string, Result> map15;

    std::string src16("doc", 3);
    Result var16(src16);

    std::map<std::string, Result> map17;

    std::string src18("id", 2);
    Result var18(src18);

    double num19(0);
    Result var19(num19);

    map17.insert({src18, var19});

    Result var17(map17);

    map15.insert({src16, var17});

    std::string src20("dist", 4);
    Result var20(src20);

    double num21(1565109.0992178896);
    Result var21(num21);

    map15.insert({src20, var21});

    Result var15(map15);

    arr0.insert(arr0.end(), var15);

    Result var0(arr0);
  }

  SECTION("test41") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("doc", 3);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("dist", 4);
    Result var6(src6);

    double num7(0);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("doc", 3);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("id", 2);
    Result var11(src11);

    double num12(2);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("dist", 4);
    Result var13(src13);

    double num14(0.055659745396754216);
    Result var14(num14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test42") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test43") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("doc", 3);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("dist", 4);
    Result var6(src6);

    double num7(0);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("doc", 3);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("id", 2);
    Result var11(src11);

    double num12(2);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("dist", 4);
    Result var13(src13);

    double num14(5.565974539675422e-05);
    Result var14(num14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    std::map<std::string, Result> map15;

    std::string src16("doc", 3);
    Result var16(src16);

    std::map<std::string, Result> map17;

    std::string src18("id", 2);
    Result var18(src18);

    double num19(0);
    Result var19(num19);

    map17.insert({src18, var19});

    Result var17(map17);

    map15.insert({src16, var17});

    std::string src20("dist", 4);
    Result var20(src20);

    double num21(1565.1090992178897);
    Result var21(num21);

    map15.insert({src20, var21});

    Result var15(map15);

    arr0.insert(arr0.end(), var15);

    Result var0(arr0);
  }

  SECTION("test44") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("doc", 3);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("id", 2);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("dist", 4);
    Result var6(src6);

    double num7(0);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("doc", 3);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("id", 2);
    Result var11(src11);

    double num12(2);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("dist", 4);
    Result var13(src13);

    double num14(8.726646259990191e-09);
    Result var14(num14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    std::map<std::string, Result> map15;

    std::string src16("doc", 3);
    Result var16(src16);

    std::map<std::string, Result> map17;

    std::string src18("id", 2);
    Result var18(src18);

    double num19(0);
    Result var19(num19);

    map17.insert({src18, var19});

    Result var17(map17);

    map15.insert({src16, var17});

    std::string src20("dist", 4);
    Result var20(src20);

    double num21(0.24619691677893205);
    Result var21(num21);

    map15.insert({src20, var21});

    Result var15(map15);

    arr0.insert(arr0.end(), var15);

    Result var0(arr0);
  }

  SECTION("test45") {
    std::string src0("ARRAY", 5);
    Result var0(src0);
  }

  SECTION("test46") {
    std::string src0("ARRAY", 5);
    Result var0(src0);
  }
}
