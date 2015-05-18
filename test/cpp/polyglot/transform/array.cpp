// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests manipulation operations on arrays", "[cpp][ast]") {

  SECTION("test4") {
    std::vector<Result> arr0(4);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test5") {
    std::vector<Result> arr0(4);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    std::string src4("a", 1);
    Result var4(src4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test6") {
    std::vector<Result> arr0(4);

    double num1(0);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(2);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(3);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test7") {
    std::vector<Result> arr0(4);

    std::string src1("a", 1);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(2);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(3);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test8") {
    std::vector<Result> arr0(1);

    double num1(3);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test9") {
    std::vector<Result> arr0(3);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test10") {
    std::vector<Result> arr0(3);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test11") {
    std::vector<Result> arr0(3);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test12") {
    std::vector<Result> arr0(4);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test13") {
    std::vector<Result> arr0(5);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(5);
    Result var5(num5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test14") {
    std::vector<Result> arr0(5);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(5);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(6);
    Result var5(num5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test15") {
    std::vector<Result> arr0(2);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test16") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test17") {
    std::vector<Result> arr0(2);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test18") {
    std::vector<Result> arr0(2);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test19") {
    std::vector<Result> arr0(2);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test20") {
    std::vector<Result> arr0(2);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test21") {
    std::vector<Result> arr0(2);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test22") {
    std::vector<Result> arr0(1);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test23") {
    std::vector<Result> arr0(2);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test24") {
    std::vector<Result> arr0(1);

    double num1(3);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test25") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test26") {
    std::vector<Result> arr0(2);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test27") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test28") {
    std::vector<Result> arr0(3);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test29") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    std::string src5("a", 1);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Result var9(src9);

    std::string src10("b", 1);
    Result var10(src10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("a", 1);
    Result var12(src12);

    double num13(3);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Result var14(src14);

    std::string src15("c", 1);
    Result var15(src15);

    map11.insert({src14, var15});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    Result var0(arr0);
  }

  SECTION("test30") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("a", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map7;

    std::string src8("a", 1);
    Result var8(src8);

    double num9(3);
    Result var9(num9);

    map7.insert({src8, var9});

    Result var7(map7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test31") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;
    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map3;
    Result var3(map3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test33") {
    std::vector<Result> arr0(6);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("a", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map7;

    std::string src8("a", 1);
    Result var8(src8);

    double num9(3);
    Result var9(num9);

    map7.insert({src8, var9});

    Result var7(map7);

    arr0.insert(arr0.end(), var7);

    std::map<std::string, Result> map10;

    std::string src11("a", 1);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    arr0.insert(arr0.end(), var10);

    std::map<std::string, Result> map13;

    std::string src14("a", 1);
    Result var14(src14);

    double num15(2);
    Result var15(num15);

    map13.insert({src14, var15});

    Result var13(map13);

    arr0.insert(arr0.end(), var13);

    std::map<std::string, Result> map16;

    std::string src17("a", 1);
    Result var17(src17);

    double num18(3);
    Result var18(num18);

    map16.insert({src17, var18});

    Result var16(map16);

    arr0.insert(arr0.end(), var16);

    Result var0(arr0);
  }

  SECTION("test34") {
    std::vector<Result> arr0(6);

    std::map<std::string, Result> map1;

    std::string src2("b", 1);
    Result var2(src2);

    std::string src3("a", 1);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("b", 1);
    Result var5(src5);

    std::string src6("b", 1);
    Result var6(src6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map7;

    std::string src8("b", 1);
    Result var8(src8);

    std::string src9("c", 1);
    Result var9(src9);

    map7.insert({src8, var9});

    Result var7(map7);

    arr0.insert(arr0.end(), var7);

    std::map<std::string, Result> map10;

    std::string src11("b", 1);
    Result var11(src11);

    std::string src12("a", 1);
    Result var12(src12);

    map10.insert({src11, var12});

    Result var10(map10);

    arr0.insert(arr0.end(), var10);

    std::map<std::string, Result> map13;

    std::string src14("b", 1);
    Result var14(src14);

    std::string src15("b", 1);
    Result var15(src15);

    map13.insert({src14, var15});

    Result var13(map13);

    arr0.insert(arr0.end(), var13);

    std::map<std::string, Result> map16;

    std::string src17("b", 1);
    Result var17(src17);

    std::string src18("c", 1);
    Result var18(src18);

    map16.insert({src17, var18});

    Result var16(map16);

    arr0.insert(arr0.end(), var16);

    Result var0(arr0);
  }

  SECTION("test35") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    std::string src5("a", 1);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Result var9(src9);

    std::string src10("b", 1);
    Result var10(src10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("a", 1);
    Result var12(src12);

    double num13(3);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Result var14(src14);

    std::string src15("c", 1);
    Result var15(src15);

    map11.insert({src14, var15});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    Result var0(arr0);
  }

  SECTION("test36") {
    std::vector<Result> arr0(10);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;
    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map3;
    Result var3(map3);

    arr0.insert(arr0.end(), var3);

    std::map<std::string, Result> map4;
    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map5;
    Result var5(map5);

    arr0.insert(arr0.end(), var5);

    std::map<std::string, Result> map6;
    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map7;
    Result var7(map7);

    arr0.insert(arr0.end(), var7);

    std::map<std::string, Result> map8;
    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    std::map<std::string, Result> map9;
    Result var9(map9);

    arr0.insert(arr0.end(), var9);

    std::map<std::string, Result> map10;
    Result var10(map10);

    arr0.insert(arr0.end(), var10);

    Result var0(arr0);
  }

  SECTION("test38") {
    std::vector<Result> arr0(6);

    std::map<std::string, Result> map1;

    std::string src2("b", 1);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("c", 1);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("b", 1);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("c", 1);
    Result var9(src9);

    double num10(2);
    Result var10(num10);

    map8.insert({src9, var10});

    Result var8(map8);

    map6.insert({src7, var8});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("b", 1);
    Result var12(src12);

    std::map<std::string, Result> map13;

    std::string src14("c", 1);
    Result var14(src14);

    double num15(3);
    Result var15(num15);

    map13.insert({src14, var15});

    Result var13(map13);

    map11.insert({src12, var13});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    std::map<std::string, Result> map16;

    std::string src17("b", 1);
    Result var17(src17);

    std::map<std::string, Result> map18;

    std::string src19("c", 1);
    Result var19(src19);

    double num20(1);
    Result var20(num20);

    map18.insert({src19, var20});

    Result var18(map18);

    map16.insert({src17, var18});

    Result var16(map16);

    arr0.insert(arr0.end(), var16);

    std::map<std::string, Result> map21;

    std::string src22("b", 1);
    Result var22(src22);

    std::map<std::string, Result> map23;

    std::string src24("c", 1);
    Result var24(src24);

    double num25(2);
    Result var25(num25);

    map23.insert({src24, var25});

    Result var23(map23);

    map21.insert({src22, var23});

    Result var21(map21);

    arr0.insert(arr0.end(), var21);

    std::map<std::string, Result> map26;

    std::string src27("b", 1);
    Result var27(src27);

    std::map<std::string, Result> map28;

    std::string src29("c", 1);
    Result var29(src29);

    double num30(3);
    Result var30(num30);

    map28.insert({src29, var30});

    Result var28(map28);

    map26.insert({src27, var28});

    Result var26(map26);

    arr0.insert(arr0.end(), var26);

    Result var0(arr0);
  }

  SECTION("test39") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test40") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test41") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;
    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map3;
    Result var3(map3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test42") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("b", 1);
    Result var2(src2);

    std::string src3("a", 1);
    Result var3(src3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("b", 1);
    Result var5(src5);

    std::string src6("b", 1);
    Result var6(src6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map7;

    std::string src8("b", 1);
    Result var8(src8);

    std::string src9("c", 1);
    Result var9(src9);

    map7.insert({src8, var9});

    Result var7(map7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test43") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    std::string src5("a", 1);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Result var9(src9);

    std::string src10("b", 1);
    Result var10(src10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("a", 1);
    Result var12(src12);

    double num13(3);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Result var14(src14);

    std::string src15("c", 1);
    Result var15(src15);

    map11.insert({src14, var15});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    Result var0(arr0);
  }

  SECTION("test44") {
    std::vector<Result> arr0(3);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test45") {
    double num0(6);
    Result var0(num0);
  }

  SECTION("test46") {
    double num0(6);
    Result var0(num0);
  }

  SECTION("test47") {
    double num0(12);
    Result var0(num0);
  }

  SECTION("test48") {
    double num0(12);
    Result var0(num0);
  }

  SECTION("test49") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(2);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    std::string src5("b", 1);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test50") {
    std::vector<Result> arr0(6);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(1);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(2);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(1);
    Result var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(2);
    Result var6(num6);

    arr0.insert(arr0.end(), var6);

    Result var0(arr0);
  }

  SECTION("test51") {
    std::vector<Result> arr0(6);

    std::map<std::string, Result> map1;

    std::string src2("v", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("v2", 2);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map7;

    std::string src8("v", 1);
    Result var8(src8);

    double num9(2);
    Result var9(num9);

    map7.insert({src8, var9});

    Result var7(map7);

    arr0.insert(arr0.end(), var7);

    std::map<std::string, Result> map10;

    std::string src11("v2", 2);
    Result var11(src11);

    double num12(3);
    Result var12(num12);

    map10.insert({src11, var12});

    Result var10(map10);

    arr0.insert(arr0.end(), var10);

    std::map<std::string, Result> map13;

    std::string src14("v", 1);
    Result var14(src14);

    double num15(3);
    Result var15(num15);

    map13.insert({src14, var15});

    Result var13(map13);

    arr0.insert(arr0.end(), var13);

    std::map<std::string, Result> map16;

    std::string src17("v2", 2);
    Result var17(src17);

    double num18(4);
    Result var18(num18);

    map16.insert({src17, var18});

    Result var16(map16);

    arr0.insert(arr0.end(), var16);

    Result var0(arr0);
  }

  SECTION("test52") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    std::string src5("a", 1);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Result var9(src9);

    std::string src10("b", 1);
    Result var10(src10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("a", 1);
    Result var12(src12);

    double num13(3);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Result var14(src14);

    std::string src15("c", 1);
    Result var15(src15);

    map11.insert({src14, var15});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    Result var0(arr0);
  }

  SECTION("test53") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(3);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    std::string src5("c", 1);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("a", 1);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map6.insert({src7, var8});

    std::string src9("b", 1);
    Result var9(src9);

    std::string src10("b", 1);
    Result var10(src10);

    map6.insert({src9, var10});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("a", 1);
    Result var12(src12);

    double num13(1);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("b", 1);
    Result var14(src14);

    std::string src15("a", 1);
    Result var15(src15);

    map11.insert({src14, var15});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    Result var0(arr0);
  }

  SECTION("test54") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("-a", 2);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("-a", 2);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test55") {
    std::vector<Result> arr0(4);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test56") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test57") {
    std::vector<Result> arr0(6);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    std::map<std::string, Result> map4;

    std::string src5("a", 1);
    Result var5(src5);

    double num6(1);
    Result var6(num6);

    map4.insert({src5, var6});

    std::string src7("b", 1);
    Result var7(src7);

    std::string src8("a", 1);
    Result var8(src8);

    map4.insert({src7, var8});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    std::map<std::string, Result> map9;

    std::string src10("a", 1);
    Result var10(src10);

    double num11(2);
    Result var11(num11);

    map9.insert({src10, var11});

    std::string src12("b", 1);
    Result var12(src12);

    std::string src13("b", 1);
    Result var13(src13);

    map9.insert({src12, var13});

    Result var9(map9);

    arr0.insert(arr0.end(), var9);

    std::map<std::string, Result> map14;

    std::string src15("a", 1);
    Result var15(src15);

    double num16(3);
    Result var16(num16);

    map14.insert({src15, var16});

    std::string src17("b", 1);
    Result var17(src17);

    std::string src18("c", 1);
    Result var18(src18);

    map14.insert({src17, var18});

    Result var14(map14);

    arr0.insert(arr0.end(), var14);

    Result var0(arr0);
  }

  SECTION("test58") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test59") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test60") {
    Result var0(true);
  }

  SECTION("test61") {
    Result var0(false);
  }

  SECTION("test62") {
    Result var0(true);
  }

  SECTION("test63") {
    Result var0(true);
  }

  SECTION("test64") {
    Result var0(false);
  }

  SECTION("test65") {
    Result var0(false);
  }

  SECTION("test66") {
    Result var0(false);
  }

  SECTION("test67") {
    Result var0(true);
  }

  SECTION("test68") {
    Result var0(true);
  }

  SECTION("test69") {
    Result var0(true);
  }

  SECTION("test70") {
    Result var0(false);
  }

  SECTION("test71") {
    Result var0(false);
  }

  SECTION("test72") {
    Result var0(false);
  }

  SECTION("test73") {
    Result var0(true);
  }

  SECTION("test74") {
    std::vector<Result> arr0(2);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test75") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
