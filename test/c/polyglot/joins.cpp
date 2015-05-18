// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests that manipulation data in tables 10", "[c][ast]") {

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

  SECTION("test2") {
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

  SECTION("test3") {
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
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 2500);
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 2500);
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 2);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "a";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 3);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "b";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 3);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

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
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[2]);
    reql_object_init(var4.get(), pair4.get(), 2);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "a";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_object_add(var4.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "b";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_object_add(var4.get(), var7.get(), var8.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var9;
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[2]);
    reql_object_init(var9.get(), pair9.get(), 2);

    ReQL_Obj_c var10;
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "a";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 3);

    reql_object_add(var9.get(), var10.get(), var11.get());

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "b";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 3);

    reql_object_add(var9.get(), var12.get(), var13.get());

    reql_array_append(var0.get(), var9.get());
  }

  SECTION("test28") {
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
