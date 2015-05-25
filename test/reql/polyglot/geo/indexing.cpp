// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("c Test ReQL interface to geo indexes 270", "[c][ast]") {

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[6]);
    const uint8_t src1[] = "result";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "blank";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test7") {
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

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[9]);
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test9") {
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

  SECTION("test10") {
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

  SECTION("test11") {
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

  SECTION("test12") {
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

  SECTION("test16") {
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

  SECTION("test17") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 2);
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 3);
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test24") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test25") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[6]);
    const uint8_t src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test26") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test27") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test28") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test29") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test30") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
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
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[9]);
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

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

  SECTION("test37") {
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

  SECTION("test38") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "dist";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[3]);
    const uint8_t src4[] = "doc";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[4]);
    const uint8_t src9[] = "dist";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0.055659745396754216);

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[3]);
    const uint8_t src11[] = "doc";
    reql_string_init(var11.get(), buf11.get(), 3);
    reql_string_append(var11.get(), src11, 3);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[1]);
    reql_object_init(var12.get(), pair12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 2);

    reql_object_add(var12.get(), var13.get(), var14.get());

    reql_object_add(var8.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var8.get());
  }

  SECTION("test39") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "dist";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[3]);
    const uint8_t src4[] = "doc";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[4]);
    const uint8_t src9[] = "dist";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0.11130264976984369);

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[3]);
    const uint8_t src11[] = "doc";
    reql_string_init(var11.get(), buf11.get(), 3);
    reql_string_append(var11.get(), src11, 3);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[1]);
    reql_object_init(var12.get(), pair12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 1);

    reql_object_add(var12.get(), var13.get(), var14.get());

    reql_object_add(var8.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var8.get());
  }

  SECTION("test40") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "dist";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[3]);
    const uint8_t src4[] = "doc";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[4]);
    const uint8_t src9[] = "dist";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0.055659745396754216);

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[3]);
    const uint8_t src11[] = "doc";
    reql_string_init(var11.get(), buf11.get(), 3);
    reql_string_append(var11.get(), src11, 3);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[1]);
    reql_object_init(var12.get(), pair12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 2);

    reql_object_add(var12.get(), var13.get(), var14.get());

    reql_object_add(var8.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "dist";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 1565109.0992178896);

    reql_object_add(var15.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[3]);
    const uint8_t src18[] = "doc";
    reql_string_init(var18.get(), buf18.get(), 3);
    reql_string_append(var18.get(), src18, 3);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[1]);
    reql_object_init(var19.get(), pair19.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf20(new uint8_t[2]);
    const uint8_t src20[] = "id";
    reql_string_init(var20.get(), buf20.get(), 2);
    reql_string_append(var20.get(), src20, 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_object_add(var19.get(), var20.get(), var21.get());

    reql_object_add(var15.get(), var18.get(), var19.get());

    reql_array_append(var0.get(), var15.get());
  }

  SECTION("test41") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "dist";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[3]);
    const uint8_t src4[] = "doc";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[4]);
    const uint8_t src9[] = "dist";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0.055659745396754216);

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[3]);
    const uint8_t src11[] = "doc";
    reql_string_init(var11.get(), buf11.get(), 3);
    reql_string_append(var11.get(), src11, 3);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[1]);
    reql_object_init(var12.get(), pair12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 2);

    reql_object_add(var12.get(), var13.get(), var14.get());

    reql_object_add(var8.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var8.get());
  }

  SECTION("test42") {
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

  SECTION("test43") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "dist";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[3]);
    const uint8_t src4[] = "doc";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[4]);
    const uint8_t src9[] = "dist";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 5.565974539675422e-05);

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[3]);
    const uint8_t src11[] = "doc";
    reql_string_init(var11.get(), buf11.get(), 3);
    reql_string_append(var11.get(), src11, 3);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[1]);
    reql_object_init(var12.get(), pair12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 2);

    reql_object_add(var12.get(), var13.get(), var14.get());

    reql_object_add(var8.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "dist";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 1565.1090992178897);

    reql_object_add(var15.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[3]);
    const uint8_t src18[] = "doc";
    reql_string_init(var18.get(), buf18.get(), 3);
    reql_string_append(var18.get(), src18, 3);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[1]);
    reql_object_init(var19.get(), pair19.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf20(new uint8_t[2]);
    const uint8_t src20[] = "id";
    reql_string_init(var20.get(), buf20.get(), 2);
    reql_string_append(var20.get(), src20, 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_object_add(var19.get(), var20.get(), var21.get());

    reql_object_add(var15.get(), var18.get(), var19.get());

    reql_array_append(var0.get(), var15.get());
  }

  SECTION("test44") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "dist";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[3]);
    const uint8_t src4[] = "doc";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[4]);
    const uint8_t src9[] = "dist";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 8.726646259990191e-09);

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[3]);
    const uint8_t src11[] = "doc";
    reql_string_init(var11.get(), buf11.get(), 3);
    reql_string_append(var11.get(), src11, 3);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[1]);
    reql_object_init(var12.get(), pair12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 2);

    reql_object_add(var12.get(), var13.get(), var14.get());

    reql_object_add(var8.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "dist";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 0.24619691677893205);

    reql_object_add(var15.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[3]);
    const uint8_t src18[] = "doc";
    reql_string_init(var18.get(), buf18.get(), 3);
    reql_string_append(var18.get(), src18, 3);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[1]);
    reql_object_init(var19.get(), pair19.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf20(new uint8_t[2]);
    const uint8_t src20[] = "id";
    reql_string_init(var20.get(), buf20.get(), 2);
    reql_string_append(var20.get(), src20, 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_object_add(var19.get(), var20.get(), var21.get());

    reql_object_add(var15.get(), var18.get(), var19.get());

    reql_array_append(var0.get(), var15.get());
  }

  SECTION("test45") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[5]);
    const uint8_t src0[] = "ARRAY";
    reql_string_init(var0.get(), buf0.get(), 5);
    reql_string_append(var0.get(), src0, 5);
  }

  SECTION("test46") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[5]);
    const uint8_t src0[] = "ARRAY";
    reql_string_init(var0.get(), buf0.get(), 5);
    reql_string_append(var0.get(), src0, 5);
  }
}
