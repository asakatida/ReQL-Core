// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c 2709 -- Guarantee failed with [max_els >= min_els]", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[8]);
    const uint8_t src1[] = "inserted";
    reql_string_init(var1.get(), buf1.get(), 8);
    reql_string_append(var1.get(), src1, 8);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 999);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 999);
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 999);
  }
}
