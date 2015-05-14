// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Tests key sorting of all usable types in secondary indexes", "[cpp][ast]") {

  SECTION("test8") {
    double num0(28);
    Result var0(num0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("created", 7);
    Result var1(src1);

    double num2(1);
    Result var2(num2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test10") {
    std::vector<Result> arr0(1);

    std::map<std::string, Result> map1;

    std::string src2("ready", 5);
    Result var2(src2);

    Result var3(true);

    map1.insert({src2, var3});

    std::string src4("index", 5);
    Result var4(src4);

    std::string src5("idx", 3);
    Result var5(src5);

    map1.insert({src4, var5});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }

  SECTION("test11") {
    Result var0(true);
  }

  SECTION("test12") {
    Result var0(true);
  }

  SECTION("test13") {
    std::vector<Result> arr0(3);

    double num1(2);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    double num2(3);
    Result var2(num2);

    arr0.insert(arr0.end(), var2);

    double num3(4);
    Result var3(num3);

    arr0.insert(arr0.end(), var3);

    Result var0(arr0);
  }

  SECTION("test14") {
    std::vector<Result> arr0(1);

    double num1(3);
    Result var1(num1);

    arr0.insert(arr0.end(), var1);

    Result var0(arr0);
  }
}
