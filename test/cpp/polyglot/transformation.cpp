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

    double num8(100);
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
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test6") {
    Result var0;
  }

  SECTION("test7") {
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

    double num8(100);
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

  SECTION("test8") {
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

    double num8(100);
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

  SECTION("test9") {
    double num0(4950);
    Result var0(num0);
  }

  SECTION("test10") {
    double num0(9900);
    Result var0(num0);
  }

  SECTION("test11") {
    double num0(9900);
    Result var0(num0);
  }

  SECTION("test12") {
    double num0(9900);
    Result var0(num0);
  }

  SECTION("test13") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test15") {
    double num0(200);
    Result var0(num0);
  }

  SECTION("test16") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test17") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

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

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test20") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test21") {
    double num0(1);
    Result var0(num0);
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
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

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

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(5);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test27") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test28") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test29") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test30") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test31") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test32") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(3);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(3);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test33") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test34") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(3);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(3);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test35") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(3);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(3);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test36") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(3);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(3);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test37") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(96);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test38") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(96);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test39") {
    std::string src0("SELECTION<ARRAY>", 16);
    Result var0(src0);
  }

  SECTION("test40") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test41") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test42") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test43") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test44") {
    Result var0(true);
  }

  SECTION("test45") {
    Result var0(true);
  }

  SECTION("test46") {
    Result var0(true);
  }

  SECTION("test47") {
    double num0(99);
    Result var0(num0);
  }

  SECTION("test48") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test49") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test50") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test51") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test52") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test53") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test54") {
    double num0(95);
    Result var0(num0);
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
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
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
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test59") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test60") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test61") {
    double num0(8);
    Result var0(num0);
  }

  SECTION("test62") {
    double num0(9);
    Result var0(num0);
  }

  SECTION("test63") {
    double num0(7);
    Result var0(num0);
  }

  SECTION("test64") {
    double num0(8);
    Result var0(num0);
  }

  SECTION("test65") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test66") {
    double num0(88);
    Result var0(num0);
  }

  SECTION("test67") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
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

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test70") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test71") {
    double num0(8);
    Result var0(num0);
  }

  SECTION("test72") {
    double num0(9);
    Result var0(num0);
  }

  SECTION("test73") {
    double num0(7);
    Result var0(num0);
  }

  SECTION("test74") {
    double num0(8);
    Result var0(num0);
  }

  SECTION("test75") {
    double num0(87);
    Result var0(num0);
  }

  SECTION("test76") {
    double num0(88);
    Result var0(num0);
  }

  SECTION("test77") {
    double num0(86);
    Result var0(num0);
  }

  SECTION("test78") {
    double num0(87);
    Result var0(num0);
  }

  SECTION("test79") {
    double num0(10);
    Result var0(num0);
  }

  SECTION("test80") {
    double num0(11);
    Result var0(num0);
  }

  SECTION("test83") {
    std::vector<Result> arr0(2);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test85") {
    std::vector<Result> arr0(1);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test86") {
    std::vector<Result> arr0(4);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(5);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test87") {
    std::vector<Result> arr0(3);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test88") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(1);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test89") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(3);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(99);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test90") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test91") {
    Result var0(false);
  }

  SECTION("test92") {
    Result var0(true);
  }

  SECTION("test93") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test94") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test95") {
    std::map<std::string, Result> map0;
    Result var0(map0);
  }

  SECTION("test96") {
    std::map<std::string, Result> map0;
    Result var0(map0);
  }

  SECTION("test97") {
    std::map<std::string, Result> map0;
    Result var0(map0);
  }

  SECTION("test98") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test99") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test100") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test101") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test102") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test103") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test104") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test105") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test106") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test107") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("c", 1);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    std::string src5("id", 2);
    Result var5(src5);

    double num6(0);
    Result var6(num6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test108") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("c", 1);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    std::string src5("id", 2);
    Result var5(src5);

    double num6(0);
    Result var6(num6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test109") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test110") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test111") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("a", 1);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("b", 1);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test112") {
    std::map<std::string, Result> map0;

    std::string src1("foo", 3);
    Result var1(src1);

    std::map<std::string, Result> map2;
    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test113") {
    std::map<std::string, Result> map0;

    std::string src1("a", 1);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test114") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test115") {
    std::map<std::string, Result> map0;
    Result var0(map0);
  }

  SECTION("test116") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test117") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;
    Result var2(map2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test118") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;
    Result var2(map2);

    map0.insert({src1, var2});

    std::string src3("id", 2);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map0.insert({src3, var4});

    Result var0(map0);
  }

  SECTION("test119") {
    std::map<std::string, Result> map0;

    std::string src1("b", 1);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("c", 1);
    Result var3(src3);

    double num4(0);
    Result var4(num4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    std::string src5("id", 2);
    Result var5(src5);

    double num6(0);
    Result var6(num6);

    map0.insert({src5, var6});

    Result var0(map0);
  }

  SECTION("test120") {
    std::string src0("SELECTION<STREAM>", 17);
    Result var0(src0);
  }

  SECTION("test121") {
    std::string src0("ARRAY", 5);
    Result var0(src0);
  }

  SECTION("test122") {
    double num0(200);
    Result var0(num0);
  }

  SECTION("test123") {
    double num0(103);
    Result var0(num0);
  }

  SECTION("test124") {
    double num0(103);
    Result var0(num0);
  }

  SECTION("test125") {
    std::vector<Result> arr0(2);

    double num1(0);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(1);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test126") {
    std::vector<Result> arr0(1);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test127") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test128") {
    std::vector<Result> arr0(1);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test129") {
    Result var0(true);
  }

  SECTION("test130") {
    Result var0(false);
  }

  SECTION("test133") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test134") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test135") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }

  SECTION("test136") {
    std::map<std::string, Result> map0;

    std::string src1("id", 2);
    Result var1(src1);

    double num2(0);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test137") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test138") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
