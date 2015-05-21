// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test the native shims.", "[c][ast]") {

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[29]);
    const uint8_t src0[] = "2013-07-29T18:21:36.680-07:00";
    reql_string_init(var0.get(), buf0.get(), 29);
    reql_string_append(var0.get(), src0, 29);
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[29]);
    const uint8_t src0[] = "2013-07-30T01:21:36.680+00:00";
    reql_string_init(var0.get(), buf0.get(), 29);
    reql_string_append(var0.get(), src0, 29);
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_number_init(var0.get(), 1375147296.68);
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_number_init(var0.get(), 1375147296.68);
  }
}
