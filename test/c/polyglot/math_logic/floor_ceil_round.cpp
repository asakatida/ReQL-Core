// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c tests for `floor`, `ceil`, and `round`, tests inspired by the Python test suite", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "NUMBER";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0.0);
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1.0);
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1.0);
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -2.0);
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

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
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 2.0);
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0.0);
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1.0);
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1.0);
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test20") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "NUMBER";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test24") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1.0);
  }

  SECTION("test25") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0.0);
  }

  SECTION("test26") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test27") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 10.0);
  }

  SECTION("test28") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1000000000.0);
  }

  SECTION("test29") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1e+20);
  }

  SECTION("test30") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1.0);
  }

  SECTION("test31") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -10.0);
  }

  SECTION("test32") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1000000000.0);
  }

  SECTION("test33") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1e+20);
  }

  SECTION("test34") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0.0);
  }

  SECTION("test35") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test36") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 10.0);
  }

  SECTION("test37") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1000000000.0);
  }

  SECTION("test38") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1.0);
  }

  SECTION("test39") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -10.0);
  }

  SECTION("test40") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1000000000.0);
  }

  SECTION("test41") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.0);
  }

  SECTION("test42") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 10.0);
  }

  SECTION("test43") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1000000000.0);
  }

  SECTION("test44") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1.0);
  }

  SECTION("test45") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -10.0);
  }

  SECTION("test46") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1000000000.0);
  }

  SECTION("test47") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
