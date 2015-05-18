// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp tests for `floor`, `ceil`, and `round`, tests inspired by the Python test suite", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("NUMBER", 6);
    Query var0(src0);
  }

  SECTION("test1") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test2") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test3") {
    double num0(0.0);
    Query var0(num0);
  }

  SECTION("test4") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test5") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test6") {
    double num0(-1.0);
    Query var0(num0);
  }

  SECTION("test7") {
    double num0(-1.0);
    Query var0(num0);
  }

  SECTION("test8") {
    double num0(-2.0);
    Query var0(num0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    std::string src0("NUMBER", 6);
    Query var0(src0);
  }

  SECTION("test11") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test12") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test13") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test14") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test15") {
    double num0(2.0);
    Query var0(num0);
  }

  SECTION("test16") {
    double num0(0.0);
    Query var0(num0);
  }

  SECTION("test17") {
    double num0(-1.0);
    Query var0(num0);
  }

  SECTION("test18") {
    double num0(-1.0);
    Query var0(num0);
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
    std::string src0("NUMBER", 6);
    Query var0(src0);
  }

  SECTION("test21") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test22") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test23") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test24") {
    double num0(-1.0);
    Query var0(num0);
  }

  SECTION("test25") {
    double num0(0.0);
    Query var0(num0);
  }

  SECTION("test26") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test27") {
    double num0(10.0);
    Query var0(num0);
  }

  SECTION("test28") {
    double num0(1000000000.0);
    Query var0(num0);
  }

  SECTION("test29") {
    double num0(1e+20);
    Query var0(num0);
  }

  SECTION("test30") {
    double num0(-1.0);
    Query var0(num0);
  }

  SECTION("test31") {
    double num0(-10.0);
    Query var0(num0);
  }

  SECTION("test32") {
    double num0(-1000000000.0);
    Query var0(num0);
  }

  SECTION("test33") {
    double num0(-1e+20);
    Query var0(num0);
  }

  SECTION("test34") {
    double num0(0.0);
    Query var0(num0);
  }

  SECTION("test35") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test36") {
    double num0(10.0);
    Query var0(num0);
  }

  SECTION("test37") {
    double num0(1000000000.0);
    Query var0(num0);
  }

  SECTION("test38") {
    double num0(-1.0);
    Query var0(num0);
  }

  SECTION("test39") {
    double num0(-10.0);
    Query var0(num0);
  }

  SECTION("test40") {
    double num0(-1000000000.0);
    Query var0(num0);
  }

  SECTION("test41") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test42") {
    double num0(10.0);
    Query var0(num0);
  }

  SECTION("test43") {
    double num0(1000000000.0);
    Query var0(num0);
  }

  SECTION("test44") {
    double num0(-1.0);
    Query var0(num0);
  }

  SECTION("test45") {
    double num0(-10.0);
    Query var0(num0);
  }

  SECTION("test46") {
    double num0(-1000000000.0);
    Query var0(num0);
  }

  SECTION("test47") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
