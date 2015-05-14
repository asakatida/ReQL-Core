// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Regression tests for issue", "[cpp][ast]") {

  SECTION("test0") {
    Result var0;
  }

  SECTION("test1") {
    std::vector<Result> arr0(2);

    std::string src1("rethinkdb", 9);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    std::string src2("test", 4);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    Result var0(arr0);
  }

  SECTION("test2") {
    std::vector<Result> arr0(1);

    std::string src1("t370", 4);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test3") {
    Result var0;
  }
}
