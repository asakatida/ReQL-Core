// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("reql Issue 344", "[reql][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[7]);
    const ReQL_Byte src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[7]);
    const ReQL_Byte src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "index";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[1]);
    const ReQL_Byte src3[] = "x";
    reql_string_init(var3.get(), buf3.get(), src3, 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[5]);
    const ReQL_Byte src4[] = "ready";
    reql_string_init(var4.get(), buf4.get(), src4, 5);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "MINVAL";
    reql_string_init(var2.get(), buf2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "MAXVAL";
    reql_string_init(var2.get(), buf2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[4]);
    const ReQL_Byte src2[] = "NULL";
    reql_string_init(var2.get(), buf2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[4]);
    const ReQL_Byte src2[] = "BOOL";
    reql_string_init(var2.get(), buf2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[4]);
    const ReQL_Byte src4[] = "true";
    reql_string_init(var4.get(), buf4.get(), src4, 4);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "NUMBER";
    reql_string_init(var2.get(), buf2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[1]);
    const ReQL_Byte src4[] = "1";
    reql_string_init(var4.get(), buf4.get(), src4, 1);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "STRING";
    reql_string_init(var2.get(), buf2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[5]);
    const ReQL_Byte src4[] = "\"1\"";
    reql_string_init(var4.get(), buf4.get(), src4, 5);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "ARRAY";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "[\n\t1\n]";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "OBJECT";
    reql_string_init(var2.get(), buf2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[17]);
    const ReQL_Byte src4[] = "{\n\t\"a\":\t1\n}";
    reql_string_init(var4.get(), buf4.get(), src4, 17);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[7]);
    const ReQL_Byte src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[2]);
    const ReQL_Byte src1[] = "db";
    reql_string_init(var1.get(), buf1.get(), src1, 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[3]);
    reql_object_init(var2.get(), pair2.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[4]);
    const ReQL_Byte src5[] = "func";
    reql_string_init(var5.get(), buf5.get(), src5, 4);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[4]);
    const ReQL_Byte src6[] = "uuid";
    reql_string_init(var6.get(), buf6.get(), src6, 4);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_object_add(var2.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[4]);
    const ReQL_Byte src7[] = "name";
    reql_string_init(var7.get(), buf7.get(), src7, 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[4]);
    const ReQL_Byte src8[] = "d469";
    reql_string_init(var8.get(), buf8.get(), src8, 4);

    reql_object_add(var2.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[4]);
    const ReQL_Byte src9[] = "type";
    reql_string_init(var9.get(), buf9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[2]);
    const ReQL_Byte src10[] = "DB";
    reql_string_init(var10.get(), buf10.get(), src10, 2);

    reql_object_add(var2.get(), var9.get(), var10.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[19]);
    const ReQL_Byte src11[] = "doc_count_estimates";
    reql_string_init(var11.get(), buf11.get(), src11, 19);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr12(new ReQL_Obj_t*[1]);
    reql_array_init(var12.get(), arr12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_array_append(var12.get(), var13.get());

    reql_object_add(var0.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[2]);
    const ReQL_Byte src14[] = "id";
    reql_string_init(var14.get(), buf14.get(), src14, 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[1]);
    reql_object_init(var15.get(), pair15.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[4]);
    const ReQL_Byte src16[] = "func";
    reql_string_init(var16.get(), buf16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[4]);
    const ReQL_Byte src17[] = "uuid";
    reql_string_init(var17.get(), buf17.get(), src17, 4);

    reql_object_add(var15.get(), var16.get(), var17.get());

    reql_object_add(var0.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[7]);
    const ReQL_Byte src18[] = "indexes";
    reql_string_init(var18.get(), buf18.get(), src18, 7);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr19(new ReQL_Obj_t*[1]);
    reql_array_init(var19.get(), arr19.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[1]);
    const ReQL_Byte src20[] = "x";
    reql_string_init(var20.get(), buf20.get(), src20, 1);

    reql_array_append(var19.get(), var20.get());

    reql_object_add(var0.get(), var18.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[4]);
    const ReQL_Byte src21[] = "name";
    reql_string_init(var21.get(), buf21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[4]);
    const ReQL_Byte src22[] = "t469";
    reql_string_init(var22.get(), buf22.get(), src22, 4);

    reql_object_add(var0.get(), var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[11]);
    const ReQL_Byte src23[] = "primary_key";
    reql_string_init(var23.get(), buf23.get(), src23, 11);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[2]);
    const ReQL_Byte src24[] = "id";
    reql_string_init(var24.get(), buf24.get(), src24, 2);

    reql_object_add(var0.get(), var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[4]);
    const ReQL_Byte src25[] = "type";
    reql_string_init(var25.get(), buf25.get(), src25, 4);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[5]);
    const ReQL_Byte src26[] = "TABLE";
    reql_string_init(var26.get(), buf26.get(), src26, 5);

    reql_object_add(var0.get(), var25.get(), var26.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[5]);
    const ReQL_Byte src1[] = "table";
    reql_string_init(var1.get(), buf1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[7]);
    reql_object_init(var2.get(), pair2.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "db";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[3]);
    reql_object_init(var4.get(), pair4.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[2]);
    const ReQL_Byte src5[] = "id";
    reql_string_init(var5.get(), buf5.get(), src5, 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[4]);
    const ReQL_Byte src7[] = "func";
    reql_string_init(var7.get(), buf7.get(), src7, 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[4]);
    const ReQL_Byte src8[] = "uuid";
    reql_string_init(var8.get(), buf8.get(), src8, 4);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[4]);
    const ReQL_Byte src9[] = "name";
    reql_string_init(var9.get(), buf9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[4]);
    const ReQL_Byte src10[] = "d469";
    reql_string_init(var10.get(), buf10.get(), src10, 4);

    reql_object_add(var4.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[4]);
    const ReQL_Byte src11[] = "type";
    reql_string_init(var11.get(), buf11.get(), src11, 4);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[2]);
    const ReQL_Byte src12[] = "DB";
    reql_string_init(var12.get(), buf12.get(), src12, 2);

    reql_object_add(var4.get(), var11.get(), var12.get());

    reql_object_add(var2.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[19]);
    const ReQL_Byte src13[] = "doc_count_estimates";
    reql_string_init(var13.get(), buf13.get(), src13, 19);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[1]);
    reql_array_init(var14.get(), arr14.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 0);

    reql_array_append(var14.get(), var15.get());

    reql_object_add(var2.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[2]);
    const ReQL_Byte src16[] = "id";
    reql_string_init(var16.get(), buf16.get(), src16, 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair17(new ReQL_Pair_t[1]);
    reql_object_init(var17.get(), pair17.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[4]);
    const ReQL_Byte src18[] = "func";
    reql_string_init(var18.get(), buf18.get(), src18, 4);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[4]);
    const ReQL_Byte src19[] = "uuid";
    reql_string_init(var19.get(), buf19.get(), src19, 4);

    reql_object_add(var17.get(), var18.get(), var19.get());

    reql_object_add(var2.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[7]);
    const ReQL_Byte src20[] = "indexes";
    reql_string_init(var20.get(), buf20.get(), src20, 7);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[1]);
    reql_array_init(var21.get(), arr21.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[1]);
    const ReQL_Byte src22[] = "x";
    reql_string_init(var22.get(), buf22.get(), src22, 1);

    reql_array_append(var21.get(), var22.get());

    reql_object_add(var2.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[4]);
    const ReQL_Byte src23[] = "name";
    reql_string_init(var23.get(), buf23.get(), src23, 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[4]);
    const ReQL_Byte src24[] = "t469";
    reql_string_init(var24.get(), buf24.get(), src24, 4);

    reql_object_add(var2.get(), var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[11]);
    const ReQL_Byte src25[] = "primary_key";
    reql_string_init(var25.get(), buf25.get(), src25, 11);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[2]);
    const ReQL_Byte src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), src26, 2);

    reql_object_add(var2.get(), var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf27(new ReQL_Byte[4]);
    const ReQL_Byte src27[] = "type";
    reql_string_init(var27.get(), buf27.get(), src27, 4);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf28(new ReQL_Byte[5]);
    const ReQL_Byte src28[] = "TABLE";
    reql_string_init(var28.get(), buf28.get(), src28, 5);

    reql_object_add(var2.get(), var27.get(), var28.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf29(new ReQL_Byte[4]);
    const ReQL_Byte src29[] = "type";
    reql_string_init(var29.get(), buf29.get(), src29, 4);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[17]);
    const ReQL_Byte src30[] = "SELECTION<STREAM>";
    reql_string_init(var30.get(), buf30.get(), src30, 17);

    reql_object_add(var0.get(), var29.get(), var30.get());
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "STREAM";
    reql_string_init(var2.get(), buf2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[8]);
    reql_object_init(var0.get(), pair0.get(), 8);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[5]);
    const ReQL_Byte src1[] = "index";
    reql_string_init(var1.get(), buf1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[2]);
    const ReQL_Byte src2[] = "id";
    reql_string_init(var2.get(), buf2.get(), src2, 2);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[10]);
    const ReQL_Byte src3[] = "left_bound";
    reql_string_init(var3.get(), buf3.get(), src3, 10);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[15]);
    const ReQL_Byte src5[] = "left_bound_type";
    reql_string_init(var5.get(), buf5.get(), src5, 15);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[6]);
    const ReQL_Byte src6[] = "closed";
    reql_string_init(var6.get(), buf6.get(), src6, 6);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[11]);
    const ReQL_Byte src7[] = "right_bound";
    reql_string_init(var7.get(), buf7.get(), src7, 11);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[16]);
    const ReQL_Byte src9[] = "right_bound_type";
    reql_string_init(var9.get(), buf9.get(), src9, 16);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[4]);
    const ReQL_Byte src10[] = "open";
    reql_string_init(var10.get(), buf10.get(), src10, 4);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[7]);
    const ReQL_Byte src11[] = "sorting";
    reql_string_init(var11.get(), buf11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[9]);
    const ReQL_Byte src12[] = "UNORDERED";
    reql_string_init(var12.get(), buf12.get(), src12, 9);

    reql_object_add(var0.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[5]);
    const ReQL_Byte src13[] = "table";
    reql_string_init(var13.get(), buf13.get(), src13, 5);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[7]);
    reql_object_init(var14.get(), pair14.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[2]);
    const ReQL_Byte src15[] = "db";
    reql_string_init(var15.get(), buf15.get(), src15, 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[3]);
    reql_object_init(var16.get(), pair16.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[2]);
    const ReQL_Byte src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[4]);
    const ReQL_Byte src19[] = "func";
    reql_string_init(var19.get(), buf19.get(), src19, 4);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[4]);
    const ReQL_Byte src20[] = "uuid";
    reql_string_init(var20.get(), buf20.get(), src20, 4);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[4]);
    const ReQL_Byte src21[] = "name";
    reql_string_init(var21.get(), buf21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[4]);
    const ReQL_Byte src22[] = "d469";
    reql_string_init(var22.get(), buf22.get(), src22, 4);

    reql_object_add(var16.get(), var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[4]);
    const ReQL_Byte src23[] = "type";
    reql_string_init(var23.get(), buf23.get(), src23, 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[2]);
    const ReQL_Byte src24[] = "DB";
    reql_string_init(var24.get(), buf24.get(), src24, 2);

    reql_object_add(var16.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[19]);
    const ReQL_Byte src25[] = "doc_count_estimates";
    reql_string_init(var25.get(), buf25.get(), src25, 19);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr26(new ReQL_Obj_t*[1]);
    reql_array_init(var26.get(), arr26.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 0);

    reql_array_append(var26.get(), var27.get());

    reql_object_add(var14.get(), var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf28(new ReQL_Byte[2]);
    const ReQL_Byte src28[] = "id";
    reql_string_init(var28.get(), buf28.get(), src28, 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[4]);
    const ReQL_Byte src30[] = "func";
    reql_string_init(var30.get(), buf30.get(), src30, 4);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[4]);
    const ReQL_Byte src31[] = "uuid";
    reql_string_init(var31.get(), buf31.get(), src31, 4);

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var14.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf32(new ReQL_Byte[7]);
    const ReQL_Byte src32[] = "indexes";
    reql_string_init(var32.get(), buf32.get(), src32, 7);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr33(new ReQL_Obj_t*[1]);
    reql_array_init(var33.get(), arr33.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf34(new ReQL_Byte[1]);
    const ReQL_Byte src34[] = "x";
    reql_string_init(var34.get(), buf34.get(), src34, 1);

    reql_array_append(var33.get(), var34.get());

    reql_object_add(var14.get(), var32.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[4]);
    const ReQL_Byte src35[] = "name";
    reql_string_init(var35.get(), buf35.get(), src35, 4);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf36(new ReQL_Byte[4]);
    const ReQL_Byte src36[] = "t469";
    reql_string_init(var36.get(), buf36.get(), src36, 4);

    reql_object_add(var14.get(), var35.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[11]);
    const ReQL_Byte src37[] = "primary_key";
    reql_string_init(var37.get(), buf37.get(), src37, 11);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf38(new ReQL_Byte[2]);
    const ReQL_Byte src38[] = "id";
    reql_string_init(var38.get(), buf38.get(), src38, 2);

    reql_object_add(var14.get(), var37.get(), var38.get());

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf39(new ReQL_Byte[4]);
    const ReQL_Byte src39[] = "type";
    reql_string_init(var39.get(), buf39.get(), src39, 4);

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf40(new ReQL_Byte[5]);
    const ReQL_Byte src40[] = "TABLE";
    reql_string_init(var40.get(), buf40.get(), src40, 5);

    reql_object_add(var14.get(), var39.get(), var40.get());

    reql_object_add(var0.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf41(new ReQL_Byte[4]);
    const ReQL_Byte src41[] = "type";
    reql_string_init(var41.get(), buf41.get(), src41, 4);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf42(new ReQL_Byte[11]);
    const ReQL_Byte src42[] = "TABLE_SLICE";
    reql_string_init(var42.get(), buf42.get(), src42, 11);

    reql_object_add(var0.get(), var41.get(), var42.get());
  }

  SECTION("test17") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[8]);
    reql_object_init(var0.get(), pair0.get(), 8);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[5]);
    const ReQL_Byte src1[] = "index";
    reql_string_init(var1.get(), buf1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[1]);
    const ReQL_Byte src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), src2, 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[10]);
    const ReQL_Byte src3[] = "left_bound";
    reql_string_init(var3.get(), buf3.get(), src3, 10);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[15]);
    const ReQL_Byte src5[] = "left_bound_type";
    reql_string_init(var5.get(), buf5.get(), src5, 15);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[6]);
    const ReQL_Byte src6[] = "closed";
    reql_string_init(var6.get(), buf6.get(), src6, 6);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[11]);
    const ReQL_Byte src7[] = "right_bound";
    reql_string_init(var7.get(), buf7.get(), src7, 11);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[16]);
    const ReQL_Byte src9[] = "right_bound_type";
    reql_string_init(var9.get(), buf9.get(), src9, 16);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[4]);
    const ReQL_Byte src10[] = "open";
    reql_string_init(var10.get(), buf10.get(), src10, 4);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[7]);
    const ReQL_Byte src11[] = "sorting";
    reql_string_init(var11.get(), buf11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[9]);
    const ReQL_Byte src12[] = "UNORDERED";
    reql_string_init(var12.get(), buf12.get(), src12, 9);

    reql_object_add(var0.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[5]);
    const ReQL_Byte src13[] = "table";
    reql_string_init(var13.get(), buf13.get(), src13, 5);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[7]);
    reql_object_init(var14.get(), pair14.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[2]);
    const ReQL_Byte src15[] = "db";
    reql_string_init(var15.get(), buf15.get(), src15, 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[3]);
    reql_object_init(var16.get(), pair16.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[2]);
    const ReQL_Byte src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[4]);
    const ReQL_Byte src19[] = "func";
    reql_string_init(var19.get(), buf19.get(), src19, 4);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[4]);
    const ReQL_Byte src20[] = "uuid";
    reql_string_init(var20.get(), buf20.get(), src20, 4);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[4]);
    const ReQL_Byte src21[] = "name";
    reql_string_init(var21.get(), buf21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[4]);
    const ReQL_Byte src22[] = "d469";
    reql_string_init(var22.get(), buf22.get(), src22, 4);

    reql_object_add(var16.get(), var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[4]);
    const ReQL_Byte src23[] = "type";
    reql_string_init(var23.get(), buf23.get(), src23, 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[2]);
    const ReQL_Byte src24[] = "DB";
    reql_string_init(var24.get(), buf24.get(), src24, 2);

    reql_object_add(var16.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[19]);
    const ReQL_Byte src25[] = "doc_count_estimates";
    reql_string_init(var25.get(), buf25.get(), src25, 19);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr26(new ReQL_Obj_t*[1]);
    reql_array_init(var26.get(), arr26.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 0);

    reql_array_append(var26.get(), var27.get());

    reql_object_add(var14.get(), var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf28(new ReQL_Byte[2]);
    const ReQL_Byte src28[] = "id";
    reql_string_init(var28.get(), buf28.get(), src28, 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[4]);
    const ReQL_Byte src30[] = "func";
    reql_string_init(var30.get(), buf30.get(), src30, 4);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[4]);
    const ReQL_Byte src31[] = "uuid";
    reql_string_init(var31.get(), buf31.get(), src31, 4);

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var14.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf32(new ReQL_Byte[7]);
    const ReQL_Byte src32[] = "indexes";
    reql_string_init(var32.get(), buf32.get(), src32, 7);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr33(new ReQL_Obj_t*[1]);
    reql_array_init(var33.get(), arr33.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf34(new ReQL_Byte[1]);
    const ReQL_Byte src34[] = "x";
    reql_string_init(var34.get(), buf34.get(), src34, 1);

    reql_array_append(var33.get(), var34.get());

    reql_object_add(var14.get(), var32.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[4]);
    const ReQL_Byte src35[] = "name";
    reql_string_init(var35.get(), buf35.get(), src35, 4);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf36(new ReQL_Byte[4]);
    const ReQL_Byte src36[] = "t469";
    reql_string_init(var36.get(), buf36.get(), src36, 4);

    reql_object_add(var14.get(), var35.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[11]);
    const ReQL_Byte src37[] = "primary_key";
    reql_string_init(var37.get(), buf37.get(), src37, 11);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf38(new ReQL_Byte[2]);
    const ReQL_Byte src38[] = "id";
    reql_string_init(var38.get(), buf38.get(), src38, 2);

    reql_object_add(var14.get(), var37.get(), var38.get());

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf39(new ReQL_Byte[4]);
    const ReQL_Byte src39[] = "type";
    reql_string_init(var39.get(), buf39.get(), src39, 4);

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf40(new ReQL_Byte[5]);
    const ReQL_Byte src40[] = "TABLE";
    reql_string_init(var40.get(), buf40.get(), src40, 5);

    reql_object_add(var14.get(), var39.get(), var40.get());

    reql_object_add(var0.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf41(new ReQL_Byte[4]);
    const ReQL_Byte src41[] = "type";
    reql_string_init(var41.get(), buf41.get(), src41, 4);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf42(new ReQL_Byte[11]);
    const ReQL_Byte src42[] = "TABLE_SLICE";
    reql_string_init(var42.get(), buf42.get(), src42, 11);

    reql_object_add(var0.get(), var41.get(), var42.get());
  }

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[8]);
    reql_object_init(var0.get(), pair0.get(), 8);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[5]);
    const ReQL_Byte src1[] = "index";
    reql_string_init(var1.get(), buf1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[1]);
    const ReQL_Byte src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), src2, 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[10]);
    const ReQL_Byte src3[] = "left_bound";
    reql_string_init(var3.get(), buf3.get(), src3, 10);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[15]);
    const ReQL_Byte src5[] = "left_bound_type";
    reql_string_init(var5.get(), buf5.get(), src5, 15);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[6]);
    const ReQL_Byte src6[] = "closed";
    reql_string_init(var6.get(), buf6.get(), src6, 6);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[11]);
    const ReQL_Byte src7[] = "right_bound";
    reql_string_init(var7.get(), buf7.get(), src7, 11);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[16]);
    const ReQL_Byte src9[] = "right_bound_type";
    reql_string_init(var9.get(), buf9.get(), src9, 16);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[4]);
    const ReQL_Byte src10[] = "open";
    reql_string_init(var10.get(), buf10.get(), src10, 4);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[7]);
    const ReQL_Byte src11[] = "sorting";
    reql_string_init(var11.get(), buf11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[9]);
    const ReQL_Byte src12[] = "ASCENDING";
    reql_string_init(var12.get(), buf12.get(), src12, 9);

    reql_object_add(var0.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[5]);
    const ReQL_Byte src13[] = "table";
    reql_string_init(var13.get(), buf13.get(), src13, 5);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[7]);
    reql_object_init(var14.get(), pair14.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[2]);
    const ReQL_Byte src15[] = "db";
    reql_string_init(var15.get(), buf15.get(), src15, 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[3]);
    reql_object_init(var16.get(), pair16.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[2]);
    const ReQL_Byte src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[4]);
    const ReQL_Byte src19[] = "func";
    reql_string_init(var19.get(), buf19.get(), src19, 4);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[4]);
    const ReQL_Byte src20[] = "uuid";
    reql_string_init(var20.get(), buf20.get(), src20, 4);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[4]);
    const ReQL_Byte src21[] = "name";
    reql_string_init(var21.get(), buf21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[4]);
    const ReQL_Byte src22[] = "d469";
    reql_string_init(var22.get(), buf22.get(), src22, 4);

    reql_object_add(var16.get(), var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[4]);
    const ReQL_Byte src23[] = "type";
    reql_string_init(var23.get(), buf23.get(), src23, 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[2]);
    const ReQL_Byte src24[] = "DB";
    reql_string_init(var24.get(), buf24.get(), src24, 2);

    reql_object_add(var16.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[19]);
    const ReQL_Byte src25[] = "doc_count_estimates";
    reql_string_init(var25.get(), buf25.get(), src25, 19);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr26(new ReQL_Obj_t*[1]);
    reql_array_init(var26.get(), arr26.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 0);

    reql_array_append(var26.get(), var27.get());

    reql_object_add(var14.get(), var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf28(new ReQL_Byte[2]);
    const ReQL_Byte src28[] = "id";
    reql_string_init(var28.get(), buf28.get(), src28, 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[4]);
    const ReQL_Byte src30[] = "func";
    reql_string_init(var30.get(), buf30.get(), src30, 4);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[4]);
    const ReQL_Byte src31[] = "uuid";
    reql_string_init(var31.get(), buf31.get(), src31, 4);

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var14.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf32(new ReQL_Byte[7]);
    const ReQL_Byte src32[] = "indexes";
    reql_string_init(var32.get(), buf32.get(), src32, 7);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr33(new ReQL_Obj_t*[1]);
    reql_array_init(var33.get(), arr33.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf34(new ReQL_Byte[1]);
    const ReQL_Byte src34[] = "x";
    reql_string_init(var34.get(), buf34.get(), src34, 1);

    reql_array_append(var33.get(), var34.get());

    reql_object_add(var14.get(), var32.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[4]);
    const ReQL_Byte src35[] = "name";
    reql_string_init(var35.get(), buf35.get(), src35, 4);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf36(new ReQL_Byte[4]);
    const ReQL_Byte src36[] = "t469";
    reql_string_init(var36.get(), buf36.get(), src36, 4);

    reql_object_add(var14.get(), var35.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[11]);
    const ReQL_Byte src37[] = "primary_key";
    reql_string_init(var37.get(), buf37.get(), src37, 11);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf38(new ReQL_Byte[2]);
    const ReQL_Byte src38[] = "id";
    reql_string_init(var38.get(), buf38.get(), src38, 2);

    reql_object_add(var14.get(), var37.get(), var38.get());

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf39(new ReQL_Byte[4]);
    const ReQL_Byte src39[] = "type";
    reql_string_init(var39.get(), buf39.get(), src39, 4);

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf40(new ReQL_Byte[5]);
    const ReQL_Byte src40[] = "TABLE";
    reql_string_init(var40.get(), buf40.get(), src40, 5);

    reql_object_add(var14.get(), var39.get(), var40.get());

    reql_object_add(var0.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf41(new ReQL_Byte[4]);
    const ReQL_Byte src41[] = "type";
    reql_string_init(var41.get(), buf41.get(), src41, 4);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf42(new ReQL_Byte[11]);
    const ReQL_Byte src42[] = "TABLE_SLICE";
    reql_string_init(var42.get(), buf42.get(), src42, 11);

    reql_object_add(var0.get(), var41.get(), var42.get());
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[5]);
    const ReQL_Byte src1[] = "index";
    reql_string_init(var1.get(), buf1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[2]);
    const ReQL_Byte src2[] = "id";
    reql_string_init(var2.get(), buf2.get(), src2, 2);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[15]);
    const ReQL_Byte src3[] = "left_bound_type";
    reql_string_init(var3.get(), buf3.get(), src3, 15);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "unbounded";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[16]);
    const ReQL_Byte src5[] = "right_bound_type";
    reql_string_init(var5.get(), buf5.get(), src5, 16);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[9]);
    const ReQL_Byte src6[] = "unbounded";
    reql_string_init(var6.get(), buf6.get(), src6, 9);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[7]);
    const ReQL_Byte src7[] = "sorting";
    reql_string_init(var7.get(), buf7.get(), src7, 7);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[9]);
    const ReQL_Byte src8[] = "UNORDERED";
    reql_string_init(var8.get(), buf8.get(), src8, 9);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[5]);
    const ReQL_Byte src9[] = "table";
    reql_string_init(var9.get(), buf9.get(), src9, 5);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[7]);
    reql_object_init(var10.get(), pair10.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[2]);
    const ReQL_Byte src11[] = "db";
    reql_string_init(var11.get(), buf11.get(), src11, 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[3]);
    reql_object_init(var12.get(), pair12.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[2]);
    const ReQL_Byte src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[1]);
    reql_object_init(var14.get(), pair14.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[4]);
    const ReQL_Byte src15[] = "func";
    reql_string_init(var15.get(), buf15.get(), src15, 4);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[4]);
    const ReQL_Byte src16[] = "uuid";
    reql_string_init(var16.get(), buf16.get(), src16, 4);

    reql_object_add(var14.get(), var15.get(), var16.get());

    reql_object_add(var12.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[4]);
    const ReQL_Byte src17[] = "name";
    reql_string_init(var17.get(), buf17.get(), src17, 4);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[4]);
    const ReQL_Byte src18[] = "d469";
    reql_string_init(var18.get(), buf18.get(), src18, 4);

    reql_object_add(var12.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[4]);
    const ReQL_Byte src19[] = "type";
    reql_string_init(var19.get(), buf19.get(), src19, 4);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[2]);
    const ReQL_Byte src20[] = "DB";
    reql_string_init(var20.get(), buf20.get(), src20, 2);

    reql_object_add(var12.get(), var19.get(), var20.get());

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[19]);
    const ReQL_Byte src21[] = "doc_count_estimates";
    reql_string_init(var21.get(), buf21.get(), src21, 19);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[1]);
    reql_array_init(var22.get(), arr22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 0);

    reql_array_append(var22.get(), var23.get());

    reql_object_add(var10.get(), var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[2]);
    const ReQL_Byte src24[] = "id";
    reql_string_init(var24.get(), buf24.get(), src24, 2);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair25(new ReQL_Pair_t[1]);
    reql_object_init(var25.get(), pair25.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[4]);
    const ReQL_Byte src26[] = "func";
    reql_string_init(var26.get(), buf26.get(), src26, 4);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf27(new ReQL_Byte[4]);
    const ReQL_Byte src27[] = "uuid";
    reql_string_init(var27.get(), buf27.get(), src27, 4);

    reql_object_add(var25.get(), var26.get(), var27.get());

    reql_object_add(var10.get(), var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf28(new ReQL_Byte[7]);
    const ReQL_Byte src28[] = "indexes";
    reql_string_init(var28.get(), buf28.get(), src28, 7);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr29(new ReQL_Obj_t*[1]);
    reql_array_init(var29.get(), arr29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[1]);
    const ReQL_Byte src30[] = "x";
    reql_string_init(var30.get(), buf30.get(), src30, 1);

    reql_array_append(var29.get(), var30.get());

    reql_object_add(var10.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[4]);
    const ReQL_Byte src31[] = "name";
    reql_string_init(var31.get(), buf31.get(), src31, 4);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf32(new ReQL_Byte[4]);
    const ReQL_Byte src32[] = "t469";
    reql_string_init(var32.get(), buf32.get(), src32, 4);

    reql_object_add(var10.get(), var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf33(new ReQL_Byte[11]);
    const ReQL_Byte src33[] = "primary_key";
    reql_string_init(var33.get(), buf33.get(), src33, 11);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf34(new ReQL_Byte[2]);
    const ReQL_Byte src34[] = "id";
    reql_string_init(var34.get(), buf34.get(), src34, 2);

    reql_object_add(var10.get(), var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[4]);
    const ReQL_Byte src35[] = "type";
    reql_string_init(var35.get(), buf35.get(), src35, 4);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf36(new ReQL_Byte[5]);
    const ReQL_Byte src36[] = "TABLE";
    reql_string_init(var36.get(), buf36.get(), src36, 5);

    reql_object_add(var10.get(), var35.get(), var36.get());

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[4]);
    const ReQL_Byte src37[] = "type";
    reql_string_init(var37.get(), buf37.get(), src37, 4);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf38(new ReQL_Byte[11]);
    const ReQL_Byte src38[] = "TABLE_SLICE";
    reql_string_init(var38.get(), buf38.get(), src38, 11);

    reql_object_add(var0.get(), var37.get(), var38.get());
  }

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[5]);
    const ReQL_Byte src1[] = "index";
    reql_string_init(var1.get(), buf1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[2]);
    const ReQL_Byte src2[] = "id";
    reql_string_init(var2.get(), buf2.get(), src2, 2);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[15]);
    const ReQL_Byte src3[] = "left_bound_type";
    reql_string_init(var3.get(), buf3.get(), src3, 15);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[12]);
    const ReQL_Byte src4[] = "unachievable";
    reql_string_init(var4.get(), buf4.get(), src4, 12);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[16]);
    const ReQL_Byte src5[] = "right_bound_type";
    reql_string_init(var5.get(), buf5.get(), src5, 16);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[12]);
    const ReQL_Byte src6[] = "unachievable";
    reql_string_init(var6.get(), buf6.get(), src6, 12);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[7]);
    const ReQL_Byte src7[] = "sorting";
    reql_string_init(var7.get(), buf7.get(), src7, 7);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[9]);
    const ReQL_Byte src8[] = "UNORDERED";
    reql_string_init(var8.get(), buf8.get(), src8, 9);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[5]);
    const ReQL_Byte src9[] = "table";
    reql_string_init(var9.get(), buf9.get(), src9, 5);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[7]);
    reql_object_init(var10.get(), pair10.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[2]);
    const ReQL_Byte src11[] = "db";
    reql_string_init(var11.get(), buf11.get(), src11, 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[3]);
    reql_object_init(var12.get(), pair12.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[2]);
    const ReQL_Byte src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[1]);
    reql_object_init(var14.get(), pair14.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[4]);
    const ReQL_Byte src15[] = "func";
    reql_string_init(var15.get(), buf15.get(), src15, 4);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[4]);
    const ReQL_Byte src16[] = "uuid";
    reql_string_init(var16.get(), buf16.get(), src16, 4);

    reql_object_add(var14.get(), var15.get(), var16.get());

    reql_object_add(var12.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[4]);
    const ReQL_Byte src17[] = "name";
    reql_string_init(var17.get(), buf17.get(), src17, 4);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[4]);
    const ReQL_Byte src18[] = "d469";
    reql_string_init(var18.get(), buf18.get(), src18, 4);

    reql_object_add(var12.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[4]);
    const ReQL_Byte src19[] = "type";
    reql_string_init(var19.get(), buf19.get(), src19, 4);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[2]);
    const ReQL_Byte src20[] = "DB";
    reql_string_init(var20.get(), buf20.get(), src20, 2);

    reql_object_add(var12.get(), var19.get(), var20.get());

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[19]);
    const ReQL_Byte src21[] = "doc_count_estimates";
    reql_string_init(var21.get(), buf21.get(), src21, 19);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[1]);
    reql_array_init(var22.get(), arr22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 0);

    reql_array_append(var22.get(), var23.get());

    reql_object_add(var10.get(), var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[2]);
    const ReQL_Byte src24[] = "id";
    reql_string_init(var24.get(), buf24.get(), src24, 2);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair25(new ReQL_Pair_t[1]);
    reql_object_init(var25.get(), pair25.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[4]);
    const ReQL_Byte src26[] = "func";
    reql_string_init(var26.get(), buf26.get(), src26, 4);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf27(new ReQL_Byte[4]);
    const ReQL_Byte src27[] = "uuid";
    reql_string_init(var27.get(), buf27.get(), src27, 4);

    reql_object_add(var25.get(), var26.get(), var27.get());

    reql_object_add(var10.get(), var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf28(new ReQL_Byte[7]);
    const ReQL_Byte src28[] = "indexes";
    reql_string_init(var28.get(), buf28.get(), src28, 7);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr29(new ReQL_Obj_t*[1]);
    reql_array_init(var29.get(), arr29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[1]);
    const ReQL_Byte src30[] = "x";
    reql_string_init(var30.get(), buf30.get(), src30, 1);

    reql_array_append(var29.get(), var30.get());

    reql_object_add(var10.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[4]);
    const ReQL_Byte src31[] = "name";
    reql_string_init(var31.get(), buf31.get(), src31, 4);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf32(new ReQL_Byte[4]);
    const ReQL_Byte src32[] = "t469";
    reql_string_init(var32.get(), buf32.get(), src32, 4);

    reql_object_add(var10.get(), var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf33(new ReQL_Byte[11]);
    const ReQL_Byte src33[] = "primary_key";
    reql_string_init(var33.get(), buf33.get(), src33, 11);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf34(new ReQL_Byte[2]);
    const ReQL_Byte src34[] = "id";
    reql_string_init(var34.get(), buf34.get(), src34, 2);

    reql_object_add(var10.get(), var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[4]);
    const ReQL_Byte src35[] = "type";
    reql_string_init(var35.get(), buf35.get(), src35, 4);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf36(new ReQL_Byte[5]);
    const ReQL_Byte src36[] = "TABLE";
    reql_string_init(var36.get(), buf36.get(), src36, 5);

    reql_object_add(var10.get(), var35.get(), var36.get());

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[4]);
    const ReQL_Byte src37[] = "type";
    reql_string_init(var37.get(), buf37.get(), src37, 4);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf38(new ReQL_Byte[11]);
    const ReQL_Byte src38[] = "TABLE_SLICE";
    reql_string_init(var38.get(), buf38.get(), src38, 11);

    reql_object_add(var0.get(), var37.get(), var38.get());
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[7]);
    const ReQL_Byte src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
