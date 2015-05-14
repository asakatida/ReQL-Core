// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests insertion into tables", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test3") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test5") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test7") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test9") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(1);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(2);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(4);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test13") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("inserted", 8);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("unchanged", 9);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("deleted", 7);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("first_error", 11);
    Result var9(src9);

    std::string src10("Duplicate primary key `id`:\n{\n\t\"a\":\t2,\n\t\"id\":\t2\n}\n{\n\t\"b\":\t20,\n\t\"id\":\t2\n}", 96);
    Result var10(src10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("skipped", 7);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    Result var0(map0);
  }

  SECTION("test14") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("inserted", 8);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("unchanged", 9);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("deleted", 7);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("first_error", 11);
    Result var9(src9);

    std::string src10("Duplicate primary key `id`:\n{\n\t\"a\":\t2,\n\t\"id\":\t2\n}\n{\n\t\"b\":\t20,\n\t\"id\":\t2\n}", 96);
    Result var10(src10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("skipped", 7);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    Result var0(map0);
  }

  SECTION("test15") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    double num2(20);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(15);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test17") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    double num2(20);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(2);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test19") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test20") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    double num2(20);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(20);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test21") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test22") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    double num2(20);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(2);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("c", 1);
    Result var5(src5);

    double num6(30);
    Result var6(num6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test23") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(1);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test24") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    double num2(20);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(30);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test25") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test26") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test27") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("generated_keys", 14);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("func", 4);
    Result var7(src7);

    std::string src8("arrlen", 6);
    Result var8(src8);

    map6.insert({src7, var8});

    Result var6(map6);

    map0.insert({src5, var6});

    std::string src9("deleted", 7);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("inserted", 8);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("replaced", 8);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    std::string src15("skipped", 7);
    Result var15(src15);

    double num16(0.0);
    Result var16(num16);

    map0.insert({src15, var16});

    Result var0(map0);
  }

  SECTION("test28") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("foo", 3);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("func", 4);
    Result var4(src4);

    std::string src5("uuid", 4);
    Result var5(src5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test29") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("generated_keys", 14);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("func", 4);
    Result var7(src7);

    std::string src8("arrlen", 6);
    Result var8(src8);

    map6.insert({src7, var8});

    Result var6(map6);

    map0.insert({src5, var6});

    std::string src9("deleted", 7);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("inserted", 8);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("replaced", 8);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    std::string src15("skipped", 7);
    Result var15(src15);

    double num16(0.0);
    Result var16(num16);

    map0.insert({src15, var16});

    Result var0(map0);
  }

  SECTION("test30") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("generated_keys", 14);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("func", 4);
    Result var7(src7);

    std::string src8("arrlen", 6);
    Result var8(src8);

    map6.insert({src7, var8});

    Result var6(map6);

    map0.insert({src5, var6});

    std::string src9("deleted", 7);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("inserted", 8);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("replaced", 8);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    std::string src15("skipped", 7);
    Result var15(src15);

    double num16(0.0);
    Result var16(num16);

    map0.insert({src15, var16});

    Result var0(map0);
  }

  SECTION("test31") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test32") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("unchanged", 9);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(7);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test33") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test34") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test35") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test36") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test37") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
