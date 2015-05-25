// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("c Test changefeed squashing 257", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[6]);
    const uint8_t src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test1") {
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

  SECTION("test2") {
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

  SECTION("test3") {
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

  SECTION("test4") {
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

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[2]);
    const uint8_t src4[] = "id";
    reql_string_init(var4.get(), buf4.get(), 2);
    reql_string_append(var4.get(), src4, 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 100);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_null_init(var7.get());

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[7]);
    const uint8_t src9[] = "new_val";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "a";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 100);

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[7]);
    const uint8_t src15[] = "old_val";
    reql_string_init(var15.get(), buf15.get(), 7);
    reql_string_append(var15.get(), src15, 7);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[2]);
    const uint8_t src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 100);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var8.get(), var15.get(), var16.get());

    reql_array_append(var0.get(), var8.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[2]);
    const uint8_t src4[] = "id";
    reql_string_init(var4.get(), buf4.get(), 2);
    reql_string_append(var4.get(), src4, 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 100);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_null_init(var7.get());

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[7]);
    const uint8_t src9[] = "new_val";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "a";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 100);

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[7]);
    const uint8_t src15[] = "old_val";
    reql_string_init(var15.get(), buf15.get(), 7);
    reql_string_append(var15.get(), src15, 7);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[2]);
    const uint8_t src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 100);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var8.get(), var15.get(), var16.get());

    reql_array_append(var0.get(), var8.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1);

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 100);

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_null_init(var9.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "new_val";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1);

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 100);

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_null_init(var9.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
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
}
