// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Regression test for issue 220", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("self", 4);
    Query var1(src1);

    std::string src2("foo", 3);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("self", 4);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("a", 1);
    Query var1(src1);

    Types::object map2;

    std::string src3("self", 4);
    Query var3(src3);

    double num4(1);
    Query var4(num4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("self", 4);
    Query var1(src1);

    Types::object map2;

    std::string src3("self", 4);
    Query var3(src3);

    Types::object map4;

    std::string src5("self", 4);
    Query var5(src5);

    double num6(1);
    Query var6(num6);

    map4.insert({src5, var6});

    Query var4(map4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
