// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("reql Tests that manipulation data in tables", "[reql][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0.0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[6]);
    const ReQL_Byte src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), src3, 6);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0.0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[8]);
    const ReQL_Byte src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), src5, 8);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 100);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[8]);
    const ReQL_Byte src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), src7, 8);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0.0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[7]);
    const ReQL_Byte src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), src9, 7);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0.0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[9]);
    const ReQL_Byte src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), src11, 9);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0.0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0.0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[6]);
    const ReQL_Byte src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), src3, 6);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0.0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[8]);
    const ReQL_Byte src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), src5, 8);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 100);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[8]);
    const ReQL_Byte src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), src7, 8);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0.0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[7]);
    const ReQL_Byte src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), src9, 7);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0.0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[9]);
    const ReQL_Byte src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), src11, 9);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0.0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0.0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[6]);
    const ReQL_Byte src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), src3, 6);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0.0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[8]);
    const ReQL_Byte src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), src5, 8);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 100);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[8]);
    const ReQL_Byte src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), src7, 8);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0.0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[7]);
    const ReQL_Byte src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), src9, 7);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0.0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[9]);
    const ReQL_Byte src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), src11, 9);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0.0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0.0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[6]);
    const ReQL_Byte src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), src3, 6);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0.0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[8]);
    const ReQL_Byte src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), src5, 8);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 1);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[8]);
    const ReQL_Byte src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), src7, 8);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0.0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[7]);
    const ReQL_Byte src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), src9, 7);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0.0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[9]);
    const ReQL_Byte src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), src11, 9);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0.0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 150);
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 150);
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1200);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1225);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1250);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 1275);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 48);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 49);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 50);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 51);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[1]);
    const ReQL_Byte src6[] = "a";
    reql_string_init(var6.get(), buf6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[2]);
    const ReQL_Byte src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[5]);
    const ReQL_Byte src11[] = "group";
    reql_string_init(var11.get(), buf11.get(), src11, 5);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[9]);
    const ReQL_Byte src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), src13, 9);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[1]);
    const ReQL_Byte src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), src15, 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[2]);
    const ReQL_Byte src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 1);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[5]);
    const ReQL_Byte src20[] = "group";
    reql_string_init(var20.get(), buf20.get(), src20, 5);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 2);

    reql_object_add(var19.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[9]);
    const ReQL_Byte src22[] = "reduction";
    reql_string_init(var22.get(), buf22.get(), src22, 9);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair23(new ReQL_Pair_t[2]);
    reql_object_init(var23.get(), pair23.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[1]);
    const ReQL_Byte src24[] = "a";
    reql_string_init(var24.get(), buf24.get(), src24, 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[2]);
    const ReQL_Byte src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), src26, 2);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 2);

    reql_object_add(var23.get(), var26.get(), var27.get());

    reql_object_add(var19.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair28(new ReQL_Pair_t[2]);
    reql_object_init(var28.get(), pair28.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf29(new ReQL_Byte[5]);
    const ReQL_Byte src29[] = "group";
    reql_string_init(var29.get(), buf29.get(), src29, 5);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[9]);
    const ReQL_Byte src31[] = "reduction";
    reql_string_init(var31.get(), buf31.get(), src31, 9);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair32(new ReQL_Pair_t[2]);
    reql_object_init(var32.get(), pair32.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf33(new ReQL_Byte[1]);
    const ReQL_Byte src33[] = "a";
    reql_string_init(var33.get(), buf33.get(), src33, 1);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 3);

    reql_object_add(var32.get(), var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[2]);
    const ReQL_Byte src35[] = "id";
    reql_string_init(var35.get(), buf35.get(), src35, 2);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_number_init(var36.get(), 3);

    reql_object_add(var32.get(), var35.get(), var36.get());

    reql_object_add(var28.get(), var31.get(), var32.get());

    reql_array_append(var0.get(), var28.get());
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test17") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 3);
  }

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[1]);
    const ReQL_Byte src6[] = "a";
    reql_string_init(var6.get(), buf6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[2]);
    const ReQL_Byte src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 96);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[5]);
    const ReQL_Byte src11[] = "group";
    reql_string_init(var11.get(), buf11.get(), src11, 5);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[9]);
    const ReQL_Byte src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), src13, 9);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[1]);
    const ReQL_Byte src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), src15, 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[2]);
    const ReQL_Byte src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 97);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[5]);
    const ReQL_Byte src20[] = "group";
    reql_string_init(var20.get(), buf20.get(), src20, 5);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 2);

    reql_object_add(var19.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[9]);
    const ReQL_Byte src22[] = "reduction";
    reql_string_init(var22.get(), buf22.get(), src22, 9);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair23(new ReQL_Pair_t[2]);
    reql_object_init(var23.get(), pair23.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[1]);
    const ReQL_Byte src24[] = "a";
    reql_string_init(var24.get(), buf24.get(), src24, 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[2]);
    const ReQL_Byte src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), src26, 2);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 98);

    reql_object_add(var23.get(), var26.get(), var27.get());

    reql_object_add(var19.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair28(new ReQL_Pair_t[2]);
    reql_object_init(var28.get(), pair28.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf29(new ReQL_Byte[5]);
    const ReQL_Byte src29[] = "group";
    reql_string_init(var29.get(), buf29.get(), src29, 5);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[9]);
    const ReQL_Byte src31[] = "reduction";
    reql_string_init(var31.get(), buf31.get(), src31, 9);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair32(new ReQL_Pair_t[2]);
    reql_object_init(var32.get(), pair32.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf33(new ReQL_Byte[1]);
    const ReQL_Byte src33[] = "a";
    reql_string_init(var33.get(), buf33.get(), src33, 1);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 3);

    reql_object_add(var32.get(), var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[2]);
    const ReQL_Byte src35[] = "id";
    reql_string_init(var35.get(), buf35.get(), src35, 2);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_number_init(var36.get(), 99);

    reql_object_add(var32.get(), var35.get(), var36.get());

    reql_object_add(var28.get(), var31.get(), var32.get());

    reql_array_append(var0.get(), var28.get());
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[1]);
    const ReQL_Byte src6[] = "a";
    reql_string_init(var6.get(), buf6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[2]);
    const ReQL_Byte src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[5]);
    const ReQL_Byte src11[] = "group";
    reql_string_init(var11.get(), buf11.get(), src11, 5);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[9]);
    const ReQL_Byte src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), src13, 9);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[1]);
    const ReQL_Byte src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), src15, 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[2]);
    const ReQL_Byte src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 1);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[5]);
    const ReQL_Byte src20[] = "group";
    reql_string_init(var20.get(), buf20.get(), src20, 5);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 2);

    reql_object_add(var19.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[9]);
    const ReQL_Byte src22[] = "reduction";
    reql_string_init(var22.get(), buf22.get(), src22, 9);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair23(new ReQL_Pair_t[2]);
    reql_object_init(var23.get(), pair23.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[1]);
    const ReQL_Byte src24[] = "a";
    reql_string_init(var24.get(), buf24.get(), src24, 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[2]);
    const ReQL_Byte src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), src26, 2);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 2);

    reql_object_add(var23.get(), var26.get(), var27.get());

    reql_object_add(var19.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair28(new ReQL_Pair_t[2]);
    reql_object_init(var28.get(), pair28.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf29(new ReQL_Byte[5]);
    const ReQL_Byte src29[] = "group";
    reql_string_init(var29.get(), buf29.get(), src29, 5);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[9]);
    const ReQL_Byte src31[] = "reduction";
    reql_string_init(var31.get(), buf31.get(), src31, 9);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair32(new ReQL_Pair_t[2]);
    reql_object_init(var32.get(), pair32.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf33(new ReQL_Byte[1]);
    const ReQL_Byte src33[] = "a";
    reql_string_init(var33.get(), buf33.get(), src33, 1);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 3);

    reql_object_add(var32.get(), var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[2]);
    const ReQL_Byte src35[] = "id";
    reql_string_init(var35.get(), buf35.get(), src35, 2);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_number_init(var36.get(), 3);

    reql_object_add(var32.get(), var35.get(), var36.get());

    reql_object_add(var28.get(), var31.get(), var32.get());

    reql_array_append(var0.get(), var28.get());
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[1]);
    const ReQL_Byte src6[] = "a";
    reql_string_init(var6.get(), buf6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[2]);
    const ReQL_Byte src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 96);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[5]);
    const ReQL_Byte src11[] = "group";
    reql_string_init(var11.get(), buf11.get(), src11, 5);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[9]);
    const ReQL_Byte src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), src13, 9);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[1]);
    const ReQL_Byte src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), src15, 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[2]);
    const ReQL_Byte src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 97);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[5]);
    const ReQL_Byte src20[] = "group";
    reql_string_init(var20.get(), buf20.get(), src20, 5);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 2);

    reql_object_add(var19.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[9]);
    const ReQL_Byte src22[] = "reduction";
    reql_string_init(var22.get(), buf22.get(), src22, 9);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair23(new ReQL_Pair_t[2]);
    reql_object_init(var23.get(), pair23.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf24(new ReQL_Byte[1]);
    const ReQL_Byte src24[] = "a";
    reql_string_init(var24.get(), buf24.get(), src24, 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[2]);
    const ReQL_Byte src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), src26, 2);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 98);

    reql_object_add(var23.get(), var26.get(), var27.get());

    reql_object_add(var19.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair28(new ReQL_Pair_t[2]);
    reql_object_init(var28.get(), pair28.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf29(new ReQL_Byte[5]);
    const ReQL_Byte src29[] = "group";
    reql_string_init(var29.get(), buf29.get(), src29, 5);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf31(new ReQL_Byte[9]);
    const ReQL_Byte src31[] = "reduction";
    reql_string_init(var31.get(), buf31.get(), src31, 9);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair32(new ReQL_Pair_t[2]);
    reql_object_init(var32.get(), pair32.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf33(new ReQL_Byte[1]);
    const ReQL_Byte src33[] = "a";
    reql_string_init(var33.get(), buf33.get(), src33, 1);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 3);

    reql_object_add(var32.get(), var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf35(new ReQL_Byte[2]);
    const ReQL_Byte src35[] = "id";
    reql_string_init(var35.get(), buf35.get(), src35, 2);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_number_init(var36.get(), 99);

    reql_object_add(var32.get(), var35.get(), var36.get());

    reql_object_add(var28.get(), var31.get(), var32.get());

    reql_array_append(var0.get(), var28.get());
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 150);
  }

  SECTION("test24") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 150);
  }

  SECTION("test25") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1200);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1225);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1250);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 1275);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test26") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test27") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test28") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 48);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 49);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 50);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 51);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test29") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 96);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test30") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test31") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test32") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 0);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 2);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 3);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test33") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 3);
  }

  SECTION("test34") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 3);
  }

  SECTION("test35") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 96);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 97);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 98);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 99);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test36") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1200);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1225);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1250);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 1275);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test37") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1200);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1225);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 1250);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1275);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test38") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 1);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[1]);
    reql_array_init(var7.get(), arr7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[1]);
    reql_object_init(var8.get(), pair8.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[1]);
    const ReQL_Byte src9[] = "a";
    reql_string_init(var9.get(), buf9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1);

    reql_object_add(var8.get(), var9.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test39") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[14]);
    const ReQL_Byte src0[] = "GROUPED_STREAM";
    reql_string_init(var0.get(), buf0.get(), src0, 14);
  }

  SECTION("test40") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[12]);
    const ReQL_Byte src0[] = "GROUPED_DATA";
    reql_string_init(var0.get(), buf0.get(), src0, 12);
  }

  SECTION("test41") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[12]);
    const ReQL_Byte src0[] = "GROUPED_DATA";
    reql_string_init(var0.get(), buf0.get(), src0, 12);
  }

  SECTION("test42") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[3]);
    reql_array_init(var5.get(), arr5.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 4);

    reql_array_append(var5.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 8);

    reql_array_append(var5.get(), var8.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[2]);
    reql_object_init(var9.get(), pair9.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[5]);
    const ReQL_Byte src10[] = "group";
    reql_string_init(var10.get(), buf10.get(), src10, 5);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 1);

    reql_object_add(var9.get(), var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[9]);
    const ReQL_Byte src12[] = "reduction";
    reql_string_init(var12.get(), buf12.get(), src12, 9);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr13(new ReQL_Obj_t*[3]);
    reql_array_init(var13.get(), arr13.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 1);

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 5);

    reql_array_append(var13.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 9);

    reql_array_append(var13.get(), var16.get());

    reql_object_add(var9.get(), var12.get(), var13.get());

    reql_array_append(var0.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair17(new ReQL_Pair_t[2]);
    reql_object_init(var17.get(), pair17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[5]);
    const ReQL_Byte src18[] = "group";
    reql_string_init(var18.get(), buf18.get(), src18, 5);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 2);

    reql_object_add(var17.get(), var18.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[9]);
    const ReQL_Byte src20[] = "reduction";
    reql_string_init(var20.get(), buf20.get(), src20, 9);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[2]);
    reql_array_init(var21.get(), arr21.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 2);

    reql_array_append(var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 6);

    reql_array_append(var21.get(), var23.get());

    reql_object_add(var17.get(), var20.get(), var21.get());

    reql_array_append(var0.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair24(new ReQL_Pair_t[2]);
    reql_object_init(var24.get(), pair24.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[5]);
    const ReQL_Byte src25[] = "group";
    reql_string_init(var25.get(), buf25.get(), src25, 5);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 3);

    reql_object_add(var24.get(), var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf27(new ReQL_Byte[9]);
    const ReQL_Byte src27[] = "reduction";
    reql_string_init(var27.get(), buf27.get(), src27, 9);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr28(new ReQL_Obj_t*[2]);
    reql_array_init(var28.get(), arr28.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_number_init(var29.get(), 3);

    reql_array_append(var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_number_init(var30.get(), 7);

    reql_array_append(var28.get(), var30.get());

    reql_object_add(var24.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var24.get());
  }

  SECTION("test43") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 9);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 9);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 4);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 4);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test44") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2400);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 2450);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2500);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 2550);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test45") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2400);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 2450);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2500);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 2550);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test46") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2400);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 2450);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2500);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 2550);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test47") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1200);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1225);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 1250);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1275);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test49") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 25);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 25);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 25);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 25);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test50") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1200);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1225);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 1250);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1275);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test51") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 48);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 49);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 50);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 51);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test52") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[5]);
    reql_array_init(var4.get(), arr4.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 20);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 20);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 20);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 20);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 4);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 20);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var4.get(), var17.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test53") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[12]);
    reql_array_init(var4.get(), arr4.get(), 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr6(new ReQL_Obj_t*[2]);
    reql_array_init(var6.get(), arr6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_array_append(var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0);

    reql_array_append(var6.get(), var8.get());

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 9);

    reql_array_append(var5.get(), var9.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 1);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 8);

    reql_array_append(var10.get(), var14.get());

    reql_array_append(var4.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr16(new ReQL_Obj_t*[2]);
    reql_array_init(var16.get(), arr16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 0);

    reql_array_append(var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 2);

    reql_array_append(var16.get(), var18.get());

    reql_array_append(var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 8);

    reql_array_append(var15.get(), var19.get());

    reql_array_append(var4.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[2]);
    reql_array_init(var21.get(), arr21.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 1);

    reql_array_append(var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 0);

    reql_array_append(var21.get(), var23.get());

    reql_array_append(var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 8);

    reql_array_append(var20.get(), var24.get());

    reql_array_append(var4.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr25(new ReQL_Obj_t*[2]);
    reql_array_init(var25.get(), arr25.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr26(new ReQL_Obj_t*[2]);
    reql_array_init(var26.get(), arr26.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 1);

    reql_array_append(var26.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 1);

    reql_array_append(var26.get(), var28.get());

    reql_array_append(var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_number_init(var29.get(), 9);

    reql_array_append(var25.get(), var29.get());

    reql_array_append(var4.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr30(new ReQL_Obj_t*[2]);
    reql_array_init(var30.get(), arr30.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_number_init(var32.get(), 1);

    reql_array_append(var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_number_init(var33.get(), 2);

    reql_array_append(var31.get(), var33.get());

    reql_array_append(var30.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 8);

    reql_array_append(var30.get(), var34.get());

    reql_array_append(var4.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr35(new ReQL_Obj_t*[2]);
    reql_array_init(var35.get(), arr35.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr36(new ReQL_Obj_t*[2]);
    reql_array_init(var36.get(), arr36.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_number_init(var37.get(), 2);

    reql_array_append(var36.get(), var37.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    reql_number_init(var38.get(), 0);

    reql_array_append(var36.get(), var38.get());

    reql_array_append(var35.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_number_init(var39.get(), 8);

    reql_array_append(var35.get(), var39.get());

    reql_array_append(var4.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr40(new ReQL_Obj_t*[2]);
    reql_array_init(var40.get(), arr40.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr41(new ReQL_Obj_t*[2]);
    reql_array_init(var41.get(), arr41.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_number_init(var42.get(), 2);

    reql_array_append(var41.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    reql_number_init(var43.get(), 1);

    reql_array_append(var41.get(), var43.get());

    reql_array_append(var40.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    reql_number_init(var44.get(), 8);

    reql_array_append(var40.get(), var44.get());

    reql_array_append(var4.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr45(new ReQL_Obj_t*[2]);
    reql_array_init(var45.get(), arr45.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr46(new ReQL_Obj_t*[2]);
    reql_array_init(var46.get(), arr46.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_number_init(var47.get(), 2);

    reql_array_append(var46.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_number_init(var48.get(), 2);

    reql_array_append(var46.get(), var48.get());

    reql_array_append(var45.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    reql_number_init(var49.get(), 9);

    reql_array_append(var45.get(), var49.get());

    reql_array_append(var4.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr50(new ReQL_Obj_t*[2]);
    reql_array_init(var50.get(), arr50.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr51(new ReQL_Obj_t*[2]);
    reql_array_init(var51.get(), arr51.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    reql_number_init(var52.get(), 3);

    reql_array_append(var51.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_number_init(var53.get(), 0);

    reql_array_append(var51.get(), var53.get());

    reql_array_append(var50.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    reql_number_init(var54.get(), 9);

    reql_array_append(var50.get(), var54.get());

    reql_array_append(var4.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr55(new ReQL_Obj_t*[2]);
    reql_array_init(var55.get(), arr55.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr56(new ReQL_Obj_t*[2]);
    reql_array_init(var56.get(), arr56.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_number_init(var57.get(), 3);

    reql_array_append(var56.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_number_init(var58.get(), 1);

    reql_array_append(var56.get(), var58.get());

    reql_array_append(var55.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    reql_number_init(var59.get(), 8);

    reql_array_append(var55.get(), var59.get());

    reql_array_append(var4.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr60(new ReQL_Obj_t*[2]);
    reql_array_init(var60.get(), arr60.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr61(new ReQL_Obj_t*[2]);
    reql_array_init(var61.get(), arr61.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    reql_number_init(var62.get(), 3);

    reql_array_append(var61.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_number_init(var63.get(), 2);

    reql_array_append(var61.get(), var63.get());

    reql_array_append(var60.get(), var61.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    reql_number_init(var64.get(), 8);

    reql_array_append(var60.get(), var64.get());

    reql_array_append(var4.get(), var60.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test55") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[6]);
    const ReQL_Byte src1[] = "result";
    reql_string_init(var1.get(), buf1.get(), src1, 6);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "error";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test57") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 4);
  }

  SECTION("test58") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[6]);
    const ReQL_Byte src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), src0, 6);
  }

  SECTION("test59") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 100);
  }

  SECTION("test60") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[6]);
    const ReQL_Byte src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), src0, 6);
  }

  SECTION("test61") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 100);
  }

  SECTION("test62") {
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

  SECTION("test65") {
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
    const ReQL_Byte src3[] = "a";
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

  SECTION("test68") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 25);
  }

  SECTION("test69") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 25);
  }

  SECTION("test81") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[6]);
    const ReQL_Byte src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), src0, 6);
  }

  SECTION("test82") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 4);
  }

  SECTION("test83") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[4]);
    const ReQL_Byte src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[3]);
    const ReQL_Byte src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test84") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[100]);
    reql_array_init(var4.get(), arr4.get(), 100);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 1);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 4);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 1);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var4.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 5);

    reql_array_append(var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 1);

    reql_array_append(var20.get(), var22.get());

    reql_array_append(var4.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr23(new ReQL_Obj_t*[2]);
    reql_array_init(var23.get(), arr23.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 6);

    reql_array_append(var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 1);

    reql_array_append(var23.get(), var25.get());

    reql_array_append(var4.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr26(new ReQL_Obj_t*[2]);
    reql_array_init(var26.get(), arr26.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 7);

    reql_array_append(var26.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 1);

    reql_array_append(var26.get(), var28.get());

    reql_array_append(var4.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr29(new ReQL_Obj_t*[2]);
    reql_array_init(var29.get(), arr29.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_number_init(var30.get(), 8);

    reql_array_append(var29.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    reql_number_init(var31.get(), 1);

    reql_array_append(var29.get(), var31.get());

    reql_array_append(var4.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr32(new ReQL_Obj_t*[2]);
    reql_array_init(var32.get(), arr32.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_number_init(var33.get(), 9);

    reql_array_append(var32.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 1);

    reql_array_append(var32.get(), var34.get());

    reql_array_append(var4.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr35(new ReQL_Obj_t*[2]);
    reql_array_init(var35.get(), arr35.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_number_init(var36.get(), 10);

    reql_array_append(var35.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_number_init(var37.get(), 1);

    reql_array_append(var35.get(), var37.get());

    reql_array_append(var4.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr38(new ReQL_Obj_t*[2]);
    reql_array_init(var38.get(), arr38.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_number_init(var39.get(), 11);

    reql_array_append(var38.get(), var39.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    reql_number_init(var40.get(), 1);

    reql_array_append(var38.get(), var40.get());

    reql_array_append(var4.get(), var38.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr41(new ReQL_Obj_t*[2]);
    reql_array_init(var41.get(), arr41.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_number_init(var42.get(), 12);

    reql_array_append(var41.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    reql_number_init(var43.get(), 1);

    reql_array_append(var41.get(), var43.get());

    reql_array_append(var4.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr44(new ReQL_Obj_t*[2]);
    reql_array_init(var44.get(), arr44.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    reql_number_init(var45.get(), 13);

    reql_array_append(var44.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    reql_number_init(var46.get(), 1);

    reql_array_append(var44.get(), var46.get());

    reql_array_append(var4.get(), var44.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr47(new ReQL_Obj_t*[2]);
    reql_array_init(var47.get(), arr47.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_number_init(var48.get(), 14);

    reql_array_append(var47.get(), var48.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    reql_number_init(var49.get(), 1);

    reql_array_append(var47.get(), var49.get());

    reql_array_append(var4.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr50(new ReQL_Obj_t*[2]);
    reql_array_init(var50.get(), arr50.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    reql_number_init(var51.get(), 15);

    reql_array_append(var50.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    reql_number_init(var52.get(), 1);

    reql_array_append(var50.get(), var52.get());

    reql_array_append(var4.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr53(new ReQL_Obj_t*[2]);
    reql_array_init(var53.get(), arr53.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    reql_number_init(var54.get(), 16);

    reql_array_append(var53.get(), var54.get());

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    reql_number_init(var55.get(), 1);

    reql_array_append(var53.get(), var55.get());

    reql_array_append(var4.get(), var53.get());

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr56(new ReQL_Obj_t*[2]);
    reql_array_init(var56.get(), arr56.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_number_init(var57.get(), 17);

    reql_array_append(var56.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_number_init(var58.get(), 1);

    reql_array_append(var56.get(), var58.get());

    reql_array_append(var4.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr59(new ReQL_Obj_t*[2]);
    reql_array_init(var59.get(), arr59.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    reql_number_init(var60.get(), 18);

    reql_array_append(var59.get(), var60.get());

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    reql_number_init(var61.get(), 1);

    reql_array_append(var59.get(), var61.get());

    reql_array_append(var4.get(), var59.get());

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr62(new ReQL_Obj_t*[2]);
    reql_array_init(var62.get(), arr62.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_number_init(var63.get(), 19);

    reql_array_append(var62.get(), var63.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    reql_number_init(var64.get(), 1);

    reql_array_append(var62.get(), var64.get());

    reql_array_append(var4.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr65(new ReQL_Obj_t*[2]);
    reql_array_init(var65.get(), arr65.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    reql_number_init(var66.get(), 20);

    reql_array_append(var65.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    reql_number_init(var67.get(), 1);

    reql_array_append(var65.get(), var67.get());

    reql_array_append(var4.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr68(new ReQL_Obj_t*[2]);
    reql_array_init(var68.get(), arr68.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    reql_number_init(var69.get(), 21);

    reql_array_append(var68.get(), var69.get());

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    reql_number_init(var70.get(), 1);

    reql_array_append(var68.get(), var70.get());

    reql_array_append(var4.get(), var68.get());

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr71(new ReQL_Obj_t*[2]);
    reql_array_init(var71.get(), arr71.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    reql_number_init(var72.get(), 22);

    reql_array_append(var71.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_number_init(var73.get(), 1);

    reql_array_append(var71.get(), var73.get());

    reql_array_append(var4.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr74(new ReQL_Obj_t*[2]);
    reql_array_init(var74.get(), arr74.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    reql_number_init(var75.get(), 23);

    reql_array_append(var74.get(), var75.get());

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    reql_number_init(var76.get(), 1);

    reql_array_append(var74.get(), var76.get());

    reql_array_append(var4.get(), var74.get());

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr77(new ReQL_Obj_t*[2]);
    reql_array_init(var77.get(), arr77.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    reql_number_init(var78.get(), 24);

    reql_array_append(var77.get(), var78.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    reql_number_init(var79.get(), 1);

    reql_array_append(var77.get(), var79.get());

    reql_array_append(var4.get(), var77.get());

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr80(new ReQL_Obj_t*[2]);
    reql_array_init(var80.get(), arr80.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    reql_number_init(var81.get(), 25);

    reql_array_append(var80.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_number_init(var82.get(), 1);

    reql_array_append(var80.get(), var82.get());

    reql_array_append(var4.get(), var80.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr83(new ReQL_Obj_t*[2]);
    reql_array_init(var83.get(), arr83.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    reql_number_init(var84.get(), 26);

    reql_array_append(var83.get(), var84.get());

    std::unique_ptr<ReQL_Obj_t> var85(new ReQL_Obj_t);
    reql_number_init(var85.get(), 1);

    reql_array_append(var83.get(), var85.get());

    reql_array_append(var4.get(), var83.get());

    std::unique_ptr<ReQL_Obj_t> var86(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr86(new ReQL_Obj_t*[2]);
    reql_array_init(var86.get(), arr86.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var87(new ReQL_Obj_t);
    reql_number_init(var87.get(), 27);

    reql_array_append(var86.get(), var87.get());

    std::unique_ptr<ReQL_Obj_t> var88(new ReQL_Obj_t);
    reql_number_init(var88.get(), 1);

    reql_array_append(var86.get(), var88.get());

    reql_array_append(var4.get(), var86.get());

    std::unique_ptr<ReQL_Obj_t> var89(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr89(new ReQL_Obj_t*[2]);
    reql_array_init(var89.get(), arr89.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var90(new ReQL_Obj_t);
    reql_number_init(var90.get(), 28);

    reql_array_append(var89.get(), var90.get());

    std::unique_ptr<ReQL_Obj_t> var91(new ReQL_Obj_t);
    reql_number_init(var91.get(), 1);

    reql_array_append(var89.get(), var91.get());

    reql_array_append(var4.get(), var89.get());

    std::unique_ptr<ReQL_Obj_t> var92(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr92(new ReQL_Obj_t*[2]);
    reql_array_init(var92.get(), arr92.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var93(new ReQL_Obj_t);
    reql_number_init(var93.get(), 29);

    reql_array_append(var92.get(), var93.get());

    std::unique_ptr<ReQL_Obj_t> var94(new ReQL_Obj_t);
    reql_number_init(var94.get(), 1);

    reql_array_append(var92.get(), var94.get());

    reql_array_append(var4.get(), var92.get());

    std::unique_ptr<ReQL_Obj_t> var95(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr95(new ReQL_Obj_t*[2]);
    reql_array_init(var95.get(), arr95.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var96(new ReQL_Obj_t);
    reql_number_init(var96.get(), 30);

    reql_array_append(var95.get(), var96.get());

    std::unique_ptr<ReQL_Obj_t> var97(new ReQL_Obj_t);
    reql_number_init(var97.get(), 1);

    reql_array_append(var95.get(), var97.get());

    reql_array_append(var4.get(), var95.get());

    std::unique_ptr<ReQL_Obj_t> var98(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr98(new ReQL_Obj_t*[2]);
    reql_array_init(var98.get(), arr98.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var99(new ReQL_Obj_t);
    reql_number_init(var99.get(), 31);

    reql_array_append(var98.get(), var99.get());

    std::unique_ptr<ReQL_Obj_t> var100(new ReQL_Obj_t);
    reql_number_init(var100.get(), 1);

    reql_array_append(var98.get(), var100.get());

    reql_array_append(var4.get(), var98.get());

    std::unique_ptr<ReQL_Obj_t> var101(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr101(new ReQL_Obj_t*[2]);
    reql_array_init(var101.get(), arr101.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var102(new ReQL_Obj_t);
    reql_number_init(var102.get(), 32);

    reql_array_append(var101.get(), var102.get());

    std::unique_ptr<ReQL_Obj_t> var103(new ReQL_Obj_t);
    reql_number_init(var103.get(), 1);

    reql_array_append(var101.get(), var103.get());

    reql_array_append(var4.get(), var101.get());

    std::unique_ptr<ReQL_Obj_t> var104(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr104(new ReQL_Obj_t*[2]);
    reql_array_init(var104.get(), arr104.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var105(new ReQL_Obj_t);
    reql_number_init(var105.get(), 33);

    reql_array_append(var104.get(), var105.get());

    std::unique_ptr<ReQL_Obj_t> var106(new ReQL_Obj_t);
    reql_number_init(var106.get(), 1);

    reql_array_append(var104.get(), var106.get());

    reql_array_append(var4.get(), var104.get());

    std::unique_ptr<ReQL_Obj_t> var107(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr107(new ReQL_Obj_t*[2]);
    reql_array_init(var107.get(), arr107.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var108(new ReQL_Obj_t);
    reql_number_init(var108.get(), 34);

    reql_array_append(var107.get(), var108.get());

    std::unique_ptr<ReQL_Obj_t> var109(new ReQL_Obj_t);
    reql_number_init(var109.get(), 1);

    reql_array_append(var107.get(), var109.get());

    reql_array_append(var4.get(), var107.get());

    std::unique_ptr<ReQL_Obj_t> var110(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr110(new ReQL_Obj_t*[2]);
    reql_array_init(var110.get(), arr110.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var111(new ReQL_Obj_t);
    reql_number_init(var111.get(), 35);

    reql_array_append(var110.get(), var111.get());

    std::unique_ptr<ReQL_Obj_t> var112(new ReQL_Obj_t);
    reql_number_init(var112.get(), 1);

    reql_array_append(var110.get(), var112.get());

    reql_array_append(var4.get(), var110.get());

    std::unique_ptr<ReQL_Obj_t> var113(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr113(new ReQL_Obj_t*[2]);
    reql_array_init(var113.get(), arr113.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var114(new ReQL_Obj_t);
    reql_number_init(var114.get(), 36);

    reql_array_append(var113.get(), var114.get());

    std::unique_ptr<ReQL_Obj_t> var115(new ReQL_Obj_t);
    reql_number_init(var115.get(), 1);

    reql_array_append(var113.get(), var115.get());

    reql_array_append(var4.get(), var113.get());

    std::unique_ptr<ReQL_Obj_t> var116(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr116(new ReQL_Obj_t*[2]);
    reql_array_init(var116.get(), arr116.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var117(new ReQL_Obj_t);
    reql_number_init(var117.get(), 37);

    reql_array_append(var116.get(), var117.get());

    std::unique_ptr<ReQL_Obj_t> var118(new ReQL_Obj_t);
    reql_number_init(var118.get(), 1);

    reql_array_append(var116.get(), var118.get());

    reql_array_append(var4.get(), var116.get());

    std::unique_ptr<ReQL_Obj_t> var119(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr119(new ReQL_Obj_t*[2]);
    reql_array_init(var119.get(), arr119.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var120(new ReQL_Obj_t);
    reql_number_init(var120.get(), 38);

    reql_array_append(var119.get(), var120.get());

    std::unique_ptr<ReQL_Obj_t> var121(new ReQL_Obj_t);
    reql_number_init(var121.get(), 1);

    reql_array_append(var119.get(), var121.get());

    reql_array_append(var4.get(), var119.get());

    std::unique_ptr<ReQL_Obj_t> var122(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr122(new ReQL_Obj_t*[2]);
    reql_array_init(var122.get(), arr122.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var123(new ReQL_Obj_t);
    reql_number_init(var123.get(), 39);

    reql_array_append(var122.get(), var123.get());

    std::unique_ptr<ReQL_Obj_t> var124(new ReQL_Obj_t);
    reql_number_init(var124.get(), 1);

    reql_array_append(var122.get(), var124.get());

    reql_array_append(var4.get(), var122.get());

    std::unique_ptr<ReQL_Obj_t> var125(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr125(new ReQL_Obj_t*[2]);
    reql_array_init(var125.get(), arr125.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var126(new ReQL_Obj_t);
    reql_number_init(var126.get(), 40);

    reql_array_append(var125.get(), var126.get());

    std::unique_ptr<ReQL_Obj_t> var127(new ReQL_Obj_t);
    reql_number_init(var127.get(), 1);

    reql_array_append(var125.get(), var127.get());

    reql_array_append(var4.get(), var125.get());

    std::unique_ptr<ReQL_Obj_t> var128(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr128(new ReQL_Obj_t*[2]);
    reql_array_init(var128.get(), arr128.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var129(new ReQL_Obj_t);
    reql_number_init(var129.get(), 41);

    reql_array_append(var128.get(), var129.get());

    std::unique_ptr<ReQL_Obj_t> var130(new ReQL_Obj_t);
    reql_number_init(var130.get(), 1);

    reql_array_append(var128.get(), var130.get());

    reql_array_append(var4.get(), var128.get());

    std::unique_ptr<ReQL_Obj_t> var131(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr131(new ReQL_Obj_t*[2]);
    reql_array_init(var131.get(), arr131.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var132(new ReQL_Obj_t);
    reql_number_init(var132.get(), 42);

    reql_array_append(var131.get(), var132.get());

    std::unique_ptr<ReQL_Obj_t> var133(new ReQL_Obj_t);
    reql_number_init(var133.get(), 1);

    reql_array_append(var131.get(), var133.get());

    reql_array_append(var4.get(), var131.get());

    std::unique_ptr<ReQL_Obj_t> var134(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr134(new ReQL_Obj_t*[2]);
    reql_array_init(var134.get(), arr134.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var135(new ReQL_Obj_t);
    reql_number_init(var135.get(), 43);

    reql_array_append(var134.get(), var135.get());

    std::unique_ptr<ReQL_Obj_t> var136(new ReQL_Obj_t);
    reql_number_init(var136.get(), 1);

    reql_array_append(var134.get(), var136.get());

    reql_array_append(var4.get(), var134.get());

    std::unique_ptr<ReQL_Obj_t> var137(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr137(new ReQL_Obj_t*[2]);
    reql_array_init(var137.get(), arr137.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var138(new ReQL_Obj_t);
    reql_number_init(var138.get(), 44);

    reql_array_append(var137.get(), var138.get());

    std::unique_ptr<ReQL_Obj_t> var139(new ReQL_Obj_t);
    reql_number_init(var139.get(), 1);

    reql_array_append(var137.get(), var139.get());

    reql_array_append(var4.get(), var137.get());

    std::unique_ptr<ReQL_Obj_t> var140(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr140(new ReQL_Obj_t*[2]);
    reql_array_init(var140.get(), arr140.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var141(new ReQL_Obj_t);
    reql_number_init(var141.get(), 45);

    reql_array_append(var140.get(), var141.get());

    std::unique_ptr<ReQL_Obj_t> var142(new ReQL_Obj_t);
    reql_number_init(var142.get(), 1);

    reql_array_append(var140.get(), var142.get());

    reql_array_append(var4.get(), var140.get());

    std::unique_ptr<ReQL_Obj_t> var143(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr143(new ReQL_Obj_t*[2]);
    reql_array_init(var143.get(), arr143.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var144(new ReQL_Obj_t);
    reql_number_init(var144.get(), 46);

    reql_array_append(var143.get(), var144.get());

    std::unique_ptr<ReQL_Obj_t> var145(new ReQL_Obj_t);
    reql_number_init(var145.get(), 1);

    reql_array_append(var143.get(), var145.get());

    reql_array_append(var4.get(), var143.get());

    std::unique_ptr<ReQL_Obj_t> var146(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr146(new ReQL_Obj_t*[2]);
    reql_array_init(var146.get(), arr146.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var147(new ReQL_Obj_t);
    reql_number_init(var147.get(), 47);

    reql_array_append(var146.get(), var147.get());

    std::unique_ptr<ReQL_Obj_t> var148(new ReQL_Obj_t);
    reql_number_init(var148.get(), 1);

    reql_array_append(var146.get(), var148.get());

    reql_array_append(var4.get(), var146.get());

    std::unique_ptr<ReQL_Obj_t> var149(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr149(new ReQL_Obj_t*[2]);
    reql_array_init(var149.get(), arr149.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var150(new ReQL_Obj_t);
    reql_number_init(var150.get(), 48);

    reql_array_append(var149.get(), var150.get());

    std::unique_ptr<ReQL_Obj_t> var151(new ReQL_Obj_t);
    reql_number_init(var151.get(), 1);

    reql_array_append(var149.get(), var151.get());

    reql_array_append(var4.get(), var149.get());

    std::unique_ptr<ReQL_Obj_t> var152(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr152(new ReQL_Obj_t*[2]);
    reql_array_init(var152.get(), arr152.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var153(new ReQL_Obj_t);
    reql_number_init(var153.get(), 49);

    reql_array_append(var152.get(), var153.get());

    std::unique_ptr<ReQL_Obj_t> var154(new ReQL_Obj_t);
    reql_number_init(var154.get(), 1);

    reql_array_append(var152.get(), var154.get());

    reql_array_append(var4.get(), var152.get());

    std::unique_ptr<ReQL_Obj_t> var155(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr155(new ReQL_Obj_t*[2]);
    reql_array_init(var155.get(), arr155.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var156(new ReQL_Obj_t);
    reql_number_init(var156.get(), 50);

    reql_array_append(var155.get(), var156.get());

    std::unique_ptr<ReQL_Obj_t> var157(new ReQL_Obj_t);
    reql_number_init(var157.get(), 1);

    reql_array_append(var155.get(), var157.get());

    reql_array_append(var4.get(), var155.get());

    std::unique_ptr<ReQL_Obj_t> var158(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr158(new ReQL_Obj_t*[2]);
    reql_array_init(var158.get(), arr158.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var159(new ReQL_Obj_t);
    reql_number_init(var159.get(), 51);

    reql_array_append(var158.get(), var159.get());

    std::unique_ptr<ReQL_Obj_t> var160(new ReQL_Obj_t);
    reql_number_init(var160.get(), 1);

    reql_array_append(var158.get(), var160.get());

    reql_array_append(var4.get(), var158.get());

    std::unique_ptr<ReQL_Obj_t> var161(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr161(new ReQL_Obj_t*[2]);
    reql_array_init(var161.get(), arr161.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var162(new ReQL_Obj_t);
    reql_number_init(var162.get(), 52);

    reql_array_append(var161.get(), var162.get());

    std::unique_ptr<ReQL_Obj_t> var163(new ReQL_Obj_t);
    reql_number_init(var163.get(), 1);

    reql_array_append(var161.get(), var163.get());

    reql_array_append(var4.get(), var161.get());

    std::unique_ptr<ReQL_Obj_t> var164(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr164(new ReQL_Obj_t*[2]);
    reql_array_init(var164.get(), arr164.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var165(new ReQL_Obj_t);
    reql_number_init(var165.get(), 53);

    reql_array_append(var164.get(), var165.get());

    std::unique_ptr<ReQL_Obj_t> var166(new ReQL_Obj_t);
    reql_number_init(var166.get(), 1);

    reql_array_append(var164.get(), var166.get());

    reql_array_append(var4.get(), var164.get());

    std::unique_ptr<ReQL_Obj_t> var167(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr167(new ReQL_Obj_t*[2]);
    reql_array_init(var167.get(), arr167.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var168(new ReQL_Obj_t);
    reql_number_init(var168.get(), 54);

    reql_array_append(var167.get(), var168.get());

    std::unique_ptr<ReQL_Obj_t> var169(new ReQL_Obj_t);
    reql_number_init(var169.get(), 1);

    reql_array_append(var167.get(), var169.get());

    reql_array_append(var4.get(), var167.get());

    std::unique_ptr<ReQL_Obj_t> var170(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr170(new ReQL_Obj_t*[2]);
    reql_array_init(var170.get(), arr170.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var171(new ReQL_Obj_t);
    reql_number_init(var171.get(), 55);

    reql_array_append(var170.get(), var171.get());

    std::unique_ptr<ReQL_Obj_t> var172(new ReQL_Obj_t);
    reql_number_init(var172.get(), 1);

    reql_array_append(var170.get(), var172.get());

    reql_array_append(var4.get(), var170.get());

    std::unique_ptr<ReQL_Obj_t> var173(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr173(new ReQL_Obj_t*[2]);
    reql_array_init(var173.get(), arr173.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var174(new ReQL_Obj_t);
    reql_number_init(var174.get(), 56);

    reql_array_append(var173.get(), var174.get());

    std::unique_ptr<ReQL_Obj_t> var175(new ReQL_Obj_t);
    reql_number_init(var175.get(), 1);

    reql_array_append(var173.get(), var175.get());

    reql_array_append(var4.get(), var173.get());

    std::unique_ptr<ReQL_Obj_t> var176(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr176(new ReQL_Obj_t*[2]);
    reql_array_init(var176.get(), arr176.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var177(new ReQL_Obj_t);
    reql_number_init(var177.get(), 57);

    reql_array_append(var176.get(), var177.get());

    std::unique_ptr<ReQL_Obj_t> var178(new ReQL_Obj_t);
    reql_number_init(var178.get(), 1);

    reql_array_append(var176.get(), var178.get());

    reql_array_append(var4.get(), var176.get());

    std::unique_ptr<ReQL_Obj_t> var179(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr179(new ReQL_Obj_t*[2]);
    reql_array_init(var179.get(), arr179.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var180(new ReQL_Obj_t);
    reql_number_init(var180.get(), 58);

    reql_array_append(var179.get(), var180.get());

    std::unique_ptr<ReQL_Obj_t> var181(new ReQL_Obj_t);
    reql_number_init(var181.get(), 1);

    reql_array_append(var179.get(), var181.get());

    reql_array_append(var4.get(), var179.get());

    std::unique_ptr<ReQL_Obj_t> var182(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr182(new ReQL_Obj_t*[2]);
    reql_array_init(var182.get(), arr182.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var183(new ReQL_Obj_t);
    reql_number_init(var183.get(), 59);

    reql_array_append(var182.get(), var183.get());

    std::unique_ptr<ReQL_Obj_t> var184(new ReQL_Obj_t);
    reql_number_init(var184.get(), 1);

    reql_array_append(var182.get(), var184.get());

    reql_array_append(var4.get(), var182.get());

    std::unique_ptr<ReQL_Obj_t> var185(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr185(new ReQL_Obj_t*[2]);
    reql_array_init(var185.get(), arr185.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var186(new ReQL_Obj_t);
    reql_number_init(var186.get(), 60);

    reql_array_append(var185.get(), var186.get());

    std::unique_ptr<ReQL_Obj_t> var187(new ReQL_Obj_t);
    reql_number_init(var187.get(), 1);

    reql_array_append(var185.get(), var187.get());

    reql_array_append(var4.get(), var185.get());

    std::unique_ptr<ReQL_Obj_t> var188(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr188(new ReQL_Obj_t*[2]);
    reql_array_init(var188.get(), arr188.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var189(new ReQL_Obj_t);
    reql_number_init(var189.get(), 61);

    reql_array_append(var188.get(), var189.get());

    std::unique_ptr<ReQL_Obj_t> var190(new ReQL_Obj_t);
    reql_number_init(var190.get(), 1);

    reql_array_append(var188.get(), var190.get());

    reql_array_append(var4.get(), var188.get());

    std::unique_ptr<ReQL_Obj_t> var191(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr191(new ReQL_Obj_t*[2]);
    reql_array_init(var191.get(), arr191.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var192(new ReQL_Obj_t);
    reql_number_init(var192.get(), 62);

    reql_array_append(var191.get(), var192.get());

    std::unique_ptr<ReQL_Obj_t> var193(new ReQL_Obj_t);
    reql_number_init(var193.get(), 1);

    reql_array_append(var191.get(), var193.get());

    reql_array_append(var4.get(), var191.get());

    std::unique_ptr<ReQL_Obj_t> var194(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr194(new ReQL_Obj_t*[2]);
    reql_array_init(var194.get(), arr194.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var195(new ReQL_Obj_t);
    reql_number_init(var195.get(), 63);

    reql_array_append(var194.get(), var195.get());

    std::unique_ptr<ReQL_Obj_t> var196(new ReQL_Obj_t);
    reql_number_init(var196.get(), 1);

    reql_array_append(var194.get(), var196.get());

    reql_array_append(var4.get(), var194.get());

    std::unique_ptr<ReQL_Obj_t> var197(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr197(new ReQL_Obj_t*[2]);
    reql_array_init(var197.get(), arr197.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var198(new ReQL_Obj_t);
    reql_number_init(var198.get(), 64);

    reql_array_append(var197.get(), var198.get());

    std::unique_ptr<ReQL_Obj_t> var199(new ReQL_Obj_t);
    reql_number_init(var199.get(), 1);

    reql_array_append(var197.get(), var199.get());

    reql_array_append(var4.get(), var197.get());

    std::unique_ptr<ReQL_Obj_t> var200(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr200(new ReQL_Obj_t*[2]);
    reql_array_init(var200.get(), arr200.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var201(new ReQL_Obj_t);
    reql_number_init(var201.get(), 65);

    reql_array_append(var200.get(), var201.get());

    std::unique_ptr<ReQL_Obj_t> var202(new ReQL_Obj_t);
    reql_number_init(var202.get(), 1);

    reql_array_append(var200.get(), var202.get());

    reql_array_append(var4.get(), var200.get());

    std::unique_ptr<ReQL_Obj_t> var203(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr203(new ReQL_Obj_t*[2]);
    reql_array_init(var203.get(), arr203.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var204(new ReQL_Obj_t);
    reql_number_init(var204.get(), 66);

    reql_array_append(var203.get(), var204.get());

    std::unique_ptr<ReQL_Obj_t> var205(new ReQL_Obj_t);
    reql_number_init(var205.get(), 1);

    reql_array_append(var203.get(), var205.get());

    reql_array_append(var4.get(), var203.get());

    std::unique_ptr<ReQL_Obj_t> var206(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr206(new ReQL_Obj_t*[2]);
    reql_array_init(var206.get(), arr206.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var207(new ReQL_Obj_t);
    reql_number_init(var207.get(), 67);

    reql_array_append(var206.get(), var207.get());

    std::unique_ptr<ReQL_Obj_t> var208(new ReQL_Obj_t);
    reql_number_init(var208.get(), 1);

    reql_array_append(var206.get(), var208.get());

    reql_array_append(var4.get(), var206.get());

    std::unique_ptr<ReQL_Obj_t> var209(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr209(new ReQL_Obj_t*[2]);
    reql_array_init(var209.get(), arr209.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var210(new ReQL_Obj_t);
    reql_number_init(var210.get(), 68);

    reql_array_append(var209.get(), var210.get());

    std::unique_ptr<ReQL_Obj_t> var211(new ReQL_Obj_t);
    reql_number_init(var211.get(), 1);

    reql_array_append(var209.get(), var211.get());

    reql_array_append(var4.get(), var209.get());

    std::unique_ptr<ReQL_Obj_t> var212(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr212(new ReQL_Obj_t*[2]);
    reql_array_init(var212.get(), arr212.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var213(new ReQL_Obj_t);
    reql_number_init(var213.get(), 69);

    reql_array_append(var212.get(), var213.get());

    std::unique_ptr<ReQL_Obj_t> var214(new ReQL_Obj_t);
    reql_number_init(var214.get(), 1);

    reql_array_append(var212.get(), var214.get());

    reql_array_append(var4.get(), var212.get());

    std::unique_ptr<ReQL_Obj_t> var215(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr215(new ReQL_Obj_t*[2]);
    reql_array_init(var215.get(), arr215.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var216(new ReQL_Obj_t);
    reql_number_init(var216.get(), 70);

    reql_array_append(var215.get(), var216.get());

    std::unique_ptr<ReQL_Obj_t> var217(new ReQL_Obj_t);
    reql_number_init(var217.get(), 1);

    reql_array_append(var215.get(), var217.get());

    reql_array_append(var4.get(), var215.get());

    std::unique_ptr<ReQL_Obj_t> var218(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr218(new ReQL_Obj_t*[2]);
    reql_array_init(var218.get(), arr218.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var219(new ReQL_Obj_t);
    reql_number_init(var219.get(), 71);

    reql_array_append(var218.get(), var219.get());

    std::unique_ptr<ReQL_Obj_t> var220(new ReQL_Obj_t);
    reql_number_init(var220.get(), 1);

    reql_array_append(var218.get(), var220.get());

    reql_array_append(var4.get(), var218.get());

    std::unique_ptr<ReQL_Obj_t> var221(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr221(new ReQL_Obj_t*[2]);
    reql_array_init(var221.get(), arr221.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var222(new ReQL_Obj_t);
    reql_number_init(var222.get(), 72);

    reql_array_append(var221.get(), var222.get());

    std::unique_ptr<ReQL_Obj_t> var223(new ReQL_Obj_t);
    reql_number_init(var223.get(), 1);

    reql_array_append(var221.get(), var223.get());

    reql_array_append(var4.get(), var221.get());

    std::unique_ptr<ReQL_Obj_t> var224(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr224(new ReQL_Obj_t*[2]);
    reql_array_init(var224.get(), arr224.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var225(new ReQL_Obj_t);
    reql_number_init(var225.get(), 73);

    reql_array_append(var224.get(), var225.get());

    std::unique_ptr<ReQL_Obj_t> var226(new ReQL_Obj_t);
    reql_number_init(var226.get(), 1);

    reql_array_append(var224.get(), var226.get());

    reql_array_append(var4.get(), var224.get());

    std::unique_ptr<ReQL_Obj_t> var227(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr227(new ReQL_Obj_t*[2]);
    reql_array_init(var227.get(), arr227.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var228(new ReQL_Obj_t);
    reql_number_init(var228.get(), 74);

    reql_array_append(var227.get(), var228.get());

    std::unique_ptr<ReQL_Obj_t> var229(new ReQL_Obj_t);
    reql_number_init(var229.get(), 1);

    reql_array_append(var227.get(), var229.get());

    reql_array_append(var4.get(), var227.get());

    std::unique_ptr<ReQL_Obj_t> var230(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr230(new ReQL_Obj_t*[2]);
    reql_array_init(var230.get(), arr230.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var231(new ReQL_Obj_t);
    reql_number_init(var231.get(), 75);

    reql_array_append(var230.get(), var231.get());

    std::unique_ptr<ReQL_Obj_t> var232(new ReQL_Obj_t);
    reql_number_init(var232.get(), 1);

    reql_array_append(var230.get(), var232.get());

    reql_array_append(var4.get(), var230.get());

    std::unique_ptr<ReQL_Obj_t> var233(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr233(new ReQL_Obj_t*[2]);
    reql_array_init(var233.get(), arr233.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var234(new ReQL_Obj_t);
    reql_number_init(var234.get(), 76);

    reql_array_append(var233.get(), var234.get());

    std::unique_ptr<ReQL_Obj_t> var235(new ReQL_Obj_t);
    reql_number_init(var235.get(), 1);

    reql_array_append(var233.get(), var235.get());

    reql_array_append(var4.get(), var233.get());

    std::unique_ptr<ReQL_Obj_t> var236(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr236(new ReQL_Obj_t*[2]);
    reql_array_init(var236.get(), arr236.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var237(new ReQL_Obj_t);
    reql_number_init(var237.get(), 77);

    reql_array_append(var236.get(), var237.get());

    std::unique_ptr<ReQL_Obj_t> var238(new ReQL_Obj_t);
    reql_number_init(var238.get(), 1);

    reql_array_append(var236.get(), var238.get());

    reql_array_append(var4.get(), var236.get());

    std::unique_ptr<ReQL_Obj_t> var239(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr239(new ReQL_Obj_t*[2]);
    reql_array_init(var239.get(), arr239.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var240(new ReQL_Obj_t);
    reql_number_init(var240.get(), 78);

    reql_array_append(var239.get(), var240.get());

    std::unique_ptr<ReQL_Obj_t> var241(new ReQL_Obj_t);
    reql_number_init(var241.get(), 1);

    reql_array_append(var239.get(), var241.get());

    reql_array_append(var4.get(), var239.get());

    std::unique_ptr<ReQL_Obj_t> var242(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr242(new ReQL_Obj_t*[2]);
    reql_array_init(var242.get(), arr242.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var243(new ReQL_Obj_t);
    reql_number_init(var243.get(), 79);

    reql_array_append(var242.get(), var243.get());

    std::unique_ptr<ReQL_Obj_t> var244(new ReQL_Obj_t);
    reql_number_init(var244.get(), 1);

    reql_array_append(var242.get(), var244.get());

    reql_array_append(var4.get(), var242.get());

    std::unique_ptr<ReQL_Obj_t> var245(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr245(new ReQL_Obj_t*[2]);
    reql_array_init(var245.get(), arr245.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var246(new ReQL_Obj_t);
    reql_number_init(var246.get(), 80);

    reql_array_append(var245.get(), var246.get());

    std::unique_ptr<ReQL_Obj_t> var247(new ReQL_Obj_t);
    reql_number_init(var247.get(), 1);

    reql_array_append(var245.get(), var247.get());

    reql_array_append(var4.get(), var245.get());

    std::unique_ptr<ReQL_Obj_t> var248(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr248(new ReQL_Obj_t*[2]);
    reql_array_init(var248.get(), arr248.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var249(new ReQL_Obj_t);
    reql_number_init(var249.get(), 81);

    reql_array_append(var248.get(), var249.get());

    std::unique_ptr<ReQL_Obj_t> var250(new ReQL_Obj_t);
    reql_number_init(var250.get(), 1);

    reql_array_append(var248.get(), var250.get());

    reql_array_append(var4.get(), var248.get());

    std::unique_ptr<ReQL_Obj_t> var251(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr251(new ReQL_Obj_t*[2]);
    reql_array_init(var251.get(), arr251.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var252(new ReQL_Obj_t);
    reql_number_init(var252.get(), 82);

    reql_array_append(var251.get(), var252.get());

    std::unique_ptr<ReQL_Obj_t> var253(new ReQL_Obj_t);
    reql_number_init(var253.get(), 1);

    reql_array_append(var251.get(), var253.get());

    reql_array_append(var4.get(), var251.get());

    std::unique_ptr<ReQL_Obj_t> var254(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr254(new ReQL_Obj_t*[2]);
    reql_array_init(var254.get(), arr254.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var255(new ReQL_Obj_t);
    reql_number_init(var255.get(), 83);

    reql_array_append(var254.get(), var255.get());

    std::unique_ptr<ReQL_Obj_t> var256(new ReQL_Obj_t);
    reql_number_init(var256.get(), 1);

    reql_array_append(var254.get(), var256.get());

    reql_array_append(var4.get(), var254.get());

    std::unique_ptr<ReQL_Obj_t> var257(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr257(new ReQL_Obj_t*[2]);
    reql_array_init(var257.get(), arr257.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var258(new ReQL_Obj_t);
    reql_number_init(var258.get(), 84);

    reql_array_append(var257.get(), var258.get());

    std::unique_ptr<ReQL_Obj_t> var259(new ReQL_Obj_t);
    reql_number_init(var259.get(), 1);

    reql_array_append(var257.get(), var259.get());

    reql_array_append(var4.get(), var257.get());

    std::unique_ptr<ReQL_Obj_t> var260(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr260(new ReQL_Obj_t*[2]);
    reql_array_init(var260.get(), arr260.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var261(new ReQL_Obj_t);
    reql_number_init(var261.get(), 85);

    reql_array_append(var260.get(), var261.get());

    std::unique_ptr<ReQL_Obj_t> var262(new ReQL_Obj_t);
    reql_number_init(var262.get(), 1);

    reql_array_append(var260.get(), var262.get());

    reql_array_append(var4.get(), var260.get());

    std::unique_ptr<ReQL_Obj_t> var263(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr263(new ReQL_Obj_t*[2]);
    reql_array_init(var263.get(), arr263.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var264(new ReQL_Obj_t);
    reql_number_init(var264.get(), 86);

    reql_array_append(var263.get(), var264.get());

    std::unique_ptr<ReQL_Obj_t> var265(new ReQL_Obj_t);
    reql_number_init(var265.get(), 1);

    reql_array_append(var263.get(), var265.get());

    reql_array_append(var4.get(), var263.get());

    std::unique_ptr<ReQL_Obj_t> var266(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr266(new ReQL_Obj_t*[2]);
    reql_array_init(var266.get(), arr266.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var267(new ReQL_Obj_t);
    reql_number_init(var267.get(), 87);

    reql_array_append(var266.get(), var267.get());

    std::unique_ptr<ReQL_Obj_t> var268(new ReQL_Obj_t);
    reql_number_init(var268.get(), 1);

    reql_array_append(var266.get(), var268.get());

    reql_array_append(var4.get(), var266.get());

    std::unique_ptr<ReQL_Obj_t> var269(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr269(new ReQL_Obj_t*[2]);
    reql_array_init(var269.get(), arr269.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var270(new ReQL_Obj_t);
    reql_number_init(var270.get(), 88);

    reql_array_append(var269.get(), var270.get());

    std::unique_ptr<ReQL_Obj_t> var271(new ReQL_Obj_t);
    reql_number_init(var271.get(), 1);

    reql_array_append(var269.get(), var271.get());

    reql_array_append(var4.get(), var269.get());

    std::unique_ptr<ReQL_Obj_t> var272(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr272(new ReQL_Obj_t*[2]);
    reql_array_init(var272.get(), arr272.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var273(new ReQL_Obj_t);
    reql_number_init(var273.get(), 89);

    reql_array_append(var272.get(), var273.get());

    std::unique_ptr<ReQL_Obj_t> var274(new ReQL_Obj_t);
    reql_number_init(var274.get(), 1);

    reql_array_append(var272.get(), var274.get());

    reql_array_append(var4.get(), var272.get());

    std::unique_ptr<ReQL_Obj_t> var275(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr275(new ReQL_Obj_t*[2]);
    reql_array_init(var275.get(), arr275.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var276(new ReQL_Obj_t);
    reql_number_init(var276.get(), 90);

    reql_array_append(var275.get(), var276.get());

    std::unique_ptr<ReQL_Obj_t> var277(new ReQL_Obj_t);
    reql_number_init(var277.get(), 1);

    reql_array_append(var275.get(), var277.get());

    reql_array_append(var4.get(), var275.get());

    std::unique_ptr<ReQL_Obj_t> var278(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr278(new ReQL_Obj_t*[2]);
    reql_array_init(var278.get(), arr278.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var279(new ReQL_Obj_t);
    reql_number_init(var279.get(), 91);

    reql_array_append(var278.get(), var279.get());

    std::unique_ptr<ReQL_Obj_t> var280(new ReQL_Obj_t);
    reql_number_init(var280.get(), 1);

    reql_array_append(var278.get(), var280.get());

    reql_array_append(var4.get(), var278.get());

    std::unique_ptr<ReQL_Obj_t> var281(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr281(new ReQL_Obj_t*[2]);
    reql_array_init(var281.get(), arr281.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var282(new ReQL_Obj_t);
    reql_number_init(var282.get(), 92);

    reql_array_append(var281.get(), var282.get());

    std::unique_ptr<ReQL_Obj_t> var283(new ReQL_Obj_t);
    reql_number_init(var283.get(), 1);

    reql_array_append(var281.get(), var283.get());

    reql_array_append(var4.get(), var281.get());

    std::unique_ptr<ReQL_Obj_t> var284(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr284(new ReQL_Obj_t*[2]);
    reql_array_init(var284.get(), arr284.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var285(new ReQL_Obj_t);
    reql_number_init(var285.get(), 93);

    reql_array_append(var284.get(), var285.get());

    std::unique_ptr<ReQL_Obj_t> var286(new ReQL_Obj_t);
    reql_number_init(var286.get(), 1);

    reql_array_append(var284.get(), var286.get());

    reql_array_append(var4.get(), var284.get());

    std::unique_ptr<ReQL_Obj_t> var287(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr287(new ReQL_Obj_t*[2]);
    reql_array_init(var287.get(), arr287.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var288(new ReQL_Obj_t);
    reql_number_init(var288.get(), 94);

    reql_array_append(var287.get(), var288.get());

    std::unique_ptr<ReQL_Obj_t> var289(new ReQL_Obj_t);
    reql_number_init(var289.get(), 1);

    reql_array_append(var287.get(), var289.get());

    reql_array_append(var4.get(), var287.get());

    std::unique_ptr<ReQL_Obj_t> var290(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr290(new ReQL_Obj_t*[2]);
    reql_array_init(var290.get(), arr290.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var291(new ReQL_Obj_t);
    reql_number_init(var291.get(), 95);

    reql_array_append(var290.get(), var291.get());

    std::unique_ptr<ReQL_Obj_t> var292(new ReQL_Obj_t);
    reql_number_init(var292.get(), 1);

    reql_array_append(var290.get(), var292.get());

    reql_array_append(var4.get(), var290.get());

    std::unique_ptr<ReQL_Obj_t> var293(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr293(new ReQL_Obj_t*[2]);
    reql_array_init(var293.get(), arr293.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var294(new ReQL_Obj_t);
    reql_number_init(var294.get(), 96);

    reql_array_append(var293.get(), var294.get());

    std::unique_ptr<ReQL_Obj_t> var295(new ReQL_Obj_t);
    reql_number_init(var295.get(), 1);

    reql_array_append(var293.get(), var295.get());

    reql_array_append(var4.get(), var293.get());

    std::unique_ptr<ReQL_Obj_t> var296(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr296(new ReQL_Obj_t*[2]);
    reql_array_init(var296.get(), arr296.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var297(new ReQL_Obj_t);
    reql_number_init(var297.get(), 97);

    reql_array_append(var296.get(), var297.get());

    std::unique_ptr<ReQL_Obj_t> var298(new ReQL_Obj_t);
    reql_number_init(var298.get(), 1);

    reql_array_append(var296.get(), var298.get());

    reql_array_append(var4.get(), var296.get());

    std::unique_ptr<ReQL_Obj_t> var299(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr299(new ReQL_Obj_t*[2]);
    reql_array_init(var299.get(), arr299.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var300(new ReQL_Obj_t);
    reql_number_init(var300.get(), 98);

    reql_array_append(var299.get(), var300.get());

    std::unique_ptr<ReQL_Obj_t> var301(new ReQL_Obj_t);
    reql_number_init(var301.get(), 1);

    reql_array_append(var299.get(), var301.get());

    reql_array_append(var4.get(), var299.get());

    std::unique_ptr<ReQL_Obj_t> var302(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr302(new ReQL_Obj_t*[2]);
    reql_array_init(var302.get(), arr302.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var303(new ReQL_Obj_t);
    reql_number_init(var303.get(), 99);

    reql_array_append(var302.get(), var303.get());

    std::unique_ptr<ReQL_Obj_t> var304(new ReQL_Obj_t);
    reql_number_init(var304.get(), 1);

    reql_array_append(var302.get(), var304.get());

    reql_array_append(var4.get(), var302.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test85") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 25);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 25);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 25);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 25);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test86") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[100]);
    reql_array_init(var4.get(), arr4.get(), 100);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr6(new ReQL_Obj_t*[2]);
    reql_array_init(var6.get(), arr6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_array_append(var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0);

    reql_array_append(var6.get(), var8.get());

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_array_append(var5.get(), var9.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 4);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 1);

    reql_array_append(var10.get(), var14.get());

    reql_array_append(var4.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr16(new ReQL_Obj_t*[2]);
    reql_array_init(var16.get(), arr16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 0);

    reql_array_append(var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 8);

    reql_array_append(var16.get(), var18.get());

    reql_array_append(var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 1);

    reql_array_append(var15.get(), var19.get());

    reql_array_append(var4.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[2]);
    reql_array_init(var21.get(), arr21.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 0);

    reql_array_append(var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 12);

    reql_array_append(var21.get(), var23.get());

    reql_array_append(var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 1);

    reql_array_append(var20.get(), var24.get());

    reql_array_append(var4.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr25(new ReQL_Obj_t*[2]);
    reql_array_init(var25.get(), arr25.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr26(new ReQL_Obj_t*[2]);
    reql_array_init(var26.get(), arr26.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 0);

    reql_array_append(var26.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 16);

    reql_array_append(var26.get(), var28.get());

    reql_array_append(var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_number_init(var29.get(), 1);

    reql_array_append(var25.get(), var29.get());

    reql_array_append(var4.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr30(new ReQL_Obj_t*[2]);
    reql_array_init(var30.get(), arr30.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_number_init(var32.get(), 0);

    reql_array_append(var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_number_init(var33.get(), 20);

    reql_array_append(var31.get(), var33.get());

    reql_array_append(var30.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 1);

    reql_array_append(var30.get(), var34.get());

    reql_array_append(var4.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr35(new ReQL_Obj_t*[2]);
    reql_array_init(var35.get(), arr35.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr36(new ReQL_Obj_t*[2]);
    reql_array_init(var36.get(), arr36.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_number_init(var37.get(), 0);

    reql_array_append(var36.get(), var37.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    reql_number_init(var38.get(), 24);

    reql_array_append(var36.get(), var38.get());

    reql_array_append(var35.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_number_init(var39.get(), 1);

    reql_array_append(var35.get(), var39.get());

    reql_array_append(var4.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr40(new ReQL_Obj_t*[2]);
    reql_array_init(var40.get(), arr40.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr41(new ReQL_Obj_t*[2]);
    reql_array_init(var41.get(), arr41.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_number_init(var42.get(), 0);

    reql_array_append(var41.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    reql_number_init(var43.get(), 28);

    reql_array_append(var41.get(), var43.get());

    reql_array_append(var40.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    reql_number_init(var44.get(), 1);

    reql_array_append(var40.get(), var44.get());

    reql_array_append(var4.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr45(new ReQL_Obj_t*[2]);
    reql_array_init(var45.get(), arr45.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr46(new ReQL_Obj_t*[2]);
    reql_array_init(var46.get(), arr46.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_number_init(var47.get(), 0);

    reql_array_append(var46.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_number_init(var48.get(), 32);

    reql_array_append(var46.get(), var48.get());

    reql_array_append(var45.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    reql_number_init(var49.get(), 1);

    reql_array_append(var45.get(), var49.get());

    reql_array_append(var4.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr50(new ReQL_Obj_t*[2]);
    reql_array_init(var50.get(), arr50.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr51(new ReQL_Obj_t*[2]);
    reql_array_init(var51.get(), arr51.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    reql_number_init(var52.get(), 0);

    reql_array_append(var51.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_number_init(var53.get(), 36);

    reql_array_append(var51.get(), var53.get());

    reql_array_append(var50.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    reql_number_init(var54.get(), 1);

    reql_array_append(var50.get(), var54.get());

    reql_array_append(var4.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr55(new ReQL_Obj_t*[2]);
    reql_array_init(var55.get(), arr55.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr56(new ReQL_Obj_t*[2]);
    reql_array_init(var56.get(), arr56.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_number_init(var57.get(), 0);

    reql_array_append(var56.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_number_init(var58.get(), 40);

    reql_array_append(var56.get(), var58.get());

    reql_array_append(var55.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    reql_number_init(var59.get(), 1);

    reql_array_append(var55.get(), var59.get());

    reql_array_append(var4.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr60(new ReQL_Obj_t*[2]);
    reql_array_init(var60.get(), arr60.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr61(new ReQL_Obj_t*[2]);
    reql_array_init(var61.get(), arr61.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    reql_number_init(var62.get(), 0);

    reql_array_append(var61.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_number_init(var63.get(), 44);

    reql_array_append(var61.get(), var63.get());

    reql_array_append(var60.get(), var61.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    reql_number_init(var64.get(), 1);

    reql_array_append(var60.get(), var64.get());

    reql_array_append(var4.get(), var60.get());

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr65(new ReQL_Obj_t*[2]);
    reql_array_init(var65.get(), arr65.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr66(new ReQL_Obj_t*[2]);
    reql_array_init(var66.get(), arr66.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    reql_number_init(var67.get(), 0);

    reql_array_append(var66.get(), var67.get());

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    reql_number_init(var68.get(), 48);

    reql_array_append(var66.get(), var68.get());

    reql_array_append(var65.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    reql_number_init(var69.get(), 1);

    reql_array_append(var65.get(), var69.get());

    reql_array_append(var4.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr70(new ReQL_Obj_t*[2]);
    reql_array_init(var70.get(), arr70.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr71(new ReQL_Obj_t*[2]);
    reql_array_init(var71.get(), arr71.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    reql_number_init(var72.get(), 0);

    reql_array_append(var71.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_number_init(var73.get(), 52);

    reql_array_append(var71.get(), var73.get());

    reql_array_append(var70.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    reql_number_init(var74.get(), 1);

    reql_array_append(var70.get(), var74.get());

    reql_array_append(var4.get(), var70.get());

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr75(new ReQL_Obj_t*[2]);
    reql_array_init(var75.get(), arr75.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr76(new ReQL_Obj_t*[2]);
    reql_array_init(var76.get(), arr76.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    reql_number_init(var77.get(), 0);

    reql_array_append(var76.get(), var77.get());

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    reql_number_init(var78.get(), 56);

    reql_array_append(var76.get(), var78.get());

    reql_array_append(var75.get(), var76.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    reql_number_init(var79.get(), 1);

    reql_array_append(var75.get(), var79.get());

    reql_array_append(var4.get(), var75.get());

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr80(new ReQL_Obj_t*[2]);
    reql_array_init(var80.get(), arr80.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr81(new ReQL_Obj_t*[2]);
    reql_array_init(var81.get(), arr81.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_number_init(var82.get(), 0);

    reql_array_append(var81.get(), var82.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    reql_number_init(var83.get(), 60);

    reql_array_append(var81.get(), var83.get());

    reql_array_append(var80.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    reql_number_init(var84.get(), 1);

    reql_array_append(var80.get(), var84.get());

    reql_array_append(var4.get(), var80.get());

    std::unique_ptr<ReQL_Obj_t> var85(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr85(new ReQL_Obj_t*[2]);
    reql_array_init(var85.get(), arr85.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var86(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr86(new ReQL_Obj_t*[2]);
    reql_array_init(var86.get(), arr86.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var87(new ReQL_Obj_t);
    reql_number_init(var87.get(), 0);

    reql_array_append(var86.get(), var87.get());

    std::unique_ptr<ReQL_Obj_t> var88(new ReQL_Obj_t);
    reql_number_init(var88.get(), 64);

    reql_array_append(var86.get(), var88.get());

    reql_array_append(var85.get(), var86.get());

    std::unique_ptr<ReQL_Obj_t> var89(new ReQL_Obj_t);
    reql_number_init(var89.get(), 1);

    reql_array_append(var85.get(), var89.get());

    reql_array_append(var4.get(), var85.get());

    std::unique_ptr<ReQL_Obj_t> var90(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr90(new ReQL_Obj_t*[2]);
    reql_array_init(var90.get(), arr90.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var91(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr91(new ReQL_Obj_t*[2]);
    reql_array_init(var91.get(), arr91.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var92(new ReQL_Obj_t);
    reql_number_init(var92.get(), 0);

    reql_array_append(var91.get(), var92.get());

    std::unique_ptr<ReQL_Obj_t> var93(new ReQL_Obj_t);
    reql_number_init(var93.get(), 68);

    reql_array_append(var91.get(), var93.get());

    reql_array_append(var90.get(), var91.get());

    std::unique_ptr<ReQL_Obj_t> var94(new ReQL_Obj_t);
    reql_number_init(var94.get(), 1);

    reql_array_append(var90.get(), var94.get());

    reql_array_append(var4.get(), var90.get());

    std::unique_ptr<ReQL_Obj_t> var95(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr95(new ReQL_Obj_t*[2]);
    reql_array_init(var95.get(), arr95.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var96(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr96(new ReQL_Obj_t*[2]);
    reql_array_init(var96.get(), arr96.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var97(new ReQL_Obj_t);
    reql_number_init(var97.get(), 0);

    reql_array_append(var96.get(), var97.get());

    std::unique_ptr<ReQL_Obj_t> var98(new ReQL_Obj_t);
    reql_number_init(var98.get(), 72);

    reql_array_append(var96.get(), var98.get());

    reql_array_append(var95.get(), var96.get());

    std::unique_ptr<ReQL_Obj_t> var99(new ReQL_Obj_t);
    reql_number_init(var99.get(), 1);

    reql_array_append(var95.get(), var99.get());

    reql_array_append(var4.get(), var95.get());

    std::unique_ptr<ReQL_Obj_t> var100(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr100(new ReQL_Obj_t*[2]);
    reql_array_init(var100.get(), arr100.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var101(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr101(new ReQL_Obj_t*[2]);
    reql_array_init(var101.get(), arr101.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var102(new ReQL_Obj_t);
    reql_number_init(var102.get(), 0);

    reql_array_append(var101.get(), var102.get());

    std::unique_ptr<ReQL_Obj_t> var103(new ReQL_Obj_t);
    reql_number_init(var103.get(), 76);

    reql_array_append(var101.get(), var103.get());

    reql_array_append(var100.get(), var101.get());

    std::unique_ptr<ReQL_Obj_t> var104(new ReQL_Obj_t);
    reql_number_init(var104.get(), 1);

    reql_array_append(var100.get(), var104.get());

    reql_array_append(var4.get(), var100.get());

    std::unique_ptr<ReQL_Obj_t> var105(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr105(new ReQL_Obj_t*[2]);
    reql_array_init(var105.get(), arr105.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var106(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr106(new ReQL_Obj_t*[2]);
    reql_array_init(var106.get(), arr106.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var107(new ReQL_Obj_t);
    reql_number_init(var107.get(), 0);

    reql_array_append(var106.get(), var107.get());

    std::unique_ptr<ReQL_Obj_t> var108(new ReQL_Obj_t);
    reql_number_init(var108.get(), 80);

    reql_array_append(var106.get(), var108.get());

    reql_array_append(var105.get(), var106.get());

    std::unique_ptr<ReQL_Obj_t> var109(new ReQL_Obj_t);
    reql_number_init(var109.get(), 1);

    reql_array_append(var105.get(), var109.get());

    reql_array_append(var4.get(), var105.get());

    std::unique_ptr<ReQL_Obj_t> var110(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr110(new ReQL_Obj_t*[2]);
    reql_array_init(var110.get(), arr110.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var111(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr111(new ReQL_Obj_t*[2]);
    reql_array_init(var111.get(), arr111.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var112(new ReQL_Obj_t);
    reql_number_init(var112.get(), 0);

    reql_array_append(var111.get(), var112.get());

    std::unique_ptr<ReQL_Obj_t> var113(new ReQL_Obj_t);
    reql_number_init(var113.get(), 84);

    reql_array_append(var111.get(), var113.get());

    reql_array_append(var110.get(), var111.get());

    std::unique_ptr<ReQL_Obj_t> var114(new ReQL_Obj_t);
    reql_number_init(var114.get(), 1);

    reql_array_append(var110.get(), var114.get());

    reql_array_append(var4.get(), var110.get());

    std::unique_ptr<ReQL_Obj_t> var115(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr115(new ReQL_Obj_t*[2]);
    reql_array_init(var115.get(), arr115.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var116(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr116(new ReQL_Obj_t*[2]);
    reql_array_init(var116.get(), arr116.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var117(new ReQL_Obj_t);
    reql_number_init(var117.get(), 0);

    reql_array_append(var116.get(), var117.get());

    std::unique_ptr<ReQL_Obj_t> var118(new ReQL_Obj_t);
    reql_number_init(var118.get(), 88);

    reql_array_append(var116.get(), var118.get());

    reql_array_append(var115.get(), var116.get());

    std::unique_ptr<ReQL_Obj_t> var119(new ReQL_Obj_t);
    reql_number_init(var119.get(), 1);

    reql_array_append(var115.get(), var119.get());

    reql_array_append(var4.get(), var115.get());

    std::unique_ptr<ReQL_Obj_t> var120(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr120(new ReQL_Obj_t*[2]);
    reql_array_init(var120.get(), arr120.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var121(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr121(new ReQL_Obj_t*[2]);
    reql_array_init(var121.get(), arr121.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var122(new ReQL_Obj_t);
    reql_number_init(var122.get(), 0);

    reql_array_append(var121.get(), var122.get());

    std::unique_ptr<ReQL_Obj_t> var123(new ReQL_Obj_t);
    reql_number_init(var123.get(), 92);

    reql_array_append(var121.get(), var123.get());

    reql_array_append(var120.get(), var121.get());

    std::unique_ptr<ReQL_Obj_t> var124(new ReQL_Obj_t);
    reql_number_init(var124.get(), 1);

    reql_array_append(var120.get(), var124.get());

    reql_array_append(var4.get(), var120.get());

    std::unique_ptr<ReQL_Obj_t> var125(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr125(new ReQL_Obj_t*[2]);
    reql_array_init(var125.get(), arr125.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var126(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr126(new ReQL_Obj_t*[2]);
    reql_array_init(var126.get(), arr126.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var127(new ReQL_Obj_t);
    reql_number_init(var127.get(), 0);

    reql_array_append(var126.get(), var127.get());

    std::unique_ptr<ReQL_Obj_t> var128(new ReQL_Obj_t);
    reql_number_init(var128.get(), 96);

    reql_array_append(var126.get(), var128.get());

    reql_array_append(var125.get(), var126.get());

    std::unique_ptr<ReQL_Obj_t> var129(new ReQL_Obj_t);
    reql_number_init(var129.get(), 1);

    reql_array_append(var125.get(), var129.get());

    reql_array_append(var4.get(), var125.get());

    std::unique_ptr<ReQL_Obj_t> var130(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr130(new ReQL_Obj_t*[2]);
    reql_array_init(var130.get(), arr130.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var131(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr131(new ReQL_Obj_t*[2]);
    reql_array_init(var131.get(), arr131.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var132(new ReQL_Obj_t);
    reql_number_init(var132.get(), 1);

    reql_array_append(var131.get(), var132.get());

    std::unique_ptr<ReQL_Obj_t> var133(new ReQL_Obj_t);
    reql_number_init(var133.get(), 1);

    reql_array_append(var131.get(), var133.get());

    reql_array_append(var130.get(), var131.get());

    std::unique_ptr<ReQL_Obj_t> var134(new ReQL_Obj_t);
    reql_number_init(var134.get(), 1);

    reql_array_append(var130.get(), var134.get());

    reql_array_append(var4.get(), var130.get());

    std::unique_ptr<ReQL_Obj_t> var135(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr135(new ReQL_Obj_t*[2]);
    reql_array_init(var135.get(), arr135.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var136(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr136(new ReQL_Obj_t*[2]);
    reql_array_init(var136.get(), arr136.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var137(new ReQL_Obj_t);
    reql_number_init(var137.get(), 1);

    reql_array_append(var136.get(), var137.get());

    std::unique_ptr<ReQL_Obj_t> var138(new ReQL_Obj_t);
    reql_number_init(var138.get(), 5);

    reql_array_append(var136.get(), var138.get());

    reql_array_append(var135.get(), var136.get());

    std::unique_ptr<ReQL_Obj_t> var139(new ReQL_Obj_t);
    reql_number_init(var139.get(), 1);

    reql_array_append(var135.get(), var139.get());

    reql_array_append(var4.get(), var135.get());

    std::unique_ptr<ReQL_Obj_t> var140(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr140(new ReQL_Obj_t*[2]);
    reql_array_init(var140.get(), arr140.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var141(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr141(new ReQL_Obj_t*[2]);
    reql_array_init(var141.get(), arr141.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var142(new ReQL_Obj_t);
    reql_number_init(var142.get(), 1);

    reql_array_append(var141.get(), var142.get());

    std::unique_ptr<ReQL_Obj_t> var143(new ReQL_Obj_t);
    reql_number_init(var143.get(), 9);

    reql_array_append(var141.get(), var143.get());

    reql_array_append(var140.get(), var141.get());

    std::unique_ptr<ReQL_Obj_t> var144(new ReQL_Obj_t);
    reql_number_init(var144.get(), 1);

    reql_array_append(var140.get(), var144.get());

    reql_array_append(var4.get(), var140.get());

    std::unique_ptr<ReQL_Obj_t> var145(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr145(new ReQL_Obj_t*[2]);
    reql_array_init(var145.get(), arr145.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var146(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr146(new ReQL_Obj_t*[2]);
    reql_array_init(var146.get(), arr146.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var147(new ReQL_Obj_t);
    reql_number_init(var147.get(), 1);

    reql_array_append(var146.get(), var147.get());

    std::unique_ptr<ReQL_Obj_t> var148(new ReQL_Obj_t);
    reql_number_init(var148.get(), 13);

    reql_array_append(var146.get(), var148.get());

    reql_array_append(var145.get(), var146.get());

    std::unique_ptr<ReQL_Obj_t> var149(new ReQL_Obj_t);
    reql_number_init(var149.get(), 1);

    reql_array_append(var145.get(), var149.get());

    reql_array_append(var4.get(), var145.get());

    std::unique_ptr<ReQL_Obj_t> var150(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr150(new ReQL_Obj_t*[2]);
    reql_array_init(var150.get(), arr150.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var151(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr151(new ReQL_Obj_t*[2]);
    reql_array_init(var151.get(), arr151.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var152(new ReQL_Obj_t);
    reql_number_init(var152.get(), 1);

    reql_array_append(var151.get(), var152.get());

    std::unique_ptr<ReQL_Obj_t> var153(new ReQL_Obj_t);
    reql_number_init(var153.get(), 17);

    reql_array_append(var151.get(), var153.get());

    reql_array_append(var150.get(), var151.get());

    std::unique_ptr<ReQL_Obj_t> var154(new ReQL_Obj_t);
    reql_number_init(var154.get(), 1);

    reql_array_append(var150.get(), var154.get());

    reql_array_append(var4.get(), var150.get());

    std::unique_ptr<ReQL_Obj_t> var155(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr155(new ReQL_Obj_t*[2]);
    reql_array_init(var155.get(), arr155.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var156(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr156(new ReQL_Obj_t*[2]);
    reql_array_init(var156.get(), arr156.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var157(new ReQL_Obj_t);
    reql_number_init(var157.get(), 1);

    reql_array_append(var156.get(), var157.get());

    std::unique_ptr<ReQL_Obj_t> var158(new ReQL_Obj_t);
    reql_number_init(var158.get(), 21);

    reql_array_append(var156.get(), var158.get());

    reql_array_append(var155.get(), var156.get());

    std::unique_ptr<ReQL_Obj_t> var159(new ReQL_Obj_t);
    reql_number_init(var159.get(), 1);

    reql_array_append(var155.get(), var159.get());

    reql_array_append(var4.get(), var155.get());

    std::unique_ptr<ReQL_Obj_t> var160(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr160(new ReQL_Obj_t*[2]);
    reql_array_init(var160.get(), arr160.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var161(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr161(new ReQL_Obj_t*[2]);
    reql_array_init(var161.get(), arr161.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var162(new ReQL_Obj_t);
    reql_number_init(var162.get(), 1);

    reql_array_append(var161.get(), var162.get());

    std::unique_ptr<ReQL_Obj_t> var163(new ReQL_Obj_t);
    reql_number_init(var163.get(), 25);

    reql_array_append(var161.get(), var163.get());

    reql_array_append(var160.get(), var161.get());

    std::unique_ptr<ReQL_Obj_t> var164(new ReQL_Obj_t);
    reql_number_init(var164.get(), 1);

    reql_array_append(var160.get(), var164.get());

    reql_array_append(var4.get(), var160.get());

    std::unique_ptr<ReQL_Obj_t> var165(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr165(new ReQL_Obj_t*[2]);
    reql_array_init(var165.get(), arr165.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var166(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr166(new ReQL_Obj_t*[2]);
    reql_array_init(var166.get(), arr166.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var167(new ReQL_Obj_t);
    reql_number_init(var167.get(), 1);

    reql_array_append(var166.get(), var167.get());

    std::unique_ptr<ReQL_Obj_t> var168(new ReQL_Obj_t);
    reql_number_init(var168.get(), 29);

    reql_array_append(var166.get(), var168.get());

    reql_array_append(var165.get(), var166.get());

    std::unique_ptr<ReQL_Obj_t> var169(new ReQL_Obj_t);
    reql_number_init(var169.get(), 1);

    reql_array_append(var165.get(), var169.get());

    reql_array_append(var4.get(), var165.get());

    std::unique_ptr<ReQL_Obj_t> var170(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr170(new ReQL_Obj_t*[2]);
    reql_array_init(var170.get(), arr170.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var171(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr171(new ReQL_Obj_t*[2]);
    reql_array_init(var171.get(), arr171.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var172(new ReQL_Obj_t);
    reql_number_init(var172.get(), 1);

    reql_array_append(var171.get(), var172.get());

    std::unique_ptr<ReQL_Obj_t> var173(new ReQL_Obj_t);
    reql_number_init(var173.get(), 33);

    reql_array_append(var171.get(), var173.get());

    reql_array_append(var170.get(), var171.get());

    std::unique_ptr<ReQL_Obj_t> var174(new ReQL_Obj_t);
    reql_number_init(var174.get(), 1);

    reql_array_append(var170.get(), var174.get());

    reql_array_append(var4.get(), var170.get());

    std::unique_ptr<ReQL_Obj_t> var175(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr175(new ReQL_Obj_t*[2]);
    reql_array_init(var175.get(), arr175.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var176(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr176(new ReQL_Obj_t*[2]);
    reql_array_init(var176.get(), arr176.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var177(new ReQL_Obj_t);
    reql_number_init(var177.get(), 1);

    reql_array_append(var176.get(), var177.get());

    std::unique_ptr<ReQL_Obj_t> var178(new ReQL_Obj_t);
    reql_number_init(var178.get(), 37);

    reql_array_append(var176.get(), var178.get());

    reql_array_append(var175.get(), var176.get());

    std::unique_ptr<ReQL_Obj_t> var179(new ReQL_Obj_t);
    reql_number_init(var179.get(), 1);

    reql_array_append(var175.get(), var179.get());

    reql_array_append(var4.get(), var175.get());

    std::unique_ptr<ReQL_Obj_t> var180(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr180(new ReQL_Obj_t*[2]);
    reql_array_init(var180.get(), arr180.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var181(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr181(new ReQL_Obj_t*[2]);
    reql_array_init(var181.get(), arr181.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var182(new ReQL_Obj_t);
    reql_number_init(var182.get(), 1);

    reql_array_append(var181.get(), var182.get());

    std::unique_ptr<ReQL_Obj_t> var183(new ReQL_Obj_t);
    reql_number_init(var183.get(), 41);

    reql_array_append(var181.get(), var183.get());

    reql_array_append(var180.get(), var181.get());

    std::unique_ptr<ReQL_Obj_t> var184(new ReQL_Obj_t);
    reql_number_init(var184.get(), 1);

    reql_array_append(var180.get(), var184.get());

    reql_array_append(var4.get(), var180.get());

    std::unique_ptr<ReQL_Obj_t> var185(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr185(new ReQL_Obj_t*[2]);
    reql_array_init(var185.get(), arr185.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var186(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr186(new ReQL_Obj_t*[2]);
    reql_array_init(var186.get(), arr186.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var187(new ReQL_Obj_t);
    reql_number_init(var187.get(), 1);

    reql_array_append(var186.get(), var187.get());

    std::unique_ptr<ReQL_Obj_t> var188(new ReQL_Obj_t);
    reql_number_init(var188.get(), 45);

    reql_array_append(var186.get(), var188.get());

    reql_array_append(var185.get(), var186.get());

    std::unique_ptr<ReQL_Obj_t> var189(new ReQL_Obj_t);
    reql_number_init(var189.get(), 1);

    reql_array_append(var185.get(), var189.get());

    reql_array_append(var4.get(), var185.get());

    std::unique_ptr<ReQL_Obj_t> var190(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr190(new ReQL_Obj_t*[2]);
    reql_array_init(var190.get(), arr190.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var191(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr191(new ReQL_Obj_t*[2]);
    reql_array_init(var191.get(), arr191.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var192(new ReQL_Obj_t);
    reql_number_init(var192.get(), 1);

    reql_array_append(var191.get(), var192.get());

    std::unique_ptr<ReQL_Obj_t> var193(new ReQL_Obj_t);
    reql_number_init(var193.get(), 49);

    reql_array_append(var191.get(), var193.get());

    reql_array_append(var190.get(), var191.get());

    std::unique_ptr<ReQL_Obj_t> var194(new ReQL_Obj_t);
    reql_number_init(var194.get(), 1);

    reql_array_append(var190.get(), var194.get());

    reql_array_append(var4.get(), var190.get());

    std::unique_ptr<ReQL_Obj_t> var195(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr195(new ReQL_Obj_t*[2]);
    reql_array_init(var195.get(), arr195.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var196(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr196(new ReQL_Obj_t*[2]);
    reql_array_init(var196.get(), arr196.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var197(new ReQL_Obj_t);
    reql_number_init(var197.get(), 1);

    reql_array_append(var196.get(), var197.get());

    std::unique_ptr<ReQL_Obj_t> var198(new ReQL_Obj_t);
    reql_number_init(var198.get(), 53);

    reql_array_append(var196.get(), var198.get());

    reql_array_append(var195.get(), var196.get());

    std::unique_ptr<ReQL_Obj_t> var199(new ReQL_Obj_t);
    reql_number_init(var199.get(), 1);

    reql_array_append(var195.get(), var199.get());

    reql_array_append(var4.get(), var195.get());

    std::unique_ptr<ReQL_Obj_t> var200(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr200(new ReQL_Obj_t*[2]);
    reql_array_init(var200.get(), arr200.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var201(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr201(new ReQL_Obj_t*[2]);
    reql_array_init(var201.get(), arr201.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var202(new ReQL_Obj_t);
    reql_number_init(var202.get(), 1);

    reql_array_append(var201.get(), var202.get());

    std::unique_ptr<ReQL_Obj_t> var203(new ReQL_Obj_t);
    reql_number_init(var203.get(), 57);

    reql_array_append(var201.get(), var203.get());

    reql_array_append(var200.get(), var201.get());

    std::unique_ptr<ReQL_Obj_t> var204(new ReQL_Obj_t);
    reql_number_init(var204.get(), 1);

    reql_array_append(var200.get(), var204.get());

    reql_array_append(var4.get(), var200.get());

    std::unique_ptr<ReQL_Obj_t> var205(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr205(new ReQL_Obj_t*[2]);
    reql_array_init(var205.get(), arr205.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var206(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr206(new ReQL_Obj_t*[2]);
    reql_array_init(var206.get(), arr206.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var207(new ReQL_Obj_t);
    reql_number_init(var207.get(), 1);

    reql_array_append(var206.get(), var207.get());

    std::unique_ptr<ReQL_Obj_t> var208(new ReQL_Obj_t);
    reql_number_init(var208.get(), 61);

    reql_array_append(var206.get(), var208.get());

    reql_array_append(var205.get(), var206.get());

    std::unique_ptr<ReQL_Obj_t> var209(new ReQL_Obj_t);
    reql_number_init(var209.get(), 1);

    reql_array_append(var205.get(), var209.get());

    reql_array_append(var4.get(), var205.get());

    std::unique_ptr<ReQL_Obj_t> var210(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr210(new ReQL_Obj_t*[2]);
    reql_array_init(var210.get(), arr210.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var211(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr211(new ReQL_Obj_t*[2]);
    reql_array_init(var211.get(), arr211.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var212(new ReQL_Obj_t);
    reql_number_init(var212.get(), 1);

    reql_array_append(var211.get(), var212.get());

    std::unique_ptr<ReQL_Obj_t> var213(new ReQL_Obj_t);
    reql_number_init(var213.get(), 65);

    reql_array_append(var211.get(), var213.get());

    reql_array_append(var210.get(), var211.get());

    std::unique_ptr<ReQL_Obj_t> var214(new ReQL_Obj_t);
    reql_number_init(var214.get(), 1);

    reql_array_append(var210.get(), var214.get());

    reql_array_append(var4.get(), var210.get());

    std::unique_ptr<ReQL_Obj_t> var215(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr215(new ReQL_Obj_t*[2]);
    reql_array_init(var215.get(), arr215.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var216(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr216(new ReQL_Obj_t*[2]);
    reql_array_init(var216.get(), arr216.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var217(new ReQL_Obj_t);
    reql_number_init(var217.get(), 1);

    reql_array_append(var216.get(), var217.get());

    std::unique_ptr<ReQL_Obj_t> var218(new ReQL_Obj_t);
    reql_number_init(var218.get(), 69);

    reql_array_append(var216.get(), var218.get());

    reql_array_append(var215.get(), var216.get());

    std::unique_ptr<ReQL_Obj_t> var219(new ReQL_Obj_t);
    reql_number_init(var219.get(), 1);

    reql_array_append(var215.get(), var219.get());

    reql_array_append(var4.get(), var215.get());

    std::unique_ptr<ReQL_Obj_t> var220(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr220(new ReQL_Obj_t*[2]);
    reql_array_init(var220.get(), arr220.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var221(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr221(new ReQL_Obj_t*[2]);
    reql_array_init(var221.get(), arr221.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var222(new ReQL_Obj_t);
    reql_number_init(var222.get(), 1);

    reql_array_append(var221.get(), var222.get());

    std::unique_ptr<ReQL_Obj_t> var223(new ReQL_Obj_t);
    reql_number_init(var223.get(), 73);

    reql_array_append(var221.get(), var223.get());

    reql_array_append(var220.get(), var221.get());

    std::unique_ptr<ReQL_Obj_t> var224(new ReQL_Obj_t);
    reql_number_init(var224.get(), 1);

    reql_array_append(var220.get(), var224.get());

    reql_array_append(var4.get(), var220.get());

    std::unique_ptr<ReQL_Obj_t> var225(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr225(new ReQL_Obj_t*[2]);
    reql_array_init(var225.get(), arr225.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var226(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr226(new ReQL_Obj_t*[2]);
    reql_array_init(var226.get(), arr226.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var227(new ReQL_Obj_t);
    reql_number_init(var227.get(), 1);

    reql_array_append(var226.get(), var227.get());

    std::unique_ptr<ReQL_Obj_t> var228(new ReQL_Obj_t);
    reql_number_init(var228.get(), 77);

    reql_array_append(var226.get(), var228.get());

    reql_array_append(var225.get(), var226.get());

    std::unique_ptr<ReQL_Obj_t> var229(new ReQL_Obj_t);
    reql_number_init(var229.get(), 1);

    reql_array_append(var225.get(), var229.get());

    reql_array_append(var4.get(), var225.get());

    std::unique_ptr<ReQL_Obj_t> var230(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr230(new ReQL_Obj_t*[2]);
    reql_array_init(var230.get(), arr230.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var231(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr231(new ReQL_Obj_t*[2]);
    reql_array_init(var231.get(), arr231.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var232(new ReQL_Obj_t);
    reql_number_init(var232.get(), 1);

    reql_array_append(var231.get(), var232.get());

    std::unique_ptr<ReQL_Obj_t> var233(new ReQL_Obj_t);
    reql_number_init(var233.get(), 81);

    reql_array_append(var231.get(), var233.get());

    reql_array_append(var230.get(), var231.get());

    std::unique_ptr<ReQL_Obj_t> var234(new ReQL_Obj_t);
    reql_number_init(var234.get(), 1);

    reql_array_append(var230.get(), var234.get());

    reql_array_append(var4.get(), var230.get());

    std::unique_ptr<ReQL_Obj_t> var235(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr235(new ReQL_Obj_t*[2]);
    reql_array_init(var235.get(), arr235.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var236(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr236(new ReQL_Obj_t*[2]);
    reql_array_init(var236.get(), arr236.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var237(new ReQL_Obj_t);
    reql_number_init(var237.get(), 1);

    reql_array_append(var236.get(), var237.get());

    std::unique_ptr<ReQL_Obj_t> var238(new ReQL_Obj_t);
    reql_number_init(var238.get(), 85);

    reql_array_append(var236.get(), var238.get());

    reql_array_append(var235.get(), var236.get());

    std::unique_ptr<ReQL_Obj_t> var239(new ReQL_Obj_t);
    reql_number_init(var239.get(), 1);

    reql_array_append(var235.get(), var239.get());

    reql_array_append(var4.get(), var235.get());

    std::unique_ptr<ReQL_Obj_t> var240(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr240(new ReQL_Obj_t*[2]);
    reql_array_init(var240.get(), arr240.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var241(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr241(new ReQL_Obj_t*[2]);
    reql_array_init(var241.get(), arr241.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var242(new ReQL_Obj_t);
    reql_number_init(var242.get(), 1);

    reql_array_append(var241.get(), var242.get());

    std::unique_ptr<ReQL_Obj_t> var243(new ReQL_Obj_t);
    reql_number_init(var243.get(), 89);

    reql_array_append(var241.get(), var243.get());

    reql_array_append(var240.get(), var241.get());

    std::unique_ptr<ReQL_Obj_t> var244(new ReQL_Obj_t);
    reql_number_init(var244.get(), 1);

    reql_array_append(var240.get(), var244.get());

    reql_array_append(var4.get(), var240.get());

    std::unique_ptr<ReQL_Obj_t> var245(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr245(new ReQL_Obj_t*[2]);
    reql_array_init(var245.get(), arr245.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var246(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr246(new ReQL_Obj_t*[2]);
    reql_array_init(var246.get(), arr246.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var247(new ReQL_Obj_t);
    reql_number_init(var247.get(), 1);

    reql_array_append(var246.get(), var247.get());

    std::unique_ptr<ReQL_Obj_t> var248(new ReQL_Obj_t);
    reql_number_init(var248.get(), 93);

    reql_array_append(var246.get(), var248.get());

    reql_array_append(var245.get(), var246.get());

    std::unique_ptr<ReQL_Obj_t> var249(new ReQL_Obj_t);
    reql_number_init(var249.get(), 1);

    reql_array_append(var245.get(), var249.get());

    reql_array_append(var4.get(), var245.get());

    std::unique_ptr<ReQL_Obj_t> var250(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr250(new ReQL_Obj_t*[2]);
    reql_array_init(var250.get(), arr250.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var251(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr251(new ReQL_Obj_t*[2]);
    reql_array_init(var251.get(), arr251.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var252(new ReQL_Obj_t);
    reql_number_init(var252.get(), 1);

    reql_array_append(var251.get(), var252.get());

    std::unique_ptr<ReQL_Obj_t> var253(new ReQL_Obj_t);
    reql_number_init(var253.get(), 97);

    reql_array_append(var251.get(), var253.get());

    reql_array_append(var250.get(), var251.get());

    std::unique_ptr<ReQL_Obj_t> var254(new ReQL_Obj_t);
    reql_number_init(var254.get(), 1);

    reql_array_append(var250.get(), var254.get());

    reql_array_append(var4.get(), var250.get());

    std::unique_ptr<ReQL_Obj_t> var255(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr255(new ReQL_Obj_t*[2]);
    reql_array_init(var255.get(), arr255.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var256(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr256(new ReQL_Obj_t*[2]);
    reql_array_init(var256.get(), arr256.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var257(new ReQL_Obj_t);
    reql_number_init(var257.get(), 2);

    reql_array_append(var256.get(), var257.get());

    std::unique_ptr<ReQL_Obj_t> var258(new ReQL_Obj_t);
    reql_number_init(var258.get(), 2);

    reql_array_append(var256.get(), var258.get());

    reql_array_append(var255.get(), var256.get());

    std::unique_ptr<ReQL_Obj_t> var259(new ReQL_Obj_t);
    reql_number_init(var259.get(), 1);

    reql_array_append(var255.get(), var259.get());

    reql_array_append(var4.get(), var255.get());

    std::unique_ptr<ReQL_Obj_t> var260(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr260(new ReQL_Obj_t*[2]);
    reql_array_init(var260.get(), arr260.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var261(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr261(new ReQL_Obj_t*[2]);
    reql_array_init(var261.get(), arr261.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var262(new ReQL_Obj_t);
    reql_number_init(var262.get(), 2);

    reql_array_append(var261.get(), var262.get());

    std::unique_ptr<ReQL_Obj_t> var263(new ReQL_Obj_t);
    reql_number_init(var263.get(), 6);

    reql_array_append(var261.get(), var263.get());

    reql_array_append(var260.get(), var261.get());

    std::unique_ptr<ReQL_Obj_t> var264(new ReQL_Obj_t);
    reql_number_init(var264.get(), 1);

    reql_array_append(var260.get(), var264.get());

    reql_array_append(var4.get(), var260.get());

    std::unique_ptr<ReQL_Obj_t> var265(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr265(new ReQL_Obj_t*[2]);
    reql_array_init(var265.get(), arr265.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var266(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr266(new ReQL_Obj_t*[2]);
    reql_array_init(var266.get(), arr266.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var267(new ReQL_Obj_t);
    reql_number_init(var267.get(), 2);

    reql_array_append(var266.get(), var267.get());

    std::unique_ptr<ReQL_Obj_t> var268(new ReQL_Obj_t);
    reql_number_init(var268.get(), 10);

    reql_array_append(var266.get(), var268.get());

    reql_array_append(var265.get(), var266.get());

    std::unique_ptr<ReQL_Obj_t> var269(new ReQL_Obj_t);
    reql_number_init(var269.get(), 1);

    reql_array_append(var265.get(), var269.get());

    reql_array_append(var4.get(), var265.get());

    std::unique_ptr<ReQL_Obj_t> var270(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr270(new ReQL_Obj_t*[2]);
    reql_array_init(var270.get(), arr270.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var271(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr271(new ReQL_Obj_t*[2]);
    reql_array_init(var271.get(), arr271.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var272(new ReQL_Obj_t);
    reql_number_init(var272.get(), 2);

    reql_array_append(var271.get(), var272.get());

    std::unique_ptr<ReQL_Obj_t> var273(new ReQL_Obj_t);
    reql_number_init(var273.get(), 14);

    reql_array_append(var271.get(), var273.get());

    reql_array_append(var270.get(), var271.get());

    std::unique_ptr<ReQL_Obj_t> var274(new ReQL_Obj_t);
    reql_number_init(var274.get(), 1);

    reql_array_append(var270.get(), var274.get());

    reql_array_append(var4.get(), var270.get());

    std::unique_ptr<ReQL_Obj_t> var275(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr275(new ReQL_Obj_t*[2]);
    reql_array_init(var275.get(), arr275.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var276(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr276(new ReQL_Obj_t*[2]);
    reql_array_init(var276.get(), arr276.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var277(new ReQL_Obj_t);
    reql_number_init(var277.get(), 2);

    reql_array_append(var276.get(), var277.get());

    std::unique_ptr<ReQL_Obj_t> var278(new ReQL_Obj_t);
    reql_number_init(var278.get(), 18);

    reql_array_append(var276.get(), var278.get());

    reql_array_append(var275.get(), var276.get());

    std::unique_ptr<ReQL_Obj_t> var279(new ReQL_Obj_t);
    reql_number_init(var279.get(), 1);

    reql_array_append(var275.get(), var279.get());

    reql_array_append(var4.get(), var275.get());

    std::unique_ptr<ReQL_Obj_t> var280(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr280(new ReQL_Obj_t*[2]);
    reql_array_init(var280.get(), arr280.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var281(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr281(new ReQL_Obj_t*[2]);
    reql_array_init(var281.get(), arr281.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var282(new ReQL_Obj_t);
    reql_number_init(var282.get(), 2);

    reql_array_append(var281.get(), var282.get());

    std::unique_ptr<ReQL_Obj_t> var283(new ReQL_Obj_t);
    reql_number_init(var283.get(), 22);

    reql_array_append(var281.get(), var283.get());

    reql_array_append(var280.get(), var281.get());

    std::unique_ptr<ReQL_Obj_t> var284(new ReQL_Obj_t);
    reql_number_init(var284.get(), 1);

    reql_array_append(var280.get(), var284.get());

    reql_array_append(var4.get(), var280.get());

    std::unique_ptr<ReQL_Obj_t> var285(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr285(new ReQL_Obj_t*[2]);
    reql_array_init(var285.get(), arr285.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var286(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr286(new ReQL_Obj_t*[2]);
    reql_array_init(var286.get(), arr286.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var287(new ReQL_Obj_t);
    reql_number_init(var287.get(), 2);

    reql_array_append(var286.get(), var287.get());

    std::unique_ptr<ReQL_Obj_t> var288(new ReQL_Obj_t);
    reql_number_init(var288.get(), 26);

    reql_array_append(var286.get(), var288.get());

    reql_array_append(var285.get(), var286.get());

    std::unique_ptr<ReQL_Obj_t> var289(new ReQL_Obj_t);
    reql_number_init(var289.get(), 1);

    reql_array_append(var285.get(), var289.get());

    reql_array_append(var4.get(), var285.get());

    std::unique_ptr<ReQL_Obj_t> var290(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr290(new ReQL_Obj_t*[2]);
    reql_array_init(var290.get(), arr290.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var291(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr291(new ReQL_Obj_t*[2]);
    reql_array_init(var291.get(), arr291.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var292(new ReQL_Obj_t);
    reql_number_init(var292.get(), 2);

    reql_array_append(var291.get(), var292.get());

    std::unique_ptr<ReQL_Obj_t> var293(new ReQL_Obj_t);
    reql_number_init(var293.get(), 30);

    reql_array_append(var291.get(), var293.get());

    reql_array_append(var290.get(), var291.get());

    std::unique_ptr<ReQL_Obj_t> var294(new ReQL_Obj_t);
    reql_number_init(var294.get(), 1);

    reql_array_append(var290.get(), var294.get());

    reql_array_append(var4.get(), var290.get());

    std::unique_ptr<ReQL_Obj_t> var295(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr295(new ReQL_Obj_t*[2]);
    reql_array_init(var295.get(), arr295.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var296(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr296(new ReQL_Obj_t*[2]);
    reql_array_init(var296.get(), arr296.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var297(new ReQL_Obj_t);
    reql_number_init(var297.get(), 2);

    reql_array_append(var296.get(), var297.get());

    std::unique_ptr<ReQL_Obj_t> var298(new ReQL_Obj_t);
    reql_number_init(var298.get(), 34);

    reql_array_append(var296.get(), var298.get());

    reql_array_append(var295.get(), var296.get());

    std::unique_ptr<ReQL_Obj_t> var299(new ReQL_Obj_t);
    reql_number_init(var299.get(), 1);

    reql_array_append(var295.get(), var299.get());

    reql_array_append(var4.get(), var295.get());

    std::unique_ptr<ReQL_Obj_t> var300(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr300(new ReQL_Obj_t*[2]);
    reql_array_init(var300.get(), arr300.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var301(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr301(new ReQL_Obj_t*[2]);
    reql_array_init(var301.get(), arr301.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var302(new ReQL_Obj_t);
    reql_number_init(var302.get(), 2);

    reql_array_append(var301.get(), var302.get());

    std::unique_ptr<ReQL_Obj_t> var303(new ReQL_Obj_t);
    reql_number_init(var303.get(), 38);

    reql_array_append(var301.get(), var303.get());

    reql_array_append(var300.get(), var301.get());

    std::unique_ptr<ReQL_Obj_t> var304(new ReQL_Obj_t);
    reql_number_init(var304.get(), 1);

    reql_array_append(var300.get(), var304.get());

    reql_array_append(var4.get(), var300.get());

    std::unique_ptr<ReQL_Obj_t> var305(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr305(new ReQL_Obj_t*[2]);
    reql_array_init(var305.get(), arr305.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var306(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr306(new ReQL_Obj_t*[2]);
    reql_array_init(var306.get(), arr306.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var307(new ReQL_Obj_t);
    reql_number_init(var307.get(), 2);

    reql_array_append(var306.get(), var307.get());

    std::unique_ptr<ReQL_Obj_t> var308(new ReQL_Obj_t);
    reql_number_init(var308.get(), 42);

    reql_array_append(var306.get(), var308.get());

    reql_array_append(var305.get(), var306.get());

    std::unique_ptr<ReQL_Obj_t> var309(new ReQL_Obj_t);
    reql_number_init(var309.get(), 1);

    reql_array_append(var305.get(), var309.get());

    reql_array_append(var4.get(), var305.get());

    std::unique_ptr<ReQL_Obj_t> var310(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr310(new ReQL_Obj_t*[2]);
    reql_array_init(var310.get(), arr310.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var311(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr311(new ReQL_Obj_t*[2]);
    reql_array_init(var311.get(), arr311.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var312(new ReQL_Obj_t);
    reql_number_init(var312.get(), 2);

    reql_array_append(var311.get(), var312.get());

    std::unique_ptr<ReQL_Obj_t> var313(new ReQL_Obj_t);
    reql_number_init(var313.get(), 46);

    reql_array_append(var311.get(), var313.get());

    reql_array_append(var310.get(), var311.get());

    std::unique_ptr<ReQL_Obj_t> var314(new ReQL_Obj_t);
    reql_number_init(var314.get(), 1);

    reql_array_append(var310.get(), var314.get());

    reql_array_append(var4.get(), var310.get());

    std::unique_ptr<ReQL_Obj_t> var315(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr315(new ReQL_Obj_t*[2]);
    reql_array_init(var315.get(), arr315.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var316(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr316(new ReQL_Obj_t*[2]);
    reql_array_init(var316.get(), arr316.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var317(new ReQL_Obj_t);
    reql_number_init(var317.get(), 2);

    reql_array_append(var316.get(), var317.get());

    std::unique_ptr<ReQL_Obj_t> var318(new ReQL_Obj_t);
    reql_number_init(var318.get(), 50);

    reql_array_append(var316.get(), var318.get());

    reql_array_append(var315.get(), var316.get());

    std::unique_ptr<ReQL_Obj_t> var319(new ReQL_Obj_t);
    reql_number_init(var319.get(), 1);

    reql_array_append(var315.get(), var319.get());

    reql_array_append(var4.get(), var315.get());

    std::unique_ptr<ReQL_Obj_t> var320(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr320(new ReQL_Obj_t*[2]);
    reql_array_init(var320.get(), arr320.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var321(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr321(new ReQL_Obj_t*[2]);
    reql_array_init(var321.get(), arr321.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var322(new ReQL_Obj_t);
    reql_number_init(var322.get(), 2);

    reql_array_append(var321.get(), var322.get());

    std::unique_ptr<ReQL_Obj_t> var323(new ReQL_Obj_t);
    reql_number_init(var323.get(), 54);

    reql_array_append(var321.get(), var323.get());

    reql_array_append(var320.get(), var321.get());

    std::unique_ptr<ReQL_Obj_t> var324(new ReQL_Obj_t);
    reql_number_init(var324.get(), 1);

    reql_array_append(var320.get(), var324.get());

    reql_array_append(var4.get(), var320.get());

    std::unique_ptr<ReQL_Obj_t> var325(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr325(new ReQL_Obj_t*[2]);
    reql_array_init(var325.get(), arr325.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var326(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr326(new ReQL_Obj_t*[2]);
    reql_array_init(var326.get(), arr326.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var327(new ReQL_Obj_t);
    reql_number_init(var327.get(), 2);

    reql_array_append(var326.get(), var327.get());

    std::unique_ptr<ReQL_Obj_t> var328(new ReQL_Obj_t);
    reql_number_init(var328.get(), 58);

    reql_array_append(var326.get(), var328.get());

    reql_array_append(var325.get(), var326.get());

    std::unique_ptr<ReQL_Obj_t> var329(new ReQL_Obj_t);
    reql_number_init(var329.get(), 1);

    reql_array_append(var325.get(), var329.get());

    reql_array_append(var4.get(), var325.get());

    std::unique_ptr<ReQL_Obj_t> var330(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr330(new ReQL_Obj_t*[2]);
    reql_array_init(var330.get(), arr330.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var331(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr331(new ReQL_Obj_t*[2]);
    reql_array_init(var331.get(), arr331.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var332(new ReQL_Obj_t);
    reql_number_init(var332.get(), 2);

    reql_array_append(var331.get(), var332.get());

    std::unique_ptr<ReQL_Obj_t> var333(new ReQL_Obj_t);
    reql_number_init(var333.get(), 62);

    reql_array_append(var331.get(), var333.get());

    reql_array_append(var330.get(), var331.get());

    std::unique_ptr<ReQL_Obj_t> var334(new ReQL_Obj_t);
    reql_number_init(var334.get(), 1);

    reql_array_append(var330.get(), var334.get());

    reql_array_append(var4.get(), var330.get());

    std::unique_ptr<ReQL_Obj_t> var335(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr335(new ReQL_Obj_t*[2]);
    reql_array_init(var335.get(), arr335.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var336(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr336(new ReQL_Obj_t*[2]);
    reql_array_init(var336.get(), arr336.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var337(new ReQL_Obj_t);
    reql_number_init(var337.get(), 2);

    reql_array_append(var336.get(), var337.get());

    std::unique_ptr<ReQL_Obj_t> var338(new ReQL_Obj_t);
    reql_number_init(var338.get(), 66);

    reql_array_append(var336.get(), var338.get());

    reql_array_append(var335.get(), var336.get());

    std::unique_ptr<ReQL_Obj_t> var339(new ReQL_Obj_t);
    reql_number_init(var339.get(), 1);

    reql_array_append(var335.get(), var339.get());

    reql_array_append(var4.get(), var335.get());

    std::unique_ptr<ReQL_Obj_t> var340(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr340(new ReQL_Obj_t*[2]);
    reql_array_init(var340.get(), arr340.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var341(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr341(new ReQL_Obj_t*[2]);
    reql_array_init(var341.get(), arr341.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var342(new ReQL_Obj_t);
    reql_number_init(var342.get(), 2);

    reql_array_append(var341.get(), var342.get());

    std::unique_ptr<ReQL_Obj_t> var343(new ReQL_Obj_t);
    reql_number_init(var343.get(), 70);

    reql_array_append(var341.get(), var343.get());

    reql_array_append(var340.get(), var341.get());

    std::unique_ptr<ReQL_Obj_t> var344(new ReQL_Obj_t);
    reql_number_init(var344.get(), 1);

    reql_array_append(var340.get(), var344.get());

    reql_array_append(var4.get(), var340.get());

    std::unique_ptr<ReQL_Obj_t> var345(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr345(new ReQL_Obj_t*[2]);
    reql_array_init(var345.get(), arr345.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var346(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr346(new ReQL_Obj_t*[2]);
    reql_array_init(var346.get(), arr346.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var347(new ReQL_Obj_t);
    reql_number_init(var347.get(), 2);

    reql_array_append(var346.get(), var347.get());

    std::unique_ptr<ReQL_Obj_t> var348(new ReQL_Obj_t);
    reql_number_init(var348.get(), 74);

    reql_array_append(var346.get(), var348.get());

    reql_array_append(var345.get(), var346.get());

    std::unique_ptr<ReQL_Obj_t> var349(new ReQL_Obj_t);
    reql_number_init(var349.get(), 1);

    reql_array_append(var345.get(), var349.get());

    reql_array_append(var4.get(), var345.get());

    std::unique_ptr<ReQL_Obj_t> var350(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr350(new ReQL_Obj_t*[2]);
    reql_array_init(var350.get(), arr350.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var351(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr351(new ReQL_Obj_t*[2]);
    reql_array_init(var351.get(), arr351.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var352(new ReQL_Obj_t);
    reql_number_init(var352.get(), 2);

    reql_array_append(var351.get(), var352.get());

    std::unique_ptr<ReQL_Obj_t> var353(new ReQL_Obj_t);
    reql_number_init(var353.get(), 78);

    reql_array_append(var351.get(), var353.get());

    reql_array_append(var350.get(), var351.get());

    std::unique_ptr<ReQL_Obj_t> var354(new ReQL_Obj_t);
    reql_number_init(var354.get(), 1);

    reql_array_append(var350.get(), var354.get());

    reql_array_append(var4.get(), var350.get());

    std::unique_ptr<ReQL_Obj_t> var355(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr355(new ReQL_Obj_t*[2]);
    reql_array_init(var355.get(), arr355.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var356(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr356(new ReQL_Obj_t*[2]);
    reql_array_init(var356.get(), arr356.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var357(new ReQL_Obj_t);
    reql_number_init(var357.get(), 2);

    reql_array_append(var356.get(), var357.get());

    std::unique_ptr<ReQL_Obj_t> var358(new ReQL_Obj_t);
    reql_number_init(var358.get(), 82);

    reql_array_append(var356.get(), var358.get());

    reql_array_append(var355.get(), var356.get());

    std::unique_ptr<ReQL_Obj_t> var359(new ReQL_Obj_t);
    reql_number_init(var359.get(), 1);

    reql_array_append(var355.get(), var359.get());

    reql_array_append(var4.get(), var355.get());

    std::unique_ptr<ReQL_Obj_t> var360(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr360(new ReQL_Obj_t*[2]);
    reql_array_init(var360.get(), arr360.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var361(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr361(new ReQL_Obj_t*[2]);
    reql_array_init(var361.get(), arr361.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var362(new ReQL_Obj_t);
    reql_number_init(var362.get(), 2);

    reql_array_append(var361.get(), var362.get());

    std::unique_ptr<ReQL_Obj_t> var363(new ReQL_Obj_t);
    reql_number_init(var363.get(), 86);

    reql_array_append(var361.get(), var363.get());

    reql_array_append(var360.get(), var361.get());

    std::unique_ptr<ReQL_Obj_t> var364(new ReQL_Obj_t);
    reql_number_init(var364.get(), 1);

    reql_array_append(var360.get(), var364.get());

    reql_array_append(var4.get(), var360.get());

    std::unique_ptr<ReQL_Obj_t> var365(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr365(new ReQL_Obj_t*[2]);
    reql_array_init(var365.get(), arr365.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var366(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr366(new ReQL_Obj_t*[2]);
    reql_array_init(var366.get(), arr366.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var367(new ReQL_Obj_t);
    reql_number_init(var367.get(), 2);

    reql_array_append(var366.get(), var367.get());

    std::unique_ptr<ReQL_Obj_t> var368(new ReQL_Obj_t);
    reql_number_init(var368.get(), 90);

    reql_array_append(var366.get(), var368.get());

    reql_array_append(var365.get(), var366.get());

    std::unique_ptr<ReQL_Obj_t> var369(new ReQL_Obj_t);
    reql_number_init(var369.get(), 1);

    reql_array_append(var365.get(), var369.get());

    reql_array_append(var4.get(), var365.get());

    std::unique_ptr<ReQL_Obj_t> var370(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr370(new ReQL_Obj_t*[2]);
    reql_array_init(var370.get(), arr370.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var371(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr371(new ReQL_Obj_t*[2]);
    reql_array_init(var371.get(), arr371.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var372(new ReQL_Obj_t);
    reql_number_init(var372.get(), 2);

    reql_array_append(var371.get(), var372.get());

    std::unique_ptr<ReQL_Obj_t> var373(new ReQL_Obj_t);
    reql_number_init(var373.get(), 94);

    reql_array_append(var371.get(), var373.get());

    reql_array_append(var370.get(), var371.get());

    std::unique_ptr<ReQL_Obj_t> var374(new ReQL_Obj_t);
    reql_number_init(var374.get(), 1);

    reql_array_append(var370.get(), var374.get());

    reql_array_append(var4.get(), var370.get());

    std::unique_ptr<ReQL_Obj_t> var375(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr375(new ReQL_Obj_t*[2]);
    reql_array_init(var375.get(), arr375.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var376(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr376(new ReQL_Obj_t*[2]);
    reql_array_init(var376.get(), arr376.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var377(new ReQL_Obj_t);
    reql_number_init(var377.get(), 2);

    reql_array_append(var376.get(), var377.get());

    std::unique_ptr<ReQL_Obj_t> var378(new ReQL_Obj_t);
    reql_number_init(var378.get(), 98);

    reql_array_append(var376.get(), var378.get());

    reql_array_append(var375.get(), var376.get());

    std::unique_ptr<ReQL_Obj_t> var379(new ReQL_Obj_t);
    reql_number_init(var379.get(), 1);

    reql_array_append(var375.get(), var379.get());

    reql_array_append(var4.get(), var375.get());

    std::unique_ptr<ReQL_Obj_t> var380(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr380(new ReQL_Obj_t*[2]);
    reql_array_init(var380.get(), arr380.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var381(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr381(new ReQL_Obj_t*[2]);
    reql_array_init(var381.get(), arr381.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var382(new ReQL_Obj_t);
    reql_number_init(var382.get(), 3);

    reql_array_append(var381.get(), var382.get());

    std::unique_ptr<ReQL_Obj_t> var383(new ReQL_Obj_t);
    reql_number_init(var383.get(), 3);

    reql_array_append(var381.get(), var383.get());

    reql_array_append(var380.get(), var381.get());

    std::unique_ptr<ReQL_Obj_t> var384(new ReQL_Obj_t);
    reql_number_init(var384.get(), 1);

    reql_array_append(var380.get(), var384.get());

    reql_array_append(var4.get(), var380.get());

    std::unique_ptr<ReQL_Obj_t> var385(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr385(new ReQL_Obj_t*[2]);
    reql_array_init(var385.get(), arr385.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var386(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr386(new ReQL_Obj_t*[2]);
    reql_array_init(var386.get(), arr386.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var387(new ReQL_Obj_t);
    reql_number_init(var387.get(), 3);

    reql_array_append(var386.get(), var387.get());

    std::unique_ptr<ReQL_Obj_t> var388(new ReQL_Obj_t);
    reql_number_init(var388.get(), 7);

    reql_array_append(var386.get(), var388.get());

    reql_array_append(var385.get(), var386.get());

    std::unique_ptr<ReQL_Obj_t> var389(new ReQL_Obj_t);
    reql_number_init(var389.get(), 1);

    reql_array_append(var385.get(), var389.get());

    reql_array_append(var4.get(), var385.get());

    std::unique_ptr<ReQL_Obj_t> var390(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr390(new ReQL_Obj_t*[2]);
    reql_array_init(var390.get(), arr390.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var391(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr391(new ReQL_Obj_t*[2]);
    reql_array_init(var391.get(), arr391.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var392(new ReQL_Obj_t);
    reql_number_init(var392.get(), 3);

    reql_array_append(var391.get(), var392.get());

    std::unique_ptr<ReQL_Obj_t> var393(new ReQL_Obj_t);
    reql_number_init(var393.get(), 11);

    reql_array_append(var391.get(), var393.get());

    reql_array_append(var390.get(), var391.get());

    std::unique_ptr<ReQL_Obj_t> var394(new ReQL_Obj_t);
    reql_number_init(var394.get(), 1);

    reql_array_append(var390.get(), var394.get());

    reql_array_append(var4.get(), var390.get());

    std::unique_ptr<ReQL_Obj_t> var395(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr395(new ReQL_Obj_t*[2]);
    reql_array_init(var395.get(), arr395.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var396(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr396(new ReQL_Obj_t*[2]);
    reql_array_init(var396.get(), arr396.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var397(new ReQL_Obj_t);
    reql_number_init(var397.get(), 3);

    reql_array_append(var396.get(), var397.get());

    std::unique_ptr<ReQL_Obj_t> var398(new ReQL_Obj_t);
    reql_number_init(var398.get(), 15);

    reql_array_append(var396.get(), var398.get());

    reql_array_append(var395.get(), var396.get());

    std::unique_ptr<ReQL_Obj_t> var399(new ReQL_Obj_t);
    reql_number_init(var399.get(), 1);

    reql_array_append(var395.get(), var399.get());

    reql_array_append(var4.get(), var395.get());

    std::unique_ptr<ReQL_Obj_t> var400(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr400(new ReQL_Obj_t*[2]);
    reql_array_init(var400.get(), arr400.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var401(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr401(new ReQL_Obj_t*[2]);
    reql_array_init(var401.get(), arr401.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var402(new ReQL_Obj_t);
    reql_number_init(var402.get(), 3);

    reql_array_append(var401.get(), var402.get());

    std::unique_ptr<ReQL_Obj_t> var403(new ReQL_Obj_t);
    reql_number_init(var403.get(), 19);

    reql_array_append(var401.get(), var403.get());

    reql_array_append(var400.get(), var401.get());

    std::unique_ptr<ReQL_Obj_t> var404(new ReQL_Obj_t);
    reql_number_init(var404.get(), 1);

    reql_array_append(var400.get(), var404.get());

    reql_array_append(var4.get(), var400.get());

    std::unique_ptr<ReQL_Obj_t> var405(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr405(new ReQL_Obj_t*[2]);
    reql_array_init(var405.get(), arr405.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var406(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr406(new ReQL_Obj_t*[2]);
    reql_array_init(var406.get(), arr406.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var407(new ReQL_Obj_t);
    reql_number_init(var407.get(), 3);

    reql_array_append(var406.get(), var407.get());

    std::unique_ptr<ReQL_Obj_t> var408(new ReQL_Obj_t);
    reql_number_init(var408.get(), 23);

    reql_array_append(var406.get(), var408.get());

    reql_array_append(var405.get(), var406.get());

    std::unique_ptr<ReQL_Obj_t> var409(new ReQL_Obj_t);
    reql_number_init(var409.get(), 1);

    reql_array_append(var405.get(), var409.get());

    reql_array_append(var4.get(), var405.get());

    std::unique_ptr<ReQL_Obj_t> var410(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr410(new ReQL_Obj_t*[2]);
    reql_array_init(var410.get(), arr410.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var411(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr411(new ReQL_Obj_t*[2]);
    reql_array_init(var411.get(), arr411.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var412(new ReQL_Obj_t);
    reql_number_init(var412.get(), 3);

    reql_array_append(var411.get(), var412.get());

    std::unique_ptr<ReQL_Obj_t> var413(new ReQL_Obj_t);
    reql_number_init(var413.get(), 27);

    reql_array_append(var411.get(), var413.get());

    reql_array_append(var410.get(), var411.get());

    std::unique_ptr<ReQL_Obj_t> var414(new ReQL_Obj_t);
    reql_number_init(var414.get(), 1);

    reql_array_append(var410.get(), var414.get());

    reql_array_append(var4.get(), var410.get());

    std::unique_ptr<ReQL_Obj_t> var415(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr415(new ReQL_Obj_t*[2]);
    reql_array_init(var415.get(), arr415.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var416(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr416(new ReQL_Obj_t*[2]);
    reql_array_init(var416.get(), arr416.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var417(new ReQL_Obj_t);
    reql_number_init(var417.get(), 3);

    reql_array_append(var416.get(), var417.get());

    std::unique_ptr<ReQL_Obj_t> var418(new ReQL_Obj_t);
    reql_number_init(var418.get(), 31);

    reql_array_append(var416.get(), var418.get());

    reql_array_append(var415.get(), var416.get());

    std::unique_ptr<ReQL_Obj_t> var419(new ReQL_Obj_t);
    reql_number_init(var419.get(), 1);

    reql_array_append(var415.get(), var419.get());

    reql_array_append(var4.get(), var415.get());

    std::unique_ptr<ReQL_Obj_t> var420(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr420(new ReQL_Obj_t*[2]);
    reql_array_init(var420.get(), arr420.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var421(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr421(new ReQL_Obj_t*[2]);
    reql_array_init(var421.get(), arr421.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var422(new ReQL_Obj_t);
    reql_number_init(var422.get(), 3);

    reql_array_append(var421.get(), var422.get());

    std::unique_ptr<ReQL_Obj_t> var423(new ReQL_Obj_t);
    reql_number_init(var423.get(), 35);

    reql_array_append(var421.get(), var423.get());

    reql_array_append(var420.get(), var421.get());

    std::unique_ptr<ReQL_Obj_t> var424(new ReQL_Obj_t);
    reql_number_init(var424.get(), 1);

    reql_array_append(var420.get(), var424.get());

    reql_array_append(var4.get(), var420.get());

    std::unique_ptr<ReQL_Obj_t> var425(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr425(new ReQL_Obj_t*[2]);
    reql_array_init(var425.get(), arr425.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var426(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr426(new ReQL_Obj_t*[2]);
    reql_array_init(var426.get(), arr426.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var427(new ReQL_Obj_t);
    reql_number_init(var427.get(), 3);

    reql_array_append(var426.get(), var427.get());

    std::unique_ptr<ReQL_Obj_t> var428(new ReQL_Obj_t);
    reql_number_init(var428.get(), 39);

    reql_array_append(var426.get(), var428.get());

    reql_array_append(var425.get(), var426.get());

    std::unique_ptr<ReQL_Obj_t> var429(new ReQL_Obj_t);
    reql_number_init(var429.get(), 1);

    reql_array_append(var425.get(), var429.get());

    reql_array_append(var4.get(), var425.get());

    std::unique_ptr<ReQL_Obj_t> var430(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr430(new ReQL_Obj_t*[2]);
    reql_array_init(var430.get(), arr430.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var431(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr431(new ReQL_Obj_t*[2]);
    reql_array_init(var431.get(), arr431.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var432(new ReQL_Obj_t);
    reql_number_init(var432.get(), 3);

    reql_array_append(var431.get(), var432.get());

    std::unique_ptr<ReQL_Obj_t> var433(new ReQL_Obj_t);
    reql_number_init(var433.get(), 43);

    reql_array_append(var431.get(), var433.get());

    reql_array_append(var430.get(), var431.get());

    std::unique_ptr<ReQL_Obj_t> var434(new ReQL_Obj_t);
    reql_number_init(var434.get(), 1);

    reql_array_append(var430.get(), var434.get());

    reql_array_append(var4.get(), var430.get());

    std::unique_ptr<ReQL_Obj_t> var435(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr435(new ReQL_Obj_t*[2]);
    reql_array_init(var435.get(), arr435.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var436(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr436(new ReQL_Obj_t*[2]);
    reql_array_init(var436.get(), arr436.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var437(new ReQL_Obj_t);
    reql_number_init(var437.get(), 3);

    reql_array_append(var436.get(), var437.get());

    std::unique_ptr<ReQL_Obj_t> var438(new ReQL_Obj_t);
    reql_number_init(var438.get(), 47);

    reql_array_append(var436.get(), var438.get());

    reql_array_append(var435.get(), var436.get());

    std::unique_ptr<ReQL_Obj_t> var439(new ReQL_Obj_t);
    reql_number_init(var439.get(), 1);

    reql_array_append(var435.get(), var439.get());

    reql_array_append(var4.get(), var435.get());

    std::unique_ptr<ReQL_Obj_t> var440(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr440(new ReQL_Obj_t*[2]);
    reql_array_init(var440.get(), arr440.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var441(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr441(new ReQL_Obj_t*[2]);
    reql_array_init(var441.get(), arr441.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var442(new ReQL_Obj_t);
    reql_number_init(var442.get(), 3);

    reql_array_append(var441.get(), var442.get());

    std::unique_ptr<ReQL_Obj_t> var443(new ReQL_Obj_t);
    reql_number_init(var443.get(), 51);

    reql_array_append(var441.get(), var443.get());

    reql_array_append(var440.get(), var441.get());

    std::unique_ptr<ReQL_Obj_t> var444(new ReQL_Obj_t);
    reql_number_init(var444.get(), 1);

    reql_array_append(var440.get(), var444.get());

    reql_array_append(var4.get(), var440.get());

    std::unique_ptr<ReQL_Obj_t> var445(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr445(new ReQL_Obj_t*[2]);
    reql_array_init(var445.get(), arr445.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var446(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr446(new ReQL_Obj_t*[2]);
    reql_array_init(var446.get(), arr446.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var447(new ReQL_Obj_t);
    reql_number_init(var447.get(), 3);

    reql_array_append(var446.get(), var447.get());

    std::unique_ptr<ReQL_Obj_t> var448(new ReQL_Obj_t);
    reql_number_init(var448.get(), 55);

    reql_array_append(var446.get(), var448.get());

    reql_array_append(var445.get(), var446.get());

    std::unique_ptr<ReQL_Obj_t> var449(new ReQL_Obj_t);
    reql_number_init(var449.get(), 1);

    reql_array_append(var445.get(), var449.get());

    reql_array_append(var4.get(), var445.get());

    std::unique_ptr<ReQL_Obj_t> var450(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr450(new ReQL_Obj_t*[2]);
    reql_array_init(var450.get(), arr450.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var451(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr451(new ReQL_Obj_t*[2]);
    reql_array_init(var451.get(), arr451.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var452(new ReQL_Obj_t);
    reql_number_init(var452.get(), 3);

    reql_array_append(var451.get(), var452.get());

    std::unique_ptr<ReQL_Obj_t> var453(new ReQL_Obj_t);
    reql_number_init(var453.get(), 59);

    reql_array_append(var451.get(), var453.get());

    reql_array_append(var450.get(), var451.get());

    std::unique_ptr<ReQL_Obj_t> var454(new ReQL_Obj_t);
    reql_number_init(var454.get(), 1);

    reql_array_append(var450.get(), var454.get());

    reql_array_append(var4.get(), var450.get());

    std::unique_ptr<ReQL_Obj_t> var455(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr455(new ReQL_Obj_t*[2]);
    reql_array_init(var455.get(), arr455.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var456(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr456(new ReQL_Obj_t*[2]);
    reql_array_init(var456.get(), arr456.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var457(new ReQL_Obj_t);
    reql_number_init(var457.get(), 3);

    reql_array_append(var456.get(), var457.get());

    std::unique_ptr<ReQL_Obj_t> var458(new ReQL_Obj_t);
    reql_number_init(var458.get(), 63);

    reql_array_append(var456.get(), var458.get());

    reql_array_append(var455.get(), var456.get());

    std::unique_ptr<ReQL_Obj_t> var459(new ReQL_Obj_t);
    reql_number_init(var459.get(), 1);

    reql_array_append(var455.get(), var459.get());

    reql_array_append(var4.get(), var455.get());

    std::unique_ptr<ReQL_Obj_t> var460(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr460(new ReQL_Obj_t*[2]);
    reql_array_init(var460.get(), arr460.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var461(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr461(new ReQL_Obj_t*[2]);
    reql_array_init(var461.get(), arr461.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var462(new ReQL_Obj_t);
    reql_number_init(var462.get(), 3);

    reql_array_append(var461.get(), var462.get());

    std::unique_ptr<ReQL_Obj_t> var463(new ReQL_Obj_t);
    reql_number_init(var463.get(), 67);

    reql_array_append(var461.get(), var463.get());

    reql_array_append(var460.get(), var461.get());

    std::unique_ptr<ReQL_Obj_t> var464(new ReQL_Obj_t);
    reql_number_init(var464.get(), 1);

    reql_array_append(var460.get(), var464.get());

    reql_array_append(var4.get(), var460.get());

    std::unique_ptr<ReQL_Obj_t> var465(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr465(new ReQL_Obj_t*[2]);
    reql_array_init(var465.get(), arr465.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var466(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr466(new ReQL_Obj_t*[2]);
    reql_array_init(var466.get(), arr466.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var467(new ReQL_Obj_t);
    reql_number_init(var467.get(), 3);

    reql_array_append(var466.get(), var467.get());

    std::unique_ptr<ReQL_Obj_t> var468(new ReQL_Obj_t);
    reql_number_init(var468.get(), 71);

    reql_array_append(var466.get(), var468.get());

    reql_array_append(var465.get(), var466.get());

    std::unique_ptr<ReQL_Obj_t> var469(new ReQL_Obj_t);
    reql_number_init(var469.get(), 1);

    reql_array_append(var465.get(), var469.get());

    reql_array_append(var4.get(), var465.get());

    std::unique_ptr<ReQL_Obj_t> var470(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr470(new ReQL_Obj_t*[2]);
    reql_array_init(var470.get(), arr470.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var471(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr471(new ReQL_Obj_t*[2]);
    reql_array_init(var471.get(), arr471.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var472(new ReQL_Obj_t);
    reql_number_init(var472.get(), 3);

    reql_array_append(var471.get(), var472.get());

    std::unique_ptr<ReQL_Obj_t> var473(new ReQL_Obj_t);
    reql_number_init(var473.get(), 75);

    reql_array_append(var471.get(), var473.get());

    reql_array_append(var470.get(), var471.get());

    std::unique_ptr<ReQL_Obj_t> var474(new ReQL_Obj_t);
    reql_number_init(var474.get(), 1);

    reql_array_append(var470.get(), var474.get());

    reql_array_append(var4.get(), var470.get());

    std::unique_ptr<ReQL_Obj_t> var475(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr475(new ReQL_Obj_t*[2]);
    reql_array_init(var475.get(), arr475.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var476(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr476(new ReQL_Obj_t*[2]);
    reql_array_init(var476.get(), arr476.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var477(new ReQL_Obj_t);
    reql_number_init(var477.get(), 3);

    reql_array_append(var476.get(), var477.get());

    std::unique_ptr<ReQL_Obj_t> var478(new ReQL_Obj_t);
    reql_number_init(var478.get(), 79);

    reql_array_append(var476.get(), var478.get());

    reql_array_append(var475.get(), var476.get());

    std::unique_ptr<ReQL_Obj_t> var479(new ReQL_Obj_t);
    reql_number_init(var479.get(), 1);

    reql_array_append(var475.get(), var479.get());

    reql_array_append(var4.get(), var475.get());

    std::unique_ptr<ReQL_Obj_t> var480(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr480(new ReQL_Obj_t*[2]);
    reql_array_init(var480.get(), arr480.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var481(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr481(new ReQL_Obj_t*[2]);
    reql_array_init(var481.get(), arr481.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var482(new ReQL_Obj_t);
    reql_number_init(var482.get(), 3);

    reql_array_append(var481.get(), var482.get());

    std::unique_ptr<ReQL_Obj_t> var483(new ReQL_Obj_t);
    reql_number_init(var483.get(), 83);

    reql_array_append(var481.get(), var483.get());

    reql_array_append(var480.get(), var481.get());

    std::unique_ptr<ReQL_Obj_t> var484(new ReQL_Obj_t);
    reql_number_init(var484.get(), 1);

    reql_array_append(var480.get(), var484.get());

    reql_array_append(var4.get(), var480.get());

    std::unique_ptr<ReQL_Obj_t> var485(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr485(new ReQL_Obj_t*[2]);
    reql_array_init(var485.get(), arr485.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var486(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr486(new ReQL_Obj_t*[2]);
    reql_array_init(var486.get(), arr486.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var487(new ReQL_Obj_t);
    reql_number_init(var487.get(), 3);

    reql_array_append(var486.get(), var487.get());

    std::unique_ptr<ReQL_Obj_t> var488(new ReQL_Obj_t);
    reql_number_init(var488.get(), 87);

    reql_array_append(var486.get(), var488.get());

    reql_array_append(var485.get(), var486.get());

    std::unique_ptr<ReQL_Obj_t> var489(new ReQL_Obj_t);
    reql_number_init(var489.get(), 1);

    reql_array_append(var485.get(), var489.get());

    reql_array_append(var4.get(), var485.get());

    std::unique_ptr<ReQL_Obj_t> var490(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr490(new ReQL_Obj_t*[2]);
    reql_array_init(var490.get(), arr490.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var491(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr491(new ReQL_Obj_t*[2]);
    reql_array_init(var491.get(), arr491.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var492(new ReQL_Obj_t);
    reql_number_init(var492.get(), 3);

    reql_array_append(var491.get(), var492.get());

    std::unique_ptr<ReQL_Obj_t> var493(new ReQL_Obj_t);
    reql_number_init(var493.get(), 91);

    reql_array_append(var491.get(), var493.get());

    reql_array_append(var490.get(), var491.get());

    std::unique_ptr<ReQL_Obj_t> var494(new ReQL_Obj_t);
    reql_number_init(var494.get(), 1);

    reql_array_append(var490.get(), var494.get());

    reql_array_append(var4.get(), var490.get());

    std::unique_ptr<ReQL_Obj_t> var495(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr495(new ReQL_Obj_t*[2]);
    reql_array_init(var495.get(), arr495.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var496(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr496(new ReQL_Obj_t*[2]);
    reql_array_init(var496.get(), arr496.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var497(new ReQL_Obj_t);
    reql_number_init(var497.get(), 3);

    reql_array_append(var496.get(), var497.get());

    std::unique_ptr<ReQL_Obj_t> var498(new ReQL_Obj_t);
    reql_number_init(var498.get(), 95);

    reql_array_append(var496.get(), var498.get());

    reql_array_append(var495.get(), var496.get());

    std::unique_ptr<ReQL_Obj_t> var499(new ReQL_Obj_t);
    reql_number_init(var499.get(), 1);

    reql_array_append(var495.get(), var499.get());

    reql_array_append(var4.get(), var495.get());

    std::unique_ptr<ReQL_Obj_t> var500(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr500(new ReQL_Obj_t*[2]);
    reql_array_init(var500.get(), arr500.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var501(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr501(new ReQL_Obj_t*[2]);
    reql_array_init(var501.get(), arr501.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var502(new ReQL_Obj_t);
    reql_number_init(var502.get(), 3);

    reql_array_append(var501.get(), var502.get());

    std::unique_ptr<ReQL_Obj_t> var503(new ReQL_Obj_t);
    reql_number_init(var503.get(), 99);

    reql_array_append(var501.get(), var503.get());

    reql_array_append(var500.get(), var501.get());

    std::unique_ptr<ReQL_Obj_t> var504(new ReQL_Obj_t);
    reql_number_init(var504.get(), 1);

    reql_array_append(var500.get(), var504.get());

    reql_array_append(var4.get(), var500.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test87") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr6(new ReQL_Obj_t*[2]);
    reql_array_init(var6.get(), arr6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_array_append(var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0);

    reql_array_append(var6.get(), var8.get());

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 25);

    reql_array_append(var5.get(), var9.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 1);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 25);

    reql_array_append(var10.get(), var14.get());

    reql_array_append(var4.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr16(new ReQL_Obj_t*[2]);
    reql_array_init(var16.get(), arr16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 2);

    reql_array_append(var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 2);

    reql_array_append(var16.get(), var18.get());

    reql_array_append(var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 25);

    reql_array_append(var15.get(), var19.get());

    reql_array_append(var4.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[2]);
    reql_array_init(var21.get(), arr21.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 3);

    reql_array_append(var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 3);

    reql_array_append(var21.get(), var23.get());

    reql_array_append(var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 25);

    reql_array_append(var20.get(), var24.get());

    reql_array_append(var4.get(), var20.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test88") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[12]);
    const ReQL_Byte src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[4]);
    const ReQL_Byte src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[16]);
    reql_array_init(var4.get(), arr4.get(), 16);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr6(new ReQL_Obj_t*[4]);
    reql_array_init(var6.get(), arr6.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_array_append(var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[1]);
    const ReQL_Byte src8[] = "f";
    reql_string_init(var8.get(), buf8.get(), src8, 1);

    reql_array_append(var6.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_null_init(var9.get());

    reql_array_append(var6.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[1]);
    reql_array_init(var10.get(), arr10.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_array_append(var10.get(), var11.get());

    reql_array_append(var6.get(), var10.get());

    reql_array_append(var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 25);

    reql_array_append(var5.get(), var12.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr14(new ReQL_Obj_t*[4]);
    reql_array_init(var14.get(), arr14.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 0);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[1]);
    const ReQL_Byte src16[] = "f";
    reql_string_init(var16.get(), buf16.get(), src16, 1);

    reql_array_append(var14.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_null_init(var17.get());

    reql_array_append(var14.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_null_init(var18.get());

    reql_array_append(var14.get(), var18.get());

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 25);

    reql_array_append(var13.get(), var19.get());

    reql_array_append(var4.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[4]);
    reql_array_init(var21.get(), arr21.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 0);

    reql_array_append(var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[1]);
    const ReQL_Byte src23[] = "f";
    reql_string_init(var23.get(), buf23.get(), src23, 1);

    reql_array_append(var21.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_null_init(var24.get());

    reql_array_append(var21.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 0);

    reql_array_append(var21.get(), var25.get());

    reql_array_append(var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 25);

    reql_array_append(var20.get(), var26.get());

    reql_array_append(var4.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr27(new ReQL_Obj_t*[2]);
    reql_array_init(var27.get(), arr27.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr28(new ReQL_Obj_t*[4]);
    reql_array_init(var28.get(), arr28.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_number_init(var29.get(), 0);

    reql_array_append(var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[1]);
    const ReQL_Byte src30[] = "f";
    reql_string_init(var30.get(), buf30.get(), src30, 1);

    reql_array_append(var28.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    reql_null_init(var31.get());

    reql_array_append(var28.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_object_init(var32.get(), nullptr, 0);

    reql_array_append(var28.get(), var32.get());

    reql_array_append(var27.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_number_init(var33.get(), 25);

    reql_array_append(var27.get(), var33.get());

    reql_array_append(var4.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr34(new ReQL_Obj_t*[2]);
    reql_array_init(var34.get(), arr34.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr35(new ReQL_Obj_t*[4]);
    reql_array_init(var35.get(), arr35.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_number_init(var36.get(), 1);

    reql_array_append(var35.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[1]);
    const ReQL_Byte src37[] = "f";
    reql_string_init(var37.get(), buf37.get(), src37, 1);

    reql_array_append(var35.get(), var37.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    reql_null_init(var38.get());

    reql_array_append(var35.get(), var38.get());

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr39(new ReQL_Obj_t*[1]);
    reql_array_init(var39.get(), arr39.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    reql_number_init(var40.get(), 0);

    reql_array_append(var39.get(), var40.get());

    reql_array_append(var35.get(), var39.get());

    reql_array_append(var34.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    reql_number_init(var41.get(), 25);

    reql_array_append(var34.get(), var41.get());

    reql_array_append(var4.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr42(new ReQL_Obj_t*[2]);
    reql_array_init(var42.get(), arr42.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr43(new ReQL_Obj_t*[4]);
    reql_array_init(var43.get(), arr43.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    reql_number_init(var44.get(), 1);

    reql_array_append(var43.get(), var44.get());

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf45(new ReQL_Byte[1]);
    const ReQL_Byte src45[] = "f";
    reql_string_init(var45.get(), buf45.get(), src45, 1);

    reql_array_append(var43.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    reql_null_init(var46.get());

    reql_array_append(var43.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_null_init(var47.get());

    reql_array_append(var43.get(), var47.get());

    reql_array_append(var42.get(), var43.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_number_init(var48.get(), 25);

    reql_array_append(var42.get(), var48.get());

    reql_array_append(var4.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr49(new ReQL_Obj_t*[2]);
    reql_array_init(var49.get(), arr49.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr50(new ReQL_Obj_t*[4]);
    reql_array_init(var50.get(), arr50.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    reql_number_init(var51.get(), 1);

    reql_array_append(var50.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf52(new ReQL_Byte[1]);
    const ReQL_Byte src52[] = "f";
    reql_string_init(var52.get(), buf52.get(), src52, 1);

    reql_array_append(var50.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_null_init(var53.get());

    reql_array_append(var50.get(), var53.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    reql_number_init(var54.get(), 0);

    reql_array_append(var50.get(), var54.get());

    reql_array_append(var49.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    reql_number_init(var55.get(), 25);

    reql_array_append(var49.get(), var55.get());

    reql_array_append(var4.get(), var49.get());

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr56(new ReQL_Obj_t*[2]);
    reql_array_init(var56.get(), arr56.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr57(new ReQL_Obj_t*[4]);
    reql_array_init(var57.get(), arr57.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_number_init(var58.get(), 1);

    reql_array_append(var57.get(), var58.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf59(new ReQL_Byte[1]);
    const ReQL_Byte src59[] = "f";
    reql_string_init(var59.get(), buf59.get(), src59, 1);

    reql_array_append(var57.get(), var59.get());

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    reql_null_init(var60.get());

    reql_array_append(var57.get(), var60.get());

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    reql_object_init(var61.get(), nullptr, 0);

    reql_array_append(var57.get(), var61.get());

    reql_array_append(var56.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    reql_number_init(var62.get(), 25);

    reql_array_append(var56.get(), var62.get());

    reql_array_append(var4.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr63(new ReQL_Obj_t*[2]);
    reql_array_init(var63.get(), arr63.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr64(new ReQL_Obj_t*[4]);
    reql_array_init(var64.get(), arr64.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    reql_number_init(var65.get(), 2);

    reql_array_append(var64.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf66(new ReQL_Byte[1]);
    const ReQL_Byte src66[] = "f";
    reql_string_init(var66.get(), buf66.get(), src66, 1);

    reql_array_append(var64.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    reql_null_init(var67.get());

    reql_array_append(var64.get(), var67.get());

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr68(new ReQL_Obj_t*[1]);
    reql_array_init(var68.get(), arr68.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    reql_number_init(var69.get(), 0);

    reql_array_append(var68.get(), var69.get());

    reql_array_append(var64.get(), var68.get());

    reql_array_append(var63.get(), var64.get());

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    reql_number_init(var70.get(), 25);

    reql_array_append(var63.get(), var70.get());

    reql_array_append(var4.get(), var63.get());

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr71(new ReQL_Obj_t*[2]);
    reql_array_init(var71.get(), arr71.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr72(new ReQL_Obj_t*[4]);
    reql_array_init(var72.get(), arr72.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_number_init(var73.get(), 2);

    reql_array_append(var72.get(), var73.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf74(new ReQL_Byte[1]);
    const ReQL_Byte src74[] = "f";
    reql_string_init(var74.get(), buf74.get(), src74, 1);

    reql_array_append(var72.get(), var74.get());

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    reql_null_init(var75.get());

    reql_array_append(var72.get(), var75.get());

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    reql_null_init(var76.get());

    reql_array_append(var72.get(), var76.get());

    reql_array_append(var71.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    reql_number_init(var77.get(), 25);

    reql_array_append(var71.get(), var77.get());

    reql_array_append(var4.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr78(new ReQL_Obj_t*[2]);
    reql_array_init(var78.get(), arr78.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr79(new ReQL_Obj_t*[4]);
    reql_array_init(var79.get(), arr79.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    reql_number_init(var80.get(), 2);

    reql_array_append(var79.get(), var80.get());

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf81(new ReQL_Byte[1]);
    const ReQL_Byte src81[] = "f";
    reql_string_init(var81.get(), buf81.get(), src81, 1);

    reql_array_append(var79.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_null_init(var82.get());

    reql_array_append(var79.get(), var82.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    reql_number_init(var83.get(), 0);

    reql_array_append(var79.get(), var83.get());

    reql_array_append(var78.get(), var79.get());

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    reql_number_init(var84.get(), 25);

    reql_array_append(var78.get(), var84.get());

    reql_array_append(var4.get(), var78.get());

    std::unique_ptr<ReQL_Obj_t> var85(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr85(new ReQL_Obj_t*[2]);
    reql_array_init(var85.get(), arr85.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var86(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr86(new ReQL_Obj_t*[4]);
    reql_array_init(var86.get(), arr86.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var87(new ReQL_Obj_t);
    reql_number_init(var87.get(), 2);

    reql_array_append(var86.get(), var87.get());

    std::unique_ptr<ReQL_Obj_t> var88(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf88(new ReQL_Byte[1]);
    const ReQL_Byte src88[] = "f";
    reql_string_init(var88.get(), buf88.get(), src88, 1);

    reql_array_append(var86.get(), var88.get());

    std::unique_ptr<ReQL_Obj_t> var89(new ReQL_Obj_t);
    reql_null_init(var89.get());

    reql_array_append(var86.get(), var89.get());

    std::unique_ptr<ReQL_Obj_t> var90(new ReQL_Obj_t);
    reql_object_init(var90.get(), nullptr, 0);

    reql_array_append(var86.get(), var90.get());

    reql_array_append(var85.get(), var86.get());

    std::unique_ptr<ReQL_Obj_t> var91(new ReQL_Obj_t);
    reql_number_init(var91.get(), 25);

    reql_array_append(var85.get(), var91.get());

    reql_array_append(var4.get(), var85.get());

    std::unique_ptr<ReQL_Obj_t> var92(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr92(new ReQL_Obj_t*[2]);
    reql_array_init(var92.get(), arr92.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var93(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr93(new ReQL_Obj_t*[4]);
    reql_array_init(var93.get(), arr93.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var94(new ReQL_Obj_t);
    reql_number_init(var94.get(), 3);

    reql_array_append(var93.get(), var94.get());

    std::unique_ptr<ReQL_Obj_t> var95(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf95(new ReQL_Byte[1]);
    const ReQL_Byte src95[] = "f";
    reql_string_init(var95.get(), buf95.get(), src95, 1);

    reql_array_append(var93.get(), var95.get());

    std::unique_ptr<ReQL_Obj_t> var96(new ReQL_Obj_t);
    reql_null_init(var96.get());

    reql_array_append(var93.get(), var96.get());

    std::unique_ptr<ReQL_Obj_t> var97(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr97(new ReQL_Obj_t*[1]);
    reql_array_init(var97.get(), arr97.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var98(new ReQL_Obj_t);
    reql_number_init(var98.get(), 0);

    reql_array_append(var97.get(), var98.get());

    reql_array_append(var93.get(), var97.get());

    reql_array_append(var92.get(), var93.get());

    std::unique_ptr<ReQL_Obj_t> var99(new ReQL_Obj_t);
    reql_number_init(var99.get(), 25);

    reql_array_append(var92.get(), var99.get());

    reql_array_append(var4.get(), var92.get());

    std::unique_ptr<ReQL_Obj_t> var100(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr100(new ReQL_Obj_t*[2]);
    reql_array_init(var100.get(), arr100.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var101(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr101(new ReQL_Obj_t*[4]);
    reql_array_init(var101.get(), arr101.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var102(new ReQL_Obj_t);
    reql_number_init(var102.get(), 3);

    reql_array_append(var101.get(), var102.get());

    std::unique_ptr<ReQL_Obj_t> var103(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf103(new ReQL_Byte[1]);
    const ReQL_Byte src103[] = "f";
    reql_string_init(var103.get(), buf103.get(), src103, 1);

    reql_array_append(var101.get(), var103.get());

    std::unique_ptr<ReQL_Obj_t> var104(new ReQL_Obj_t);
    reql_null_init(var104.get());

    reql_array_append(var101.get(), var104.get());

    std::unique_ptr<ReQL_Obj_t> var105(new ReQL_Obj_t);
    reql_null_init(var105.get());

    reql_array_append(var101.get(), var105.get());

    reql_array_append(var100.get(), var101.get());

    std::unique_ptr<ReQL_Obj_t> var106(new ReQL_Obj_t);
    reql_number_init(var106.get(), 25);

    reql_array_append(var100.get(), var106.get());

    reql_array_append(var4.get(), var100.get());

    std::unique_ptr<ReQL_Obj_t> var107(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr107(new ReQL_Obj_t*[2]);
    reql_array_init(var107.get(), arr107.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var108(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr108(new ReQL_Obj_t*[4]);
    reql_array_init(var108.get(), arr108.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var109(new ReQL_Obj_t);
    reql_number_init(var109.get(), 3);

    reql_array_append(var108.get(), var109.get());

    std::unique_ptr<ReQL_Obj_t> var110(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf110(new ReQL_Byte[1]);
    const ReQL_Byte src110[] = "f";
    reql_string_init(var110.get(), buf110.get(), src110, 1);

    reql_array_append(var108.get(), var110.get());

    std::unique_ptr<ReQL_Obj_t> var111(new ReQL_Obj_t);
    reql_null_init(var111.get());

    reql_array_append(var108.get(), var111.get());

    std::unique_ptr<ReQL_Obj_t> var112(new ReQL_Obj_t);
    reql_number_init(var112.get(), 0);

    reql_array_append(var108.get(), var112.get());

    reql_array_append(var107.get(), var108.get());

    std::unique_ptr<ReQL_Obj_t> var113(new ReQL_Obj_t);
    reql_number_init(var113.get(), 25);

    reql_array_append(var107.get(), var113.get());

    reql_array_append(var4.get(), var107.get());

    std::unique_ptr<ReQL_Obj_t> var114(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr114(new ReQL_Obj_t*[2]);
    reql_array_init(var114.get(), arr114.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var115(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr115(new ReQL_Obj_t*[4]);
    reql_array_init(var115.get(), arr115.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var116(new ReQL_Obj_t);
    reql_number_init(var116.get(), 3);

    reql_array_append(var115.get(), var116.get());

    std::unique_ptr<ReQL_Obj_t> var117(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf117(new ReQL_Byte[1]);
    const ReQL_Byte src117[] = "f";
    reql_string_init(var117.get(), buf117.get(), src117, 1);

    reql_array_append(var115.get(), var117.get());

    std::unique_ptr<ReQL_Obj_t> var118(new ReQL_Obj_t);
    reql_null_init(var118.get());

    reql_array_append(var115.get(), var118.get());

    std::unique_ptr<ReQL_Obj_t> var119(new ReQL_Obj_t);
    reql_object_init(var119.get(), nullptr, 0);

    reql_array_append(var115.get(), var119.get());

    reql_array_append(var114.get(), var115.get());

    std::unique_ptr<ReQL_Obj_t> var120(new ReQL_Obj_t);
    reql_number_init(var120.get(), 25);

    reql_array_append(var114.get(), var120.get());

    reql_array_append(var4.get(), var114.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test89") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[9]);
    const ReQL_Byte src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), src4, 9);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 25);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf7(new ReQL_Byte[5]);
    const ReQL_Byte src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), src7, 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[9]);
    const ReQL_Byte src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), src9, 9);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 25);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[5]);
    const ReQL_Byte src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[9]);
    const ReQL_Byte src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), src14, 9);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 25);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[5]);
    const ReQL_Byte src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[9]);
    const ReQL_Byte src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), src19, 9);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 25);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test90") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test91") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[2]);
    reql_array_init(var3.get(), arr3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 0);

    reql_array_append(var3.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[9]);
    const ReQL_Byte src6[] = "reduction";
    reql_string_init(var6.get(), buf6.get(), src6, 9);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 24);

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[5]);
    const ReQL_Byte src9[] = "group";
    reql_string_init(var9.get(), buf9.get(), src9, 5);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 1);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_array_append(var10.get(), var12.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[9]);
    const ReQL_Byte src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), src13, 9);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 28);

    reql_object_add(var8.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[5]);
    const ReQL_Byte src16[] = "group";
    reql_string_init(var16.get(), buf16.get(), src16, 5);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 2);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 2);

    reql_array_append(var17.get(), var19.get());

    reql_object_add(var15.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[9]);
    const ReQL_Byte src20[] = "reduction";
    reql_string_init(var20.get(), buf20.get(), src20, 9);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 32);

    reql_object_add(var15.get(), var20.get(), var21.get());

    reql_array_append(var0.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair22(new ReQL_Pair_t[2]);
    reql_object_init(var22.get(), pair22.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[5]);
    const ReQL_Byte src23[] = "group";
    reql_string_init(var23.get(), buf23.get(), src23, 5);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr24(new ReQL_Obj_t*[2]);
    reql_array_init(var24.get(), arr24.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 3);

    reql_array_append(var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 3);

    reql_array_append(var24.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf27(new ReQL_Byte[9]);
    const ReQL_Byte src27[] = "reduction";
    reql_string_init(var27.get(), buf27.get(), src27, 9);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 36);

    reql_object_add(var22.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var22.get());
  }

  SECTION("test92") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[2]);
    reql_array_init(var3.get(), arr3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_null_init(var5.get());

    reql_array_append(var3.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[9]);
    const ReQL_Byte src6[] = "reduction";
    reql_string_init(var6.get(), buf6.get(), src6, 9);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 25);

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[5]);
    const ReQL_Byte src9[] = "group";
    reql_string_init(var9.get(), buf9.get(), src9, 5);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 1);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_null_init(var12.get());

    reql_array_append(var10.get(), var12.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[9]);
    const ReQL_Byte src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), src13, 9);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 25);

    reql_object_add(var8.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[5]);
    const ReQL_Byte src16[] = "group";
    reql_string_init(var16.get(), buf16.get(), src16, 5);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 2);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_null_init(var19.get());

    reql_array_append(var17.get(), var19.get());

    reql_object_add(var15.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[9]);
    const ReQL_Byte src20[] = "reduction";
    reql_string_init(var20.get(), buf20.get(), src20, 9);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 25);

    reql_object_add(var15.get(), var20.get(), var21.get());

    reql_array_append(var0.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair22(new ReQL_Pair_t[2]);
    reql_object_init(var22.get(), pair22.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[5]);
    const ReQL_Byte src23[] = "group";
    reql_string_init(var23.get(), buf23.get(), src23, 5);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr24(new ReQL_Obj_t*[2]);
    reql_array_init(var24.get(), arr24.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 3);

    reql_array_append(var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_null_init(var26.get());

    reql_array_append(var24.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf27(new ReQL_Byte[9]);
    const ReQL_Byte src27[] = "reduction";
    reql_string_init(var27.get(), buf27.get(), src27, 9);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 25);

    reql_object_add(var22.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var22.get());
  }

  SECTION("test93") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[8]);
    reql_array_init(var0.get(), arr0.get(), 8);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[5]);
    const ReQL_Byte src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[2]);
    reql_array_init(var3.get(), arr3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1);

    reql_array_append(var3.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[9]);
    const ReQL_Byte src6[] = "reduction";
    reql_string_init(var6.get(), buf6.get(), src6, 9);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 25);

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[5]);
    const ReQL_Byte src9[] = "group";
    reql_string_init(var9.get(), buf9.get(), src9, 5);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[3]);
    const ReQL_Byte src12[] = "two";
    reql_string_init(var12.get(), buf12.get(), src12, 3);

    reql_array_append(var10.get(), var12.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[9]);
    const ReQL_Byte src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), src13, 9);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 25);

    reql_object_add(var8.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[5]);
    const ReQL_Byte src16[] = "group";
    reql_string_init(var16.get(), buf16.get(), src16, 5);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 1);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 1);

    reql_array_append(var17.get(), var19.get());

    reql_object_add(var15.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[9]);
    const ReQL_Byte src20[] = "reduction";
    reql_string_init(var20.get(), buf20.get(), src20, 9);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 25);

    reql_object_add(var15.get(), var20.get(), var21.get());

    reql_array_append(var0.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair22(new ReQL_Pair_t[2]);
    reql_object_init(var22.get(), pair22.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[5]);
    const ReQL_Byte src23[] = "group";
    reql_string_init(var23.get(), buf23.get(), src23, 5);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr24(new ReQL_Obj_t*[2]);
    reql_array_init(var24.get(), arr24.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 1);

    reql_array_append(var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf26(new ReQL_Byte[3]);
    const ReQL_Byte src26[] = "two";
    reql_string_init(var26.get(), buf26.get(), src26, 3);

    reql_array_append(var24.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf27(new ReQL_Byte[9]);
    const ReQL_Byte src27[] = "reduction";
    reql_string_init(var27.get(), buf27.get(), src27, 9);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 25);

    reql_object_add(var22.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair29(new ReQL_Pair_t[2]);
    reql_object_init(var29.get(), pair29.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf30(new ReQL_Byte[5]);
    const ReQL_Byte src30[] = "group";
    reql_string_init(var30.get(), buf30.get(), src30, 5);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_number_init(var32.get(), 2);

    reql_array_append(var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_number_init(var33.get(), 1);

    reql_array_append(var31.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf34(new ReQL_Byte[9]);
    const ReQL_Byte src34[] = "reduction";
    reql_string_init(var34.get(), buf34.get(), src34, 9);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_number_init(var35.get(), 25);

    reql_object_add(var29.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair36(new ReQL_Pair_t[2]);
    reql_object_init(var36.get(), pair36.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[5]);
    const ReQL_Byte src37[] = "group";
    reql_string_init(var37.get(), buf37.get(), src37, 5);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr38(new ReQL_Obj_t*[2]);
    reql_array_init(var38.get(), arr38.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_number_init(var39.get(), 2);

    reql_array_append(var38.get(), var39.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf40(new ReQL_Byte[3]);
    const ReQL_Byte src40[] = "two";
    reql_string_init(var40.get(), buf40.get(), src40, 3);

    reql_array_append(var38.get(), var40.get());

    reql_object_add(var36.get(), var37.get(), var38.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf41(new ReQL_Byte[9]);
    const ReQL_Byte src41[] = "reduction";
    reql_string_init(var41.get(), buf41.get(), src41, 9);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_number_init(var42.get(), 25);

    reql_object_add(var36.get(), var41.get(), var42.get());

    reql_array_append(var0.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair43(new ReQL_Pair_t[2]);
    reql_object_init(var43.get(), pair43.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf44(new ReQL_Byte[5]);
    const ReQL_Byte src44[] = "group";
    reql_string_init(var44.get(), buf44.get(), src44, 5);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr45(new ReQL_Obj_t*[2]);
    reql_array_init(var45.get(), arr45.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    reql_number_init(var46.get(), 3);

    reql_array_append(var45.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_number_init(var47.get(), 1);

    reql_array_append(var45.get(), var47.get());

    reql_object_add(var43.get(), var44.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf48(new ReQL_Byte[9]);
    const ReQL_Byte src48[] = "reduction";
    reql_string_init(var48.get(), buf48.get(), src48, 9);

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    reql_number_init(var49.get(), 25);

    reql_object_add(var43.get(), var48.get(), var49.get());

    reql_array_append(var0.get(), var43.get());

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair50(new ReQL_Pair_t[2]);
    reql_object_init(var50.get(), pair50.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf51(new ReQL_Byte[5]);
    const ReQL_Byte src51[] = "group";
    reql_string_init(var51.get(), buf51.get(), src51, 5);

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr52(new ReQL_Obj_t*[2]);
    reql_array_init(var52.get(), arr52.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_number_init(var53.get(), 3);

    reql_array_append(var52.get(), var53.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf54(new ReQL_Byte[3]);
    const ReQL_Byte src54[] = "two";
    reql_string_init(var54.get(), buf54.get(), src54, 3);

    reql_array_append(var52.get(), var54.get());

    reql_object_add(var50.get(), var51.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf55(new ReQL_Byte[9]);
    const ReQL_Byte src55[] = "reduction";
    reql_string_init(var55.get(), buf55.get(), src55, 9);

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    reql_number_init(var56.get(), 25);

    reql_object_add(var50.get(), var55.get(), var56.get());

    reql_array_append(var0.get(), var50.get());
  }

  SECTION("test94") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 100);
  }

  SECTION("test102") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test103") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test104") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test105") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test106") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test107") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[1]);
    const ReQL_Byte src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[2]);
    const ReQL_Byte src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), src3, 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }
}
