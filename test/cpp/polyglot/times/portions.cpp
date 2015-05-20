// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp accessing portions", "[cpp][ast]") {

  SECTION("test10") {
    Types::array arr0(4);

    double num1(1375142400);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1375142400);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(1375142400);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(2375136000);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test11") {
    Types::array arr0(4);

    double num1(0);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(0);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(0);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(0);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test12") {
    Types::array arr0(4);

    double num1(4896.681);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(4896.682);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4897.681);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(11296.681);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test13") {
    Types::array arr0(4);

    Types::array arr1(6);

    double num2(2013);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(7);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    double num4(30);
    Query var4(num4);

    arr1.insert(arr1.end(), var4);

    double num5(1);
    Query var5(num5);

    arr1.insert(arr1.end(), var5);

    double num6(21);
    Query var6(num6);

    arr1.insert(arr1.end(), var6);

    double num7(36.681);
    Query var7(num7);

    arr1.insert(arr1.end(), var7);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Types::array arr8(6);

    double num9(2013);
    Query var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(7);
    Query var10(num10);

    arr8.insert(arr8.end(), var10);

    double num11(30);
    Query var11(num11);

    arr8.insert(arr8.end(), var11);

    double num12(1);
    Query var12(num12);

    arr8.insert(arr8.end(), var12);

    double num13(21);
    Query var13(num13);

    arr8.insert(arr8.end(), var13);

    double num14(36.682);
    Query var14(num14);

    arr8.insert(arr8.end(), var14);

    Query var8(arr8);

    arr0.insert(arr0.end(), var8);

    Types::array arr15(6);

    double num16(2013);
    Query var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(7);
    Query var17(num17);

    arr15.insert(arr15.end(), var17);

    double num18(30);
    Query var18(num18);

    arr15.insert(arr15.end(), var18);

    double num19(1);
    Query var19(num19);

    arr15.insert(arr15.end(), var19);

    double num20(21);
    Query var20(num20);

    arr15.insert(arr15.end(), var20);

    double num21(37.681);
    Query var21(num21);

    arr15.insert(arr15.end(), var21);

    Query var15(arr15);

    arr0.insert(arr0.end(), var15);

    Types::array arr22(6);

    double num23(2045);
    Query var23(num23);

    arr22.insert(arr22.end(), var23);

    double num24(4);
    Query var24(num24);

    arr22.insert(arr22.end(), var24);

    double num25(7);
    Query var25(num25);

    arr22.insert(arr22.end(), var25);

    double num26(3);
    Query var26(num26);

    arr22.insert(arr22.end(), var26);

    double num27(8);
    Query var27(num27);

    arr22.insert(arr22.end(), var27);

    double num28(16.681);
    Query var28(num28);

    arr22.insert(arr22.end(), var28);

    Query var22(arr22);

    arr0.insert(arr0.end(), var22);

    Query var0(arr0);
  }

  SECTION("test14") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("rts", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test15") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test16") {
    Types::array arr0(4);

    Types::array arr1(2);

    double num2(2);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(211);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    Types::array arr4(2);

    double num5(2);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(211);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    Types::array arr7(2);

    double num8(2);
    Query var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(211);
    Query var9(num9);

    arr7.insert(arr7.end(), var9);

    Query var7(arr7);

    arr0.insert(arr0.end(), var7);

    Types::array arr10(2);

    double num11(5);
    Query var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(97);
    Query var12(num12);

    arr10.insert(arr10.end(), var12);

    Query var10(arr10);

    arr0.insert(arr0.end(), var10);

    Query var0(arr0);
  }
}
