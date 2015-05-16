// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Skip after orderby causes use-after-free (#522)", "[cpp][ast]") {

  SECTION("test0") {
    Result var0;
  }

  SECTION("test1") {
    std::vector<Result> arr0(2);

    std::map<std::string, Result> map1;

    std::string src2("id", 2);
    Result var2(src2);

    double num3(1);
    Result var3(num3);

    map1.insert({src2, var3});

    Result var1(map1);

    arr0.insert(arr0.end(), var1);

    std::map<std::string, Result> map4;

    std::string src5("id", 2);
    Result var5(src5);

    double num6(2);
    Result var6(num6);

    map4.insert({src5, var6});

    Result var4(map4);

    arr0.insert(arr0.end(), var4);

    Result var0(arr0);
  }
}