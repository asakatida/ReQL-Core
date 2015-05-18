// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp accessing portions", "[cpp][ast]") {

  SECTION("test10") {
    std::vector<Result> arr0(4);

    double num1(1375142400);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1375142400);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(1375142400);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(2375136000);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test11") {
    std::vector<Result> arr0(4);

    double num1(0);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(0);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(0);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(0);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test12") {
    std::vector<Result> arr0(4);

    double num1(4896.681);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(4896.682);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4897.681);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(11296.681);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test13") {
    std::vector<Result> arr0(4);

    std::vector<Result> arr1(6);

    double num2(2013);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(7);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    double num4(30);
    Result var4(num4);

    arr1.insert(arr1.end(), var4);

    double num5(1);
    Result var5(num5);

    arr1.insert(arr1.end(), var5);

    double num6(21);
    Result var6(num6);

    arr1.insert(arr1.end(), var6);

    double num7(36.681);
    Result var7(num7);

    arr1.insert(arr1.end(), var7);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr8(6);

    double num9(2013);
    Result var9(num9);

    arr8.insert(arr8.end(), var9);

    double num10(7);
    Result var10(num10);

    arr8.insert(arr8.end(), var10);

    double num11(30);
    Result var11(num11);

    arr8.insert(arr8.end(), var11);

    double num12(1);
    Result var12(num12);

    arr8.insert(arr8.end(), var12);

    double num13(21);
    Result var13(num13);

    arr8.insert(arr8.end(), var13);

    double num14(36.682);
    Result var14(num14);

    arr8.insert(arr8.end(), var14);

    Result var8(arr8);

    arr0.insert(arr0.end(), var8);

    std::vector<Result> arr15(6);

    double num16(2013);
    Result var16(num16);

    arr15.insert(arr15.end(), var16);

    double num17(7);
    Result var17(num17);

    arr15.insert(arr15.end(), var17);

    double num18(30);
    Result var18(num18);

    arr15.insert(arr15.end(), var18);

    double num19(1);
    Result var19(num19);

    arr15.insert(arr15.end(), var19);

    double num20(21);
    Result var20(num20);

    arr15.insert(arr15.end(), var20);

    double num21(37.681);
    Result var21(num21);

    arr15.insert(arr15.end(), var21);

    Result var15(arr15);

    arr0.insert(arr0.end(), var15);

    std::vector<Result> arr22(6);

    double num23(2045);
    Result var23(num23);

    arr22.insert(arr22.end(), var23);

    double num24(4);
    Result var24(num24);

    arr22.insert(arr22.end(), var24);

    double num25(7);
    Result var25(num25);

    arr22.insert(arr22.end(), var25);

    double num26(3);
    Result var26(num26);

    arr22.insert(arr22.end(), var26);

    double num27(8);
    Result var27(num27);

    arr22.insert(arr22.end(), var27);

    double num28(16.681);
    Result var28(num28);

    arr22.insert(arr22.end(), var28);

    Result var22(arr22);

    arr0.insert(arr0.end(), var22);

    Result var0(arr0);
  }

  SECTION("test14") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("rts", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test15") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test16") {
    std::vector<Result> arr0(4);

    std::vector<Result> arr1(2);

    double num2(2);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(211);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    double num5(2);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(211);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    std::vector<Result> arr7(2);

    double num8(2);
    Result var8(num8);

    arr7.insert(arr7.end(), var8);

    double num9(211);
    Result var9(num9);

    arr7.insert(arr7.end(), var9);

    Result var7(arr7);

    arr0.insert(arr0.end(), var7);

    std::vector<Result> arr10(2);

    double num11(5);
    Result var11(num11);

    arr10.insert(arr10.end(), var11);

    double num12(97);
    Result var12(num12);

    arr10.insert(arr10.end(), var12);

    Result var10(arr10);

    arr0.insert(arr0.end(), var10);

    Result var0(arr0);
  }
}
