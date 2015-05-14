// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test intersects and includes semantics", "[cpp][ast]") {

  SECTION("test0") {
    Result var0(true);
  }

  SECTION("test1") {
    Result var0(false);
  }

  SECTION("test2") {
    Result var0(false);
  }

  SECTION("test3") {
    Result var0(true);
  }

  SECTION("test4") {
    Result var0(true);
  }

  SECTION("test5") {
    Result var0(true);
  }

  SECTION("test6") {
    Result var0(true);
  }

  SECTION("test7") {
    Result var0(true);
  }

  SECTION("test8") {
    Result var0(true);
  }

  SECTION("test9") {
    Result var0(true);
  }

  SECTION("test10") {
    Result var0(false);
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
    Result var0(true);
  }

  SECTION("test15") {
    Result var0(false);
  }

  SECTION("test16") {
    Result var0(false);
  }

  SECTION("test17") {
    Result var0(true);
  }

  SECTION("test18") {
    Result var0(false);
  }

  SECTION("test19") {
    Result var0(false);
  }

  SECTION("test20") {
    Result var0(true);
  }

  SECTION("test21") {
    Result var0(true);
  }

  SECTION("test22") {
    Result var0(true);
  }

  SECTION("test23") {
    Result var0(true);
  }

  SECTION("test24") {
    Result var0(false);
  }

  SECTION("test25") {
    Result var0(true);
  }

  SECTION("test26") {
    double num0(2);
    Result var0(num0);
  }

  SECTION("test27") {
    Result var0(true);
  }

  SECTION("test28") {
    Result var0(false);
  }

  SECTION("test29") {
    Result var0(false);
  }

  SECTION("test30") {
    Result var0(true);
  }

  SECTION("test31") {
    Result var0(true);
  }

  SECTION("test32") {
    Result var0(true);
  }

  SECTION("test33") {
    Result var0(true);
  }

  SECTION("test34") {
    Result var0(true);
  }

  SECTION("test35") {
    Result var0(true);
  }

  SECTION("test36") {
    Result var0(true);
  }

  SECTION("test37") {
    Result var0(false);
  }

  SECTION("test38") {
    Result var0(true);
  }

  SECTION("test39") {
    Result var0(true);
  }

  SECTION("test40") {
    Result var0(false);
  }

  SECTION("test41") {
    Result var0(true);
  }

  SECTION("test42") {
    Result var0(true);
  }

  SECTION("test43") {
    Result var0(true);
  }

  SECTION("test44") {
    Result var0(false);
  }

  SECTION("test45") {
    Result var0(false);
  }

  SECTION("test46") {
    Result var0(false);
  }

  SECTION("test47") {
    Result var0(false);
  }

  SECTION("test48") {
    Result var0(false);
  }

  SECTION("test49") {
    double num0(1);
    Result var0(num0);
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

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
