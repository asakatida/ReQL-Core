// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp date/time api (#977)", "[cpp][ast]") {

  SECTION("test3") {
    double num0(1375148296.681);
    Result var0(num0);
  }

  SECTION("test4") {
    double num0(1375146296.681);
    Result var0(num0);
  }

  SECTION("test5") {
    double num0(1000);
    Result var0(num0);
  }

  SECTION("test6") {
    Result var0(false);
  }

  SECTION("test7") {
    Result var0(true);
  }

  SECTION("test8") {
    Result var0(true);
  }

  SECTION("test9") {
    Result var0(false);
  }

  SECTION("test10") {
    Result var0(true);
  }

  SECTION("test11") {
    Result var0(false);
  }

  SECTION("test12") {
    Result var0(true);
  }

  SECTION("test13") {
    Result var0(true);
  }

  SECTION("test14") {
    Result var0(false);
  }

  SECTION("test15") {
    Result var0(true);
  }

  SECTION("test16") {
    Result var0(false);
  }

  SECTION("test17") {
    Result var0(false);
  }

  SECTION("test18") {
    Result var0(true);
  }

  SECTION("test19") {
    Result var0(false);
  }

  SECTION("test20") {
    Result var0(false);
  }

  SECTION("test21") {
    Result var0(true);
  }

  SECTION("test22") {
    double num0(1375142400);
    Result var0(num0);
  }

  SECTION("test23") {
    double num0(4896.681);
    Result var0(num0);
  }

  SECTION("test24") {
    double num0(2013);
    Result var0(num0);
  }

  SECTION("test25") {
    double num0(7);
    Result var0(num0);
  }

  SECTION("test26") {
    double num0(30);
    Result var0(num0);
  }

  SECTION("test27") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test28") {
    double num0(211);
    Result var0(num0);
  }

  SECTION("test29") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test30") {
    double num0(21);
    Result var0(num0);
  }

  SECTION("test31") {
    double num0(36.681);
    Result var0(num0);
  }

  SECTION("test32") {
    double num0(1375165800.1);
    Result var0(num0);
  }

  SECTION("test33") {
    std::string src0("-07:00", 6);
    Result var0(src0);
  }

  SECTION("test34") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
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

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test38") {
    double num0(1375081200);
    Result var0(num0);
  }

  SECTION("test39") {
    std::string src0("-07:00", 6);
    Result var0(src0);
  }

  SECTION("test40") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

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
    double num0(1375242965);
    Result var0(num0);
  }

  SECTION("test43") {
    std::string src0("2013-07-30T20:56:05-07:00", 25);
    Result var0(src0);
  }

  SECTION("test44") {
    std::string src0("PTYPE<TIME>", 11);
    Result var0(src0);
  }

  SECTION("test45") {
    double num0(0);
    Result var0(num0);
  }

  SECTION("test46") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test47") {
    std::string src0("2013-07-30T20:56:05-07:00", 25);
    Result var0(src0);
  }

  SECTION("test48") {
    std::vector<Result> arr0(7);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(5);
    Result var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(6);
    Result var6(num6);

    arr0.insert(arr0.end(), var6);

    double num7(7);
    Result var7(num7);

    arr0.insert(arr0.end(), var7);

    Result var0(arr0);
  }

  SECTION("test49") {
    std::vector<Result> arr0(12);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    double num5(5);
    Result var5(num5);

    arr0.insert(arr0.end(), var5);

    double num6(6);
    Result var6(num6);

    arr0.insert(arr0.end(), var6);

    double num7(7);
    Result var7(num7);

    arr0.insert(arr0.end(), var7);

    double num8(8);
    Result var8(num8);

    arr0.insert(arr0.end(), var8);

    double num9(9);
    Result var9(num9);

    arr0.insert(arr0.end(), var9);

    double num10(10);
    Result var10(num10);

    arr0.insert(arr0.end(), var10);

    double num11(11);
    Result var11(num11);

    arr0.insert(arr0.end(), var11);

    double num12(12);
    Result var12(num12);

    arr0.insert(arr0.end(), var12);

    Result var0(arr0);
  }
}
