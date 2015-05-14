// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("c sindex api (#602)", "[c][ast]") {

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

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
    reql_number_init(var8.get(), 4);

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
    const uint8_t src11[] = "skipped";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[9]);
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
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
    std::unique_ptr<uint8_t> buf2(new uint8_t[9]);
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
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

  SECTION("test7") {
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

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "renamed";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test15") {
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
    const uint8_t src2[] = "bag";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 3);
  }

  SECTION("test17") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "index";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf3(new uint8_t[15]);
    const uint8_t src3[] = "rename-last-dup";
    reql_string_init(var3.get(), buf3.get(), 15);
    reql_string_append(var3.get(), src3, 15);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[5]);
    const uint8_t src4[] = "ready";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_bool_init(var5.get(), 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 3);
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "dropped";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test24") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[11]);
    const uint8_t src1[] = "rename-last";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test25") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "dropped";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test26") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

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
    std::unique_ptr<uint8_t> buf2(new uint8_t[9]);
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test28") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test29") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test30") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test31") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test32") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test33") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test34") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test35") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test36") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test37") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test38") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test39") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<OBJECT>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test40") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

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
    reql_number_init(var4.get(), 1);

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
    const uint8_t src11[] = "skipped";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test41") {
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

  SECTION("test42") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test43") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test44") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test45") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test46") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test47") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test48") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test49") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test50") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test51") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test52") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

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
    reql_number_init(var4.get(), 1);

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
    const uint8_t src11[] = "skipped";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test53") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

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
    reql_number_init(var4.get(), 1);

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
    const uint8_t src11[] = "skipped";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test54") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

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
    reql_number_init(var4.get(), 3);

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
    const uint8_t src11[] = "skipped";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test55") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

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
    reql_number_init(var4.get(), 3);

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
    const uint8_t src11[] = "skipped";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test56") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[9]);
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test57") {
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

  SECTION("test58") {
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

  SECTION("test59") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test60") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test61") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test62") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test63") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test64") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 1);
  }

  SECTION("test65") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test66") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test67") {
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

  SECTION("test68") {
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

  SECTION("test69") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test70") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test71") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

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
    reql_number_init(var4.get(), 2);

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
    const uint8_t src11[] = "skipped";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test72") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test73") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf5(new uint8_t[7]);
    const uint8_t src5[] = "Bracket";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test74") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf5(new uint8_t[7]);
    const uint8_t src5[] = "Bracket";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test75") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf5(new uint8_t[7]);
    const uint8_t src5[] = "Bracket";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test76") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[12]);
    const uint8_t src2[] = "reql_ast_obj";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf5(new uint8_t[7]);
    const uint8_t src5[] = "Bracket";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test77") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[9]);
    const uint8_t src2[] = "err_regex";
    reql_string_init(var2.get(), buf2.get(), 9);
    reql_string_append(var2.get(), src2, 9);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test78") {
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

  SECTION("test79") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test80") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test81") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test82") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test83") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test84") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test85") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test86") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf15(new uint8_t[5]);
    const uint8_t src15[] = "right";
    reql_string_init(var15.get(), buf15.get(), 5);
    reql_string_append(var15.get(), src15, 5);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[4]);
    const uint8_t src21[] = "left";
    reql_string_init(var21.get(), buf21.get(), 4);
    reql_string_append(var21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf28(new uint8_t[5]);
    const uint8_t src28[] = "right";
    reql_string_init(var28.get(), buf28.get(), 5);
    reql_string_append(var28.get(), src28, 5);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf34(new uint8_t[4]);
    const uint8_t src34[] = "left";
    reql_string_init(var34.get(), buf34.get(), 4);
    reql_string_append(var34.get(), src34, 4);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair40(new ReQL_Pair_t[2]);
    reql_object_init(var40.get(), pair40.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf41(new uint8_t[5]);
    const uint8_t src41[] = "right";
    reql_string_init(var41.get(), buf41.get(), 5);
    reql_string_append(var41.get(), src41, 5);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair42(new ReQL_Pair_t[1]);
    reql_object_init(var42.get(), pair42.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf43(new uint8_t[12]);
    const uint8_t src43[] = "reql_ast_obj";
    reql_string_init(var43.get(), buf43.get(), 12);
    reql_string_append(var43.get(), src43, 12);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair44(new ReQL_Pair_t[1]);
    reql_object_init(var44.get(), pair44.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf45(new uint8_t[12]);
    const uint8_t src45[] = "reql_ast_obj";
    reql_string_init(var45.get(), buf45.get(), 12);
    reql_string_append(var45.get(), src45, 12);

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf46(new uint8_t[7]);
    const uint8_t src46[] = "Bracket";
    reql_string_init(var46.get(), buf46.get(), 7);
    reql_string_append(var46.get(), src46, 7);

    reql_object_add(var44.get(), var45.get(), var46.get());

    reql_object_add(var42.get(), var43.get(), var44.get());

    reql_object_add(var40.get(), var41.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf47(new uint8_t[4]);
    const uint8_t src47[] = "left";
    reql_string_init(var47.get(), buf47.get(), 4);
    reql_string_append(var47.get(), src47, 4);

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair48(new ReQL_Pair_t[1]);
    reql_object_init(var48.get(), pair48.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf49(new uint8_t[12]);
    const uint8_t src49[] = "reql_ast_obj";
    reql_string_init(var49.get(), buf49.get(), 12);
    reql_string_append(var49.get(), src49, 12);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair50(new ReQL_Pair_t[1]);
    reql_object_init(var50.get(), pair50.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf51(new uint8_t[12]);
    const uint8_t src51[] = "reql_ast_obj";
    reql_string_init(var51.get(), buf51.get(), 12);
    reql_string_append(var51.get(), src51, 12);

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf52(new uint8_t[7]);
    const uint8_t src52[] = "Bracket";
    reql_string_init(var52.get(), buf52.get(), 7);
    reql_string_append(var52.get(), src52, 7);

    reql_object_add(var50.get(), var51.get(), var52.get());

    reql_object_add(var48.get(), var49.get(), var50.get());

    reql_object_add(var40.get(), var47.get(), var48.get());

    reql_array_append(var0.get(), var40.get());
  }

  SECTION("test87") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf15(new uint8_t[5]);
    const uint8_t src15[] = "right";
    reql_string_init(var15.get(), buf15.get(), 5);
    reql_string_append(var15.get(), src15, 5);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[4]);
    const uint8_t src21[] = "left";
    reql_string_init(var21.get(), buf21.get(), 4);
    reql_string_append(var21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf28(new uint8_t[5]);
    const uint8_t src28[] = "right";
    reql_string_init(var28.get(), buf28.get(), 5);
    reql_string_append(var28.get(), src28, 5);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf34(new uint8_t[4]);
    const uint8_t src34[] = "left";
    reql_string_init(var34.get(), buf34.get(), 4);
    reql_string_append(var34.get(), src34, 4);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());
  }

  SECTION("test88") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf15(new uint8_t[5]);
    const uint8_t src15[] = "right";
    reql_string_init(var15.get(), buf15.get(), 5);
    reql_string_append(var15.get(), src15, 5);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[4]);
    const uint8_t src21[] = "left";
    reql_string_init(var21.get(), buf21.get(), 4);
    reql_string_append(var21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());
  }

  SECTION("test89") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test90") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[8]);
    reql_array_init(var0.get(), arr0.get(), 8);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf15(new uint8_t[5]);
    const uint8_t src15[] = "right";
    reql_string_init(var15.get(), buf15.get(), 5);
    reql_string_append(var15.get(), src15, 5);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[4]);
    const uint8_t src21[] = "left";
    reql_string_init(var21.get(), buf21.get(), 4);
    reql_string_append(var21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf28(new uint8_t[5]);
    const uint8_t src28[] = "right";
    reql_string_init(var28.get(), buf28.get(), 5);
    reql_string_append(var28.get(), src28, 5);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf34(new uint8_t[4]);
    const uint8_t src34[] = "left";
    reql_string_init(var34.get(), buf34.get(), 4);
    reql_string_append(var34.get(), src34, 4);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair40(new ReQL_Pair_t[2]);
    reql_object_init(var40.get(), pair40.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf41(new uint8_t[5]);
    const uint8_t src41[] = "right";
    reql_string_init(var41.get(), buf41.get(), 5);
    reql_string_append(var41.get(), src41, 5);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair42(new ReQL_Pair_t[1]);
    reql_object_init(var42.get(), pair42.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf43(new uint8_t[12]);
    const uint8_t src43[] = "reql_ast_obj";
    reql_string_init(var43.get(), buf43.get(), 12);
    reql_string_append(var43.get(), src43, 12);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair44(new ReQL_Pair_t[1]);
    reql_object_init(var44.get(), pair44.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf45(new uint8_t[12]);
    const uint8_t src45[] = "reql_ast_obj";
    reql_string_init(var45.get(), buf45.get(), 12);
    reql_string_append(var45.get(), src45, 12);

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf46(new uint8_t[7]);
    const uint8_t src46[] = "Bracket";
    reql_string_init(var46.get(), buf46.get(), 7);
    reql_string_append(var46.get(), src46, 7);

    reql_object_add(var44.get(), var45.get(), var46.get());

    reql_object_add(var42.get(), var43.get(), var44.get());

    reql_object_add(var40.get(), var41.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf47(new uint8_t[4]);
    const uint8_t src47[] = "left";
    reql_string_init(var47.get(), buf47.get(), 4);
    reql_string_append(var47.get(), src47, 4);

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair48(new ReQL_Pair_t[1]);
    reql_object_init(var48.get(), pair48.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf49(new uint8_t[12]);
    const uint8_t src49[] = "reql_ast_obj";
    reql_string_init(var49.get(), buf49.get(), 12);
    reql_string_append(var49.get(), src49, 12);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair50(new ReQL_Pair_t[1]);
    reql_object_init(var50.get(), pair50.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf51(new uint8_t[12]);
    const uint8_t src51[] = "reql_ast_obj";
    reql_string_init(var51.get(), buf51.get(), 12);
    reql_string_append(var51.get(), src51, 12);

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf52(new uint8_t[7]);
    const uint8_t src52[] = "Bracket";
    reql_string_init(var52.get(), buf52.get(), 7);
    reql_string_append(var52.get(), src52, 7);

    reql_object_add(var50.get(), var51.get(), var52.get());

    reql_object_add(var48.get(), var49.get(), var50.get());

    reql_object_add(var40.get(), var47.get(), var48.get());

    reql_array_append(var0.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair53(new ReQL_Pair_t[2]);
    reql_object_init(var53.get(), pair53.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf54(new uint8_t[5]);
    const uint8_t src54[] = "right";
    reql_string_init(var54.get(), buf54.get(), 5);
    reql_string_append(var54.get(), src54, 5);

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair55(new ReQL_Pair_t[1]);
    reql_object_init(var55.get(), pair55.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf56(new uint8_t[12]);
    const uint8_t src56[] = "reql_ast_obj";
    reql_string_init(var56.get(), buf56.get(), 12);
    reql_string_append(var56.get(), src56, 12);

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair57(new ReQL_Pair_t[1]);
    reql_object_init(var57.get(), pair57.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf58(new uint8_t[12]);
    const uint8_t src58[] = "reql_ast_obj";
    reql_string_init(var58.get(), buf58.get(), 12);
    reql_string_append(var58.get(), src58, 12);

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf59(new uint8_t[7]);
    const uint8_t src59[] = "Bracket";
    reql_string_init(var59.get(), buf59.get(), 7);
    reql_string_append(var59.get(), src59, 7);

    reql_object_add(var57.get(), var58.get(), var59.get());

    reql_object_add(var55.get(), var56.get(), var57.get());

    reql_object_add(var53.get(), var54.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf60(new uint8_t[4]);
    const uint8_t src60[] = "left";
    reql_string_init(var60.get(), buf60.get(), 4);
    reql_string_append(var60.get(), src60, 4);

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair61(new ReQL_Pair_t[1]);
    reql_object_init(var61.get(), pair61.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf62(new uint8_t[12]);
    const uint8_t src62[] = "reql_ast_obj";
    reql_string_init(var62.get(), buf62.get(), 12);
    reql_string_append(var62.get(), src62, 12);

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair63(new ReQL_Pair_t[1]);
    reql_object_init(var63.get(), pair63.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf64(new uint8_t[12]);
    const uint8_t src64[] = "reql_ast_obj";
    reql_string_init(var64.get(), buf64.get(), 12);
    reql_string_append(var64.get(), src64, 12);

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf65(new uint8_t[7]);
    const uint8_t src65[] = "Bracket";
    reql_string_init(var65.get(), buf65.get(), 7);
    reql_string_append(var65.get(), src65, 7);

    reql_object_add(var63.get(), var64.get(), var65.get());

    reql_object_add(var61.get(), var62.get(), var63.get());

    reql_object_add(var53.get(), var60.get(), var61.get());

    reql_array_append(var0.get(), var53.get());

    std::unique_ptr<ReQL_Obj_t> var66(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair66(new ReQL_Pair_t[2]);
    reql_object_init(var66.get(), pair66.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var67(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf67(new uint8_t[5]);
    const uint8_t src67[] = "right";
    reql_string_init(var67.get(), buf67.get(), 5);
    reql_string_append(var67.get(), src67, 5);

    std::unique_ptr<ReQL_Obj_t> var68(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair68(new ReQL_Pair_t[1]);
    reql_object_init(var68.get(), pair68.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var69(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf69(new uint8_t[12]);
    const uint8_t src69[] = "reql_ast_obj";
    reql_string_init(var69.get(), buf69.get(), 12);
    reql_string_append(var69.get(), src69, 12);

    std::unique_ptr<ReQL_Obj_t> var70(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair70(new ReQL_Pair_t[1]);
    reql_object_init(var70.get(), pair70.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var71(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf71(new uint8_t[12]);
    const uint8_t src71[] = "reql_ast_obj";
    reql_string_init(var71.get(), buf71.get(), 12);
    reql_string_append(var71.get(), src71, 12);

    std::unique_ptr<ReQL_Obj_t> var72(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf72(new uint8_t[7]);
    const uint8_t src72[] = "Bracket";
    reql_string_init(var72.get(), buf72.get(), 7);
    reql_string_append(var72.get(), src72, 7);

    reql_object_add(var70.get(), var71.get(), var72.get());

    reql_object_add(var68.get(), var69.get(), var70.get());

    reql_object_add(var66.get(), var67.get(), var68.get());

    std::unique_ptr<ReQL_Obj_t> var73(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf73(new uint8_t[4]);
    const uint8_t src73[] = "left";
    reql_string_init(var73.get(), buf73.get(), 4);
    reql_string_append(var73.get(), src73, 4);

    std::unique_ptr<ReQL_Obj_t> var74(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair74(new ReQL_Pair_t[1]);
    reql_object_init(var74.get(), pair74.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var75(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf75(new uint8_t[12]);
    const uint8_t src75[] = "reql_ast_obj";
    reql_string_init(var75.get(), buf75.get(), 12);
    reql_string_append(var75.get(), src75, 12);

    std::unique_ptr<ReQL_Obj_t> var76(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair76(new ReQL_Pair_t[1]);
    reql_object_init(var76.get(), pair76.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var77(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf77(new uint8_t[12]);
    const uint8_t src77[] = "reql_ast_obj";
    reql_string_init(var77.get(), buf77.get(), 12);
    reql_string_append(var77.get(), src77, 12);

    std::unique_ptr<ReQL_Obj_t> var78(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf78(new uint8_t[7]);
    const uint8_t src78[] = "Bracket";
    reql_string_init(var78.get(), buf78.get(), 7);
    reql_string_append(var78.get(), src78, 7);

    reql_object_add(var76.get(), var77.get(), var78.get());

    reql_object_add(var74.get(), var75.get(), var76.get());

    reql_object_add(var66.get(), var73.get(), var74.get());

    reql_array_append(var0.get(), var66.get());

    std::unique_ptr<ReQL_Obj_t> var79(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair79(new ReQL_Pair_t[2]);
    reql_object_init(var79.get(), pair79.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var80(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf80(new uint8_t[5]);
    const uint8_t src80[] = "right";
    reql_string_init(var80.get(), buf80.get(), 5);
    reql_string_append(var80.get(), src80, 5);

    std::unique_ptr<ReQL_Obj_t> var81(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair81(new ReQL_Pair_t[1]);
    reql_object_init(var81.get(), pair81.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var82(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf82(new uint8_t[12]);
    const uint8_t src82[] = "reql_ast_obj";
    reql_string_init(var82.get(), buf82.get(), 12);
    reql_string_append(var82.get(), src82, 12);

    std::unique_ptr<ReQL_Obj_t> var83(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair83(new ReQL_Pair_t[1]);
    reql_object_init(var83.get(), pair83.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var84(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf84(new uint8_t[12]);
    const uint8_t src84[] = "reql_ast_obj";
    reql_string_init(var84.get(), buf84.get(), 12);
    reql_string_append(var84.get(), src84, 12);

    std::unique_ptr<ReQL_Obj_t> var85(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf85(new uint8_t[7]);
    const uint8_t src85[] = "Bracket";
    reql_string_init(var85.get(), buf85.get(), 7);
    reql_string_append(var85.get(), src85, 7);

    reql_object_add(var83.get(), var84.get(), var85.get());

    reql_object_add(var81.get(), var82.get(), var83.get());

    reql_object_add(var79.get(), var80.get(), var81.get());

    std::unique_ptr<ReQL_Obj_t> var86(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf86(new uint8_t[4]);
    const uint8_t src86[] = "left";
    reql_string_init(var86.get(), buf86.get(), 4);
    reql_string_append(var86.get(), src86, 4);

    std::unique_ptr<ReQL_Obj_t> var87(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair87(new ReQL_Pair_t[1]);
    reql_object_init(var87.get(), pair87.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var88(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf88(new uint8_t[12]);
    const uint8_t src88[] = "reql_ast_obj";
    reql_string_init(var88.get(), buf88.get(), 12);
    reql_string_append(var88.get(), src88, 12);

    std::unique_ptr<ReQL_Obj_t> var89(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair89(new ReQL_Pair_t[1]);
    reql_object_init(var89.get(), pair89.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var90(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf90(new uint8_t[12]);
    const uint8_t src90[] = "reql_ast_obj";
    reql_string_init(var90.get(), buf90.get(), 12);
    reql_string_append(var90.get(), src90, 12);

    std::unique_ptr<ReQL_Obj_t> var91(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf91(new uint8_t[7]);
    const uint8_t src91[] = "Bracket";
    reql_string_init(var91.get(), buf91.get(), 7);
    reql_string_append(var91.get(), src91, 7);

    reql_object_add(var89.get(), var90.get(), var91.get());

    reql_object_add(var87.get(), var88.get(), var89.get());

    reql_object_add(var79.get(), var86.get(), var87.get());

    reql_array_append(var0.get(), var79.get());

    std::unique_ptr<ReQL_Obj_t> var92(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair92(new ReQL_Pair_t[2]);
    reql_object_init(var92.get(), pair92.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var93(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf93(new uint8_t[5]);
    const uint8_t src93[] = "right";
    reql_string_init(var93.get(), buf93.get(), 5);
    reql_string_append(var93.get(), src93, 5);

    std::unique_ptr<ReQL_Obj_t> var94(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair94(new ReQL_Pair_t[1]);
    reql_object_init(var94.get(), pair94.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var95(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf95(new uint8_t[12]);
    const uint8_t src95[] = "reql_ast_obj";
    reql_string_init(var95.get(), buf95.get(), 12);
    reql_string_append(var95.get(), src95, 12);

    std::unique_ptr<ReQL_Obj_t> var96(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair96(new ReQL_Pair_t[1]);
    reql_object_init(var96.get(), pair96.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var97(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf97(new uint8_t[12]);
    const uint8_t src97[] = "reql_ast_obj";
    reql_string_init(var97.get(), buf97.get(), 12);
    reql_string_append(var97.get(), src97, 12);

    std::unique_ptr<ReQL_Obj_t> var98(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf98(new uint8_t[7]);
    const uint8_t src98[] = "Bracket";
    reql_string_init(var98.get(), buf98.get(), 7);
    reql_string_append(var98.get(), src98, 7);

    reql_object_add(var96.get(), var97.get(), var98.get());

    reql_object_add(var94.get(), var95.get(), var96.get());

    reql_object_add(var92.get(), var93.get(), var94.get());

    std::unique_ptr<ReQL_Obj_t> var99(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf99(new uint8_t[4]);
    const uint8_t src99[] = "left";
    reql_string_init(var99.get(), buf99.get(), 4);
    reql_string_append(var99.get(), src99, 4);

    std::unique_ptr<ReQL_Obj_t> var100(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair100(new ReQL_Pair_t[1]);
    reql_object_init(var100.get(), pair100.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var101(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf101(new uint8_t[12]);
    const uint8_t src101[] = "reql_ast_obj";
    reql_string_init(var101.get(), buf101.get(), 12);
    reql_string_append(var101.get(), src101, 12);

    std::unique_ptr<ReQL_Obj_t> var102(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair102(new ReQL_Pair_t[1]);
    reql_object_init(var102.get(), pair102.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var103(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf103(new uint8_t[12]);
    const uint8_t src103[] = "reql_ast_obj";
    reql_string_init(var103.get(), buf103.get(), 12);
    reql_string_append(var103.get(), src103, 12);

    std::unique_ptr<ReQL_Obj_t> var104(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf104(new uint8_t[7]);
    const uint8_t src104[] = "Bracket";
    reql_string_init(var104.get(), buf104.get(), 7);
    reql_string_append(var104.get(), src104, 7);

    reql_object_add(var102.get(), var103.get(), var104.get());

    reql_object_add(var100.get(), var101.get(), var102.get());

    reql_object_add(var92.get(), var99.get(), var100.get());

    reql_array_append(var0.get(), var92.get());
  }

  SECTION("test91") {
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

  SECTION("test92") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test93") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test94") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test95") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test96") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test97") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test98") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test99") {
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

  SECTION("test100") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

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
    const uint8_t src11[] = "skipped";
    reql_string_init(var11.get(), buf11.get(), 7);
    reql_string_append(var11.get(), src11, 7);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test102") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf15(new uint8_t[5]);
    const uint8_t src15[] = "right";
    reql_string_init(var15.get(), buf15.get(), 5);
    reql_string_append(var15.get(), src15, 5);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[4]);
    const uint8_t src21[] = "left";
    reql_string_init(var21.get(), buf21.get(), 4);
    reql_string_append(var21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf28(new uint8_t[5]);
    const uint8_t src28[] = "right";
    reql_string_init(var28.get(), buf28.get(), 5);
    reql_string_append(var28.get(), src28, 5);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf34(new uint8_t[4]);
    const uint8_t src34[] = "left";
    reql_string_init(var34.get(), buf34.get(), 4);
    reql_string_append(var34.get(), src34, 4);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair40(new ReQL_Pair_t[2]);
    reql_object_init(var40.get(), pair40.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf41(new uint8_t[5]);
    const uint8_t src41[] = "right";
    reql_string_init(var41.get(), buf41.get(), 5);
    reql_string_append(var41.get(), src41, 5);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair42(new ReQL_Pair_t[1]);
    reql_object_init(var42.get(), pair42.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf43(new uint8_t[12]);
    const uint8_t src43[] = "reql_ast_obj";
    reql_string_init(var43.get(), buf43.get(), 12);
    reql_string_append(var43.get(), src43, 12);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair44(new ReQL_Pair_t[1]);
    reql_object_init(var44.get(), pair44.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf45(new uint8_t[12]);
    const uint8_t src45[] = "reql_ast_obj";
    reql_string_init(var45.get(), buf45.get(), 12);
    reql_string_append(var45.get(), src45, 12);

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf46(new uint8_t[7]);
    const uint8_t src46[] = "Bracket";
    reql_string_init(var46.get(), buf46.get(), 7);
    reql_string_append(var46.get(), src46, 7);

    reql_object_add(var44.get(), var45.get(), var46.get());

    reql_object_add(var42.get(), var43.get(), var44.get());

    reql_object_add(var40.get(), var41.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf47(new uint8_t[4]);
    const uint8_t src47[] = "left";
    reql_string_init(var47.get(), buf47.get(), 4);
    reql_string_append(var47.get(), src47, 4);

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair48(new ReQL_Pair_t[1]);
    reql_object_init(var48.get(), pair48.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf49(new uint8_t[12]);
    const uint8_t src49[] = "reql_ast_obj";
    reql_string_init(var49.get(), buf49.get(), 12);
    reql_string_append(var49.get(), src49, 12);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair50(new ReQL_Pair_t[1]);
    reql_object_init(var50.get(), pair50.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf51(new uint8_t[12]);
    const uint8_t src51[] = "reql_ast_obj";
    reql_string_init(var51.get(), buf51.get(), 12);
    reql_string_append(var51.get(), src51, 12);

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf52(new uint8_t[7]);
    const uint8_t src52[] = "Bracket";
    reql_string_init(var52.get(), buf52.get(), 7);
    reql_string_append(var52.get(), src52, 7);

    reql_object_add(var50.get(), var51.get(), var52.get());

    reql_object_add(var48.get(), var49.get(), var50.get());

    reql_object_add(var40.get(), var47.get(), var48.get());

    reql_array_append(var0.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair53(new ReQL_Pair_t[2]);
    reql_object_init(var53.get(), pair53.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf54(new uint8_t[5]);
    const uint8_t src54[] = "right";
    reql_string_init(var54.get(), buf54.get(), 5);
    reql_string_append(var54.get(), src54, 5);

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair55(new ReQL_Pair_t[1]);
    reql_object_init(var55.get(), pair55.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf56(new uint8_t[12]);
    const uint8_t src56[] = "reql_ast_obj";
    reql_string_init(var56.get(), buf56.get(), 12);
    reql_string_append(var56.get(), src56, 12);

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair57(new ReQL_Pair_t[1]);
    reql_object_init(var57.get(), pair57.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf58(new uint8_t[12]);
    const uint8_t src58[] = "reql_ast_obj";
    reql_string_init(var58.get(), buf58.get(), 12);
    reql_string_append(var58.get(), src58, 12);

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf59(new uint8_t[7]);
    const uint8_t src59[] = "Bracket";
    reql_string_init(var59.get(), buf59.get(), 7);
    reql_string_append(var59.get(), src59, 7);

    reql_object_add(var57.get(), var58.get(), var59.get());

    reql_object_add(var55.get(), var56.get(), var57.get());

    reql_object_add(var53.get(), var54.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf60(new uint8_t[4]);
    const uint8_t src60[] = "left";
    reql_string_init(var60.get(), buf60.get(), 4);
    reql_string_append(var60.get(), src60, 4);

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair61(new ReQL_Pair_t[1]);
    reql_object_init(var61.get(), pair61.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf62(new uint8_t[12]);
    const uint8_t src62[] = "reql_ast_obj";
    reql_string_init(var62.get(), buf62.get(), 12);
    reql_string_append(var62.get(), src62, 12);

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair63(new ReQL_Pair_t[1]);
    reql_object_init(var63.get(), pair63.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf64(new uint8_t[12]);
    const uint8_t src64[] = "reql_ast_obj";
    reql_string_init(var64.get(), buf64.get(), 12);
    reql_string_append(var64.get(), src64, 12);

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf65(new uint8_t[7]);
    const uint8_t src65[] = "Bracket";
    reql_string_init(var65.get(), buf65.get(), 7);
    reql_string_append(var65.get(), src65, 7);

    reql_object_add(var63.get(), var64.get(), var65.get());

    reql_object_add(var61.get(), var62.get(), var63.get());

    reql_object_add(var53.get(), var60.get(), var61.get());

    reql_array_append(var0.get(), var53.get());
  }

  SECTION("test103") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf2(new uint8_t[5]);
    const uint8_t src2[] = "right";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf4(new uint8_t[12]);
    const uint8_t src4[] = "reql_ast_obj";
    reql_string_init(var4.get(), buf4.get(), 12);
    reql_string_append(var4.get(), src4, 12);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf6(new uint8_t[12]);
    const uint8_t src6[] = "reql_ast_obj";
    reql_string_init(var6.get(), buf6.get(), 12);
    reql_string_append(var6.get(), src6, 12);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf7(new uint8_t[7]);
    const uint8_t src7[] = "Bracket";
    reql_string_init(var7.get(), buf7.get(), 7);
    reql_string_append(var7.get(), src7, 7);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf8(new uint8_t[4]);
    const uint8_t src8[] = "left";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf10(new uint8_t[12]);
    const uint8_t src10[] = "reql_ast_obj";
    reql_string_init(var10.get(), buf10.get(), 12);
    reql_string_append(var10.get(), src10, 12);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf12(new uint8_t[12]);
    const uint8_t src12[] = "reql_ast_obj";
    reql_string_init(var12.get(), buf12.get(), 12);
    reql_string_append(var12.get(), src12, 12);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf13(new uint8_t[7]);
    const uint8_t src13[] = "Bracket";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var1.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf15(new uint8_t[5]);
    const uint8_t src15[] = "right";
    reql_string_init(var15.get(), buf15.get(), 5);
    reql_string_append(var15.get(), src15, 5);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf17(new uint8_t[12]);
    const uint8_t src17[] = "reql_ast_obj";
    reql_string_init(var17.get(), buf17.get(), 12);
    reql_string_append(var17.get(), src17, 12);

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf19(new uint8_t[12]);
    const uint8_t src19[] = "reql_ast_obj";
    reql_string_init(var19.get(), buf19.get(), 12);
    reql_string_append(var19.get(), src19, 12);

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf20(new uint8_t[7]);
    const uint8_t src20[] = "Bracket";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf21(new uint8_t[4]);
    const uint8_t src21[] = "left";
    reql_string_init(var21.get(), buf21.get(), 4);
    reql_string_append(var21.get(), src21, 4);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair22(new ReQL_Pair_t[1]);
    reql_object_init(var22.get(), pair22.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf23(new uint8_t[12]);
    const uint8_t src23[] = "reql_ast_obj";
    reql_string_init(var23.get(), buf23.get(), 12);
    reql_string_append(var23.get(), src23, 12);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf25(new uint8_t[12]);
    const uint8_t src25[] = "reql_ast_obj";
    reql_string_init(var25.get(), buf25.get(), 12);
    reql_string_append(var25.get(), src25, 12);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf26(new uint8_t[7]);
    const uint8_t src26[] = "Bracket";
    reql_string_init(var26.get(), buf26.get(), 7);
    reql_string_append(var26.get(), src26, 7);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var21.get(), var22.get());

    reql_array_append(var0.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair27(new ReQL_Pair_t[2]);
    reql_object_init(var27.get(), pair27.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf28(new uint8_t[5]);
    const uint8_t src28[] = "right";
    reql_string_init(var28.get(), buf28.get(), 5);
    reql_string_append(var28.get(), src28, 5);

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair29(new ReQL_Pair_t[1]);
    reql_object_init(var29.get(), pair29.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf30(new uint8_t[12]);
    const uint8_t src30[] = "reql_ast_obj";
    reql_string_init(var30.get(), buf30.get(), 12);
    reql_string_append(var30.get(), src30, 12);

    std::unique_ptr<ReQL_Obj_t> var31(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair31(new ReQL_Pair_t[1]);
    reql_object_init(var31.get(), pair31.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var32(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf32(new uint8_t[12]);
    const uint8_t src32[] = "reql_ast_obj";
    reql_string_init(var32.get(), buf32.get(), 12);
    reql_string_append(var32.get(), src32, 12);

    std::unique_ptr<ReQL_Obj_t> var33(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf33(new uint8_t[7]);
    const uint8_t src33[] = "Bracket";
    reql_string_init(var33.get(), buf33.get(), 7);
    reql_string_append(var33.get(), src33, 7);

    reql_object_add(var31.get(), var32.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    reql_object_add(var27.get(), var28.get(), var29.get());

    std::unique_ptr<ReQL_Obj_t> var34(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf34(new uint8_t[4]);
    const uint8_t src34[] = "left";
    reql_string_init(var34.get(), buf34.get(), 4);
    reql_string_append(var34.get(), src34, 4);

    std::unique_ptr<ReQL_Obj_t> var35(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair35(new ReQL_Pair_t[1]);
    reql_object_init(var35.get(), pair35.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var36(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf36(new uint8_t[12]);
    const uint8_t src36[] = "reql_ast_obj";
    reql_string_init(var36.get(), buf36.get(), 12);
    reql_string_append(var36.get(), src36, 12);

    std::unique_ptr<ReQL_Obj_t> var37(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair37(new ReQL_Pair_t[1]);
    reql_object_init(var37.get(), pair37.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var38(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf38(new uint8_t[12]);
    const uint8_t src38[] = "reql_ast_obj";
    reql_string_init(var38.get(), buf38.get(), 12);
    reql_string_append(var38.get(), src38, 12);

    std::unique_ptr<ReQL_Obj_t> var39(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf39(new uint8_t[7]);
    const uint8_t src39[] = "Bracket";
    reql_string_init(var39.get(), buf39.get(), 7);
    reql_string_append(var39.get(), src39, 7);

    reql_object_add(var37.get(), var38.get(), var39.get());

    reql_object_add(var35.get(), var36.get(), var37.get());

    reql_object_add(var27.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var40(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair40(new ReQL_Pair_t[2]);
    reql_object_init(var40.get(), pair40.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var41(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf41(new uint8_t[5]);
    const uint8_t src41[] = "right";
    reql_string_init(var41.get(), buf41.get(), 5);
    reql_string_append(var41.get(), src41, 5);

    std::unique_ptr<ReQL_Obj_t> var42(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair42(new ReQL_Pair_t[1]);
    reql_object_init(var42.get(), pair42.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var43(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf43(new uint8_t[12]);
    const uint8_t src43[] = "reql_ast_obj";
    reql_string_init(var43.get(), buf43.get(), 12);
    reql_string_append(var43.get(), src43, 12);

    std::unique_ptr<ReQL_Obj_t> var44(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair44(new ReQL_Pair_t[1]);
    reql_object_init(var44.get(), pair44.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var45(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf45(new uint8_t[12]);
    const uint8_t src45[] = "reql_ast_obj";
    reql_string_init(var45.get(), buf45.get(), 12);
    reql_string_append(var45.get(), src45, 12);

    std::unique_ptr<ReQL_Obj_t> var46(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf46(new uint8_t[7]);
    const uint8_t src46[] = "Bracket";
    reql_string_init(var46.get(), buf46.get(), 7);
    reql_string_append(var46.get(), src46, 7);

    reql_object_add(var44.get(), var45.get(), var46.get());

    reql_object_add(var42.get(), var43.get(), var44.get());

    reql_object_add(var40.get(), var41.get(), var42.get());

    std::unique_ptr<ReQL_Obj_t> var47(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf47(new uint8_t[4]);
    const uint8_t src47[] = "left";
    reql_string_init(var47.get(), buf47.get(), 4);
    reql_string_append(var47.get(), src47, 4);

    std::unique_ptr<ReQL_Obj_t> var48(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair48(new ReQL_Pair_t[1]);
    reql_object_init(var48.get(), pair48.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var49(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf49(new uint8_t[12]);
    const uint8_t src49[] = "reql_ast_obj";
    reql_string_init(var49.get(), buf49.get(), 12);
    reql_string_append(var49.get(), src49, 12);

    std::unique_ptr<ReQL_Obj_t> var50(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair50(new ReQL_Pair_t[1]);
    reql_object_init(var50.get(), pair50.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var51(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf51(new uint8_t[12]);
    const uint8_t src51[] = "reql_ast_obj";
    reql_string_init(var51.get(), buf51.get(), 12);
    reql_string_append(var51.get(), src51, 12);

    std::unique_ptr<ReQL_Obj_t> var52(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf52(new uint8_t[7]);
    const uint8_t src52[] = "Bracket";
    reql_string_init(var52.get(), buf52.get(), 7);
    reql_string_append(var52.get(), src52, 7);

    reql_object_add(var50.get(), var51.get(), var52.get());

    reql_object_add(var48.get(), var49.get(), var50.get());

    reql_object_add(var40.get(), var47.get(), var48.get());

    reql_array_append(var0.get(), var40.get());

    std::unique_ptr<ReQL_Obj_t> var53(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair53(new ReQL_Pair_t[2]);
    reql_object_init(var53.get(), pair53.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var54(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf54(new uint8_t[5]);
    const uint8_t src54[] = "right";
    reql_string_init(var54.get(), buf54.get(), 5);
    reql_string_append(var54.get(), src54, 5);

    std::unique_ptr<ReQL_Obj_t> var55(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair55(new ReQL_Pair_t[1]);
    reql_object_init(var55.get(), pair55.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var56(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf56(new uint8_t[12]);
    const uint8_t src56[] = "reql_ast_obj";
    reql_string_init(var56.get(), buf56.get(), 12);
    reql_string_append(var56.get(), src56, 12);

    std::unique_ptr<ReQL_Obj_t> var57(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair57(new ReQL_Pair_t[1]);
    reql_object_init(var57.get(), pair57.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var58(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf58(new uint8_t[12]);
    const uint8_t src58[] = "reql_ast_obj";
    reql_string_init(var58.get(), buf58.get(), 12);
    reql_string_append(var58.get(), src58, 12);

    std::unique_ptr<ReQL_Obj_t> var59(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf59(new uint8_t[7]);
    const uint8_t src59[] = "Bracket";
    reql_string_init(var59.get(), buf59.get(), 7);
    reql_string_append(var59.get(), src59, 7);

    reql_object_add(var57.get(), var58.get(), var59.get());

    reql_object_add(var55.get(), var56.get(), var57.get());

    reql_object_add(var53.get(), var54.get(), var55.get());

    std::unique_ptr<ReQL_Obj_t> var60(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf60(new uint8_t[4]);
    const uint8_t src60[] = "left";
    reql_string_init(var60.get(), buf60.get(), 4);
    reql_string_append(var60.get(), src60, 4);

    std::unique_ptr<ReQL_Obj_t> var61(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair61(new ReQL_Pair_t[1]);
    reql_object_init(var61.get(), pair61.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var62(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf62(new uint8_t[12]);
    const uint8_t src62[] = "reql_ast_obj";
    reql_string_init(var62.get(), buf62.get(), 12);
    reql_string_append(var62.get(), src62, 12);

    std::unique_ptr<ReQL_Obj_t> var63(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair63(new ReQL_Pair_t[1]);
    reql_object_init(var63.get(), pair63.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var64(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf64(new uint8_t[12]);
    const uint8_t src64[] = "reql_ast_obj";
    reql_string_init(var64.get(), buf64.get(), 12);
    reql_string_append(var64.get(), src64, 12);

    std::unique_ptr<ReQL_Obj_t> var65(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf65(new uint8_t[7]);
    const uint8_t src65[] = "Bracket";
    reql_string_init(var65.get(), buf65.get(), 7);
    reql_string_append(var65.get(), src65, 7);

    reql_object_add(var63.get(), var64.get(), var65.get());

    reql_object_add(var61.get(), var62.get(), var63.get());

    reql_object_add(var53.get(), var60.get(), var61.get());

    reql_array_append(var0.get(), var53.get());
  }

  SECTION("test104") {
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

  SECTION("test105") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test106") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test107") {
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

  SECTION("test108") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test109") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test110") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test111") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test112") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test113") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test114") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test115") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test116") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test117") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test118") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test119") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test120") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test121") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test122") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test123") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test124") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test125") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test126") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test127") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test128") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test129") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test130") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test131") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test132") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test133") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test134") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test135") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test136") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test137") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test138") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test139") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test140") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test141") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test142") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test143") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test144") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test145") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test146") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test147") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test148") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test149") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test150") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test151") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test152") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test153") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test154") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test155") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test156") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test157") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test158") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test159") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test160") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test161") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test162") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test163") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test164") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test165") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test166") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test167") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test168") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test169") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test170") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test171") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test172") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test173") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test174") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test175") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test176") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test177") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test178") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test179") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test180") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test181") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 4);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test182") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test183") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test184") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test185") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test186") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test187") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 4);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test188") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test189") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test190") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test191") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test192") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test193") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test194") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test195") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test196") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test197") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test198") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test199") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test200") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test201") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test202") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test203") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test204") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test205") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test206") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test207") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test208") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test209") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test210") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_null_init(var0.get());
  }

  SECTION("test211") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test212") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test213") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test214") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test215") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test216") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test217") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test218") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test219") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test220") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test221") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test222") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test223") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test224") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test225") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test226") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test227") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test228") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test229") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test230") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test231") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test232") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test233") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test234") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test235") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test236") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test237") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test238") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test239") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test240") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test241") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test242") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test243") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test244") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test245") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test246") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test247") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test248") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test249") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test250") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 4);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test251") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test252") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test253") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test254") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test255") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test256") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test257") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test258") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test259") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test260") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test261") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test262") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test263") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test264") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test265") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test266") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test267") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test268") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test269") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test270") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test271") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test272") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test273") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test274") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test275") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test276") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test277") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test278") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test279") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test280") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test281") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test282") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test283") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test284") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test285") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test286") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test287") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test288") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test289") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test290") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test291") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test292") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test293") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test294") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test295") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test296") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test297") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test298") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test299") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test300") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test301") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test302") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test303") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test304") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test305") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test306") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test307") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test308") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test309") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test310") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test311") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test312") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[13]);
    reql_array_init(var0.get(), arr0.get(), 13);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 1);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 1);

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2);

    reql_array_append(var0.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 3);

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 3);

    reql_array_append(var0.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 3);

    reql_array_append(var0.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 4);

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 4);

    reql_array_append(var0.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 4);

    reql_array_append(var0.get(), var13.get());
  }

  SECTION("test313") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*> arr0(new ReQL_Obj_t*[13]);
    reql_array_init(var0.get(), arr0.get(), 13);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 1);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 1);

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 2);

    reql_array_append(var0.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 3);

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 3);

    reql_array_append(var0.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 3);

    reql_array_append(var0.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 4);

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 4);

    reql_array_append(var0.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 4);

    reql_array_append(var0.get(), var13.get());
  }
}
