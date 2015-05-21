// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Issue", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::array arr0(1);

    std::string src1("46", 2);
    Query var1(src1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
