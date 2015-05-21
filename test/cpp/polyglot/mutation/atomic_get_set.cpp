// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests replacement of selections", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src8("old_val", 7);
    Query var8(src8);

    Query var9;

    map3.insert({src8, var9});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src8("old_val", 7);
    Query var8(src8);

    Types::object map9;

    std::string src10("id", 2);
    Query var10(src10);

    double num11(0);
    Query var11(num11);

    map9.insert({src10, var11});

    Query var9(map9);

    map3.insert({src8, var9});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src12("first_error", 11);
    Query var12(src12);

    std::string src13("Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}", 67);
    Query var13(src13);

    map0.insert({src12, var13});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src8("old_val", 7);
    Query var8(src8);

    Query var9;

    map3.insert({src8, var9});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src10("deleted", 7);
    Query var10(src10);

    double num11(0);
    Query var11(num11);

    map0.insert({src10, var11});

    std::string src12("errors", 6);
    Query var12(src12);

    double num13(0);
    Query var13(num13);

    map0.insert({src12, var13});

    std::string src14("inserted", 8);
    Query var14(src14);

    double num15(1);
    Query var15(num15);

    map0.insert({src14, var15});

    std::string src16("replaced", 8);
    Query var16(src16);

    double num17(0);
    Query var17(num17);

    map0.insert({src16, var17});

    std::string src18("skipped", 7);
    Query var18(src18);

    double num19(0);
    Query var19(num19);

    map0.insert({src18, var19});

    std::string src20("unchanged", 9);
    Query var20(src20);

    double num21(0);
    Query var21(num21);

    map0.insert({src20, var21});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src8("old_val", 7);
    Query var8(src8);

    Types::object map9;

    std::string src10("id", 2);
    Query var10(src10);

    double num11(0);
    Query var11(num11);

    map9.insert({src10, var11});

    Query var9(map9);

    map3.insert({src8, var9});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src12("first_error", 11);
    Query var12(src12);

    std::string src13("Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}", 67);
    Query var13(src13);

    map0.insert({src12, var13});

    Query var0(map0);
  }

  SECTION("test5") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("x", 1);
    Query var8(src8);

    double num9(1);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src10("old_val", 7);
    Query var10(src10);

    Types::object map11;

    std::string src12("id", 2);
    Query var12(src12);

    double num13(0);
    Query var13(num13);

    map11.insert({src12, var13});

    Query var11(map11);

    map3.insert({src10, var11});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("x", 1);
    Query var8(src8);

    double num9(1);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src10("old_val", 7);
    Query var10(src10);

    Types::object map11;

    std::string src12("id", 2);
    Query var12(src12);

    double num13(0);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("x", 1);
    Query var14(src14);

    double num15(1);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    map3.insert({src10, var11});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src16("first_error", 11);
    Query var16(src16);

    std::string src17("a", 1);
    Query var17(src17);

    map0.insert({src16, var17});

    Query var0(map0);
  }

  SECTION("test7") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(2);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("x", 1);
    Query var8(src8);

    double num9(3);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src10("old_val", 7);
    Query var10(src10);

    Types::object map11;

    std::string src12("id", 2);
    Query var12(src12);

    double num13(0);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("x", 1);
    Query var14(src14);

    double num15(1);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    map3.insert({src10, var11});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Types::object map16;

    std::string src17("new_val", 7);
    Query var17(src17);

    Types::object map18;

    std::string src19("id", 2);
    Query var19(src19);

    double num20(1);
    Query var20(num20);

    map18.insert({src19, var20});

    std::string src21("x", 1);
    Query var21(src21);

    double num22(3);
    Query var22(num22);

    map18.insert({src21, var22});

    Query var18(map18);

    map16.insert({src17, var18});

    std::string src23("old_val", 7);
    Query var23(src23);

    Types::object map24;

    std::string src25("id", 2);
    Query var25(src25);

    double num26(1);
    Query var26(num26);

    map24.insert({src25, var26});

    Query var24(map24);

    map16.insert({src23, var24});

    Query var16(map16);

    arr2.insert(arr2.end(), var16);

    Query var2(arr2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test8") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("x", 1);
    Query var8(src8);

    double num9(2);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src10("old_val", 7);
    Query var10(src10);

    Types::object map11;

    std::string src12("id", 2);
    Query var12(src12);

    double num13(0);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("x", 1);
    Query var14(src14);

    double num15(3);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    map3.insert({src10, var11});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    std::string src8("x", 1);
    Query var8(src8);

    double num9(2);
    Query var9(num9);

    map5.insert({src8, var9});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src10("old_val", 7);
    Query var10(src10);

    Types::object map11;

    std::string src12("id", 2);
    Query var12(src12);

    double num13(0);
    Query var13(num13);

    map11.insert({src12, var13});

    std::string src14("x", 1);
    Query var14(src14);

    double num15(2);
    Query var15(num15);

    map11.insert({src14, var15});

    Query var11(map11);

    map3.insert({src10, var11});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src16("first_error", 11);
    Query var16(src16);

    std::string src17("a", 1);
    Query var17(src17);

    map0.insert({src16, var17});

    Query var0(map0);
  }

  SECTION("test10") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(2);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src8("old_val", 7);
    Query var8(src8);

    Types::object map9;

    std::string src10("id", 2);
    Query var10(src10);

    double num11(0);
    Query var11(num11);

    map9.insert({src10, var11});

    std::string src12("x", 1);
    Query var12(src12);

    double num13(2);
    Query var13(num13);

    map9.insert({src12, var13});

    Query var9(map9);

    map3.insert({src8, var9});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Types::object map14;

    std::string src15("new_val", 7);
    Query var15(src15);

    Types::object map16;

    std::string src17("id", 2);
    Query var17(src17);

    double num18(1);
    Query var18(num18);

    map16.insert({src17, var18});

    Query var16(map16);

    map14.insert({src15, var16});

    std::string src19("old_val", 7);
    Query var19(src19);

    Types::object map20;

    std::string src21("id", 2);
    Query var21(src21);

    double num22(1);
    Query var22(num22);

    map20.insert({src21, var22});

    std::string src23("x", 1);
    Query var23(src23);

    double num24(3);
    Query var24(num24);

    map20.insert({src23, var24});

    Query var20(map20);

    map14.insert({src19, var20});

    Query var14(map14);

    arr2.insert(arr2.end(), var14);

    Query var2(arr2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test11") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(2);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Types::object map5;

    std::string src6("id", 2);
    Query var6(src6);

    double num7(0);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    map3.insert({src4, var5});

    std::string src8("old_val", 7);
    Query var8(src8);

    Types::object map9;

    std::string src10("id", 2);
    Query var10(src10);

    double num11(0);
    Query var11(num11);

    map9.insert({src10, var11});

    Query var9(map9);

    map3.insert({src8, var9});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Types::object map12;

    std::string src13("new_val", 7);
    Query var13(src13);

    Types::object map14;

    std::string src15("id", 2);
    Query var15(src15);

    double num16(1);
    Query var16(num16);

    map14.insert({src15, var16});

    Query var14(map14);

    map12.insert({src13, var14});

    std::string src17("old_val", 7);
    Query var17(src17);

    Types::object map18;

    std::string src19("id", 2);
    Query var19(src19);

    double num20(1);
    Query var20(num20);

    map18.insert({src19, var20});

    Query var18(map18);

    map12.insert({src17, var18});

    Query var12(map12);

    arr2.insert(arr2.end(), var12);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src21("first_error", 11);
    Query var21(src21);

    std::string src22("Inserted object must have primary key `id`:\n{\n\t\"x\":\t1\n}", 62);
    Query var22(src22);

    map0.insert({src21, var22});

    Query var0(map0);
  }

  SECTION("test14") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Query var5;

    map3.insert({src4, var5});

    std::string src6("old_val", 7);
    Query var6(src6);

    Types::object map7;

    std::string src8("id", 2);
    Query var8(src8);

    double num9(0);
    Query var9(num9);

    map7.insert({src8, var9});

    Query var7(map7);

    map3.insert({src6, var7});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test15") {
    Types::object map0;

    std::string src1("changes", 7);
    Query var1(src1);

    Types::array arr2(1);

    Types::object map3;

    std::string src4("new_val", 7);
    Query var4(src4);

    Query var5;

    map3.insert({src4, var5});

    std::string src6("old_val", 7);
    Query var6(src6);

    Types::object map7;

    std::string src8("id", 2);
    Query var8(src8);

    double num9(1);
    Query var9(num9);

    map7.insert({src8, var9});

    Query var7(map7);

    map3.insert({src6, var7});

    Query var3(map3);

    arr2.insert(arr2.end(), var3);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src10("deleted", 7);
    Query var10(src10);

    double num11(1);
    Query var11(num11);

    map0.insert({src10, var11});

    std::string src12("errors", 6);
    Query var12(src12);

    double num13(0);
    Query var13(num13);

    map0.insert({src12, var13});

    std::string src14("inserted", 8);
    Query var14(src14);

    double num15(0);
    Query var15(num15);

    map0.insert({src14, var15});

    std::string src16("replaced", 8);
    Query var16(src16);

    double num17(0);
    Query var17(num17);

    map0.insert({src16, var17});

    std::string src18("skipped", 7);
    Query var18(src18);

    double num19(0);
    Query var19(num19);

    map0.insert({src18, var19});

    std::string src20("unchanged", 9);
    Query var20(src20);

    double num21(0);
    Query var21(num21);

    map0.insert({src20, var21});

    Query var0(map0);
  }
}
