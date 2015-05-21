// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests manipulation operations on objects", "[cpp][ast]") {

  SECTION("test1") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test2") {
    std::string src0("str", 3);
    Query var0(src0);
  }

  SECTION("test3") {
    Query var0(true);
  }

  SECTION("test4") {
    Query var0(true);
  }

  SECTION("test5") {
    Query var0(false);
  }

  SECTION("test6") {
    Query var0(true);
  }

  SECTION("test7") {
    Query var0(false);
  }

  SECTION("test8") {
    Query var0(false);
  }

  SECTION("test9") {
    Query var0(true);
  }

  SECTION("test10") {
    Query var0(false);
  }

  SECTION("test11") {
    Query var0(false);
  }

  SECTION("test12") {
    Query var0(true);
  }

  SECTION("test13") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test14") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test15") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test16") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test17") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test18") {
    Types::object map0;

    std::string src1("b", 1);
    Query var1(src1);

    double num2(2);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("c", 1);
    Query var3(src3);

    std::string src4("str", 3);
    Query var4(src4);

    map0.insert({src3, var4});

    std::string src5("d", 1);
    Query var5(src5);

    Query var6;

    map0.insert({src5, var6});

    std::string src7("e", 1);
    Query var7(src7);

    Types::object map8;

    std::string src9("f", 1);
    Query var9(src9);

    std::string src10("buzz", 4);
    Query var10(src10);

    map8.insert({src9, var10});

    Query var8(map8);

    map0.insert({src7, var8});

    Query var0(map0);
  }

  SECTION("test19") {
    Types::object map0;

    std::string src1("c", 1);
    Query var1(src1);

    std::string src2("str", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    std::string src3("d", 1);
    Query var3(src3);

    Query var4;

    map0.insert({src3, var4});

    std::string src5("e", 1);
    Query var5(src5);

    Types::object map6;

    std::string src7("f", 1);
    Query var7(src7);

    std::string src8("buzz", 4);
    Query var8(src8);

    map6.insert({src7, var8});

    Query var6(map6);

    map0.insert({src5, var6});

    Query var0(map0);
  }

  SECTION("test20") {
    Types::object map0;

    std::string src1("e", 1);
    Query var1(src1);

    Types::object map2;

    std::string src3("f", 1);
    Query var3(src3);

    std::string src4("buzz", 4);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test21") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    std::string src6("str", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("d", 1);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    std::string src9("e", 1);
    Query var9(src9);

    Types::object map10;
    Query var10(map10);

    map0.insert({src9, var10});

    Query var0(map0);
  }

  SECTION("test22") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    std::string src6("str", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("d", 1);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    std::string src9("e", 1);
    Query var9(src9);

    Types::object map10;

    std::string src11("f", 1);
    Query var11(src11);

    std::string src12("buzz", 4);
    Query var12(src12);

    map10.insert({src11, var12});

    Query var10(map10);

    map0.insert({src9, var10});

    Query var0(map0);
  }

  SECTION("test23") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test24") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    std::string src6("str", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("d", 1);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    std::string src9("e", 1);
    Query var9(src9);

    double num10(-2);
    Query var10(num10);

    map0.insert({src9, var10});

    Query var0(map0);
  }

  SECTION("test25") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    std::string src6("str", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("d", 1);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    Query var0(map0);
  }

  SECTION("test26") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    std::string src6("str", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("d", 1);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    std::string src9("e", 1);
    Query var9(src9);

    Types::object map10;

    std::string src11("f", 1);
    Query var11(src11);

    std::string src12("quux", 4);
    Query var12(src12);

    map10.insert({src11, var12});

    Query var10(map10);

    map0.insert({src9, var10});

    Query var0(map0);
  }

  SECTION("test27") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    std::string src6("str", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("d", 1);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    std::string src9("e", 1);
    Query var9(src9);

    Types::object map10;

    std::string src11("f", 1);
    Query var11(src11);

    std::string src12("buzz", 4);
    Query var12(src12);

    map10.insert({src11, var12});

    std::string src13("g", 1);
    Query var13(src13);

    std::string src14("quux", 4);
    Query var14(src14);

    map10.insert({src13, var14});

    Query var10(map10);

    map0.insert({src9, var10});

    Query var0(map0);
  }

  SECTION("test28") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    std::string src6("str", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("d", 1);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    std::string src9("e", 1);
    Query var9(src9);

    Types::object map10;

    std::string src11("g", 1);
    Query var11(src11);

    std::string src12("quux", 4);
    Query var12(src12);

    map10.insert({src11, var12});

    Query var10(map10);

    map0.insert({src9, var10});

    Query var0(map0);
  }

  SECTION("test29") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(-1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    std::string src6("str", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("d", 1);
    Query var7(src7);

    Query var8;

    map0.insert({src7, var8});

    std::string src9("e", 1);
    Query var9(src9);

    Types::object map10;

    std::string src11("f", 1);
    Query var11(src11);

    std::string src12("buzz", 4);
    Query var12(src12);

    map10.insert({src11, var12});

    Query var10(map10);

    map0.insert({src9, var10});

    Query var0(map0);
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

    std::string src2("err", 3);
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

  SECTION("test35") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    Types::object map2;

    std::string src3("b", 1);
    Query var3(src3);

    double num4(1);
    Query var4(num4);

    map2.insert({src3, var4});

    std::string src5("c", 1);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map2.insert({src5, var6});

    Query var2(map2);

    map0.insert({src1, var2});

    std::string src7("d", 1);
    Query var7(src7);

    double num8(3);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("e", 1);
    Query var9(src9);

    double num10(4);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("f", 1);
    Query var11(src11);

    double num12(5);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test36") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    Types::object map3;

    std::string src4("b", 1);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("c", 1);
    Query var6(src6);

    double num7(2);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("d", 1);
    Query var8(src8);

    double num9(3);
    Query var9(num9);

    map1.insert({src8, var9});

    std::string src10("e", 1);
    Query var10(src10);

    double num11(3);
    Query var11(num11);

    map1.insert({src10, var11});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map12;

    std::string src13("a", 1);
    Query var13(src13);

    Types::object map14;

    std::string src15("b", 1);
    Query var15(src15);

    double num16(1);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("c", 1);
    Query var17(src17);

    double num18(2);
    Query var18(num18);

    map14.insert({src17, var18});

    Query var14(map14);

    map12.insert({src13, var14});

    std::string src19("d", 1);
    Query var19(src19);

    double num20(4);
    Query var20(num20);

    map12.insert({src19, var20});

    std::string src21("e", 1);
    Query var21(src21);

    double num22(4);
    Query var22(num22);

    map12.insert({src21, var22});

    Query var12(map12);

    arr0.insert(arr0.end(), var12);

    Query var0(arr0);
  }

  SECTION("test37") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    Types::object map3;

    std::string src4("b", 1);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("c", 1);
    Query var6(src6);

    double num7(2);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("d", 1);
    Query var8(src8);

    double num9(3);
    Query var9(num9);

    map1.insert({src8, var9});

    std::string src10("e", 1);
    Query var10(src10);

    double num11(3);
    Query var11(num11);

    map1.insert({src10, var11});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map12;

    std::string src13("a", 1);
    Query var13(src13);

    Types::object map14;

    std::string src15("b", 1);
    Query var15(src15);

    double num16(1);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("c", 1);
    Query var17(src17);

    double num18(2);
    Query var18(num18);

    map14.insert({src17, var18});

    Query var14(map14);

    map12.insert({src13, var14});

    std::string src19("d", 1);
    Query var19(src19);

    double num20(4);
    Query var20(num20);

    map12.insert({src19, var20});

    std::string src21("e", 1);
    Query var21(src21);

    double num22(4);
    Query var22(num22);

    map12.insert({src21, var22});

    Query var12(map12);

    arr0.insert(arr0.end(), var12);

    Query var0(arr0);
  }

  SECTION("test38") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    Types::object map3;

    std::string src4("b", 1);
    Query var4(src4);

    double num5(2);
    Query var5(num5);

    map3.insert({src4, var5});

    std::string src6("c", 1);
    Query var6(src6);

    double num7(2);
    Query var7(num7);

    map3.insert({src6, var7});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src8("d", 1);
    Query var8(src8);

    double num9(3);
    Query var9(num9);

    map1.insert({src8, var9});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map10;

    std::string src11("a", 1);
    Query var11(src11);

    Types::object map12;

    std::string src13("b", 1);
    Query var13(src13);

    double num14(2);
    Query var14(num14);

    map12.insert({src13, var14});

    std::string src15("c", 1);
    Query var15(src15);

    double num16(2);
    Query var16(num16);

    map12.insert({src15, var16});

    Query var12(map12);

    map10.insert({src11, var12});

    std::string src17("d", 1);
    Query var17(src17);

    double num18(4);
    Query var18(num18);

    map10.insert({src17, var18});

    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Query var0(arr0);
  }

  SECTION("test39") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    Types::object map3;

    std::string src4("b", 1);
    Query var4(src4);

    double num5(2);
    Query var5(num5);

    map3.insert({src4, var5});

    Query var3(map3);

    map1.insert({src2, var3});

    std::string src6("d", 1);
    Query var6(src6);

    double num7(3);
    Query var7(num7);

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map8;

    std::string src9("a", 1);
    Query var9(src9);

    Types::object map10;

    std::string src11("b", 1);
    Query var11(src11);

    double num12(2);
    Query var12(num12);

    map10.insert({src11, var12});

    Query var10(map10);

    map8.insert({src9, var10});

    std::string src13("d", 1);
    Query var13(src13);

    double num14(4);
    Query var14(num14);

    map8.insert({src13, var14});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test40") {
    Types::array arr0(5);

    std::string src1("a", 1);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("b", 1);
    Query var2(src2);

    arr0.insert(arr0.end(), var2);

    std::string src3("c", 1);
    Query var3(src3);

    arr0.insert(arr0.end(), var3);

    std::string src4("d", 1);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    std::string src5("e", 1);
    Query var5(src5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }
}
