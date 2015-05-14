// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests that manipulation data in tables", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
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

  SECTION("test4") {
    std::string src0("TABLE", 5);
    Result var0(src0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test7") {
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

    double num8(1);
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

  SECTION("test8") {
    Result var0;
  }

  SECTION("test9") {
    Result var0;
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

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
    double num0(100);
    Result var0(num0);
  }

  SECTION("test13") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test15") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(20);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("a", 1);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test16") {
    Result var0;
  }

  SECTION("test19") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test20") {
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

    double num8(1);
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

  SECTION("test21") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(10);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("foo", 3);
    Result var3(src3);

    double num4(10);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test22") {
    std::string src0("TABLE_SLICE", 11);
    Result var0(src0);
  }

  SECTION("test23") {
    std::string src0("TABLE_SLICE", 11);
    Result var0(src0);
  }

  SECTION("test24") {
    std::string src0("TABLE_SLICE", 11);
    Result var0(src0);
  }

  SECTION("test25") {
    std::string src0("TABLE_SLICE", 11);
    Result var0(src0);
  }

  SECTION("test26") {
    std::string src0("TABLE_SLICE", 11);
    Result var0(src0);
  }

  SECTION("test27") {
    double num0(9);
    Result var0(num0);
  }

  SECTION("test28") {
    double num0(9);
    Result var0(num0);
  }

  SECTION("test29") {
    double num0(20);
    Result var0(num0);
  }

  SECTION("test30") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test31") {
    double num0(10);
    Result var0(num0);
  }

  SECTION("test32") {
    double num0(10);
    Result var0(num0);
  }

  SECTION("test33") {
    double num0(20);
    Result var0(num0);
  }

  SECTION("test34") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test35") {
    double num0(8);
    Result var0(num0);
  }

  SECTION("test36") {
    double num0(9);
    Result var0(num0);
  }

  SECTION("test37") {
    double num0(19);
    Result var0(num0);
  }

  SECTION("test38") {
    double num0(100);
    Result var0(num0);
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
    double num0(2);
    Result var0(num0);
  }

  SECTION("test41") {
    double num0(3);
    Result var0(num0);
  }

  SECTION("test42") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test43") {
    double num0(98);
    Result var0(num0);
  }

  SECTION("test45") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test46") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test47") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test48") {
    double num0(25);
    Result var0(num0);
  }

  SECTION("test49") {
    double num0(100);
    Result var0(num0);
  }

  SECTION("test50") {
    std::vector<Result> arr0(2);

    double num1(4);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(5);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test52") {
    std::vector<Result> arr0(2);

    std::vector<Result> arr1(2);

    double num2(3);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(4);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    double num5(5);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(6);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test53") {
    std::vector<Result> arr0(2);

    std::vector<Result> arr1(2);

    double num2(3);
    Result var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(4);
    Result var3(num3);

    arr1.insert(arr1.end(), var3);

    Result var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Result> arr4(2);

    double num5(5);
    Result var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(6);
    Result var6(num6);

    arr4.insert(arr4.end(), var6);

    Result var4(arr4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test54") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test55") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test56") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    double num5(2);
    Result var5(num5);

    map1.insert({src4, var5});

    std::string src6("c", 1);
    Result var6(src6);

    double num7(3);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test57") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map1.insert({src4, var5});

    std::string src6("c", 1);
    Result var6(src6);

    double num7(3);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map8;

    std::string src9("a", 1);
    Result var9(src9);

    double num10(1);
    Result var10(num10);

    map8.insert({src9, var10});

    std::string src11("b", 1);
    Result var11(src11);

    double num12(2);
    Result var12(num12);

    map8.insert({src11, var12});

    std::string src13("c", 1);
    Result var13(src13);

    double num14(3);
    Result var14(num14);

    map8.insert({src13, var14});

    Result var8(map8);

    arr0.insert(arr0.end(), var8);

    Result var0(arr0);
  }

  SECTION("test58") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Result var4(src4);

    double num5(1);
    Result var5(num5);

    map1.insert({src4, var5});

    std::string src6("c", 1);
    Result var6(src6);

    double num7(3);
    Result var7(num7);

    map1.insert({src6, var7});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test59") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test60") {
    double num0(25);
    Result var0(num0);
  }

  SECTION("test62") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test63") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test64") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test65") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
