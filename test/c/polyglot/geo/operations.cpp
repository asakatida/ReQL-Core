// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("c Test basic geometry operators", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[21]);
    const uint8_t src0[] = "89011.262538353315904";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[21]);
    const uint8_t src0[] = "110968.30443995493988";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[21]);
    const uint8_t src0[] = "89011.262538353315904";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
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
    std::unique_ptr<uint8_t> buf0(new uint8_t[22]);
    const uint8_t src0[] = "0.01393875509649327056";
    reql_string_init(var0.get(), buf0.get(), 22);
    reql_string_append(var0.get(), src0, 22);
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[20]);
    const uint8_t src0[] = "40007862.91725089401";
    reql_string_init(var0.get(), buf0.get(), 20);
    reql_string_append(var0.get(), src0, 20);
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[20]);
    const uint8_t src0[] = "40007862.91725089401";
    reql_string_init(var0.get(), buf0.get(), 20);
    reql_string_append(var0.get(), src0, 20);
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test17") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[21]);
    const uint8_t src0[] = "492471.49900552548934";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[21]);
    const uint8_t src0[] = "492471.49900552548934";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
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
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[7]);
    const uint8_t src2[] = "Polygon";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[11]);
    const uint8_t src3[] = "$reql_type$";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[8]);
    const uint8_t src4[] = "GEOMETRY";
    reql_string_init(var4.get(), buf4.get(), 8);
    reql_string_append(var4.get(), src4, 8);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf5(new uint8_t[11]);
    const uint8_t src5[] = "coordinates";
    reql_string_init(var5.get(), buf5.get(), 11);
    reql_string_append(var5.get(), src5, 11);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[2]);
    reql_array_init(var6.get(), arr6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[5]);
    reql_array_init(var7.get(), arr7.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var7.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var7.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 1);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var7.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_array_append(var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 0);

    reql_array_append(var20.get(), var22.get());

    reql_array_append(var7.get(), var20.get());

    reql_array_append(var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr23(new ReQL_Obj_t*[5]);
    reql_array_init(var23.get(), arr23.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr24(new ReQL_Obj_t*[2]);
    reql_array_init(var24.get(), arr24.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 0.1);

    reql_array_append(var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 0.1);

    reql_array_append(var24.get(), var26.get());

    reql_array_append(var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr27(new ReQL_Obj_t*[2]);
    reql_array_init(var27.get(), arr27.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 0.9);

    reql_array_append(var27.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_number_init(var29.get(), 0.1);

    reql_array_append(var27.get(), var29.get());

    reql_array_append(var23.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr30(new ReQL_Obj_t*[2]);
    reql_array_init(var30.get(), arr30.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    reql_number_init(var31.get(), 0.9);

    reql_array_append(var30.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_number_init(var32.get(), 0.9);

    reql_array_append(var30.get(), var32.get());

    reql_array_append(var23.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr33(new ReQL_Obj_t*[2]);
    reql_array_init(var33.get(), arr33.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 0.1);

    reql_array_append(var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_number_init(var35.get(), 0.9);

    reql_array_append(var33.get(), var35.get());

    reql_array_append(var23.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr36(new ReQL_Obj_t*[2]);
    reql_array_init(var36.get(), arr36.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_number_init(var37.get(), 0.1);

    reql_array_append(var36.get(), var37.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    reql_number_init(var38.get(), 0.1);

    reql_array_append(var36.get(), var38.get());

    reql_array_append(var23.get(), var36.get());

    reql_array_append(var6.get(), var23.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test25") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test26") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test27") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test28") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test29") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test30") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[7]);
    const uint8_t src2[] = "Polygon";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[11]);
    const uint8_t src3[] = "$reql_type$";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[8]);
    const uint8_t src4[] = "GEOMETRY";
    reql_string_init(var4.get(), buf4.get(), 8);
    reql_string_append(var4.get(), src4, 8);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf5(new uint8_t[11]);
    const uint8_t src5[] = "coordinates";
    reql_string_init(var5.get(), buf5.get(), 11);
    reql_string_append(var5.get(), src5, 11);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[2]);
    reql_array_init(var6.get(), arr6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[5]);
    reql_array_init(var7.get(), arr7.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var7.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var7.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 1);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var7.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_array_append(var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 0);

    reql_array_append(var20.get(), var22.get());

    reql_array_append(var7.get(), var20.get());

    reql_array_append(var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr23(new ReQL_Obj_t*[5]);
    reql_array_init(var23.get(), arr23.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr24(new ReQL_Obj_t*[2]);
    reql_array_init(var24.get(), arr24.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 0);

    reql_array_append(var24.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 0);

    reql_array_append(var24.get(), var26.get());

    reql_array_append(var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr27(new ReQL_Obj_t*[2]);
    reql_array_init(var27.get(), arr27.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 0.1);

    reql_array_append(var27.get(), var28.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    reql_number_init(var29.get(), 0.9);

    reql_array_append(var27.get(), var29.get());

    reql_array_append(var23.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr30(new ReQL_Obj_t*[2]);
    reql_array_init(var30.get(), arr30.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    reql_number_init(var31.get(), 0.9);

    reql_array_append(var30.get(), var31.get());

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    reql_number_init(var32.get(), 0.9);

    reql_array_append(var30.get(), var32.get());

    reql_array_append(var23.get(), var30.get());

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr33(new ReQL_Obj_t*[2]);
    reql_array_init(var33.get(), arr33.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    reql_number_init(var34.get(), 0.9);

    reql_array_append(var33.get(), var34.get());

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    reql_number_init(var35.get(), 0.1);

    reql_array_append(var33.get(), var35.get());

    reql_array_append(var23.get(), var33.get());

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr36(new ReQL_Obj_t*[2]);
    reql_array_init(var36.get(), arr36.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    reql_number_init(var37.get(), 0);

    reql_array_append(var36.get(), var37.get());

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    reql_number_init(var38.get(), 0);

    reql_array_append(var36.get(), var38.get());

    reql_array_append(var23.get(), var36.get());

    reql_array_append(var6.get(), var23.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test31") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test32") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
