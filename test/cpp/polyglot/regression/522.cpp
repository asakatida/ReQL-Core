// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Skip after orderby causes use-after-free (#522)", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("result", 6);
    Query var1(src1);

    std::string src2("blank", 5);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::array arr0(2);

    Types::object map1;

    std::string src2("id", 2);
    Query var2(src2);

    double num3(1);
    Query var3(num3);

    map1.insert({src2, var3});

    Query var1(map1);

    arr0.insert(arr0.end(), var1);

    Types::object map4;

    std::string src5("id", 2);
    Query var5(src5);

    double num6(2);
    Query var6(num6);

    map4.insert({src5, var6});

    Query var4(map4);

    arr0.insert(arr0.end(), var4);

    Query var0(arr0);
  }
}
