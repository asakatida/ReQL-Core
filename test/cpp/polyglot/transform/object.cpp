// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests manipulation operations on objects", "[cpp][ast]") {

  SECTION("test1") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test2") {
    std::string src0("str", 3);
    Result var0(src0);
  }

  SECTION("test3") {
    Result var0(true);
  }

  SECTION("test4") {
    Result var0(true);
  }

  SECTION("test5") {
    Result var0(false);
  }

  SECTION("test6") {
    Result var0(true);
  }

  SECTION("test7") {
    Result var0(false);
  }

  SECTION("test8") {
    Result var0(false);
  }

  SECTION("test9") {
    Result var0(true);
  }

  SECTION("test10") {
    Result var0(false);
  }

  SECTION("test11") {
    Result var0(false);
  }

  SECTION("test12") {
    Result var0(true);
  }

  SECTION("test13") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test14") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test15") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test17") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Result var3(src3);

    double num4(2);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("e", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("f", 1);
    Result var3(src3);

    std::string src4("buzz", 4);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    std::string src5("d", 1);
    Result var5(src5);

    Result var6;

    map0.insert({src5, var6});

    std::string src7("b", 1);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("c", 1);
    Result var9(src9);

    std::string src10("str", 3);
    Result var10(src10);

    map0.insert({src9, var10});

    Result var0(map0);
  }

  SECTION("test19") {
    std::map<std::string, Result> map0;

    std::string src1("e", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("f", 1);
    Result var3(src3);

    std::string src4("buzz", 4);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    std::string src5("d", 1);
    Result var5(src5);

    Result var6;

    map0.insert({src5, var6});

    std::string src7("c", 1);
    Result var7(src7);

    std::string src8("str", 3);
    Result var8(src8);

    map0.insert({src7, var8});

    Result var0(map0);
  }

  SECTION("test20") {
    std::map<std::string, Result> map0;

    std::string src1("e", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("f", 1);
    Result var3(src3);

    std::string src4("buzz", 4);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test21") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Result var3(src3);

    Result var4;

    map0.insert({src3, var4});

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("e", 1);
    Result var7(src7);

    std::map<std::string, Result> map8;
    Result var8(map8);

    map0.insert({src7, var8});

    std::string src9("c", 1);
    Result var9(src9);

    std::string src10("str", 3);
    Result var10(src10);

    map0.insert({src9, var10});

    Result var0(map0);
  }

  SECTION("test22") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Result var3(src3);

    Result var4;

    map0.insert({src3, var4});

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("e", 1);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("f", 1);
    Result var9(src9);

    std::string src10("buzz", 4);
    Result var10(src10);

    map8.insert({src9, var10});

    Result var8(map8);

    map0.insert({src7, var8});

    std::string src11("c", 1);
    Result var11(src11);

    std::string src12("str", 3);
    Result var12(src12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test23") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test24") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Result var3(src3);

    Result var4;

    map0.insert({src3, var4});

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("e", 1);
    Result var7(src7);

    double num8(-2);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("c", 1);
    Result var9(src9);

    std::string src10("str", 3);
    Result var10(src10);

    map0.insert({src9, var10});

    Result var0(map0);
  }

  SECTION("test25") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Result var3(src3);

    Result var4;

    map0.insert({src3, var4});

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("c", 1);
    Result var7(src7);

    std::string src8("str", 3);
    Result var8(src8);

    map0.insert({src7, var8});

    Result var0(map0);
  }

  SECTION("test26") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Result var3(src3);

    Result var4;

    map0.insert({src3, var4});

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("e", 1);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("f", 1);
    Result var9(src9);

    std::string src10("quux", 4);
    Result var10(src10);

    map8.insert({src9, var10});

    Result var8(map8);

    map0.insert({src7, var8});

    std::string src11("c", 1);
    Result var11(src11);

    std::string src12("str", 3);
    Result var12(src12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test27") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Result var3(src3);

    Result var4;

    map0.insert({src3, var4});

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("e", 1);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("f", 1);
    Result var9(src9);

    std::string src10("buzz", 4);
    Result var10(src10);

    map8.insert({src9, var10});

    std::string src11("g", 1);
    Result var11(src11);

    std::string src12("quux", 4);
    Result var12(src12);

    map8.insert({src11, var12});

    Result var8(map8);

    map0.insert({src7, var8});

    std::string src13("c", 1);
    Result var13(src13);

    std::string src14("str", 3);
    Result var14(src14);

    map0.insert({src13, var14});

    Result var0(map0);
  }

  SECTION("test28") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Result var3(src3);

    Result var4;

    map0.insert({src3, var4});

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("e", 1);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("g", 1);
    Result var9(src9);

    std::string src10("quux", 4);
    Result var10(src10);

    map8.insert({src9, var10});

    Result var8(map8);

    map0.insert({src7, var8});

    std::string src11("c", 1);
    Result var11(src11);

    std::string src12("str", 3);
    Result var12(src12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test29") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(-1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Result var3(src3);

    Result var4;

    map0.insert({src3, var4});

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("e", 1);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("f", 1);
    Result var9(src9);

    std::string src10("buzz", 4);
    Result var10(src10);

    map8.insert({src9, var10});

    Result var8(map8);

    map0.insert({src7, var8});

    std::string src11("c", 1);
    Result var11(src11);

    std::string src12("str", 3);
    Result var12(src12);

    map0.insert({src11, var12});

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

  SECTION("test33") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test35") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("b", 1);
    Result var3(src3);

    double num4(1);
    Result var4(num4);

    map2.insert({src3, var4});

    std::string src5("c", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map2.insert({src5, var6});

    Result var2(map2);

    map0.insert({src1, var2});

    std::string src7("d", 1);
    Result var7(src7);

    double num8(3);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("f", 1);
    Result var9(src9);

    double num10(5);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("e", 1);
    Result var11(src11);

    double num12(4);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test36") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("b", 1);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    std::string src6("c", 1);
    Result var6(src6);

    double num7(2);
    Result var7(num7);

    map3.insert({src6, var7});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src8("d", 1);
    Result var8(src8);

    double num9(3);
    Result var9(num9);

    map1.insert({src8, var9});

    std::string src10("e", 1);
    Result var10(src10);

    double num11(3);
    Result var11(num11);

    map1.insert({src10, var11});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map12;

    std::string src13("a", 1);
    Result var13(src13);

    std::map<std::string, Result> map14;

    std::string src15("b", 1);
    Result var15(src15);

    double num16(1);
    Result var16(num16);

    map14.insert({src15, var16});

    std::string src17("c", 1);
    Result var17(src17);

    double num18(2);
    Result var18(num18);

    map14.insert({src17, var18});

    Result var14(map14);

    map12.insert({src13, var14});

    std::string src19("d", 1);
    Result var19(src19);

    double num20(4);
    Result var20(num20);

    map12.insert({src19, var20});

    std::string src21("e", 1);
    Result var21(src21);

    double num22(4);
    Result var22(num22);

    map12.insert({src21, var22});

    Result var12(map12);

    arr0.insert(arr0.end(), var12);

    Result var0(arr0);
  }

  SECTION("test37") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("b", 1);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    std::string src6("c", 1);
    Result var6(src6);

    double num7(2);
    Result var7(num7);

    map3.insert({src6, var7});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src8("d", 1);
    Result var8(src8);

    double num9(3);
    Result var9(num9);

    map1.insert({src8, var9});

    std::string src10("e", 1);
    Result var10(src10);

    double num11(3);
    Result var11(num11);

    map1.insert({src10, var11});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map12;

    std::string src13("a", 1);
    Result var13(src13);

    std::map<std::string, Result> map14;

    std::string src15("b", 1);
    Result var15(src15);

    double num16(1);
    Result var16(num16);

    map14.insert({src15, var16});

    std::string src17("c", 1);
    Result var17(src17);

    double num18(2);
    Result var18(num18);

    map14.insert({src17, var18});

    Result var14(map14);

    map12.insert({src13, var14});

    std::string src19("d", 1);
    Result var19(src19);

    double num20(4);
    Result var20(num20);

    map12.insert({src19, var20});

    std::string src21("e", 1);
    Result var21(src21);

    double num22(4);
    Result var22(num22);

    map12.insert({src21, var22});

    Result var12(map12);

    arr0.insert(arr0.end(), var12);

    Result var0(arr0);
  }

  SECTION("test38") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("b", 1);
    Result var4(src4);

    double num5(2);
    Result var5(num5);

    map3.insert({src4, var5});

    std::string src6("c", 1);
    Result var6(src6);

    double num7(2);
    Result var7(num7);

    map3.insert({src6, var7});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src8("d", 1);
    Result var8(src8);

    double num9(3);
    Result var9(num9);

    map1.insert({src8, var9});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map10;

    std::string src11("a", 1);
    Result var11(src11);

    std::map<std::string, Result> map12;

    std::string src13("b", 1);
    Result var13(src13);

    double num14(2);
    Result var14(num14);

    map12.insert({src13, var14});

    std::string src15("c", 1);
    Result var15(src15);

    double num16(2);
    Result var16(num16);

    map12.insert({src15, var16});

    Result var12(map12);

    map10.insert({src11, var12});

    std::string src17("d", 1);
    Result var17(src17);

    double num18(4);
    Result var18(num18);

    map10.insert({src17, var18});

    Result var10(map10);

    arr0.insert(arr0.end(), var10);

    Result var0(arr0);
  }

  SECTION("test39") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("b", 1);
    Result var4(src4);

    double num5(2);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    std::string src6("d", 1);
    Result var6(src6);

    double num7(3);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("a", 1);
    Result var9(src9);

    std::map<std::string, Result> map10;

    std::string src11("b", 1);
    Result var11(src11);

    double num12(2);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    map8.insert({src9, var10});

    std::string src13("d", 1);
    Result var13(src13);

    double num14(4);
    Result var14(num14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test40") {
    std::vector<Result> arr0(5);

    std::string src1("a", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("b", 1);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("c", 1);
    Result var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("d", 1);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("e", 1);
    Result var5(src5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }
}
