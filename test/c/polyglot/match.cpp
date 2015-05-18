// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests for match", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[4]);
    reql_object_init(var0.get(), pair0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[3]);
    const uint8_t src1[] = "end";
    reql_string_init(var1.get(), buf1.get(), 3);
    reql_string_append(var1.get(), src1, 3);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 5);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "groups";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_null_init(var5.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[3]);
    reql_object_init(var6.get(), pair6.get(), 3);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[3]);
    const uint8_t src7[] = "end";
    reql_string_init(var7.get(), buf7.get(), 3);
    reql_string_append(var7.get(), src7, 3);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 5);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[5]);
    const uint8_t src9[] = "start";
    reql_string_init(var9.get(), buf9.get(), 5);
    reql_string_append(var9.get(), src9, 5);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 2);

    reql_object_add(var6.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[3]);
    const uint8_t src11[] = "str";
    reql_string_init(var11.get(), buf11.get(), 3);
    reql_string_append(var11.get(), src11, 3);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[3]);
    const uint8_t src12[] = "cde";
    reql_string_init(var12.get(), buf12.get(), 3);
    reql_string_append(var12.get(), src12, 3);

    reql_object_add(var6.get(), var11.get(), var12.get());

    reql_array_append(var4.get(), var6.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[5]);
    const uint8_t src13[] = "start";
    reql_string_init(var13.get(), buf13.get(), 5);
    reql_string_append(var13.get(), src13, 5);

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 1);

    reql_object_add(var0.get(), var13.get(), var14.get());

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[3]);
    const uint8_t src15[] = "str";
    reql_string_init(var15.get(), buf15.get(), 3);
    reql_string_append(var15.get(), src15, 3);

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[4]);
    const uint8_t src16[] = "bcde";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    reql_object_add(var0.get(), var15.get(), var16.get());
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    reql_null_init(var0.get());
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[4]);
    reql_object_init(var0.get(), pair0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[3]);
    const uint8_t src1[] = "end";
    reql_string_init(var1.get(), buf1.get(), 3);
    reql_string_append(var1.get(), src1, 3);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 5);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "groups";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_null_init(var5.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[3]);
    reql_object_init(var6.get(), pair6.get(), 3);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[3]);
    const uint8_t src7[] = "end";
    reql_string_init(var7.get(), buf7.get(), 3);
    reql_string_append(var7.get(), src7, 3);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 5);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[5]);
    const uint8_t src9[] = "start";
    reql_string_init(var9.get(), buf9.get(), 5);
    reql_string_append(var9.get(), src9, 5);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 2);

    reql_object_add(var6.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[3]);
    const uint8_t src11[] = "str";
    reql_string_init(var11.get(), buf11.get(), 3);
    reql_string_append(var11.get(), src11, 3);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[3]);
    const uint8_t src12[] = "cde";
    reql_string_init(var12.get(), buf12.get(), 3);
    reql_string_append(var12.get(), src12, 3);

    reql_object_add(var6.get(), var11.get(), var12.get());

    reql_array_append(var4.get(), var6.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[5]);
    const uint8_t src13[] = "start";
    reql_string_init(var13.get(), buf13.get(), 5);
    reql_string_append(var13.get(), src13, 5);

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 1);

    reql_object_add(var0.get(), var13.get(), var14.get());

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[3]);
    const uint8_t src15[] = "str";
    reql_string_init(var15.get(), buf15.get(), 3);
    reql_string_append(var15.get(), src15, 3);

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[4]);
    const uint8_t src16[] = "bcde";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    reql_object_add(var0.get(), var15.get(), var16.get());
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[3]);
    const uint8_t src1[] = "aca";
    reql_string_init(var1.get(), buf1.get(), 3);
    reql_string_append(var1.get(), src1, 3);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "ada";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[6]);
    reql_object_init(var0.get(), pair0.get(), 6);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "deleted";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0.0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = "errors";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0.0);

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[8]);
    const uint8_t src5[] = "inserted";
    reql_string_init(var5.get(), buf5.get(), 8);
    reql_string_append(var5.get(), src5, 8);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 3);

    reql_object_add(var0.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[8]);
    const uint8_t src7[] = "replaced";
    reql_string_init(var7.get(), buf7.get(), 8);
    reql_string_append(var7.get(), src7, 8);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0.0);

    reql_object_add(var0.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[7]);
    const uint8_t src9[] = "skipped";
    reql_string_init(var9.get(), buf9.get(), 7);
    reql_string_append(var9.get(), src9, 7);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0.0);

    reql_object_add(var0.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[9]);
    const uint8_t src11[] = "unchanged";
    reql_string_init(var11.get(), buf11.get(), 9);
    reql_string_append(var11.get(), src11, 9);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0.0);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[3]);
    const uint8_t src3[] = "abc";
    reql_string_init(var3.get(), buf3.get(), 3);
    reql_string_append(var3.get(), src3, 3);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[2]);
    const uint8_t src4[] = "id";
    reql_string_init(var4.get(), buf4.get(), 2);
    reql_string_append(var4.get(), src4, 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 0);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[1]);
    const uint8_t src7[] = "a";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[2]);
    const uint8_t src8[] = "ab";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[2]);
    const uint8_t src9[] = "id";
    reql_string_init(var9.get(), buf9.get(), 2);
    reql_string_append(var9.get(), src9, 2);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[1]);
    const uint8_t src12[] = "a";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[2]);
    const uint8_t src13[] = "bc";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[2]);
    const uint8_t src14[] = "id";
    reql_string_init(var14.get(), buf14.get(), 2);
    reql_string_append(var14.get(), src14, 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 2);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[3]);
    const uint8_t src3[] = "abc";
    reql_string_init(var3.get(), buf3.get(), 3);
    reql_string_append(var3.get(), src3, 3);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[2]);
    const uint8_t src4[] = "id";
    reql_string_init(var4.get(), buf4.get(), 2);
    reql_string_append(var4.get(), src4, 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 0);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[1]);
    const uint8_t src7[] = "a";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[2]);
    const uint8_t src8[] = "ab";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[2]);
    const uint8_t src9[] = "id";
    reql_string_init(var9.get(), buf9.get(), 2);
    reql_string_append(var9.get(), src9, 2);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "ab";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[2]);
    const uint8_t src4[] = "id";
    reql_string_init(var4.get(), buf4.get(), 2);
    reql_string_append(var4.get(), src4, 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
