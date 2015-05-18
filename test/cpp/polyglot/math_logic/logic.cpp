// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp These tests are aimed at &&, ||, and !", "[cpp][ast]") {

  SECTION("test0") {
    Query var0(true);
  }

  SECTION("test1") {
    Query var0(false);
  }

  SECTION("test2") {
    Query var0(true);
  }

  SECTION("test3") {
    Query var0(false);
  }

  SECTION("test4") {
    Query var0(false);
  }

  SECTION("test5") {
    Query var0(true);
  }

  SECTION("test6") {
    Query var0(false);
  }

  SECTION("test7") {
    Query var0(true);
  }

  SECTION("test8") {
    Query var0(true);
  }

  SECTION("test9") {
    Query var0(true);
  }

  SECTION("test10") {
    Query var0(false);
  }

  SECTION("test11") {
    Query var0(false);
  }

  SECTION("test12") {
    Query var0(false);
  }

  SECTION("test13") {
    Query var0(true);
  }

  SECTION("test14") {
    Query var0(true);
  }

  SECTION("test15") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test16") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test17") {
    Query var0(false);
  }

  SECTION("test20") {
    Query var0(true);
  }

  SECTION("test21") {
    std::string src0("str", 3);
    Query var0(src0);
  }

  SECTION("test22") {
    Query var0(false);
  }

  SECTION("test23") {
    Query var0(true);
  }
}
