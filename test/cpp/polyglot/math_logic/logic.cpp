// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp These tests are aimed at &&, ||, and !", "[cpp][ast]") {

  SECTION("test0") {
    Result var0(true);
  }

  SECTION("test1") {
    Result var0(false);
  }

  SECTION("test2") {
    Result var0(true);
  }

  SECTION("test3") {
    Result var0(false);
  }

  SECTION("test4") {
    Result var0(false);
  }

  SECTION("test5") {
    Result var0(true);
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
    Result var0(true);
  }

  SECTION("test10") {
    Result var0(false);
  }

  SECTION("test11") {
    Result var0(false);
  }

  SECTION("test12") {
    Result var0(false);
  }

  SECTION("test13") {
    Result var0(true);
  }

  SECTION("test14") {
    Result var0(true);
  }

  SECTION("test15") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test16") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test17") {
    Result var0(false);
  }

  SECTION("test20") {
    Result var0(true);
  }

  SECTION("test21") {
    std::string src0("str", 3);
    Result var0(src0);
  }

  SECTION("test22") {
    Result var0(false);
  }

  SECTION("test23") {
    Result var0(true);
  }
}
