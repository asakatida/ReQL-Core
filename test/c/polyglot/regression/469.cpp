// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Issue 176", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "index";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "x";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[5]);
    const uint8_t src4[] = "ready";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    ReQL_Obj_c var5;
    reql_bool_init(var5.get(), 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "NULL";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[5]);
    const uint8_t src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "null";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "BOOL";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[5]);
    const uint8_t src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "true";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[6]);
    const uint8_t src2[] = "NUMBER";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[5]);
    const uint8_t src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[1]);
    const uint8_t src4[] = "1";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[6]);
    const uint8_t src2[] = "STRING";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[5]);
    const uint8_t src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[5]);
    const uint8_t src4[] = "\"1\"";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "ARRAY";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[5]);
    const uint8_t src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[3]);
    const uint8_t src4[] = "[1]";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[6]);
    const uint8_t src2[] = "OBJECT";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[5]);
    const uint8_t src3[] = "value";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[17]);
    const uint8_t src4[] = "{\n\t\"a\":\t1\n}";
    reql_string_init(var4.get(), buf4.get(), 17);
    reql_string_append(var4.get(), src4, 17);

    reql_object_add(var0.get(), var3.get(), var4.get());
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
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[2]);
    const uint8_t src1[] = "db";
    reql_string_init(var1.get(), buf1.get(), 2);
    reql_string_append(var1.get(), src1, 2);

    ReQL_Obj_c var2;
    _C::CTypes::pairs pair2(new ReQL_Pair_t[3]);
    reql_object_init(var2.get(), pair2.get(), 3);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    _C::CTypes::pairs pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[4]);
    const uint8_t src5[] = "func";
    reql_string_init(var5.get(), buf5.get(), 4);
    reql_string_append(var5.get(), src5, 4);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[4]);
    const uint8_t src6[] = "uuid";
    reql_string_init(var6.get(), buf6.get(), 4);
    reql_string_append(var6.get(), src6, 4);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_object_add(var2.get(), var3.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[4]);
    const uint8_t src7[] = "name";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[4]);
    const uint8_t src8[] = "d469";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    reql_object_add(var2.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[4]);
    const uint8_t src9[] = "type";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[2]);
    const uint8_t src10[] = "DB";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    reql_object_add(var2.get(), var9.get(), var10.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[19]);
    const uint8_t src11[] = "doc_count_estimates";
    reql_string_init(var11.get(), buf11.get(), 19);
    reql_string_append(var11.get(), src11, 19);

    ReQL_Obj_c var12;
    _C::CTypes::array arr12(new ReQL_Obj_t*[1]);
    reql_array_init(var12.get(), arr12.get(), 1);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_array_append(var12.get(), var13.get());

    reql_object_add(var0.get(), var11.get(), var12.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[2]);
    const uint8_t src14[] = "id";
    reql_string_init(var14.get(), buf14.get(), 2);
    reql_string_append(var14.get(), src14, 2);

    ReQL_Obj_c var15;
    _C::CTypes::pairs pair15(new ReQL_Pair_t[1]);
    reql_object_init(var15.get(), pair15.get(), 1);

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[4]);
    const uint8_t src16[] = "func";
    reql_string_init(var16.get(), buf16.get(), 4);
    reql_string_append(var16.get(), src16, 4);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[4]);
    const uint8_t src17[] = "uuid";
    reql_string_init(var17.get(), buf17.get(), 4);
    reql_string_append(var17.get(), src17, 4);

    reql_object_add(var15.get(), var16.get(), var17.get());

    reql_object_add(var0.get(), var14.get(), var15.get());

    ReQL_Obj_c var18;
    _C::CTypes::string buf18(new uint8_t[7]);
    const uint8_t src18[] = "indexes";
    reql_string_init(var18.get(), buf18.get(), 7);
    reql_string_append(var18.get(), src18, 7);

    ReQL_Obj_c var19;
    _C::CTypes::array arr19(new ReQL_Obj_t*[1]);
    reql_array_init(var19.get(), arr19.get(), 1);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[1]);
    const uint8_t src20[] = "x";
    reql_string_init(var20.get(), buf20.get(), 1);
    reql_string_append(var20.get(), src20, 1);

    reql_array_append(var19.get(), var20.get());

    reql_object_add(var0.get(), var18.get(), var19.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[4]);
    const uint8_t src21[] = "name";
    reql_string_init(var21.get(), buf21.get(), 4);
    reql_string_append(var21.get(), src21, 4);

    ReQL_Obj_c var22;
    _C::CTypes::string buf22(new uint8_t[4]);
    const uint8_t src22[] = "t469";
    reql_string_init(var22.get(), buf22.get(), 4);
    reql_string_append(var22.get(), src22, 4);

    reql_object_add(var0.get(), var21.get(), var22.get());

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[11]);
    const uint8_t src23[] = "primary_key";
    reql_string_init(var23.get(), buf23.get(), 11);
    reql_string_append(var23.get(), src23, 11);

    ReQL_Obj_c var24;
    _C::CTypes::string buf24(new uint8_t[2]);
    const uint8_t src24[] = "id";
    reql_string_init(var24.get(), buf24.get(), 2);
    reql_string_append(var24.get(), src24, 2);

    reql_object_add(var0.get(), var23.get(), var24.get());

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[4]);
    const uint8_t src25[] = "type";
    reql_string_init(var25.get(), buf25.get(), 4);
    reql_string_append(var25.get(), src25, 4);

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[5]);
    const uint8_t src26[] = "TABLE";
    reql_string_init(var26.get(), buf26.get(), 5);
    reql_string_append(var26.get(), src26, 5);

    reql_object_add(var0.get(), var25.get(), var26.get());
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "table";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    ReQL_Obj_c var2;
    _C::CTypes::pairs pair2(new ReQL_Pair_t[7]);
    reql_object_init(var2.get(), pair2.get(), 7);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "db";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    _C::CTypes::pairs pair4(new ReQL_Pair_t[3]);
    reql_object_init(var4.get(), pair4.get(), 3);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[2]);
    const uint8_t src5[] = "id";
    reql_string_init(var5.get(), buf5.get(), 2);
    reql_string_append(var5.get(), src5, 2);

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[4]);
    const uint8_t src7[] = "func";
    reql_string_init(var7.get(), buf7.get(), 4);
    reql_string_append(var7.get(), src7, 4);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[4]);
    const uint8_t src8[] = "uuid";
    reql_string_init(var8.get(), buf8.get(), 4);
    reql_string_append(var8.get(), src8, 4);

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_object_add(var4.get(), var5.get(), var6.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[4]);
    const uint8_t src9[] = "name";
    reql_string_init(var9.get(), buf9.get(), 4);
    reql_string_append(var9.get(), src9, 4);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[4]);
    const uint8_t src10[] = "d469";
    reql_string_init(var10.get(), buf10.get(), 4);
    reql_string_append(var10.get(), src10, 4);

    reql_object_add(var4.get(), var9.get(), var10.get());

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[4]);
    const uint8_t src11[] = "type";
    reql_string_init(var11.get(), buf11.get(), 4);
    reql_string_append(var11.get(), src11, 4);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[2]);
    const uint8_t src12[] = "DB";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    reql_object_add(var4.get(), var11.get(), var12.get());

    reql_object_add(var2.get(), var3.get(), var4.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[19]);
    const uint8_t src13[] = "doc_count_estimates";
    reql_string_init(var13.get(), buf13.get(), 19);
    reql_string_append(var13.get(), src13, 19);

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[1]);
    reql_array_init(var14.get(), arr14.get(), 1);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 0);

    reql_array_append(var14.get(), var15.get());

    reql_object_add(var2.get(), var13.get(), var14.get());

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[2]);
    const uint8_t src16[] = "id";
    reql_string_init(var16.get(), buf16.get(), 2);
    reql_string_append(var16.get(), src16, 2);

    ReQL_Obj_c var17;
    _C::CTypes::pairs pair17(new ReQL_Pair_t[1]);
    reql_object_init(var17.get(), pair17.get(), 1);

    ReQL_Obj_c var18;
    _C::CTypes::string buf18(new uint8_t[4]);
    const uint8_t src18[] = "func";
    reql_string_init(var18.get(), buf18.get(), 4);
    reql_string_append(var18.get(), src18, 4);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[4]);
    const uint8_t src19[] = "uuid";
    reql_string_init(var19.get(), buf19.get(), 4);
    reql_string_append(var19.get(), src19, 4);

    reql_object_add(var17.get(), var18.get(), var19.get());

    reql_object_add(var2.get(), var16.get(), var17.get());

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[7]);
    const uint8_t src20[] = "indexes";
    reql_string_init(var20.get(), buf20.get(), 7);
    reql_string_append(var20.get(), src20, 7);

    ReQL_Obj_c var21;
    _C::CTypes::array arr21(new ReQL_Obj_t*[1]);
    reql_array_init(var21.get(), arr21.get(), 1);

    ReQL_Obj_c var22;
    _C::CTypes::string buf22(new uint8_t[1]);
    const uint8_t src22[] = "x";
    reql_string_init(var22.get(), buf22.get(), 1);
    reql_string_append(var22.get(), src22, 1);

    reql_array_append(var21.get(), var22.get());

    reql_object_add(var2.get(), var20.get(), var21.get());

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[4]);
    const uint8_t src23[] = "name";
    reql_string_init(var23.get(), buf23.get(), 4);
    reql_string_append(var23.get(), src23, 4);

    ReQL_Obj_c var24;
    _C::CTypes::string buf24(new uint8_t[4]);
    const uint8_t src24[] = "t469";
    reql_string_init(var24.get(), buf24.get(), 4);
    reql_string_append(var24.get(), src24, 4);

    reql_object_add(var2.get(), var23.get(), var24.get());

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[11]);
    const uint8_t src25[] = "primary_key";
    reql_string_init(var25.get(), buf25.get(), 11);
    reql_string_append(var25.get(), src25, 11);

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[2]);
    const uint8_t src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), 2);
    reql_string_append(var26.get(), src26, 2);

    reql_object_add(var2.get(), var25.get(), var26.get());

    ReQL_Obj_c var27;
    _C::CTypes::string buf27(new uint8_t[4]);
    const uint8_t src27[] = "type";
    reql_string_init(var27.get(), buf27.get(), 4);
    reql_string_append(var27.get(), src27, 4);

    ReQL_Obj_c var28;
    _C::CTypes::string buf28(new uint8_t[5]);
    const uint8_t src28[] = "TABLE";
    reql_string_init(var28.get(), buf28.get(), 5);
    reql_string_append(var28.get(), src28, 5);

    reql_object_add(var2.get(), var27.get(), var28.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var29;
    _C::CTypes::string buf29(new uint8_t[4]);
    const uint8_t src29[] = "type";
    reql_string_init(var29.get(), buf29.get(), 4);
    reql_string_append(var29.get(), src29, 4);

    ReQL_Obj_c var30;
    _C::CTypes::string buf30(new uint8_t[17]);
    const uint8_t src30[] = "SELECTION<STREAM>";
    reql_string_init(var30.get(), buf30.get(), 17);
    reql_string_append(var30.get(), src30, 17);

    reql_object_add(var0.get(), var29.get(), var30.get());
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "type";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[6]);
    const uint8_t src2[] = "STREAM";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

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
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
