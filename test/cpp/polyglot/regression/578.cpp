// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Catch obvious sindex creation/dropping errors (#578)", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::array arr0(1);

    Types::object map1;

    std::string src2("index", 5);
    Query var2(src2);

    std::string src3("578", 3);
    Query var3(src3);

    map1.insert({src2, var3});

    std::string src4("ready", 5);
    Query var4(src4);

    Query var5(true);

    map1.insert({src4, var5});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err_regex", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("dropped", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("err_regex", 9);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
