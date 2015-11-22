// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test cleanup of cursors on the server", "[cpp][ast]") {

  SECTION("test0") {
    std::vector<Query> arr0(1);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test1") {
    Query var0;
  }

  SECTION("test2") {
    Query var0;
  }

  SECTION("test3") {
    std::vector<Query> arr0(1);

    double num1(1);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }
}
