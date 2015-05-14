// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests replacement of selections", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("changes", 7);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::map<std::string, Result> map3;

    std::string src4("old_val", 7);
    Result var4(src4);

    Result var5;

    map3.insert({src4, var5});

    std::string src6("new_val", 7);
    Result var6(src6);

    std::map<std::string, Result> map7;

    std::string src8("id", 2);
    Result var8(src8);

    double num9(0);
    Result var9(num9);

    map7.insert({src8, var9});

    Result var7(map7);

    map3.insert({src6, var7});

    Result var3(map3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("first_error", 11);
    Result var1(src1);

    std::string src2("Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}", 67);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("changes", 7);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::map<std::string, Result> map5;

    std::string src6("old_val", 7);
    Result var6(src6);

    std::map<std::string, Result> map7;

    std::string src8("id", 2);
    Result var8(src8);

    double num9(0);
    Result var9(num9);

    map7.insert({src8, var9});

    Result var7(map7);

    map5.insert({src6, var7});

    std::string src10("new_val", 7);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("id", 2);
    Result var12(src12);

    double num13(0);
    Result var13(num13);

    map11.insert({src12, var13});

    Result var11(map11);

    map5.insert({src10, var11});

    Result var5(map5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test3") {
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

    double num8(1);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("changes", 7);
    Result var11(src11);

    std::vector<Result> arr12(1);

    std::map<std::string, Result> map13;

    std::string src14("old_val", 7);
    Result var14(src14);

    Result var15;

    map13.insert({src14, var15});

    std::string src16("new_val", 7);
    Result var16(src16);

    std::map<std::string, Result> map17;

    std::string src18("id", 2);
    Result var18(src18);

    double num19(1);
    Result var19(num19);

    map17.insert({src18, var19});

    Result var17(map17);

    map13.insert({src16, var17});

    Result var13(map13);

    arr12.insert(arr12.end(), var13);

    Result var12(arr12);

    map0.insert({src11, var12});

    std::string src20("skipped", 7);
    Result var20(src20);

    double num21(0);
    Result var21(num21);

    map0.insert({src20, var21});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("first_error", 11);
    Result var1(src1);

    std::string src2("Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}", 67);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("changes", 7);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::map<std::string, Result> map5;

    std::string src6("old_val", 7);
    Result var6(src6);

    std::map<std::string, Result> map7;

    std::string src8("id", 2);
    Result var8(src8);

    double num9(0);
    Result var9(num9);

    map7.insert({src8, var9});

    Result var7(map7);

    map5.insert({src6, var7});

    std::string src10("new_val", 7);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("id", 2);
    Result var12(src12);

    double num13(0);
    Result var13(num13);

    map11.insert({src12, var13});

    Result var11(map11);

    map5.insert({src10, var11});

    Result var5(map5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("changes", 7);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::map<std::string, Result> map3;

    std::string src4("old_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(0);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map3.insert({src4, var5});

    std::string src8("new_val", 7);
    Result var8(src8);

    std::map<std::string, Result> map9;

    std::string src10("x", 1);
    Result var10(src10);

    double num11(1);
    Result var11(num11);

    map9.insert({src10, var11});

    std::string src12("id", 2);
    Result var12(src12);

    double num13(0);
    Result var13(num13);

    map9.insert({src12, var13});

    Result var9(map9);

    map3.insert({src8, var9});

    Result var3(map3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("first_error", 11);
    Result var1(src1);

    std::string src2("a", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("changes", 7);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::map<std::string, Result> map5;

    std::string src6("old_val", 7);
    Result var6(src6);

    std::map<std::string, Result> map7;

    std::string src8("x", 1);
    Result var8(src8);

    double num9(1);
    Result var9(num9);

    map7.insert({src8, var9});

    std::string src10("id", 2);
    Result var10(src10);

    double num11(0);
    Result var11(num11);

    map7.insert({src10, var11});

    Result var7(map7);

    map5.insert({src6, var7});

    std::string src12("new_val", 7);
    Result var12(src12);

    std::map<std::string, Result> map13;

    std::string src14("x", 1);
    Result var14(src14);

    double num15(1);
    Result var15(num15);

    map13.insert({src14, var15});

    std::string src16("id", 2);
    Result var16(src16);

    double num17(0);
    Result var17(num17);

    map13.insert({src16, var17});

    Result var13(map13);

    map5.insert({src12, var13});

    Result var5(map5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("changes", 7);
    Result var1(src1);

    std::vector<Result> arr2(2);

    std::map<std::string, Result> map3;

    std::string src4("old_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("x", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Result var8(src8);

    double num9(0);
    Result var9(num9);

    map5.insert({src8, var9});

    Result var5(map5);

    map3.insert({src4, var5});

    std::string src10("new_val", 7);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("x", 1);
    Result var12(src12);

    double num13(3);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("id", 2);
    Result var14(src14);

    double num15(0);
    Result var15(num15);

    map11.insert({src14, var15});

    Result var11(map11);

    map3.insert({src10, var11});

    Result var3(map3);

    arr2.insert(arr2.end(), var3);

    std::map<std::string, Result> map16;

    std::string src17("old_val", 7);
    Result var17(src17);

    std::map<std::string, Result> map18;

    std::string src19("id", 2);
    Result var19(src19);

    double num20(1);
    Result var20(num20);

    map18.insert({src19, var20});

    Result var18(map18);

    map16.insert({src17, var18});

    std::string src21("new_val", 7);
    Result var21(src21);

    std::map<std::string, Result> map22;

    std::string src23("x", 1);
    Result var23(src23);

    double num24(3);
    Result var24(num24);

    map22.insert({src23, var24});

    std::string src25("id", 2);
    Result var25(src25);

    double num26(1);
    Result var26(num26);

    map22.insert({src25, var26});

    Result var22(map22);

    map16.insert({src21, var22});

    Result var16(map16);

    arr2.insert(arr2.end(), var16);

    Result var2(arr2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("changes", 7);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::map<std::string, Result> map3;

    std::string src4("old_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("x", 1);
    Result var6(src6);

    double num7(3);
    Result var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Result var8(src8);

    double num9(0);
    Result var9(num9);

    map5.insert({src8, var9});

    Result var5(map5);

    map3.insert({src4, var5});

    std::string src10("new_val", 7);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("x", 1);
    Result var12(src12);

    double num13(2);
    Result var13(num13);

    map11.insert({src12, var13});

    std::string src14("id", 2);
    Result var14(src14);

    double num15(0);
    Result var15(num15);

    map11.insert({src14, var15});

    Result var11(map11);

    map3.insert({src10, var11});

    Result var3(map3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("first_error", 11);
    Result var1(src1);

    std::string src2("a", 1);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("changes", 7);
    Result var3(src3);

    std::vector<Result> arr4(1);

    std::map<std::string, Result> map5;

    std::string src6("old_val", 7);
    Result var6(src6);

    std::map<std::string, Result> map7;

    std::string src8("x", 1);
    Result var8(src8);

    double num9(2);
    Result var9(num9);

    map7.insert({src8, var9});

    std::string src10("id", 2);
    Result var10(src10);

    double num11(0);
    Result var11(num11);

    map7.insert({src10, var11});

    Result var7(map7);

    map5.insert({src6, var7});

    std::string src12("new_val", 7);
    Result var12(src12);

    std::map<std::string, Result> map13;

    std::string src14("x", 1);
    Result var14(src14);

    double num15(2);
    Result var15(num15);

    map13.insert({src14, var15});

    std::string src16("id", 2);
    Result var16(src16);

    double num17(0);
    Result var17(num17);

    map13.insert({src16, var17});

    Result var13(map13);

    map5.insert({src12, var13});

    Result var5(map5);

    arr4.insert(arr4.end(), var5);

    Result var4(arr4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("changes", 7);
    Result var1(src1);

    std::vector<Result> arr2(2);

    std::map<std::string, Result> map3;

    std::string src4("old_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("x", 1);
    Result var6(src6);

    double num7(2);
    Result var7(num7);

    map5.insert({src6, var7});

    std::string src8("id", 2);
    Result var8(src8);

    double num9(0);
    Result var9(num9);

    map5.insert({src8, var9});

    Result var5(map5);

    map3.insert({src4, var5});

    std::string src10("new_val", 7);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("id", 2);
    Result var12(src12);

    double num13(0);
    Result var13(num13);

    map11.insert({src12, var13});

    Result var11(map11);

    map3.insert({src10, var11});

    Result var3(map3);

    arr2.insert(arr2.end(), var3);

    std::map<std::string, Result> map14;

    std::string src15("old_val", 7);
    Result var15(src15);

    std::map<std::string, Result> map16;

    std::string src17("x", 1);
    Result var17(src17);

    double num18(3);
    Result var18(num18);

    map16.insert({src17, var18});

    std::string src19("id", 2);
    Result var19(src19);

    double num20(1);
    Result var20(num20);

    map16.insert({src19, var20});

    Result var16(map16);

    map14.insert({src15, var16});

    std::string src21("new_val", 7);
    Result var21(src21);

    std::map<std::string, Result> map22;

    std::string src23("id", 2);
    Result var23(src23);

    double num24(1);
    Result var24(num24);

    map22.insert({src23, var24});

    Result var22(map22);

    map14.insert({src21, var22});

    Result var14(map14);

    arr2.insert(arr2.end(), var14);

    Result var2(arr2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("first_error", 11);
    Result var1(src1);

    std::string src2("Inserted object must have primary key `id`:\n{\n\t\"x\":\t1\n}", 62);
    Result var2(src2);

    map0.insert({src1, var2});

    std::string src3("changes", 7);
    Result var3(src3);

    std::vector<Result> arr4(2);

    std::map<std::string, Result> map5;

    std::string src6("old_val", 7);
    Result var6(src6);

    std::map<std::string, Result> map7;

    std::string src8("id", 2);
    Result var8(src8);

    double num9(0);
    Result var9(num9);

    map7.insert({src8, var9});

    Result var7(map7);

    map5.insert({src6, var7});

    std::string src10("new_val", 7);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("id", 2);
    Result var12(src12);

    double num13(0);
    Result var13(num13);

    map11.insert({src12, var13});

    Result var11(map11);

    map5.insert({src10, var11});

    Result var5(map5);

    arr4.insert(arr4.end(), var5);

    std::map<std::string, Result> map14;

    std::string src15("old_val", 7);
    Result var15(src15);

    std::map<std::string, Result> map16;

    std::string src17("id", 2);
    Result var17(src17);

    double num18(1);
    Result var18(num18);

    map16.insert({src17, var18});

    Result var16(map16);

    map14.insert({src15, var16});

    std::string src19("new_val", 7);
    Result var19(src19);

    std::map<std::string, Result> map20;

    std::string src21("id", 2);
    Result var21(src21);

    double num22(1);
    Result var22(num22);

    map20.insert({src21, var22});

    Result var20(map20);

    map14.insert({src19, var20});

    Result var14(map14);

    arr4.insert(arr4.end(), var14);

    Result var4(arr4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test14") {
    std::map<std::string, Result> map0;

    std::string src1("changes", 7);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::map<std::string, Result> map3;

    std::string src4("old_val", 7);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("id", 2);
    Result var6(src6);

    double num7(0);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    map3.insert({src4, var5});

    std::string src8("new_val", 7);
    Result var8(src8);

    Result var9;

    map3.insert({src8, var9});

    Result var3(map3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test15") {
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

    double num6(1);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("changes", 7);
    Result var11(src11);

    std::vector<Result> arr12(1);

    std::map<std::string, Result> map13;

    std::string src14("old_val", 7);
    Result var14(src14);

    std::map<std::string, Result> map15;

    std::string src16("id", 2);
    Result var16(src16);

    double num17(1);
    Result var17(num17);

    map15.insert({src16, var17});

    Result var15(map15);

    map13.insert({src14, var15});

    std::string src18("new_val", 7);
    Result var18(src18);

    Result var19;

    map13.insert({src18, var19});

    Result var13(map13);

    arr12.insert(arr12.end(), var13);

    Result var12(arr12);

    map0.insert({src11, var12});

    std::string src20("skipped", 7);
    Result var20(src20);

    double num21(0);
    Result var21(num21);

    map0.insert({src20, var21});

    Result var0(map0);
  }
}
