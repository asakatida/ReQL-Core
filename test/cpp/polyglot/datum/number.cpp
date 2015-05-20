// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests of conversion to and from the RQL number type", "[cpp][ast]") {

  SECTION("test0") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test1") {
    double num0(-1);
    Query var0(num0);
  }

  SECTION("test2") {
    double num0(0);
    Query var0(num0);
  }

  SECTION("test3") {
    double num0(1.0);
    Query var0(num0);
  }

  SECTION("test4") {
    double num0(1.5);
    Query var0(num0);
  }

  SECTION("test5") {
    double num0(-0.5);
    Query var0(num0);
  }

  SECTION("test6") {
    double num0(67498.89278);
    Query var0(num0);
  }

  SECTION("test7") {
    double num0(1234567890);
    Query var0(num0);
  }

  SECTION("test8") {
    double num0(-73850380122423);
    Query var0(num0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    std::string src0("NUMBER", 6);
    Query var0(src0);
  }

  SECTION("test11") {
    std::string src0("1", 1);
    Query var0(src0);
  }

  SECTION("test12") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test13") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("int_cmp", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test14") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("int_cmp", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test15") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("float_cmp", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
