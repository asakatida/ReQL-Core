// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests that manipulation data in tables 11", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Query> map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(100);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Query> map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(100);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test4") {
    std::string src0("TABLE", 5);
    Query var0(src0);
  }

  SECTION("test5") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Query> map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(1);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test8") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test9") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test11") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test12") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test13") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test14") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test15") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test17") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test18") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(20);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test19") {
    Query var0;
  }

  SECTION("test20") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test21") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test22") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test23") {
    std::map<std::string, Query> map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(0.0);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("inserted", 8);
    Query var5(src5);

    double num6(1);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(0.0);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("skipped", 7);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("unchanged", 9);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    Query var0(map0);
  }

  SECTION("test24") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(10);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("foo", 3);
    Query var3(src3);

    double num4(10);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test25") {
    std::string src0("TABLE_SLICE", 11);
    Query var0(src0);
  }

  SECTION("test26") {
    std::string src0("TABLE_SLICE", 11);
    Query var0(src0);
  }

  SECTION("test27") {
    std::string src0("TABLE_SLICE", 11);
    Query var0(src0);
  }

  SECTION("test28") {
    std::string src0("TABLE_SLICE", 11);
    Query var0(src0);
  }

  SECTION("test29") {
    std::string src0("TABLE_SLICE", 11);
    Query var0(src0);
  }

  SECTION("test30") {
    double num0(9);
    Query var0(num0);
  }

  SECTION("test31") {
    double num0(9);
    Query var0(num0);
  }

  SECTION("test32") {
    double num0(20);
    Query var0(num0);
  }

  SECTION("test33") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test34") {
    double num0(10);
    Query var0(num0);
  }

  SECTION("test35") {
    double num0(10);
    Query var0(num0);
  }

  SECTION("test36") {
    double num0(20);
    Query var0(num0);
  }

  SECTION("test37") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test38") {
    double num0(8);
    Query var0(num0);
  }

  SECTION("test39") {
    double num0(9);
    Query var0(num0);
  }

  SECTION("test40") {
    double num0(19);
    Query var0(num0);
  }

  SECTION("test41") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test42") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test43") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test44") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test45") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test46") {
    double num0(98);
    Query var0(num0);
  }

  SECTION("test47") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test48") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test49") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test50") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test51") {
    double num0(25);
    Query var0(num0);
  }

  SECTION("test52") {
    double num0(100);
    Query var0(num0);
  }

  SECTION("test53") {
    std::vector<Query> arr0(2);

    double num1(4);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(5);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test55") {
    std::vector<Query> arr0(2);

    std::vector<Query> arr1(2);

    double num2(3);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(4);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Query> arr4(2);

    double num5(5);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(6);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test56") {
    std::vector<Query> arr0(2);

    std::vector<Query> arr1(2);

    double num2(3);
    Query var2(num2);

    arr1.insert(arr1.end(), var2);

    double num3(4);
    Query var3(num3);

    arr1.insert(arr1.end(), var3);

    Query var1(arr1);

    arr0.insert(arr0.end(), var1);

    std::vector<Query> arr4(2);

    double num5(5);
    Query var5(num5);

    arr4.insert(arr4.end(), var5);

    double num6(6);
    Query var6(num6);

    arr4.insert(arr4.end(), var6);

    Query var4(arr4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test57") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test58") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test59") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    double num5(2);
    Query var5(num5);

    map1.insert({src4, var5});

    std::string src6("c", 1);
    Query var6(src6);

    double num7(3);
    Query var7(num7);

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test60") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map1.insert({src4, var5});

    std::string src6("c", 1);
    Query var6(src6);

    double num7(3);
    Query var7(num7);

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map8;

    std::string src9("a", 1);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map8.insert({src9, var10});

    std::string src11("b", 1);
    Query var11(src11);

    double num12(2);
    Query var12(num12);

    map8.insert({src11, var12});

    std::string src13("c", 1);
    Query var13(src13);

    double num14(3);
    Query var14(num14);

    map8.insert({src13, var14});

    Query var8(map8);

    arr0.insert(arr0.end(), var8);

    Query var0(arr0);
  }

  SECTION("test61") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    std::string src4("b", 1);
    Query var4(src4);

    double num5(1);
    Query var5(num5);

    map1.insert({src4, var5});

    std::string src6("c", 1);
    Query var6(src6);

    double num7(3);
    Query var7(num7);

    map1.insert({src6, var7});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test62") {
    std::vector<Query> arr0;
    Query var0(arr0);
  }

  SECTION("test63") {
    double num0(25);
    Query var0(num0);
  }

  SECTION("test65") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test66") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test67") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test68") {
    std::string src0("SELECTION<STREAM>", 17);
    Query var0(src0);
  }

  SECTION("test69") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
