// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("reql Test basic geometry operators", "[reql][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[17]);
    const ReQL_Byte src0[] = "89011.26253835332";
    reql_string_init(var0.get(), buf0.get(), src0, 17);
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[18]);
    const ReQL_Byte src0[] = "110968.30443995494";
    reql_string_init(var0.get(), buf0.get(), src0, 18);
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[17]);
    const ReQL_Byte src0[] = "89011.26253835332";
    reql_string_init(var0.get(), buf0.get(), src0, 17);
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[19]);
    const ReQL_Byte src0[] = "0.01393875509649327";
    reql_string_init(var0.get(), buf0.get(), src0, 19);
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[1]);
    const ReQL_Byte src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), src0, 1);
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[18]);
    const ReQL_Byte src0[] = "40007862.917250897";
    reql_string_init(var0.get(), buf0.get(), src0, 18);
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[18]);
    const ReQL_Byte src0[] = "40007862.917250897";
    reql_string_init(var0.get(), buf0.get(), src0, 18);
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[1]);
    const ReQL_Byte src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), src0, 1);
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[1]);
    const ReQL_Byte src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), src0, 1);
  }

  SECTION("test17") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[17]);
    const ReQL_Byte src0[] = "492471.4990055255";
    reql_string_init(var0.get(), buf0.get(), src0, 17);
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[17]);
    const ReQL_Byte src0[] = "492471.4990055255";
    reql_string_init(var0.get(), buf0.get(), src0, 17);
  }

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[1]);
    const ReQL_Byte src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), src0, 1);
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[1]);
    const ReQL_Byte src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), src0, 1);
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test24") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[8]);
    const ReQL_Byte src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[11]);
    const ReQL_Byte src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), src3, 11);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[5]);
    reql_array_init(var5.get(), arr5.get(), 5);

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
    std::unique_ptr<ReQL_Obj_t*[]> arr9(new ReQL_Obj_t*[2]);
    reql_array_init(var9.get(), arr9.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1);

    reql_array_append(var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_array_append(var9.get(), var11.get());

    reql_array_append(var5.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr12(new ReQL_Obj_t*[2]);
    reql_array_init(var12.get(), arr12.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 1);

    reql_array_append(var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 1);

    reql_array_append(var12.get(), var14.get());

    reql_array_append(var5.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 0);

    reql_array_append(var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 1);

    reql_array_append(var15.get(), var17.get());

    reql_array_append(var5.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr18(new ReQL_Obj_t*[2]);
    reql_array_init(var18.get(), arr18.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 0);

    reql_array_append(var18.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 0);

    reql_array_append(var18.get(), var20.get());

    reql_array_append(var5.get(), var18.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[5]);
    reql_array_init(var21.get(), arr21.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[2]);
    reql_array_init(var22.get(), arr22.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 0.1);

    reql_array_append(var22.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 0.1);

    reql_array_append(var22.get(), var24.get());

    reql_array_append(var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr25(new ReQL_Obj_t*[2]);
    reql_array_init(var25.get(), arr25.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 0.9);

    reql_array_append(var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 0.1);

    reql_array_append(var25.get(), var27.get());

    reql_array_append(var21.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr28(new ReQL_Obj_t*[2]);
    reql_array_init(var28.get(), arr28.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_number_init(var29.get(), 0.9);

    reql_array_append(var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_number_init(var30.get(), 0.9);

    reql_array_append(var28.get(), var30.get());

    reql_array_append(var21.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_number_init(var32.get(), 0.1);

    reql_array_append(var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_number_init(var33.get(), 0.9);

    reql_array_append(var31.get(), var33.get());

    reql_array_append(var21.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr34(new ReQL_Obj_t*[2]);
    reql_array_init(var34.get(), arr34.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_number_init(var35.get(), 0.1);

    reql_array_append(var34.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_number_init(var36.get(), 0.1);

    reql_array_append(var34.get(), var36.get());

    reql_array_append(var21.get(), var34.get());

    reql_array_append(var4.get(), var21.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[4]);
    const ReQL_Byte src37[] = "type";
    reql_string_init(var37.get(), buf37.get(), src37, 4);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf38(new ReQL_Byte[7]);
    const ReQL_Byte src38[] = "Polygon";
    reql_string_init(var38.get(), buf38.get(), src38, 7);

    reql_object_add(var0.get(), var37.get(), var38.get());
  }

  SECTION("test25") {
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

  SECTION("test26") {
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

  SECTION("test27") {
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

  SECTION("test28") {
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

  SECTION("test29") {
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

  SECTION("test30") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[11]);
    const ReQL_Byte src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[8]);
    const ReQL_Byte src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[11]);
    const ReQL_Byte src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), src3, 11);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr5(new ReQL_Obj_t*[5]);
    reql_array_init(var5.get(), arr5.get(), 5);

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
    std::unique_ptr<ReQL_Obj_t*[]> arr9(new ReQL_Obj_t*[2]);
    reql_array_init(var9.get(), arr9.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1);

    reql_array_append(var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_array_append(var9.get(), var11.get());

    reql_array_append(var5.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr12(new ReQL_Obj_t*[2]);
    reql_array_init(var12.get(), arr12.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 1);

    reql_array_append(var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 1);

    reql_array_append(var12.get(), var14.get());

    reql_array_append(var5.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 0);

    reql_array_append(var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 1);

    reql_array_append(var15.get(), var17.get());

    reql_array_append(var5.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr18(new ReQL_Obj_t*[2]);
    reql_array_init(var18.get(), arr18.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 0);

    reql_array_append(var18.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 0);

    reql_array_append(var18.get(), var20.get());

    reql_array_append(var5.get(), var18.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[5]);
    reql_array_init(var21.get(), arr21.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[2]);
    reql_array_init(var22.get(), arr22.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 0);

    reql_array_append(var22.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 0);

    reql_array_append(var22.get(), var24.get());

    reql_array_append(var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr25(new ReQL_Obj_t*[2]);
    reql_array_init(var25.get(), arr25.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 0.1);

    reql_array_append(var25.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 0.9);

    reql_array_append(var25.get(), var27.get());

    reql_array_append(var21.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr28(new ReQL_Obj_t*[2]);
    reql_array_init(var28.get(), arr28.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_number_init(var29.get(), 0.9);

    reql_array_append(var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_number_init(var30.get(), 0.9);

    reql_array_append(var28.get(), var30.get());

    reql_array_append(var21.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_number_init(var32.get(), 0.9);

    reql_array_append(var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_number_init(var33.get(), 0.1);

    reql_array_append(var31.get(), var33.get());

    reql_array_append(var21.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr34(new ReQL_Obj_t*[2]);
    reql_array_init(var34.get(), arr34.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_number_init(var35.get(), 0);

    reql_array_append(var34.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_number_init(var36.get(), 0);

    reql_array_append(var34.get(), var36.get());

    reql_array_append(var21.get(), var34.get());

    reql_array_append(var4.get(), var21.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf37(new ReQL_Byte[4]);
    const ReQL_Byte src37[] = "type";
    reql_string_init(var37.get(), buf37.get(), src37, 4);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf38(new ReQL_Byte[7]);
    const ReQL_Byte src38[] = "Polygon";
    reql_string_init(var38.get(), buf38.get(), src38, 7);

    reql_object_add(var0.get(), var37.get(), var38.get());
  }

  SECTION("test31") {
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

  SECTION("test32") {
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
}
