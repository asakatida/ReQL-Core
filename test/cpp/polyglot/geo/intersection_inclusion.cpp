// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Test intersects and includes semantics", "[cpp][ast]") {

  SECTION("test0") {
    Query var0(true);
  }

  SECTION("test1") {
    Query var0(false);
  }

  SECTION("test2") {
    Query var0(false);
  }

  SECTION("test3") {
    Query var0(true);
  }

  SECTION("test4") {
    Query var0(true);
  }

  SECTION("test5") {
    Query var0(true);
  }

  SECTION("test6") {
    Query var0(true);
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
    Query var0(true);
  }

  SECTION("test13") {
    Query var0(true);
  }

  SECTION("test14") {
    Query var0(true);
  }

  SECTION("test15") {
    Query var0(false);
  }

  SECTION("test16") {
    Query var0(false);
  }

  SECTION("test17") {
    Query var0(true);
  }

  SECTION("test18") {
    Query var0(false);
  }

  SECTION("test19") {
    Query var0(false);
  }

  SECTION("test20") {
    Query var0(true);
  }

  SECTION("test21") {
    Query var0(true);
  }

  SECTION("test22") {
    Query var0(true);
  }

  SECTION("test23") {
    Query var0(true);
  }

  SECTION("test24") {
    Query var0(false);
  }

  SECTION("test25") {
    Query var0(true);
  }

  SECTION("test26") {
    double num0(2);
    Query var0(num0);
  }

  SECTION("test27") {
    Query var0(true);
  }

  SECTION("test28") {
    Query var0(false);
  }

  SECTION("test29") {
    Query var0(false);
  }

  SECTION("test30") {
    Query var0(true);
  }

  SECTION("test31") {
    Query var0(true);
  }

  SECTION("test32") {
    Query var0(true);
  }

  SECTION("test33") {
    Query var0(true);
  }

  SECTION("test34") {
    Query var0(true);
  }

  SECTION("test35") {
    Query var0(true);
  }

  SECTION("test36") {
    Query var0(true);
  }

  SECTION("test37") {
    Query var0(false);
  }

  SECTION("test38") {
    Query var0(true);
  }

  SECTION("test39") {
    Query var0(true);
  }

  SECTION("test40") {
    Query var0(false);
  }

  SECTION("test41") {
    Query var0(true);
  }

  SECTION("test42") {
    Query var0(true);
  }

  SECTION("test43") {
    Query var0(true);
  }

  SECTION("test44") {
    Query var0(false);
  }

  SECTION("test45") {
    Query var0(false);
  }

  SECTION("test46") {
    Query var0(false);
  }

  SECTION("test47") {
    Query var0(false);
  }

  SECTION("test48") {
    Query var0(false);
  }

  SECTION("test49") {
    double num0(1);
    Query var0(num0);
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

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
