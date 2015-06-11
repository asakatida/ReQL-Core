// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("reql Issue 335", "[reql][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[7]);
    const ReQL_Byte src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[7]);
    const ReQL_Byte src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

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
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[1]);
    const ReQL_Byte src3[] = "x";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[5]);
    const ReQL_Byte src4[] = "ready";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[4]);
    const ReQL_Byte src2[] = "NULL";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[4]);
    const ReQL_Byte src4[] = "null";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[4]);
    const ReQL_Byte src2[] = "BOOL";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[4]);
    const ReQL_Byte src4[] = "true";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "NUMBER";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[1]);
    const ReQL_Byte src4[] = "1";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "STRING";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[5]);
    const ReQL_Byte src4[] = "\"1\"";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "ARRAY";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "[\n\t1\n]";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "OBJECT";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[5]);
    const ReQL_Byte src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[17]);
    const ReQL_Byte src4[] = "{\n\t\"a\":\t1\n}";
    reql_string_init(var4.get(), buf4.get(), 17);
    reql_string_append(var4.get(), src4, 17);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[7]);
    const ReQL_Byte src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[2]);
    const ReQL_Byte src1[] = "db";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[3]);
    reql_object_init(var2.get(), pair2.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[4]);
    const ReQL_Byte src5[] = "func";
    reql_string_init(var5.get(), buf5.get(), 4);
    reql_string_append(var5.get(), src5, 4);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[4]);
    const ReQL_Byte src6[] = "uuid";
    reql_string_init(var6.get(), buf6.get(), 4);
    reql_string_append(var6.get(), src6, 4);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_object_add(var2.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[4]);
    const ReQL_Byte src7[] = "name";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[4]);
    const ReQL_Byte src8[] = "d469";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    reql_object_add(var2.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[4]);
    const ReQL_Byte src9[] = "type";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[2]);
    const ReQL_Byte src10[] = "DB";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    reql_object_add(var2.get(), var9.get(), var10.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[19]);
    const ReQL_Byte src11[] = "doc_count_estimates";
    reql_string_init(var11.get(), buf11.get(), 19);
    reql_string_append(var11.get(), src11, 19);

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
    reql_string_init(var14.get(), buf14.get(), 2);
    reql_string_append(var14.get(), src14, 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[1]);
    reql_object_init(var15.get(), pair15.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[4]);
    const ReQL_Byte src16[] = "func";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[4]);
    const ReQL_Byte src17[] = "uuid";
    reql_string_init(var17.get(), buf17.get(), 4);
    reql_string_append(var17.get(), src17, 4);

    reql_object_add(var15.get(), var16.get(), var17.get());

    reql_object_add(var0.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[7]);
    const ReQL_Byte src18[] = "indexes";
    reql_string_init(var18.get(), buf18.get(), 7);
    reql_string_append(var18.get(), src18, 7);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr19(new ReQL_Obj_t*[1]);
    reql_array_init(var19.get(), arr19.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[1]);
    const ReQL_Byte src20[] = "x";
    reql_string_init(var20.get(), buf20.get(), 1);
    reql_string_append(var20.get(), src20, 1);

    reql_array_append(var19.get(), var20.get());

    reql_object_add(var0.get(), var18.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[4]);
    const ReQL_Byte src21[] = "name";
    reql_string_init(var21.get(), buf21.get(), 4);
    reql_string_append(var21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[4]);
    const ReQL_Byte src22[] = "t469";
    reql_string_init(var22.get(), buf22.get(), 4);
    reql_string_append(var22.get(), src22, 4);

    reql_object_add(var0.get(), var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[11]);
    const ReQL_Byte src23[] = "primary_key";
    reql_string_init(var23.get(), buf23.get(), 11);
    reql_string_append(var23.get(), src23, 11);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[2]);
    const ReQL_Byte src24[] = "id";
    reql_string_init(var24.get(), buf24.get(), 2);
    reql_string_append(var24.get(), src24, 2);

    reql_object_add(var0.get(), var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[4]);
    const ReQL_Byte src25[] = "type";
    reql_string_init(var25.get(), buf25.get(), 4);
    reql_string_append(var25.get(), src25, 4);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[5]);
    const ReQL_Byte src26[] = "TABLE";
    reql_string_init(var26.get(), buf26.get(), 5);
    reql_string_append(var26.get(), src26, 5);

    reql_object_add(var0.get(), var25.get(), var26.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[5]);
    const ReQL_Byte src1[] = "table";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[7]);
    reql_object_init(var2.get(), pair2.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "db";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[3]);
    reql_object_init(var4.get(), pair4.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[2]);
    const ReQL_Byte src5[] = "id";
    reql_string_init(var5.get(), buf5.get(), 2);
    reql_string_append(var5.get(), src5, 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[4]);
    const ReQL_Byte src7[] = "func";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[4]);
    const ReQL_Byte src8[] = "uuid";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[4]);
    const ReQL_Byte src9[] = "name";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[4]);
    const ReQL_Byte src10[] = "d469";
    reql_string_init(var10.get(), buf10.get(), 4);
    reql_string_append(var10.get(), src10, 4);

    reql_object_add(var4.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[4]);
    const ReQL_Byte src11[] = "type";
    reql_string_init(var11.get(), buf11.get(), 4);
    reql_string_append(var11.get(), src11, 4);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[2]);
    const ReQL_Byte src12[] = "DB";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    reql_object_add(var4.get(), var11.get(), var12.get());

    reql_object_add(var2.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[19]);
    const ReQL_Byte src13[] = "doc_count_estimates";
    reql_string_init(var13.get(), buf13.get(), 19);
    reql_string_append(var13.get(), src13, 19);

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
    reql_string_init(var16.get(), buf16.get(), 2);
    reql_string_append(var16.get(), src16, 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair17(new ReQL_Pair_t[1]);
    reql_object_init(var17.get(), pair17.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[4]);
    const ReQL_Byte src18[] = "func";
    reql_string_init(var18.get(), buf18.get(), 4);
    reql_string_append(var18.get(), src18, 4);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[4]);
    const ReQL_Byte src19[] = "uuid";
    reql_string_init(var19.get(), buf19.get(), 4);
    reql_string_append(var19.get(), src19, 4);

    reql_object_add(var17.get(), var18.get(), var19.get());

    reql_object_add(var2.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[7]);
    const ReQL_Byte src20[] = "indexes";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[1]);
    reql_array_init(var21.get(), arr21.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[1]);
    const ReQL_Byte src22[] = "x";
    reql_string_init(var22.get(), buf22.get(), 1);
    reql_string_append(var22.get(), src22, 1);

    reql_array_append(var21.get(), var22.get());

    reql_object_add(var2.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[4]);
    const ReQL_Byte src23[] = "name";
    reql_string_init(var23.get(), buf23.get(), 4);
    reql_string_append(var23.get(), src23, 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[4]);
    const ReQL_Byte src24[] = "t469";
    reql_string_init(var24.get(), buf24.get(), 4);
    reql_string_append(var24.get(), src24, 4);

    reql_object_add(var2.get(), var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[11]);
    const ReQL_Byte src25[] = "primary_key";
    reql_string_init(var25.get(), buf25.get(), 11);
    reql_string_append(var25.get(), src25, 11);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[2]);
    const ReQL_Byte src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), 2);
    reql_string_append(var26.get(), src26, 2);

    reql_object_add(var2.get(), var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf27(new ReQL_Byte[4]);
    const ReQL_Byte src27[] = "type";
    reql_string_init(var27.get(), buf27.get(), 4);
    reql_string_append(var27.get(), src27, 4);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf28(new ReQL_Byte[5]);
    const ReQL_Byte src28[] = "TABLE";
    reql_string_init(var28.get(), buf28.get(), 5);
    reql_string_append(var28.get(), src28, 5);

    reql_object_add(var2.get(), var27.get(), var28.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf29(new ReQL_Byte[4]);
    const ReQL_Byte src29[] = "type";
    reql_string_init(var29.get(), buf29.get(), 4);
    reql_string_append(var29.get(), src29, 4);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[17]);
    const ReQL_Byte src30[] = "SELECTION<STREAM>";
    reql_string_init(var30.get(), buf30.get(), 17);
    reql_string_append(var30.get(), src30, 17);

    reql_object_add(var0.get(), var29.get(), var30.get());
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[6]);
    const ReQL_Byte src2[] = "STREAM";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[7]);
    const ReQL_Byte src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
