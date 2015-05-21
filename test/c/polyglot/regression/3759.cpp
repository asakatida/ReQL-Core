// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test cleanup of cursors on the server", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_null_init(var0.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_null_init(var0.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());
  }
}
