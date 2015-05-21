// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests key sorting of all usable types in primary indexes", "[cpp][ast]") {

  SECTION("test4") {
    double num0(18);
    Query var0(num0);
  }

  SECTION("test5") {
    Query var0(true);
  }

  SECTION("test6") {
    Query var0(true);
  }

  SECTION("test7") {
    Types::array arr0(3);

    double num1(2);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Query var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Query var3(num3);

    arr0.insert(arr0.end(), var3);

    Query var0(arr0);
  }

  SECTION("test8") {
    Types::array arr0(1);

    double num1(3);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }
}
