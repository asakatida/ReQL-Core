// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp These tests test the type of command", "[cpp][ast]") {

  SECTION("test0") {
    std::string src0("NULL", 4);
    Result var0(src0);
  }

  SECTION("test1") {
    std::string src0("NULL", 4);
    Result var0(src0);
  }
}
