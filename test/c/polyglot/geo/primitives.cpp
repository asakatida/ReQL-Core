// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("c Test geometric primitive constructors", "[c][ast]") {

  SECTION("test0") {
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
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[1]);
    reql_array_init(var6.get(), arr6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), -9.04369477050382e-06);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), -7.779638566553426e-06);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 4.5218473852518965e-06);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var7.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 7.779638566553426e-06);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 4.5218473852518965e-06);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var7.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), -9.04369477050382e-06);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var7.get(), var17.get());

    reql_array_append(var6.get(), var7.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test1") {
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
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[1]);
    reql_array_init(var6.get(), arr6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), -9.04369477050382e-06);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), -7.779638566553426e-06);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 4.5218473852518965e-06);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var7.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 7.779638566553426e-06);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 4.5218473852518965e-06);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var7.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), -9.04369477050382e-06);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var7.get(), var17.get());

    reql_array_append(var6.get(), var7.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[10]);
    const uint8_t src2[] = "LineString";
    reql_string_init(var2.get(), buf2.get(), 10);
    reql_string_append(var2.get(), src2, 10);

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
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[4]);
    reql_array_init(var6.get(), arr6.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), -9.04369477050382e-06);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), -7.779638566553426e-06);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 4.5218473852518965e-06);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var6.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 7.779638566553426e-06);

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 4.5218473852518965e-06);

    reql_array_append(var13.get(), var15.get());

    reql_array_append(var6.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr16(new ReQL_Obj_t*[2]);
    reql_array_init(var16.get(), arr16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 0);

    reql_array_append(var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), -9.04369477050382e-06);

    reql_array_append(var16.get(), var18.get());

    reql_array_append(var6.get(), var16.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test3") {
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

  SECTION("test4") {
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
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[1]);
    reql_array_init(var6.get(), arr6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), -9.04369477050382e-06);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), -7.779638566553426e-06);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 4.5218473852518965e-06);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var7.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 7.779638566553426e-06);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 4.5218473852518965e-06);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var7.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), -9.04369477050382e-06);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var7.get(), var17.get());

    reql_array_append(var6.get(), var7.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test5") {
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

  SECTION("test6") {
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
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[1]);
    reql_array_init(var6.get(), arr6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), -5.729577951308232);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), -4.966092947444857);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2.861205754495701);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var7.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 4.966092947444857);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 2.861205754495701);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var7.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), -5.729577951308232);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var7.get(), var17.get());

    reql_array_append(var6.get(), var7.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test7") {
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
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[1]);
    reql_array_init(var6.get(), arr6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), -9.04369477050382e-06);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), -7.779638566553426e-06);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 4.5218473852518965e-06);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var7.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 7.779638566553426e-06);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 4.5218473852518965e-06);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var7.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), -9.04369477050382e-06);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var7.get(), var17.get());

    reql_array_append(var6.get(), var7.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test8") {
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
    std::unique_ptr<ReQL_Obj_t*> arr6(new ReQL_Obj_t*[1]);
    reql_array_init(var6.get(), arr6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr7(new ReQL_Obj_t*[4]);
    reql_array_init(var7.get(), arr7.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), -9.04369477050382e-06);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), -7.779638566553426e-06);

    reql_array_append(var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 4.5218473852518965e-06);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var7.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 7.779638566553426e-06);

    reql_array_append(var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 4.5218473852518965e-06);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var7.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 0);

    reql_array_append(var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), -9.04369477050382e-06);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var7.get(), var17.get());

    reql_array_append(var6.get(), var7.get());

    reql_object_add(var0.get(), var5.get(), var6.get());
  }
}
