// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.h"

#include <memory>

TEST_CASE("c Tests of nested arithmetic expressions", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }
}
