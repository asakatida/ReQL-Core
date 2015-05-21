// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests manipulation operations on arrays", "[cpp][ast]") {

  SECTION("test4") {
    Types::array arr0(4);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test5") {
    Types::array arr0(4);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    std::string src4("a", 1);
    Query var4(src4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test6") {
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

  SECTION("test7") {
    Types::array arr0(4);

    std::string src1("a", 1);
    Query var1(src1);

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

  SECTION("test8") {
    Types::array arr0(1);

    double num1(3);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test9") {
    Types::array arr0(3);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test10") {
    Types::array arr0(3);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test11") {
    Types::array arr0(3);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test12") {
    Types::array arr0(4);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test13") {
    Types::array arr0(5);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(5);
    Query var5(num5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test14") {
    Types::array arr0(5);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(5);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(6);
    Query var5(num5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test15") {
    Types::array arr0(2);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test16") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test17") {
    Types::array arr0(2);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test18") {
    Types::array arr0(2);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test19") {
    Types::array arr0(2);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test20") {
    Types::array arr0(2);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test21") {
    Types::array arr0(2);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test22") {
    Types::array arr0(1);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test23") {
    Types::array arr0(2);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test24") {
    Types::array arr0(1);

    double num1(3);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test25") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test26") {
    Types::array arr0(2);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test27") {
    Types::array arr0;
    Query var0(arr0);
  }

  SECTION("test28") {
    Types::array arr0(3);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test29") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    std::string src5("a", 1);
    Query var5(src5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    double num8(2);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Query var9(src9);

    std::string src10("b", 1);
    Query var10(src10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("a", 1);
    Query var12(src12);

    double num13(3);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Query var14(src14);

    std::string src15("c", 1);
    Query var15(src15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Query var0(arr0);
  }

  SECTION("test30") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("a", 1);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map7;

    std::string src8("a", 1);
    Query var8(src8);

    double num9(3);
    Query var9(num9);

    map7.insert({src8, var9});

    Query var7(map7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test31") {
    Types::array arr0(3);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;
    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map3;
    Query var3(map3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test33") {
    Types::array arr0(6);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("a", 1);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map7;

    std::string src8("a", 1);
    Query var8(src8);

    double num9(3);
    Query var9(num9);

    map7.insert({src8, var9});

    Query var7(map7);

    arr0.insert(arr0.end(), var7);

    Types::object map10;

    std::string src11("a", 1);
    Query var11(src11);

    double num12(1);
    Query var12(num12);

    map10.insert({src11, var12});

    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Types::object map13;

    std::string src14("a", 1);
    Query var14(src14);

    double num15(2);
    Query var15(num15);

    map13.insert({src14, var15});

    Query var13(map13);

    arr0.insert(arr0.end(), var13);

    Types::object map16;

    std::string src17("a", 1);
    Query var17(src17);

    double num18(3);
    Query var18(num18);

    map16.insert({src17, var18});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test34") {
    Types::array arr0(6);

    Types::object map1;

    std::string src2("b", 1);
    Query var2(src2);

    std::string src3("a", 1);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("b", 1);
    Query var5(src5);

    std::string src6("b", 1);
    Query var6(src6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map7;

    std::string src8("b", 1);
    Query var8(src8);

    std::string src9("c", 1);
    Query var9(src9);

    map7.insert({src8, var9});

    Query var7(map7);

    arr0.insert(arr0.end(), var7);

    Types::object map10;

    std::string src11("b", 1);
    Query var11(src11);

    std::string src12("a", 1);
    Query var12(src12);

    map10.insert({src11, var12});

    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Types::object map13;

    std::string src14("b", 1);
    Query var14(src14);

    std::string src15("b", 1);
    Query var15(src15);

    map13.insert({src14, var15});

    Query var13(map13);

    arr0.insert(arr0.end(), var13);

    Types::object map16;

    std::string src17("b", 1);
    Query var17(src17);

    std::string src18("c", 1);
    Query var18(src18);

    map16.insert({src17, var18});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test35") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    std::string src5("a", 1);
    Query var5(src5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    double num8(2);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Query var9(src9);

    std::string src10("b", 1);
    Query var10(src10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("a", 1);
    Query var12(src12);

    double num13(3);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Query var14(src14);

    std::string src15("c", 1);
    Query var15(src15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Query var0(arr0);
  }

  SECTION("test36") {
    Types::array arr0(10);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;
    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map3;
    Query var3(map3);

    arr0.insert(arr0.end(), var3);

    Types::object map4;
    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map5;
    Query var5(map5);

    arr0.insert(arr0.end(), var5);

    Types::object map6;
    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map7;
    Query var7(map7);

    arr0.insert(arr0.end(), var7);

    Types::object map8;
    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Types::object map9;
    Query var9(map9);

    arr0.insert(arr0.end(), var9);

    Types::object map10;
    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Query var0(arr0);
  }

  SECTION("test38") {
    Types::array arr0(6);

    Types::object map1;

    std::string src2("b", 1);
    Query var2(src2);

    Types::object map3;

    std::string src4("c", 1);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map3.insert({src4, var5});

    Query var3(map3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("b", 1);
    Query var7(src7);

    Types::object map8;

    std::string src9("c", 1);
    Query var9(src9);

    double num10(2);
    Query var10(num10);

    map8.insert({src9, var10});

    Query var8(map8);

    map6.insert({src7, var8});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("b", 1);
    Query var12(src12);

    Types::object map13;

    std::string src14("c", 1);
    Query var14(src14);

    double num15(3);
    Query var15(num15);

    map13.insert({src14, var15});

    Query var13(map13);

    map11.insert({src12, var13});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Types::object map16;

    std::string src17("b", 1);
    Query var17(src17);

    Types::object map18;

    std::string src19("c", 1);
    Query var19(src19);

    double num20(1);
    Query var20(num20);

    map18.insert({src19, var20});

    Query var18(map18);

    map16.insert({src17, var18});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Types::object map21;

    std::string src22("b", 1);
    Query var22(src22);

    Types::object map23;

    std::string src24("c", 1);
    Query var24(src24);

    double num25(2);
    Query var25(num25);

    map23.insert({src24, var25});

    Query var23(map23);

    map21.insert({src22, var23});

    Query var21(map21);

    arr0.insert(arr0.end(), var21);

    Types::object map26;

    std::string src27("b", 1);
    Query var27(src27);

    Types::object map28;

    std::string src29("c", 1);
    Query var29(src29);

    double num30(3);
    Query var30(num30);

    map28.insert({src29, var30});

    Query var28(map28);

    map26.insert({src27, var28});

    Query var26(map26);

    arr0.insert(arr0.end(), var26);

    Query var0(arr0);
  }

  SECTION("test39") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test40") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test41") {
    Types::array arr0(3);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;
    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map3;
    Query var3(map3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test42") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("b", 1);
    Query var2(src2);

    std::string src3("a", 1);
    Query var3(src3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("b", 1);
    Query var5(src5);

    std::string src6("b", 1);
    Query var6(src6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map7;

    std::string src8("b", 1);
    Query var8(src8);

    std::string src9("c", 1);
    Query var9(src9);

    map7.insert({src8, var9});

    Query var7(map7);

    arr0.insert(arr0.end(), var7);

    Query var0(arr0);
  }

  SECTION("test43") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    std::string src5("a", 1);
    Query var5(src5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    double num8(2);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Query var9(src9);

    std::string src10("b", 1);
    Query var10(src10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("a", 1);
    Query var12(src12);

    double num13(3);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Query var14(src14);

    std::string src15("c", 1);
    Query var15(src15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Query var0(arr0);
  }

  SECTION("test44") {
    Types::array arr0(3);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test45") {
    double num0(6);
    Query var0(num0);
  }

  SECTION("test46") {
    double num0(6);
    Query var0(num0);
  }

  SECTION("test47") {
    double num0(12);
    Query var0(num0);
  }

  SECTION("test48") {
    double num0(12);
    Query var0(num0);
  }

  SECTION("test49") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(2);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    std::string src5("b", 1);
    Query var5(src5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test50") {
    Types::array arr0(6);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(1);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(2);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(1);
    Query var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(2);
    Query var6(num6);

    arr0.insert(arr0.end(), var6);

    Query var0(arr0);
  }

  SECTION("test51") {
    Types::array arr0(6);

    Types::object map1;

    std::string src2("v", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("v2", 2);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map7;

    std::string src8("v", 1);
    Query var8(src8);

    double num9(2);
    Query var9(num9);

    map7.insert({src8, var9});

    Query var7(map7);

    arr0.insert(arr0.end(), var7);

    Types::object map10;

    std::string src11("v2", 2);
    Query var11(src11);

    double num12(3);
    Query var12(num12);

    map10.insert({src11, var12});

    Query var10(map10);

    arr0.insert(arr0.end(), var10);

    Types::object map13;

    std::string src14("v", 1);
    Query var14(src14);

    double num15(3);
    Query var15(num15);

    map13.insert({src14, var15});

    Query var13(map13);

    arr0.insert(arr0.end(), var13);

    Types::object map16;

    std::string src17("v2", 2);
    Query var17(src17);

    double num18(4);
    Query var18(num18);

    map16.insert({src17, var18});

    Query var16(map16);

    arr0.insert(arr0.end(), var16);

    Query var0(arr0);
  }

  SECTION("test52") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    std::string src5("a", 1);
    Query var5(src5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    double num8(2);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Query var9(src9);

    std::string src10("b", 1);
    Query var10(src10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("a", 1);
    Query var12(src12);

    double num13(3);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Query var14(src14);

    std::string src15("c", 1);
    Query var15(src15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Query var0(arr0);
  }

  SECTION("test53") {
    Types::array arr0(3);

    Types::object map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(3);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    std::string src5("c", 1);
    Query var5(src5);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map6;

    std::string src7("a", 1);
    Query var7(src7);

    double num8(2);
    Query var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Query var9(src9);

    std::string src10("b", 1);
    Query var10(src10);

    map6.insert({src9, var10});

    Query var6(map6);

    arr0.insert(arr0.end(), var6);

    Types::object map11;

    std::string src12("a", 1);
    Query var12(src12);

    double num13(1);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Query var14(src14);

    std::string src15("a", 1);
    Query var15(src15);

    map11.insert({src14, var15});

    Query var11(map11);

    arr0.insert(arr0.end(), var11);

    Query var0(arr0);
  }

  SECTION("test54") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("-a", 2);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("-a", 2);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test55") {
    Types::array arr0(4);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test56") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test57") {
    Types::array arr0(6);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Types::object map4;

    std::string src5("a", 1);
    Query var5(src5);

    double num6(1);
    Query var6(num6);

    map4.insert({src5, var6});

    std::string src7("b", 1);
    Query var7(src7);

    std::string src8("a", 1);
    Query var8(src8);

    map4.insert({src7, var8});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Types::object map9;

    std::string src10("a", 1);
    Query var10(src10);

    double num11(2);
    Query var11(num11);

    map9.insert({src10, var11});

    std::string src12("b", 1);
    Query var12(src12);

    std::string src13("b", 1);
    Query var13(src13);

    map9.insert({src12, var13});

    Query var9(map9);

    arr0.insert(arr0.end(), var9);

    Types::object map14;

    std::string src15("a", 1);
    Query var15(src15);

    double num16(3);
    Query var16(num16);

    map14.insert({src15, var16});

    std::string src17("b", 1);
    Query var17(src17);

    std::string src18("c", 1);
    Query var18(src18);

    map14.insert({src17, var18});

    Query var14(map14);

    arr0.insert(arr0.end(), var14);

    Query var0(arr0);
  }

  SECTION("test58") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test59") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test60") {
    Query var0(true);
  }

  SECTION("test61") {
    Query var0(false);
  }

  SECTION("test62") {
    Query var0(true);
  }

  SECTION("test63") {
    Query var0(true);
  }

  SECTION("test64") {
    Query var0(false);
  }

  SECTION("test65") {
    Query var0(false);
  }

  SECTION("test66") {
    Query var0(false);
  }

  SECTION("test67") {
    Query var0(true);
  }

  SECTION("test68") {
    Query var0(true);
  }

  SECTION("test69") {
    Query var0(true);
  }

  SECTION("test70") {
    Query var0(false);
  }

  SECTION("test71") {
    Query var0(false);
  }

  SECTION("test72") {
    Query var0(false);
  }

  SECTION("test73") {
    Query var0(true);
  }

  SECTION("test74") {
    Types::array arr0(2);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test75") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
