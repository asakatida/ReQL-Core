// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp 2052 -- Verify that the server rejects bogus global options.", "[cpp][ast]") {

  SECTION("test0") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}