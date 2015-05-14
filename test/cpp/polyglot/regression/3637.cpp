// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test that negative zero and positive zero refer to the same row", "[cpp][ast]") {

  SECTION("test0") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test1") {
    Result var0;
  }

  SECTION("test2") {
    Result var0;
  }

  SECTION("test3") {
    Result var0;
  }

  SECTION("test4") {
    Result var0;
  }

  SECTION("test5") {
    std::string src0("{\"id\":0}", 10);
    Result var0(src0);
  }

  SECTION("test6") {
    std::string src0("{\"id\":0}", 10);
    Result var0(src0);
  }

  SECTION("test7") {
    std::string src0("{\"id\":[1,-0.0]}", 17);
    Result var0(src0);
  }

  SECTION("test8") {
    std::string src0("{\"id\":[1,-0.0]}", 17);
    Result var0(src0);
  }

  SECTION("test9") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }

  SECTION("test10") {
    std::map<std::string, Result> map0;

    std::string src1("func", 4);
    Result var1(src1);

    std::string src2("partial", 7);
    Result var2(src2);

    map0.insert({src1, var2});

    Result var0(map0);
  }
}
