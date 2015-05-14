// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests r.default", "[cpp][ast]") {

  SECTION("test0") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test1") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test2") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test5") {
    double num0(2);
    Result var0(num0);
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
    double num0(2);
    Result var0(num0);
  }

  SECTION("test8") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test9") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test10") {
    double num0(2);
    Result var0(num0);
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

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test14") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test15") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test16") {
    Result var0;
  }

  SECTION("test17") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test18") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test19") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test20") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test21") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test22") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test23") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test24") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test25") {
    Result var0;
  }

  SECTION("test26") {
    std::string src0("No attribute `b` in object:\n{\n}", 33);
    Result var0(src0);
  }

  SECTION("test27") {
    std::string src0("Cannot reduce over an empty stream.", 35);
    Result var0(src0);
  }

  SECTION("test28") {
    std::string src0("Cannot reduce over an empty stream.", 35);
    Result var0(src0);
  }

  SECTION("test29") {
    std::string src0("Expected type NUMBER but found NULL.", 36);
    Result var0(src0);
  }

  SECTION("test30") {
    std::string src0("Expected type NUMBER but found NULL.", 36);
    Result var0(src0);
  }

  SECTION("test31") {
    std::string src0("Expected type NUMBER but found NULL.", 36);
    Result var0(src0);
  }

  SECTION("test32") {
    std::string src0("Expected type NUMBER but found NULL.", 36);
    Result var0(src0);
  }

  SECTION("test34") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test35") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test36") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    double num4(1);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test37") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    double num4(1);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test38") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
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
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test41") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    double num4(1);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test42") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test43") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    Result var4;

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map5;

    std::string src6("a", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test44") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test45") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test46") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    Result var4;

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map5;

    std::string src6("a", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test47") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test48") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test49") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    Result var4;

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map5;

    std::string src6("a", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test50") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test51") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test52") {
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

    std::string src7("generated_keys", 14);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("func", 4);
    Result var9(src9);

    std::string src10("arrlen", 6);
    Result var10(src10);

    map8.insert({src9, var10});

    Result var8(map8);

    map0.insert({src7, var8});

    std::string src11("inserted", 8);
    Result var11(src11);

    double num12(3);
    Result var12(num12);

    map0.insert({src11, var12});

    std::string src13("unchanged", 9);
    Result var13(src13);

    double num14(0.0);
    Result var14(num14);

    map0.insert({src13, var14});

    std::string src15("replaced", 8);
    Result var15(src15);

    double num16(0.0);
    Result var16(num16);

    map0.insert({src15, var16});

    Result var0(map0);
  }

  SECTION("test54") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test55") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test56") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    double num4(1);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test57") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test58") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test59") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    double num4(1);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test60") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test61") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    Result var4;

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map5;

    std::string src6("a", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test62") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test63") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test64") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    Result var4;

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map5;

    std::string src6("a", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test65") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test66") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test67") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;
    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map2;

    std::string src3("a", 1);
    Result var3(src3);

    Result var4;

    map2.insert({src3, var4});

    Result var2(map2);

    arr0.insert(arr0.end(), var2);

    std::map<std::string, Result> map5;

    std::string src6("a", 1);
    Result var6(src6);

    double num7(1);
    Result var7(num7);

    map5.insert({src6, var7});

    Result var5(map5);

    arr0.insert(arr0.end(), var5);

    Result var0(arr0);
  }

  SECTION("test68") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test69") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
