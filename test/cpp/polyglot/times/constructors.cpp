// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test basic time arithmetic", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("reql_ast_obj", 12);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("reql_ast_obj", 12);
    Result var3(src3);

    std::string src4("datetime", 8);
    Result var4(src4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
    std::map<std::string, Result> map0;

    std::string src1("more", 4);
    Result var1(src1);

    std::vector<Result> arr2(1);

    std::map<std::string, Result> map3;

    std::string src4("reql_ast_obj", 12);
    Result var4(src4);

    std::map<std::string, Result> map5;

    std::string src6("reql_ast_obj", 12);
    Result var6(src6);

    std::string src7("datetime", 8);
    Result var7(src7);

    map5.insert({src6, var7});

    Result var5(map5);

    map3.insert({src4, var5});

    Result var3(map3);

    arr2.insert(arr2.end(), var3);

    Result var2(arr2);

    map0.insert({src1, var2});

    std::string src8("stuff", 5);
    Result var8(src8);

    std::map<std::string, Result> map9;

    std::string src10("reql_ast_obj", 12);
    Result var10(src10);

    std::map<std::string, Result> map11;

    std::string src12("reql_ast_obj", 12);
    Result var12(src12);

    std::string src13("datetime", 8);
    Result var13(src13);

    map11.insert({src12, var13});

    Result var11(map11);

    map9.insert({src10, var11});

    Result var9(map9);

    map0.insert({src8, var9});

    Result var0(map0);
  }

  SECTION("test2") {
    std::vector<Result> arr0(3);

    std::map<std::string, Result> map1;

    std::string src2("reql_ast_obj", 12);
    Result var2(src2);

    std::map<std::string, Result> map3;

    std::string src4("reql_ast_obj", 12);
    Result var4(src4);

    std::string src5("datetime", 8);
    Result var5(src5);

    map3.insert({src4, var5});

    Result var3(map3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map6;

    std::string src7("reql_ast_obj", 12);
    Result var7(src7);

    std::map<std::string, Result> map8;

    std::string src9("reql_ast_obj", 12);
    Result var9(src9);

    std::string src10("datetime", 8);
    Result var10(src10);

    map8.insert({src9, var10});

    Result var8(map8);

    map6.insert({src7, var8});

    Result var6(map6);

    arr0.insert(arr0.end(), var6);

    std::map<std::string, Result> map11;

    std::string src12("stuff", 5);
    Result var12(src12);

    std::map<std::string, Result> map13;

    std::string src14("reql_ast_obj", 12);
    Result var14(src14);

    std::map<std::string, Result> map15;

    std::string src16("reql_ast_obj", 12);
    Result var16(src16);

    std::string src17("datetime", 8);
    Result var17(src17);

    map15.insert({src16, var17});

    Result var15(map15);

    map13.insert({src14, var15});

    Result var13(map13);

    map11.insert({src12, var13});

    Result var11(map11);

    arr0.insert(arr0.end(), var11);

    Result var0(arr0);
  }

  SECTION("test3") {
    std::map<std::string, Result> map0;

    std::string src1("nested", 6);
    Result var1(src1);

    std::map<std::string, Result> map2;

    std::string src3("time", 4);
    Result var3(src3);

    std::map<std::string, Result> map4;

    std::string src5("reql_ast_obj", 12);
    Result var5(src5);

    std::map<std::string, Result> map6;

    std::string src7("reql_ast_obj", 12);
    Result var7(src7);

    std::string src8("datetime", 8);
    Result var8(src8);

    map6.insert({src7, var8});

    Result var6(map6);

    map4.insert({src5, var6});

    Result var4(map4);

    map2.insert({src3, var4});

    Result var2(map2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test4") {
    std::vector<Result> arr0(3);

    double num1(1);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    std::string src2("two", 3);
    Result var2(src2);

    arr0.insert(arr0.end(), var2);

    std::vector<Result> arr3(3);

    std::string src4("a", 1);
    Result var4(src4);

    arr3.insert(arr3.end(), var4);

    std::map<std::string, Result> map5;

    std::string src6("reql_ast_obj", 12);
    Result var6(src6);

    std::map<std::string, Result> map7;

    std::string src8("reql_ast_obj", 12);
    Result var8(src8);

    std::string src9("datetime", 8);
    Result var9(src9);

    map7.insert({src8, var9});

    Result var7(map7);

    map5.insert({src6, var7});

    Result var5(map5);

    arr3.insert(arr3.end(), var5);

    double num10(3);
    Result var10(num10);

    arr3.insert(arr3.end(), var10);

    Result var3(arr3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test5") {
    double num0(1);
    Result var0(num0);
  }

  SECTION("test6") {
    double num0(-1);
    Result var0(num0);
  }

  SECTION("test7") {
    double num0(1.444);
    Result var0(num0);
  }

  SECTION("test8") {
    std::string src0("1970-01-01T00:00:01.444+00:00", 29);
    Result var0(src0);
  }

  SECTION("test9") {
    double num0(1.444);
    Result var0(num0);
  }

  SECTION("test10") {
    double num0(10000);
    Result var0(num0);
  }

  SECTION("test11") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test12") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test13") {
    double num0(253440000000);
    Result var0(num0);
  }

  SECTION("test14") {
    double num0(1400);
    Result var0(num0);
  }

  SECTION("test15") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("err", 3);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test16") {
    double num0(-17990000000);
    Result var0(num0);
  }
}
