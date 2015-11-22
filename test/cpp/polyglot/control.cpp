// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests RQL control flow structures", "[cpp][ast]") {

  SECTION("test0") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test1") {
    std::vector<Query> arr0(4);

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

  SECTION("test2") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test3") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test4") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
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
    double num0(1);
    Query var0(num0);
  }

  SECTION("test9") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
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
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test13") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
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
    double num0(5);
    Query var0(num0);
  }

  SECTION("test16") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test17") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test18") {
    std::string src0("c", 1);
    Query var0(src0);
  }

  SECTION("test19") {
    std::vector<Query> arr0;
    Query var0(arr0);
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

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test23") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test24") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test25") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test26") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test27") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test28") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test29") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test30") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test31") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test32") {
    double num0(4);
    Query var0(num0);
  }

  SECTION("test33") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test34") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test35") {
    std::string src0("foobar", 6);
    Query var0(src0);
  }

  SECTION("test36") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test37") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test38") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test39") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test40") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test41") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test42") {
    std::vector<Query> arr0(2);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test43") {
    std::vector<Query> arr0(3);

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

  SECTION("test44") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test45") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test46") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test47") {
    std::vector<Query> arr0(3);

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

  SECTION("test48") {
    std::vector<Query> arr0(3);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test49") {
    std::vector<Query> arr0;
    Query var0(arr0);
  }

  SECTION("test50") {
    std::vector<Query> arr0;
    Query var0(arr0);
  }

  SECTION("test51") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test52") {
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

    double num6(3);
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

  SECTION("test53") {
    double num0(3);
    Query var0(num0);
  }

  SECTION("test54") {
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

    double num6(0.0);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(9);
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

  SECTION("test55") {
    std::map<std::string, Query> map0;

    std::string src1("deleted", 7);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("errors", 6);
    Query var3(src3);

    double num4(3);
    Query var4(num4);

    map0.insert({src3, var4});

    std::string src5("first_error", 11);
    Query var5(src5);

    std::string src6("Duplicate primary key `id`:\n{\n\t\"foo\":\t3,\n\t\"id\":\t1\n}\n{\n\t\"id\":\t1\n}", 83);
    Query var6(src6);

    map0.insert({src5, var6});

    std::string src7("inserted", 8);
    Query var7(src7);

    double num8(3);
    Query var8(num8);

    map0.insert({src7, var8});

    std::string src9("replaced", 8);
    Query var9(src9);

    double num10(0.0);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("skipped", 7);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    std::string src13("unchanged", 9);
    Query var13(src13);

    double num14(0.0);
    Query var14(num14);

    map0.insert({src13, var14});

    Query var0(map0);
  }

  SECTION("test56") {
    double num0(6);
    Query var0(num0);
  }

  SECTION("test57") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test58") {
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

    std::string src5("generated_keys", 14);
    Query var5(src5);

    std::map<std::string, Query> map6;

    std::string src7("func", 4);
    Query var7(src7);

    std::string src8("arrlen", 6);
    Query var8(src8);

    map6.insert({src7, var8});

    Query var6(map6);

    map0.insert({src5, var6});

    std::string src9("inserted", 8);
    Query var9(src9);

    double num10(3);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    std::string src13("skipped", 7);
    Query var13(src13);

    double num14(0.0);
    Query var14(num14);

    map0.insert({src13, var14});

    std::string src15("unchanged", 9);
    Query var15(src15);

    double num16(0.0);
    Query var16(num16);

    map0.insert({src15, var16});

    Query var0(map0);
  }

  SECTION("test59") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test60") {
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

    double num6(0.0);
    Query var6(num6);

    map0.insert({src5, var6});

    std::string src7("replaced", 8);
    Query var7(src7);

    double num8(36);
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

  SECTION("test61") {
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

    double num6(3);
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

  SECTION("test62") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test63") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test64") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test65") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test67") {
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

    std::string src5("generated_keys", 14);
    Query var5(src5);

    std::map<std::string, Query> map6;

    std::string src7("func", 4);
    Query var7(src7);

    std::string src8("arrlen", 6);
    Query var8(src8);

    map6.insert({src7, var8});

    Query var6(map6);

    map0.insert({src5, var6});

    std::string src9("inserted", 8);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    std::string src13("skipped", 7);
    Query var13(src13);

    double num14(0.0);
    Query var14(num14);

    map0.insert({src13, var14});

    std::string src15("unchanged", 9);
    Query var15(src15);

    double num16(0.0);
    Query var16(num16);

    map0.insert({src15, var16});

    Query var0(map0);
  }

  SECTION("test68") {
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

    std::string src5("generated_keys", 14);
    Query var5(src5);

    std::map<std::string, Query> map6;

    std::string src7("func", 4);
    Query var7(src7);

    std::string src8("arrlen", 6);
    Query var8(src8);

    map6.insert({src7, var8});

    Query var6(map6);

    map0.insert({src5, var6});

    std::string src9("inserted", 8);
    Query var9(src9);

    double num10(1);
    Query var10(num10);

    map0.insert({src9, var10});

    std::string src11("replaced", 8);
    Query var11(src11);

    double num12(0.0);
    Query var12(num12);

    map0.insert({src11, var12});

    std::string src13("skipped", 7);
    Query var13(src13);

    double num14(0.0);
    Query var14(num14);

    map0.insert({src13, var14});

    std::string src15("unchanged", 9);
    Query var15(src15);

    double num16(0.0);
    Query var16(num16);

    map0.insert({src15, var16});

    Query var0(map0);
  }

  SECTION("test69") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test70") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test71") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test72") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test73") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test74") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
