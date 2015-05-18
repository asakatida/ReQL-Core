// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests key sorting of all usable types in primary indexes", "[cpp][ast]") {

  SECTION("test4") {
    double num0(18);
    Result var0(num0);
  }

  SECTION("test5") {
    Result var0(true);
  }

  SECTION("test6") {
    Result var0(true);
  }

  SECTION("test7") {
    std::vector<Result> arr0(3);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test8") {
    std::vector<Result> arr0(1);

    double num1(3);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }
}
