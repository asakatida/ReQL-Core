// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests key sorting of all usable types in primary indexes", "[c][ast]") {

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_number_init(var0.get(), 18);
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }
}
