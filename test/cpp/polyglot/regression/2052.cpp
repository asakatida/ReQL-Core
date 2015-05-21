// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp 2052 -- Verify that the server rejects bogus global options.", "[cpp][ast]") {

  SECTION("test0") {
    double num0(1);
    Query var0(num0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
