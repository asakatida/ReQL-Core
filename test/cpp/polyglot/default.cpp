// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

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
    Types::object map0;

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
    Types::object map0;

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
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test12") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test13") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test14") {
    Types::object map0;

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
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test18") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test19") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test20") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test21") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test22") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test23") {
    Types::object map0;

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
    std::string src0("No attribute `b` in object:\n{\n}", 33);
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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(2);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

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
    Types::array arr0(2);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test40") {
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(2);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(3);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map5;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(3);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map5;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(3);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map5;

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
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test51") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test52") {
    Types::object map0;

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

    Types::object map6;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(2);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

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
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test58") {
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(2);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(3);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map5;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(3);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map5;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(1);

    Types::object map1;

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
    Types::array arr0(3);

    Types::object map1;
    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map2;

    std::string src3("a", 1);
    Query var3(src3);

    Query var4;

    map2.insert({src3, var4});

    Query var2(map2);

    arr0.insert(arr0.end(), var2);

    Types::object map5;

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
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test69") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
