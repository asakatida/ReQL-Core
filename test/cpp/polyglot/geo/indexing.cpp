// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Test ReQL interface to geo indexes", "[cpp][ast]") {

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("deleted", 7);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Result var5(src5);

    double num6(3);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Result var7(src7);

    double num8(0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Result var9(src9);

    double num10(0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
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
    std::map<std::string, Result> map0;

    std::string src1("result", 6);
    Result var1(src1);

    std::string src2("blank", 5);
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

    std::string src2("dist", 4);
    Result var2(src2);

    double num3(0);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("dist", 4);
    Result var9(src9);

    double num10(0.055659745396754216);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Result var11(src11);

    std::map<std::string, Result> map12;

    std::string src13("id", 2);
    Result var13(src13);

    double num14(2);
    Result var14(num14);

    map12.insert({src13, var14});

    Result var12(map12);

    map8.insert({src11, var12});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test39") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("dist", 4);
    Result var2(src2);

    double num3(0);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(2);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("dist", 4);
    Result var9(src9);

    double num10(0.11130264976984369);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Result var11(src11);

    std::map<std::string, Result> map12;

    std::string src13("id", 2);
    Result var13(src13);

    double num14(1);
    Result var14(num14);

    map12.insert({src13, var14});

    Result var12(map12);

    map8.insert({src11, var12});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test40") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("dist", 4);
    Result var2(src2);

    double num3(0);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("dist", 4);
    Result var9(src9);

    double num10(0.055659745396754216);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Result var11(src11);

    std::map<std::string, Result> map12;

    std::string src13("id", 2);
    Result var13(src13);

    double num14(2);
    Result var14(num14);

    map12.insert({src13, var14});

    Result var12(map12);

    map8.insert({src11, var12});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    std::map<std::string, Result> map15;

    std::string src16("dist", 4);
    Result var16(src16);

    double num17(1565109.0992178896);
    Result var17(num17);

    map15.insert({src16, var17});

    std::string src18("doc", 3);
    Result var18(src18);

    std::map<std::string, Result> map19;

    std::string src20("id", 2);
    Result var20(src20);

    double num21(0);
    Result var21(num21);

    map19.insert({src20, var21});

    Result var19(map19);

    map15.insert({src18, var19});

    Result var15(map15);

    arr0.insert(arr0.end(), var15);

    Result var0(arr0);
  }

  SECTION("test41") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("dist", 4);
    Result var2(src2);

    double num3(0);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("dist", 4);
    Result var9(src9);

    double num10(0.055659745396754216);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Result var11(src11);

    std::map<std::string, Result> map12;

    std::string src13("id", 2);
    Result var13(src13);

    double num14(2);
    Result var14(num14);

    map12.insert({src13, var14});

    Result var12(map12);

    map8.insert({src11, var12});

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

    std::string src2("dist", 4);
    Result var2(src2);

    double num3(0);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("dist", 4);
    Result var9(src9);

    double num10(5.565974539675422e-05);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Result var11(src11);

    std::map<std::string, Result> map12;

    std::string src13("id", 2);
    Result var13(src13);

    double num14(2);
    Result var14(num14);

    map12.insert({src13, var14});

    Result var12(map12);

    map8.insert({src11, var12});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    std::map<std::string, Result> map15;

    std::string src16("dist", 4);
    Result var16(src16);

    double num17(1565.1090992178897);
    Result var17(num17);

    map15.insert({src16, var17});

    std::string src18("doc", 3);
    Result var18(src18);

    std::map<std::string, Result> map19;

    std::string src20("id", 2);
    Result var20(src20);

    double num21(0);
    Result var21(num21);

    map19.insert({src20, var21});

    Result var19(map19);

    map15.insert({src18, var19});

    Result var15(map15);

    arr0.insert(arr0.end(), var15);

    Result var0(arr0);
  }

  SECTION("test44") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("dist", 4);
    Result var2(src2);

    double num3(0);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("dist", 4);
    Result var9(src9);

    double num10(8.726646259990191e-09);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Result var11(src11);

    std::map<std::string, Result> map12;

    std::string src13("id", 2);
    Result var13(src13);

    double num14(2);
    Result var14(num14);

    map12.insert({src13, var14});

    Result var12(map12);

    map8.insert({src11, var12});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    std::map<std::string, Result> map15;

    std::string src16("dist", 4);
    Result var16(src16);

    double num17(0.24619691677893205);
    Result var17(num17);

    map15.insert({src16, var17});

    std::string src18("doc", 3);
    Result var18(src18);

    std::map<std::string, Result> map19;

    std::string src20("id", 2);
    Result var20(src20);

    double num21(0);
    Result var21(num21);

    map19.insert({src20, var21});

    Result var19(map19);

    map15.insert({src18, var19});

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
