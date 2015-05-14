// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Regression test for issue 2696, delete_at with end bounds.", "[cpp][ast]") {

  SECTION("test0") {
    std::vector<Result> arr0(4);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(2);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(3);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    double num4(4);
    Result var4(num4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }

  SECTION("test1") {
    std::vector<Result> arr0;
    Result var0(arr0);
  }
}
