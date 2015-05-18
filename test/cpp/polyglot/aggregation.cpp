// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests that manipulation data in tables", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(100);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(100);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(100);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test5") {
    Types::object map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(1);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test6") {
    double num0(150);
    Query var0(num0);
  }

  SECTION("test7") {
    double num0(150);
    Query var0(num0);
  }

  SECTION("test8") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(1200);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(1225);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(1250);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(1275);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test9") {
    double num0(1.5);
    Query var0(num0);
  }

  SECTION("test10") {
    double num0(1.5);
    Query var0(num0);
  }

  SECTION("test11") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(48);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(49);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(50);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(51);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test12") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test13") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test14") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test15") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    Types::object map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Query var8(src8);

    double num9(0);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map10;

    std::string src11("group", 5);
    Query var11(src11);

    double num12(1);
    Query var12(num12);

    map10.insert({src11, var12});

    std::string src13("reduction", 9);
    Query var13(src13);

    Types::object map14;

    std::string src15("a", 1);
    Query var15(src15);

    double num16(1);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("id", 2);
    Query var17(src17);

    double num18(1);
    Query var18(num18);

    map14.insert({src17, var18});

    Query var14(map14);

    map10.insert({src13, var14});

    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Types::object map19;

    std::string src20("group", 5);
    Query var20(src20);

    double num21(2);
    Query var21(num21);

    map19.insert({src20, var21});

    std::string src22("reduction", 9);
    Query var22(src22);

    Types::object map23;

    std::string src24("a", 1);
    Query var24(src24);

    double num25(2);
    Query var25(num25);

    map23.insert({src24, var25});

    std::string src26("id", 2);
    Query var26(src26);

    double num27(2);
    Query var27(num27);

    map23.insert({src26, var27});

    Query var23(map23);

    map19.insert({src22, var23});

    Query var19(map19);

    arr0.insert(arr0.end(), var19);

    Types::object map28;

    std::string src29("group", 5);
    Query var29(src29);

    double num30(3);
    Query var30(num30);

    map28.insert({src29, var30});

    std::string src31("reduction", 9);
    Query var31(src31);

    Types::object map32;

    std::string src33("a", 1);
    Query var33(src33);

    double num34(3);
    Query var34(num34);

    map32.insert({src33, var34});

    std::string src35("id", 2);
    Query var35(src35);

    double num36(3);
    Query var36(num36);

    map32.insert({src35, var36});

    Query var32(map32);

    map28.insert({src31, var32});

    Query var28(map28);

    arr0.insert(arr0.end(), var28);

    Query var0(arr0);
  }

  SECTION("test16") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(3);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test17") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test18") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    Types::object map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Query var8(src8);

    double num9(96);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map10;

    std::string src11("group", 5);
    Query var11(src11);

    double num12(1);
    Query var12(num12);

    map10.insert({src11, var12});

    std::string src13("reduction", 9);
    Query var13(src13);

    Types::object map14;

    std::string src15("a", 1);
    Query var15(src15);

    double num16(1);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("id", 2);
    Query var17(src17);

    double num18(97);
    Query var18(num18);

    map14.insert({src17, var18});

    Query var14(map14);

    map10.insert({src13, var14});

    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Types::object map19;

    std::string src20("group", 5);
    Query var20(src20);

    double num21(2);
    Query var21(num21);

    map19.insert({src20, var21});

    std::string src22("reduction", 9);
    Query var22(src22);

    Types::object map23;

    std::string src24("a", 1);
    Query var24(src24);

    double num25(2);
    Query var25(num25);

    map23.insert({src24, var25});

    std::string src26("id", 2);
    Query var26(src26);

    double num27(98);
    Query var27(num27);

    map23.insert({src26, var27});

    Query var23(map23);

    map19.insert({src22, var23});

    Query var19(map19);

    arr0.insert(arr0.end(), var19);

    Types::object map28;

    std::string src29("group", 5);
    Query var29(src29);

    double num30(3);
    Query var30(num30);

    map28.insert({src29, var30});

    std::string src31("reduction", 9);
    Query var31(src31);

    Types::object map32;

    std::string src33("a", 1);
    Query var33(src33);

    double num34(3);
    Query var34(num34);

    map32.insert({src33, var34});

    std::string src35("id", 2);
    Query var35(src35);

    double num36(99);
    Query var36(num36);

    map32.insert({src35, var36});

    Query var32(map32);

    map28.insert({src31, var32});

    Query var28(map28);

    arr0.insert(arr0.end(), var28);

    Query var0(arr0);
  }

  SECTION("test19") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test20") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    Types::object map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Query var8(src8);

    double num9(0);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map10;

    std::string src11("group", 5);
    Query var11(src11);

    double num12(1);
    Query var12(num12);

    map10.insert({src11, var12});

    std::string src13("reduction", 9);
    Query var13(src13);

    Types::object map14;

    std::string src15("a", 1);
    Query var15(src15);

    double num16(1);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("id", 2);
    Query var17(src17);

    double num18(1);
    Query var18(num18);

    map14.insert({src17, var18});

    Query var14(map14);

    map10.insert({src13, var14});

    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Types::object map19;

    std::string src20("group", 5);
    Query var20(src20);

    double num21(2);
    Query var21(num21);

    map19.insert({src20, var21});

    std::string src22("reduction", 9);
    Query var22(src22);

    Types::object map23;

    std::string src24("a", 1);
    Query var24(src24);

    double num25(2);
    Query var25(num25);

    map23.insert({src24, var25});

    std::string src26("id", 2);
    Query var26(src26);

    double num27(2);
    Query var27(num27);

    map23.insert({src26, var27});

    Query var23(map23);

    map19.insert({src22, var23});

    Query var19(map19);

    arr0.insert(arr0.end(), var19);

    Types::object map28;

    std::string src29("group", 5);
    Query var29(src29);

    double num30(3);
    Query var30(num30);

    map28.insert({src29, var30});

    std::string src31("reduction", 9);
    Query var31(src31);

    Types::object map32;

    std::string src33("a", 1);
    Query var33(src33);

    double num34(3);
    Query var34(num34);

    map32.insert({src33, var34});

    std::string src35("id", 2);
    Query var35(src35);

    double num36(3);
    Query var36(num36);

    map32.insert({src35, var36});

    Query var32(map32);

    map28.insert({src31, var32});

    Query var28(map28);

    arr0.insert(arr0.end(), var28);

    Query var0(arr0);
  }

  SECTION("test21") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(99);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test22") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    Types::object map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Query var8(src8);

    double num9(96);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map10;

    std::string src11("group", 5);
    Query var11(src11);

    double num12(1);
    Query var12(num12);

    map10.insert({src11, var12});

    std::string src13("reduction", 9);
    Query var13(src13);

    Types::object map14;

    std::string src15("a", 1);
    Query var15(src15);

    double num16(1);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("id", 2);
    Query var17(src17);

    double num18(97);
    Query var18(num18);

    map14.insert({src17, var18});

    Query var14(map14);

    map10.insert({src13, var14});

    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Types::object map19;

    std::string src20("group", 5);
    Query var20(src20);

    double num21(2);
    Query var21(num21);

    map19.insert({src20, var21});

    std::string src22("reduction", 9);
    Query var22(src22);

    Types::object map23;

    std::string src24("a", 1);
    Query var24(src24);

    double num25(2);
    Query var25(num25);

    map23.insert({src24, var25});

    std::string src26("id", 2);
    Query var26(src26);

    double num27(98);
    Query var27(num27);

    map23.insert({src26, var27});

    Query var23(map23);

    map19.insert({src22, var23});

    Query var19(map19);

    arr0.insert(arr0.end(), var19);

    Types::object map28;

    std::string src29("group", 5);
    Query var29(src29);

    double num30(3);
    Query var30(num30);

    map28.insert({src29, var30});

    std::string src31("reduction", 9);
    Query var31(src31);

    Types::object map32;

    std::string src33("a", 1);
    Query var33(src33);

    double num34(3);
    Query var34(num34);

    map32.insert({src33, var34});

    std::string src35("id", 2);
    Query var35(src35);

    double num36(99);
    Query var36(num36);

    map32.insert({src35, var36});

    Query var32(map32);

    map28.insert({src31, var32});

    Query var28(map28);

    arr0.insert(arr0.end(), var28);

    Query var0(arr0);
  }

  SECTION("test23") {
    double num0(150);
    Query var0(num0);
  }

  SECTION("test24") {
    double num0(150);
    Query var0(num0);
  }

  SECTION("test25") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(1200);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(1225);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(1250);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(1275);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test26") {
    double num0(1.5);
    Query var0(num0);
  }

  SECTION("test27") {
    double num0(1.5);
    Query var0(num0);
  }

  SECTION("test28") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(48);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(49);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(50);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(51);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test29") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(96);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test30") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test31") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test32") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(0);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(2);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(3);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test33") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test34") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test35") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(96);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(97);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(98);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(99);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test36") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(1200);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(1225);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(1250);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(1275);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test37") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(1200);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(1225);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(1250);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(1275);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test38") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(1);

    Types::array arr5(2);

    double num6(1);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    Types::array arr7(1);

    Types::object map8;

    std::string src9("a", 1);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map8.insert({src9, var10});

    Query var8(map8);

    arr7.insert(arr7.end(), var8);

    Query var7(arr7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test39") {
    std::string src0("GROUPED_STREAM", 14);
    Query var0(src0);
  }

  SECTION("test40") {
    std::string src0("GROUPED_DATA", 12);
    Query var0(src0);
  }

  SECTION("test41") {
    std::string src0("GROUPED_DATA", 12);
    Query var0(src0);
  }

  SECTION("test42") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    Types::array arr5(3);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(4);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    double num8(8);
    Query var8(num8);

    arr5.insert(arr5.end(), var8);

    Query var5(arr5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map9;

    std::string src10("group", 5);
    Query var10(src10);

    double num11(1);
    Query var11(num11);

    map9.insert({src10, var11});

    std::string src12("reduction", 9);
    Query var12(src12);

    Types::array arr13(3);

    double num14(1);
    Query var14(num14);

    arr13.insert(arr13.end(), var14);

    double num15(5);
    Query var15(num15);

    arr13.insert(arr13.end(), var15);

    double num16(9);
    Query var16(num16);

    arr13.insert(arr13.end(), var16);

    Query var13(arr13);

    map9.insert({src12, var13});

    Query var9(map9);

    arr0.insert(arr0.end(), var9);

    Types::object map17;

    std::string src18("group", 5);
    Query var18(src18);

    double num19(2);
    Query var19(num19);

    map17.insert({src18, var19});

    std::string src20("reduction", 9);
    Query var20(src20);

    Types::array arr21(2);

    double num22(2);
    Query var22(num22);

    arr21.insert(arr21.end(), var22);

    double num23(6);
    Query var23(num23);

    arr21.insert(arr21.end(), var23);

    Query var21(arr21);

    map17.insert({src20, var21});

    Query var17(map17);

    arr0.insert(arr0.end(), var17);

    Types::object map24;

    std::string src25("group", 5);
    Query var25(src25);

    double num26(3);
    Query var26(num26);

    map24.insert({src25, var26});

    std::string src27("reduction", 9);
    Query var27(src27);

    Types::array arr28(2);

    double num29(3);
    Query var29(num29);

    arr28.insert(arr28.end(), var29);

    double num30(7);
    Query var30(num30);

    arr28.insert(arr28.end(), var30);

    Query var28(arr28);

    map24.insert({src27, var28});

    Query var24(map24);

    arr0.insert(arr0.end(), var24);

    Query var0(arr0);
  }

  SECTION("test43") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(9);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(9);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(4);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(4);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test44") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(2400);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(2450);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(2500);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(2550);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test45") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(2400);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(2450);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(2500);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(2550);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test46") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(2400);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(2450);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(2500);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(2550);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test47") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(1200);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(1225);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(1250);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(1275);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test49") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(25);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(25);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(25);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(25);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test50") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(1200);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(1225);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(1250);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(1275);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test51") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(48);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(49);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(50);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(51);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test52") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(5);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(20);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(20);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(20);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(20);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Types::array arr17(2);

    double num18(4);
    Query var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(20);
    Query var19(num19);

    arr17.insert(arr17.end(), var19);

    Query var17(arr17);

    arr4.insert(arr4.end(), var17);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test53") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(12);

    Types::array arr5(2);

    Types::array arr6(2);

    double num7(0);
    Query var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Query var8(num8);

    arr6.insert(arr6.end(), var8);

    Query var6(arr6);

    arr5.insert(arr5.end(), var6);

    double num9(9);
    Query var9(num9);

    arr5.insert(arr5.end(), var9);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr10(2);

    Types::array arr11(2);

    double num12(0);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(1);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr10.insert(arr10.end(), var11);

    double num14(8);
    Query var14(num14);

    arr10.insert(arr10.end(), var14);

    Query var10(arr10);

    arr4.insert(arr4.end(), var10);

    Types::array arr15(2);

    Types::array arr16(2);

    double num17(0);
    Query var17(num17);

    arr16.insert(arr16.end(), var17);

    double num18(2);
    Query var18(num18);

    arr16.insert(arr16.end(), var18);

    Query var16(arr16);

    arr15.insert(arr15.end(), var16);

    double num19(8);
    Query var19(num19);

    arr15.insert(arr15.end(), var19);

    Query var15(arr15);

    arr4.insert(arr4.end(), var15);

    Types::array arr20(2);

    Types::array arr21(2);

    double num22(1);
    Query var22(num22);

    arr21.insert(arr21.end(), var22);

    double num23(0);
    Query var23(num23);

    arr21.insert(arr21.end(), var23);

    Query var21(arr21);

    arr20.insert(arr20.end(), var21);

    double num24(8);
    Query var24(num24);

    arr20.insert(arr20.end(), var24);

    Query var20(arr20);

    arr4.insert(arr4.end(), var20);

    Types::array arr25(2);

    Types::array arr26(2);

    double num27(1);
    Query var27(num27);

    arr26.insert(arr26.end(), var27);

    double num28(1);
    Query var28(num28);

    arr26.insert(arr26.end(), var28);

    Query var26(arr26);

    arr25.insert(arr25.end(), var26);

    double num29(9);
    Query var29(num29);

    arr25.insert(arr25.end(), var29);

    Query var25(arr25);

    arr4.insert(arr4.end(), var25);

    Types::array arr30(2);

    Types::array arr31(2);

    double num32(1);
    Query var32(num32);

    arr31.insert(arr31.end(), var32);

    double num33(2);
    Query var33(num33);

    arr31.insert(arr31.end(), var33);

    Query var31(arr31);

    arr30.insert(arr30.end(), var31);

    double num34(8);
    Query var34(num34);

    arr30.insert(arr30.end(), var34);

    Query var30(arr30);

    arr4.insert(arr4.end(), var30);

    Types::array arr35(2);

    Types::array arr36(2);

    double num37(2);
    Query var37(num37);

    arr36.insert(arr36.end(), var37);

    double num38(0);
    Query var38(num38);

    arr36.insert(arr36.end(), var38);

    Query var36(arr36);

    arr35.insert(arr35.end(), var36);

    double num39(8);
    Query var39(num39);

    arr35.insert(arr35.end(), var39);

    Query var35(arr35);

    arr4.insert(arr4.end(), var35);

    Types::array arr40(2);

    Types::array arr41(2);

    double num42(2);
    Query var42(num42);

    arr41.insert(arr41.end(), var42);

    double num43(1);
    Query var43(num43);

    arr41.insert(arr41.end(), var43);

    Query var41(arr41);

    arr40.insert(arr40.end(), var41);

    double num44(8);
    Query var44(num44);

    arr40.insert(arr40.end(), var44);

    Query var40(arr40);

    arr4.insert(arr4.end(), var40);

    Types::array arr45(2);

    Types::array arr46(2);

    double num47(2);
    Query var47(num47);

    arr46.insert(arr46.end(), var47);

    double num48(2);
    Query var48(num48);

    arr46.insert(arr46.end(), var48);

    Query var46(arr46);

    arr45.insert(arr45.end(), var46);

    double num49(9);
    Query var49(num49);

    arr45.insert(arr45.end(), var49);

    Query var45(arr45);

    arr4.insert(arr4.end(), var45);

    Types::array arr50(2);

    Types::array arr51(2);

    double num52(3);
    Query var52(num52);

    arr51.insert(arr51.end(), var52);

    double num53(0);
    Query var53(num53);

    arr51.insert(arr51.end(), var53);

    Query var51(arr51);

    arr50.insert(arr50.end(), var51);

    double num54(9);
    Query var54(num54);

    arr50.insert(arr50.end(), var54);

    Query var50(arr50);

    arr4.insert(arr4.end(), var50);

    Types::array arr55(2);

    Types::array arr56(2);

    double num57(3);
    Query var57(num57);

    arr56.insert(arr56.end(), var57);

    double num58(1);
    Query var58(num58);

    arr56.insert(arr56.end(), var58);

    Query var56(arr56);

    arr55.insert(arr55.end(), var56);

    double num59(8);
    Query var59(num59);

    arr55.insert(arr55.end(), var59);

    Query var55(arr55);

    arr4.insert(arr4.end(), var55);

    Types::array arr60(2);

    Types::array arr61(2);

    double num62(3);
    Query var62(num62);

    arr61.insert(arr61.end(), var62);

    double num63(2);
    Query var63(num63);

    arr61.insert(arr61.end(), var63);

    Query var61(arr61);

    arr60.insert(arr60.end(), var61);

    double num64(8);
    Query var64(num64);

    arr60.insert(arr60.end(), var64);

    Query var60(arr60);

    arr4.insert(arr4.end(), var60);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test55") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("error", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test57") {
    double num0(4);
    Query var0(num0);
  }

  SECTION("test58") {
    std::string src0("STREAM", 6);
    Query var0(src0);
  }

  SECTION("test59") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test60") {
    std::string src0("STREAM", 6);
    Query var0(src0);
  }

  SECTION("test61") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test62") {
    Types::object map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test65") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("index", 5);
    Query var2(src2);

    std::string src3("a", 1);
    Query var3(src3);

    map1.insert({src2, var3});

    std::string src4("ready", 5);
    Query var4(src4);

    Query var5(true);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test68") {
    double num0(25);
    Query var0(num0);
  }

  SECTION("test69") {
    double num0(25);
    Query var0(num0);
  }

  SECTION("test81") {
    std::string src0("STREAM", 6);
    Query var0(src0);
  }

  SECTION("test82") {
    double num0(4);
    Query var0(num0);
  }

  SECTION("test83") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test84") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(100);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(1);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(1);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(1);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(1);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Types::array arr17(2);

    double num18(4);
    Query var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(1);
    Query var19(num19);

    arr17.insert(arr17.end(), var19);

    Query var17(arr17);

    arr4.insert(arr4.end(), var17);

    Types::array arr20(2);

    double num21(5);
    Query var21(num21);

    arr20.insert(arr20.end(), var21);

    double num22(1);
    Query var22(num22);

    arr20.insert(arr20.end(), var22);

    Query var20(arr20);

    arr4.insert(arr4.end(), var20);

    Types::array arr23(2);

    double num24(6);
    Query var24(num24);

    arr23.insert(arr23.end(), var24);

    double num25(1);
    Query var25(num25);

    arr23.insert(arr23.end(), var25);

    Query var23(arr23);

    arr4.insert(arr4.end(), var23);

    Types::array arr26(2);

    double num27(7);
    Query var27(num27);

    arr26.insert(arr26.end(), var27);

    double num28(1);
    Query var28(num28);

    arr26.insert(arr26.end(), var28);

    Query var26(arr26);

    arr4.insert(arr4.end(), var26);

    Types::array arr29(2);

    double num30(8);
    Query var30(num30);

    arr29.insert(arr29.end(), var30);

    double num31(1);
    Query var31(num31);

    arr29.insert(arr29.end(), var31);

    Query var29(arr29);

    arr4.insert(arr4.end(), var29);

    Types::array arr32(2);

    double num33(9);
    Query var33(num33);

    arr32.insert(arr32.end(), var33);

    double num34(1);
    Query var34(num34);

    arr32.insert(arr32.end(), var34);

    Query var32(arr32);

    arr4.insert(arr4.end(), var32);

    Types::array arr35(2);

    double num36(10);
    Query var36(num36);

    arr35.insert(arr35.end(), var36);

    double num37(1);
    Query var37(num37);

    arr35.insert(arr35.end(), var37);

    Query var35(arr35);

    arr4.insert(arr4.end(), var35);

    Types::array arr38(2);

    double num39(11);
    Query var39(num39);

    arr38.insert(arr38.end(), var39);

    double num40(1);
    Query var40(num40);

    arr38.insert(arr38.end(), var40);

    Query var38(arr38);

    arr4.insert(arr4.end(), var38);

    Types::array arr41(2);

    double num42(12);
    Query var42(num42);

    arr41.insert(arr41.end(), var42);

    double num43(1);
    Query var43(num43);

    arr41.insert(arr41.end(), var43);

    Query var41(arr41);

    arr4.insert(arr4.end(), var41);

    Types::array arr44(2);

    double num45(13);
    Query var45(num45);

    arr44.insert(arr44.end(), var45);

    double num46(1);
    Query var46(num46);

    arr44.insert(arr44.end(), var46);

    Query var44(arr44);

    arr4.insert(arr4.end(), var44);

    Types::array arr47(2);

    double num48(14);
    Query var48(num48);

    arr47.insert(arr47.end(), var48);

    double num49(1);
    Query var49(num49);

    arr47.insert(arr47.end(), var49);

    Query var47(arr47);

    arr4.insert(arr4.end(), var47);

    Types::array arr50(2);

    double num51(15);
    Query var51(num51);

    arr50.insert(arr50.end(), var51);

    double num52(1);
    Query var52(num52);

    arr50.insert(arr50.end(), var52);

    Query var50(arr50);

    arr4.insert(arr4.end(), var50);

    Types::array arr53(2);

    double num54(16);
    Query var54(num54);

    arr53.insert(arr53.end(), var54);

    double num55(1);
    Query var55(num55);

    arr53.insert(arr53.end(), var55);

    Query var53(arr53);

    arr4.insert(arr4.end(), var53);

    Types::array arr56(2);

    double num57(17);
    Query var57(num57);

    arr56.insert(arr56.end(), var57);

    double num58(1);
    Query var58(num58);

    arr56.insert(arr56.end(), var58);

    Query var56(arr56);

    arr4.insert(arr4.end(), var56);

    Types::array arr59(2);

    double num60(18);
    Query var60(num60);

    arr59.insert(arr59.end(), var60);

    double num61(1);
    Query var61(num61);

    arr59.insert(arr59.end(), var61);

    Query var59(arr59);

    arr4.insert(arr4.end(), var59);

    Types::array arr62(2);

    double num63(19);
    Query var63(num63);

    arr62.insert(arr62.end(), var63);

    double num64(1);
    Query var64(num64);

    arr62.insert(arr62.end(), var64);

    Query var62(arr62);

    arr4.insert(arr4.end(), var62);

    Types::array arr65(2);

    double num66(20);
    Query var66(num66);

    arr65.insert(arr65.end(), var66);

    double num67(1);
    Query var67(num67);

    arr65.insert(arr65.end(), var67);

    Query var65(arr65);

    arr4.insert(arr4.end(), var65);

    Types::array arr68(2);

    double num69(21);
    Query var69(num69);

    arr68.insert(arr68.end(), var69);

    double num70(1);
    Query var70(num70);

    arr68.insert(arr68.end(), var70);

    Query var68(arr68);

    arr4.insert(arr4.end(), var68);

    Types::array arr71(2);

    double num72(22);
    Query var72(num72);

    arr71.insert(arr71.end(), var72);

    double num73(1);
    Query var73(num73);

    arr71.insert(arr71.end(), var73);

    Query var71(arr71);

    arr4.insert(arr4.end(), var71);

    Types::array arr74(2);

    double num75(23);
    Query var75(num75);

    arr74.insert(arr74.end(), var75);

    double num76(1);
    Query var76(num76);

    arr74.insert(arr74.end(), var76);

    Query var74(arr74);

    arr4.insert(arr4.end(), var74);

    Types::array arr77(2);

    double num78(24);
    Query var78(num78);

    arr77.insert(arr77.end(), var78);

    double num79(1);
    Query var79(num79);

    arr77.insert(arr77.end(), var79);

    Query var77(arr77);

    arr4.insert(arr4.end(), var77);

    Types::array arr80(2);

    double num81(25);
    Query var81(num81);

    arr80.insert(arr80.end(), var81);

    double num82(1);
    Query var82(num82);

    arr80.insert(arr80.end(), var82);

    Query var80(arr80);

    arr4.insert(arr4.end(), var80);

    Types::array arr83(2);

    double num84(26);
    Query var84(num84);

    arr83.insert(arr83.end(), var84);

    double num85(1);
    Query var85(num85);

    arr83.insert(arr83.end(), var85);

    Query var83(arr83);

    arr4.insert(arr4.end(), var83);

    Types::array arr86(2);

    double num87(27);
    Query var87(num87);

    arr86.insert(arr86.end(), var87);

    double num88(1);
    Query var88(num88);

    arr86.insert(arr86.end(), var88);

    Query var86(arr86);

    arr4.insert(arr4.end(), var86);

    Types::array arr89(2);

    double num90(28);
    Query var90(num90);

    arr89.insert(arr89.end(), var90);

    double num91(1);
    Query var91(num91);

    arr89.insert(arr89.end(), var91);

    Query var89(arr89);

    arr4.insert(arr4.end(), var89);

    Types::array arr92(2);

    double num93(29);
    Query var93(num93);

    arr92.insert(arr92.end(), var93);

    double num94(1);
    Query var94(num94);

    arr92.insert(arr92.end(), var94);

    Query var92(arr92);

    arr4.insert(arr4.end(), var92);

    Types::array arr95(2);

    double num96(30);
    Query var96(num96);

    arr95.insert(arr95.end(), var96);

    double num97(1);
    Query var97(num97);

    arr95.insert(arr95.end(), var97);

    Query var95(arr95);

    arr4.insert(arr4.end(), var95);

    Types::array arr98(2);

    double num99(31);
    Query var99(num99);

    arr98.insert(arr98.end(), var99);

    double num100(1);
    Query var100(num100);

    arr98.insert(arr98.end(), var100);

    Query var98(arr98);

    arr4.insert(arr4.end(), var98);

    Types::array arr101(2);

    double num102(32);
    Query var102(num102);

    arr101.insert(arr101.end(), var102);

    double num103(1);
    Query var103(num103);

    arr101.insert(arr101.end(), var103);

    Query var101(arr101);

    arr4.insert(arr4.end(), var101);

    Types::array arr104(2);

    double num105(33);
    Query var105(num105);

    arr104.insert(arr104.end(), var105);

    double num106(1);
    Query var106(num106);

    arr104.insert(arr104.end(), var106);

    Query var104(arr104);

    arr4.insert(arr4.end(), var104);

    Types::array arr107(2);

    double num108(34);
    Query var108(num108);

    arr107.insert(arr107.end(), var108);

    double num109(1);
    Query var109(num109);

    arr107.insert(arr107.end(), var109);

    Query var107(arr107);

    arr4.insert(arr4.end(), var107);

    Types::array arr110(2);

    double num111(35);
    Query var111(num111);

    arr110.insert(arr110.end(), var111);

    double num112(1);
    Query var112(num112);

    arr110.insert(arr110.end(), var112);

    Query var110(arr110);

    arr4.insert(arr4.end(), var110);

    Types::array arr113(2);

    double num114(36);
    Query var114(num114);

    arr113.insert(arr113.end(), var114);

    double num115(1);
    Query var115(num115);

    arr113.insert(arr113.end(), var115);

    Query var113(arr113);

    arr4.insert(arr4.end(), var113);

    Types::array arr116(2);

    double num117(37);
    Query var117(num117);

    arr116.insert(arr116.end(), var117);

    double num118(1);
    Query var118(num118);

    arr116.insert(arr116.end(), var118);

    Query var116(arr116);

    arr4.insert(arr4.end(), var116);

    Types::array arr119(2);

    double num120(38);
    Query var120(num120);

    arr119.insert(arr119.end(), var120);

    double num121(1);
    Query var121(num121);

    arr119.insert(arr119.end(), var121);

    Query var119(arr119);

    arr4.insert(arr4.end(), var119);

    Types::array arr122(2);

    double num123(39);
    Query var123(num123);

    arr122.insert(arr122.end(), var123);

    double num124(1);
    Query var124(num124);

    arr122.insert(arr122.end(), var124);

    Query var122(arr122);

    arr4.insert(arr4.end(), var122);

    Types::array arr125(2);

    double num126(40);
    Query var126(num126);

    arr125.insert(arr125.end(), var126);

    double num127(1);
    Query var127(num127);

    arr125.insert(arr125.end(), var127);

    Query var125(arr125);

    arr4.insert(arr4.end(), var125);

    Types::array arr128(2);

    double num129(41);
    Query var129(num129);

    arr128.insert(arr128.end(), var129);

    double num130(1);
    Query var130(num130);

    arr128.insert(arr128.end(), var130);

    Query var128(arr128);

    arr4.insert(arr4.end(), var128);

    Types::array arr131(2);

    double num132(42);
    Query var132(num132);

    arr131.insert(arr131.end(), var132);

    double num133(1);
    Query var133(num133);

    arr131.insert(arr131.end(), var133);

    Query var131(arr131);

    arr4.insert(arr4.end(), var131);

    Types::array arr134(2);

    double num135(43);
    Query var135(num135);

    arr134.insert(arr134.end(), var135);

    double num136(1);
    Query var136(num136);

    arr134.insert(arr134.end(), var136);

    Query var134(arr134);

    arr4.insert(arr4.end(), var134);

    Types::array arr137(2);

    double num138(44);
    Query var138(num138);

    arr137.insert(arr137.end(), var138);

    double num139(1);
    Query var139(num139);

    arr137.insert(arr137.end(), var139);

    Query var137(arr137);

    arr4.insert(arr4.end(), var137);

    Types::array arr140(2);

    double num141(45);
    Query var141(num141);

    arr140.insert(arr140.end(), var141);

    double num142(1);
    Query var142(num142);

    arr140.insert(arr140.end(), var142);

    Query var140(arr140);

    arr4.insert(arr4.end(), var140);

    Types::array arr143(2);

    double num144(46);
    Query var144(num144);

    arr143.insert(arr143.end(), var144);

    double num145(1);
    Query var145(num145);

    arr143.insert(arr143.end(), var145);

    Query var143(arr143);

    arr4.insert(arr4.end(), var143);

    Types::array arr146(2);

    double num147(47);
    Query var147(num147);

    arr146.insert(arr146.end(), var147);

    double num148(1);
    Query var148(num148);

    arr146.insert(arr146.end(), var148);

    Query var146(arr146);

    arr4.insert(arr4.end(), var146);

    Types::array arr149(2);

    double num150(48);
    Query var150(num150);

    arr149.insert(arr149.end(), var150);

    double num151(1);
    Query var151(num151);

    arr149.insert(arr149.end(), var151);

    Query var149(arr149);

    arr4.insert(arr4.end(), var149);

    Types::array arr152(2);

    double num153(49);
    Query var153(num153);

    arr152.insert(arr152.end(), var153);

    double num154(1);
    Query var154(num154);

    arr152.insert(arr152.end(), var154);

    Query var152(arr152);

    arr4.insert(arr4.end(), var152);

    Types::array arr155(2);

    double num156(50);
    Query var156(num156);

    arr155.insert(arr155.end(), var156);

    double num157(1);
    Query var157(num157);

    arr155.insert(arr155.end(), var157);

    Query var155(arr155);

    arr4.insert(arr4.end(), var155);

    Types::array arr158(2);

    double num159(51);
    Query var159(num159);

    arr158.insert(arr158.end(), var159);

    double num160(1);
    Query var160(num160);

    arr158.insert(arr158.end(), var160);

    Query var158(arr158);

    arr4.insert(arr4.end(), var158);

    Types::array arr161(2);

    double num162(52);
    Query var162(num162);

    arr161.insert(arr161.end(), var162);

    double num163(1);
    Query var163(num163);

    arr161.insert(arr161.end(), var163);

    Query var161(arr161);

    arr4.insert(arr4.end(), var161);

    Types::array arr164(2);

    double num165(53);
    Query var165(num165);

    arr164.insert(arr164.end(), var165);

    double num166(1);
    Query var166(num166);

    arr164.insert(arr164.end(), var166);

    Query var164(arr164);

    arr4.insert(arr4.end(), var164);

    Types::array arr167(2);

    double num168(54);
    Query var168(num168);

    arr167.insert(arr167.end(), var168);

    double num169(1);
    Query var169(num169);

    arr167.insert(arr167.end(), var169);

    Query var167(arr167);

    arr4.insert(arr4.end(), var167);

    Types::array arr170(2);

    double num171(55);
    Query var171(num171);

    arr170.insert(arr170.end(), var171);

    double num172(1);
    Query var172(num172);

    arr170.insert(arr170.end(), var172);

    Query var170(arr170);

    arr4.insert(arr4.end(), var170);

    Types::array arr173(2);

    double num174(56);
    Query var174(num174);

    arr173.insert(arr173.end(), var174);

    double num175(1);
    Query var175(num175);

    arr173.insert(arr173.end(), var175);

    Query var173(arr173);

    arr4.insert(arr4.end(), var173);

    Types::array arr176(2);

    double num177(57);
    Query var177(num177);

    arr176.insert(arr176.end(), var177);

    double num178(1);
    Query var178(num178);

    arr176.insert(arr176.end(), var178);

    Query var176(arr176);

    arr4.insert(arr4.end(), var176);

    Types::array arr179(2);

    double num180(58);
    Query var180(num180);

    arr179.insert(arr179.end(), var180);

    double num181(1);
    Query var181(num181);

    arr179.insert(arr179.end(), var181);

    Query var179(arr179);

    arr4.insert(arr4.end(), var179);

    Types::array arr182(2);

    double num183(59);
    Query var183(num183);

    arr182.insert(arr182.end(), var183);

    double num184(1);
    Query var184(num184);

    arr182.insert(arr182.end(), var184);

    Query var182(arr182);

    arr4.insert(arr4.end(), var182);

    Types::array arr185(2);

    double num186(60);
    Query var186(num186);

    arr185.insert(arr185.end(), var186);

    double num187(1);
    Query var187(num187);

    arr185.insert(arr185.end(), var187);

    Query var185(arr185);

    arr4.insert(arr4.end(), var185);

    Types::array arr188(2);

    double num189(61);
    Query var189(num189);

    arr188.insert(arr188.end(), var189);

    double num190(1);
    Query var190(num190);

    arr188.insert(arr188.end(), var190);

    Query var188(arr188);

    arr4.insert(arr4.end(), var188);

    Types::array arr191(2);

    double num192(62);
    Query var192(num192);

    arr191.insert(arr191.end(), var192);

    double num193(1);
    Query var193(num193);

    arr191.insert(arr191.end(), var193);

    Query var191(arr191);

    arr4.insert(arr4.end(), var191);

    Types::array arr194(2);

    double num195(63);
    Query var195(num195);

    arr194.insert(arr194.end(), var195);

    double num196(1);
    Query var196(num196);

    arr194.insert(arr194.end(), var196);

    Query var194(arr194);

    arr4.insert(arr4.end(), var194);

    Types::array arr197(2);

    double num198(64);
    Query var198(num198);

    arr197.insert(arr197.end(), var198);

    double num199(1);
    Query var199(num199);

    arr197.insert(arr197.end(), var199);

    Query var197(arr197);

    arr4.insert(arr4.end(), var197);

    Types::array arr200(2);

    double num201(65);
    Query var201(num201);

    arr200.insert(arr200.end(), var201);

    double num202(1);
    Query var202(num202);

    arr200.insert(arr200.end(), var202);

    Query var200(arr200);

    arr4.insert(arr4.end(), var200);

    Types::array arr203(2);

    double num204(66);
    Query var204(num204);

    arr203.insert(arr203.end(), var204);

    double num205(1);
    Query var205(num205);

    arr203.insert(arr203.end(), var205);

    Query var203(arr203);

    arr4.insert(arr4.end(), var203);

    Types::array arr206(2);

    double num207(67);
    Query var207(num207);

    arr206.insert(arr206.end(), var207);

    double num208(1);
    Query var208(num208);

    arr206.insert(arr206.end(), var208);

    Query var206(arr206);

    arr4.insert(arr4.end(), var206);

    Types::array arr209(2);

    double num210(68);
    Query var210(num210);

    arr209.insert(arr209.end(), var210);

    double num211(1);
    Query var211(num211);

    arr209.insert(arr209.end(), var211);

    Query var209(arr209);

    arr4.insert(arr4.end(), var209);

    Types::array arr212(2);

    double num213(69);
    Query var213(num213);

    arr212.insert(arr212.end(), var213);

    double num214(1);
    Query var214(num214);

    arr212.insert(arr212.end(), var214);

    Query var212(arr212);

    arr4.insert(arr4.end(), var212);

    Types::array arr215(2);

    double num216(70);
    Query var216(num216);

    arr215.insert(arr215.end(), var216);

    double num217(1);
    Query var217(num217);

    arr215.insert(arr215.end(), var217);

    Query var215(arr215);

    arr4.insert(arr4.end(), var215);

    Types::array arr218(2);

    double num219(71);
    Query var219(num219);

    arr218.insert(arr218.end(), var219);

    double num220(1);
    Query var220(num220);

    arr218.insert(arr218.end(), var220);

    Query var218(arr218);

    arr4.insert(arr4.end(), var218);

    Types::array arr221(2);

    double num222(72);
    Query var222(num222);

    arr221.insert(arr221.end(), var222);

    double num223(1);
    Query var223(num223);

    arr221.insert(arr221.end(), var223);

    Query var221(arr221);

    arr4.insert(arr4.end(), var221);

    Types::array arr224(2);

    double num225(73);
    Query var225(num225);

    arr224.insert(arr224.end(), var225);

    double num226(1);
    Query var226(num226);

    arr224.insert(arr224.end(), var226);

    Query var224(arr224);

    arr4.insert(arr4.end(), var224);

    Types::array arr227(2);

    double num228(74);
    Query var228(num228);

    arr227.insert(arr227.end(), var228);

    double num229(1);
    Query var229(num229);

    arr227.insert(arr227.end(), var229);

    Query var227(arr227);

    arr4.insert(arr4.end(), var227);

    Types::array arr230(2);

    double num231(75);
    Query var231(num231);

    arr230.insert(arr230.end(), var231);

    double num232(1);
    Query var232(num232);

    arr230.insert(arr230.end(), var232);

    Query var230(arr230);

    arr4.insert(arr4.end(), var230);

    Types::array arr233(2);

    double num234(76);
    Query var234(num234);

    arr233.insert(arr233.end(), var234);

    double num235(1);
    Query var235(num235);

    arr233.insert(arr233.end(), var235);

    Query var233(arr233);

    arr4.insert(arr4.end(), var233);

    Types::array arr236(2);

    double num237(77);
    Query var237(num237);

    arr236.insert(arr236.end(), var237);

    double num238(1);
    Query var238(num238);

    arr236.insert(arr236.end(), var238);

    Query var236(arr236);

    arr4.insert(arr4.end(), var236);

    Types::array arr239(2);

    double num240(78);
    Query var240(num240);

    arr239.insert(arr239.end(), var240);

    double num241(1);
    Query var241(num241);

    arr239.insert(arr239.end(), var241);

    Query var239(arr239);

    arr4.insert(arr4.end(), var239);

    Types::array arr242(2);

    double num243(79);
    Query var243(num243);

    arr242.insert(arr242.end(), var243);

    double num244(1);
    Query var244(num244);

    arr242.insert(arr242.end(), var244);

    Query var242(arr242);

    arr4.insert(arr4.end(), var242);

    Types::array arr245(2);

    double num246(80);
    Query var246(num246);

    arr245.insert(arr245.end(), var246);

    double num247(1);
    Query var247(num247);

    arr245.insert(arr245.end(), var247);

    Query var245(arr245);

    arr4.insert(arr4.end(), var245);

    Types::array arr248(2);

    double num249(81);
    Query var249(num249);

    arr248.insert(arr248.end(), var249);

    double num250(1);
    Query var250(num250);

    arr248.insert(arr248.end(), var250);

    Query var248(arr248);

    arr4.insert(arr4.end(), var248);

    Types::array arr251(2);

    double num252(82);
    Query var252(num252);

    arr251.insert(arr251.end(), var252);

    double num253(1);
    Query var253(num253);

    arr251.insert(arr251.end(), var253);

    Query var251(arr251);

    arr4.insert(arr4.end(), var251);

    Types::array arr254(2);

    double num255(83);
    Query var255(num255);

    arr254.insert(arr254.end(), var255);

    double num256(1);
    Query var256(num256);

    arr254.insert(arr254.end(), var256);

    Query var254(arr254);

    arr4.insert(arr4.end(), var254);

    Types::array arr257(2);

    double num258(84);
    Query var258(num258);

    arr257.insert(arr257.end(), var258);

    double num259(1);
    Query var259(num259);

    arr257.insert(arr257.end(), var259);

    Query var257(arr257);

    arr4.insert(arr4.end(), var257);

    Types::array arr260(2);

    double num261(85);
    Query var261(num261);

    arr260.insert(arr260.end(), var261);

    double num262(1);
    Query var262(num262);

    arr260.insert(arr260.end(), var262);

    Query var260(arr260);

    arr4.insert(arr4.end(), var260);

    Types::array arr263(2);

    double num264(86);
    Query var264(num264);

    arr263.insert(arr263.end(), var264);

    double num265(1);
    Query var265(num265);

    arr263.insert(arr263.end(), var265);

    Query var263(arr263);

    arr4.insert(arr4.end(), var263);

    Types::array arr266(2);

    double num267(87);
    Query var267(num267);

    arr266.insert(arr266.end(), var267);

    double num268(1);
    Query var268(num268);

    arr266.insert(arr266.end(), var268);

    Query var266(arr266);

    arr4.insert(arr4.end(), var266);

    Types::array arr269(2);

    double num270(88);
    Query var270(num270);

    arr269.insert(arr269.end(), var270);

    double num271(1);
    Query var271(num271);

    arr269.insert(arr269.end(), var271);

    Query var269(arr269);

    arr4.insert(arr4.end(), var269);

    Types::array arr272(2);

    double num273(89);
    Query var273(num273);

    arr272.insert(arr272.end(), var273);

    double num274(1);
    Query var274(num274);

    arr272.insert(arr272.end(), var274);

    Query var272(arr272);

    arr4.insert(arr4.end(), var272);

    Types::array arr275(2);

    double num276(90);
    Query var276(num276);

    arr275.insert(arr275.end(), var276);

    double num277(1);
    Query var277(num277);

    arr275.insert(arr275.end(), var277);

    Query var275(arr275);

    arr4.insert(arr4.end(), var275);

    Types::array arr278(2);

    double num279(91);
    Query var279(num279);

    arr278.insert(arr278.end(), var279);

    double num280(1);
    Query var280(num280);

    arr278.insert(arr278.end(), var280);

    Query var278(arr278);

    arr4.insert(arr4.end(), var278);

    Types::array arr281(2);

    double num282(92);
    Query var282(num282);

    arr281.insert(arr281.end(), var282);

    double num283(1);
    Query var283(num283);

    arr281.insert(arr281.end(), var283);

    Query var281(arr281);

    arr4.insert(arr4.end(), var281);

    Types::array arr284(2);

    double num285(93);
    Query var285(num285);

    arr284.insert(arr284.end(), var285);

    double num286(1);
    Query var286(num286);

    arr284.insert(arr284.end(), var286);

    Query var284(arr284);

    arr4.insert(arr4.end(), var284);

    Types::array arr287(2);

    double num288(94);
    Query var288(num288);

    arr287.insert(arr287.end(), var288);

    double num289(1);
    Query var289(num289);

    arr287.insert(arr287.end(), var289);

    Query var287(arr287);

    arr4.insert(arr4.end(), var287);

    Types::array arr290(2);

    double num291(95);
    Query var291(num291);

    arr290.insert(arr290.end(), var291);

    double num292(1);
    Query var292(num292);

    arr290.insert(arr290.end(), var292);

    Query var290(arr290);

    arr4.insert(arr4.end(), var290);

    Types::array arr293(2);

    double num294(96);
    Query var294(num294);

    arr293.insert(arr293.end(), var294);

    double num295(1);
    Query var295(num295);

    arr293.insert(arr293.end(), var295);

    Query var293(arr293);

    arr4.insert(arr4.end(), var293);

    Types::array arr296(2);

    double num297(97);
    Query var297(num297);

    arr296.insert(arr296.end(), var297);

    double num298(1);
    Query var298(num298);

    arr296.insert(arr296.end(), var298);

    Query var296(arr296);

    arr4.insert(arr4.end(), var296);

    Types::array arr299(2);

    double num300(98);
    Query var300(num300);

    arr299.insert(arr299.end(), var300);

    double num301(1);
    Query var301(num301);

    arr299.insert(arr299.end(), var301);

    Query var299(arr299);

    arr4.insert(arr4.end(), var299);

    Types::array arr302(2);

    double num303(99);
    Query var303(num303);

    arr302.insert(arr302.end(), var303);

    double num304(1);
    Query var304(num304);

    arr302.insert(arr302.end(), var304);

    Query var302(arr302);

    arr4.insert(arr4.end(), var302);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test85") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    double num6(0);
    Query var6(num6);

    arr5.insert(arr5.end(), var6);

    double num7(25);
    Query var7(num7);

    arr5.insert(arr5.end(), var7);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr8(2);

    double num9(1);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(25);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    Query var8(arr8);

    arr4.insert(arr4.end(), var8);

    Types::array arr11(2);

    double num12(2);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(25);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr4.insert(arr4.end(), var11);

    Types::array arr14(2);

    double num15(3);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    double num16(25);
    Query var16(num16);

    arr14.insert(arr14.end(), var16);

    Query var14(arr14);

    arr4.insert(arr4.end(), var14);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test86") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(100);

    Types::array arr5(2);

    Types::array arr6(2);

    double num7(0);
    Query var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Query var8(num8);

    arr6.insert(arr6.end(), var8);

    Query var6(arr6);

    arr5.insert(arr5.end(), var6);

    double num9(1);
    Query var9(num9);

    arr5.insert(arr5.end(), var9);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr10(2);

    Types::array arr11(2);

    double num12(0);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(4);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr10.insert(arr10.end(), var11);

    double num14(1);
    Query var14(num14);

    arr10.insert(arr10.end(), var14);

    Query var10(arr10);

    arr4.insert(arr4.end(), var10);

    Types::array arr15(2);

    Types::array arr16(2);

    double num17(0);
    Query var17(num17);

    arr16.insert(arr16.end(), var17);

    double num18(8);
    Query var18(num18);

    arr16.insert(arr16.end(), var18);

    Query var16(arr16);

    arr15.insert(arr15.end(), var16);

    double num19(1);
    Query var19(num19);

    arr15.insert(arr15.end(), var19);

    Query var15(arr15);

    arr4.insert(arr4.end(), var15);

    Types::array arr20(2);

    Types::array arr21(2);

    double num22(0);
    Query var22(num22);

    arr21.insert(arr21.end(), var22);

    double num23(12);
    Query var23(num23);

    arr21.insert(arr21.end(), var23);

    Query var21(arr21);

    arr20.insert(arr20.end(), var21);

    double num24(1);
    Query var24(num24);

    arr20.insert(arr20.end(), var24);

    Query var20(arr20);

    arr4.insert(arr4.end(), var20);

    Types::array arr25(2);

    Types::array arr26(2);

    double num27(0);
    Query var27(num27);

    arr26.insert(arr26.end(), var27);

    double num28(16);
    Query var28(num28);

    arr26.insert(arr26.end(), var28);

    Query var26(arr26);

    arr25.insert(arr25.end(), var26);

    double num29(1);
    Query var29(num29);

    arr25.insert(arr25.end(), var29);

    Query var25(arr25);

    arr4.insert(arr4.end(), var25);

    Types::array arr30(2);

    Types::array arr31(2);

    double num32(0);
    Query var32(num32);

    arr31.insert(arr31.end(), var32);

    double num33(20);
    Query var33(num33);

    arr31.insert(arr31.end(), var33);

    Query var31(arr31);

    arr30.insert(arr30.end(), var31);

    double num34(1);
    Query var34(num34);

    arr30.insert(arr30.end(), var34);

    Query var30(arr30);

    arr4.insert(arr4.end(), var30);

    Types::array arr35(2);

    Types::array arr36(2);

    double num37(0);
    Query var37(num37);

    arr36.insert(arr36.end(), var37);

    double num38(24);
    Query var38(num38);

    arr36.insert(arr36.end(), var38);

    Query var36(arr36);

    arr35.insert(arr35.end(), var36);

    double num39(1);
    Query var39(num39);

    arr35.insert(arr35.end(), var39);

    Query var35(arr35);

    arr4.insert(arr4.end(), var35);

    Types::array arr40(2);

    Types::array arr41(2);

    double num42(0);
    Query var42(num42);

    arr41.insert(arr41.end(), var42);

    double num43(28);
    Query var43(num43);

    arr41.insert(arr41.end(), var43);

    Query var41(arr41);

    arr40.insert(arr40.end(), var41);

    double num44(1);
    Query var44(num44);

    arr40.insert(arr40.end(), var44);

    Query var40(arr40);

    arr4.insert(arr4.end(), var40);

    Types::array arr45(2);

    Types::array arr46(2);

    double num47(0);
    Query var47(num47);

    arr46.insert(arr46.end(), var47);

    double num48(32);
    Query var48(num48);

    arr46.insert(arr46.end(), var48);

    Query var46(arr46);

    arr45.insert(arr45.end(), var46);

    double num49(1);
    Query var49(num49);

    arr45.insert(arr45.end(), var49);

    Query var45(arr45);

    arr4.insert(arr4.end(), var45);

    Types::array arr50(2);

    Types::array arr51(2);

    double num52(0);
    Query var52(num52);

    arr51.insert(arr51.end(), var52);

    double num53(36);
    Query var53(num53);

    arr51.insert(arr51.end(), var53);

    Query var51(arr51);

    arr50.insert(arr50.end(), var51);

    double num54(1);
    Query var54(num54);

    arr50.insert(arr50.end(), var54);

    Query var50(arr50);

    arr4.insert(arr4.end(), var50);

    Types::array arr55(2);

    Types::array arr56(2);

    double num57(0);
    Query var57(num57);

    arr56.insert(arr56.end(), var57);

    double num58(40);
    Query var58(num58);

    arr56.insert(arr56.end(), var58);

    Query var56(arr56);

    arr55.insert(arr55.end(), var56);

    double num59(1);
    Query var59(num59);

    arr55.insert(arr55.end(), var59);

    Query var55(arr55);

    arr4.insert(arr4.end(), var55);

    Types::array arr60(2);

    Types::array arr61(2);

    double num62(0);
    Query var62(num62);

    arr61.insert(arr61.end(), var62);

    double num63(44);
    Query var63(num63);

    arr61.insert(arr61.end(), var63);

    Query var61(arr61);

    arr60.insert(arr60.end(), var61);

    double num64(1);
    Query var64(num64);

    arr60.insert(arr60.end(), var64);

    Query var60(arr60);

    arr4.insert(arr4.end(), var60);

    Types::array arr65(2);

    Types::array arr66(2);

    double num67(0);
    Query var67(num67);

    arr66.insert(arr66.end(), var67);

    double num68(48);
    Query var68(num68);

    arr66.insert(arr66.end(), var68);

    Query var66(arr66);

    arr65.insert(arr65.end(), var66);

    double num69(1);
    Query var69(num69);

    arr65.insert(arr65.end(), var69);

    Query var65(arr65);

    arr4.insert(arr4.end(), var65);

    Types::array arr70(2);

    Types::array arr71(2);

    double num72(0);
    Query var72(num72);

    arr71.insert(arr71.end(), var72);

    double num73(52);
    Query var73(num73);

    arr71.insert(arr71.end(), var73);

    Query var71(arr71);

    arr70.insert(arr70.end(), var71);

    double num74(1);
    Query var74(num74);

    arr70.insert(arr70.end(), var74);

    Query var70(arr70);

    arr4.insert(arr4.end(), var70);

    Types::array arr75(2);

    Types::array arr76(2);

    double num77(0);
    Query var77(num77);

    arr76.insert(arr76.end(), var77);

    double num78(56);
    Query var78(num78);

    arr76.insert(arr76.end(), var78);

    Query var76(arr76);

    arr75.insert(arr75.end(), var76);

    double num79(1);
    Query var79(num79);

    arr75.insert(arr75.end(), var79);

    Query var75(arr75);

    arr4.insert(arr4.end(), var75);

    Types::array arr80(2);

    Types::array arr81(2);

    double num82(0);
    Query var82(num82);

    arr81.insert(arr81.end(), var82);

    double num83(60);
    Query var83(num83);

    arr81.insert(arr81.end(), var83);

    Query var81(arr81);

    arr80.insert(arr80.end(), var81);

    double num84(1);
    Query var84(num84);

    arr80.insert(arr80.end(), var84);

    Query var80(arr80);

    arr4.insert(arr4.end(), var80);

    Types::array arr85(2);

    Types::array arr86(2);

    double num87(0);
    Query var87(num87);

    arr86.insert(arr86.end(), var87);

    double num88(64);
    Query var88(num88);

    arr86.insert(arr86.end(), var88);

    Query var86(arr86);

    arr85.insert(arr85.end(), var86);

    double num89(1);
    Query var89(num89);

    arr85.insert(arr85.end(), var89);

    Query var85(arr85);

    arr4.insert(arr4.end(), var85);

    Types::array arr90(2);

    Types::array arr91(2);

    double num92(0);
    Query var92(num92);

    arr91.insert(arr91.end(), var92);

    double num93(68);
    Query var93(num93);

    arr91.insert(arr91.end(), var93);

    Query var91(arr91);

    arr90.insert(arr90.end(), var91);

    double num94(1);
    Query var94(num94);

    arr90.insert(arr90.end(), var94);

    Query var90(arr90);

    arr4.insert(arr4.end(), var90);

    Types::array arr95(2);

    Types::array arr96(2);

    double num97(0);
    Query var97(num97);

    arr96.insert(arr96.end(), var97);

    double num98(72);
    Query var98(num98);

    arr96.insert(arr96.end(), var98);

    Query var96(arr96);

    arr95.insert(arr95.end(), var96);

    double num99(1);
    Query var99(num99);

    arr95.insert(arr95.end(), var99);

    Query var95(arr95);

    arr4.insert(arr4.end(), var95);

    Types::array arr100(2);

    Types::array arr101(2);

    double num102(0);
    Query var102(num102);

    arr101.insert(arr101.end(), var102);

    double num103(76);
    Query var103(num103);

    arr101.insert(arr101.end(), var103);

    Query var101(arr101);

    arr100.insert(arr100.end(), var101);

    double num104(1);
    Query var104(num104);

    arr100.insert(arr100.end(), var104);

    Query var100(arr100);

    arr4.insert(arr4.end(), var100);

    Types::array arr105(2);

    Types::array arr106(2);

    double num107(0);
    Query var107(num107);

    arr106.insert(arr106.end(), var107);

    double num108(80);
    Query var108(num108);

    arr106.insert(arr106.end(), var108);

    Query var106(arr106);

    arr105.insert(arr105.end(), var106);

    double num109(1);
    Query var109(num109);

    arr105.insert(arr105.end(), var109);

    Query var105(arr105);

    arr4.insert(arr4.end(), var105);

    Types::array arr110(2);

    Types::array arr111(2);

    double num112(0);
    Query var112(num112);

    arr111.insert(arr111.end(), var112);

    double num113(84);
    Query var113(num113);

    arr111.insert(arr111.end(), var113);

    Query var111(arr111);

    arr110.insert(arr110.end(), var111);

    double num114(1);
    Query var114(num114);

    arr110.insert(arr110.end(), var114);

    Query var110(arr110);

    arr4.insert(arr4.end(), var110);

    Types::array arr115(2);

    Types::array arr116(2);

    double num117(0);
    Query var117(num117);

    arr116.insert(arr116.end(), var117);

    double num118(88);
    Query var118(num118);

    arr116.insert(arr116.end(), var118);

    Query var116(arr116);

    arr115.insert(arr115.end(), var116);

    double num119(1);
    Query var119(num119);

    arr115.insert(arr115.end(), var119);

    Query var115(arr115);

    arr4.insert(arr4.end(), var115);

    Types::array arr120(2);

    Types::array arr121(2);

    double num122(0);
    Query var122(num122);

    arr121.insert(arr121.end(), var122);

    double num123(92);
    Query var123(num123);

    arr121.insert(arr121.end(), var123);

    Query var121(arr121);

    arr120.insert(arr120.end(), var121);

    double num124(1);
    Query var124(num124);

    arr120.insert(arr120.end(), var124);

    Query var120(arr120);

    arr4.insert(arr4.end(), var120);

    Types::array arr125(2);

    Types::array arr126(2);

    double num127(0);
    Query var127(num127);

    arr126.insert(arr126.end(), var127);

    double num128(96);
    Query var128(num128);

    arr126.insert(arr126.end(), var128);

    Query var126(arr126);

    arr125.insert(arr125.end(), var126);

    double num129(1);
    Query var129(num129);

    arr125.insert(arr125.end(), var129);

    Query var125(arr125);

    arr4.insert(arr4.end(), var125);

    Types::array arr130(2);

    Types::array arr131(2);

    double num132(1);
    Query var132(num132);

    arr131.insert(arr131.end(), var132);

    double num133(1);
    Query var133(num133);

    arr131.insert(arr131.end(), var133);

    Query var131(arr131);

    arr130.insert(arr130.end(), var131);

    double num134(1);
    Query var134(num134);

    arr130.insert(arr130.end(), var134);

    Query var130(arr130);

    arr4.insert(arr4.end(), var130);

    Types::array arr135(2);

    Types::array arr136(2);

    double num137(1);
    Query var137(num137);

    arr136.insert(arr136.end(), var137);

    double num138(5);
    Query var138(num138);

    arr136.insert(arr136.end(), var138);

    Query var136(arr136);

    arr135.insert(arr135.end(), var136);

    double num139(1);
    Query var139(num139);

    arr135.insert(arr135.end(), var139);

    Query var135(arr135);

    arr4.insert(arr4.end(), var135);

    Types::array arr140(2);

    Types::array arr141(2);

    double num142(1);
    Query var142(num142);

    arr141.insert(arr141.end(), var142);

    double num143(9);
    Query var143(num143);

    arr141.insert(arr141.end(), var143);

    Query var141(arr141);

    arr140.insert(arr140.end(), var141);

    double num144(1);
    Query var144(num144);

    arr140.insert(arr140.end(), var144);

    Query var140(arr140);

    arr4.insert(arr4.end(), var140);

    Types::array arr145(2);

    Types::array arr146(2);

    double num147(1);
    Query var147(num147);

    arr146.insert(arr146.end(), var147);

    double num148(13);
    Query var148(num148);

    arr146.insert(arr146.end(), var148);

    Query var146(arr146);

    arr145.insert(arr145.end(), var146);

    double num149(1);
    Query var149(num149);

    arr145.insert(arr145.end(), var149);

    Query var145(arr145);

    arr4.insert(arr4.end(), var145);

    Types::array arr150(2);

    Types::array arr151(2);

    double num152(1);
    Query var152(num152);

    arr151.insert(arr151.end(), var152);

    double num153(17);
    Query var153(num153);

    arr151.insert(arr151.end(), var153);

    Query var151(arr151);

    arr150.insert(arr150.end(), var151);

    double num154(1);
    Query var154(num154);

    arr150.insert(arr150.end(), var154);

    Query var150(arr150);

    arr4.insert(arr4.end(), var150);

    Types::array arr155(2);

    Types::array arr156(2);

    double num157(1);
    Query var157(num157);

    arr156.insert(arr156.end(), var157);

    double num158(21);
    Query var158(num158);

    arr156.insert(arr156.end(), var158);

    Query var156(arr156);

    arr155.insert(arr155.end(), var156);

    double num159(1);
    Query var159(num159);

    arr155.insert(arr155.end(), var159);

    Query var155(arr155);

    arr4.insert(arr4.end(), var155);

    Types::array arr160(2);

    Types::array arr161(2);

    double num162(1);
    Query var162(num162);

    arr161.insert(arr161.end(), var162);

    double num163(25);
    Query var163(num163);

    arr161.insert(arr161.end(), var163);

    Query var161(arr161);

    arr160.insert(arr160.end(), var161);

    double num164(1);
    Query var164(num164);

    arr160.insert(arr160.end(), var164);

    Query var160(arr160);

    arr4.insert(arr4.end(), var160);

    Types::array arr165(2);

    Types::array arr166(2);

    double num167(1);
    Query var167(num167);

    arr166.insert(arr166.end(), var167);

    double num168(29);
    Query var168(num168);

    arr166.insert(arr166.end(), var168);

    Query var166(arr166);

    arr165.insert(arr165.end(), var166);

    double num169(1);
    Query var169(num169);

    arr165.insert(arr165.end(), var169);

    Query var165(arr165);

    arr4.insert(arr4.end(), var165);

    Types::array arr170(2);

    Types::array arr171(2);

    double num172(1);
    Query var172(num172);

    arr171.insert(arr171.end(), var172);

    double num173(33);
    Query var173(num173);

    arr171.insert(arr171.end(), var173);

    Query var171(arr171);

    arr170.insert(arr170.end(), var171);

    double num174(1);
    Query var174(num174);

    arr170.insert(arr170.end(), var174);

    Query var170(arr170);

    arr4.insert(arr4.end(), var170);

    Types::array arr175(2);

    Types::array arr176(2);

    double num177(1);
    Query var177(num177);

    arr176.insert(arr176.end(), var177);

    double num178(37);
    Query var178(num178);

    arr176.insert(arr176.end(), var178);

    Query var176(arr176);

    arr175.insert(arr175.end(), var176);

    double num179(1);
    Query var179(num179);

    arr175.insert(arr175.end(), var179);

    Query var175(arr175);

    arr4.insert(arr4.end(), var175);

    Types::array arr180(2);

    Types::array arr181(2);

    double num182(1);
    Query var182(num182);

    arr181.insert(arr181.end(), var182);

    double num183(41);
    Query var183(num183);

    arr181.insert(arr181.end(), var183);

    Query var181(arr181);

    arr180.insert(arr180.end(), var181);

    double num184(1);
    Query var184(num184);

    arr180.insert(arr180.end(), var184);

    Query var180(arr180);

    arr4.insert(arr4.end(), var180);

    Types::array arr185(2);

    Types::array arr186(2);

    double num187(1);
    Query var187(num187);

    arr186.insert(arr186.end(), var187);

    double num188(45);
    Query var188(num188);

    arr186.insert(arr186.end(), var188);

    Query var186(arr186);

    arr185.insert(arr185.end(), var186);

    double num189(1);
    Query var189(num189);

    arr185.insert(arr185.end(), var189);

    Query var185(arr185);

    arr4.insert(arr4.end(), var185);

    Types::array arr190(2);

    Types::array arr191(2);

    double num192(1);
    Query var192(num192);

    arr191.insert(arr191.end(), var192);

    double num193(49);
    Query var193(num193);

    arr191.insert(arr191.end(), var193);

    Query var191(arr191);

    arr190.insert(arr190.end(), var191);

    double num194(1);
    Query var194(num194);

    arr190.insert(arr190.end(), var194);

    Query var190(arr190);

    arr4.insert(arr4.end(), var190);

    Types::array arr195(2);

    Types::array arr196(2);

    double num197(1);
    Query var197(num197);

    arr196.insert(arr196.end(), var197);

    double num198(53);
    Query var198(num198);

    arr196.insert(arr196.end(), var198);

    Query var196(arr196);

    arr195.insert(arr195.end(), var196);

    double num199(1);
    Query var199(num199);

    arr195.insert(arr195.end(), var199);

    Query var195(arr195);

    arr4.insert(arr4.end(), var195);

    Types::array arr200(2);

    Types::array arr201(2);

    double num202(1);
    Query var202(num202);

    arr201.insert(arr201.end(), var202);

    double num203(57);
    Query var203(num203);

    arr201.insert(arr201.end(), var203);

    Query var201(arr201);

    arr200.insert(arr200.end(), var201);

    double num204(1);
    Query var204(num204);

    arr200.insert(arr200.end(), var204);

    Query var200(arr200);

    arr4.insert(arr4.end(), var200);

    Types::array arr205(2);

    Types::array arr206(2);

    double num207(1);
    Query var207(num207);

    arr206.insert(arr206.end(), var207);

    double num208(61);
    Query var208(num208);

    arr206.insert(arr206.end(), var208);

    Query var206(arr206);

    arr205.insert(arr205.end(), var206);

    double num209(1);
    Query var209(num209);

    arr205.insert(arr205.end(), var209);

    Query var205(arr205);

    arr4.insert(arr4.end(), var205);

    Types::array arr210(2);

    Types::array arr211(2);

    double num212(1);
    Query var212(num212);

    arr211.insert(arr211.end(), var212);

    double num213(65);
    Query var213(num213);

    arr211.insert(arr211.end(), var213);

    Query var211(arr211);

    arr210.insert(arr210.end(), var211);

    double num214(1);
    Query var214(num214);

    arr210.insert(arr210.end(), var214);

    Query var210(arr210);

    arr4.insert(arr4.end(), var210);

    Types::array arr215(2);

    Types::array arr216(2);

    double num217(1);
    Query var217(num217);

    arr216.insert(arr216.end(), var217);

    double num218(69);
    Query var218(num218);

    arr216.insert(arr216.end(), var218);

    Query var216(arr216);

    arr215.insert(arr215.end(), var216);

    double num219(1);
    Query var219(num219);

    arr215.insert(arr215.end(), var219);

    Query var215(arr215);

    arr4.insert(arr4.end(), var215);

    Types::array arr220(2);

    Types::array arr221(2);

    double num222(1);
    Query var222(num222);

    arr221.insert(arr221.end(), var222);

    double num223(73);
    Query var223(num223);

    arr221.insert(arr221.end(), var223);

    Query var221(arr221);

    arr220.insert(arr220.end(), var221);

    double num224(1);
    Query var224(num224);

    arr220.insert(arr220.end(), var224);

    Query var220(arr220);

    arr4.insert(arr4.end(), var220);

    Types::array arr225(2);

    Types::array arr226(2);

    double num227(1);
    Query var227(num227);

    arr226.insert(arr226.end(), var227);

    double num228(77);
    Query var228(num228);

    arr226.insert(arr226.end(), var228);

    Query var226(arr226);

    arr225.insert(arr225.end(), var226);

    double num229(1);
    Query var229(num229);

    arr225.insert(arr225.end(), var229);

    Query var225(arr225);

    arr4.insert(arr4.end(), var225);

    Types::array arr230(2);

    Types::array arr231(2);

    double num232(1);
    Query var232(num232);

    arr231.insert(arr231.end(), var232);

    double num233(81);
    Query var233(num233);

    arr231.insert(arr231.end(), var233);

    Query var231(arr231);

    arr230.insert(arr230.end(), var231);

    double num234(1);
    Query var234(num234);

    arr230.insert(arr230.end(), var234);

    Query var230(arr230);

    arr4.insert(arr4.end(), var230);

    Types::array arr235(2);

    Types::array arr236(2);

    double num237(1);
    Query var237(num237);

    arr236.insert(arr236.end(), var237);

    double num238(85);
    Query var238(num238);

    arr236.insert(arr236.end(), var238);

    Query var236(arr236);

    arr235.insert(arr235.end(), var236);

    double num239(1);
    Query var239(num239);

    arr235.insert(arr235.end(), var239);

    Query var235(arr235);

    arr4.insert(arr4.end(), var235);

    Types::array arr240(2);

    Types::array arr241(2);

    double num242(1);
    Query var242(num242);

    arr241.insert(arr241.end(), var242);

    double num243(89);
    Query var243(num243);

    arr241.insert(arr241.end(), var243);

    Query var241(arr241);

    arr240.insert(arr240.end(), var241);

    double num244(1);
    Query var244(num244);

    arr240.insert(arr240.end(), var244);

    Query var240(arr240);

    arr4.insert(arr4.end(), var240);

    Types::array arr245(2);

    Types::array arr246(2);

    double num247(1);
    Query var247(num247);

    arr246.insert(arr246.end(), var247);

    double num248(93);
    Query var248(num248);

    arr246.insert(arr246.end(), var248);

    Query var246(arr246);

    arr245.insert(arr245.end(), var246);

    double num249(1);
    Query var249(num249);

    arr245.insert(arr245.end(), var249);

    Query var245(arr245);

    arr4.insert(arr4.end(), var245);

    Types::array arr250(2);

    Types::array arr251(2);

    double num252(1);
    Query var252(num252);

    arr251.insert(arr251.end(), var252);

    double num253(97);
    Query var253(num253);

    arr251.insert(arr251.end(), var253);

    Query var251(arr251);

    arr250.insert(arr250.end(), var251);

    double num254(1);
    Query var254(num254);

    arr250.insert(arr250.end(), var254);

    Query var250(arr250);

    arr4.insert(arr4.end(), var250);

    Types::array arr255(2);

    Types::array arr256(2);

    double num257(2);
    Query var257(num257);

    arr256.insert(arr256.end(), var257);

    double num258(2);
    Query var258(num258);

    arr256.insert(arr256.end(), var258);

    Query var256(arr256);

    arr255.insert(arr255.end(), var256);

    double num259(1);
    Query var259(num259);

    arr255.insert(arr255.end(), var259);

    Query var255(arr255);

    arr4.insert(arr4.end(), var255);

    Types::array arr260(2);

    Types::array arr261(2);

    double num262(2);
    Query var262(num262);

    arr261.insert(arr261.end(), var262);

    double num263(6);
    Query var263(num263);

    arr261.insert(arr261.end(), var263);

    Query var261(arr261);

    arr260.insert(arr260.end(), var261);

    double num264(1);
    Query var264(num264);

    arr260.insert(arr260.end(), var264);

    Query var260(arr260);

    arr4.insert(arr4.end(), var260);

    Types::array arr265(2);

    Types::array arr266(2);

    double num267(2);
    Query var267(num267);

    arr266.insert(arr266.end(), var267);

    double num268(10);
    Query var268(num268);

    arr266.insert(arr266.end(), var268);

    Query var266(arr266);

    arr265.insert(arr265.end(), var266);

    double num269(1);
    Query var269(num269);

    arr265.insert(arr265.end(), var269);

    Query var265(arr265);

    arr4.insert(arr4.end(), var265);

    Types::array arr270(2);

    Types::array arr271(2);

    double num272(2);
    Query var272(num272);

    arr271.insert(arr271.end(), var272);

    double num273(14);
    Query var273(num273);

    arr271.insert(arr271.end(), var273);

    Query var271(arr271);

    arr270.insert(arr270.end(), var271);

    double num274(1);
    Query var274(num274);

    arr270.insert(arr270.end(), var274);

    Query var270(arr270);

    arr4.insert(arr4.end(), var270);

    Types::array arr275(2);

    Types::array arr276(2);

    double num277(2);
    Query var277(num277);

    arr276.insert(arr276.end(), var277);

    double num278(18);
    Query var278(num278);

    arr276.insert(arr276.end(), var278);

    Query var276(arr276);

    arr275.insert(arr275.end(), var276);

    double num279(1);
    Query var279(num279);

    arr275.insert(arr275.end(), var279);

    Query var275(arr275);

    arr4.insert(arr4.end(), var275);

    Types::array arr280(2);

    Types::array arr281(2);

    double num282(2);
    Query var282(num282);

    arr281.insert(arr281.end(), var282);

    double num283(22);
    Query var283(num283);

    arr281.insert(arr281.end(), var283);

    Query var281(arr281);

    arr280.insert(arr280.end(), var281);

    double num284(1);
    Query var284(num284);

    arr280.insert(arr280.end(), var284);

    Query var280(arr280);

    arr4.insert(arr4.end(), var280);

    Types::array arr285(2);

    Types::array arr286(2);

    double num287(2);
    Query var287(num287);

    arr286.insert(arr286.end(), var287);

    double num288(26);
    Query var288(num288);

    arr286.insert(arr286.end(), var288);

    Query var286(arr286);

    arr285.insert(arr285.end(), var286);

    double num289(1);
    Query var289(num289);

    arr285.insert(arr285.end(), var289);

    Query var285(arr285);

    arr4.insert(arr4.end(), var285);

    Types::array arr290(2);

    Types::array arr291(2);

    double num292(2);
    Query var292(num292);

    arr291.insert(arr291.end(), var292);

    double num293(30);
    Query var293(num293);

    arr291.insert(arr291.end(), var293);

    Query var291(arr291);

    arr290.insert(arr290.end(), var291);

    double num294(1);
    Query var294(num294);

    arr290.insert(arr290.end(), var294);

    Query var290(arr290);

    arr4.insert(arr4.end(), var290);

    Types::array arr295(2);

    Types::array arr296(2);

    double num297(2);
    Query var297(num297);

    arr296.insert(arr296.end(), var297);

    double num298(34);
    Query var298(num298);

    arr296.insert(arr296.end(), var298);

    Query var296(arr296);

    arr295.insert(arr295.end(), var296);

    double num299(1);
    Query var299(num299);

    arr295.insert(arr295.end(), var299);

    Query var295(arr295);

    arr4.insert(arr4.end(), var295);

    Types::array arr300(2);

    Types::array arr301(2);

    double num302(2);
    Query var302(num302);

    arr301.insert(arr301.end(), var302);

    double num303(38);
    Query var303(num303);

    arr301.insert(arr301.end(), var303);

    Query var301(arr301);

    arr300.insert(arr300.end(), var301);

    double num304(1);
    Query var304(num304);

    arr300.insert(arr300.end(), var304);

    Query var300(arr300);

    arr4.insert(arr4.end(), var300);

    Types::array arr305(2);

    Types::array arr306(2);

    double num307(2);
    Query var307(num307);

    arr306.insert(arr306.end(), var307);

    double num308(42);
    Query var308(num308);

    arr306.insert(arr306.end(), var308);

    Query var306(arr306);

    arr305.insert(arr305.end(), var306);

    double num309(1);
    Query var309(num309);

    arr305.insert(arr305.end(), var309);

    Query var305(arr305);

    arr4.insert(arr4.end(), var305);

    Types::array arr310(2);

    Types::array arr311(2);

    double num312(2);
    Query var312(num312);

    arr311.insert(arr311.end(), var312);

    double num313(46);
    Query var313(num313);

    arr311.insert(arr311.end(), var313);

    Query var311(arr311);

    arr310.insert(arr310.end(), var311);

    double num314(1);
    Query var314(num314);

    arr310.insert(arr310.end(), var314);

    Query var310(arr310);

    arr4.insert(arr4.end(), var310);

    Types::array arr315(2);

    Types::array arr316(2);

    double num317(2);
    Query var317(num317);

    arr316.insert(arr316.end(), var317);

    double num318(50);
    Query var318(num318);

    arr316.insert(arr316.end(), var318);

    Query var316(arr316);

    arr315.insert(arr315.end(), var316);

    double num319(1);
    Query var319(num319);

    arr315.insert(arr315.end(), var319);

    Query var315(arr315);

    arr4.insert(arr4.end(), var315);

    Types::array arr320(2);

    Types::array arr321(2);

    double num322(2);
    Query var322(num322);

    arr321.insert(arr321.end(), var322);

    double num323(54);
    Query var323(num323);

    arr321.insert(arr321.end(), var323);

    Query var321(arr321);

    arr320.insert(arr320.end(), var321);

    double num324(1);
    Query var324(num324);

    arr320.insert(arr320.end(), var324);

    Query var320(arr320);

    arr4.insert(arr4.end(), var320);

    Types::array arr325(2);

    Types::array arr326(2);

    double num327(2);
    Query var327(num327);

    arr326.insert(arr326.end(), var327);

    double num328(58);
    Query var328(num328);

    arr326.insert(arr326.end(), var328);

    Query var326(arr326);

    arr325.insert(arr325.end(), var326);

    double num329(1);
    Query var329(num329);

    arr325.insert(arr325.end(), var329);

    Query var325(arr325);

    arr4.insert(arr4.end(), var325);

    Types::array arr330(2);

    Types::array arr331(2);

    double num332(2);
    Query var332(num332);

    arr331.insert(arr331.end(), var332);

    double num333(62);
    Query var333(num333);

    arr331.insert(arr331.end(), var333);

    Query var331(arr331);

    arr330.insert(arr330.end(), var331);

    double num334(1);
    Query var334(num334);

    arr330.insert(arr330.end(), var334);

    Query var330(arr330);

    arr4.insert(arr4.end(), var330);

    Types::array arr335(2);

    Types::array arr336(2);

    double num337(2);
    Query var337(num337);

    arr336.insert(arr336.end(), var337);

    double num338(66);
    Query var338(num338);

    arr336.insert(arr336.end(), var338);

    Query var336(arr336);

    arr335.insert(arr335.end(), var336);

    double num339(1);
    Query var339(num339);

    arr335.insert(arr335.end(), var339);

    Query var335(arr335);

    arr4.insert(arr4.end(), var335);

    Types::array arr340(2);

    Types::array arr341(2);

    double num342(2);
    Query var342(num342);

    arr341.insert(arr341.end(), var342);

    double num343(70);
    Query var343(num343);

    arr341.insert(arr341.end(), var343);

    Query var341(arr341);

    arr340.insert(arr340.end(), var341);

    double num344(1);
    Query var344(num344);

    arr340.insert(arr340.end(), var344);

    Query var340(arr340);

    arr4.insert(arr4.end(), var340);

    Types::array arr345(2);

    Types::array arr346(2);

    double num347(2);
    Query var347(num347);

    arr346.insert(arr346.end(), var347);

    double num348(74);
    Query var348(num348);

    arr346.insert(arr346.end(), var348);

    Query var346(arr346);

    arr345.insert(arr345.end(), var346);

    double num349(1);
    Query var349(num349);

    arr345.insert(arr345.end(), var349);

    Query var345(arr345);

    arr4.insert(arr4.end(), var345);

    Types::array arr350(2);

    Types::array arr351(2);

    double num352(2);
    Query var352(num352);

    arr351.insert(arr351.end(), var352);

    double num353(78);
    Query var353(num353);

    arr351.insert(arr351.end(), var353);

    Query var351(arr351);

    arr350.insert(arr350.end(), var351);

    double num354(1);
    Query var354(num354);

    arr350.insert(arr350.end(), var354);

    Query var350(arr350);

    arr4.insert(arr4.end(), var350);

    Types::array arr355(2);

    Types::array arr356(2);

    double num357(2);
    Query var357(num357);

    arr356.insert(arr356.end(), var357);

    double num358(82);
    Query var358(num358);

    arr356.insert(arr356.end(), var358);

    Query var356(arr356);

    arr355.insert(arr355.end(), var356);

    double num359(1);
    Query var359(num359);

    arr355.insert(arr355.end(), var359);

    Query var355(arr355);

    arr4.insert(arr4.end(), var355);

    Types::array arr360(2);

    Types::array arr361(2);

    double num362(2);
    Query var362(num362);

    arr361.insert(arr361.end(), var362);

    double num363(86);
    Query var363(num363);

    arr361.insert(arr361.end(), var363);

    Query var361(arr361);

    arr360.insert(arr360.end(), var361);

    double num364(1);
    Query var364(num364);

    arr360.insert(arr360.end(), var364);

    Query var360(arr360);

    arr4.insert(arr4.end(), var360);

    Types::array arr365(2);

    Types::array arr366(2);

    double num367(2);
    Query var367(num367);

    arr366.insert(arr366.end(), var367);

    double num368(90);
    Query var368(num368);

    arr366.insert(arr366.end(), var368);

    Query var366(arr366);

    arr365.insert(arr365.end(), var366);

    double num369(1);
    Query var369(num369);

    arr365.insert(arr365.end(), var369);

    Query var365(arr365);

    arr4.insert(arr4.end(), var365);

    Types::array arr370(2);

    Types::array arr371(2);

    double num372(2);
    Query var372(num372);

    arr371.insert(arr371.end(), var372);

    double num373(94);
    Query var373(num373);

    arr371.insert(arr371.end(), var373);

    Query var371(arr371);

    arr370.insert(arr370.end(), var371);

    double num374(1);
    Query var374(num374);

    arr370.insert(arr370.end(), var374);

    Query var370(arr370);

    arr4.insert(arr4.end(), var370);

    Types::array arr375(2);

    Types::array arr376(2);

    double num377(2);
    Query var377(num377);

    arr376.insert(arr376.end(), var377);

    double num378(98);
    Query var378(num378);

    arr376.insert(arr376.end(), var378);

    Query var376(arr376);

    arr375.insert(arr375.end(), var376);

    double num379(1);
    Query var379(num379);

    arr375.insert(arr375.end(), var379);

    Query var375(arr375);

    arr4.insert(arr4.end(), var375);

    Types::array arr380(2);

    Types::array arr381(2);

    double num382(3);
    Query var382(num382);

    arr381.insert(arr381.end(), var382);

    double num383(3);
    Query var383(num383);

    arr381.insert(arr381.end(), var383);

    Query var381(arr381);

    arr380.insert(arr380.end(), var381);

    double num384(1);
    Query var384(num384);

    arr380.insert(arr380.end(), var384);

    Query var380(arr380);

    arr4.insert(arr4.end(), var380);

    Types::array arr385(2);

    Types::array arr386(2);

    double num387(3);
    Query var387(num387);

    arr386.insert(arr386.end(), var387);

    double num388(7);
    Query var388(num388);

    arr386.insert(arr386.end(), var388);

    Query var386(arr386);

    arr385.insert(arr385.end(), var386);

    double num389(1);
    Query var389(num389);

    arr385.insert(arr385.end(), var389);

    Query var385(arr385);

    arr4.insert(arr4.end(), var385);

    Types::array arr390(2);

    Types::array arr391(2);

    double num392(3);
    Query var392(num392);

    arr391.insert(arr391.end(), var392);

    double num393(11);
    Query var393(num393);

    arr391.insert(arr391.end(), var393);

    Query var391(arr391);

    arr390.insert(arr390.end(), var391);

    double num394(1);
    Query var394(num394);

    arr390.insert(arr390.end(), var394);

    Query var390(arr390);

    arr4.insert(arr4.end(), var390);

    Types::array arr395(2);

    Types::array arr396(2);

    double num397(3);
    Query var397(num397);

    arr396.insert(arr396.end(), var397);

    double num398(15);
    Query var398(num398);

    arr396.insert(arr396.end(), var398);

    Query var396(arr396);

    arr395.insert(arr395.end(), var396);

    double num399(1);
    Query var399(num399);

    arr395.insert(arr395.end(), var399);

    Query var395(arr395);

    arr4.insert(arr4.end(), var395);

    Types::array arr400(2);

    Types::array arr401(2);

    double num402(3);
    Query var402(num402);

    arr401.insert(arr401.end(), var402);

    double num403(19);
    Query var403(num403);

    arr401.insert(arr401.end(), var403);

    Query var401(arr401);

    arr400.insert(arr400.end(), var401);

    double num404(1);
    Query var404(num404);

    arr400.insert(arr400.end(), var404);

    Query var400(arr400);

    arr4.insert(arr4.end(), var400);

    Types::array arr405(2);

    Types::array arr406(2);

    double num407(3);
    Query var407(num407);

    arr406.insert(arr406.end(), var407);

    double num408(23);
    Query var408(num408);

    arr406.insert(arr406.end(), var408);

    Query var406(arr406);

    arr405.insert(arr405.end(), var406);

    double num409(1);
    Query var409(num409);

    arr405.insert(arr405.end(), var409);

    Query var405(arr405);

    arr4.insert(arr4.end(), var405);

    Types::array arr410(2);

    Types::array arr411(2);

    double num412(3);
    Query var412(num412);

    arr411.insert(arr411.end(), var412);

    double num413(27);
    Query var413(num413);

    arr411.insert(arr411.end(), var413);

    Query var411(arr411);

    arr410.insert(arr410.end(), var411);

    double num414(1);
    Query var414(num414);

    arr410.insert(arr410.end(), var414);

    Query var410(arr410);

    arr4.insert(arr4.end(), var410);

    Types::array arr415(2);

    Types::array arr416(2);

    double num417(3);
    Query var417(num417);

    arr416.insert(arr416.end(), var417);

    double num418(31);
    Query var418(num418);

    arr416.insert(arr416.end(), var418);

    Query var416(arr416);

    arr415.insert(arr415.end(), var416);

    double num419(1);
    Query var419(num419);

    arr415.insert(arr415.end(), var419);

    Query var415(arr415);

    arr4.insert(arr4.end(), var415);

    Types::array arr420(2);

    Types::array arr421(2);

    double num422(3);
    Query var422(num422);

    arr421.insert(arr421.end(), var422);

    double num423(35);
    Query var423(num423);

    arr421.insert(arr421.end(), var423);

    Query var421(arr421);

    arr420.insert(arr420.end(), var421);

    double num424(1);
    Query var424(num424);

    arr420.insert(arr420.end(), var424);

    Query var420(arr420);

    arr4.insert(arr4.end(), var420);

    Types::array arr425(2);

    Types::array arr426(2);

    double num427(3);
    Query var427(num427);

    arr426.insert(arr426.end(), var427);

    double num428(39);
    Query var428(num428);

    arr426.insert(arr426.end(), var428);

    Query var426(arr426);

    arr425.insert(arr425.end(), var426);

    double num429(1);
    Query var429(num429);

    arr425.insert(arr425.end(), var429);

    Query var425(arr425);

    arr4.insert(arr4.end(), var425);

    Types::array arr430(2);

    Types::array arr431(2);

    double num432(3);
    Query var432(num432);

    arr431.insert(arr431.end(), var432);

    double num433(43);
    Query var433(num433);

    arr431.insert(arr431.end(), var433);

    Query var431(arr431);

    arr430.insert(arr430.end(), var431);

    double num434(1);
    Query var434(num434);

    arr430.insert(arr430.end(), var434);

    Query var430(arr430);

    arr4.insert(arr4.end(), var430);

    Types::array arr435(2);

    Types::array arr436(2);

    double num437(3);
    Query var437(num437);

    arr436.insert(arr436.end(), var437);

    double num438(47);
    Query var438(num438);

    arr436.insert(arr436.end(), var438);

    Query var436(arr436);

    arr435.insert(arr435.end(), var436);

    double num439(1);
    Query var439(num439);

    arr435.insert(arr435.end(), var439);

    Query var435(arr435);

    arr4.insert(arr4.end(), var435);

    Types::array arr440(2);

    Types::array arr441(2);

    double num442(3);
    Query var442(num442);

    arr441.insert(arr441.end(), var442);

    double num443(51);
    Query var443(num443);

    arr441.insert(arr441.end(), var443);

    Query var441(arr441);

    arr440.insert(arr440.end(), var441);

    double num444(1);
    Query var444(num444);

    arr440.insert(arr440.end(), var444);

    Query var440(arr440);

    arr4.insert(arr4.end(), var440);

    Types::array arr445(2);

    Types::array arr446(2);

    double num447(3);
    Query var447(num447);

    arr446.insert(arr446.end(), var447);

    double num448(55);
    Query var448(num448);

    arr446.insert(arr446.end(), var448);

    Query var446(arr446);

    arr445.insert(arr445.end(), var446);

    double num449(1);
    Query var449(num449);

    arr445.insert(arr445.end(), var449);

    Query var445(arr445);

    arr4.insert(arr4.end(), var445);

    Types::array arr450(2);

    Types::array arr451(2);

    double num452(3);
    Query var452(num452);

    arr451.insert(arr451.end(), var452);

    double num453(59);
    Query var453(num453);

    arr451.insert(arr451.end(), var453);

    Query var451(arr451);

    arr450.insert(arr450.end(), var451);

    double num454(1);
    Query var454(num454);

    arr450.insert(arr450.end(), var454);

    Query var450(arr450);

    arr4.insert(arr4.end(), var450);

    Types::array arr455(2);

    Types::array arr456(2);

    double num457(3);
    Query var457(num457);

    arr456.insert(arr456.end(), var457);

    double num458(63);
    Query var458(num458);

    arr456.insert(arr456.end(), var458);

    Query var456(arr456);

    arr455.insert(arr455.end(), var456);

    double num459(1);
    Query var459(num459);

    arr455.insert(arr455.end(), var459);

    Query var455(arr455);

    arr4.insert(arr4.end(), var455);

    Types::array arr460(2);

    Types::array arr461(2);

    double num462(3);
    Query var462(num462);

    arr461.insert(arr461.end(), var462);

    double num463(67);
    Query var463(num463);

    arr461.insert(arr461.end(), var463);

    Query var461(arr461);

    arr460.insert(arr460.end(), var461);

    double num464(1);
    Query var464(num464);

    arr460.insert(arr460.end(), var464);

    Query var460(arr460);

    arr4.insert(arr4.end(), var460);

    Types::array arr465(2);

    Types::array arr466(2);

    double num467(3);
    Query var467(num467);

    arr466.insert(arr466.end(), var467);

    double num468(71);
    Query var468(num468);

    arr466.insert(arr466.end(), var468);

    Query var466(arr466);

    arr465.insert(arr465.end(), var466);

    double num469(1);
    Query var469(num469);

    arr465.insert(arr465.end(), var469);

    Query var465(arr465);

    arr4.insert(arr4.end(), var465);

    Types::array arr470(2);

    Types::array arr471(2);

    double num472(3);
    Query var472(num472);

    arr471.insert(arr471.end(), var472);

    double num473(75);
    Query var473(num473);

    arr471.insert(arr471.end(), var473);

    Query var471(arr471);

    arr470.insert(arr470.end(), var471);

    double num474(1);
    Query var474(num474);

    arr470.insert(arr470.end(), var474);

    Query var470(arr470);

    arr4.insert(arr4.end(), var470);

    Types::array arr475(2);

    Types::array arr476(2);

    double num477(3);
    Query var477(num477);

    arr476.insert(arr476.end(), var477);

    double num478(79);
    Query var478(num478);

    arr476.insert(arr476.end(), var478);

    Query var476(arr476);

    arr475.insert(arr475.end(), var476);

    double num479(1);
    Query var479(num479);

    arr475.insert(arr475.end(), var479);

    Query var475(arr475);

    arr4.insert(arr4.end(), var475);

    Types::array arr480(2);

    Types::array arr481(2);

    double num482(3);
    Query var482(num482);

    arr481.insert(arr481.end(), var482);

    double num483(83);
    Query var483(num483);

    arr481.insert(arr481.end(), var483);

    Query var481(arr481);

    arr480.insert(arr480.end(), var481);

    double num484(1);
    Query var484(num484);

    arr480.insert(arr480.end(), var484);

    Query var480(arr480);

    arr4.insert(arr4.end(), var480);

    Types::array arr485(2);

    Types::array arr486(2);

    double num487(3);
    Query var487(num487);

    arr486.insert(arr486.end(), var487);

    double num488(87);
    Query var488(num488);

    arr486.insert(arr486.end(), var488);

    Query var486(arr486);

    arr485.insert(arr485.end(), var486);

    double num489(1);
    Query var489(num489);

    arr485.insert(arr485.end(), var489);

    Query var485(arr485);

    arr4.insert(arr4.end(), var485);

    Types::array arr490(2);

    Types::array arr491(2);

    double num492(3);
    Query var492(num492);

    arr491.insert(arr491.end(), var492);

    double num493(91);
    Query var493(num493);

    arr491.insert(arr491.end(), var493);

    Query var491(arr491);

    arr490.insert(arr490.end(), var491);

    double num494(1);
    Query var494(num494);

    arr490.insert(arr490.end(), var494);

    Query var490(arr490);

    arr4.insert(arr4.end(), var490);

    Types::array arr495(2);

    Types::array arr496(2);

    double num497(3);
    Query var497(num497);

    arr496.insert(arr496.end(), var497);

    double num498(95);
    Query var498(num498);

    arr496.insert(arr496.end(), var498);

    Query var496(arr496);

    arr495.insert(arr495.end(), var496);

    double num499(1);
    Query var499(num499);

    arr495.insert(arr495.end(), var499);

    Query var495(arr495);

    arr4.insert(arr4.end(), var495);

    Types::array arr500(2);

    Types::array arr501(2);

    double num502(3);
    Query var502(num502);

    arr501.insert(arr501.end(), var502);

    double num503(99);
    Query var503(num503);

    arr501.insert(arr501.end(), var503);

    Query var501(arr501);

    arr500.insert(arr500.end(), var501);

    double num504(1);
    Query var504(num504);

    arr500.insert(arr500.end(), var504);

    Query var500(arr500);

    arr4.insert(arr4.end(), var500);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test87") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(4);

    Types::array arr5(2);

    Types::array arr6(2);

    double num7(0);
    Query var7(num7);

    arr6.insert(arr6.end(), var7);

    double num8(0);
    Query var8(num8);

    arr6.insert(arr6.end(), var8);

    Query var6(arr6);

    arr5.insert(arr5.end(), var6);

    double num9(25);
    Query var9(num9);

    arr5.insert(arr5.end(), var9);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr10(2);

    Types::array arr11(2);

    double num12(1);
    Query var12(num12);

    arr11.insert(arr11.end(), var12);

    double num13(1);
    Query var13(num13);

    arr11.insert(arr11.end(), var13);

    Query var11(arr11);

    arr10.insert(arr10.end(), var11);

    double num14(25);
    Query var14(num14);

    arr10.insert(arr10.end(), var14);

    Query var10(arr10);

    arr4.insert(arr4.end(), var10);

    Types::array arr15(2);

    Types::array arr16(2);

    double num17(2);
    Query var17(num17);

    arr16.insert(arr16.end(), var17);

    double num18(2);
    Query var18(num18);

    arr16.insert(arr16.end(), var18);

    Query var16(arr16);

    arr15.insert(arr15.end(), var16);

    double num19(25);
    Query var19(num19);

    arr15.insert(arr15.end(), var19);

    Query var15(arr15);

    arr4.insert(arr4.end(), var15);

    Types::array arr20(2);

    Types::array arr21(2);

    double num22(3);
    Query var22(num22);

    arr21.insert(arr21.end(), var22);

    double num23(3);
    Query var23(num23);

    arr21.insert(arr21.end(), var23);

    Query var21(arr21);

    arr20.insert(arr20.end(), var21);

    double num24(25);
    Query var24(num24);

    arr20.insert(arr20.end(), var24);

    Query var20(arr20);

    arr4.insert(arr4.end(), var20);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test88") {
    Types::object map0;

    std::string src1("$reql_type$", 11);
    Query var1(src1);

    std::string src2("GROUPED_DATA", 12);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("data", 4);
    Query var3(src3);

    Types::array arr4(16);

    Types::array arr5(2);

    Types::array arr6(4);

    double num7(0);
    Query var7(num7);

    arr6.insert(arr6.end(), var7);

    std::string src8("f", 1);
    Query var8(src8);

    arr6.insert(arr6.end(), var8);

    Query var9;

    arr6.insert(arr6.end(), var9);

    Types::array arr10(1);

    double num11(0);
    Query var11(num11);

    arr10.insert(arr10.end(), var11);

    Query var10(arr10);

    arr6.insert(arr6.end(), var10);

    Query var6(arr6);

    arr5.insert(arr5.end(), var6);

    double num12(25);
    Query var12(num12);

    arr5.insert(arr5.end(), var12);

    Query var5(arr5);

    arr4.insert(arr4.end(), var5);

    Types::array arr13(2);

    Types::array arr14(4);

    double num15(0);
    Query var15(num15);

    arr14.insert(arr14.end(), var15);

    std::string src16("f", 1);
    Query var16(src16);

    arr14.insert(arr14.end(), var16);

    Query var17;

    arr14.insert(arr14.end(), var17);

    Query var18;

    arr14.insert(arr14.end(), var18);

    Query var14(arr14);

    arr13.insert(arr13.end(), var14);

    double num19(25);
    Query var19(num19);

    arr13.insert(arr13.end(), var19);

    Query var13(arr13);

    arr4.insert(arr4.end(), var13);

    Types::array arr20(2);

    Types::array arr21(4);

    double num22(0);
    Query var22(num22);

    arr21.insert(arr21.end(), var22);

    std::string src23("f", 1);
    Query var23(src23);

    arr21.insert(arr21.end(), var23);

    Query var24;

    arr21.insert(arr21.end(), var24);

    double num25(0);
    Query var25(num25);

    arr21.insert(arr21.end(), var25);

    Query var21(arr21);

    arr20.insert(arr20.end(), var21);

    double num26(25);
    Query var26(num26);

    arr20.insert(arr20.end(), var26);

    Query var20(arr20);

    arr4.insert(arr4.end(), var20);

    Types::array arr27(2);

    Types::array arr28(4);

    double num29(0);
    Query var29(num29);

    arr28.insert(arr28.end(), var29);

    std::string src30("f", 1);
    Query var30(src30);

    arr28.insert(arr28.end(), var30);

    Query var31;

    arr28.insert(arr28.end(), var31);

    Types::object map32;
    Query var32(map32);

    arr28.insert(arr28.end(), var32);

    Query var28(arr28);

    arr27.insert(arr27.end(), var28);

    double num33(25);
    Query var33(num33);

    arr27.insert(arr27.end(), var33);

    Query var27(arr27);

    arr4.insert(arr4.end(), var27);

    Types::array arr34(2);

    Types::array arr35(4);

    double num36(1);
    Query var36(num36);

    arr35.insert(arr35.end(), var36);

    std::string src37("f", 1);
    Query var37(src37);

    arr35.insert(arr35.end(), var37);

    Query var38;

    arr35.insert(arr35.end(), var38);

    Types::array arr39(1);

    double num40(0);
    Query var40(num40);

    arr39.insert(arr39.end(), var40);

    Query var39(arr39);

    arr35.insert(arr35.end(), var39);

    Query var35(arr35);

    arr34.insert(arr34.end(), var35);

    double num41(25);
    Query var41(num41);

    arr34.insert(arr34.end(), var41);

    Query var34(arr34);

    arr4.insert(arr4.end(), var34);

    Types::array arr42(2);

    Types::array arr43(4);

    double num44(1);
    Query var44(num44);

    arr43.insert(arr43.end(), var44);

    std::string src45("f", 1);
    Query var45(src45);

    arr43.insert(arr43.end(), var45);

    Query var46;

    arr43.insert(arr43.end(), var46);

    Query var47;

    arr43.insert(arr43.end(), var47);

    Query var43(arr43);

    arr42.insert(arr42.end(), var43);

    double num48(25);
    Query var48(num48);

    arr42.insert(arr42.end(), var48);

    Query var42(arr42);

    arr4.insert(arr4.end(), var42);

    Types::array arr49(2);

    Types::array arr50(4);

    double num51(1);
    Query var51(num51);

    arr50.insert(arr50.end(), var51);

    std::string src52("f", 1);
    Query var52(src52);

    arr50.insert(arr50.end(), var52);

    Query var53;

    arr50.insert(arr50.end(), var53);

    double num54(0);
    Query var54(num54);

    arr50.insert(arr50.end(), var54);

    Query var50(arr50);

    arr49.insert(arr49.end(), var50);

    double num55(25);
    Query var55(num55);

    arr49.insert(arr49.end(), var55);

    Query var49(arr49);

    arr4.insert(arr4.end(), var49);

    Types::array arr56(2);

    Types::array arr57(4);

    double num58(1);
    Query var58(num58);

    arr57.insert(arr57.end(), var58);

    std::string src59("f", 1);
    Query var59(src59);

    arr57.insert(arr57.end(), var59);

    Query var60;

    arr57.insert(arr57.end(), var60);

    Types::object map61;
    Query var61(map61);

    arr57.insert(arr57.end(), var61);

    Query var57(arr57);

    arr56.insert(arr56.end(), var57);

    double num62(25);
    Query var62(num62);

    arr56.insert(arr56.end(), var62);

    Query var56(arr56);

    arr4.insert(arr4.end(), var56);

    Types::array arr63(2);

    Types::array arr64(4);

    double num65(2);
    Query var65(num65);

    arr64.insert(arr64.end(), var65);

    std::string src66("f", 1);
    Query var66(src66);

    arr64.insert(arr64.end(), var66);

    Query var67;

    arr64.insert(arr64.end(), var67);

    Types::array arr68(1);

    double num69(0);
    Query var69(num69);

    arr68.insert(arr68.end(), var69);

    Query var68(arr68);

    arr64.insert(arr64.end(), var68);

    Query var64(arr64);

    arr63.insert(arr63.end(), var64);

    double num70(25);
    Query var70(num70);

    arr63.insert(arr63.end(), var70);

    Query var63(arr63);

    arr4.insert(arr4.end(), var63);

    Types::array arr71(2);

    Types::array arr72(4);

    double num73(2);
    Query var73(num73);

    arr72.insert(arr72.end(), var73);

    std::string src74("f", 1);
    Query var74(src74);

    arr72.insert(arr72.end(), var74);

    Query var75;

    arr72.insert(arr72.end(), var75);

    Query var76;

    arr72.insert(arr72.end(), var76);

    Query var72(arr72);

    arr71.insert(arr71.end(), var72);

    double num77(25);
    Query var77(num77);

    arr71.insert(arr71.end(), var77);

    Query var71(arr71);

    arr4.insert(arr4.end(), var71);

    Types::array arr78(2);

    Types::array arr79(4);

    double num80(2);
    Query var80(num80);

    arr79.insert(arr79.end(), var80);

    std::string src81("f", 1);
    Query var81(src81);

    arr79.insert(arr79.end(), var81);

    Query var82;

    arr79.insert(arr79.end(), var82);

    double num83(0);
    Query var83(num83);

    arr79.insert(arr79.end(), var83);

    Query var79(arr79);

    arr78.insert(arr78.end(), var79);

    double num84(25);
    Query var84(num84);

    arr78.insert(arr78.end(), var84);

    Query var78(arr78);

    arr4.insert(arr4.end(), var78);

    Types::array arr85(2);

    Types::array arr86(4);

    double num87(2);
    Query var87(num87);

    arr86.insert(arr86.end(), var87);

    std::string src88("f", 1);
    Query var88(src88);

    arr86.insert(arr86.end(), var88);

    Query var89;

    arr86.insert(arr86.end(), var89);

    Types::object map90;
    Query var90(map90);

    arr86.insert(arr86.end(), var90);

    Query var86(arr86);

    arr85.insert(arr85.end(), var86);

    double num91(25);
    Query var91(num91);

    arr85.insert(arr85.end(), var91);

    Query var85(arr85);

    arr4.insert(arr4.end(), var85);

    Types::array arr92(2);

    Types::array arr93(4);

    double num94(3);
    Query var94(num94);

    arr93.insert(arr93.end(), var94);

    std::string src95("f", 1);
    Query var95(src95);

    arr93.insert(arr93.end(), var95);

    Query var96;

    arr93.insert(arr93.end(), var96);

    Types::array arr97(1);

    double num98(0);
    Query var98(num98);

    arr97.insert(arr97.end(), var98);

    Query var97(arr97);

    arr93.insert(arr93.end(), var97);

    Query var93(arr93);

    arr92.insert(arr92.end(), var93);

    double num99(25);
    Query var99(num99);

    arr92.insert(arr92.end(), var99);

    Query var92(arr92);

    arr4.insert(arr4.end(), var92);

    Types::array arr100(2);

    Types::array arr101(4);

    double num102(3);
    Query var102(num102);

    arr101.insert(arr101.end(), var102);

    std::string src103("f", 1);
    Query var103(src103);

    arr101.insert(arr101.end(), var103);

    Query var104;

    arr101.insert(arr101.end(), var104);

    Query var105;

    arr101.insert(arr101.end(), var105);

    Query var101(arr101);

    arr100.insert(arr100.end(), var101);

    double num106(25);
    Query var106(num106);

    arr100.insert(arr100.end(), var106);

    Query var100(arr100);

    arr4.insert(arr4.end(), var100);

    Types::array arr107(2);

    Types::array arr108(4);

    double num109(3);
    Query var109(num109);

    arr108.insert(arr108.end(), var109);

    std::string src110("f", 1);
    Query var110(src110);

    arr108.insert(arr108.end(), var110);

    Query var111;

    arr108.insert(arr108.end(), var111);

    double num112(0);
    Query var112(num112);

    arr108.insert(arr108.end(), var112);

    Query var108(arr108);

    arr107.insert(arr107.end(), var108);

    double num113(25);
    Query var113(num113);

    arr107.insert(arr107.end(), var113);

    Query var107(arr107);

    arr4.insert(arr4.end(), var107);

    Types::array arr114(2);

    Types::array arr115(4);

    double num116(3);
    Query var116(num116);

    arr115.insert(arr115.end(), var116);

    std::string src117("f", 1);
    Query var117(src117);

    arr115.insert(arr115.end(), var117);

    Query var118;

    arr115.insert(arr115.end(), var118);

    Types::object map119;
    Query var119(map119);

    arr115.insert(arr115.end(), var119);

    Query var115(arr115);

    arr114.insert(arr114.end(), var115);

    double num120(25);
    Query var120(num120);

    arr114.insert(arr114.end(), var120);

    Query var114(arr114);

    arr4.insert(arr4.end(), var114);

    Query var4(arr4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test89") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    double num3(0);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("reduction", 9);
    Query var4(src4);

    double num5(25);
    Query var5(num5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("group", 5);
    Query var7(src7);

    double num8(1);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("reduction", 9);
    Query var9(src9);

    double num10(25);
    Query var10(num10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("group", 5);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("reduction", 9);
    Query var14(src14);

    double num15(25);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("group", 5);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    std::string src19("reduction", 9);
    Query var19(src19);

    double num20(25);
    Query var20(num20);

    map16.insert({src19, var20});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test90") {
    Types::array arr0(4);

    double num1(0);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(2);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(3);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test91") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    Types::array arr3(2);

    double num4(0);
    Query var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(0);
    Query var5(num5);

    arr3.insert(arr3.end(), var5);

    Query var3(arr3);

    map1.insert({src2, var3});

    std::string src6("reduction", 9);
    Query var6(src6);

    double num7(24);
    Query var7(num7);

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("group", 5);
    Query var9(src9);

    Types::array arr10(2);

    double num11(1);
    Query var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(1);
    Query var12(num12);

    arr10.insert(arr10.end(), var12);

    Query var10(arr10);

    map8.insert({src9, var10});

    std::string src13("reduction", 9);
    Query var13(src13);

    double num14(28);
    Query var14(num14);

    map8.insert({src13, var14});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Types::object map15;

    std::string src16("group", 5);
    Query var16(src16);

    Types::array arr17(2);

    double num18(2);
    Query var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(2);
    Query var19(num19);

    arr17.insert(arr17.end(), var19);

    Query var17(arr17);

    map15.insert({src16, var17});

    std::string src20("reduction", 9);
    Query var20(src20);

    double num21(32);
    Query var21(num21);

    map15.insert({src20, var21});

    Query var15(map15);

    arr0.insert(arr0.end(), var15);

    Types::object map22;

    std::string src23("group", 5);
    Query var23(src23);

    Types::array arr24(2);

    double num25(3);
    Query var25(num25);

    arr24.insert(arr24.end(), var25);

    double num26(3);
    Query var26(num26);

    arr24.insert(arr24.end(), var26);

    Query var24(arr24);

    map22.insert({src23, var24});

    std::string src27("reduction", 9);
    Query var27(src27);

    double num28(36);
    Query var28(num28);

    map22.insert({src27, var28});

    Query var22(map22);

    arr0.insert(arr0.end(), var22);

    Query var0(arr0);
  }

  SECTION("test92") {
    Types::array arr0(4);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    Types::array arr3(2);

    double num4(0);
    Query var4(num4);

    arr3.insert(arr3.end(), var4);

    Query var5;

    arr3.insert(arr3.end(), var5);

    Query var3(arr3);

    map1.insert({src2, var3});

    std::string src6("reduction", 9);
    Query var6(src6);

    double num7(25);
    Query var7(num7);

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("group", 5);
    Query var9(src9);

    Types::array arr10(2);

    double num11(1);
    Query var11(num11);

    arr10.insert(arr10.end(), var11);

    Query var12;

    arr10.insert(arr10.end(), var12);

    Query var10(arr10);

    map8.insert({src9, var10});

    std::string src13("reduction", 9);
    Query var13(src13);

    double num14(25);
    Query var14(num14);

    map8.insert({src13, var14});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Types::object map15;

    std::string src16("group", 5);
    Query var16(src16);

    Types::array arr17(2);

    double num18(2);
    Query var18(num18);

    arr17.insert(arr17.end(), var18);

    Query var19;

    arr17.insert(arr17.end(), var19);

    Query var17(arr17);

    map15.insert({src16, var17});

    std::string src20("reduction", 9);
    Query var20(src20);

    double num21(25);
    Query var21(num21);

    map15.insert({src20, var21});

    Query var15(map15);

    arr0.insert(arr0.end(), var15);

    Types::object map22;

    std::string src23("group", 5);
    Query var23(src23);

    Types::array arr24(2);

    double num25(3);
    Query var25(num25);

    arr24.insert(arr24.end(), var25);

    Query var26;

    arr24.insert(arr24.end(), var26);

    Query var24(arr24);

    map22.insert({src23, var24});

    std::string src27("reduction", 9);
    Query var27(src27);

    double num28(25);
    Query var28(num28);

    map22.insert({src27, var28});

    Query var22(map22);

    arr0.insert(arr0.end(), var22);

    Query var0(arr0);
  }

  SECTION("test93") {
    Types::array arr0(8);

    Types::object map1;

    std::string src2("group", 5);
    Query var2(src2);

    Types::array arr3(2);

    double num4(0);
    Query var4(num4);

    arr3.insert(arr3.end(), var4);

    double num5(1);
    Query var5(num5);

    arr3.insert(arr3.end(), var5);

    Query var3(arr3);

    map1.insert({src2, var3});

    std::string src6("reduction", 9);
    Query var6(src6);

    double num7(25);
    Query var7(num7);

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("group", 5);
    Query var9(src9);

    Types::array arr10(2);

    double num11(0);
    Query var11(num11);

    arr10.insert(arr10.end(), var11);

    std::string src12("two", 3);
    Query var12(src12);

    arr10.insert(arr10.end(), var12);

    Query var10(arr10);

    map8.insert({src9, var10});

    std::string src13("reduction", 9);
    Query var13(src13);

    double num14(25);
    Query var14(num14);

    map8.insert({src13, var14});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Types::object map15;

    std::string src16("group", 5);
    Query var16(src16);

    Types::array arr17(2);

    double num18(1);
    Query var18(num18);

    arr17.insert(arr17.end(), var18);

    double num19(1);
    Query var19(num19);

    arr17.insert(arr17.end(), var19);

    Query var17(arr17);

    map15.insert({src16, var17});

    std::string src20("reduction", 9);
    Query var20(src20);

    double num21(25);
    Query var21(num21);

    map15.insert({src20, var21});

    Query var15(map15);

    arr0.insert(arr0.end(), var15);

    Types::object map22;

    std::string src23("group", 5);
    Query var23(src23);

    Types::array arr24(2);

    double num25(1);
    Query var25(num25);

    arr24.insert(arr24.end(), var25);

    std::string src26("two", 3);
    Query var26(src26);

    arr24.insert(arr24.end(), var26);

    Query var24(arr24);

    map22.insert({src23, var24});

    std::string src27("reduction", 9);
    Query var27(src27);

    double num28(25);
    Query var28(num28);

    map22.insert({src27, var28});

    Query var22(map22);

    arr0.insert(arr0.end(), var22);

    Types::object map29;

    std::string src30("group", 5);
    Query var30(src30);

    Types::array arr31(2);

    double num32(2);
    Query var32(num32);

    arr31.insert(arr31.end(), var32);

    double num33(1);
    Query var33(num33);

    arr31.insert(arr31.end(), var33);

    Query var31(arr31);

    map29.insert({src30, var31});

    std::string src34("reduction", 9);
    Query var34(src34);

    double num35(25);
    Query var35(num35);

    map29.insert({src34, var35});

    Query var29(map29);

    arr0.insert(arr0.end(), var29);

    Types::object map36;

    std::string src37("group", 5);
    Query var37(src37);

    Types::array arr38(2);

    double num39(2);
    Query var39(num39);

    arr38.insert(arr38.end(), var39);

    std::string src40("two", 3);
    Query var40(src40);

    arr38.insert(arr38.end(), var40);

    Query var38(arr38);

    map36.insert({src37, var38});

    std::string src41("reduction", 9);
    Query var41(src41);

    double num42(25);
    Query var42(num42);

    map36.insert({src41, var42});

    Query var36(map36);

    arr0.insert(arr0.end(), var36);

    Types::object map43;

    std::string src44("group", 5);
    Query var44(src44);

    Types::array arr45(2);

    double num46(3);
    Query var46(num46);

    arr45.insert(arr45.end(), var46);

    double num47(1);
    Query var47(num47);

    arr45.insert(arr45.end(), var47);

    Query var45(arr45);

    map43.insert({src44, var45});

    std::string src48("reduction", 9);
    Query var48(src48);

    double num49(25);
    Query var49(num49);

    map43.insert({src48, var49});

    Query var43(map43);

    arr0.insert(arr0.end(), var43);

    Types::object map50;

    std::string src51("group", 5);
    Query var51(src51);

    Types::array arr52(2);

    double num53(3);
    Query var53(num53);

    arr52.insert(arr52.end(), var53);

    std::string src54("two", 3);
    Query var54(src54);

    arr52.insert(arr52.end(), var54);

    Query var52(arr52);

    map50.insert({src51, var52});

    std::string src55("reduction", 9);
    Query var55(src55);

    double num56(25);
    Query var56(num56);

    map50.insert({src55, var56});

    Query var50(map50);

    arr0.insert(arr0.end(), var50);

    Query var0(arr0);
  }

  SECTION("test94") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test102") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test103") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test104") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test105") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(99);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test106") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(99);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test107") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(99);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }
}
