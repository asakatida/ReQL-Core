// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("c Tests replacement of selections", "[c][ast]") {

  SECTION("test0") {
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

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[7]);
    const uint8_t src4[] = "old_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_null_init(var5.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[7]);
    const uint8_t src6[] = "new_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[11]);
    const uint8_t src1[] = "first_error";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[67]);
    const uint8_t src2[] = "Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
    reql_string_init(var2.get(), buf2.get(), 67);
    reql_string_append(var2.get(), src2, 67);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[7]);
    const uint8_t src3[] = "changes";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[7]);
    const uint8_t src10[] = "new_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var5.get(), var10.get(), var11.get());

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[6]);
    const uint8_t src1[] = "errors";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[9]);
    const uint8_t src3[] = "unchanged";
    reql_string_init(var3.get(), buf3.get(), 9);
    reql_string_append(var3.get(), src3, 9);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf5(new uint8_t[7]);
    const uint8_t src5[] = "deleted";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[8]);
    const uint8_t src7[] = "inserted";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 1);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf9(new uint8_t[8]);
    const uint8_t src9[] = "replaced";
    reql_string_init(var9.get(), buf9.get(), 8);
    reql_string_append(var9.get(), src9, 8);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf11(new uint8_t[7]);
    const uint8_t src11[] = "changes";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr12(new ReQL_Obj_t*[1]);
    reql_array_init(var12.get(), arr12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair13(new ReQL_Pair_t[2]);
    reql_object_init(var13.get(), pair13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf14(new uint8_t[7]);
    const uint8_t src14[] = "old_val";
    reql_string_init(var14.get(), buf14.get(), 7);
    reql_string_append(var14.get(), src14, 7);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_null_init(var15.get());

    reql_object_add(var13.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf16(new uint8_t[7]);
    const uint8_t src16[] = "new_val";
    reql_string_init(var16.get(), buf16.get(), 7);
    reql_string_append(var16.get(), src16, 7);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair17(new ReQL_Pair_t[1]);
    reql_object_init(var17.get(), pair17.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf18(new uint8_t[2]);
    const uint8_t src18[] = "id";
    reql_string_init(var18.get(), buf18.get(), 2);
    reql_string_append(var18.get(), src18, 2);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 1);

    reql_object_add(var17.get(), var18.get(), var19.get());

    reql_object_add(var13.get(), var16.get(), var17.get());

    reql_array_append(var12.get(), var13.get());

    reql_object_add(var0.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf20(new uint8_t[7]);
    const uint8_t src20[] = "skipped";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_object_add(var0.get(), var20.get(), var21.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[11]);
    const uint8_t src1[] = "first_error";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[67]);
    const uint8_t src2[] = "Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
    reql_string_init(var2.get(), buf2.get(), 67);
    reql_string_append(var2.get(), src2, 67);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[7]);
    const uint8_t src3[] = "changes";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[7]);
    const uint8_t src10[] = "new_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var5.get(), var10.get(), var11.get());

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[7]);
    const uint8_t src4[] = "old_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[7]);
    const uint8_t src8[] = "new_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[2]);
    reql_object_init(var9.get(), pair9.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[1]);
    const uint8_t src10[] = "x";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 1);

    reql_object_add(var9.get(), var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var9.get(), var12.get(), var13.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[11]);
    const uint8_t src1[] = "first_error";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[7]);
    const uint8_t src3[] = "changes";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair7(new ReQL_Pair_t[2]);
    reql_object_init(var7.get(), pair7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[1]);
    const uint8_t src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 1);

    reql_object_add(var7.get(), var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[2]);
    const uint8_t src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_object_add(var7.get(), var10.get(), var11.get());

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[7]);
    const uint8_t src12[] = "new_val";
    reql_string_init(var12.get(), buf12.get(), 7);
    reql_string_append(var12.get(), src12, 7);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair13(new ReQL_Pair_t[2]);
    reql_object_init(var13.get(), pair13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf14(new uint8_t[1]);
    const uint8_t src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 1);

    reql_object_add(var13.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf16(new uint8_t[2]);
    const uint8_t src16[] = "id";
    reql_string_init(var16.get(), buf16.get(), 2);
    reql_string_append(var16.get(), src16, 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 0);

    reql_object_add(var13.get(), var16.get(), var17.get());

    reql_object_add(var5.get(), var12.get(), var13.get());

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr2(new ReQL_Obj_t*[2]);
    reql_array_init(var2.get(), arr2.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[7]);
    const uint8_t src4[] = "old_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[1]);
    const uint8_t src6[] = "x";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[7]);
    const uint8_t src10[] = "new_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[1]);
    const uint8_t src12[] = "x";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 3);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf14(new uint8_t[2]);
    const uint8_t src14[] = "id";
    reql_string_init(var14.get(), buf14.get(), 2);
    reql_string_append(var14.get(), src14, 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 0);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[7]);
    const uint8_t src17[] = "old_val";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[2]);
    const uint8_t src19[] = "id";
    reql_string_init(var19.get(), buf19.get(), 2);
    reql_string_append(var19.get(), src19, 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 1);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[7]);
    const uint8_t src21[] = "new_val";
    reql_string_init(var21.get(), buf21.get(), 7);
    reql_string_append(var21.get(), src21, 7);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair22(new ReQL_Pair_t[2]);
    reql_object_init(var22.get(), pair22.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf23(new uint8_t[1]);
    const uint8_t src23[] = "x";
    reql_string_init(var23.get(), buf23.get(), 1);
    reql_string_append(var23.get(), src23, 1);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 3);

    reql_object_add(var22.get(), var23.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf25(new uint8_t[2]);
    const uint8_t src25[] = "id";
    reql_string_init(var25.get(), buf25.get(), 2);
    reql_string_append(var25.get(), src25, 2);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 1);

    reql_object_add(var22.get(), var25.get(), var26.get());

    reql_object_add(var16.get(), var21.get(), var22.get());

    reql_array_append(var2.get(), var16.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[7]);
    const uint8_t src4[] = "old_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[1]);
    const uint8_t src6[] = "x";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 3);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[7]);
    const uint8_t src10[] = "new_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[1]);
    const uint8_t src12[] = "x";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf14(new uint8_t[2]);
    const uint8_t src14[] = "id";
    reql_string_init(var14.get(), buf14.get(), 2);
    reql_string_append(var14.get(), src14, 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 0);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[11]);
    const uint8_t src1[] = "first_error";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[7]);
    const uint8_t src3[] = "changes";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair7(new ReQL_Pair_t[2]);
    reql_object_init(var7.get(), pair7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[1]);
    const uint8_t src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 2);

    reql_object_add(var7.get(), var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[2]);
    const uint8_t src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 0);

    reql_object_add(var7.get(), var10.get(), var11.get());

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[7]);
    const uint8_t src12[] = "new_val";
    reql_string_init(var12.get(), buf12.get(), 7);
    reql_string_append(var12.get(), src12, 7);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair13(new ReQL_Pair_t[2]);
    reql_object_init(var13.get(), pair13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf14(new uint8_t[1]);
    const uint8_t src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    reql_number_init(var15.get(), 2);

    reql_object_add(var13.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf16(new uint8_t[2]);
    const uint8_t src16[] = "id";
    reql_string_init(var16.get(), buf16.get(), 2);
    reql_string_append(var16.get(), src16, 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 0);

    reql_object_add(var13.get(), var16.get(), var17.get());

    reql_object_add(var5.get(), var12.get(), var13.get());

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr2(new ReQL_Obj_t*[2]);
    reql_array_init(var2.get(), arr2.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[7]);
    const uint8_t src4[] = "old_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[1]);
    const uint8_t src6[] = "x";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2);

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[7]);
    const uint8_t src10[] = "new_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf15(new uint8_t[7]);
    const uint8_t src15[] = "old_val";
    reql_string_init(var15.get(), buf15.get(), 7);
    reql_string_append(var15.get(), src15, 7);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[1]);
    const uint8_t src17[] = "x";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[2]);
    const uint8_t src19[] = "id";
    reql_string_init(var19.get(), buf19.get(), 2);
    reql_string_append(var19.get(), src19, 2);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 1);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[7]);
    const uint8_t src21[] = "new_val";
    reql_string_init(var21.get(), buf21.get(), 7);
    reql_string_append(var21.get(), src21, 7);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf23(new uint8_t[2]);
    const uint8_t src23[] = "id";
    reql_string_init(var23.get(), buf23.get(), 2);
    reql_string_append(var23.get(), src23, 2);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 1);

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var2.get(), var14.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[11]);
    const uint8_t src1[] = "first_error";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[62]);
    const uint8_t src2[] = "Inserted object must have primary key `id`:\n{\n\t\"x\":\t1\n}";
    reql_string_init(var2.get(), buf2.get(), 62);
    reql_string_append(var2.get(), src2, 62);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[7]);
    const uint8_t src3[] = "changes";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 0);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var5.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[7]);
    const uint8_t src10[] = "new_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var5.get(), var10.get(), var11.get());

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf15(new uint8_t[7]);
    const uint8_t src15[] = "old_val";
    reql_string_init(var15.get(), buf15.get(), 7);
    reql_string_append(var15.get(), src15, 7);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[2]);
    const uint8_t src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 1);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[7]);
    const uint8_t src19[] = "new_val";
    reql_string_init(var19.get(), buf19.get(), 7);
    reql_string_append(var19.get(), src19, 7);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair20(new ReQL_Pair_t[1]);
    reql_object_init(var20.get(), pair20.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[2]);
    const uint8_t src21[] = "id";
    reql_string_init(var21.get(), buf21.get(), 2);
    reql_string_append(var21.get(), src21, 2);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 1);

    reql_object_add(var20.get(), var21.get(), var22.get());

    reql_object_add(var14.get(), var19.get(), var20.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[7]);
    const uint8_t src4[] = "old_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[7]);
    const uint8_t src8[] = "new_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_null_init(var9.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[6]);
    const uint8_t src1[] = "errors";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[9]);
    const uint8_t src3[] = "unchanged";
    reql_string_init(var3.get(), buf3.get(), 9);
    reql_string_append(var3.get(), src3, 9);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf5(new uint8_t[7]);
    const uint8_t src5[] = "deleted";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 1);

    reql_object_add(var0.get(), var5.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[8]);
    const uint8_t src7[] = "inserted";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf9(new uint8_t[8]);
    const uint8_t src9[] = "replaced";
    reql_string_init(var9.get(), buf9.get(), 8);
    reql_string_append(var9.get(), src9, 8);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf11(new uint8_t[7]);
    const uint8_t src11[] = "changes";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr12(new ReQL_Obj_t*[1]);
    reql_array_init(var12.get(), arr12.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair13(new ReQL_Pair_t[2]);
    reql_object_init(var13.get(), pair13.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf14(new uint8_t[7]);
    const uint8_t src14[] = "old_val";
    reql_string_init(var14.get(), buf14.get(), 7);
    reql_string_append(var14.get(), src14, 7);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair15(new ReQL_Pair_t[1]);
    reql_object_init(var15.get(), pair15.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf16(new uint8_t[2]);
    const uint8_t src16[] = "id";
    reql_string_init(var16.get(), buf16.get(), 2);
    reql_string_append(var16.get(), src16, 2);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 1);

    reql_object_add(var15.get(), var16.get(), var17.get());

    reql_object_add(var13.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf18(new uint8_t[7]);
    const uint8_t src18[] = "new_val";
    reql_string_init(var18.get(), buf18.get(), 7);
    reql_string_append(var18.get(), src18, 7);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_null_init(var19.get());

    reql_object_add(var13.get(), var18.get(), var19.get());

    reql_array_append(var12.get(), var13.get());

    reql_object_add(var0.get(), var11.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf20(new uint8_t[7]);
    const uint8_t src20[] = "skipped";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 0);

    reql_object_add(var0.get(), var20.get(), var21.get());
  }
}
