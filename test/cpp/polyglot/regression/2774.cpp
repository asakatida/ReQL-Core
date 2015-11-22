// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests key sorting of all usable types in secondary indexes", "[cpp][ast]") {

  SECTION("test8") {
    double num0(28);
    Query var0(num0);
  }

  SECTION("test9") {
    std::map<std::string, Query> map0;

    std::string src1("created", 7);
    Query var1(src1);

    double num2(1);
    Query var2(num2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    std::vector<Query> arr0(1);

    std::map<std::string, Query> map1;

    std::string src2("index", 5);
    Query var2(src2);

    std::string src3("idx", 3);
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

  SECTION("test11") {
    Query var0(true);
  }

  SECTION("test12") {
    Query var0(true);
  }

  SECTION("test13") {
    std::vector<Query> arr0(3);

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

  SECTION("test14") {
    std::vector<Query> arr0(1);

    double num1(3);
    Query var1(num1);

    arr0.insert(arr0.end(), var1);

    Query var0(arr0);
  }
}
