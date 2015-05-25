// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("c Tests manipulation operations on objects", "[c][ast]") {

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[3]);
    const uint8_t src0[] = "str";
    reql_string_init(var0.get(), buf0.get(), 3);
    reql_string_append(var0.get(), src0, 3);
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 2);
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 2);
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test17") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[4]);
    reql_object_init(var0.get(), pair0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "b";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "c";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[3]);
    const uint8_t src4[] = "str";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "d";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_null_init(var6.get());

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "e";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[1]);
    reql_object_init(var8.get(), pair8.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "f";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[4]);
    const uint8_t src10[] = "buzz";
    reql_string_init(var10.get(), buf10.get(), 4);
    reql_string_append(var10.get(), src10, 4);

    reql_object_add(var8.get(), var9.get(), var10.get());

    reql_object_add(var0.get(), var7.get(), var8.get());
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "c";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "str";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "d";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_null_init(var4.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "e";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "f";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[4]);
    const uint8_t src8[] = "buzz";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "e";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[4]);
    const uint8_t src4[] = "buzz";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[5]);
    reql_object_init(var0.get(), pair0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[3]);
    const uint8_t src6[] = "str";
    reql_string_init(var6.get(), buf6.get(), 3);
    reql_string_append(var6.get(), src6, 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_null_init(var8.get());

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "e";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_object_init(var10.get(), nullptr, 0);

    reql_object_add(var0.get(), var9.get(), var10.get());
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[5]);
    reql_object_init(var0.get(), pair0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[3]);
    const uint8_t src6[] = "str";
    reql_string_init(var6.get(), buf6.get(), 3);
    reql_string_append(var6.get(), src6, 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_null_init(var8.get());

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "e";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "f";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[4]);
    const uint8_t src12[] = "buzz";
    reql_string_init(var12.get(), buf12.get(), 4);
    reql_string_append(var12.get(), src12, 4);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_object_add(var0.get(), var9.get(), var10.get());
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test24") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[5]);
    reql_object_init(var0.get(), pair0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[3]);
    const uint8_t src6[] = "str";
    reql_string_init(var6.get(), buf6.get(), 3);
    reql_string_append(var6.get(), src6, 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_null_init(var8.get());

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "e";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), -2);

    reql_object_add(var0.get(), var9.get(), var10.get());
  }

  SECTION("test25") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[4]);
    reql_object_init(var0.get(), pair0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[3]);
    const uint8_t src6[] = "str";
    reql_string_init(var6.get(), buf6.get(), 3);
    reql_string_append(var6.get(), src6, 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_null_init(var8.get());

    reql_object_add(var0.get(), var7.get(), var8.get());
  }

  SECTION("test26") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[5]);
    reql_object_init(var0.get(), pair0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[3]);
    const uint8_t src6[] = "str";
    reql_string_init(var6.get(), buf6.get(), 3);
    reql_string_append(var6.get(), src6, 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_null_init(var8.get());

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "e";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "f";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[4]);
    const uint8_t src12[] = "quux";
    reql_string_init(var12.get(), buf12.get(), 4);
    reql_string_append(var12.get(), src12, 4);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_object_add(var0.get(), var9.get(), var10.get());
  }

  SECTION("test27") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[5]);
    reql_object_init(var0.get(), pair0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[3]);
    const uint8_t src6[] = "str";
    reql_string_init(var6.get(), buf6.get(), 3);
    reql_string_append(var6.get(), src6, 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_null_init(var8.get());

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "e";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "f";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[4]);
    const uint8_t src12[] = "buzz";
    reql_string_init(var12.get(), buf12.get(), 4);
    reql_string_append(var12.get(), src12, 4);

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[1]);
    const uint8_t src13[] = "g";
    reql_string_init(var13.get(), buf13.get(), 1);
    reql_string_append(var13.get(), src13, 1);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[4]);
    const uint8_t src14[] = "quux";
    reql_string_init(var14.get(), buf14.get(), 4);
    reql_string_append(var14.get(), src14, 4);

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_object_add(var0.get(), var9.get(), var10.get());
  }

  SECTION("test28") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[5]);
    reql_object_init(var0.get(), pair0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[3]);
    const uint8_t src6[] = "str";
    reql_string_init(var6.get(), buf6.get(), 3);
    reql_string_append(var6.get(), src6, 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_null_init(var8.get());

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "e";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "g";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[4]);
    const uint8_t src12[] = "quux";
    reql_string_init(var12.get(), buf12.get(), 4);
    reql_string_append(var12.get(), src12, 4);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_object_add(var0.get(), var9.get(), var10.get());
  }

  SECTION("test29") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[5]);
    reql_object_init(var0.get(), pair0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), -1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[3]);
    const uint8_t src6[] = "str";
    reql_string_init(var6.get(), buf6.get(), 3);
    reql_string_append(var6.get(), src6, 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_null_init(var8.get());

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "e";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "f";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[4]);
    const uint8_t src12[] = "buzz";
    reql_string_init(var12.get(), buf12.get(), 4);
    reql_string_append(var12.get(), src12, 4);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_object_add(var0.get(), var9.get(), var10.get());
  }

  SECTION("test31") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test32") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test33") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test35") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[4]);
    reql_object_init(var0.get(), pair0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[2]);
    reql_object_init(var2.get(), pair2.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 1);

    reql_object_add(var2.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 2);

    reql_object_add(var2.get(), var5.get(), var6.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "d";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 3);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "e";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 4);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "f";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 5);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test36") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[3]);
    reql_object_init(var1.get(), pair1.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1);

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[1]);
    const uint8_t src6[] = "c";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2);

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "d";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 3);

    reql_object_add(var1.get(), var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "e";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 3);

    reql_object_add(var1.get(), var10.get(), var11.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[3]);
    reql_object_init(var12.get(), pair12.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[1]);
    const uint8_t src13[] = "a";
    reql_string_init(var13.get(), buf13.get(), 1);
    reql_string_append(var13.get(), src13, 1);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "b";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[1]);
    const uint8_t src17[] = "c";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 2);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var12.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[1]);
    const uint8_t src19[] = "d";
    reql_string_init(var19.get(), buf19.get(), 1);
    reql_string_append(var19.get(), src19, 1);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 4);

    reql_object_add(var12.get(), var19.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf21(new uint8_t[1]);
    const uint8_t src21[] = "e";
    reql_string_init(var21.get(), buf21.get(), 1);
    reql_string_append(var21.get(), src21, 1);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 4);

    reql_object_add(var12.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var12.get());
  }

  SECTION("test37") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[3]);
    reql_object_init(var1.get(), pair1.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1);

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[1]);
    const uint8_t src6[] = "c";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2);

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "d";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 3);

    reql_object_add(var1.get(), var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "e";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 3);

    reql_object_add(var1.get(), var10.get(), var11.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[3]);
    reql_object_init(var12.get(), pair12.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[1]);
    const uint8_t src13[] = "a";
    reql_string_init(var13.get(), buf13.get(), 1);
    reql_string_append(var13.get(), src13, 1);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "b";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[1]);
    const uint8_t src17[] = "c";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 2);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var12.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[1]);
    const uint8_t src19[] = "d";
    reql_string_init(var19.get(), buf19.get(), 1);
    reql_string_append(var19.get(), src19, 1);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 4);

    reql_object_add(var12.get(), var19.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf21(new uint8_t[1]);
    const uint8_t src21[] = "e";
    reql_string_init(var21.get(), buf21.get(), 1);
    reql_string_append(var21.get(), src21, 1);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 4);

    reql_object_add(var12.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var12.get());
  }

  SECTION("test38") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 2);

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[1]);
    const uint8_t src6[] = "c";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2);

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "d";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 3);

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "a";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[2]);
    reql_object_init(var12.get(), pair12.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[1]);
    const uint8_t src13[] = "b";
    reql_string_init(var13.get(), buf13.get(), 1);
    reql_string_append(var13.get(), src13, 1);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 2);

    reql_object_add(var12.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "c";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 2);

    reql_object_add(var12.get(), var15.get(), var16.get());

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[1]);
    const uint8_t src17[] = "d";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 4);

    reql_object_add(var10.get(), var17.get(), var18.get());

    reql_array_append(var0.get(), var10.get());
  }

  SECTION("test39") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 2);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[1]);
    const uint8_t src6[] = "d";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 3);

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "a";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "b";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[1]);
    const uint8_t src13[] = "d";
    reql_string_init(var13.get(), buf13.get(), 1);
    reql_string_append(var13.get(), src13, 1);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 4);

    reql_object_add(var8.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var8.get());
  }

  SECTION("test40") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "b";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "c";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "d";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "e";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_array_append(var0.get(), var5.get());
  }
}
