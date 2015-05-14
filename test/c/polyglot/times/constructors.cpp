// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("c Test basic time arithmetic", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[12]);
    const uint8_t src1[] = "reql_ast_obj";
    reql_string_init(var1.get(), buf1.get(), 12);
    reql_string_append(var1.get(), src1, 12);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "reql_ast_obj";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[8]);
    const uint8_t src4[] = "datetime";
    reql_string_init(var4.get(), buf4.get(), 8);
    reql_string_append(var4.get(), src4, 8);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "more";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[8]);
    const uint8_t src7[] = "datetime";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[5]);
    const uint8_t src8[] = "stuff";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[8]);
    const uint8_t src13[] = "datetime";
    reql_string_init(var13.get(), buf13.get(), 8);
    reql_string_append(var13.get(), src13, 8);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var0.get(), var8.get(), var9.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[8]);
    const uint8_t src5[] = "datetime";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[12]);
    const uint8_t src7[] = "reql_ast_obj";
    reql_string_init(var7.get(), buf7.get(), 12);
    reql_string_append(var7.get(), src7, 12);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[1]);
    reql_object_init(var8.get(), pair8.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[12]);
    const uint8_t src9[] = "reql_ast_obj";
    reql_string_init(var9.get(), buf9.get(), 12);
    reql_string_append(var9.get(), src9, 12);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[8]);
    const uint8_t src10[] = "datetime";
    reql_string_init(var10.get(), buf10.get(), 8);
    reql_string_append(var10.get(), src10, 8);

    reql_object_add(var8.get(), var9.get(), var10.get());

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[5]);
    const uint8_t src12[] = "stuff";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair13(new ReQL_Pair_t[1]);
    reql_object_init(var13.get(), pair13.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[12]);
    const uint8_t src14[] = "reql_ast_obj";
    reql_string_init(var14.get(), buf14.get(), 12);
    reql_string_append(var14.get(), src14, 12);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[1]);
    reql_object_init(var15.get(), pair15.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[12]);
    const uint8_t src16[] = "reql_ast_obj";
    reql_string_init(var16.get(), buf16.get(), 12);
    reql_string_append(var16.get(), src16, 12);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[8]);
    const uint8_t src17[] = "datetime";
    reql_string_init(var17.get(), buf17.get(), 8);
    reql_string_append(var17.get(), src17, 8);

    reql_object_add(var15.get(), var16.get(), var17.get());

    reql_object_add(var13.get(), var14.get(), var15.get());

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_array_append(var0.get(), var11.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[6]);
    const uint8_t src1[] = "nested";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[4]);
    const uint8_t src3[] = "time";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[12]);
    const uint8_t src5[] = "reql_ast_obj";
    reql_string_init(var5.get(), buf5.get(), 12);
    reql_string_append(var5.get(), src5, 12);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[12]);
    const uint8_t src7[] = "reql_ast_obj";
    reql_string_init(var7.get(), buf7.get(), 12);
    reql_string_append(var7.get(), src7, 12);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[8]);
    const uint8_t src8[] = "datetime";
    reql_string_init(var8.get(), buf8.get(), 8);
    reql_string_append(var8.get(), src8, 8);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "two";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr3(new ReQL_Obj_t*[3]);
    reql_array_init(var3.get(), arr3.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[12]);
    const uint8_t src8[] = "reql_ast_obj";
    reql_string_init(var8.get(), buf8.get(), 12);
    reql_string_append(var8.get(), src8, 12);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[8]);
    const uint8_t src9[] = "datetime";
    reql_string_init(var9.get(), buf9.get(), 8);
    reql_string_append(var9.get(), src9, 8);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_array_append(var3.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 3);

    reql_array_append(var3.get(), var10.get());

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), -1);
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1.444);
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[29]);
    const uint8_t src0[] = "1970-01-01T00:00:01.444+00:00";
    reql_string_init(var0.get(), buf0.get(), 29);
    reql_string_append(var0.get(), src0, 29);
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1.444);
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 10000);
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

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 253440000000);
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1400);
  }

  SECTION("test15") {
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

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), -17990000000);
  }
}
