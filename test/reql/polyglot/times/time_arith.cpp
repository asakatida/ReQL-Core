// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("reql Test basic time arithmetic 370", "[reql][ast]") {

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1000000000);
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), -1);
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), -1000000000);
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[4]);
    const ReQL_Byte src2[] = "func";
    reql_string_init(var2.get(), buf2.get(), src2, 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[3]);
    const ReQL_Byte src3[] = "rt1";
    reql_string_init(var3.get(), buf3.get(), src3, 3);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[4]);
    const ReQL_Byte src5[] = "func";
    reql_string_init(var5.get(), buf5.get(), src5, 4);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[3]);
    const ReQL_Byte src6[] = "rt2";
    reql_string_init(var6.get(), buf6.get(), src6, 3);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[4]);
    const ReQL_Byte src8[] = "func";
    reql_string_init(var8.get(), buf8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[3]);
    const ReQL_Byte src9[] = "rt3";
    reql_string_init(var9.get(), buf9.get(), src9, 3);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[4]);
    const ReQL_Byte src11[] = "func";
    reql_string_init(var11.get(), buf11.get(), src11, 4);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[3]);
    const ReQL_Byte src12[] = "rt4";
    reql_string_init(var12.get(), buf12.get(), src12, 3);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var10.get());
  }

  SECTION("test17") {
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

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf2(new ReQL_Byte[4]);
    const ReQL_Byte src2[] = "func";
    reql_string_init(var2.get(), buf2.get(), src2, 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[3]);
    const ReQL_Byte src3[] = "rt1";
    reql_string_init(var3.get(), buf3.get(), src3, 3);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf5(new ReQL_Byte[4]);
    const ReQL_Byte src5[] = "func";
    reql_string_init(var5.get(), buf5.get(), src5, 4);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[3]);
    const ReQL_Byte src6[] = "rt2";
    reql_string_init(var6.get(), buf6.get(), src6, 3);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[4]);
    const ReQL_Byte src8[] = "func";
    reql_string_init(var8.get(), buf8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf9(new ReQL_Byte[3]);
    const ReQL_Byte src9[] = "rt3";
    reql_string_init(var9.get(), buf9.get(), src9, 3);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf11(new ReQL_Byte[4]);
    const ReQL_Byte src11[] = "func";
    reql_string_init(var11.get(), buf11.get(), src11, 4);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[3]);
    const ReQL_Byte src12[] = "rt4";
    reql_string_init(var12.get(), buf12.get(), src12, 3);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var10.get());
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr1(new ReQL_Obj_t*[4]);
    reql_array_init(var1.get(), arr1.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[6]);
    reql_array_init(var2.get(), arr2.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_bool_init(var3.get(), 0);

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_bool_init(var4.get(), 1);

    reql_array_append(var2.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 1);

    reql_array_append(var2.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_bool_init(var6.get(), 0);

    reql_array_append(var2.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_bool_init(var7.get(), 1);

    reql_array_append(var2.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_bool_init(var8.get(), 0);

    reql_array_append(var2.get(), var8.get());

    reql_array_append(var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr9(new ReQL_Obj_t*[6]);
    reql_array_init(var9.get(), arr9.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_bool_init(var10.get(), 1);

    reql_array_append(var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_bool_init(var11.get(), 1);

    reql_array_append(var9.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_bool_init(var12.get(), 0);

    reql_array_append(var9.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_bool_init(var13.get(), 1);

    reql_array_append(var9.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_bool_init(var14.get(), 0);

    reql_array_append(var9.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_bool_init(var15.get(), 0);

    reql_array_append(var9.get(), var15.get());

    reql_array_append(var1.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr16(new ReQL_Obj_t*[6]);
    reql_array_init(var16.get(), arr16.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_bool_init(var17.get(), 1);

    reql_array_append(var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_bool_init(var18.get(), 1);

    reql_array_append(var16.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_bool_init(var19.get(), 0);

    reql_array_append(var16.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_bool_init(var20.get(), 1);

    reql_array_append(var16.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_bool_init(var21.get(), 0);

    reql_array_append(var16.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_bool_init(var22.get(), 0);

    reql_array_append(var16.get(), var22.get());

    reql_array_append(var1.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr23(new ReQL_Obj_t*[6]);
    reql_array_init(var23.get(), arr23.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_bool_init(var24.get(), 1);

    reql_array_append(var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_bool_init(var25.get(), 1);

    reql_array_append(var23.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_bool_init(var26.get(), 0);

    reql_array_append(var23.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_bool_init(var27.get(), 1);

    reql_array_append(var23.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_bool_init(var28.get(), 0);

    reql_array_append(var23.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_bool_init(var29.get(), 0);

    reql_array_append(var23.get(), var29.get());

    reql_array_append(var1.get(), var23.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr30(new ReQL_Obj_t*[4]);
    reql_array_init(var30.get(), arr30.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr31(new ReQL_Obj_t*[6]);
    reql_array_init(var31.get(), arr31.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_bool_init(var32.get(), 0);

    reql_array_append(var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_bool_init(var33.get(), 0);

    reql_array_append(var31.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_bool_init(var34.get(), 0);

    reql_array_append(var31.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_bool_init(var35.get(), 1);

    reql_array_append(var31.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_bool_init(var36.get(), 1);

    reql_array_append(var31.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_bool_init(var37.get(), 1);

    reql_array_append(var31.get(), var37.get());

    reql_array_append(var30.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr38(new ReQL_Obj_t*[6]);
    reql_array_init(var38.get(), arr38.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_bool_init(var39.get(), 0);

    reql_array_append(var38.get(), var39.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    reql_bool_init(var40.get(), 1);

    reql_array_append(var38.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    reql_bool_init(var41.get(), 1);

    reql_array_append(var38.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_bool_init(var42.get(), 0);

    reql_array_append(var38.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    reql_bool_init(var43.get(), 1);

    reql_array_append(var38.get(), var43.get());

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    reql_bool_init(var44.get(), 0);

    reql_array_append(var38.get(), var44.get());

    reql_array_append(var30.get(), var38.get());

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr45(new ReQL_Obj_t*[6]);
    reql_array_init(var45.get(), arr45.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    reql_bool_init(var46.get(), 1);

    reql_array_append(var45.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_bool_init(var47.get(), 1);

    reql_array_append(var45.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_bool_init(var48.get(), 0);

    reql_array_append(var45.get(), var48.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    reql_bool_init(var49.get(), 1);

    reql_array_append(var45.get(), var49.get());

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    reql_bool_init(var50.get(), 0);

    reql_array_append(var45.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    reql_bool_init(var51.get(), 0);

    reql_array_append(var45.get(), var51.get());

    reql_array_append(var30.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr52(new ReQL_Obj_t*[6]);
    reql_array_init(var52.get(), arr52.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_bool_init(var53.get(), 1);

    reql_array_append(var52.get(), var53.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    reql_bool_init(var54.get(), 1);

    reql_array_append(var52.get(), var54.get());

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    reql_bool_init(var55.get(), 0);

    reql_array_append(var52.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    reql_bool_init(var56.get(), 1);

    reql_array_append(var52.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_bool_init(var57.get(), 0);

    reql_array_append(var52.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_bool_init(var58.get(), 0);

    reql_array_append(var52.get(), var58.get());

    reql_array_append(var30.get(), var52.get());

    reql_array_append(var0.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr59(new ReQL_Obj_t*[4]);
    reql_array_init(var59.get(), arr59.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr60(new ReQL_Obj_t*[6]);
    reql_array_init(var60.get(), arr60.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    reql_bool_init(var61.get(), 0);

    reql_array_append(var60.get(), var61.get());

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    reql_bool_init(var62.get(), 0);

    reql_array_append(var60.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_bool_init(var63.get(), 0);

    reql_array_append(var60.get(), var63.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    reql_bool_init(var64.get(), 1);

    reql_array_append(var60.get(), var64.get());

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    reql_bool_init(var65.get(), 1);

    reql_array_append(var60.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    reql_bool_init(var66.get(), 1);

    reql_array_append(var60.get(), var66.get());

    reql_array_append(var59.get(), var60.get());

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr67(new ReQL_Obj_t*[6]);
    reql_array_init(var67.get(), arr67.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    reql_bool_init(var68.get(), 0);

    reql_array_append(var67.get(), var68.get());

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    reql_bool_init(var69.get(), 0);

    reql_array_append(var67.get(), var69.get());

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    reql_bool_init(var70.get(), 0);

    reql_array_append(var67.get(), var70.get());

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    reql_bool_init(var71.get(), 1);

    reql_array_append(var67.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    reql_bool_init(var72.get(), 1);

    reql_array_append(var67.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_bool_init(var73.get(), 1);

    reql_array_append(var67.get(), var73.get());

    reql_array_append(var59.get(), var67.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr74(new ReQL_Obj_t*[6]);
    reql_array_init(var74.get(), arr74.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    reql_bool_init(var75.get(), 0);

    reql_array_append(var74.get(), var75.get());

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    reql_bool_init(var76.get(), 1);

    reql_array_append(var74.get(), var76.get());

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    reql_bool_init(var77.get(), 1);

    reql_array_append(var74.get(), var77.get());

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    reql_bool_init(var78.get(), 0);

    reql_array_append(var74.get(), var78.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    reql_bool_init(var79.get(), 1);

    reql_array_append(var74.get(), var79.get());

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    reql_bool_init(var80.get(), 0);

    reql_array_append(var74.get(), var80.get());

    reql_array_append(var59.get(), var74.get());

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr81(new ReQL_Obj_t*[6]);
    reql_array_init(var81.get(), arr81.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_bool_init(var82.get(), 1);

    reql_array_append(var81.get(), var82.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    reql_bool_init(var83.get(), 1);

    reql_array_append(var81.get(), var83.get());

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    reql_bool_init(var84.get(), 0);

    reql_array_append(var81.get(), var84.get());

    std::unique_ptr<ReQL_Obj_t> var85(new ReQL_Obj_t);
    reql_bool_init(var85.get(), 1);

    reql_array_append(var81.get(), var85.get());

    std::unique_ptr<ReQL_Obj_t> var86(new ReQL_Obj_t);
    reql_bool_init(var86.get(), 0);

    reql_array_append(var81.get(), var86.get());

    std::unique_ptr<ReQL_Obj_t> var87(new ReQL_Obj_t);
    reql_bool_init(var87.get(), 0);

    reql_array_append(var81.get(), var87.get());

    reql_array_append(var59.get(), var81.get());

    reql_array_append(var0.get(), var59.get());

    std::unique_ptr<ReQL_Obj_t> var88(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr88(new ReQL_Obj_t*[4]);
    reql_array_init(var88.get(), arr88.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var89(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr89(new ReQL_Obj_t*[6]);
    reql_array_init(var89.get(), arr89.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var90(new ReQL_Obj_t);
    reql_bool_init(var90.get(), 0);

    reql_array_append(var89.get(), var90.get());

    std::unique_ptr<ReQL_Obj_t> var91(new ReQL_Obj_t);
    reql_bool_init(var91.get(), 0);

    reql_array_append(var89.get(), var91.get());

    std::unique_ptr<ReQL_Obj_t> var92(new ReQL_Obj_t);
    reql_bool_init(var92.get(), 0);

    reql_array_append(var89.get(), var92.get());

    std::unique_ptr<ReQL_Obj_t> var93(new ReQL_Obj_t);
    reql_bool_init(var93.get(), 1);

    reql_array_append(var89.get(), var93.get());

    std::unique_ptr<ReQL_Obj_t> var94(new ReQL_Obj_t);
    reql_bool_init(var94.get(), 1);

    reql_array_append(var89.get(), var94.get());

    std::unique_ptr<ReQL_Obj_t> var95(new ReQL_Obj_t);
    reql_bool_init(var95.get(), 1);

    reql_array_append(var89.get(), var95.get());

    reql_array_append(var88.get(), var89.get());

    std::unique_ptr<ReQL_Obj_t> var96(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr96(new ReQL_Obj_t*[6]);
    reql_array_init(var96.get(), arr96.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var97(new ReQL_Obj_t);
    reql_bool_init(var97.get(), 0);

    reql_array_append(var96.get(), var97.get());

    std::unique_ptr<ReQL_Obj_t> var98(new ReQL_Obj_t);
    reql_bool_init(var98.get(), 0);

    reql_array_append(var96.get(), var98.get());

    std::unique_ptr<ReQL_Obj_t> var99(new ReQL_Obj_t);
    reql_bool_init(var99.get(), 0);

    reql_array_append(var96.get(), var99.get());

    std::unique_ptr<ReQL_Obj_t> var100(new ReQL_Obj_t);
    reql_bool_init(var100.get(), 1);

    reql_array_append(var96.get(), var100.get());

    std::unique_ptr<ReQL_Obj_t> var101(new ReQL_Obj_t);
    reql_bool_init(var101.get(), 1);

    reql_array_append(var96.get(), var101.get());

    std::unique_ptr<ReQL_Obj_t> var102(new ReQL_Obj_t);
    reql_bool_init(var102.get(), 1);

    reql_array_append(var96.get(), var102.get());

    reql_array_append(var88.get(), var96.get());

    std::unique_ptr<ReQL_Obj_t> var103(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr103(new ReQL_Obj_t*[6]);
    reql_array_init(var103.get(), arr103.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var104(new ReQL_Obj_t);
    reql_bool_init(var104.get(), 0);

    reql_array_append(var103.get(), var104.get());

    std::unique_ptr<ReQL_Obj_t> var105(new ReQL_Obj_t);
    reql_bool_init(var105.get(), 0);

    reql_array_append(var103.get(), var105.get());

    std::unique_ptr<ReQL_Obj_t> var106(new ReQL_Obj_t);
    reql_bool_init(var106.get(), 0);

    reql_array_append(var103.get(), var106.get());

    std::unique_ptr<ReQL_Obj_t> var107(new ReQL_Obj_t);
    reql_bool_init(var107.get(), 1);

    reql_array_append(var103.get(), var107.get());

    std::unique_ptr<ReQL_Obj_t> var108(new ReQL_Obj_t);
    reql_bool_init(var108.get(), 1);

    reql_array_append(var103.get(), var108.get());

    std::unique_ptr<ReQL_Obj_t> var109(new ReQL_Obj_t);
    reql_bool_init(var109.get(), 1);

    reql_array_append(var103.get(), var109.get());

    reql_array_append(var88.get(), var103.get());

    std::unique_ptr<ReQL_Obj_t> var110(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr110(new ReQL_Obj_t*[6]);
    reql_array_init(var110.get(), arr110.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var111(new ReQL_Obj_t);
    reql_bool_init(var111.get(), 0);

    reql_array_append(var110.get(), var111.get());

    std::unique_ptr<ReQL_Obj_t> var112(new ReQL_Obj_t);
    reql_bool_init(var112.get(), 1);

    reql_array_append(var110.get(), var112.get());

    std::unique_ptr<ReQL_Obj_t> var113(new ReQL_Obj_t);
    reql_bool_init(var113.get(), 1);

    reql_array_append(var110.get(), var113.get());

    std::unique_ptr<ReQL_Obj_t> var114(new ReQL_Obj_t);
    reql_bool_init(var114.get(), 0);

    reql_array_append(var110.get(), var114.get());

    std::unique_ptr<ReQL_Obj_t> var115(new ReQL_Obj_t);
    reql_bool_init(var115.get(), 1);

    reql_array_append(var110.get(), var115.get());

    std::unique_ptr<ReQL_Obj_t> var116(new ReQL_Obj_t);
    reql_bool_init(var116.get(), 0);

    reql_array_append(var110.get(), var116.get());

    reql_array_append(var88.get(), var110.get());

    reql_array_append(var0.get(), var88.get());
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[8]);
    reql_array_init(var0.get(), arr0.get(), 8);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[6]);
    reql_array_init(var2.get(), arr2.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_bool_init(var3.get(), 1);

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_bool_init(var4.get(), 1);

    reql_array_append(var2.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 0);

    reql_array_append(var2.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_bool_init(var6.get(), 1);

    reql_array_append(var2.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_bool_init(var7.get(), 0);

    reql_array_append(var2.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_bool_init(var8.get(), 0);

    reql_array_append(var2.get(), var8.get());

    reql_array_append(var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr9(new ReQL_Obj_t*[6]);
    reql_array_init(var9.get(), arr9.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_bool_init(var10.get(), 0);

    reql_array_append(var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_bool_init(var11.get(), 0);

    reql_array_append(var9.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_bool_init(var12.get(), 0);

    reql_array_append(var9.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_bool_init(var13.get(), 1);

    reql_array_append(var9.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_bool_init(var14.get(), 1);

    reql_array_append(var9.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_bool_init(var15.get(), 1);

    reql_array_append(var9.get(), var15.get());

    reql_array_append(var1.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr16(new ReQL_Obj_t*[2]);
    reql_array_init(var16.get(), arr16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[6]);
    reql_array_init(var17.get(), arr17.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_bool_init(var18.get(), 1);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_bool_init(var19.get(), 1);

    reql_array_append(var17.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_bool_init(var20.get(), 0);

    reql_array_append(var17.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_bool_init(var21.get(), 1);

    reql_array_append(var17.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_bool_init(var22.get(), 0);

    reql_array_append(var17.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_bool_init(var23.get(), 0);

    reql_array_append(var17.get(), var23.get());

    reql_array_append(var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr24(new ReQL_Obj_t*[6]);
    reql_array_init(var24.get(), arr24.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_bool_init(var25.get(), 0);

    reql_array_append(var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_bool_init(var26.get(), 0);

    reql_array_append(var24.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_bool_init(var27.get(), 0);

    reql_array_append(var24.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_bool_init(var28.get(), 1);

    reql_array_append(var24.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_bool_init(var29.get(), 1);

    reql_array_append(var24.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_bool_init(var30.get(), 1);

    reql_array_append(var24.get(), var30.get());

    reql_array_append(var16.get(), var24.get());

    reql_array_append(var0.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr32(new ReQL_Obj_t*[6]);
    reql_array_init(var32.get(), arr32.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    reql_bool_init(var33.get(), 1);

    reql_array_append(var32.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_bool_init(var34.get(), 1);

    reql_array_append(var32.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_bool_init(var35.get(), 0);

    reql_array_append(var32.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_bool_init(var36.get(), 1);

    reql_array_append(var32.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_bool_init(var37.get(), 0);

    reql_array_append(var32.get(), var37.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    reql_bool_init(var38.get(), 0);

    reql_array_append(var32.get(), var38.get());

    reql_array_append(var31.get(), var32.get());

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr39(new ReQL_Obj_t*[6]);
    reql_array_init(var39.get(), arr39.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    reql_bool_init(var40.get(), 0);

    reql_array_append(var39.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    reql_bool_init(var41.get(), 0);

    reql_array_append(var39.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_bool_init(var42.get(), 0);

    reql_array_append(var39.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    reql_bool_init(var43.get(), 1);

    reql_array_append(var39.get(), var43.get());

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    reql_bool_init(var44.get(), 1);

    reql_array_append(var39.get(), var44.get());

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    reql_bool_init(var45.get(), 1);

    reql_array_append(var39.get(), var45.get());

    reql_array_append(var31.get(), var39.get());

    reql_array_append(var0.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr46(new ReQL_Obj_t*[2]);
    reql_array_init(var46.get(), arr46.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr47(new ReQL_Obj_t*[6]);
    reql_array_init(var47.get(), arr47.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_bool_init(var48.get(), 1);

    reql_array_append(var47.get(), var48.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    reql_bool_init(var49.get(), 1);

    reql_array_append(var47.get(), var49.get());

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    reql_bool_init(var50.get(), 0);

    reql_array_append(var47.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    reql_bool_init(var51.get(), 1);

    reql_array_append(var47.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    reql_bool_init(var52.get(), 0);

    reql_array_append(var47.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_bool_init(var53.get(), 0);

    reql_array_append(var47.get(), var53.get());

    reql_array_append(var46.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr54(new ReQL_Obj_t*[6]);
    reql_array_init(var54.get(), arr54.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    reql_bool_init(var55.get(), 0);

    reql_array_append(var54.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    reql_bool_init(var56.get(), 0);

    reql_array_append(var54.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_bool_init(var57.get(), 0);

    reql_array_append(var54.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_bool_init(var58.get(), 1);

    reql_array_append(var54.get(), var58.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    reql_bool_init(var59.get(), 1);

    reql_array_append(var54.get(), var59.get());

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    reql_bool_init(var60.get(), 1);

    reql_array_append(var54.get(), var60.get());

    reql_array_append(var46.get(), var54.get());

    reql_array_append(var0.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr61(new ReQL_Obj_t*[2]);
    reql_array_init(var61.get(), arr61.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr62(new ReQL_Obj_t*[6]);
    reql_array_init(var62.get(), arr62.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_bool_init(var63.get(), 0);

    reql_array_append(var62.get(), var63.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    reql_bool_init(var64.get(), 0);

    reql_array_append(var62.get(), var64.get());

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    reql_bool_init(var65.get(), 0);

    reql_array_append(var62.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    reql_bool_init(var66.get(), 1);

    reql_array_append(var62.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    reql_bool_init(var67.get(), 1);

    reql_array_append(var62.get(), var67.get());

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    reql_bool_init(var68.get(), 1);

    reql_array_append(var62.get(), var68.get());

    reql_array_append(var61.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr69(new ReQL_Obj_t*[6]);
    reql_array_init(var69.get(), arr69.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    reql_bool_init(var70.get(), 1);

    reql_array_append(var69.get(), var70.get());

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    reql_bool_init(var71.get(), 1);

    reql_array_append(var69.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    reql_bool_init(var72.get(), 0);

    reql_array_append(var69.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_bool_init(var73.get(), 1);

    reql_array_append(var69.get(), var73.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    reql_bool_init(var74.get(), 0);

    reql_array_append(var69.get(), var74.get());

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    reql_bool_init(var75.get(), 0);

    reql_array_append(var69.get(), var75.get());

    reql_array_append(var61.get(), var69.get());

    reql_array_append(var0.get(), var61.get());

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr76(new ReQL_Obj_t*[2]);
    reql_array_init(var76.get(), arr76.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr77(new ReQL_Obj_t*[6]);
    reql_array_init(var77.get(), arr77.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    reql_bool_init(var78.get(), 1);

    reql_array_append(var77.get(), var78.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    reql_bool_init(var79.get(), 1);

    reql_array_append(var77.get(), var79.get());

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    reql_bool_init(var80.get(), 0);

    reql_array_append(var77.get(), var80.get());

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    reql_bool_init(var81.get(), 1);

    reql_array_append(var77.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_bool_init(var82.get(), 0);

    reql_array_append(var77.get(), var82.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    reql_bool_init(var83.get(), 0);

    reql_array_append(var77.get(), var83.get());

    reql_array_append(var76.get(), var77.get());

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr84(new ReQL_Obj_t*[6]);
    reql_array_init(var84.get(), arr84.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var85(new ReQL_Obj_t);
    reql_bool_init(var85.get(), 0);

    reql_array_append(var84.get(), var85.get());

    std::unique_ptr<ReQL_Obj_t> var86(new ReQL_Obj_t);
    reql_bool_init(var86.get(), 0);

    reql_array_append(var84.get(), var86.get());

    std::unique_ptr<ReQL_Obj_t> var87(new ReQL_Obj_t);
    reql_bool_init(var87.get(), 0);

    reql_array_append(var84.get(), var87.get());

    std::unique_ptr<ReQL_Obj_t> var88(new ReQL_Obj_t);
    reql_bool_init(var88.get(), 1);

    reql_array_append(var84.get(), var88.get());

    std::unique_ptr<ReQL_Obj_t> var89(new ReQL_Obj_t);
    reql_bool_init(var89.get(), 1);

    reql_array_append(var84.get(), var89.get());

    std::unique_ptr<ReQL_Obj_t> var90(new ReQL_Obj_t);
    reql_bool_init(var90.get(), 1);

    reql_array_append(var84.get(), var90.get());

    reql_array_append(var76.get(), var84.get());

    reql_array_append(var0.get(), var76.get());

    std::unique_ptr<ReQL_Obj_t> var91(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr91(new ReQL_Obj_t*[2]);
    reql_array_init(var91.get(), arr91.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var92(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr92(new ReQL_Obj_t*[6]);
    reql_array_init(var92.get(), arr92.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var93(new ReQL_Obj_t);
    reql_bool_init(var93.get(), 1);

    reql_array_append(var92.get(), var93.get());

    std::unique_ptr<ReQL_Obj_t> var94(new ReQL_Obj_t);
    reql_bool_init(var94.get(), 1);

    reql_array_append(var92.get(), var94.get());

    std::unique_ptr<ReQL_Obj_t> var95(new ReQL_Obj_t);
    reql_bool_init(var95.get(), 0);

    reql_array_append(var92.get(), var95.get());

    std::unique_ptr<ReQL_Obj_t> var96(new ReQL_Obj_t);
    reql_bool_init(var96.get(), 1);

    reql_array_append(var92.get(), var96.get());

    std::unique_ptr<ReQL_Obj_t> var97(new ReQL_Obj_t);
    reql_bool_init(var97.get(), 0);

    reql_array_append(var92.get(), var97.get());

    std::unique_ptr<ReQL_Obj_t> var98(new ReQL_Obj_t);
    reql_bool_init(var98.get(), 0);

    reql_array_append(var92.get(), var98.get());

    reql_array_append(var91.get(), var92.get());

    std::unique_ptr<ReQL_Obj_t> var99(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr99(new ReQL_Obj_t*[6]);
    reql_array_init(var99.get(), arr99.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var100(new ReQL_Obj_t);
    reql_bool_init(var100.get(), 0);

    reql_array_append(var99.get(), var100.get());

    std::unique_ptr<ReQL_Obj_t> var101(new ReQL_Obj_t);
    reql_bool_init(var101.get(), 0);

    reql_array_append(var99.get(), var101.get());

    std::unique_ptr<ReQL_Obj_t> var102(new ReQL_Obj_t);
    reql_bool_init(var102.get(), 0);

    reql_array_append(var99.get(), var102.get());

    std::unique_ptr<ReQL_Obj_t> var103(new ReQL_Obj_t);
    reql_bool_init(var103.get(), 1);

    reql_array_append(var99.get(), var103.get());

    std::unique_ptr<ReQL_Obj_t> var104(new ReQL_Obj_t);
    reql_bool_init(var104.get(), 1);

    reql_array_append(var99.get(), var104.get());

    std::unique_ptr<ReQL_Obj_t> var105(new ReQL_Obj_t);
    reql_bool_init(var105.get(), 1);

    reql_array_append(var99.get(), var105.get());

    reql_array_append(var91.get(), var99.get());

    reql_array_append(var0.get(), var91.get());

    std::unique_ptr<ReQL_Obj_t> var106(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr106(new ReQL_Obj_t*[2]);
    reql_array_init(var106.get(), arr106.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var107(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr107(new ReQL_Obj_t*[6]);
    reql_array_init(var107.get(), arr107.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var108(new ReQL_Obj_t);
    reql_bool_init(var108.get(), 1);

    reql_array_append(var107.get(), var108.get());

    std::unique_ptr<ReQL_Obj_t> var109(new ReQL_Obj_t);
    reql_bool_init(var109.get(), 1);

    reql_array_append(var107.get(), var109.get());

    std::unique_ptr<ReQL_Obj_t> var110(new ReQL_Obj_t);
    reql_bool_init(var110.get(), 0);

    reql_array_append(var107.get(), var110.get());

    std::unique_ptr<ReQL_Obj_t> var111(new ReQL_Obj_t);
    reql_bool_init(var111.get(), 1);

    reql_array_append(var107.get(), var111.get());

    std::unique_ptr<ReQL_Obj_t> var112(new ReQL_Obj_t);
    reql_bool_init(var112.get(), 0);

    reql_array_append(var107.get(), var112.get());

    std::unique_ptr<ReQL_Obj_t> var113(new ReQL_Obj_t);
    reql_bool_init(var113.get(), 0);

    reql_array_append(var107.get(), var113.get());

    reql_array_append(var106.get(), var107.get());

    std::unique_ptr<ReQL_Obj_t> var114(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr114(new ReQL_Obj_t*[6]);
    reql_array_init(var114.get(), arr114.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var115(new ReQL_Obj_t);
    reql_bool_init(var115.get(), 0);

    reql_array_append(var114.get(), var115.get());

    std::unique_ptr<ReQL_Obj_t> var116(new ReQL_Obj_t);
    reql_bool_init(var116.get(), 0);

    reql_array_append(var114.get(), var116.get());

    std::unique_ptr<ReQL_Obj_t> var117(new ReQL_Obj_t);
    reql_bool_init(var117.get(), 0);

    reql_array_append(var114.get(), var117.get());

    std::unique_ptr<ReQL_Obj_t> var118(new ReQL_Obj_t);
    reql_bool_init(var118.get(), 1);

    reql_array_append(var114.get(), var118.get());

    std::unique_ptr<ReQL_Obj_t> var119(new ReQL_Obj_t);
    reql_bool_init(var119.get(), 1);

    reql_array_append(var114.get(), var119.get());

    std::unique_ptr<ReQL_Obj_t> var120(new ReQL_Obj_t);
    reql_bool_init(var120.get(), 1);

    reql_array_append(var114.get(), var120.get());

    reql_array_append(var106.get(), var114.get());

    reql_array_append(var0.get(), var106.get());
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr1(new ReQL_Obj_t*[4]);
    reql_array_init(var1.get(), arr1.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[4]);
    reql_array_init(var2.get(), arr2.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_bool_init(var3.get(), 0);

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_bool_init(var4.get(), 1);

    reql_array_append(var2.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 1);

    reql_array_append(var2.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_bool_init(var6.get(), 1);

    reql_array_append(var2.get(), var6.get());

    reql_array_append(var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_bool_init(var8.get(), 0);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_bool_init(var9.get(), 0);

    reql_array_append(var7.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_bool_init(var10.get(), 1);

    reql_array_append(var7.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_bool_init(var11.get(), 1);

    reql_array_append(var7.get(), var11.get());

    reql_array_append(var1.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr12(new ReQL_Obj_t*[4]);
    reql_array_init(var12.get(), arr12.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_bool_init(var13.get(), 0);

    reql_array_append(var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_bool_init(var14.get(), 0);

    reql_array_append(var12.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_bool_init(var15.get(), 0);

    reql_array_append(var12.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_bool_init(var16.get(), 1);

    reql_array_append(var12.get(), var16.get());

    reql_array_append(var1.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[4]);
    reql_array_init(var17.get(), arr17.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_bool_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_bool_init(var19.get(), 0);

    reql_array_append(var17.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_bool_init(var20.get(), 0);

    reql_array_append(var17.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_bool_init(var21.get(), 0);

    reql_array_append(var17.get(), var21.get());

    reql_array_append(var1.get(), var17.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[4]);
    reql_array_init(var22.get(), arr22.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr23(new ReQL_Obj_t*[4]);
    reql_array_init(var23.get(), arr23.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_bool_init(var24.get(), 0);

    reql_array_append(var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_bool_init(var25.get(), 0);

    reql_array_append(var23.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_bool_init(var26.get(), 0);

    reql_array_append(var23.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_bool_init(var27.get(), 0);

    reql_array_append(var23.get(), var27.get());

    reql_array_append(var22.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr28(new ReQL_Obj_t*[4]);
    reql_array_init(var28.get(), arr28.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_bool_init(var29.get(), 0);

    reql_array_append(var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_bool_init(var30.get(), 0);

    reql_array_append(var28.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    reql_bool_init(var31.get(), 1);

    reql_array_append(var28.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_bool_init(var32.get(), 1);

    reql_array_append(var28.get(), var32.get());

    reql_array_append(var22.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr33(new ReQL_Obj_t*[4]);
    reql_array_init(var33.get(), arr33.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_bool_init(var34.get(), 0);

    reql_array_append(var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_bool_init(var35.get(), 0);

    reql_array_append(var33.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_bool_init(var36.get(), 0);

    reql_array_append(var33.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_bool_init(var37.get(), 1);

    reql_array_append(var33.get(), var37.get());

    reql_array_append(var22.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr38(new ReQL_Obj_t*[4]);
    reql_array_init(var38.get(), arr38.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_bool_init(var39.get(), 0);

    reql_array_append(var38.get(), var39.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    reql_bool_init(var40.get(), 0);

    reql_array_append(var38.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    reql_bool_init(var41.get(), 0);

    reql_array_append(var38.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_bool_init(var42.get(), 0);

    reql_array_append(var38.get(), var42.get());

    reql_array_append(var22.get(), var38.get());

    reql_array_append(var0.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr43(new ReQL_Obj_t*[4]);
    reql_array_init(var43.get(), arr43.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr44(new ReQL_Obj_t*[4]);
    reql_array_init(var44.get(), arr44.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    reql_bool_init(var45.get(), 0);

    reql_array_append(var44.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    reql_bool_init(var46.get(), 0);

    reql_array_append(var44.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_bool_init(var47.get(), 0);

    reql_array_append(var44.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_bool_init(var48.get(), 0);

    reql_array_append(var44.get(), var48.get());

    reql_array_append(var43.get(), var44.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr49(new ReQL_Obj_t*[4]);
    reql_array_init(var49.get(), arr49.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    reql_bool_init(var50.get(), 0);

    reql_array_append(var49.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    reql_bool_init(var51.get(), 0);

    reql_array_append(var49.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    reql_bool_init(var52.get(), 0);

    reql_array_append(var49.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_bool_init(var53.get(), 0);

    reql_array_append(var49.get(), var53.get());

    reql_array_append(var43.get(), var49.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr54(new ReQL_Obj_t*[4]);
    reql_array_init(var54.get(), arr54.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    reql_bool_init(var55.get(), 0);

    reql_array_append(var54.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    reql_bool_init(var56.get(), 0);

    reql_array_append(var54.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_bool_init(var57.get(), 0);

    reql_array_append(var54.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_bool_init(var58.get(), 1);

    reql_array_append(var54.get(), var58.get());

    reql_array_append(var43.get(), var54.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr59(new ReQL_Obj_t*[4]);
    reql_array_init(var59.get(), arr59.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    reql_bool_init(var60.get(), 0);

    reql_array_append(var59.get(), var60.get());

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    reql_bool_init(var61.get(), 0);

    reql_array_append(var59.get(), var61.get());

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    reql_bool_init(var62.get(), 0);

    reql_array_append(var59.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_bool_init(var63.get(), 0);

    reql_array_append(var59.get(), var63.get());

    reql_array_append(var43.get(), var59.get());

    reql_array_append(var0.get(), var43.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr64(new ReQL_Obj_t*[4]);
    reql_array_init(var64.get(), arr64.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr65(new ReQL_Obj_t*[4]);
    reql_array_init(var65.get(), arr65.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    reql_bool_init(var66.get(), 0);

    reql_array_append(var65.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    reql_bool_init(var67.get(), 0);

    reql_array_append(var65.get(), var67.get());

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    reql_bool_init(var68.get(), 0);

    reql_array_append(var65.get(), var68.get());

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    reql_bool_init(var69.get(), 0);

    reql_array_append(var65.get(), var69.get());

    reql_array_append(var64.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr70(new ReQL_Obj_t*[4]);
    reql_array_init(var70.get(), arr70.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    reql_bool_init(var71.get(), 0);

    reql_array_append(var70.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    reql_bool_init(var72.get(), 0);

    reql_array_append(var70.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_bool_init(var73.get(), 0);

    reql_array_append(var70.get(), var73.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    reql_bool_init(var74.get(), 0);

    reql_array_append(var70.get(), var74.get());

    reql_array_append(var64.get(), var70.get());

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr75(new ReQL_Obj_t*[4]);
    reql_array_init(var75.get(), arr75.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    reql_bool_init(var76.get(), 0);

    reql_array_append(var75.get(), var76.get());

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    reql_bool_init(var77.get(), 0);

    reql_array_append(var75.get(), var77.get());

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    reql_bool_init(var78.get(), 0);

    reql_array_append(var75.get(), var78.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    reql_bool_init(var79.get(), 0);

    reql_array_append(var75.get(), var79.get());

    reql_array_append(var64.get(), var75.get());

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr80(new ReQL_Obj_t*[4]);
    reql_array_init(var80.get(), arr80.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    reql_bool_init(var81.get(), 0);

    reql_array_append(var80.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_bool_init(var82.get(), 0);

    reql_array_append(var80.get(), var82.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    reql_bool_init(var83.get(), 0);

    reql_array_append(var80.get(), var83.get());

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    reql_bool_init(var84.get(), 0);

    reql_array_append(var80.get(), var84.get());

    reql_array_append(var64.get(), var80.get());

    reql_array_append(var0.get(), var64.get());
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr1(new ReQL_Obj_t*[4]);
    reql_array_init(var1.get(), arr1.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[4]);
    reql_array_init(var2.get(), arr2.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_bool_init(var3.get(), 0);

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_bool_init(var4.get(), 0);

    reql_array_append(var2.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 0);

    reql_array_append(var2.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_bool_init(var6.get(), 0);

    reql_array_append(var2.get(), var6.get());

    reql_array_append(var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_bool_init(var8.get(), 0);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_bool_init(var9.get(), 0);

    reql_array_append(var7.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_bool_init(var10.get(), 1);

    reql_array_append(var7.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_bool_init(var11.get(), 1);

    reql_array_append(var7.get(), var11.get());

    reql_array_append(var1.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr12(new ReQL_Obj_t*[4]);
    reql_array_init(var12.get(), arr12.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_bool_init(var13.get(), 0);

    reql_array_append(var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_bool_init(var14.get(), 0);

    reql_array_append(var12.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_bool_init(var15.get(), 0);

    reql_array_append(var12.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_bool_init(var16.get(), 1);

    reql_array_append(var12.get(), var16.get());

    reql_array_append(var1.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[4]);
    reql_array_init(var17.get(), arr17.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_bool_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_bool_init(var19.get(), 0);

    reql_array_append(var17.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_bool_init(var20.get(), 0);

    reql_array_append(var17.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_bool_init(var21.get(), 0);

    reql_array_append(var17.get(), var21.get());

    reql_array_append(var1.get(), var17.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[4]);
    reql_array_init(var22.get(), arr22.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr23(new ReQL_Obj_t*[4]);
    reql_array_init(var23.get(), arr23.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_bool_init(var24.get(), 0);

    reql_array_append(var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_bool_init(var25.get(), 0);

    reql_array_append(var23.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_bool_init(var26.get(), 0);

    reql_array_append(var23.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_bool_init(var27.get(), 0);

    reql_array_append(var23.get(), var27.get());

    reql_array_append(var22.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr28(new ReQL_Obj_t*[4]);
    reql_array_init(var28.get(), arr28.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_bool_init(var29.get(), 0);

    reql_array_append(var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_bool_init(var30.get(), 0);

    reql_array_append(var28.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    reql_bool_init(var31.get(), 0);

    reql_array_append(var28.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_bool_init(var32.get(), 0);

    reql_array_append(var28.get(), var32.get());

    reql_array_append(var22.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr33(new ReQL_Obj_t*[4]);
    reql_array_init(var33.get(), arr33.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_bool_init(var34.get(), 0);

    reql_array_append(var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_bool_init(var35.get(), 0);

    reql_array_append(var33.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_bool_init(var36.get(), 0);

    reql_array_append(var33.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_bool_init(var37.get(), 1);

    reql_array_append(var33.get(), var37.get());

    reql_array_append(var22.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr38(new ReQL_Obj_t*[4]);
    reql_array_init(var38.get(), arr38.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_bool_init(var39.get(), 0);

    reql_array_append(var38.get(), var39.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    reql_bool_init(var40.get(), 0);

    reql_array_append(var38.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    reql_bool_init(var41.get(), 0);

    reql_array_append(var38.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_bool_init(var42.get(), 0);

    reql_array_append(var38.get(), var42.get());

    reql_array_append(var22.get(), var38.get());

    reql_array_append(var0.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr43(new ReQL_Obj_t*[4]);
    reql_array_init(var43.get(), arr43.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr44(new ReQL_Obj_t*[4]);
    reql_array_init(var44.get(), arr44.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    reql_bool_init(var45.get(), 0);

    reql_array_append(var44.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    reql_bool_init(var46.get(), 0);

    reql_array_append(var44.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_bool_init(var47.get(), 0);

    reql_array_append(var44.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_bool_init(var48.get(), 0);

    reql_array_append(var44.get(), var48.get());

    reql_array_append(var43.get(), var44.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr49(new ReQL_Obj_t*[4]);
    reql_array_init(var49.get(), arr49.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    reql_bool_init(var50.get(), 0);

    reql_array_append(var49.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    reql_bool_init(var51.get(), 0);

    reql_array_append(var49.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    reql_bool_init(var52.get(), 0);

    reql_array_append(var49.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_bool_init(var53.get(), 0);

    reql_array_append(var49.get(), var53.get());

    reql_array_append(var43.get(), var49.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr54(new ReQL_Obj_t*[4]);
    reql_array_init(var54.get(), arr54.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    reql_bool_init(var55.get(), 0);

    reql_array_append(var54.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    reql_bool_init(var56.get(), 0);

    reql_array_append(var54.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_bool_init(var57.get(), 0);

    reql_array_append(var54.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_bool_init(var58.get(), 0);

    reql_array_append(var54.get(), var58.get());

    reql_array_append(var43.get(), var54.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr59(new ReQL_Obj_t*[4]);
    reql_array_init(var59.get(), arr59.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    reql_bool_init(var60.get(), 0);

    reql_array_append(var59.get(), var60.get());

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    reql_bool_init(var61.get(), 0);

    reql_array_append(var59.get(), var61.get());

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    reql_bool_init(var62.get(), 0);

    reql_array_append(var59.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_bool_init(var63.get(), 0);

    reql_array_append(var59.get(), var63.get());

    reql_array_append(var43.get(), var59.get());

    reql_array_append(var0.get(), var43.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr64(new ReQL_Obj_t*[4]);
    reql_array_init(var64.get(), arr64.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr65(new ReQL_Obj_t*[4]);
    reql_array_init(var65.get(), arr65.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    reql_bool_init(var66.get(), 0);

    reql_array_append(var65.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    reql_bool_init(var67.get(), 0);

    reql_array_append(var65.get(), var67.get());

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    reql_bool_init(var68.get(), 0);

    reql_array_append(var65.get(), var68.get());

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    reql_bool_init(var69.get(), 0);

    reql_array_append(var65.get(), var69.get());

    reql_array_append(var64.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr70(new ReQL_Obj_t*[4]);
    reql_array_init(var70.get(), arr70.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    reql_bool_init(var71.get(), 0);

    reql_array_append(var70.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    reql_bool_init(var72.get(), 0);

    reql_array_append(var70.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_bool_init(var73.get(), 0);

    reql_array_append(var70.get(), var73.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    reql_bool_init(var74.get(), 0);

    reql_array_append(var70.get(), var74.get());

    reql_array_append(var64.get(), var70.get());

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr75(new ReQL_Obj_t*[4]);
    reql_array_init(var75.get(), arr75.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    reql_bool_init(var76.get(), 0);

    reql_array_append(var75.get(), var76.get());

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    reql_bool_init(var77.get(), 0);

    reql_array_append(var75.get(), var77.get());

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    reql_bool_init(var78.get(), 0);

    reql_array_append(var75.get(), var78.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    reql_bool_init(var79.get(), 0);

    reql_array_append(var75.get(), var79.get());

    reql_array_append(var64.get(), var75.get());

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr80(new ReQL_Obj_t*[4]);
    reql_array_init(var80.get(), arr80.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    reql_bool_init(var81.get(), 0);

    reql_array_append(var80.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_bool_init(var82.get(), 0);

    reql_array_append(var80.get(), var82.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    reql_bool_init(var83.get(), 0);

    reql_array_append(var80.get(), var83.get());

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    reql_bool_init(var84.get(), 0);

    reql_array_append(var80.get(), var84.get());

    reql_array_append(var64.get(), var80.get());

    reql_array_append(var0.get(), var64.get());
  }

  SECTION("test24") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr1(new ReQL_Obj_t*[4]);
    reql_array_init(var1.get(), arr1.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[4]);
    reql_array_init(var2.get(), arr2.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_bool_init(var3.get(), 1);

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_bool_init(var4.get(), 1);

    reql_array_append(var2.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 1);

    reql_array_append(var2.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_bool_init(var6.get(), 1);

    reql_array_append(var2.get(), var6.get());

    reql_array_append(var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_bool_init(var8.get(), 0);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_bool_init(var9.get(), 1);

    reql_array_append(var7.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_bool_init(var10.get(), 1);

    reql_array_append(var7.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_bool_init(var11.get(), 1);

    reql_array_append(var7.get(), var11.get());

    reql_array_append(var1.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr12(new ReQL_Obj_t*[4]);
    reql_array_init(var12.get(), arr12.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_bool_init(var13.get(), 0);

    reql_array_append(var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_bool_init(var14.get(), 0);

    reql_array_append(var12.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_bool_init(var15.get(), 1);

    reql_array_append(var12.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_bool_init(var16.get(), 1);

    reql_array_append(var12.get(), var16.get());

    reql_array_append(var1.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[4]);
    reql_array_init(var17.get(), arr17.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_bool_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_bool_init(var19.get(), 0);

    reql_array_append(var17.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_bool_init(var20.get(), 0);

    reql_array_append(var17.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_bool_init(var21.get(), 1);

    reql_array_append(var17.get(), var21.get());

    reql_array_append(var1.get(), var17.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[4]);
    reql_array_init(var22.get(), arr22.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr23(new ReQL_Obj_t*[4]);
    reql_array_init(var23.get(), arr23.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_bool_init(var24.get(), 0);

    reql_array_append(var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_bool_init(var25.get(), 0);

    reql_array_append(var23.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_bool_init(var26.get(), 0);

    reql_array_append(var23.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_bool_init(var27.get(), 0);

    reql_array_append(var23.get(), var27.get());

    reql_array_append(var22.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr28(new ReQL_Obj_t*[4]);
    reql_array_init(var28.get(), arr28.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_bool_init(var29.get(), 0);

    reql_array_append(var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_bool_init(var30.get(), 1);

    reql_array_append(var28.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    reql_bool_init(var31.get(), 1);

    reql_array_append(var28.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_bool_init(var32.get(), 1);

    reql_array_append(var28.get(), var32.get());

    reql_array_append(var22.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr33(new ReQL_Obj_t*[4]);
    reql_array_init(var33.get(), arr33.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_bool_init(var34.get(), 0);

    reql_array_append(var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_bool_init(var35.get(), 0);

    reql_array_append(var33.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_bool_init(var36.get(), 1);

    reql_array_append(var33.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_bool_init(var37.get(), 1);

    reql_array_append(var33.get(), var37.get());

    reql_array_append(var22.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr38(new ReQL_Obj_t*[4]);
    reql_array_init(var38.get(), arr38.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_bool_init(var39.get(), 0);

    reql_array_append(var38.get(), var39.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    reql_bool_init(var40.get(), 0);

    reql_array_append(var38.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    reql_bool_init(var41.get(), 0);

    reql_array_append(var38.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_bool_init(var42.get(), 1);

    reql_array_append(var38.get(), var42.get());

    reql_array_append(var22.get(), var38.get());

    reql_array_append(var0.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr43(new ReQL_Obj_t*[4]);
    reql_array_init(var43.get(), arr43.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr44(new ReQL_Obj_t*[4]);
    reql_array_init(var44.get(), arr44.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    reql_bool_init(var45.get(), 0);

    reql_array_append(var44.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    reql_bool_init(var46.get(), 0);

    reql_array_append(var44.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_bool_init(var47.get(), 0);

    reql_array_append(var44.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_bool_init(var48.get(), 0);

    reql_array_append(var44.get(), var48.get());

    reql_array_append(var43.get(), var44.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr49(new ReQL_Obj_t*[4]);
    reql_array_init(var49.get(), arr49.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    reql_bool_init(var50.get(), 0);

    reql_array_append(var49.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    reql_bool_init(var51.get(), 0);

    reql_array_append(var49.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    reql_bool_init(var52.get(), 0);

    reql_array_append(var49.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_bool_init(var53.get(), 0);

    reql_array_append(var49.get(), var53.get());

    reql_array_append(var43.get(), var49.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr54(new ReQL_Obj_t*[4]);
    reql_array_init(var54.get(), arr54.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    reql_bool_init(var55.get(), 0);

    reql_array_append(var54.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    reql_bool_init(var56.get(), 0);

    reql_array_append(var54.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_bool_init(var57.get(), 1);

    reql_array_append(var54.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_bool_init(var58.get(), 1);

    reql_array_append(var54.get(), var58.get());

    reql_array_append(var43.get(), var54.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr59(new ReQL_Obj_t*[4]);
    reql_array_init(var59.get(), arr59.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    reql_bool_init(var60.get(), 0);

    reql_array_append(var59.get(), var60.get());

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    reql_bool_init(var61.get(), 0);

    reql_array_append(var59.get(), var61.get());

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    reql_bool_init(var62.get(), 0);

    reql_array_append(var59.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_bool_init(var63.get(), 1);

    reql_array_append(var59.get(), var63.get());

    reql_array_append(var43.get(), var59.get());

    reql_array_append(var0.get(), var43.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr64(new ReQL_Obj_t*[4]);
    reql_array_init(var64.get(), arr64.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr65(new ReQL_Obj_t*[4]);
    reql_array_init(var65.get(), arr65.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    reql_bool_init(var66.get(), 0);

    reql_array_append(var65.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    reql_bool_init(var67.get(), 0);

    reql_array_append(var65.get(), var67.get());

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    reql_bool_init(var68.get(), 0);

    reql_array_append(var65.get(), var68.get());

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    reql_bool_init(var69.get(), 0);

    reql_array_append(var65.get(), var69.get());

    reql_array_append(var64.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr70(new ReQL_Obj_t*[4]);
    reql_array_init(var70.get(), arr70.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    reql_bool_init(var71.get(), 0);

    reql_array_append(var70.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    reql_bool_init(var72.get(), 0);

    reql_array_append(var70.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_bool_init(var73.get(), 0);

    reql_array_append(var70.get(), var73.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    reql_bool_init(var74.get(), 0);

    reql_array_append(var70.get(), var74.get());

    reql_array_append(var64.get(), var70.get());

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr75(new ReQL_Obj_t*[4]);
    reql_array_init(var75.get(), arr75.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    reql_bool_init(var76.get(), 0);

    reql_array_append(var75.get(), var76.get());

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    reql_bool_init(var77.get(), 0);

    reql_array_append(var75.get(), var77.get());

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    reql_bool_init(var78.get(), 0);

    reql_array_append(var75.get(), var78.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    reql_bool_init(var79.get(), 0);

    reql_array_append(var75.get(), var79.get());

    reql_array_append(var64.get(), var75.get());

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr80(new ReQL_Obj_t*[4]);
    reql_array_init(var80.get(), arr80.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    reql_bool_init(var81.get(), 0);

    reql_array_append(var80.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_bool_init(var82.get(), 0);

    reql_array_append(var80.get(), var82.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    reql_bool_init(var83.get(), 0);

    reql_array_append(var80.get(), var83.get());

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    reql_bool_init(var84.get(), 1);

    reql_array_append(var80.get(), var84.get());

    reql_array_append(var64.get(), var80.get());

    reql_array_append(var0.get(), var64.get());
  }

  SECTION("test25") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr1(new ReQL_Obj_t*[4]);
    reql_array_init(var1.get(), arr1.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[4]);
    reql_array_init(var2.get(), arr2.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_bool_init(var3.get(), 0);

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_bool_init(var4.get(), 0);

    reql_array_append(var2.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 0);

    reql_array_append(var2.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_bool_init(var6.get(), 0);

    reql_array_append(var2.get(), var6.get());

    reql_array_append(var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_bool_init(var8.get(), 0);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_bool_init(var9.get(), 1);

    reql_array_append(var7.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_bool_init(var10.get(), 1);

    reql_array_append(var7.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_bool_init(var11.get(), 1);

    reql_array_append(var7.get(), var11.get());

    reql_array_append(var1.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr12(new ReQL_Obj_t*[4]);
    reql_array_init(var12.get(), arr12.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_bool_init(var13.get(), 0);

    reql_array_append(var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_bool_init(var14.get(), 0);

    reql_array_append(var12.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_bool_init(var15.get(), 1);

    reql_array_append(var12.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_bool_init(var16.get(), 1);

    reql_array_append(var12.get(), var16.get());

    reql_array_append(var1.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr17(new ReQL_Obj_t*[4]);
    reql_array_init(var17.get(), arr17.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_bool_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_bool_init(var19.get(), 0);

    reql_array_append(var17.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_bool_init(var20.get(), 0);

    reql_array_append(var17.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_bool_init(var21.get(), 1);

    reql_array_append(var17.get(), var21.get());

    reql_array_append(var1.get(), var17.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[4]);
    reql_array_init(var22.get(), arr22.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr23(new ReQL_Obj_t*[4]);
    reql_array_init(var23.get(), arr23.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_bool_init(var24.get(), 0);

    reql_array_append(var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_bool_init(var25.get(), 0);

    reql_array_append(var23.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_bool_init(var26.get(), 0);

    reql_array_append(var23.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_bool_init(var27.get(), 0);

    reql_array_append(var23.get(), var27.get());

    reql_array_append(var22.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr28(new ReQL_Obj_t*[4]);
    reql_array_init(var28.get(), arr28.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_bool_init(var29.get(), 0);

    reql_array_append(var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    reql_bool_init(var30.get(), 0);

    reql_array_append(var28.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    reql_bool_init(var31.get(), 0);

    reql_array_append(var28.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_bool_init(var32.get(), 0);

    reql_array_append(var28.get(), var32.get());

    reql_array_append(var22.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr33(new ReQL_Obj_t*[4]);
    reql_array_init(var33.get(), arr33.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_bool_init(var34.get(), 0);

    reql_array_append(var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_bool_init(var35.get(), 0);

    reql_array_append(var33.get(), var35.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    reql_bool_init(var36.get(), 1);

    reql_array_append(var33.get(), var36.get());

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_bool_init(var37.get(), 1);

    reql_array_append(var33.get(), var37.get());

    reql_array_append(var22.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr38(new ReQL_Obj_t*[4]);
    reql_array_init(var38.get(), arr38.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    reql_bool_init(var39.get(), 0);

    reql_array_append(var38.get(), var39.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    reql_bool_init(var40.get(), 0);

    reql_array_append(var38.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    reql_bool_init(var41.get(), 0);

    reql_array_append(var38.get(), var41.get());

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    reql_bool_init(var42.get(), 1);

    reql_array_append(var38.get(), var42.get());

    reql_array_append(var22.get(), var38.get());

    reql_array_append(var0.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr43(new ReQL_Obj_t*[4]);
    reql_array_init(var43.get(), arr43.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr44(new ReQL_Obj_t*[4]);
    reql_array_init(var44.get(), arr44.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    reql_bool_init(var45.get(), 0);

    reql_array_append(var44.get(), var45.get());

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    reql_bool_init(var46.get(), 0);

    reql_array_append(var44.get(), var46.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    reql_bool_init(var47.get(), 0);

    reql_array_append(var44.get(), var47.get());

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    reql_bool_init(var48.get(), 0);

    reql_array_append(var44.get(), var48.get());

    reql_array_append(var43.get(), var44.get());

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr49(new ReQL_Obj_t*[4]);
    reql_array_init(var49.get(), arr49.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    reql_bool_init(var50.get(), 0);

    reql_array_append(var49.get(), var50.get());

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    reql_bool_init(var51.get(), 0);

    reql_array_append(var49.get(), var51.get());

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    reql_bool_init(var52.get(), 0);

    reql_array_append(var49.get(), var52.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    reql_bool_init(var53.get(), 0);

    reql_array_append(var49.get(), var53.get());

    reql_array_append(var43.get(), var49.get());

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr54(new ReQL_Obj_t*[4]);
    reql_array_init(var54.get(), arr54.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    reql_bool_init(var55.get(), 0);

    reql_array_append(var54.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    reql_bool_init(var56.get(), 0);

    reql_array_append(var54.get(), var56.get());

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    reql_bool_init(var57.get(), 0);

    reql_array_append(var54.get(), var57.get());

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    reql_bool_init(var58.get(), 0);

    reql_array_append(var54.get(), var58.get());

    reql_array_append(var43.get(), var54.get());

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr59(new ReQL_Obj_t*[4]);
    reql_array_init(var59.get(), arr59.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    reql_bool_init(var60.get(), 0);

    reql_array_append(var59.get(), var60.get());

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    reql_bool_init(var61.get(), 0);

    reql_array_append(var59.get(), var61.get());

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    reql_bool_init(var62.get(), 0);

    reql_array_append(var59.get(), var62.get());

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    reql_bool_init(var63.get(), 1);

    reql_array_append(var59.get(), var63.get());

    reql_array_append(var43.get(), var59.get());

    reql_array_append(var0.get(), var43.get());

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr64(new ReQL_Obj_t*[4]);
    reql_array_init(var64.get(), arr64.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr65(new ReQL_Obj_t*[4]);
    reql_array_init(var65.get(), arr65.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    reql_bool_init(var66.get(), 0);

    reql_array_append(var65.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    reql_bool_init(var67.get(), 0);

    reql_array_append(var65.get(), var67.get());

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    reql_bool_init(var68.get(), 0);

    reql_array_append(var65.get(), var68.get());

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    reql_bool_init(var69.get(), 0);

    reql_array_append(var65.get(), var69.get());

    reql_array_append(var64.get(), var65.get());

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr70(new ReQL_Obj_t*[4]);
    reql_array_init(var70.get(), arr70.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    reql_bool_init(var71.get(), 0);

    reql_array_append(var70.get(), var71.get());

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    reql_bool_init(var72.get(), 0);

    reql_array_append(var70.get(), var72.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    reql_bool_init(var73.get(), 0);

    reql_array_append(var70.get(), var73.get());

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    reql_bool_init(var74.get(), 0);

    reql_array_append(var70.get(), var74.get());

    reql_array_append(var64.get(), var70.get());

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr75(new ReQL_Obj_t*[4]);
    reql_array_init(var75.get(), arr75.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    reql_bool_init(var76.get(), 0);

    reql_array_append(var75.get(), var76.get());

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    reql_bool_init(var77.get(), 0);

    reql_array_append(var75.get(), var77.get());

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    reql_bool_init(var78.get(), 0);

    reql_array_append(var75.get(), var78.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    reql_bool_init(var79.get(), 0);

    reql_array_append(var75.get(), var79.get());

    reql_array_append(var64.get(), var75.get());

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr80(new ReQL_Obj_t*[4]);
    reql_array_init(var80.get(), arr80.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    reql_bool_init(var81.get(), 0);

    reql_array_append(var80.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    reql_bool_init(var82.get(), 0);

    reql_array_append(var80.get(), var82.get());

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    reql_bool_init(var83.get(), 0);

    reql_array_append(var80.get(), var83.get());

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    reql_bool_init(var84.get(), 0);

    reql_array_append(var80.get(), var84.get());

    reql_array_append(var64.get(), var80.get());

    reql_array_append(var0.get(), var64.get());
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
    const ReQL_Byte src2[] = "rts";
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
    const ReQL_Byte src2[] = "rt1";
    reql_string_init(var2.get(), buf2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test28") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[25]);
    const ReQL_Byte src0[] = "2012-08-01T00:00:00+00:00";
    reql_string_init(var0.get(), buf0.get(), src0, 25);
  }

  SECTION("test29") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf0(new ReQL_Byte[25]);
    const ReQL_Byte src0[] = "2012-08-01T00:00:00+00:00";
    reql_string_init(var0.get(), buf0.get(), src0, 25);
  }
}
