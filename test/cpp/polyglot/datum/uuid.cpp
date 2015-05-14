// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp Test that UUIDs work", "[cpp][ast]") {

  SECTION("test0") {
    Result var0;
  }

  SECTION("test1") {
    Result var0;
  }

  SECTION("test2") {
    std::string src0("STRING", 6);
    Result var0(src0);
  }

  SECTION("test3") {
    Result var0(true);
  }

  SECTION("test4") {
    double num0(10);
    Result var0(num0);
  }
}
