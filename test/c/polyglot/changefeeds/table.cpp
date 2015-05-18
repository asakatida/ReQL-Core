// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test changefeeds on a table", "[c][ast]") {

  SECTION("test0") {
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

  SECTION("test1") {
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
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
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

  SECTION("test3") {
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
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[2]);
    const uint8_t src4[] = "id";
    reql_string_init(var4.get(), buf4.get(), 2);
    reql_string_append(var4.get(), src4, 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[7]);
    const uint8_t src6[] = "version";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1);

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[2]);
    const uint8_t src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 1);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
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
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    ReQL_Obj_c var3;
    reql_null_init(var3.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "old_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "version";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test7") {
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

  SECTION("test8") {
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
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "version";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 5);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test10") {
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

  SECTION("test12") {
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
    const uint8_t src2[] = "partial";
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
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "bag";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

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
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[2]);
    const uint8_t src4[] = "id";
    reql_string_init(var4.get(), buf4.get(), 2);
    reql_string_append(var4.get(), src4, 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[7]);
    const uint8_t src6[] = "version";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1);

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[2]);
    const uint8_t src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 1);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test17") {
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
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    ReQL_Obj_c var3;
    reql_null_init(var3.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "old_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "version";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test19") {
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

  SECTION("test20") {
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
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "version";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 5);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }
}
