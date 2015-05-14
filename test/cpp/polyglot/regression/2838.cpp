// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test that return_changes fails gracefully.", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("inserted", 8);
    Result var1(src1);

    double num2(99);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
    double num0(40);
    Result var0(num0);
  }

  SECTION("test2") {
    std::vector<Result> arr0(1);

    std::string src1("Too many changes, array truncated to 40.", 40);
    Result var1(src1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }
}
