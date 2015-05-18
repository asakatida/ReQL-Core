// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests RQL json parsing", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    reql_object_init(var0.get(), nullptr, 0);
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[3]);
    const uint8_t src0[] = "foo";
    reql_string_init(var0.get(), buf0.get(), 3);
    reql_string_append(var0.get(), src0, 3);
  }

  SECTION("test4") {
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

  SECTION("test5") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[7]);
    const uint8_t src0[] = "[1,2,3]";
    reql_string_init(var0.get(), buf0.get(), 7);
    reql_string_append(var0.get(), src0, 7);
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[7]);
    const uint8_t src0[] = "[1,2,3]";
    reql_string_init(var0.get(), buf0.get(), 7);
    reql_string_append(var0.get(), src0, 7);
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[11]);
    const uint8_t src0[] = "{\"foo\":4}";
    reql_string_init(var0.get(), buf0.get(), 11);
    reql_string_append(var0.get(), src0, 11);
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[11]);
    const uint8_t src0[] = "{\"foo\":4}";
    reql_string_init(var0.get(), buf0.get(), 11);
    reql_string_append(var0.get(), src0, 11);
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[6]);
    const uint8_t src2[] = "sorted";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test12") {
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

  SECTION("test13") {
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

  SECTION("test14") {
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

  SECTION("test15") {
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

  SECTION("test16") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "TIME";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[10]);
    const uint8_t src3[] = "epoch_time";
    reql_string_init(var3.get(), buf3.get(), 10);
    reql_string_append(var3.get(), src3, 10);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 1410393600);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[8]);
    const uint8_t src5[] = "timezone";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[6]);
    const uint8_t src6[] = "+00:00";
    reql_string_init(var6.get(), buf6.get(), 6);
    reql_string_append(var6.get(), src6, 6);

    reql_object_add(var0.get(), var5.get(), var6.get());
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[76]);
    const uint8_t src0[] = "{\"$reql_type$\":\"TIME\",\"epoch_time\":1410393600,\"timezone\":\"+00:00\"}";
    reql_string_init(var0.get(), buf0.get(), 76);
    reql_string_append(var0.get(), src0, 76);
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var4.get(), var6.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[4]);
    const uint8_t src7[] = "type";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    ReQL_Obj_c var8;
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[5]);
    const uint8_t src8[] = "Point";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    reql_object_add(var0.get(), var7.get(), var8.get());
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[71]);
    const uint8_t src0[] = "{\"$reql_type$\":\"GEOMETRY\",\"coordinates\":[0,0],\"type\":\"Point\"}";
    reql_string_init(var0.get(), buf0.get(), 71);
    reql_string_append(var0.get(), src0, 71);
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "s";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[46]);
    const uint8_t src0[] = "{\"$reql_type$\":\"BINARY\",\"data\":\"Zm9v\"}";
    reql_string_init(var0.get(), buf0.get(), 46);
    reql_string_append(var0.get(), src0, 46);
  }
}
