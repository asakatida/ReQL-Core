// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Regression test for issue", "[cpp][ast]") {

  SECTION("test0") {
    Types::object map0;

    std::string src1("reql_ast_obj", 12);
    Query var1(src1);

    Types::object map2;

    std::string src3("reql_ast_obj", 12);
    Query var3(src3);

    std::string src4("TableListTL", 11);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test1") {
    Types::object map0;

    std::string src1("reql_ast_obj", 12);
    Query var1(src1);

    Types::object map2;

    std::string src3("reql_ast_obj", 12);
    Query var3(src3);

    std::string src4("TableCreateTL", 13);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test2") {
    Types::object map0;

    std::string src1("reql_ast_obj", 12);
    Query var1(src1);

    Types::object map2;

    std::string src3("reql_ast_obj", 12);
    Query var3(src3);

    std::string src4("TableDropTL", 11);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test3") {
    Types::object map0;

    std::string src1("reql_ast_obj", 12);
    Query var1(src1);

    Types::object map2;

    std::string src3("reql_ast_obj", 12);
    Query var3(src3);

    std::string src4("TableList", 9);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test4") {
    Types::object map0;

    std::string src1("reql_ast_obj", 12);
    Query var1(src1);

    Types::object map2;

    std::string src3("reql_ast_obj", 12);
    Query var3(src3);

    std::string src4("TableCreate", 11);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }

  SECTION("test5") {
    Types::object map0;

    std::string src1("reql_ast_obj", 12);
    Query var1(src1);

    Types::object map2;

    std::string src3("reql_ast_obj", 12);
    Query var3(src3);

    std::string src4("TableDrop", 9);
    Query var4(src4);

    map2.insert({src3, var4});

    Query var2(map2);

    map0.insert({src1, var2});

    Query var0(map0);
  }
}
