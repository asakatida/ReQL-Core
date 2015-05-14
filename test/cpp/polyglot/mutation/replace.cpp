// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests replacement of selections", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
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

    double num8(100);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test1") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
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

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
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

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
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

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(10);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("first_error", 11);
    Result var3(src3);

    std::string src4("Inserted object must have primary key `id`:\n{\n\t\"a\":\t1\n}", 62);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("skipped", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("deleted", 7);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("inserted", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("replaced", 8);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    Result var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
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

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(8);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("first_error", 11);
    Result var3(src3);

    std::string src4("Primary key `id` cannot be changed (`{\n\t\"id\":\t1\n}` -> `{\n\t\"a\":\t1,\n\t\"id\":\t2\n}`).", 96);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("skipped", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("deleted", 7);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("inserted", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("replaced", 8);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    Result var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("first_error", 11);
    Result var3(src3);

    std::string src4("Inserted object must have primary key `id`:\n{\n\t\"a\":\t1\n}", 62);
    Result var4(src4);

    map0.insert({src3, var4});

    std::string src5("skipped", 7);
    Result var5(src5);

    double num6(0.0);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("deleted", 7);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("inserted", 8);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("replaced", 8);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    Result var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
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

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
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

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test13") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
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

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(1);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("errors", 6);
    Result var1(src1);

    double num2(0.0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("skipped", 7);
    Result var3(src3);

    double num4(0.0);
    Result var4(num4);

    map0.insert({src3, var4});

    std::string src5("deleted", 7);
    Result var5(src5);

    double num6(99);
    Result var6(num6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Result var7(src7);

    double num8(0.0);
    Result var8(num8);

    map0.insert({src7, var8});

    std::string src9("unchanged", 9);
    Result var9(src9);

    double num10(0.0);
    Result var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Result var11(src11);

    double num12(0.0);
    Result var12(num12);

    map0.insert({src11, var12});

    Result var0(map0);
  }

  SECTION("test17") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test18") {
    double num0(1);
    Result var0(num0);
  }
}
