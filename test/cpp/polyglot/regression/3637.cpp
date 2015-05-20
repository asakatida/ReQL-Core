// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Test that negative zero and positive zero refer to the same row", "[cpp][ast]") {

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
    Types::object map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("abc", 3);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("id", 2);
    Query var1(src1);

    double num2(0.0);
    Query var2(num2);

    map0.insert({src1, var2});

    std::string src3("value", 5);
    Query var3(src3);

    std::string src4("abc", 3);
    Query var4(src4);

    map0.insert({src3, var4});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("id", 2);
    Query var1(src1);

    Types::array arr2(2);

    double num3(1);
    Query var3(num3);

    arr2.insert(arr2.end(), var3);

    double num4(-0.0);
    Query var4(num4);

    arr2.insert(arr2.end(), var4);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src5("value", 5);
    Query var5(src5);

    std::string src6("def", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("id", 2);
    Query var1(src1);

    Types::array arr2(2);

    double num3(1);
    Query var3(num3);

    arr2.insert(arr2.end(), var3);

    double num4(-0.0);
    Query var4(num4);

    arr2.insert(arr2.end(), var4);

    Query var2(arr2);

    map0.insert({src1, var2});

    std::string src5("value", 5);
    Query var5(src5);

    std::string src6("def", 3);
    Query var6(src6);

    map0.insert({src5, var6});

    Query var0(map0);
  }

  SECTION("test5") {
    std::string src0("{\"id\":0}", 10);
    Query var0(src0);
  }

  SECTION("test6") {
    std::string src0("{\"id\":0}", 10);
    Query var0(src0);
  }

  SECTION("test7") {
    std::string src0("{\"id\":[1,-0.0]}", 17);
    Query var0(src0);
  }

  SECTION("test8") {
    std::string src0("{\"id\":[1,-0.0]}", 17);
    Query var0(src0);
  }

  SECTION("test9") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test10") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
