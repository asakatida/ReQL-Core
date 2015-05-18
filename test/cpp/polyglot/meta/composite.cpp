// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Tests meta operations in composite queries", "[cpp][ast]") {

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

    std::string src1("config_changes", 14);
    Query var1(src1);

    Types::object map2;

    std::string src3("func", 4);
    Query var3(src3);

    std::string src4("arrlen", 6);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    std::string src5("dbs_created", 11);
    Query var5(src5);

    double num6(3);
    Query var6(num6);

    map0.insert({src5, var6});

    Query var0(map0);
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

  SECTION("test3") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("func", 4);
    Query var1(src1);

    std::string src2("partial", 7);
    Query var2(src2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
