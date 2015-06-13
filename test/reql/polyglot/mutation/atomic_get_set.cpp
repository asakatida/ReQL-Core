// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("reql Tests replacement of selections", "[reql][ast]") {

  SECTION("test0") {
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

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[7]);
    const ReQL_Byte src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_null_init(var9.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_array_init(var2.get(), nullptr, 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[11]);
    const ReQL_Byte src3[] = "first_error";
    reql_string_init(var3.get(), buf3.get(), src3, 11);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[67]);
    const ReQL_Byte src4[] = "Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
    reql_string_init(var4.get(), buf4.get(), src4, 67);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[7]);
    const ReQL_Byte src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[2]);
    const ReQL_Byte src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), src10, 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[11]);
    const ReQL_Byte src12[] = "first_error";
    reql_string_init(var12.get(), buf12.get(), src12, 11);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[67]);
    const ReQL_Byte src13[] = "Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
    reql_string_init(var13.get(), buf13.get(), src13, 67);

    reql_object_add(var0.get(), var12.get(), var13.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[7]);
    const ReQL_Byte src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_null_init(var9.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[7]);
    const ReQL_Byte src10[] = "deleted";
    reql_string_init(var10.get(), buf10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_object_add(var0.get(), var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[6]);
    const ReQL_Byte src12[] = "errors";
    reql_string_init(var12.get(), buf12.get(), src12, 6);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var0.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[8]);
    const ReQL_Byte src14[] = "inserted";
    reql_string_init(var14.get(), buf14.get(), src14, 8);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1);

    reql_object_add(var0.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[8]);
    const ReQL_Byte src16[] = "replaced";
    reql_string_init(var16.get(), buf16.get(), src16, 8);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 0);

    reql_object_add(var0.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[7]);
    const ReQL_Byte src18[] = "skipped";
    reql_string_init(var18.get(), buf18.get(), src18, 7);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 0);

    reql_object_add(var0.get(), var18.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[9]);
    const ReQL_Byte src20[] = "unchanged";
    reql_string_init(var20.get(), buf20.get(), src20, 9);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_object_add(var0.get(), var20.get(), var21.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_array_init(var2.get(), nullptr, 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[11]);
    const ReQL_Byte src3[] = "first_error";
    reql_string_init(var3.get(), buf3.get(), src3, 11);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[67]);
    const ReQL_Byte src4[] = "Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
    reql_string_init(var4.get(), buf4.get(), src4, 67);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[1]);
    const ReQL_Byte src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[7]);
    const ReQL_Byte src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[2]);
    const ReQL_Byte src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_array_init(var2.get(), nullptr, 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[11]);
    const ReQL_Byte src3[] = "first_error";
    reql_string_init(var3.get(), buf3.get(), src3, 11);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[1]);
    const ReQL_Byte src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), src4, 1);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[2]);
    reql_array_init(var2.get(), arr2.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[1]);
    const ReQL_Byte src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 3);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[7]);
    const ReQL_Byte src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[2]);
    const ReQL_Byte src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[1]);
    const ReQL_Byte src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), src14, 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[7]);
    const ReQL_Byte src17[] = "new_val";
    reql_string_init(var17.get(), buf17.get(), src17, 7);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair18(new ReQL_Pair_t[2]);
    reql_object_init(var18.get(), pair18.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[2]);
    const ReQL_Byte src19[] = "id";
    reql_string_init(var19.get(), buf19.get(), src19, 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 1);

    reql_object_add(var18.get(), var19.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[1]);
    const ReQL_Byte src21[] = "x";
    reql_string_init(var21.get(), buf21.get(), src21, 1);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 3);

    reql_object_add(var18.get(), var21.get(), var22.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[7]);
    const ReQL_Byte src23[] = "old_val";
    reql_string_init(var23.get(), buf23.get(), src23, 7);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf25(new ReQL_Byte[2]);
    const ReQL_Byte src25[] = "id";
    reql_string_init(var25.get(), buf25.get(), src25, 2);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 1);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var16.get(), var23.get(), var24.get());

    reql_array_append(var2.get(), var16.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[1]);
    const ReQL_Byte src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 2);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[7]);
    const ReQL_Byte src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[2]);
    const ReQL_Byte src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[1]);
    const ReQL_Byte src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), src14, 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 3);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_array_init(var2.get(), nullptr, 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf3(new ReQL_Byte[11]);
    const ReQL_Byte src3[] = "first_error";
    reql_string_init(var3.get(), buf3.get(), src3, 11);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[1]);
    const ReQL_Byte src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), src4, 1);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[1]);
    const ReQL_Byte src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 2);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[7]);
    const ReQL_Byte src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[2]);
    const ReQL_Byte src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[1]);
    const ReQL_Byte src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), src14, 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 2);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[11]);
    const ReQL_Byte src16[] = "first_error";
    reql_string_init(var16.get(), buf16.get(), src16, 11);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[1]);
    const ReQL_Byte src17[] = "a";
    reql_string_init(var17.get(), buf17.get(), src17, 1);

    reql_object_add(var0.get(), var16.get(), var17.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[2]);
    reql_array_init(var2.get(), arr2.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[7]);
    const ReQL_Byte src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[2]);
    reql_object_init(var9.get(), pair9.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[2]);
    const ReQL_Byte src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), src10, 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_object_add(var9.get(), var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[1]);
    const ReQL_Byte src12[] = "x";
    reql_string_init(var12.get(), buf12.get(), src12, 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var9.get(), var12.get(), var13.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[7]);
    const ReQL_Byte src15[] = "new_val";
    reql_string_init(var15.get(), buf15.get(), src15, 7);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[2]);
    const ReQL_Byte src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 1);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[7]);
    const ReQL_Byte src19[] = "old_val";
    reql_string_init(var19.get(), buf19.get(), src19, 7);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair20(new ReQL_Pair_t[2]);
    reql_object_init(var20.get(), pair20.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[2]);
    const ReQL_Byte src21[] = "id";
    reql_string_init(var21.get(), buf21.get(), src21, 2);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 1);

    reql_object_add(var20.get(), var21.get(), var22.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf23(new ReQL_Byte[1]);
    const ReQL_Byte src23[] = "x";
    reql_string_init(var23.get(), buf23.get(), src23, 1);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 3);

    reql_object_add(var20.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var19.get(), var20.get());

    reql_array_append(var2.get(), var14.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[2]);
    reql_array_init(var2.get(), arr2.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[2]);
    const ReQL_Byte src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[7]);
    const ReQL_Byte src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[2]);
    const ReQL_Byte src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), src10, 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair12(new ReQL_Pair_t[2]);
    reql_object_init(var12.get(), pair12.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf13(new ReQL_Byte[7]);
    const ReQL_Byte src13[] = "new_val";
    reql_string_init(var13.get(), buf13.get(), src13, 7);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[1]);
    reql_object_init(var14.get(), pair14.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf15(new ReQL_Byte[2]);
    const ReQL_Byte src15[] = "id";
    reql_string_init(var15.get(), buf15.get(), src15, 2);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    reql_object_add(var12.get(), var13.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf17(new ReQL_Byte[7]);
    const ReQL_Byte src17[] = "old_val";
    reql_string_init(var17.get(), buf17.get(), src17, 7);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf19(new ReQL_Byte[2]);
    const ReQL_Byte src19[] = "id";
    reql_string_init(var19.get(), buf19.get(), src19, 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 1);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var12.get(), var17.get(), var18.get());

    reql_array_append(var2.get(), var12.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf21(new ReQL_Byte[11]);
    const ReQL_Byte src21[] = "first_error";
    reql_string_init(var21.get(), buf21.get(), src21, 11);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf22(new ReQL_Byte[62]);
    const ReQL_Byte src22[] = "Inserted object must have primary key `id`:\n{\n\t\"x\":\t1\n}";
    reql_string_init(var22.get(), buf22.get(), src22, 62);

    reql_object_add(var0.get(), var21.get(), var22.get());
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_null_init(var5.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[7]);
    const ReQL_Byte src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[2]);
    const ReQL_Byte src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf1(new ReQL_Byte[7]);
    const ReQL_Byte src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf4(new ReQL_Byte[7]);
    const ReQL_Byte src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_null_init(var5.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf6(new ReQL_Byte[7]);
    const ReQL_Byte src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf8(new ReQL_Byte[2]);
    const ReQL_Byte src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf10(new ReQL_Byte[7]);
    const ReQL_Byte src10[] = "deleted";
    reql_string_init(var10.get(), buf10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 1);

    reql_object_add(var0.get(), var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf12(new ReQL_Byte[6]);
    const ReQL_Byte src12[] = "errors";
    reql_string_init(var12.get(), buf12.get(), src12, 6);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var0.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf14(new ReQL_Byte[8]);
    const ReQL_Byte src14[] = "inserted";
    reql_string_init(var14.get(), buf14.get(), src14, 8);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 0);

    reql_object_add(var0.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf16(new ReQL_Byte[8]);
    const ReQL_Byte src16[] = "replaced";
    reql_string_init(var16.get(), buf16.get(), src16, 8);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 0);

    reql_object_add(var0.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf18(new ReQL_Byte[7]);
    const ReQL_Byte src18[] = "skipped";
    reql_string_init(var18.get(), buf18.get(), src18, 7);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 0);

    reql_object_add(var0.get(), var18.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte[]> buf20(new ReQL_Byte[9]);
    const ReQL_Byte src20[] = "unchanged";
    reql_string_init(var20.get(), buf20.get(), src20, 9);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_object_add(var0.get(), var20.get(), var21.get());
  }
}
