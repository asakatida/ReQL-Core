// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp 2697 -- Array insert and splice operations don't check array size limit.", "[cpp][ast]") {

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("inserted", 8);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("first_error", 11);
    Result var1(src1);

    std::string src2("Array over size limit `100000`.", 31);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    double num0(100000);
    Result var0(num0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("first_error", 11);
    Result var1(src1);

    std::string src2("Array over size limit `100000`.", 31);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    double num0(100000);
    Result var0(num0);
  }

  SECTION("test6") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test7") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
