// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("c Test geometric primitive constructors", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "coordinates";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[4]);
    reql_array_init(var3.get(), arr3.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), -9.04369477050382e-06);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), -7.779638566553426e-06);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 4.5218473852518965e-06);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var3.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 7.779638566553426e-06);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 4.5218473852518965e-06);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var3.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 0);

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), -9.04369477050382e-06);

    reql_array_append(var13.get(), var15.get());

    reql_array_append(var3.get(), var13.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "type";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[7]);
    const uint8_t src17[] = "Polygon";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    reql_object_add(var0.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[11]);
    const uint8_t src18[] = "$reql_type$";
    reql_string_init(var18.get(), buf18.get(), 11);
    reql_string_append(var18.get(), src18, 11);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[8]);
    const uint8_t src19[] = "GEOMETRY";
    reql_string_init(var19.get(), buf19.get(), 8);
    reql_string_append(var19.get(), src19, 8);

    reql_object_add(var0.get(), var18.get(), var19.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "coordinates";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[4]);
    reql_array_init(var3.get(), arr3.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), -9.04369477050382e-06);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), -7.779638566553426e-06);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 4.5218473852518965e-06);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var3.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 7.779638566553426e-06);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 4.5218473852518965e-06);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var3.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 0);

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), -9.04369477050382e-06);

    reql_array_append(var13.get(), var15.get());

    reql_array_append(var3.get(), var13.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "type";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[7]);
    const uint8_t src17[] = "Polygon";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    reql_object_add(var0.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[11]);
    const uint8_t src18[] = "$reql_type$";
    reql_string_init(var18.get(), buf18.get(), 11);
    reql_string_append(var18.get(), src18, 11);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[8]);
    const uint8_t src19[] = "GEOMETRY";
    reql_string_init(var19.get(), buf19.get(), 8);
    reql_string_append(var19.get(), src19, 8);

    reql_object_add(var0.get(), var18.get(), var19.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "coordinates";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[4]);
    reql_array_init(var2.get(), arr2.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[2]);
    reql_array_init(var3.get(), arr3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), -9.04369477050382e-06);

    reql_array_append(var3.get(), var5.get());

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr6(new ReQL_Obj_t*[2]);
    reql_array_init(var6.get(), arr6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), -7.779638566553426e-06);

    reql_array_append(var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 4.5218473852518965e-06);

    reql_array_append(var6.get(), var8.get());

    reql_array_append(var2.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr9(new ReQL_Obj_t*[2]);
    reql_array_init(var9.get(), arr9.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 7.779638566553426e-06);

    reql_array_append(var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 4.5218473852518965e-06);

    reql_array_append(var9.get(), var11.get());

    reql_array_append(var2.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr12(new ReQL_Obj_t*[2]);
    reql_array_init(var12.get(), arr12.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_array_append(var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), -9.04369477050382e-06);

    reql_array_append(var12.get(), var14.get());

    reql_array_append(var2.get(), var12.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[4]);
    const uint8_t src15[] = "type";
    reql_string_init(var15.get(), buf15.get(), 4);
    reql_string_append(var15.get(), src15, 4);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[10]);
    const uint8_t src16[] = "LineString";
    reql_string_init(var16.get(), buf16.get(), 10);
    reql_string_append(var16.get(), src16, 10);

    reql_object_add(var0.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[11]);
    const uint8_t src17[] = "$reql_type$";
    reql_string_init(var17.get(), buf17.get(), 11);
    reql_string_append(var17.get(), src17, 11);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[8]);
    const uint8_t src18[] = "GEOMETRY";
    reql_string_init(var18.get(), buf18.get(), 8);
    reql_string_append(var18.get(), src18, 8);

    reql_object_add(var0.get(), var17.get(), var18.get());
  }

  SECTION("test3") {
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

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "coordinates";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[4]);
    reql_array_init(var3.get(), arr3.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), -9.04369477050382e-06);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), -7.779638566553426e-06);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 4.5218473852518965e-06);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var3.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 7.779638566553426e-06);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 4.5218473852518965e-06);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var3.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 0);

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), -9.04369477050382e-06);

    reql_array_append(var13.get(), var15.get());

    reql_array_append(var3.get(), var13.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "type";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[7]);
    const uint8_t src17[] = "Polygon";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    reql_object_add(var0.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[11]);
    const uint8_t src18[] = "$reql_type$";
    reql_string_init(var18.get(), buf18.get(), 11);
    reql_string_append(var18.get(), src18, 11);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[8]);
    const uint8_t src19[] = "GEOMETRY";
    reql_string_init(var19.get(), buf19.get(), 8);
    reql_string_append(var19.get(), src19, 8);

    reql_object_add(var0.get(), var18.get(), var19.get());
  }

  SECTION("test5") {
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

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "coordinates";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[4]);
    reql_array_init(var3.get(), arr3.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), -5.729577951308232);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), -4.966092947444857);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 2.861205754495701);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var3.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 4.966092947444857);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 2.861205754495701);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var3.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 0);

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), -5.729577951308232);

    reql_array_append(var13.get(), var15.get());

    reql_array_append(var3.get(), var13.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "type";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[7]);
    const uint8_t src17[] = "Polygon";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    reql_object_add(var0.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[11]);
    const uint8_t src18[] = "$reql_type$";
    reql_string_init(var18.get(), buf18.get(), 11);
    reql_string_append(var18.get(), src18, 11);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[8]);
    const uint8_t src19[] = "GEOMETRY";
    reql_string_init(var19.get(), buf19.get(), 8);
    reql_string_append(var19.get(), src19, 8);

    reql_object_add(var0.get(), var18.get(), var19.get());
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "coordinates";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[4]);
    reql_array_init(var3.get(), arr3.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), -9.04369477050382e-06);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), -7.779638566553426e-06);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 4.5218473852518965e-06);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var3.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 7.779638566553426e-06);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 4.5218473852518965e-06);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var3.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 0);

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), -9.04369477050382e-06);

    reql_array_append(var13.get(), var15.get());

    reql_array_append(var3.get(), var13.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "type";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[7]);
    const uint8_t src17[] = "Polygon";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    reql_object_add(var0.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[11]);
    const uint8_t src18[] = "$reql_type$";
    reql_string_init(var18.get(), buf18.get(), 11);
    reql_string_append(var18.get(), src18, 11);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[8]);
    const uint8_t src19[] = "GEOMETRY";
    reql_string_init(var19.get(), buf19.get(), 8);
    reql_string_append(var19.get(), src19, 8);

    reql_object_add(var0.get(), var18.get(), var19.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "coordinates";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[4]);
    reql_array_init(var3.get(), arr3.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), -9.04369477050382e-06);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), -7.779638566553426e-06);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 4.5218473852518965e-06);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var3.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 7.779638566553426e-06);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 4.5218473852518965e-06);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var3.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 0);

    reql_array_append(var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), -9.04369477050382e-06);

    reql_array_append(var13.get(), var15.get());

    reql_array_append(var3.get(), var13.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "type";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[7]);
    const uint8_t src17[] = "Polygon";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    reql_object_add(var0.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[11]);
    const uint8_t src18[] = "$reql_type$";
    reql_string_init(var18.get(), buf18.get(), 11);
    reql_string_append(var18.get(), src18, 11);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[8]);
    const uint8_t src19[] = "GEOMETRY";
    reql_string_init(var19.get(), buf19.get(), 8);
    reql_string_append(var19.get(), src19, 8);

    reql_object_add(var0.get(), var18.get(), var19.get());
  }
}
