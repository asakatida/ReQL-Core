// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests that manipulation data in tables 26", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0.0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0.0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 100);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0.0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0.0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0.0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[6]);
    const uint8_t src1[] = "result";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "blank";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0.0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0.0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 100);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0.0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0.0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0.0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0.0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0.0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 100);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0.0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0.0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0.0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 4950);
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 9900);
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 9900);
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 9900);
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 200);
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test20") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test24") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test25") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test26") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 5);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test27") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test28") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test29") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test30") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test31") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test32") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test33") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test34") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test35") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test36") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test37") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 96);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test38") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 96);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test39") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[16]);
    const uint8_t src0[] = "SELECTION<ARRAY>";
    reql_string_init(var0.get(), buf0.get(), 16);
    reql_string_append(var0.get(), src0, 16);
  }

  SECTION("test40") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test41") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test42") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test43") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test44") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test45") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test46") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test47") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 99);
  }

  SECTION("test48") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test49") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test50") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test51") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test52") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test53") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 2);
  }

  SECTION("test54") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 95);
  }

  SECTION("test55") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test56") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test57") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test58") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test59") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test60") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test61") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 8);
  }

  SECTION("test62") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 9);
  }

  SECTION("test63") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 7);
  }

  SECTION("test64") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 8);
  }

  SECTION("test65") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test66") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 88);
  }

  SECTION("test67") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test68") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test69") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test70") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test71") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 8);
  }

  SECTION("test72") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 9);
  }

  SECTION("test73") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 7);
  }

  SECTION("test74") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 8);
  }

  SECTION("test75") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 87);
  }

  SECTION("test76") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 88);
  }

  SECTION("test77") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 86);
  }

  SECTION("test78") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 87);
  }

  SECTION("test79") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 10);
  }

  SECTION("test80") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 11);
  }

  SECTION("test83") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test85") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test86") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 5);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test87") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test88") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 1);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test89") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test90") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test91") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test92") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test93") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test94") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test95") {
    ReQL_Obj_c var0;
    reql_object_init(var0.get(), nullptr, 0);
  }

  SECTION("test96") {
    ReQL_Obj_c var0;
    reql_object_init(var0.get(), nullptr, 0);
  }

  SECTION("test97") {
    ReQL_Obj_c var0;
    reql_object_init(var0.get(), nullptr, 0);
  }

  SECTION("test98") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test99") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test100") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test101") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test102") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test103") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test104") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test105") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test106") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test107") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "b";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "c";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[2]);
    const uint8_t src5[] = "id";
    reql_string_init(var5.get(), buf5.get(), 2);
    reql_string_append(var5.get(), src5, 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test108") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "b";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "c";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[2]);
    const uint8_t src5[] = "id";
    reql_string_init(var5.get(), buf5.get(), 2);
    reql_string_append(var5.get(), src5, 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test109") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test110") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test111") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "b";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test112") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[3]);
    const uint8_t src1[] = "foo";
    reql_string_init(var1.get(), buf1.get(), 3);
    reql_string_append(var1.get(), src1, 3);

    ReQL_Obj_c var2;
    reql_object_init(var2.get(), nullptr, 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test113") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test114") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test115") {
    ReQL_Obj_c var0;
    reql_object_init(var0.get(), nullptr, 0);
  }

  SECTION("test116") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test117") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "b";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_object_init(var2.get(), nullptr, 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test118") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "b";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_object_init(var2.get(), nullptr, 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test119") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "b";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "c";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[2]);
    const uint8_t src5[] = "id";
    reql_string_init(var5.get(), buf5.get(), 2);
    reql_string_append(var5.get(), src5, 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test120") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[17]);
    const uint8_t src0[] = "SELECTION<STREAM>";
    reql_string_init(var0.get(), buf0.get(), 17);
    reql_string_append(var0.get(), src0, 17);
  }

  SECTION("test121") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[5]);
    const uint8_t src0[] = "ARRAY";
    reql_string_init(var0.get(), buf0.get(), 5);
    reql_string_append(var0.get(), src0, 5);
  }

  SECTION("test122") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 200);
  }

  SECTION("test123") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 103);
  }

  SECTION("test124") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 103);
  }

  SECTION("test125") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test126") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test127") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test128") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test129") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test130") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test133") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test134") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test135") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test136") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[2]);
    const uint8_t src1[] = "id";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test137") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test138") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
