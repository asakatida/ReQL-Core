// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Test pseudo literal strings in JSON.", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    Types::object map2;

    std::string src3("b", 1);
    Query var3(src3);

    double num4(2);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
