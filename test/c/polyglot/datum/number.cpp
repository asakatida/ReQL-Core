// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests of conversion to and from the RQL number type", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1);
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -0.5);
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 67498.89278);
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1234567890);
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -73850380122423);
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "result";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "blank";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "NUMBER";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[1]);
    const uint8_t src0[] = "1";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "int_cmp";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "int_cmp";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[9]);
    const uint8_t src2[] = "float_cmp";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
