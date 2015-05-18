// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Test cleanup of cursors on the server", "[cpp][ast]") {

  SECTION("test0") {
    std::vector<Result> arr0(1);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test1") {
    Result var0;
  }

  SECTION("test2") {
    Result var0;
  }

  SECTION("test3") {
    std::vector<Result> arr0(1);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }
}
