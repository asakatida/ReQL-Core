// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test that return_changes fails gracefully.", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("inserted", 8);
    Query var1(src1);

    double num2(99);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    double num0(40);
    Query var0(num0);
  }

  SECTION("test2") {
    Types::array arr0(1);

    std::string src1("Too many changes, array truncated to 40.", 40);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }
}
