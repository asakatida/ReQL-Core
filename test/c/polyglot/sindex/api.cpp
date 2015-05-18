// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c sindex api (#602)", "[c][ast]") {

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 4);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test4") {
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
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test5") {
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
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
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

  SECTION("test7") {
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

  SECTION("test8") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

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
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "bag";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test20") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "index";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[15]);
    const uint8_t src3[] = "rename-last-dup";
    reql_string_init(var3.get(), buf3.get(), 15);
    reql_string_append(var3.get(), src3, 15);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[5]);
    const uint8_t src4[] = "ready";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    ReQL_Obj_c var5;
    reql_bool_init(var5.get(), 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "dropped";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test24") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "rename-last";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test25") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "dropped";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test26") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test27") {
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
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test28") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test29") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test30") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test31") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test32") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test33") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test34") {
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

  SECTION("test35") {
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

  SECTION("test36") {
    ReQL_Obj_c var0;
    reql_null_init(var0.get());
  }

  SECTION("test37") {
    ReQL_Obj_c var0;
    reql_null_init(var0.get());
  }

  SECTION("test38") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test39") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<OBJECT>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test40") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test41") {
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

  SECTION("test42") {
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

  SECTION("test43") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test44") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test45") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test46") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test47") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test48") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test49") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test50") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test51") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test52") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test53") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test54") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 3);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test55") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 3);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test56") {
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
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test57") {
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

  SECTION("test58") {
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

  SECTION("test59") {
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

  SECTION("test60") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test61") {
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

  SECTION("test62") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test63") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test64") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test65") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test66") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test67") {
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

  SECTION("test68") {
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

  SECTION("test69") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test70") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test71") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test72") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test73") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "Bracket";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test74") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "Bracket";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test75") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "Bracket";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test76") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "Bracket";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test77") {
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
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test78") {
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

  SECTION("test79") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test80") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test81") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test82") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test83") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test84") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test85") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test86") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[4]);
    const uint8_t src15[] = "left";
    reql_string_init(var15.get(), buf15.get(), 4);
    reql_string_append(var15.get(), src15, 4);

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    ReQL_Obj_c var18;
    _C::CTypes::pairs pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[5]);
    const uint8_t src21[] = "right";
    reql_string_init(var21.get(), buf21.get(), 5);
    reql_string_append(var21.get(), src21, 5);

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    ReQL_Obj_c var24;
    _C::CTypes::pairs pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    ReQL_Obj_c var27;
    _C::CTypes::pairs pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    ReQL_Obj_c var28;
    _C::CTypes::string buf28(new uint8_t[4]);
    const uint8_t src28[] = "left";
    reql_string_init(var28.get(), buf28.get(), 4);
    reql_string_append(var28.get(), src28, 4);

    ReQL_Obj_c var29;
    _C::CTypes::pairs pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    ReQL_Obj_c var30;
    _C::CTypes::string buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    ReQL_Obj_c var31;
    _C::CTypes::pairs pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    ReQL_Obj_c var32;
    _C::CTypes::string buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    ReQL_Obj_c var34;
    _C::CTypes::string buf34(new uint8_t[5]);
    const uint8_t src34[] = "right";
    reql_string_init(var34.get(), buf34.get(), 5);
    reql_string_append(var34.get(), src34, 5);

    ReQL_Obj_c var35;
    _C::CTypes::pairs pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    ReQL_Obj_c var36;
    _C::CTypes::string buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    ReQL_Obj_c var37;
    _C::CTypes::pairs pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    ReQL_Obj_c var38;
    _C::CTypes::string buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    ReQL_Obj_c var39;
    _C::CTypes::string buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());

    ReQL_Obj_c var40;
    _C::CTypes::pairs pair40(new ReQL_Pair_t[2]);
    reql_object_init(var40.get(), pair40.get(), 2);

    ReQL_Obj_c var41;
    _C::CTypes::string buf41(new uint8_t[4]);
    const uint8_t src41[] = "left";
    reql_string_init(var41.get(), buf41.get(), 4);
    reql_string_append(var41.get(), src41, 4);

    ReQL_Obj_c var42;
    _C::CTypes::pairs pair42(new ReQL_Pair_t[1]);
    reql_object_init(var42.get(), pair42.get(), 1);

    ReQL_Obj_c var43;
    _C::CTypes::string buf43(new uint8_t[12]);
    const uint8_t src43[] = "reql_ast_obj";
    reql_string_init(var43.get(), buf43.get(), 12);
    reql_string_append(var43.get(), src43, 12);

    ReQL_Obj_c var44;
    _C::CTypes::pairs pair44(new ReQL_Pair_t[1]);
    reql_object_init(var44.get(), pair44.get(), 1);

    ReQL_Obj_c var45;
    _C::CTypes::string buf45(new uint8_t[12]);
    const uint8_t src45[] = "reql_ast_obj";
    reql_string_init(var45.get(), buf45.get(), 12);
    reql_string_append(var45.get(), src45, 12);

    ReQL_Obj_c var46;
    _C::CTypes::string buf46(new uint8_t[7]);
    const uint8_t src46[] = "Bracket";
    reql_string_init(var46.get(), buf46.get(), 7);
    reql_string_append(var46.get(), src46, 7);

    reql_object_add(var44.get(), var45.get(), var46.get());

    reql_object_add(var42.get(), var43.get(), var44.get());

    reql_object_add(var40.get(), var41.get(), var42.get());

    ReQL_Obj_c var47;
    _C::CTypes::string buf47(new uint8_t[5]);
    const uint8_t src47[] = "right";
    reql_string_init(var47.get(), buf47.get(), 5);
    reql_string_append(var47.get(), src47, 5);

    ReQL_Obj_c var48;
    _C::CTypes::pairs pair48(new ReQL_Pair_t[1]);
    reql_object_init(var48.get(), pair48.get(), 1);

    ReQL_Obj_c var49;
    _C::CTypes::string buf49(new uint8_t[12]);
    const uint8_t src49[] = "reql_ast_obj";
    reql_string_init(var49.get(), buf49.get(), 12);
    reql_string_append(var49.get(), src49, 12);

    ReQL_Obj_c var50;
    _C::CTypes::pairs pair50(new ReQL_Pair_t[1]);
    reql_object_init(var50.get(), pair50.get(), 1);

    ReQL_Obj_c var51;
    _C::CTypes::string buf51(new uint8_t[12]);
    const uint8_t src51[] = "reql_ast_obj";
    reql_string_init(var51.get(), buf51.get(), 12);
    reql_string_append(var51.get(), src51, 12);

    ReQL_Obj_c var52;
    _C::CTypes::string buf52(new uint8_t[7]);
    const uint8_t src52[] = "Bracket";
    reql_string_init(var52.get(), buf52.get(), 7);
    reql_string_append(var52.get(), src52, 7);

    reql_object_add(var50.get(), var51.get(), var52.get());

    reql_object_add(var48.get(), var49.get(), var50.get());

    reql_object_add(var40.get(), var47.get(), var48.get());

    reql_array_append(var0.get(), var40.get());
  }

  SECTION("test87") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[4]);
    const uint8_t src15[] = "left";
    reql_string_init(var15.get(), buf15.get(), 4);
    reql_string_append(var15.get(), src15, 4);

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    ReQL_Obj_c var18;
    _C::CTypes::pairs pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[5]);
    const uint8_t src21[] = "right";
    reql_string_init(var21.get(), buf21.get(), 5);
    reql_string_append(var21.get(), src21, 5);

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    ReQL_Obj_c var24;
    _C::CTypes::pairs pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    ReQL_Obj_c var27;
    _C::CTypes::pairs pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    ReQL_Obj_c var28;
    _C::CTypes::string buf28(new uint8_t[4]);
    const uint8_t src28[] = "left";
    reql_string_init(var28.get(), buf28.get(), 4);
    reql_string_append(var28.get(), src28, 4);

    ReQL_Obj_c var29;
    _C::CTypes::pairs pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    ReQL_Obj_c var30;
    _C::CTypes::string buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    ReQL_Obj_c var31;
    _C::CTypes::pairs pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    ReQL_Obj_c var32;
    _C::CTypes::string buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    ReQL_Obj_c var34;
    _C::CTypes::string buf34(new uint8_t[5]);
    const uint8_t src34[] = "right";
    reql_string_init(var34.get(), buf34.get(), 5);
    reql_string_append(var34.get(), src34, 5);

    ReQL_Obj_c var35;
    _C::CTypes::pairs pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    ReQL_Obj_c var36;
    _C::CTypes::string buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    ReQL_Obj_c var37;
    _C::CTypes::pairs pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    ReQL_Obj_c var38;
    _C::CTypes::string buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    ReQL_Obj_c var39;
    _C::CTypes::string buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());
  }

  SECTION("test88") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[4]);
    const uint8_t src15[] = "left";
    reql_string_init(var15.get(), buf15.get(), 4);
    reql_string_append(var15.get(), src15, 4);

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    ReQL_Obj_c var18;
    _C::CTypes::pairs pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[5]);
    const uint8_t src21[] = "right";
    reql_string_init(var21.get(), buf21.get(), 5);
    reql_string_append(var21.get(), src21, 5);

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    ReQL_Obj_c var24;
    _C::CTypes::pairs pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());
  }

  SECTION("test89") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test90") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[8]);
    reql_array_init(var0.get(), arr0.get(), 8);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[4]);
    const uint8_t src15[] = "left";
    reql_string_init(var15.get(), buf15.get(), 4);
    reql_string_append(var15.get(), src15, 4);

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    ReQL_Obj_c var18;
    _C::CTypes::pairs pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[5]);
    const uint8_t src21[] = "right";
    reql_string_init(var21.get(), buf21.get(), 5);
    reql_string_append(var21.get(), src21, 5);

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    ReQL_Obj_c var24;
    _C::CTypes::pairs pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    ReQL_Obj_c var27;
    _C::CTypes::pairs pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    ReQL_Obj_c var28;
    _C::CTypes::string buf28(new uint8_t[4]);
    const uint8_t src28[] = "left";
    reql_string_init(var28.get(), buf28.get(), 4);
    reql_string_append(var28.get(), src28, 4);

    ReQL_Obj_c var29;
    _C::CTypes::pairs pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    ReQL_Obj_c var30;
    _C::CTypes::string buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    ReQL_Obj_c var31;
    _C::CTypes::pairs pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    ReQL_Obj_c var32;
    _C::CTypes::string buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    ReQL_Obj_c var34;
    _C::CTypes::string buf34(new uint8_t[5]);
    const uint8_t src34[] = "right";
    reql_string_init(var34.get(), buf34.get(), 5);
    reql_string_append(var34.get(), src34, 5);

    ReQL_Obj_c var35;
    _C::CTypes::pairs pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    ReQL_Obj_c var36;
    _C::CTypes::string buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    ReQL_Obj_c var37;
    _C::CTypes::pairs pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    ReQL_Obj_c var38;
    _C::CTypes::string buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    ReQL_Obj_c var39;
    _C::CTypes::string buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());

    ReQL_Obj_c var40;
    _C::CTypes::pairs pair40(new ReQL_Pair_t[2]);
    reql_object_init(var40.get(), pair40.get(), 2);

    ReQL_Obj_c var41;
    _C::CTypes::string buf41(new uint8_t[4]);
    const uint8_t src41[] = "left";
    reql_string_init(var41.get(), buf41.get(), 4);
    reql_string_append(var41.get(), src41, 4);

    ReQL_Obj_c var42;
    _C::CTypes::pairs pair42(new ReQL_Pair_t[1]);
    reql_object_init(var42.get(), pair42.get(), 1);

    ReQL_Obj_c var43;
    _C::CTypes::string buf43(new uint8_t[12]);
    const uint8_t src43[] = "reql_ast_obj";
    reql_string_init(var43.get(), buf43.get(), 12);
    reql_string_append(var43.get(), src43, 12);

    ReQL_Obj_c var44;
    _C::CTypes::pairs pair44(new ReQL_Pair_t[1]);
    reql_object_init(var44.get(), pair44.get(), 1);

    ReQL_Obj_c var45;
    _C::CTypes::string buf45(new uint8_t[12]);
    const uint8_t src45[] = "reql_ast_obj";
    reql_string_init(var45.get(), buf45.get(), 12);
    reql_string_append(var45.get(), src45, 12);

    ReQL_Obj_c var46;
    _C::CTypes::string buf46(new uint8_t[7]);
    const uint8_t src46[] = "Bracket";
    reql_string_init(var46.get(), buf46.get(), 7);
    reql_string_append(var46.get(), src46, 7);

    reql_object_add(var44.get(), var45.get(), var46.get());

    reql_object_add(var42.get(), var43.get(), var44.get());

    reql_object_add(var40.get(), var41.get(), var42.get());

    ReQL_Obj_c var47;
    _C::CTypes::string buf47(new uint8_t[5]);
    const uint8_t src47[] = "right";
    reql_string_init(var47.get(), buf47.get(), 5);
    reql_string_append(var47.get(), src47, 5);

    ReQL_Obj_c var48;
    _C::CTypes::pairs pair48(new ReQL_Pair_t[1]);
    reql_object_init(var48.get(), pair48.get(), 1);

    ReQL_Obj_c var49;
    _C::CTypes::string buf49(new uint8_t[12]);
    const uint8_t src49[] = "reql_ast_obj";
    reql_string_init(var49.get(), buf49.get(), 12);
    reql_string_append(var49.get(), src49, 12);

    ReQL_Obj_c var50;
    _C::CTypes::pairs pair50(new ReQL_Pair_t[1]);
    reql_object_init(var50.get(), pair50.get(), 1);

    ReQL_Obj_c var51;
    _C::CTypes::string buf51(new uint8_t[12]);
    const uint8_t src51[] = "reql_ast_obj";
    reql_string_init(var51.get(), buf51.get(), 12);
    reql_string_append(var51.get(), src51, 12);

    ReQL_Obj_c var52;
    _C::CTypes::string buf52(new uint8_t[7]);
    const uint8_t src52[] = "Bracket";
    reql_string_init(var52.get(), buf52.get(), 7);
    reql_string_append(var52.get(), src52, 7);

    reql_object_add(var50.get(), var51.get(), var52.get());

    reql_object_add(var48.get(), var49.get(), var50.get());

    reql_object_add(var40.get(), var47.get(), var48.get());

    reql_array_append(var0.get(), var40.get());

    ReQL_Obj_c var53;
    _C::CTypes::pairs pair53(new ReQL_Pair_t[2]);
    reql_object_init(var53.get(), pair53.get(), 2);

    ReQL_Obj_c var54;
    _C::CTypes::string buf54(new uint8_t[4]);
    const uint8_t src54[] = "left";
    reql_string_init(var54.get(), buf54.get(), 4);
    reql_string_append(var54.get(), src54, 4);

    ReQL_Obj_c var55;
    _C::CTypes::pairs pair55(new ReQL_Pair_t[1]);
    reql_object_init(var55.get(), pair55.get(), 1);

    ReQL_Obj_c var56;
    _C::CTypes::string buf56(new uint8_t[12]);
    const uint8_t src56[] = "reql_ast_obj";
    reql_string_init(var56.get(), buf56.get(), 12);
    reql_string_append(var56.get(), src56, 12);

    ReQL_Obj_c var57;
    _C::CTypes::pairs pair57(new ReQL_Pair_t[1]);
    reql_object_init(var57.get(), pair57.get(), 1);

    ReQL_Obj_c var58;
    _C::CTypes::string buf58(new uint8_t[12]);
    const uint8_t src58[] = "reql_ast_obj";
    reql_string_init(var58.get(), buf58.get(), 12);
    reql_string_append(var58.get(), src58, 12);

    ReQL_Obj_c var59;
    _C::CTypes::string buf59(new uint8_t[7]);
    const uint8_t src59[] = "Bracket";
    reql_string_init(var59.get(), buf59.get(), 7);
    reql_string_append(var59.get(), src59, 7);

    reql_object_add(var57.get(), var58.get(), var59.get());

    reql_object_add(var55.get(), var56.get(), var57.get());

    reql_object_add(var53.get(), var54.get(), var55.get());

    ReQL_Obj_c var60;
    _C::CTypes::string buf60(new uint8_t[5]);
    const uint8_t src60[] = "right";
    reql_string_init(var60.get(), buf60.get(), 5);
    reql_string_append(var60.get(), src60, 5);

    ReQL_Obj_c var61;
    _C::CTypes::pairs pair61(new ReQL_Pair_t[1]);
    reql_object_init(var61.get(), pair61.get(), 1);

    ReQL_Obj_c var62;
    _C::CTypes::string buf62(new uint8_t[12]);
    const uint8_t src62[] = "reql_ast_obj";
    reql_string_init(var62.get(), buf62.get(), 12);
    reql_string_append(var62.get(), src62, 12);

    ReQL_Obj_c var63;
    _C::CTypes::pairs pair63(new ReQL_Pair_t[1]);
    reql_object_init(var63.get(), pair63.get(), 1);

    ReQL_Obj_c var64;
    _C::CTypes::string buf64(new uint8_t[12]);
    const uint8_t src64[] = "reql_ast_obj";
    reql_string_init(var64.get(), buf64.get(), 12);
    reql_string_append(var64.get(), src64, 12);

    ReQL_Obj_c var65;
    _C::CTypes::string buf65(new uint8_t[7]);
    const uint8_t src65[] = "Bracket";
    reql_string_init(var65.get(), buf65.get(), 7);
    reql_string_append(var65.get(), src65, 7);

    reql_object_add(var63.get(), var64.get(), var65.get());

    reql_object_add(var61.get(), var62.get(), var63.get());

    reql_object_add(var53.get(), var60.get(), var61.get());

    reql_array_append(var0.get(), var53.get());

    ReQL_Obj_c var66;
    _C::CTypes::pairs pair66(new ReQL_Pair_t[2]);
    reql_object_init(var66.get(), pair66.get(), 2);

    ReQL_Obj_c var67;
    _C::CTypes::string buf67(new uint8_t[4]);
    const uint8_t src67[] = "left";
    reql_string_init(var67.get(), buf67.get(), 4);
    reql_string_append(var67.get(), src67, 4);

    ReQL_Obj_c var68;
    _C::CTypes::pairs pair68(new ReQL_Pair_t[1]);
    reql_object_init(var68.get(), pair68.get(), 1);

    ReQL_Obj_c var69;
    _C::CTypes::string buf69(new uint8_t[12]);
    const uint8_t src69[] = "reql_ast_obj";
    reql_string_init(var69.get(), buf69.get(), 12);
    reql_string_append(var69.get(), src69, 12);

    ReQL_Obj_c var70;
    _C::CTypes::pairs pair70(new ReQL_Pair_t[1]);
    reql_object_init(var70.get(), pair70.get(), 1);

    ReQL_Obj_c var71;
    _C::CTypes::string buf71(new uint8_t[12]);
    const uint8_t src71[] = "reql_ast_obj";
    reql_string_init(var71.get(), buf71.get(), 12);
    reql_string_append(var71.get(), src71, 12);

    ReQL_Obj_c var72;
    _C::CTypes::string buf72(new uint8_t[7]);
    const uint8_t src72[] = "Bracket";
    reql_string_init(var72.get(), buf72.get(), 7);
    reql_string_append(var72.get(), src72, 7);

    reql_object_add(var70.get(), var71.get(), var72.get());

    reql_object_add(var68.get(), var69.get(), var70.get());

    reql_object_add(var66.get(), var67.get(), var68.get());

    ReQL_Obj_c var73;
    _C::CTypes::string buf73(new uint8_t[5]);
    const uint8_t src73[] = "right";
    reql_string_init(var73.get(), buf73.get(), 5);
    reql_string_append(var73.get(), src73, 5);

    ReQL_Obj_c var74;
    _C::CTypes::pairs pair74(new ReQL_Pair_t[1]);
    reql_object_init(var74.get(), pair74.get(), 1);

    ReQL_Obj_c var75;
    _C::CTypes::string buf75(new uint8_t[12]);
    const uint8_t src75[] = "reql_ast_obj";
    reql_string_init(var75.get(), buf75.get(), 12);
    reql_string_append(var75.get(), src75, 12);

    ReQL_Obj_c var76;
    _C::CTypes::pairs pair76(new ReQL_Pair_t[1]);
    reql_object_init(var76.get(), pair76.get(), 1);

    ReQL_Obj_c var77;
    _C::CTypes::string buf77(new uint8_t[12]);
    const uint8_t src77[] = "reql_ast_obj";
    reql_string_init(var77.get(), buf77.get(), 12);
    reql_string_append(var77.get(), src77, 12);

    ReQL_Obj_c var78;
    _C::CTypes::string buf78(new uint8_t[7]);
    const uint8_t src78[] = "Bracket";
    reql_string_init(var78.get(), buf78.get(), 7);
    reql_string_append(var78.get(), src78, 7);

    reql_object_add(var76.get(), var77.get(), var78.get());

    reql_object_add(var74.get(), var75.get(), var76.get());

    reql_object_add(var66.get(), var73.get(), var74.get());

    reql_array_append(var0.get(), var66.get());

    ReQL_Obj_c var79;
    _C::CTypes::pairs pair79(new ReQL_Pair_t[2]);
    reql_object_init(var79.get(), pair79.get(), 2);

    ReQL_Obj_c var80;
    _C::CTypes::string buf80(new uint8_t[4]);
    const uint8_t src80[] = "left";
    reql_string_init(var80.get(), buf80.get(), 4);
    reql_string_append(var80.get(), src80, 4);

    ReQL_Obj_c var81;
    _C::CTypes::pairs pair81(new ReQL_Pair_t[1]);
    reql_object_init(var81.get(), pair81.get(), 1);

    ReQL_Obj_c var82;
    _C::CTypes::string buf82(new uint8_t[12]);
    const uint8_t src82[] = "reql_ast_obj";
    reql_string_init(var82.get(), buf82.get(), 12);
    reql_string_append(var82.get(), src82, 12);

    ReQL_Obj_c var83;
    _C::CTypes::pairs pair83(new ReQL_Pair_t[1]);
    reql_object_init(var83.get(), pair83.get(), 1);

    ReQL_Obj_c var84;
    _C::CTypes::string buf84(new uint8_t[12]);
    const uint8_t src84[] = "reql_ast_obj";
    reql_string_init(var84.get(), buf84.get(), 12);
    reql_string_append(var84.get(), src84, 12);

    ReQL_Obj_c var85;
    _C::CTypes::string buf85(new uint8_t[7]);
    const uint8_t src85[] = "Bracket";
    reql_string_init(var85.get(), buf85.get(), 7);
    reql_string_append(var85.get(), src85, 7);

    reql_object_add(var83.get(), var84.get(), var85.get());

    reql_object_add(var81.get(), var82.get(), var83.get());

    reql_object_add(var79.get(), var80.get(), var81.get());

    ReQL_Obj_c var86;
    _C::CTypes::string buf86(new uint8_t[5]);
    const uint8_t src86[] = "right";
    reql_string_init(var86.get(), buf86.get(), 5);
    reql_string_append(var86.get(), src86, 5);

    ReQL_Obj_c var87;
    _C::CTypes::pairs pair87(new ReQL_Pair_t[1]);
    reql_object_init(var87.get(), pair87.get(), 1);

    ReQL_Obj_c var88;
    _C::CTypes::string buf88(new uint8_t[12]);
    const uint8_t src88[] = "reql_ast_obj";
    reql_string_init(var88.get(), buf88.get(), 12);
    reql_string_append(var88.get(), src88, 12);

    ReQL_Obj_c var89;
    _C::CTypes::pairs pair89(new ReQL_Pair_t[1]);
    reql_object_init(var89.get(), pair89.get(), 1);

    ReQL_Obj_c var90;
    _C::CTypes::string buf90(new uint8_t[12]);
    const uint8_t src90[] = "reql_ast_obj";
    reql_string_init(var90.get(), buf90.get(), 12);
    reql_string_append(var90.get(), src90, 12);

    ReQL_Obj_c var91;
    _C::CTypes::string buf91(new uint8_t[7]);
    const uint8_t src91[] = "Bracket";
    reql_string_init(var91.get(), buf91.get(), 7);
    reql_string_append(var91.get(), src91, 7);

    reql_object_add(var89.get(), var90.get(), var91.get());

    reql_object_add(var87.get(), var88.get(), var89.get());

    reql_object_add(var79.get(), var86.get(), var87.get());

    reql_array_append(var0.get(), var79.get());

    ReQL_Obj_c var92;
    _C::CTypes::pairs pair92(new ReQL_Pair_t[2]);
    reql_object_init(var92.get(), pair92.get(), 2);

    ReQL_Obj_c var93;
    _C::CTypes::string buf93(new uint8_t[4]);
    const uint8_t src93[] = "left";
    reql_string_init(var93.get(), buf93.get(), 4);
    reql_string_append(var93.get(), src93, 4);

    ReQL_Obj_c var94;
    _C::CTypes::pairs pair94(new ReQL_Pair_t[1]);
    reql_object_init(var94.get(), pair94.get(), 1);

    ReQL_Obj_c var95;
    _C::CTypes::string buf95(new uint8_t[12]);
    const uint8_t src95[] = "reql_ast_obj";
    reql_string_init(var95.get(), buf95.get(), 12);
    reql_string_append(var95.get(), src95, 12);

    ReQL_Obj_c var96;
    _C::CTypes::pairs pair96(new ReQL_Pair_t[1]);
    reql_object_init(var96.get(), pair96.get(), 1);

    ReQL_Obj_c var97;
    _C::CTypes::string buf97(new uint8_t[12]);
    const uint8_t src97[] = "reql_ast_obj";
    reql_string_init(var97.get(), buf97.get(), 12);
    reql_string_append(var97.get(), src97, 12);

    ReQL_Obj_c var98;
    _C::CTypes::string buf98(new uint8_t[7]);
    const uint8_t src98[] = "Bracket";
    reql_string_init(var98.get(), buf98.get(), 7);
    reql_string_append(var98.get(), src98, 7);

    reql_object_add(var96.get(), var97.get(), var98.get());

    reql_object_add(var94.get(), var95.get(), var96.get());

    reql_object_add(var92.get(), var93.get(), var94.get());

    ReQL_Obj_c var99;
    _C::CTypes::string buf99(new uint8_t[5]);
    const uint8_t src99[] = "right";
    reql_string_init(var99.get(), buf99.get(), 5);
    reql_string_append(var99.get(), src99, 5);

    ReQL_Obj_c var100;
    _C::CTypes::pairs pair100(new ReQL_Pair_t[1]);
    reql_object_init(var100.get(), pair100.get(), 1);

    ReQL_Obj_c var101;
    _C::CTypes::string buf101(new uint8_t[12]);
    const uint8_t src101[] = "reql_ast_obj";
    reql_string_init(var101.get(), buf101.get(), 12);
    reql_string_append(var101.get(), src101, 12);

    ReQL_Obj_c var102;
    _C::CTypes::pairs pair102(new ReQL_Pair_t[1]);
    reql_object_init(var102.get(), pair102.get(), 1);

    ReQL_Obj_c var103;
    _C::CTypes::string buf103(new uint8_t[12]);
    const uint8_t src103[] = "reql_ast_obj";
    reql_string_init(var103.get(), buf103.get(), 12);
    reql_string_append(var103.get(), src103, 12);

    ReQL_Obj_c var104;
    _C::CTypes::string buf104(new uint8_t[7]);
    const uint8_t src104[] = "Bracket";
    reql_string_init(var104.get(), buf104.get(), 7);
    reql_string_append(var104.get(), src104, 7);

    reql_object_add(var102.get(), var103.get(), var104.get());

    reql_object_add(var100.get(), var101.get(), var102.get());

    reql_object_add(var92.get(), var99.get(), var100.get());

    reql_array_append(var0.get(), var92.get());
  }

  SECTION("test91") {
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

  SECTION("test92") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test93") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test94") {
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

  SECTION("test95") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test96") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test97") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test98") {
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

  SECTION("test99") {
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

  SECTION("test100") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test102") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[4]);
    const uint8_t src15[] = "left";
    reql_string_init(var15.get(), buf15.get(), 4);
    reql_string_append(var15.get(), src15, 4);

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    ReQL_Obj_c var18;
    _C::CTypes::pairs pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[5]);
    const uint8_t src21[] = "right";
    reql_string_init(var21.get(), buf21.get(), 5);
    reql_string_append(var21.get(), src21, 5);

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    ReQL_Obj_c var24;
    _C::CTypes::pairs pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    ReQL_Obj_c var27;
    _C::CTypes::pairs pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    ReQL_Obj_c var28;
    _C::CTypes::string buf28(new uint8_t[4]);
    const uint8_t src28[] = "left";
    reql_string_init(var28.get(), buf28.get(), 4);
    reql_string_append(var28.get(), src28, 4);

    ReQL_Obj_c var29;
    _C::CTypes::pairs pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    ReQL_Obj_c var30;
    _C::CTypes::string buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    ReQL_Obj_c var31;
    _C::CTypes::pairs pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    ReQL_Obj_c var32;
    _C::CTypes::string buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    ReQL_Obj_c var34;
    _C::CTypes::string buf34(new uint8_t[5]);
    const uint8_t src34[] = "right";
    reql_string_init(var34.get(), buf34.get(), 5);
    reql_string_append(var34.get(), src34, 5);

    ReQL_Obj_c var35;
    _C::CTypes::pairs pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    ReQL_Obj_c var36;
    _C::CTypes::string buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    ReQL_Obj_c var37;
    _C::CTypes::pairs pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    ReQL_Obj_c var38;
    _C::CTypes::string buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    ReQL_Obj_c var39;
    _C::CTypes::string buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());

    ReQL_Obj_c var40;
    _C::CTypes::pairs pair40(new ReQL_Pair_t[2]);
    reql_object_init(var40.get(), pair40.get(), 2);

    ReQL_Obj_c var41;
    _C::CTypes::string buf41(new uint8_t[4]);
    const uint8_t src41[] = "left";
    reql_string_init(var41.get(), buf41.get(), 4);
    reql_string_append(var41.get(), src41, 4);

    ReQL_Obj_c var42;
    _C::CTypes::pairs pair42(new ReQL_Pair_t[1]);
    reql_object_init(var42.get(), pair42.get(), 1);

    ReQL_Obj_c var43;
    _C::CTypes::string buf43(new uint8_t[12]);
    const uint8_t src43[] = "reql_ast_obj";
    reql_string_init(var43.get(), buf43.get(), 12);
    reql_string_append(var43.get(), src43, 12);

    ReQL_Obj_c var44;
    _C::CTypes::pairs pair44(new ReQL_Pair_t[1]);
    reql_object_init(var44.get(), pair44.get(), 1);

    ReQL_Obj_c var45;
    _C::CTypes::string buf45(new uint8_t[12]);
    const uint8_t src45[] = "reql_ast_obj";
    reql_string_init(var45.get(), buf45.get(), 12);
    reql_string_append(var45.get(), src45, 12);

    ReQL_Obj_c var46;
    _C::CTypes::string buf46(new uint8_t[7]);
    const uint8_t src46[] = "Bracket";
    reql_string_init(var46.get(), buf46.get(), 7);
    reql_string_append(var46.get(), src46, 7);

    reql_object_add(var44.get(), var45.get(), var46.get());

    reql_object_add(var42.get(), var43.get(), var44.get());

    reql_object_add(var40.get(), var41.get(), var42.get());

    ReQL_Obj_c var47;
    _C::CTypes::string buf47(new uint8_t[5]);
    const uint8_t src47[] = "right";
    reql_string_init(var47.get(), buf47.get(), 5);
    reql_string_append(var47.get(), src47, 5);

    ReQL_Obj_c var48;
    _C::CTypes::pairs pair48(new ReQL_Pair_t[1]);
    reql_object_init(var48.get(), pair48.get(), 1);

    ReQL_Obj_c var49;
    _C::CTypes::string buf49(new uint8_t[12]);
    const uint8_t src49[] = "reql_ast_obj";
    reql_string_init(var49.get(), buf49.get(), 12);
    reql_string_append(var49.get(), src49, 12);

    ReQL_Obj_c var50;
    _C::CTypes::pairs pair50(new ReQL_Pair_t[1]);
    reql_object_init(var50.get(), pair50.get(), 1);

    ReQL_Obj_c var51;
    _C::CTypes::string buf51(new uint8_t[12]);
    const uint8_t src51[] = "reql_ast_obj";
    reql_string_init(var51.get(), buf51.get(), 12);
    reql_string_append(var51.get(), src51, 12);

    ReQL_Obj_c var52;
    _C::CTypes::string buf52(new uint8_t[7]);
    const uint8_t src52[] = "Bracket";
    reql_string_init(var52.get(), buf52.get(), 7);
    reql_string_append(var52.get(), src52, 7);

    reql_object_add(var50.get(), var51.get(), var52.get());

    reql_object_add(var48.get(), var49.get(), var50.get());

    reql_object_add(var40.get(), var47.get(), var48.get());

    reql_array_append(var0.get(), var40.get());

    ReQL_Obj_c var53;
    _C::CTypes::pairs pair53(new ReQL_Pair_t[2]);
    reql_object_init(var53.get(), pair53.get(), 2);

    ReQL_Obj_c var54;
    _C::CTypes::string buf54(new uint8_t[4]);
    const uint8_t src54[] = "left";
    reql_string_init(var54.get(), buf54.get(), 4);
    reql_string_append(var54.get(), src54, 4);

    ReQL_Obj_c var55;
    _C::CTypes::pairs pair55(new ReQL_Pair_t[1]);
    reql_object_init(var55.get(), pair55.get(), 1);

    ReQL_Obj_c var56;
    _C::CTypes::string buf56(new uint8_t[12]);
    const uint8_t src56[] = "reql_ast_obj";
    reql_string_init(var56.get(), buf56.get(), 12);
    reql_string_append(var56.get(), src56, 12);

    ReQL_Obj_c var57;
    _C::CTypes::pairs pair57(new ReQL_Pair_t[1]);
    reql_object_init(var57.get(), pair57.get(), 1);

    ReQL_Obj_c var58;
    _C::CTypes::string buf58(new uint8_t[12]);
    const uint8_t src58[] = "reql_ast_obj";
    reql_string_init(var58.get(), buf58.get(), 12);
    reql_string_append(var58.get(), src58, 12);

    ReQL_Obj_c var59;
    _C::CTypes::string buf59(new uint8_t[7]);
    const uint8_t src59[] = "Bracket";
    reql_string_init(var59.get(), buf59.get(), 7);
    reql_string_append(var59.get(), src59, 7);

    reql_object_add(var57.get(), var58.get(), var59.get());

    reql_object_add(var55.get(), var56.get(), var57.get());

    reql_object_add(var53.get(), var54.get(), var55.get());

    ReQL_Obj_c var60;
    _C::CTypes::string buf60(new uint8_t[5]);
    const uint8_t src60[] = "right";
    reql_string_init(var60.get(), buf60.get(), 5);
    reql_string_append(var60.get(), src60, 5);

    ReQL_Obj_c var61;
    _C::CTypes::pairs pair61(new ReQL_Pair_t[1]);
    reql_object_init(var61.get(), pair61.get(), 1);

    ReQL_Obj_c var62;
    _C::CTypes::string buf62(new uint8_t[12]);
    const uint8_t src62[] = "reql_ast_obj";
    reql_string_init(var62.get(), buf62.get(), 12);
    reql_string_append(var62.get(), src62, 12);

    ReQL_Obj_c var63;
    _C::CTypes::pairs pair63(new ReQL_Pair_t[1]);
    reql_object_init(var63.get(), pair63.get(), 1);

    ReQL_Obj_c var64;
    _C::CTypes::string buf64(new uint8_t[12]);
    const uint8_t src64[] = "reql_ast_obj";
    reql_string_init(var64.get(), buf64.get(), 12);
    reql_string_append(var64.get(), src64, 12);

    ReQL_Obj_c var65;
    _C::CTypes::string buf65(new uint8_t[7]);
    const uint8_t src65[] = "Bracket";
    reql_string_init(var65.get(), buf65.get(), 7);
    reql_string_append(var65.get(), src65, 7);

    reql_object_add(var63.get(), var64.get(), var65.get());

    reql_object_add(var61.get(), var62.get(), var63.get());

    reql_object_add(var53.get(), var60.get(), var61.get());

    reql_array_append(var0.get(), var53.get());
  }

  SECTION("test103") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "left";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "right";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[4]);
    const uint8_t src15[] = "left";
    reql_string_init(var15.get(), buf15.get(), 4);
    reql_string_append(var15.get(), src15, 4);

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    ReQL_Obj_c var18;
    _C::CTypes::pairs pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[5]);
    const uint8_t src21[] = "right";
    reql_string_init(var21.get(), buf21.get(), 5);
    reql_string_append(var21.get(), src21, 5);

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    ReQL_Obj_c var24;
    _C::CTypes::pairs pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    ReQL_Obj_c var27;
    _C::CTypes::pairs pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    ReQL_Obj_c var28;
    _C::CTypes::string buf28(new uint8_t[4]);
    const uint8_t src28[] = "left";
    reql_string_init(var28.get(), buf28.get(), 4);
    reql_string_append(var28.get(), src28, 4);

    ReQL_Obj_c var29;
    _C::CTypes::pairs pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    ReQL_Obj_c var30;
    _C::CTypes::string buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    ReQL_Obj_c var31;
    _C::CTypes::pairs pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    ReQL_Obj_c var32;
    _C::CTypes::string buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    ReQL_Obj_c var34;
    _C::CTypes::string buf34(new uint8_t[5]);
    const uint8_t src34[] = "right";
    reql_string_init(var34.get(), buf34.get(), 5);
    reql_string_append(var34.get(), src34, 5);

    ReQL_Obj_c var35;
    _C::CTypes::pairs pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    ReQL_Obj_c var36;
    _C::CTypes::string buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    ReQL_Obj_c var37;
    _C::CTypes::pairs pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    ReQL_Obj_c var38;
    _C::CTypes::string buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    ReQL_Obj_c var39;
    _C::CTypes::string buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());

    ReQL_Obj_c var40;
    _C::CTypes::pairs pair40(new ReQL_Pair_t[2]);
    reql_object_init(var40.get(), pair40.get(), 2);

    ReQL_Obj_c var41;
    _C::CTypes::string buf41(new uint8_t[4]);
    const uint8_t src41[] = "left";
    reql_string_init(var41.get(), buf41.get(), 4);
    reql_string_append(var41.get(), src41, 4);

    ReQL_Obj_c var42;
    _C::CTypes::pairs pair42(new ReQL_Pair_t[1]);
    reql_object_init(var42.get(), pair42.get(), 1);

    ReQL_Obj_c var43;
    _C::CTypes::string buf43(new uint8_t[12]);
    const uint8_t src43[] = "reql_ast_obj";
    reql_string_init(var43.get(), buf43.get(), 12);
    reql_string_append(var43.get(), src43, 12);

    ReQL_Obj_c var44;
    _C::CTypes::pairs pair44(new ReQL_Pair_t[1]);
    reql_object_init(var44.get(), pair44.get(), 1);

    ReQL_Obj_c var45;
    _C::CTypes::string buf45(new uint8_t[12]);
    const uint8_t src45[] = "reql_ast_obj";
    reql_string_init(var45.get(), buf45.get(), 12);
    reql_string_append(var45.get(), src45, 12);

    ReQL_Obj_c var46;
    _C::CTypes::string buf46(new uint8_t[7]);
    const uint8_t src46[] = "Bracket";
    reql_string_init(var46.get(), buf46.get(), 7);
    reql_string_append(var46.get(), src46, 7);

    reql_object_add(var44.get(), var45.get(), var46.get());

    reql_object_add(var42.get(), var43.get(), var44.get());

    reql_object_add(var40.get(), var41.get(), var42.get());

    ReQL_Obj_c var47;
    _C::CTypes::string buf47(new uint8_t[5]);
    const uint8_t src47[] = "right";
    reql_string_init(var47.get(), buf47.get(), 5);
    reql_string_append(var47.get(), src47, 5);

    ReQL_Obj_c var48;
    _C::CTypes::pairs pair48(new ReQL_Pair_t[1]);
    reql_object_init(var48.get(), pair48.get(), 1);

    ReQL_Obj_c var49;
    _C::CTypes::string buf49(new uint8_t[12]);
    const uint8_t src49[] = "reql_ast_obj";
    reql_string_init(var49.get(), buf49.get(), 12);
    reql_string_append(var49.get(), src49, 12);

    ReQL_Obj_c var50;
    _C::CTypes::pairs pair50(new ReQL_Pair_t[1]);
    reql_object_init(var50.get(), pair50.get(), 1);

    ReQL_Obj_c var51;
    _C::CTypes::string buf51(new uint8_t[12]);
    const uint8_t src51[] = "reql_ast_obj";
    reql_string_init(var51.get(), buf51.get(), 12);
    reql_string_append(var51.get(), src51, 12);

    ReQL_Obj_c var52;
    _C::CTypes::string buf52(new uint8_t[7]);
    const uint8_t src52[] = "Bracket";
    reql_string_init(var52.get(), buf52.get(), 7);
    reql_string_append(var52.get(), src52, 7);

    reql_object_add(var50.get(), var51.get(), var52.get());

    reql_object_add(var48.get(), var49.get(), var50.get());

    reql_object_add(var40.get(), var47.get(), var48.get());

    reql_array_append(var0.get(), var40.get());

    ReQL_Obj_c var53;
    _C::CTypes::pairs pair53(new ReQL_Pair_t[2]);
    reql_object_init(var53.get(), pair53.get(), 2);

    ReQL_Obj_c var54;
    _C::CTypes::string buf54(new uint8_t[4]);
    const uint8_t src54[] = "left";
    reql_string_init(var54.get(), buf54.get(), 4);
    reql_string_append(var54.get(), src54, 4);

    ReQL_Obj_c var55;
    _C::CTypes::pairs pair55(new ReQL_Pair_t[1]);
    reql_object_init(var55.get(), pair55.get(), 1);

    ReQL_Obj_c var56;
    _C::CTypes::string buf56(new uint8_t[12]);
    const uint8_t src56[] = "reql_ast_obj";
    reql_string_init(var56.get(), buf56.get(), 12);
    reql_string_append(var56.get(), src56, 12);

    ReQL_Obj_c var57;
    _C::CTypes::pairs pair57(new ReQL_Pair_t[1]);
    reql_object_init(var57.get(), pair57.get(), 1);

    ReQL_Obj_c var58;
    _C::CTypes::string buf58(new uint8_t[12]);
    const uint8_t src58[] = "reql_ast_obj";
    reql_string_init(var58.get(), buf58.get(), 12);
    reql_string_append(var58.get(), src58, 12);

    ReQL_Obj_c var59;
    _C::CTypes::string buf59(new uint8_t[7]);
    const uint8_t src59[] = "Bracket";
    reql_string_init(var59.get(), buf59.get(), 7);
    reql_string_append(var59.get(), src59, 7);

    reql_object_add(var57.get(), var58.get(), var59.get());

    reql_object_add(var55.get(), var56.get(), var57.get());

    reql_object_add(var53.get(), var54.get(), var55.get());

    ReQL_Obj_c var60;
    _C::CTypes::string buf60(new uint8_t[5]);
    const uint8_t src60[] = "right";
    reql_string_init(var60.get(), buf60.get(), 5);
    reql_string_append(var60.get(), src60, 5);

    ReQL_Obj_c var61;
    _C::CTypes::pairs pair61(new ReQL_Pair_t[1]);
    reql_object_init(var61.get(), pair61.get(), 1);

    ReQL_Obj_c var62;
    _C::CTypes::string buf62(new uint8_t[12]);
    const uint8_t src62[] = "reql_ast_obj";
    reql_string_init(var62.get(), buf62.get(), 12);
    reql_string_append(var62.get(), src62, 12);

    ReQL_Obj_c var63;
    _C::CTypes::pairs pair63(new ReQL_Pair_t[1]);
    reql_object_init(var63.get(), pair63.get(), 1);

    ReQL_Obj_c var64;
    _C::CTypes::string buf64(new uint8_t[12]);
    const uint8_t src64[] = "reql_ast_obj";
    reql_string_init(var64.get(), buf64.get(), 12);
    reql_string_append(var64.get(), src64, 12);

    ReQL_Obj_c var65;
    _C::CTypes::string buf65(new uint8_t[7]);
    const uint8_t src65[] = "Bracket";
    reql_string_init(var65.get(), buf65.get(), 7);
    reql_string_append(var65.get(), src65, 7);

    reql_object_add(var63.get(), var64.get(), var65.get());

    reql_object_add(var61.get(), var62.get(), var63.get());

    reql_object_add(var53.get(), var60.get(), var61.get());

    reql_array_append(var0.get(), var53.get());
  }

  SECTION("test104") {
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

  SECTION("test105") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test106") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test107") {
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

  SECTION("test108") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test109") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test110") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test111") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test112") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test113") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test114") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test115") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test116") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test117") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test118") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test119") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test120") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test121") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test122") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test123") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test124") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test125") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test126") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test127") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test128") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test129") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test130") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test131") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test132") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test133") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test134") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test135") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test136") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test137") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test138") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test139") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test140") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test141") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test142") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test143") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test144") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test145") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test146") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test147") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test148") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test149") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test150") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test151") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test152") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test153") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test154") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test155") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test156") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test157") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test158") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test159") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test160") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test161") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test162") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test163") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test164") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test165") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test166") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test167") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test168") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test169") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test170") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test171") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test172") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test173") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test174") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test175") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test176") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test177") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test178") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test179") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test180") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test181") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 4);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test182") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test183") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test184") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test185") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test186") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test187") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 4);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test188") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test189") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test190") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test191") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test192") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test193") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test194") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test195") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test196") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test197") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test198") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test199") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test200") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test201") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test202") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test203") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test204") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test205") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test206") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test207") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test208") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test209") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test210") {
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

  SECTION("test211") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test212") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test213") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test214") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test215") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test216") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test217") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test218") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test219") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test220") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test221") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test222") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test223") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test224") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test225") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test226") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test227") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test228") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test229") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test230") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test231") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test232") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test233") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test234") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test235") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test236") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test237") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test238") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test239") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test240") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test241") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test242") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test243") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test244") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test245") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test246") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test247") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test248") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test249") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test250") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test251") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test252") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test253") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test254") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test255") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test256") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test257") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test258") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test259") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test260") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test261") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test262") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test263") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test264") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test265") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test266") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test267") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test268") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test269") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test270") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test271") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test272") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test273") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test274") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test275") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test276") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test277") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test278") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test279") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test280") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test281") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test282") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test283") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test284") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test285") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test286") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test287") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test288") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test289") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test290") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test291") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test292") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test293") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test294") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test295") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test296") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test297") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test298") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test299") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test300") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test301") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test302") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test303") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test304") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test305") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test306") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test307") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test308") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test309") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test310") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test311") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test312") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[13]);
    reql_array_init(var0.get(), arr0.get(), 13);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 1);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var0.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 2);

    reql_array_append(var0.get(), var7.get());

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 3);

    reql_array_append(var0.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 3);

    reql_array_append(var0.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 3);

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 4);

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 4);

    reql_array_append(var0.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 4);

    reql_array_append(var0.get(), var13.get());
  }

  SECTION("test313") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[13]);
    reql_array_init(var0.get(), arr0.get(), 13);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 1);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var0.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 2);

    reql_array_append(var0.get(), var7.get());

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 3);

    reql_array_append(var0.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 3);

    reql_array_append(var0.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 3);

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 4);

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 4);

    reql_array_append(var0.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 4);

    reql_array_append(var0.get(), var13.get());
  }
}
