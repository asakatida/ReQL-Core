// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("c Tests conversion to and from the RQL array type 259", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 5);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[5]);
    const uint8_t src0[] = "ARRAY";
    reql_string_init(var0.get(), buf0.get(), 5);
    reql_string_append(var0.get(), src0, 5);
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[6]);
    const uint8_t src0[] = "[1, 2]";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test6") {
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

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test13") {
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

  SECTION("test16") {
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

  SECTION("test17") {
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

  SECTION("test18") {
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

  SECTION("test19") {
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

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test24") {
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

  SECTION("test27") {
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

  SECTION("test28") {
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

  SECTION("test29") {
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

  SECTION("test30") {
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

  SECTION("test31") {
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

  SECTION("test32") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test33") {
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

  SECTION("test36") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test37") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test38") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test39") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test40") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test41") {
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

  SECTION("test42") {
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

  SECTION("test43") {
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

  SECTION("test44") {
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

  SECTION("test45") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test46") {
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

  SECTION("test49") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test51") {
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

  SECTION("test52") {
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

  SECTION("test53") {
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

  SECTION("test54") {
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
