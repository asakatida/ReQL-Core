// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests r.default", "[cpp][ast]") {

  SECTION("test0") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test1") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test2") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test3") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test5") {
    double num0(2);
    Query var0(num0);
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
    double num0(2);
    Query var0(num0);
  }

  SECTION("test8") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test9") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test10") {
    double num0(2);
    Query var0(num0);
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
    double num0(1);
    Query var0(num0);
  }

  SECTION("test16") {
    Query var0;
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

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test19") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
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
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test24") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test25") {
    Query var0;
  }

  SECTION("test26") {
    std::string src0("No attribute `b` in object:\n{}", 31);
    Query var0(src0);
  }

  SECTION("test27") {
    std::string src0("Cannot reduce over an empty stream.", 35);
    Query var0(src0);
  }

  SECTION("test28") {
    std::string src0("Cannot reduce over an empty stream.", 35);
    Query var0(src0);
  }

  SECTION("test29") {
    std::string src0("Expected type NUMBER but found NULL.", 36);
    Query var0(src0);
  }

  SECTION("test30") {
    std::string src0("Expected type NUMBER but found NULL.", 36);
    Query var0(src0);
  }

  SECTION("test31") {
    std::string src0("Expected type NUMBER but found NULL.", 36);
    Query var0(src0);
  }

  SECTION("test32") {
    std::string src0("Expected type NUMBER but found NULL.", 36);
    Query var0(src0);
  }

  SECTION("test34") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test35") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test36") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    double num4(1);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test37") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    double num4(1);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test38") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test39") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test40") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test41") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    double num4(1);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test42") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test43") {
    std::vector<Query> arr0(3);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Query> map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test44") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test45") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test46") {
    std::vector<Query> arr0(3);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Query> map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test47") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test48") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test49") {
    std::vector<Query> arr0(3);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Query> map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test50") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test51") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
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

  SECTION("test54") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test55") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test56") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    double num4(1);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

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
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test59") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    double num4(1);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test60") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test61") {
    std::vector<Query> arr0(3);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Query> map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test62") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test63") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test64") {
    std::vector<Query> arr0(3);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Query> map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test65") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test66") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test67") {
    std::vector<Query> arr0(3);

    std::map<std::string, Query> map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Query> map5;

    std::string src6("a", 1);
    Query var6(src6);

    double num7(1);
    Query var7(num7);

    map5.insert({src6, var7});

    Query var5(map5);

    arr0.insert(arr0.end(), var5);

    Query var0(arr0);
  }

  SECTION("test68") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
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
