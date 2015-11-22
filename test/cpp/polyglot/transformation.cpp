// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests that manipulation data in tables 13", "[cpp][ast]") {

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

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Query> map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Query> map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test6") {
    std::map<std::string, Query> map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
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

  SECTION("test8") {
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

  SECTION("test9") {
    double num0(4950);
    Query var0(num0);
  }

  SECTION("test10") {
    double num0(9900);
    Query var0(num0);
  }

  SECTION("test11") {
    double num0(9900);
    Query var0(num0);
  }

  SECTION("test12") {
    double num0(9900);
    Query var0(num0);
  }

  SECTION("test13") {
    std::vector<Query> arr0;
    Query var0(arr0);
  }

  SECTION("test15") {
    double num0(200);
    Query var0(num0);
  }

  SECTION("test16") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test17") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

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

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test20") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test21") {
    double num0(1);
    Query var0(num0);
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
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test25") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test26") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(5);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
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

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test29") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test30") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test31") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test32") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(3);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test33") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test34") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(3);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test35") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(3);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test36") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(3);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test37") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(96);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test38") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(96);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test39") {
    std::string src0("SELECTION<ARRAY>", 16);
    Query var0(src0);
  }

  SECTION("test40") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
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
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test43") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test44") {
    Query var0(true);
  }

  SECTION("test45") {
    Query var0(true);
  }

  SECTION("test46") {
    Query var0(true);
  }

  SECTION("test47") {
    double num0(99);
    Query var0(num0);
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
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test50") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test51") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test52") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test53") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test54") {
    double num0(95);
    Query var0(num0);
  }

  SECTION("test55") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test56") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
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
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test60") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test61") {
    double num0(8);
    Query var0(num0);
  }

  SECTION("test62") {
    double num0(9);
    Query var0(num0);
  }

  SECTION("test63") {
    double num0(7);
    Query var0(num0);
  }

  SECTION("test64") {
    double num0(8);
    Query var0(num0);
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

  SECTION("test66") {
    double num0(88);
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
    double num0(8);
    Query var0(num0);
  }

  SECTION("test72") {
    double num0(9);
    Query var0(num0);
  }

  SECTION("test73") {
    double num0(7);
    Query var0(num0);
  }

  SECTION("test74") {
    double num0(8);
    Query var0(num0);
  }

  SECTION("test75") {
    double num0(87);
    Query var0(num0);
  }

  SECTION("test76") {
    double num0(88);
    Query var0(num0);
  }

  SECTION("test77") {
    double num0(86);
    Query var0(num0);
  }

  SECTION("test78") {
    double num0(87);
    Query var0(num0);
  }

  SECTION("test79") {
    double num0(10);
    Query var0(num0);
  }

  SECTION("test80") {
    double num0(11);
    Query var0(num0);
  }

  SECTION("test83") {
    std::vector<Query> arr0(2);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test85") {
    std::vector<Query> arr0(1);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test86") {
    std::vector<Query> arr0(4);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(5);
    Query var4(num4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test87") {
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

  SECTION("test88") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(1);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test89") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(3);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(99);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test90") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test91") {
    Query var0(false);
  }

  SECTION("test92") {
    Query var0(true);
  }

  SECTION("test93") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test94") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test95") {
    std::map<std::string, Query> map0;
    Query var0(map0);
  }

  SECTION("test96") {
    std::map<std::string, Query> map0;
    Query var0(map0);
  }

  SECTION("test97") {
    std::map<std::string, Query> map0;
    Query var0(map0);
  }

  SECTION("test98") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test99") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test100") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test101") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test102") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test103") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test104") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test105") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test106") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test107") {
    std::map<std::string, Query> map0;

    std::string src1("b", 1);
    Query var1(src1);

    std::map<std::string, Query> map2;

    std::string src3("c", 1);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    std::string src5("id", 2);
    Query var5(src5);

    double num6(0);
    Query var6(num6);

    map0.insert({src5, var6});

    Query var0(map0);
  }

  SECTION("test108") {
    std::map<std::string, Query> map0;

    std::string src1("b", 1);
    Query var1(src1);

    std::map<std::string, Query> map2;

    std::string src3("c", 1);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    std::string src5("id", 2);
    Query var5(src5);

    double num6(0);
    Query var6(num6);

    map0.insert({src5, var6});

    Query var0(map0);
  }

  SECTION("test109") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test110") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test111") {
    std::vector<Query> arr0(2);

    std::map<std::string, Query> map1;

    std::string src2("a", 1);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Query> map4;

    std::string src5("b", 1);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }

  SECTION("test112") {
    std::map<std::string, Query> map0;

    std::string src1("foo", 3);
    Query var1(src1);

    std::map<std::string, Query> map2;
    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test113") {
    std::map<std::string, Query> map0;

    std::string src1("a", 1);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test114") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test115") {
    std::map<std::string, Query> map0;
    Query var0(map0);
  }

  SECTION("test116") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test117") {
    std::map<std::string, Query> map0;

    std::string src1("b", 1);
    Query var1(src1);

    std::map<std::string, Query> map2;
    Query var2(map2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test118") {
    std::map<std::string, Query> map0;

    std::string src1("b", 1);
    Query var1(src1);

    std::map<std::string, Query> map2;
    Query var2(map2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test119") {
    std::map<std::string, Query> map0;

    std::string src1("b", 1);
    Query var1(src1);

    std::map<std::string, Query> map2;

    std::string src3("c", 1);
    Query var3(src3);

    double num4(0);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    std::string src5("id", 2);
    Query var5(src5);

    double num6(0);
    Query var6(num6);

    map0.insert({src5, var6});

    Query var0(map0);
  }

  SECTION("test120") {
    std::string src0("SELECTION<STREAM>", 17);
    Query var0(src0);
  }

  SECTION("test121") {
    std::string src0("ARRAY", 5);
    Query var0(src0);
  }

  SECTION("test122") {
    double num0(200);
    Query var0(num0);
  }

  SECTION("test123") {
    double num0(103);
    Query var0(num0);
  }

  SECTION("test124") {
    double num0(103);
    Query var0(num0);
  }

  SECTION("test125") {
    std::vector<Query> arr0(2);

    double num1(0);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    Query var0(arr0);
  }

  SECTION("test126") {
    std::vector<Query> arr0(1);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test127") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test128") {
    std::vector<Query> arr0(1);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test129") {
    Query var0(true);
  }

  SECTION("test130") {
    Query var0(false);
  }

  SECTION("test133") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test134") {
    std::vector<Query> arr0;
    Query var0(arr0);
  }

  SECTION("test135") {
    std::vector<Query> arr0;
    Query var0(arr0);
  }

  SECTION("test136") {
    std::map<std::string, Query> map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test137") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test138") {
    std::map<std::string, Query> map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
