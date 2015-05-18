// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp Regression test for issue", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("reql_ast_obj", 12);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("reql_ast_obj", 12);
    Result var3(src3);

    std::string src4("TableListTL", 11);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("reql_ast_obj", 12);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("reql_ast_obj", 12);
    Result var3(src3);

    std::string src4("TableCreateTL", 13);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test2") {
    std::map<std::string, Result> map0;

    std::string src1("reql_ast_obj", 12);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("reql_ast_obj", 12);
    Result var3(src3);

    std::string src4("TableDropTL", 11);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("reql_ast_obj", 12);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("reql_ast_obj", 12);
    Result var3(src3);

    std::string src4("TableList", 9);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::map<std::string, Result> map0;

    std::string src1("reql_ast_obj", 12);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("reql_ast_obj", 12);
    Result var3(src3);

    std::string src4("TableCreate", 11);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test5") {
    std::map<std::string, Result> map0;

    std::string src1("reql_ast_obj", 12);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("reql_ast_obj", 12);
    Result var3(src3);

    std::string src4("TableDrop", 9);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
