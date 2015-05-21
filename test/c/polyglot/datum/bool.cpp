// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests of conversion to and from the RQL bool type", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[4]);
    const uint8_t src0[] = "BOOL";
    reql_string_init(var0.get(), buf0.get(), 4);
    reql_string_append(var0.get(), src0, 4);
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[4]);
    const uint8_t src0[] = "true";
    reql_string_init(var0.get(), buf0.get(), 4);
    reql_string_append(var0.get(), src0, 4);
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 1);
  }
}
