// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test ReQL interface to geo indexes", "[cpp][ast]") {

  SECTION("test1") {
    Types::object map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(3);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    Types::object map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test7") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test8") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err_regex", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test11") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test12") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test17") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test18") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test19") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test20") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test21") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test22") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test23") {
    std::string src0("SELECTION<STREAM>", 17);
    Query var0(src0);
  }

  SECTION("test24") {
    std::string src0("SELECTION<STREAM>", 17);
    Query var0(src0);
  }

  SECTION("test25") {
    std::string src0("STREAM", 6);
    Query var0(src0);
  }

  SECTION("test26") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test27") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test28") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test29") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test30") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test31") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test32") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err_regex", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test33") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test37") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test38") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("dist", 4);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("dist", 4);
    Query var9(src9);

    double num10(0.055659745396754216);
    Query var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Query var11(src11);

    Types::object map12;

    std::string src13("id", 2);
    Query var13(src13);

    double num14(2);
    Query var14(num14);

    map12.insert({src13, var14});

    Query var12(map12);

    map8.insert({src11, var12});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test39") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("dist", 4);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(2);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("dist", 4);
    Query var9(src9);

    double num10(0.11130264976984369);
    Query var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Query var11(src11);

    Types::object map12;

    std::string src13("id", 2);
    Query var13(src13);

    double num14(1);
    Query var14(num14);

    map12.insert({src13, var14});

    Query var12(map12);

    map8.insert({src11, var12});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test40") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("dist", 4);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("dist", 4);
    Query var9(src9);

    double num10(0.055659745396754216);
    Query var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Query var11(src11);

    Types::object map12;

    std::string src13("id", 2);
    Query var13(src13);

    double num14(2);
    Query var14(num14);

    map12.insert({src13, var14});

    Query var12(map12);

    map8.insert({src11, var12});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Types::object map15;

    std::string src16("dist", 4);
    Query var16(src16);

    double num17(1565109.0992178896);
    Query var17(num17);

    map15.insert({src16, var17});

    std::string src18("doc", 3);
    Query var18(src18);

    Types::object map19;

    std::string src20("id", 2);
    Query var20(src20);

    double num21(0);
    Query var21(num21);

    map19.insert({src20, var21});

    Query var19(map19);

    map15.insert({src18, var19});

    Query var15(map15);

    arr0.insert(arr0.end(), var15);

    Query var0(arr0);
  }

  SECTION("test41") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("dist", 4);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("dist", 4);
    Query var9(src9);

    double num10(0.055659745396754216);
    Query var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Query var11(src11);

    Types::object map12;

    std::string src13("id", 2);
    Query var13(src13);

    double num14(2);
    Query var14(num14);

    map12.insert({src13, var14});

    Query var12(map12);

    map8.insert({src11, var12});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test42") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test43") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("dist", 4);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("dist", 4);
    Query var9(src9);

    double num10(5.565974539675422e-05);
    Query var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Query var11(src11);

    Types::object map12;

    std::string src13("id", 2);
    Query var13(src13);

    double num14(2);
    Query var14(num14);

    map12.insert({src13, var14});

    Query var12(map12);

    map8.insert({src11, var12});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Types::object map15;

    std::string src16("dist", 4);
    Query var16(src16);

    double num17(1565.1090992178897);
    Query var17(num17);

    map15.insert({src16, var17});

    std::string src18("doc", 3);
    Query var18(src18);

    Types::object map19;

    std::string src20("id", 2);
    Query var20(src20);

    double num21(0);
    Query var21(num21);

    map19.insert({src20, var21});

    Query var19(map19);

    map15.insert({src18, var19});

    Query var15(map15);

    arr0.insert(arr0.end(), var15);

    Query var0(arr0);
  }

  SECTION("test44") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("dist", 4);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("doc", 3);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("dist", 4);
    Query var9(src9);

    double num10(8.726646259990191e-09);
    Query var10(num10);

    map8.insert({src9, var10});

    std::string src11("doc", 3);
    Query var11(src11);

    Types::object map12;

    std::string src13("id", 2);
    Query var13(src13);

    double num14(2);
    Query var14(num14);

    map12.insert({src13, var14});

    Query var12(map12);

    map8.insert({src11, var12});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Types::object map15;

    std::string src16("dist", 4);
    Query var16(src16);

    double num17(0.24619691677893205);
    Query var17(num17);

    map15.insert({src16, var17});

    std::string src18("doc", 3);
    Query var18(src18);

    Types::object map19;

    std::string src20("id", 2);
    Query var20(src20);

    double num21(0);
    Query var21(num21);

    map19.insert({src20, var21});

    Query var19(map19);

    map15.insert({src18, var19});

    Query var15(map15);

    arr0.insert(arr0.end(), var15);

    Query var0(arr0);
  }

  SECTION("test45") {
    std::string src0("ARRAY", 5);
    Query var0(src0);
  }

  SECTION("test46") {
    std::string src0("ARRAY", 5);
    Query var0(src0);
  }
}
