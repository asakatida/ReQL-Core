// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("c Issue", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "ready";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_bool_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[5]);
    const uint8_t src4[] = "index";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "x";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[5]);
    const uint8_t src1[] = "value";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "None";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[4]);
    const uint8_t src3[] = "type";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[4]);
    const uint8_t src4[] = "NULL";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[5]);
    const uint8_t src1[] = "value";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[4]);
    const uint8_t src2[] = "True";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[4]);
    const uint8_t src3[] = "type";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[4]);
    const uint8_t src4[] = "BOOL";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[5]);
    const uint8_t src1[] = "value";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "1";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[4]);
    const uint8_t src3[] = "type";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[6]);
    const uint8_t src4[] = "NUMBER";
    reql_string_init(var4.get(), buf4.get(), 6);
    reql_string_append(var4.get(), src4, 6);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[5]);
    const uint8_t src1[] = "value";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[5]);
    const uint8_t src2[] = "\"1\"";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[4]);
    const uint8_t src3[] = "type";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[6]);
    const uint8_t src4[] = "STRING";
    reql_string_init(var4.get(), buf4.get(), 6);
    reql_string_append(var4.get(), src4, 6);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[5]);
    const uint8_t src1[] = "value";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "[1]";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[4]);
    const uint8_t src3[] = "type";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[5]);
    const uint8_t src4[] = "ARRAY";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[5]);
    const uint8_t src1[] = "value";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[17]);
    const uint8_t src2[] = "{\n\t\"a\":\t1\n}";
    reql_string_init(var2.get(), buf2.get(), 17);
    reql_string_append(var2.get(), src2, 17);

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[4]);
    const uint8_t src3[] = "type";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[6]);
    const uint8_t src4[] = "OBJECT";
    reql_string_init(var4.get(), buf4.get(), 6);
    reql_string_append(var4.get(), src4, 6);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "indexes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "x";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[11]);
    const uint8_t src4[] = "primary_key";
    reql_string_init(var4.get(), buf4.get(), 11);
    reql_string_append(var4.get(), src4, 11);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[2]);
    const uint8_t src5[] = "id";
    reql_string_init(var5.get(), buf5.get(), 2);
    reql_string_append(var5.get(), src5, 2);

    reql_object_add(var0.get(), var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[4]);
    const uint8_t src6[] = "name";
    reql_string_init(var6.get(), buf6.get(), 4);
    reql_string_append(var6.get(), src6, 4);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[4]);
    const uint8_t src7[] = "t469";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    reql_object_add(var0.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[4]);
    const uint8_t src8[] = "type";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[5]);
    const uint8_t src9[] = "TABLE";
    reql_string_init(var9.get(), buf9.get(), 5);
    reql_string_append(var9.get(), src9, 5);

    reql_object_add(var0.get(), var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[2]);
    const uint8_t src10[] = "db";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[3]);
    reql_object_init(var11.get(), pair11.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair13(new ReQL_Pair_t[1]);
    reql_object_init(var13.get(), pair13.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[4]);
    const uint8_t src14[] = "func";
    reql_string_init(var14.get(), buf14.get(), 4);
    reql_string_append(var14.get(), src14, 4);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[4]);
    const uint8_t src15[] = "uuid";
    reql_string_init(var15.get(), buf15.get(), 4);
    reql_string_append(var15.get(), src15, 4);

    reql_object_add(var13.get(), var14.get(), var15.get());

    reql_object_add(var11.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "name";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[4]);
    const uint8_t src17[] = "d469";
    reql_string_init(var17.get(), buf17.get(), 4);
    reql_string_append(var17.get(), src17, 4);

    reql_object_add(var11.get(), var16.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[4]);
    const uint8_t src18[] = "type";
    reql_string_init(var18.get(), buf18.get(), 4);
    reql_string_append(var18.get(), src18, 4);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[2]);
    const uint8_t src19[] = "DB";
    reql_string_init(var19.get(), buf19.get(), 2);
    reql_string_append(var19.get(), src19, 2);

    reql_object_add(var11.get(), var18.get(), var19.get());

    reql_object_add(var0.get(), var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf20(new uint8_t[19]);
    const uint8_t src20[] = "doc_count_estimates";
    reql_string_init(var20.get(), buf20.get(), 19);
    reql_string_append(var20.get(), src20, 19);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr21(new ReQL_Obj_t*[1]);
    reql_array_init(var21.get(), arr21.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    reql_number_init(var22.get(), 0);

    reql_array_append(var21.get(), var22.get());

    reql_object_add(var0.get(), var20.get(), var21.get());

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf23(new uint8_t[2]);
    const uint8_t src23[] = "id";
    reql_string_init(var23.get(), buf23.get(), 2);
    reql_string_append(var23.get(), src23, 2);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf25(new uint8_t[4]);
    const uint8_t src25[] = "func";
    reql_string_init(var25.get(), buf25.get(), 4);
    reql_string_append(var25.get(), src25, 4);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf26(new uint8_t[4]);
    const uint8_t src26[] = "uuid";
    reql_string_init(var26.get(), buf26.get(), 4);
    reql_string_append(var26.get(), src26, 4);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var0.get(), var23.get(), var24.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[5]);
    const uint8_t src1[] = "table";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[7]);
    reql_object_init(var2.get(), pair2.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[7]);
    const uint8_t src3[] = "indexes";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "x";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var2.get(), var3.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[11]);
    const uint8_t src6[] = "primary_key";
    reql_string_init(var6.get(), buf6.get(), 11);
    reql_string_append(var6.get(), src6, 11);

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[2]);
    const uint8_t src7[] = "id";
    reql_string_init(var7.get(), buf7.get(), 2);
    reql_string_append(var7.get(), src7, 2);

    reql_object_add(var2.get(), var6.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[4]);
    const uint8_t src8[] = "name";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[4]);
    const uint8_t src9[] = "t469";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    reql_object_add(var2.get(), var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[4]);
    const uint8_t src10[] = "type";
    reql_string_init(var10.get(), buf10.get(), 4);
    reql_string_append(var10.get(), src10, 4);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[5]);
    const uint8_t src11[] = "TABLE";
    reql_string_init(var11.get(), buf11.get(), 5);
    reql_string_append(var11.get(), src11, 5);

    reql_object_add(var2.get(), var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[2]);
    const uint8_t src12[] = "db";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair13(new ReQL_Pair_t[3]);
    reql_object_init(var13.get(), pair13.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[2]);
    const uint8_t src14[] = "id";
    reql_string_init(var14.get(), buf14.get(), 2);
    reql_string_append(var14.get(), src14, 2);

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair15(new ReQL_Pair_t[1]);
    reql_object_init(var15.get(), pair15.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf16(new uint8_t[4]);
    const uint8_t src16[] = "func";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[4]);
    const uint8_t src17[] = "uuid";
    reql_string_init(var17.get(), buf17.get(), 4);
    reql_string_append(var17.get(), src17, 4);

    reql_object_add(var15.get(), var16.get(), var17.get());

    reql_object_add(var13.get(), var14.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[4]);
    const uint8_t src18[] = "name";
    reql_string_init(var18.get(), buf18.get(), 4);
    reql_string_append(var18.get(), src18, 4);

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[4]);
    const uint8_t src19[] = "d469";
    reql_string_init(var19.get(), buf19.get(), 4);
    reql_string_append(var19.get(), src19, 4);

    reql_object_add(var13.get(), var18.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf20(new uint8_t[4]);
    const uint8_t src20[] = "type";
    reql_string_init(var20.get(), buf20.get(), 4);
    reql_string_append(var20.get(), src20, 4);

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf21(new uint8_t[2]);
    const uint8_t src21[] = "DB";
    reql_string_init(var21.get(), buf21.get(), 2);
    reql_string_append(var21.get(), src21, 2);

    reql_object_add(var13.get(), var20.get(), var21.get());

    reql_object_add(var2.get(), var12.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf22(new uint8_t[19]);
    const uint8_t src22[] = "doc_count_estimates";
    reql_string_init(var22.get(), buf22.get(), 19);
    reql_string_append(var22.get(), src22, 19);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr23(new ReQL_Obj_t*[1]);
    reql_array_init(var23.get(), arr23.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 0);

    reql_array_append(var23.get(), var24.get());

    reql_object_add(var2.get(), var22.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf25(new uint8_t[2]);
    const uint8_t src25[] = "id";
    reql_string_init(var25.get(), buf25.get(), 2);
    reql_string_append(var25.get(), src25, 2);

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair26(new ReQL_Pair_t[1]);
    reql_object_init(var26.get(), pair26.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf27(new uint8_t[4]);
    const uint8_t src27[] = "func";
    reql_string_init(var27.get(), buf27.get(), 4);
    reql_string_append(var27.get(), src27, 4);

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf28(new uint8_t[4]);
    const uint8_t src28[] = "uuid";
    reql_string_init(var28.get(), buf28.get(), 4);
    reql_string_append(var28.get(), src28, 4);

    reql_object_add(var26.get(), var27.get(), var28.get());

    reql_object_add(var2.get(), var25.get(), var26.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var29(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf29(new uint8_t[4]);
    const uint8_t src29[] = "type";
    reql_string_init(var29.get(), buf29.get(), 4);
    reql_string_append(var29.get(), src29, 4);

    std::unique_ptr<ReQL_Obj_t> var30(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf30(new uint8_t[17]);
    const uint8_t src30[] = "SELECTION<STREAM>";
    reql_string_init(var30.get(), buf30.get(), 17);
    reql_string_append(var30.get(), src30, 17);

    reql_object_add(var0.get(), var29.get(), var30.get());
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[6]);
    const uint8_t src2[] = "STREAM";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
