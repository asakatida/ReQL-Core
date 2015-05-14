// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("c Test `include_states`", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "state";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[5]);
    const uint8_t src3[] = "ready";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "state";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "initializing";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[7]);
    const uint8_t src5[] = "new_val";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_null_init(var6.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[5]);
    const uint8_t src8[] = "state";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[5]);
    const uint8_t src9[] = "ready";
    reql_string_init(var9.get(), buf9.get(), 5);
    reql_string_append(var9.get(), src9, 5);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "state";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "initializing";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[5]);
    const uint8_t src5[] = "state";
    reql_string_init(var5.get(), buf5.get(), 5);
    reql_string_append(var5.get(), src5, 5);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[5]);
    const uint8_t src6[] = "ready";
    reql_string_init(var6.get(), buf6.get(), 5);
    reql_string_append(var6.get(), src6, 5);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "state";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "initializing";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[7]);
    const uint8_t src5[] = "new_val";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[2]);
    const uint8_t src7[] = "id";
    reql_string_init(var7.get(), buf7.get(), 2);
    reql_string_append(var7.get(), src7, 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[5]);
    const uint8_t src10[] = "state";
    reql_string_init(var10.get(), buf10.get(), 5);
    reql_string_append(var10.get(), src10, 5);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[5]);
    const uint8_t src11[] = "ready";
    reql_string_init(var11.get(), buf11.get(), 5);
    reql_string_append(var11.get(), src11, 5);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_array_append(var0.get(), var9.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "state";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[5]);
    const uint8_t src3[] = "ready";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[2]);
    reql_object_init(var4.get(), pair4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[7]);
    const uint8_t src5[] = "new_val";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[2]);
    const uint8_t src7[] = "id";
    reql_string_init(var7.get(), buf7.get(), 2);
    reql_string_append(var7.get(), src7, 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[7]);
    const uint8_t src9[] = "old_val";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_null_init(var10.get());

    reql_object_add(var4.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "state";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "initializing";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[7]);
    const uint8_t src5[] = "new_val";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[2]);
    const uint8_t src7[] = "id";
    reql_string_init(var7.get(), buf7.get(), 2);
    reql_string_append(var7.get(), src7, 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[5]);
    const uint8_t src10[] = "state";
    reql_string_init(var10.get(), buf10.get(), 5);
    reql_string_append(var10.get(), src10, 5);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[5]);
    const uint8_t src11[] = "ready";
    reql_string_init(var11.get(), buf11.get(), 5);
    reql_string_append(var11.get(), src11, 5);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_array_append(var0.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[2]);
    reql_object_init(var12.get(), pair12.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[7]);
    const uint8_t src13[] = "new_val";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[2]);
    const uint8_t src15[] = "id";
    reql_string_init(var15.get(), buf15.get(), 2);
    reql_string_append(var15.get(), src15, 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 2);

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[1]);
    const uint8_t src17[] = "a";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 1);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var12.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[7]);
    const uint8_t src19[] = "old_val";
    reql_string_init(var19.get(), buf19.get(), 7);
    reql_string_append(var19.get(), src19, 7);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair20(new ReQL_Pair_t[1]);
    reql_object_init(var20.get(), pair20.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf21(new uint8_t[2]);
    const uint8_t src21[] = "id";
    reql_string_init(var21.get(), buf21.get(), 2);
    reql_string_append(var21.get(), src21, 2);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 2);

    reql_object_add(var20.get(), var21.get(), var22.get());

    reql_object_add(var12.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var12.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "state";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "initializing";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[7]);
    const uint8_t src5[] = "new_val";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[2]);
    const uint8_t src7[] = "id";
    reql_string_init(var7.get(), buf7.get(), 2);
    reql_string_append(var7.get(), src7, 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[7]);
    const uint8_t src10[] = "new_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "a";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_array_append(var0.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[5]);
    const uint8_t src17[] = "state";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[5]);
    const uint8_t src18[] = "ready";
    reql_string_init(var18.get(), buf18.get(), 5);
    reql_string_append(var18.get(), src18, 5);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_array_append(var0.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf20(new uint8_t[7]);
    const uint8_t src20[] = "new_val";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair21(new ReQL_Pair_t[1]);
    reql_object_init(var21.get(), pair21.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf22(new uint8_t[2]);
    const uint8_t src22[] = "id";
    reql_string_init(var22.get(), buf22.get(), 2);
    reql_string_append(var22.get(), src22, 2);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 3);

    reql_object_add(var21.get(), var22.get(), var23.get());

    reql_object_add(var19.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf24(new uint8_t[7]);
    const uint8_t src24[] = "old_val";
    reql_string_init(var24.get(), buf24.get(), 7);
    reql_string_append(var24.get(), src24, 7);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_null_init(var25.get());

    reql_object_add(var19.get(), var24.get(), var25.get());

    reql_array_append(var0.get(), var19.get());
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "state";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "initializing";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[7]);
    const uint8_t src5[] = "new_val";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[2]);
    const uint8_t src7[] = "id";
    reql_string_init(var7.get(), buf7.get(), 2);
    reql_string_append(var7.get(), src7, 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "a";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[7]);
    const uint8_t src12[] = "new_val";
    reql_string_init(var12.get(), buf12.get(), 7);
    reql_string_append(var12.get(), src12, 7);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair13(new ReQL_Pair_t[1]);
    reql_object_init(var13.get(), pair13.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[2]);
    const uint8_t src14[] = "id";
    reql_string_init(var14.get(), buf14.get(), 2);
    reql_string_append(var14.get(), src14, 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1);

    reql_object_add(var13.get(), var14.get(), var15.get());

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[5]);
    const uint8_t src17[] = "state";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[5]);
    const uint8_t src18[] = "ready";
    reql_string_init(var18.get(), buf18.get(), 5);
    reql_string_append(var18.get(), src18, 5);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_array_append(var0.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf20(new uint8_t[7]);
    const uint8_t src20[] = "new_val";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair21(new ReQL_Pair_t[1]);
    reql_object_init(var21.get(), pair21.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf22(new uint8_t[2]);
    const uint8_t src22[] = "id";
    reql_string_init(var22.get(), buf22.get(), 2);
    reql_string_append(var22.get(), src22, 2);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 3);

    reql_object_add(var21.get(), var22.get(), var23.get());

    reql_object_add(var19.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf24(new uint8_t[7]);
    const uint8_t src24[] = "old_val";
    reql_string_init(var24.get(), buf24.get(), 7);
    reql_string_append(var24.get(), src24, 7);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_null_init(var25.get());

    reql_object_add(var19.get(), var24.get(), var25.get());

    reql_array_append(var0.get(), var19.get());
  }
}
