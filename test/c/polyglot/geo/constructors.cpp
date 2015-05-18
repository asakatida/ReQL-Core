// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test geo constructors", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var4.get(), var6.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[4]);
    const uint8_t src7[] = "type";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "Point";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    reql_object_add(var0.get(), var7.get(), var8.get());
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), -90);

    reql_array_append(var4.get(), var6.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[4]);
    const uint8_t src7[] = "type";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "Point";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    reql_object_add(var0.get(), var7.get(), var8.get());
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 0);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 90);

    reql_array_append(var4.get(), var6.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[4]);
    const uint8_t src7[] = "type";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "Point";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    reql_object_add(var0.get(), var7.get(), var8.get());
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), -180);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var4.get(), var6.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[4]);
    const uint8_t src7[] = "type";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "Point";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    reql_object_add(var0.get(), var7.get(), var8.get());
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 180);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var4.get(), var6.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[4]);
    const uint8_t src7[] = "type";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[5]);
    const uint8_t src8[] = "Point";
    reql_string_init(var8.get(), buf8.get(), 5);
    reql_string_append(var8.get(), src8, 5);

    reql_object_add(var0.get(), var7.get(), var8.get());
  }

  SECTION("test5") {
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

  SECTION("test6") {
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

  SECTION("test7") {
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

  SECTION("test8") {
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

  SECTION("test10") {
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

  SECTION("test11") {
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

  SECTION("test12") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[4]);
    const uint8_t src11[] = "type";
    reql_string_init(var11.get(), buf11.get(), 4);
    reql_string_append(var11.get(), src11, 4);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[10]);
    const uint8_t src12[] = "LineString";
    reql_string_init(var12.get(), buf12.get(), 10);
    reql_string_append(var12.get(), src12, 10);

    reql_object_add(var0.get(), var11.get(), var12.get());
  }

  SECTION("test13") {
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

  SECTION("test14") {
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

  SECTION("test15") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[3]);
    reql_array_init(var4.get(), arr4.get(), 3);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[4]);
    const uint8_t src14[] = "type";
    reql_string_init(var14.get(), buf14.get(), 4);
    reql_string_append(var14.get(), src14, 4);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[10]);
    const uint8_t src15[] = "LineString";
    reql_string_init(var15.get(), buf15.get(), 10);
    reql_string_append(var15.get(), src15, 10);

    reql_object_add(var0.get(), var14.get(), var15.get());
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[3]);
    reql_array_init(var4.get(), arr4.get(), 3);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 0);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[4]);
    const uint8_t src14[] = "type";
    reql_string_init(var14.get(), buf14.get(), 4);
    reql_string_append(var14.get(), src14, 4);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[10]);
    const uint8_t src15[] = "LineString";
    reql_string_init(var15.get(), buf15.get(), 10);
    reql_string_append(var15.get(), src15, 10);

    reql_object_add(var0.get(), var14.get(), var15.get());
  }

  SECTION("test17") {
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

  SECTION("test18") {
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

  SECTION("test19") {
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

  SECTION("test20") {
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

  SECTION("test21") {
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

  SECTION("test22") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[4]);
    reql_array_init(var5.get(), arr5.get(), 4);

    ReQL_Obj_c var6;
    _C::CTypes::array arr6(new ReQL_Obj_t*[2]);
    reql_array_init(var6.get(), arr6.get(), 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_array_append(var6.get(), var7.get());

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_array_append(var6.get(), var8.get());

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var9;
    _C::CTypes::array arr9(new ReQL_Obj_t*[2]);
    reql_array_init(var9.get(), arr9.get(), 2);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_array_append(var9.get(), var10.get());

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 1);

    reql_array_append(var9.get(), var11.get());

    reql_array_append(var5.get(), var9.get());

    ReQL_Obj_c var12;
    _C::CTypes::array arr12(new ReQL_Obj_t*[2]);
    reql_array_init(var12.get(), arr12.get(), 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1);

    reql_array_append(var12.get(), var13.get());

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 0);

    reql_array_append(var12.get(), var14.get());

    reql_array_append(var5.get(), var12.get());

    ReQL_Obj_c var15;
    _C::CTypes::array arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 0);

    reql_array_append(var15.get(), var16.get());

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 0);

    reql_array_append(var15.get(), var17.get());

    reql_array_append(var5.get(), var15.get());

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var18;
    _C::CTypes::string buf18(new uint8_t[4]);
    const uint8_t src18[] = "type";
    reql_string_init(var18.get(), buf18.get(), 4);
    reql_string_append(var18.get(), src18, 4);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[7]);
    const uint8_t src19[] = "Polygon";
    reql_string_init(var19.get(), buf19.get(), 7);
    reql_string_append(var19.get(), src19, 7);

    reql_object_add(var0.get(), var18.get(), var19.get());
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[3]);
    reql_object_init(var0.get(), pair0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[8]);
    const uint8_t src2[] = "GEOMETRY";
    reql_string_init(var2.get(), buf2.get(), 8);
    reql_string_append(var2.get(), src2, 8);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "coordinates";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[4]);
    reql_array_init(var5.get(), arr5.get(), 4);

    ReQL_Obj_c var6;
    _C::CTypes::array arr6(new ReQL_Obj_t*[2]);
    reql_array_init(var6.get(), arr6.get(), 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_array_append(var6.get(), var7.get());

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 0);

    reql_array_append(var6.get(), var8.get());

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var9;
    _C::CTypes::array arr9(new ReQL_Obj_t*[2]);
    reql_array_init(var9.get(), arr9.get(), 2);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 0);

    reql_array_append(var9.get(), var10.get());

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 1);

    reql_array_append(var9.get(), var11.get());

    reql_array_append(var5.get(), var9.get());

    ReQL_Obj_c var12;
    _C::CTypes::array arr12(new ReQL_Obj_t*[2]);
    reql_array_init(var12.get(), arr12.get(), 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1);

    reql_array_append(var12.get(), var13.get());

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 0);

    reql_array_append(var12.get(), var14.get());

    reql_array_append(var5.get(), var12.get());

    ReQL_Obj_c var15;
    _C::CTypes::array arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 0);

    reql_array_append(var15.get(), var16.get());

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 0);

    reql_array_append(var15.get(), var17.get());

    reql_array_append(var5.get(), var15.get());

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var18;
    _C::CTypes::string buf18(new uint8_t[4]);
    const uint8_t src18[] = "type";
    reql_string_init(var18.get(), buf18.get(), 4);
    reql_string_append(var18.get(), src18, 4);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[7]);
    const uint8_t src19[] = "Polygon";
    reql_string_init(var19.get(), buf19.get(), 7);
    reql_string_append(var19.get(), src19, 7);

    reql_object_add(var0.get(), var18.get(), var19.get());
  }

  SECTION("test24") {
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

  SECTION("test25") {
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

  SECTION("test26") {
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

  SECTION("test27") {
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
