// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Regression test for issue 2696, delete_at with end bounds.", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }
}
