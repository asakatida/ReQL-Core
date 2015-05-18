// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests that manipulation data in tables", "[c][ast]") {

  SECTION("test0") {
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
    reql_number_init(var6.get(), 100);

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

  SECTION("test1") {
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
    reql_number_init(var6.get(), 100);

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

  SECTION("test2") {
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
    reql_number_init(var6.get(), 100);

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
    reql_number_init(var6.get(), 1);

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

  SECTION("test6") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 150);
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 150);
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1200);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1225);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 1250);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 1275);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 48);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 49);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 50);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 51);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[1]);
    const uint8_t src6[] = "a";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 0);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var10;
    _C::CTypes::pairs pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[5]);
    const uint8_t src11[] = "group";
    reql_string_init(var11.get(), buf11.get(), 5);
    reql_string_append(var11.get(), src11, 5);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[9]);
    const uint8_t src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), 9);
    reql_string_append(var13.get(), src13, 9);

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[1]);
    const uint8_t src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[2]);
    const uint8_t src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 1);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var19;
    _C::CTypes::pairs pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[5]);
    const uint8_t src20[] = "group";
    reql_string_init(var20.get(), buf20.get(), 5);
    reql_string_append(var20.get(), src20, 5);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 2);

    reql_object_add(var19.get(), var20.get(), var21.get());

    ReQL_Obj_c var22;
    _C::CTypes::string buf22(new uint8_t[9]);
    const uint8_t src22[] = "reduction";
    reql_string_init(var22.get(), buf22.get(), 9);
    reql_string_append(var22.get(), src22, 9);

    ReQL_Obj_c var23;
    _C::CTypes::pairs pair23(new ReQL_Pair_t[2]);
    reql_object_init(var23.get(), pair23.get(), 2);

    ReQL_Obj_c var24;
    _C::CTypes::string buf24(new uint8_t[1]);
    const uint8_t src24[] = "a";
    reql_string_init(var24.get(), buf24.get(), 1);
    reql_string_append(var24.get(), src24, 1);

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[2]);
    const uint8_t src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), 2);
    reql_string_append(var26.get(), src26, 2);

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 2);

    reql_object_add(var23.get(), var26.get(), var27.get());

    reql_object_add(var19.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var19.get());

    ReQL_Obj_c var28;
    _C::CTypes::pairs pair28(new ReQL_Pair_t[2]);
    reql_object_init(var28.get(), pair28.get(), 2);

    ReQL_Obj_c var29;
    _C::CTypes::string buf29(new uint8_t[5]);
    const uint8_t src29[] = "group";
    reql_string_init(var29.get(), buf29.get(), 5);
    reql_string_append(var29.get(), src29, 5);

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    ReQL_Obj_c var31;
    _C::CTypes::string buf31(new uint8_t[9]);
    const uint8_t src31[] = "reduction";
    reql_string_init(var31.get(), buf31.get(), 9);
    reql_string_append(var31.get(), src31, 9);

    ReQL_Obj_c var32;
    _C::CTypes::pairs pair32(new ReQL_Pair_t[2]);
    reql_object_init(var32.get(), pair32.get(), 2);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[1]);
    const uint8_t src33[] = "a";
    reql_string_init(var33.get(), buf33.get(), 1);
    reql_string_append(var33.get(), src33, 1);

    ReQL_Obj_c var34;
    reql_number_init(var34.get(), 3);

    reql_object_add(var32.get(), var33.get(), var34.get());

    ReQL_Obj_c var35;
    _C::CTypes::string buf35(new uint8_t[2]);
    const uint8_t src35[] = "id";
    reql_string_init(var35.get(), buf35.get(), 2);
    reql_string_append(var35.get(), src35, 2);

    ReQL_Obj_c var36;
    reql_number_init(var36.get(), 3);

    reql_object_add(var32.get(), var35.get(), var36.get());

    reql_object_add(var28.get(), var31.get(), var32.get());

    reql_array_append(var0.get(), var28.get());
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[1]);
    const uint8_t src6[] = "a";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 96);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var10;
    _C::CTypes::pairs pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[5]);
    const uint8_t src11[] = "group";
    reql_string_init(var11.get(), buf11.get(), 5);
    reql_string_append(var11.get(), src11, 5);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[9]);
    const uint8_t src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), 9);
    reql_string_append(var13.get(), src13, 9);

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[1]);
    const uint8_t src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[2]);
    const uint8_t src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 97);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var19;
    _C::CTypes::pairs pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[5]);
    const uint8_t src20[] = "group";
    reql_string_init(var20.get(), buf20.get(), 5);
    reql_string_append(var20.get(), src20, 5);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 2);

    reql_object_add(var19.get(), var20.get(), var21.get());

    ReQL_Obj_c var22;
    _C::CTypes::string buf22(new uint8_t[9]);
    const uint8_t src22[] = "reduction";
    reql_string_init(var22.get(), buf22.get(), 9);
    reql_string_append(var22.get(), src22, 9);

    ReQL_Obj_c var23;
    _C::CTypes::pairs pair23(new ReQL_Pair_t[2]);
    reql_object_init(var23.get(), pair23.get(), 2);

    ReQL_Obj_c var24;
    _C::CTypes::string buf24(new uint8_t[1]);
    const uint8_t src24[] = "a";
    reql_string_init(var24.get(), buf24.get(), 1);
    reql_string_append(var24.get(), src24, 1);

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[2]);
    const uint8_t src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), 2);
    reql_string_append(var26.get(), src26, 2);

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 98);

    reql_object_add(var23.get(), var26.get(), var27.get());

    reql_object_add(var19.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var19.get());

    ReQL_Obj_c var28;
    _C::CTypes::pairs pair28(new ReQL_Pair_t[2]);
    reql_object_init(var28.get(), pair28.get(), 2);

    ReQL_Obj_c var29;
    _C::CTypes::string buf29(new uint8_t[5]);
    const uint8_t src29[] = "group";
    reql_string_init(var29.get(), buf29.get(), 5);
    reql_string_append(var29.get(), src29, 5);

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    ReQL_Obj_c var31;
    _C::CTypes::string buf31(new uint8_t[9]);
    const uint8_t src31[] = "reduction";
    reql_string_init(var31.get(), buf31.get(), 9);
    reql_string_append(var31.get(), src31, 9);

    ReQL_Obj_c var32;
    _C::CTypes::pairs pair32(new ReQL_Pair_t[2]);
    reql_object_init(var32.get(), pair32.get(), 2);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[1]);
    const uint8_t src33[] = "a";
    reql_string_init(var33.get(), buf33.get(), 1);
    reql_string_append(var33.get(), src33, 1);

    ReQL_Obj_c var34;
    reql_number_init(var34.get(), 3);

    reql_object_add(var32.get(), var33.get(), var34.get());

    ReQL_Obj_c var35;
    _C::CTypes::string buf35(new uint8_t[2]);
    const uint8_t src35[] = "id";
    reql_string_init(var35.get(), buf35.get(), 2);
    reql_string_append(var35.get(), src35, 2);

    ReQL_Obj_c var36;
    reql_number_init(var36.get(), 99);

    reql_object_add(var32.get(), var35.get(), var36.get());

    reql_object_add(var28.get(), var31.get(), var32.get());

    reql_array_append(var0.get(), var28.get());
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test20") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[1]);
    const uint8_t src6[] = "a";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 0);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var10;
    _C::CTypes::pairs pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[5]);
    const uint8_t src11[] = "group";
    reql_string_init(var11.get(), buf11.get(), 5);
    reql_string_append(var11.get(), src11, 5);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[9]);
    const uint8_t src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), 9);
    reql_string_append(var13.get(), src13, 9);

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[1]);
    const uint8_t src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[2]);
    const uint8_t src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 1);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var19;
    _C::CTypes::pairs pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[5]);
    const uint8_t src20[] = "group";
    reql_string_init(var20.get(), buf20.get(), 5);
    reql_string_append(var20.get(), src20, 5);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 2);

    reql_object_add(var19.get(), var20.get(), var21.get());

    ReQL_Obj_c var22;
    _C::CTypes::string buf22(new uint8_t[9]);
    const uint8_t src22[] = "reduction";
    reql_string_init(var22.get(), buf22.get(), 9);
    reql_string_append(var22.get(), src22, 9);

    ReQL_Obj_c var23;
    _C::CTypes::pairs pair23(new ReQL_Pair_t[2]);
    reql_object_init(var23.get(), pair23.get(), 2);

    ReQL_Obj_c var24;
    _C::CTypes::string buf24(new uint8_t[1]);
    const uint8_t src24[] = "a";
    reql_string_init(var24.get(), buf24.get(), 1);
    reql_string_append(var24.get(), src24, 1);

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[2]);
    const uint8_t src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), 2);
    reql_string_append(var26.get(), src26, 2);

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 2);

    reql_object_add(var23.get(), var26.get(), var27.get());

    reql_object_add(var19.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var19.get());

    ReQL_Obj_c var28;
    _C::CTypes::pairs pair28(new ReQL_Pair_t[2]);
    reql_object_init(var28.get(), pair28.get(), 2);

    ReQL_Obj_c var29;
    _C::CTypes::string buf29(new uint8_t[5]);
    const uint8_t src29[] = "group";
    reql_string_init(var29.get(), buf29.get(), 5);
    reql_string_append(var29.get(), src29, 5);

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    ReQL_Obj_c var31;
    _C::CTypes::string buf31(new uint8_t[9]);
    const uint8_t src31[] = "reduction";
    reql_string_init(var31.get(), buf31.get(), 9);
    reql_string_append(var31.get(), src31, 9);

    ReQL_Obj_c var32;
    _C::CTypes::pairs pair32(new ReQL_Pair_t[2]);
    reql_object_init(var32.get(), pair32.get(), 2);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[1]);
    const uint8_t src33[] = "a";
    reql_string_init(var33.get(), buf33.get(), 1);
    reql_string_append(var33.get(), src33, 1);

    ReQL_Obj_c var34;
    reql_number_init(var34.get(), 3);

    reql_object_add(var32.get(), var33.get(), var34.get());

    ReQL_Obj_c var35;
    _C::CTypes::string buf35(new uint8_t[2]);
    const uint8_t src35[] = "id";
    reql_string_init(var35.get(), buf35.get(), 2);
    reql_string_append(var35.get(), src35, 2);

    ReQL_Obj_c var36;
    reql_number_init(var36.get(), 3);

    reql_object_add(var32.get(), var35.get(), var36.get());

    reql_object_add(var28.get(), var31.get(), var32.get());

    reql_array_append(var0.get(), var28.get());
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[1]);
    const uint8_t src6[] = "a";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 96);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var10;
    _C::CTypes::pairs pair10(new ReQL_Pair_t[2]);
    reql_object_init(var10.get(), pair10.get(), 2);

    ReQL_Obj_c var11;
    _C::CTypes::string buf11(new uint8_t[5]);
    const uint8_t src11[] = "group";
    reql_string_init(var11.get(), buf11.get(), 5);
    reql_string_append(var11.get(), src11, 5);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[9]);
    const uint8_t src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), 9);
    reql_string_append(var13.get(), src13, 9);

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[1]);
    const uint8_t src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[2]);
    const uint8_t src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 97);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_object_add(var10.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var19;
    _C::CTypes::pairs pair19(new ReQL_Pair_t[2]);
    reql_object_init(var19.get(), pair19.get(), 2);

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[5]);
    const uint8_t src20[] = "group";
    reql_string_init(var20.get(), buf20.get(), 5);
    reql_string_append(var20.get(), src20, 5);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 2);

    reql_object_add(var19.get(), var20.get(), var21.get());

    ReQL_Obj_c var22;
    _C::CTypes::string buf22(new uint8_t[9]);
    const uint8_t src22[] = "reduction";
    reql_string_init(var22.get(), buf22.get(), 9);
    reql_string_append(var22.get(), src22, 9);

    ReQL_Obj_c var23;
    _C::CTypes::pairs pair23(new ReQL_Pair_t[2]);
    reql_object_init(var23.get(), pair23.get(), 2);

    ReQL_Obj_c var24;
    _C::CTypes::string buf24(new uint8_t[1]);
    const uint8_t src24[] = "a";
    reql_string_init(var24.get(), buf24.get(), 1);
    reql_string_append(var24.get(), src24, 1);

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[2]);
    const uint8_t src26[] = "id";
    reql_string_init(var26.get(), buf26.get(), 2);
    reql_string_append(var26.get(), src26, 2);

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 98);

    reql_object_add(var23.get(), var26.get(), var27.get());

    reql_object_add(var19.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var19.get());

    ReQL_Obj_c var28;
    _C::CTypes::pairs pair28(new ReQL_Pair_t[2]);
    reql_object_init(var28.get(), pair28.get(), 2);

    ReQL_Obj_c var29;
    _C::CTypes::string buf29(new uint8_t[5]);
    const uint8_t src29[] = "group";
    reql_string_init(var29.get(), buf29.get(), 5);
    reql_string_append(var29.get(), src29, 5);

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    ReQL_Obj_c var31;
    _C::CTypes::string buf31(new uint8_t[9]);
    const uint8_t src31[] = "reduction";
    reql_string_init(var31.get(), buf31.get(), 9);
    reql_string_append(var31.get(), src31, 9);

    ReQL_Obj_c var32;
    _C::CTypes::pairs pair32(new ReQL_Pair_t[2]);
    reql_object_init(var32.get(), pair32.get(), 2);

    ReQL_Obj_c var33;
    _C::CTypes::string buf33(new uint8_t[1]);
    const uint8_t src33[] = "a";
    reql_string_init(var33.get(), buf33.get(), 1);
    reql_string_append(var33.get(), src33, 1);

    ReQL_Obj_c var34;
    reql_number_init(var34.get(), 3);

    reql_object_add(var32.get(), var33.get(), var34.get());

    ReQL_Obj_c var35;
    _C::CTypes::string buf35(new uint8_t[2]);
    const uint8_t src35[] = "id";
    reql_string_init(var35.get(), buf35.get(), 2);
    reql_string_append(var35.get(), src35, 2);

    ReQL_Obj_c var36;
    reql_number_init(var36.get(), 99);

    reql_object_add(var32.get(), var35.get(), var36.get());

    reql_object_add(var28.get(), var31.get(), var32.get());

    reql_array_append(var0.get(), var28.get());
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 150);
  }

  SECTION("test24") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 150);
  }

  SECTION("test25") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1200);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1225);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 1250);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 1275);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test26") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test27") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.5);
  }

  SECTION("test28") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 48);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 49);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 50);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 51);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test29") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 96);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test30") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test31") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test32") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 0);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 2);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 3);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test33") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test34") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test35") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 96);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 97);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 98);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 99);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test36") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1200);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1225);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 1250);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 1275);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test37") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1200);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1225);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1250);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1275);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test38") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[1]);
    reql_array_init(var4.get(), arr4.get(), 1);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    _C::CTypes::array arr7(new ReQL_Obj_t*[1]);
    reql_array_init(var7.get(), arr7.get(), 1);

    ReQL_Obj_c var8;
    _C::CTypes::pairs pair8(new ReQL_Pair_t[1]);
    reql_object_init(var8.get(), pair8.get(), 1);

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[1]);
    const uint8_t src9[] = "a";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1);

    reql_object_add(var8.get(), var9.get(), var10.get());

    reql_array_append(var7.get(), var8.get());

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test39") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[14]);
    const uint8_t src0[] = "GROUPED_STREAM";
    reql_string_init(var0.get(), buf0.get(), 14);
    reql_string_append(var0.get(), src0, 14);
  }

  SECTION("test40") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[12]);
    const uint8_t src0[] = "GROUPED_DATA";
    reql_string_init(var0.get(), buf0.get(), 12);
    reql_string_append(var0.get(), src0, 12);
  }

  SECTION("test41") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[12]);
    const uint8_t src0[] = "GROUPED_DATA";
    reql_string_init(var0.get(), buf0.get(), 12);
    reql_string_append(var0.get(), src0, 12);
  }

  SECTION("test42") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[3]);
    reql_array_init(var5.get(), arr5.get(), 3);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 4);

    reql_array_append(var5.get(), var7.get());

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 8);

    reql_array_append(var5.get(), var8.get());

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[2]);
    reql_object_init(var9.get(), pair9.get(), 2);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[5]);
    const uint8_t src10[] = "group";
    reql_string_init(var10.get(), buf10.get(), 5);
    reql_string_append(var10.get(), src10, 5);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 1);

    reql_object_add(var9.get(), var10.get(), var11.get());

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[9]);
    const uint8_t src12[] = "reduction";
    reql_string_init(var12.get(), buf12.get(), 9);
    reql_string_append(var12.get(), src12, 9);

    ReQL_Obj_c var13;
    _C::CTypes::array arr13(new ReQL_Obj_t*[3]);
    reql_array_init(var13.get(), arr13.get(), 3);

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 1);

    reql_array_append(var13.get(), var14.get());

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 5);

    reql_array_append(var13.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 9);

    reql_array_append(var13.get(), var16.get());

    reql_object_add(var9.get(), var12.get(), var13.get());

    reql_array_append(var0.get(), var9.get());

    ReQL_Obj_c var17;
    _C::CTypes::pairs pair17(new ReQL_Pair_t[2]);
    reql_object_init(var17.get(), pair17.get(), 2);

    ReQL_Obj_c var18;
    _C::CTypes::string buf18(new uint8_t[5]);
    const uint8_t src18[] = "group";
    reql_string_init(var18.get(), buf18.get(), 5);
    reql_string_append(var18.get(), src18, 5);

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 2);

    reql_object_add(var17.get(), var18.get(), var19.get());

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[9]);
    const uint8_t src20[] = "reduction";
    reql_string_init(var20.get(), buf20.get(), 9);
    reql_string_append(var20.get(), src20, 9);

    ReQL_Obj_c var21;
    _C::CTypes::array arr21(new ReQL_Obj_t*[2]);
    reql_array_init(var21.get(), arr21.get(), 2);

    ReQL_Obj_c var22;
    reql_number_init(var22.get(), 2);

    reql_array_append(var21.get(), var22.get());

    ReQL_Obj_c var23;
    reql_number_init(var23.get(), 6);

    reql_array_append(var21.get(), var23.get());

    reql_object_add(var17.get(), var20.get(), var21.get());

    reql_array_append(var0.get(), var17.get());

    ReQL_Obj_c var24;
    _C::CTypes::pairs pair24(new ReQL_Pair_t[2]);
    reql_object_init(var24.get(), pair24.get(), 2);

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[5]);
    const uint8_t src25[] = "group";
    reql_string_init(var25.get(), buf25.get(), 5);
    reql_string_append(var25.get(), src25, 5);

    ReQL_Obj_c var26;
    reql_number_init(var26.get(), 3);

    reql_object_add(var24.get(), var25.get(), var26.get());

    ReQL_Obj_c var27;
    _C::CTypes::string buf27(new uint8_t[9]);
    const uint8_t src27[] = "reduction";
    reql_string_init(var27.get(), buf27.get(), 9);
    reql_string_append(var27.get(), src27, 9);

    ReQL_Obj_c var28;
    _C::CTypes::array arr28(new ReQL_Obj_t*[2]);
    reql_array_init(var28.get(), arr28.get(), 2);

    ReQL_Obj_c var29;
    reql_number_init(var29.get(), 3);

    reql_array_append(var28.get(), var29.get());

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 7);

    reql_array_append(var28.get(), var30.get());

    reql_object_add(var24.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var24.get());
  }

  SECTION("test43") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 9);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 9);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 4);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 4);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test44") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 2400);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 2450);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2500);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 2550);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test45") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 2400);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 2450);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2500);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 2550);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test46") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 2400);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 2450);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2500);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 2550);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test47") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1200);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1225);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1250);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1275);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test49") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 25);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 25);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 25);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 25);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test50") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1200);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1225);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1250);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1275);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test51") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 48);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 49);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 50);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 51);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test52") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[5]);
    reql_array_init(var4.get(), arr4.get(), 5);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 20);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 20);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 20);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 20);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    ReQL_Obj_c var17;
    _C::CTypes::array arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 4);

    reql_array_append(var17.get(), var18.get());

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 20);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var4.get(), var17.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test53") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[12]);
    reql_array_init(var4.get(), arr4.get(), 12);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

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
    reql_number_init(var9.get(), 9);

    reql_array_append(var5.get(), var9.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var10;
    _C::CTypes::array arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var10.get(), var11.get());

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 8);

    reql_array_append(var10.get(), var14.get());

    reql_array_append(var4.get(), var10.get());

    ReQL_Obj_c var15;
    _C::CTypes::array arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    ReQL_Obj_c var16;
    _C::CTypes::array arr16(new ReQL_Obj_t*[2]);
    reql_array_init(var16.get(), arr16.get(), 2);

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 0);

    reql_array_append(var16.get(), var17.get());

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 2);

    reql_array_append(var16.get(), var18.get());

    reql_array_append(var15.get(), var16.get());

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 8);

    reql_array_append(var15.get(), var19.get());

    reql_array_append(var4.get(), var15.get());

    ReQL_Obj_c var20;
    _C::CTypes::array arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    ReQL_Obj_c var21;
    _C::CTypes::array arr21(new ReQL_Obj_t*[2]);
    reql_array_init(var21.get(), arr21.get(), 2);

    ReQL_Obj_c var22;
    reql_number_init(var22.get(), 1);

    reql_array_append(var21.get(), var22.get());

    ReQL_Obj_c var23;
    reql_number_init(var23.get(), 0);

    reql_array_append(var21.get(), var23.get());

    reql_array_append(var20.get(), var21.get());

    ReQL_Obj_c var24;
    reql_number_init(var24.get(), 8);

    reql_array_append(var20.get(), var24.get());

    reql_array_append(var4.get(), var20.get());

    ReQL_Obj_c var25;
    _C::CTypes::array arr25(new ReQL_Obj_t*[2]);
    reql_array_init(var25.get(), arr25.get(), 2);

    ReQL_Obj_c var26;
    _C::CTypes::array arr26(new ReQL_Obj_t*[2]);
    reql_array_init(var26.get(), arr26.get(), 2);

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 1);

    reql_array_append(var26.get(), var27.get());

    ReQL_Obj_c var28;
    reql_number_init(var28.get(), 1);

    reql_array_append(var26.get(), var28.get());

    reql_array_append(var25.get(), var26.get());

    ReQL_Obj_c var29;
    reql_number_init(var29.get(), 9);

    reql_array_append(var25.get(), var29.get());

    reql_array_append(var4.get(), var25.get());

    ReQL_Obj_c var30;
    _C::CTypes::array arr30(new ReQL_Obj_t*[2]);
    reql_array_init(var30.get(), arr30.get(), 2);

    ReQL_Obj_c var31;
    _C::CTypes::array arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    ReQL_Obj_c var32;
    reql_number_init(var32.get(), 1);

    reql_array_append(var31.get(), var32.get());

    ReQL_Obj_c var33;
    reql_number_init(var33.get(), 2);

    reql_array_append(var31.get(), var33.get());

    reql_array_append(var30.get(), var31.get());

    ReQL_Obj_c var34;
    reql_number_init(var34.get(), 8);

    reql_array_append(var30.get(), var34.get());

    reql_array_append(var4.get(), var30.get());

    ReQL_Obj_c var35;
    _C::CTypes::array arr35(new ReQL_Obj_t*[2]);
    reql_array_init(var35.get(), arr35.get(), 2);

    ReQL_Obj_c var36;
    _C::CTypes::array arr36(new ReQL_Obj_t*[2]);
    reql_array_init(var36.get(), arr36.get(), 2);

    ReQL_Obj_c var37;
    reql_number_init(var37.get(), 2);

    reql_array_append(var36.get(), var37.get());

    ReQL_Obj_c var38;
    reql_number_init(var38.get(), 0);

    reql_array_append(var36.get(), var38.get());

    reql_array_append(var35.get(), var36.get());

    ReQL_Obj_c var39;
    reql_number_init(var39.get(), 8);

    reql_array_append(var35.get(), var39.get());

    reql_array_append(var4.get(), var35.get());

    ReQL_Obj_c var40;
    _C::CTypes::array arr40(new ReQL_Obj_t*[2]);
    reql_array_init(var40.get(), arr40.get(), 2);

    ReQL_Obj_c var41;
    _C::CTypes::array arr41(new ReQL_Obj_t*[2]);
    reql_array_init(var41.get(), arr41.get(), 2);

    ReQL_Obj_c var42;
    reql_number_init(var42.get(), 2);

    reql_array_append(var41.get(), var42.get());

    ReQL_Obj_c var43;
    reql_number_init(var43.get(), 1);

    reql_array_append(var41.get(), var43.get());

    reql_array_append(var40.get(), var41.get());

    ReQL_Obj_c var44;
    reql_number_init(var44.get(), 8);

    reql_array_append(var40.get(), var44.get());

    reql_array_append(var4.get(), var40.get());

    ReQL_Obj_c var45;
    _C::CTypes::array arr45(new ReQL_Obj_t*[2]);
    reql_array_init(var45.get(), arr45.get(), 2);

    ReQL_Obj_c var46;
    _C::CTypes::array arr46(new ReQL_Obj_t*[2]);
    reql_array_init(var46.get(), arr46.get(), 2);

    ReQL_Obj_c var47;
    reql_number_init(var47.get(), 2);

    reql_array_append(var46.get(), var47.get());

    ReQL_Obj_c var48;
    reql_number_init(var48.get(), 2);

    reql_array_append(var46.get(), var48.get());

    reql_array_append(var45.get(), var46.get());

    ReQL_Obj_c var49;
    reql_number_init(var49.get(), 9);

    reql_array_append(var45.get(), var49.get());

    reql_array_append(var4.get(), var45.get());

    ReQL_Obj_c var50;
    _C::CTypes::array arr50(new ReQL_Obj_t*[2]);
    reql_array_init(var50.get(), arr50.get(), 2);

    ReQL_Obj_c var51;
    _C::CTypes::array arr51(new ReQL_Obj_t*[2]);
    reql_array_init(var51.get(), arr51.get(), 2);

    ReQL_Obj_c var52;
    reql_number_init(var52.get(), 3);

    reql_array_append(var51.get(), var52.get());

    ReQL_Obj_c var53;
    reql_number_init(var53.get(), 0);

    reql_array_append(var51.get(), var53.get());

    reql_array_append(var50.get(), var51.get());

    ReQL_Obj_c var54;
    reql_number_init(var54.get(), 9);

    reql_array_append(var50.get(), var54.get());

    reql_array_append(var4.get(), var50.get());

    ReQL_Obj_c var55;
    _C::CTypes::array arr55(new ReQL_Obj_t*[2]);
    reql_array_init(var55.get(), arr55.get(), 2);

    ReQL_Obj_c var56;
    _C::CTypes::array arr56(new ReQL_Obj_t*[2]);
    reql_array_init(var56.get(), arr56.get(), 2);

    ReQL_Obj_c var57;
    reql_number_init(var57.get(), 3);

    reql_array_append(var56.get(), var57.get());

    ReQL_Obj_c var58;
    reql_number_init(var58.get(), 1);

    reql_array_append(var56.get(), var58.get());

    reql_array_append(var55.get(), var56.get());

    ReQL_Obj_c var59;
    reql_number_init(var59.get(), 8);

    reql_array_append(var55.get(), var59.get());

    reql_array_append(var4.get(), var55.get());

    ReQL_Obj_c var60;
    _C::CTypes::array arr60(new ReQL_Obj_t*[2]);
    reql_array_init(var60.get(), arr60.get(), 2);

    ReQL_Obj_c var61;
    _C::CTypes::array arr61(new ReQL_Obj_t*[2]);
    reql_array_init(var61.get(), arr61.get(), 2);

    ReQL_Obj_c var62;
    reql_number_init(var62.get(), 3);

    reql_array_append(var61.get(), var62.get());

    ReQL_Obj_c var63;
    reql_number_init(var63.get(), 2);

    reql_array_append(var61.get(), var63.get());

    reql_array_append(var60.get(), var61.get());

    ReQL_Obj_c var64;
    reql_number_init(var64.get(), 8);

    reql_array_append(var60.get(), var64.get());

    reql_array_append(var4.get(), var60.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test55") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "result";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "error";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test57") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 4);
  }

  SECTION("test58") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test59") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test60") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test61") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test62") {
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

  SECTION("test65") {
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
    const uint8_t src3[] = "a";
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

  SECTION("test68") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 25);
  }

  SECTION("test69") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 25);
  }

  SECTION("test81") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test82") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 4);
  }

  SECTION("test83") {
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

  SECTION("test84") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[100]);
    reql_array_init(var4.get(), arr4.get(), 100);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 1);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    ReQL_Obj_c var17;
    _C::CTypes::array arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 4);

    reql_array_append(var17.get(), var18.get());

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 1);

    reql_array_append(var17.get(), var19.get());

    reql_array_append(var4.get(), var17.get());

    ReQL_Obj_c var20;
    _C::CTypes::array arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 5);

    reql_array_append(var20.get(), var21.get());

    ReQL_Obj_c var22;
    reql_number_init(var22.get(), 1);

    reql_array_append(var20.get(), var22.get());

    reql_array_append(var4.get(), var20.get());

    ReQL_Obj_c var23;
    _C::CTypes::array arr23(new ReQL_Obj_t*[2]);
    reql_array_init(var23.get(), arr23.get(), 2);

    ReQL_Obj_c var24;
    reql_number_init(var24.get(), 6);

    reql_array_append(var23.get(), var24.get());

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 1);

    reql_array_append(var23.get(), var25.get());

    reql_array_append(var4.get(), var23.get());

    ReQL_Obj_c var26;
    _C::CTypes::array arr26(new ReQL_Obj_t*[2]);
    reql_array_init(var26.get(), arr26.get(), 2);

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 7);

    reql_array_append(var26.get(), var27.get());

    ReQL_Obj_c var28;
    reql_number_init(var28.get(), 1);

    reql_array_append(var26.get(), var28.get());

    reql_array_append(var4.get(), var26.get());

    ReQL_Obj_c var29;
    _C::CTypes::array arr29(new ReQL_Obj_t*[2]);
    reql_array_init(var29.get(), arr29.get(), 2);

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 8);

    reql_array_append(var29.get(), var30.get());

    ReQL_Obj_c var31;
    reql_number_init(var31.get(), 1);

    reql_array_append(var29.get(), var31.get());

    reql_array_append(var4.get(), var29.get());

    ReQL_Obj_c var32;
    _C::CTypes::array arr32(new ReQL_Obj_t*[2]);
    reql_array_init(var32.get(), arr32.get(), 2);

    ReQL_Obj_c var33;
    reql_number_init(var33.get(), 9);

    reql_array_append(var32.get(), var33.get());

    ReQL_Obj_c var34;
    reql_number_init(var34.get(), 1);

    reql_array_append(var32.get(), var34.get());

    reql_array_append(var4.get(), var32.get());

    ReQL_Obj_c var35;
    _C::CTypes::array arr35(new ReQL_Obj_t*[2]);
    reql_array_init(var35.get(), arr35.get(), 2);

    ReQL_Obj_c var36;
    reql_number_init(var36.get(), 10);

    reql_array_append(var35.get(), var36.get());

    ReQL_Obj_c var37;
    reql_number_init(var37.get(), 1);

    reql_array_append(var35.get(), var37.get());

    reql_array_append(var4.get(), var35.get());

    ReQL_Obj_c var38;
    _C::CTypes::array arr38(new ReQL_Obj_t*[2]);
    reql_array_init(var38.get(), arr38.get(), 2);

    ReQL_Obj_c var39;
    reql_number_init(var39.get(), 11);

    reql_array_append(var38.get(), var39.get());

    ReQL_Obj_c var40;
    reql_number_init(var40.get(), 1);

    reql_array_append(var38.get(), var40.get());

    reql_array_append(var4.get(), var38.get());

    ReQL_Obj_c var41;
    _C::CTypes::array arr41(new ReQL_Obj_t*[2]);
    reql_array_init(var41.get(), arr41.get(), 2);

    ReQL_Obj_c var42;
    reql_number_init(var42.get(), 12);

    reql_array_append(var41.get(), var42.get());

    ReQL_Obj_c var43;
    reql_number_init(var43.get(), 1);

    reql_array_append(var41.get(), var43.get());

    reql_array_append(var4.get(), var41.get());

    ReQL_Obj_c var44;
    _C::CTypes::array arr44(new ReQL_Obj_t*[2]);
    reql_array_init(var44.get(), arr44.get(), 2);

    ReQL_Obj_c var45;
    reql_number_init(var45.get(), 13);

    reql_array_append(var44.get(), var45.get());

    ReQL_Obj_c var46;
    reql_number_init(var46.get(), 1);

    reql_array_append(var44.get(), var46.get());

    reql_array_append(var4.get(), var44.get());

    ReQL_Obj_c var47;
    _C::CTypes::array arr47(new ReQL_Obj_t*[2]);
    reql_array_init(var47.get(), arr47.get(), 2);

    ReQL_Obj_c var48;
    reql_number_init(var48.get(), 14);

    reql_array_append(var47.get(), var48.get());

    ReQL_Obj_c var49;
    reql_number_init(var49.get(), 1);

    reql_array_append(var47.get(), var49.get());

    reql_array_append(var4.get(), var47.get());

    ReQL_Obj_c var50;
    _C::CTypes::array arr50(new ReQL_Obj_t*[2]);
    reql_array_init(var50.get(), arr50.get(), 2);

    ReQL_Obj_c var51;
    reql_number_init(var51.get(), 15);

    reql_array_append(var50.get(), var51.get());

    ReQL_Obj_c var52;
    reql_number_init(var52.get(), 1);

    reql_array_append(var50.get(), var52.get());

    reql_array_append(var4.get(), var50.get());

    ReQL_Obj_c var53;
    _C::CTypes::array arr53(new ReQL_Obj_t*[2]);
    reql_array_init(var53.get(), arr53.get(), 2);

    ReQL_Obj_c var54;
    reql_number_init(var54.get(), 16);

    reql_array_append(var53.get(), var54.get());

    ReQL_Obj_c var55;
    reql_number_init(var55.get(), 1);

    reql_array_append(var53.get(), var55.get());

    reql_array_append(var4.get(), var53.get());

    ReQL_Obj_c var56;
    _C::CTypes::array arr56(new ReQL_Obj_t*[2]);
    reql_array_init(var56.get(), arr56.get(), 2);

    ReQL_Obj_c var57;
    reql_number_init(var57.get(), 17);

    reql_array_append(var56.get(), var57.get());

    ReQL_Obj_c var58;
    reql_number_init(var58.get(), 1);

    reql_array_append(var56.get(), var58.get());

    reql_array_append(var4.get(), var56.get());

    ReQL_Obj_c var59;
    _C::CTypes::array arr59(new ReQL_Obj_t*[2]);
    reql_array_init(var59.get(), arr59.get(), 2);

    ReQL_Obj_c var60;
    reql_number_init(var60.get(), 18);

    reql_array_append(var59.get(), var60.get());

    ReQL_Obj_c var61;
    reql_number_init(var61.get(), 1);

    reql_array_append(var59.get(), var61.get());

    reql_array_append(var4.get(), var59.get());

    ReQL_Obj_c var62;
    _C::CTypes::array arr62(new ReQL_Obj_t*[2]);
    reql_array_init(var62.get(), arr62.get(), 2);

    ReQL_Obj_c var63;
    reql_number_init(var63.get(), 19);

    reql_array_append(var62.get(), var63.get());

    ReQL_Obj_c var64;
    reql_number_init(var64.get(), 1);

    reql_array_append(var62.get(), var64.get());

    reql_array_append(var4.get(), var62.get());

    ReQL_Obj_c var65;
    _C::CTypes::array arr65(new ReQL_Obj_t*[2]);
    reql_array_init(var65.get(), arr65.get(), 2);

    ReQL_Obj_c var66;
    reql_number_init(var66.get(), 20);

    reql_array_append(var65.get(), var66.get());

    ReQL_Obj_c var67;
    reql_number_init(var67.get(), 1);

    reql_array_append(var65.get(), var67.get());

    reql_array_append(var4.get(), var65.get());

    ReQL_Obj_c var68;
    _C::CTypes::array arr68(new ReQL_Obj_t*[2]);
    reql_array_init(var68.get(), arr68.get(), 2);

    ReQL_Obj_c var69;
    reql_number_init(var69.get(), 21);

    reql_array_append(var68.get(), var69.get());

    ReQL_Obj_c var70;
    reql_number_init(var70.get(), 1);

    reql_array_append(var68.get(), var70.get());

    reql_array_append(var4.get(), var68.get());

    ReQL_Obj_c var71;
    _C::CTypes::array arr71(new ReQL_Obj_t*[2]);
    reql_array_init(var71.get(), arr71.get(), 2);

    ReQL_Obj_c var72;
    reql_number_init(var72.get(), 22);

    reql_array_append(var71.get(), var72.get());

    ReQL_Obj_c var73;
    reql_number_init(var73.get(), 1);

    reql_array_append(var71.get(), var73.get());

    reql_array_append(var4.get(), var71.get());

    ReQL_Obj_c var74;
    _C::CTypes::array arr74(new ReQL_Obj_t*[2]);
    reql_array_init(var74.get(), arr74.get(), 2);

    ReQL_Obj_c var75;
    reql_number_init(var75.get(), 23);

    reql_array_append(var74.get(), var75.get());

    ReQL_Obj_c var76;
    reql_number_init(var76.get(), 1);

    reql_array_append(var74.get(), var76.get());

    reql_array_append(var4.get(), var74.get());

    ReQL_Obj_c var77;
    _C::CTypes::array arr77(new ReQL_Obj_t*[2]);
    reql_array_init(var77.get(), arr77.get(), 2);

    ReQL_Obj_c var78;
    reql_number_init(var78.get(), 24);

    reql_array_append(var77.get(), var78.get());

    ReQL_Obj_c var79;
    reql_number_init(var79.get(), 1);

    reql_array_append(var77.get(), var79.get());

    reql_array_append(var4.get(), var77.get());

    ReQL_Obj_c var80;
    _C::CTypes::array arr80(new ReQL_Obj_t*[2]);
    reql_array_init(var80.get(), arr80.get(), 2);

    ReQL_Obj_c var81;
    reql_number_init(var81.get(), 25);

    reql_array_append(var80.get(), var81.get());

    ReQL_Obj_c var82;
    reql_number_init(var82.get(), 1);

    reql_array_append(var80.get(), var82.get());

    reql_array_append(var4.get(), var80.get());

    ReQL_Obj_c var83;
    _C::CTypes::array arr83(new ReQL_Obj_t*[2]);
    reql_array_init(var83.get(), arr83.get(), 2);

    ReQL_Obj_c var84;
    reql_number_init(var84.get(), 26);

    reql_array_append(var83.get(), var84.get());

    ReQL_Obj_c var85;
    reql_number_init(var85.get(), 1);

    reql_array_append(var83.get(), var85.get());

    reql_array_append(var4.get(), var83.get());

    ReQL_Obj_c var86;
    _C::CTypes::array arr86(new ReQL_Obj_t*[2]);
    reql_array_init(var86.get(), arr86.get(), 2);

    ReQL_Obj_c var87;
    reql_number_init(var87.get(), 27);

    reql_array_append(var86.get(), var87.get());

    ReQL_Obj_c var88;
    reql_number_init(var88.get(), 1);

    reql_array_append(var86.get(), var88.get());

    reql_array_append(var4.get(), var86.get());

    ReQL_Obj_c var89;
    _C::CTypes::array arr89(new ReQL_Obj_t*[2]);
    reql_array_init(var89.get(), arr89.get(), 2);

    ReQL_Obj_c var90;
    reql_number_init(var90.get(), 28);

    reql_array_append(var89.get(), var90.get());

    ReQL_Obj_c var91;
    reql_number_init(var91.get(), 1);

    reql_array_append(var89.get(), var91.get());

    reql_array_append(var4.get(), var89.get());

    ReQL_Obj_c var92;
    _C::CTypes::array arr92(new ReQL_Obj_t*[2]);
    reql_array_init(var92.get(), arr92.get(), 2);

    ReQL_Obj_c var93;
    reql_number_init(var93.get(), 29);

    reql_array_append(var92.get(), var93.get());

    ReQL_Obj_c var94;
    reql_number_init(var94.get(), 1);

    reql_array_append(var92.get(), var94.get());

    reql_array_append(var4.get(), var92.get());

    ReQL_Obj_c var95;
    _C::CTypes::array arr95(new ReQL_Obj_t*[2]);
    reql_array_init(var95.get(), arr95.get(), 2);

    ReQL_Obj_c var96;
    reql_number_init(var96.get(), 30);

    reql_array_append(var95.get(), var96.get());

    ReQL_Obj_c var97;
    reql_number_init(var97.get(), 1);

    reql_array_append(var95.get(), var97.get());

    reql_array_append(var4.get(), var95.get());

    ReQL_Obj_c var98;
    _C::CTypes::array arr98(new ReQL_Obj_t*[2]);
    reql_array_init(var98.get(), arr98.get(), 2);

    ReQL_Obj_c var99;
    reql_number_init(var99.get(), 31);

    reql_array_append(var98.get(), var99.get());

    ReQL_Obj_c var100;
    reql_number_init(var100.get(), 1);

    reql_array_append(var98.get(), var100.get());

    reql_array_append(var4.get(), var98.get());

    ReQL_Obj_c var101;
    _C::CTypes::array arr101(new ReQL_Obj_t*[2]);
    reql_array_init(var101.get(), arr101.get(), 2);

    ReQL_Obj_c var102;
    reql_number_init(var102.get(), 32);

    reql_array_append(var101.get(), var102.get());

    ReQL_Obj_c var103;
    reql_number_init(var103.get(), 1);

    reql_array_append(var101.get(), var103.get());

    reql_array_append(var4.get(), var101.get());

    ReQL_Obj_c var104;
    _C::CTypes::array arr104(new ReQL_Obj_t*[2]);
    reql_array_init(var104.get(), arr104.get(), 2);

    ReQL_Obj_c var105;
    reql_number_init(var105.get(), 33);

    reql_array_append(var104.get(), var105.get());

    ReQL_Obj_c var106;
    reql_number_init(var106.get(), 1);

    reql_array_append(var104.get(), var106.get());

    reql_array_append(var4.get(), var104.get());

    ReQL_Obj_c var107;
    _C::CTypes::array arr107(new ReQL_Obj_t*[2]);
    reql_array_init(var107.get(), arr107.get(), 2);

    ReQL_Obj_c var108;
    reql_number_init(var108.get(), 34);

    reql_array_append(var107.get(), var108.get());

    ReQL_Obj_c var109;
    reql_number_init(var109.get(), 1);

    reql_array_append(var107.get(), var109.get());

    reql_array_append(var4.get(), var107.get());

    ReQL_Obj_c var110;
    _C::CTypes::array arr110(new ReQL_Obj_t*[2]);
    reql_array_init(var110.get(), arr110.get(), 2);

    ReQL_Obj_c var111;
    reql_number_init(var111.get(), 35);

    reql_array_append(var110.get(), var111.get());

    ReQL_Obj_c var112;
    reql_number_init(var112.get(), 1);

    reql_array_append(var110.get(), var112.get());

    reql_array_append(var4.get(), var110.get());

    ReQL_Obj_c var113;
    _C::CTypes::array arr113(new ReQL_Obj_t*[2]);
    reql_array_init(var113.get(), arr113.get(), 2);

    ReQL_Obj_c var114;
    reql_number_init(var114.get(), 36);

    reql_array_append(var113.get(), var114.get());

    ReQL_Obj_c var115;
    reql_number_init(var115.get(), 1);

    reql_array_append(var113.get(), var115.get());

    reql_array_append(var4.get(), var113.get());

    ReQL_Obj_c var116;
    _C::CTypes::array arr116(new ReQL_Obj_t*[2]);
    reql_array_init(var116.get(), arr116.get(), 2);

    ReQL_Obj_c var117;
    reql_number_init(var117.get(), 37);

    reql_array_append(var116.get(), var117.get());

    ReQL_Obj_c var118;
    reql_number_init(var118.get(), 1);

    reql_array_append(var116.get(), var118.get());

    reql_array_append(var4.get(), var116.get());

    ReQL_Obj_c var119;
    _C::CTypes::array arr119(new ReQL_Obj_t*[2]);
    reql_array_init(var119.get(), arr119.get(), 2);

    ReQL_Obj_c var120;
    reql_number_init(var120.get(), 38);

    reql_array_append(var119.get(), var120.get());

    ReQL_Obj_c var121;
    reql_number_init(var121.get(), 1);

    reql_array_append(var119.get(), var121.get());

    reql_array_append(var4.get(), var119.get());

    ReQL_Obj_c var122;
    _C::CTypes::array arr122(new ReQL_Obj_t*[2]);
    reql_array_init(var122.get(), arr122.get(), 2);

    ReQL_Obj_c var123;
    reql_number_init(var123.get(), 39);

    reql_array_append(var122.get(), var123.get());

    ReQL_Obj_c var124;
    reql_number_init(var124.get(), 1);

    reql_array_append(var122.get(), var124.get());

    reql_array_append(var4.get(), var122.get());

    ReQL_Obj_c var125;
    _C::CTypes::array arr125(new ReQL_Obj_t*[2]);
    reql_array_init(var125.get(), arr125.get(), 2);

    ReQL_Obj_c var126;
    reql_number_init(var126.get(), 40);

    reql_array_append(var125.get(), var126.get());

    ReQL_Obj_c var127;
    reql_number_init(var127.get(), 1);

    reql_array_append(var125.get(), var127.get());

    reql_array_append(var4.get(), var125.get());

    ReQL_Obj_c var128;
    _C::CTypes::array arr128(new ReQL_Obj_t*[2]);
    reql_array_init(var128.get(), arr128.get(), 2);

    ReQL_Obj_c var129;
    reql_number_init(var129.get(), 41);

    reql_array_append(var128.get(), var129.get());

    ReQL_Obj_c var130;
    reql_number_init(var130.get(), 1);

    reql_array_append(var128.get(), var130.get());

    reql_array_append(var4.get(), var128.get());

    ReQL_Obj_c var131;
    _C::CTypes::array arr131(new ReQL_Obj_t*[2]);
    reql_array_init(var131.get(), arr131.get(), 2);

    ReQL_Obj_c var132;
    reql_number_init(var132.get(), 42);

    reql_array_append(var131.get(), var132.get());

    ReQL_Obj_c var133;
    reql_number_init(var133.get(), 1);

    reql_array_append(var131.get(), var133.get());

    reql_array_append(var4.get(), var131.get());

    ReQL_Obj_c var134;
    _C::CTypes::array arr134(new ReQL_Obj_t*[2]);
    reql_array_init(var134.get(), arr134.get(), 2);

    ReQL_Obj_c var135;
    reql_number_init(var135.get(), 43);

    reql_array_append(var134.get(), var135.get());

    ReQL_Obj_c var136;
    reql_number_init(var136.get(), 1);

    reql_array_append(var134.get(), var136.get());

    reql_array_append(var4.get(), var134.get());

    ReQL_Obj_c var137;
    _C::CTypes::array arr137(new ReQL_Obj_t*[2]);
    reql_array_init(var137.get(), arr137.get(), 2);

    ReQL_Obj_c var138;
    reql_number_init(var138.get(), 44);

    reql_array_append(var137.get(), var138.get());

    ReQL_Obj_c var139;
    reql_number_init(var139.get(), 1);

    reql_array_append(var137.get(), var139.get());

    reql_array_append(var4.get(), var137.get());

    ReQL_Obj_c var140;
    _C::CTypes::array arr140(new ReQL_Obj_t*[2]);
    reql_array_init(var140.get(), arr140.get(), 2);

    ReQL_Obj_c var141;
    reql_number_init(var141.get(), 45);

    reql_array_append(var140.get(), var141.get());

    ReQL_Obj_c var142;
    reql_number_init(var142.get(), 1);

    reql_array_append(var140.get(), var142.get());

    reql_array_append(var4.get(), var140.get());

    ReQL_Obj_c var143;
    _C::CTypes::array arr143(new ReQL_Obj_t*[2]);
    reql_array_init(var143.get(), arr143.get(), 2);

    ReQL_Obj_c var144;
    reql_number_init(var144.get(), 46);

    reql_array_append(var143.get(), var144.get());

    ReQL_Obj_c var145;
    reql_number_init(var145.get(), 1);

    reql_array_append(var143.get(), var145.get());

    reql_array_append(var4.get(), var143.get());

    ReQL_Obj_c var146;
    _C::CTypes::array arr146(new ReQL_Obj_t*[2]);
    reql_array_init(var146.get(), arr146.get(), 2);

    ReQL_Obj_c var147;
    reql_number_init(var147.get(), 47);

    reql_array_append(var146.get(), var147.get());

    ReQL_Obj_c var148;
    reql_number_init(var148.get(), 1);

    reql_array_append(var146.get(), var148.get());

    reql_array_append(var4.get(), var146.get());

    ReQL_Obj_c var149;
    _C::CTypes::array arr149(new ReQL_Obj_t*[2]);
    reql_array_init(var149.get(), arr149.get(), 2);

    ReQL_Obj_c var150;
    reql_number_init(var150.get(), 48);

    reql_array_append(var149.get(), var150.get());

    ReQL_Obj_c var151;
    reql_number_init(var151.get(), 1);

    reql_array_append(var149.get(), var151.get());

    reql_array_append(var4.get(), var149.get());

    ReQL_Obj_c var152;
    _C::CTypes::array arr152(new ReQL_Obj_t*[2]);
    reql_array_init(var152.get(), arr152.get(), 2);

    ReQL_Obj_c var153;
    reql_number_init(var153.get(), 49);

    reql_array_append(var152.get(), var153.get());

    ReQL_Obj_c var154;
    reql_number_init(var154.get(), 1);

    reql_array_append(var152.get(), var154.get());

    reql_array_append(var4.get(), var152.get());

    ReQL_Obj_c var155;
    _C::CTypes::array arr155(new ReQL_Obj_t*[2]);
    reql_array_init(var155.get(), arr155.get(), 2);

    ReQL_Obj_c var156;
    reql_number_init(var156.get(), 50);

    reql_array_append(var155.get(), var156.get());

    ReQL_Obj_c var157;
    reql_number_init(var157.get(), 1);

    reql_array_append(var155.get(), var157.get());

    reql_array_append(var4.get(), var155.get());

    ReQL_Obj_c var158;
    _C::CTypes::array arr158(new ReQL_Obj_t*[2]);
    reql_array_init(var158.get(), arr158.get(), 2);

    ReQL_Obj_c var159;
    reql_number_init(var159.get(), 51);

    reql_array_append(var158.get(), var159.get());

    ReQL_Obj_c var160;
    reql_number_init(var160.get(), 1);

    reql_array_append(var158.get(), var160.get());

    reql_array_append(var4.get(), var158.get());

    ReQL_Obj_c var161;
    _C::CTypes::array arr161(new ReQL_Obj_t*[2]);
    reql_array_init(var161.get(), arr161.get(), 2);

    ReQL_Obj_c var162;
    reql_number_init(var162.get(), 52);

    reql_array_append(var161.get(), var162.get());

    ReQL_Obj_c var163;
    reql_number_init(var163.get(), 1);

    reql_array_append(var161.get(), var163.get());

    reql_array_append(var4.get(), var161.get());

    ReQL_Obj_c var164;
    _C::CTypes::array arr164(new ReQL_Obj_t*[2]);
    reql_array_init(var164.get(), arr164.get(), 2);

    ReQL_Obj_c var165;
    reql_number_init(var165.get(), 53);

    reql_array_append(var164.get(), var165.get());

    ReQL_Obj_c var166;
    reql_number_init(var166.get(), 1);

    reql_array_append(var164.get(), var166.get());

    reql_array_append(var4.get(), var164.get());

    ReQL_Obj_c var167;
    _C::CTypes::array arr167(new ReQL_Obj_t*[2]);
    reql_array_init(var167.get(), arr167.get(), 2);

    ReQL_Obj_c var168;
    reql_number_init(var168.get(), 54);

    reql_array_append(var167.get(), var168.get());

    ReQL_Obj_c var169;
    reql_number_init(var169.get(), 1);

    reql_array_append(var167.get(), var169.get());

    reql_array_append(var4.get(), var167.get());

    ReQL_Obj_c var170;
    _C::CTypes::array arr170(new ReQL_Obj_t*[2]);
    reql_array_init(var170.get(), arr170.get(), 2);

    ReQL_Obj_c var171;
    reql_number_init(var171.get(), 55);

    reql_array_append(var170.get(), var171.get());

    ReQL_Obj_c var172;
    reql_number_init(var172.get(), 1);

    reql_array_append(var170.get(), var172.get());

    reql_array_append(var4.get(), var170.get());

    ReQL_Obj_c var173;
    _C::CTypes::array arr173(new ReQL_Obj_t*[2]);
    reql_array_init(var173.get(), arr173.get(), 2);

    ReQL_Obj_c var174;
    reql_number_init(var174.get(), 56);

    reql_array_append(var173.get(), var174.get());

    ReQL_Obj_c var175;
    reql_number_init(var175.get(), 1);

    reql_array_append(var173.get(), var175.get());

    reql_array_append(var4.get(), var173.get());

    ReQL_Obj_c var176;
    _C::CTypes::array arr176(new ReQL_Obj_t*[2]);
    reql_array_init(var176.get(), arr176.get(), 2);

    ReQL_Obj_c var177;
    reql_number_init(var177.get(), 57);

    reql_array_append(var176.get(), var177.get());

    ReQL_Obj_c var178;
    reql_number_init(var178.get(), 1);

    reql_array_append(var176.get(), var178.get());

    reql_array_append(var4.get(), var176.get());

    ReQL_Obj_c var179;
    _C::CTypes::array arr179(new ReQL_Obj_t*[2]);
    reql_array_init(var179.get(), arr179.get(), 2);

    ReQL_Obj_c var180;
    reql_number_init(var180.get(), 58);

    reql_array_append(var179.get(), var180.get());

    ReQL_Obj_c var181;
    reql_number_init(var181.get(), 1);

    reql_array_append(var179.get(), var181.get());

    reql_array_append(var4.get(), var179.get());

    ReQL_Obj_c var182;
    _C::CTypes::array arr182(new ReQL_Obj_t*[2]);
    reql_array_init(var182.get(), arr182.get(), 2);

    ReQL_Obj_c var183;
    reql_number_init(var183.get(), 59);

    reql_array_append(var182.get(), var183.get());

    ReQL_Obj_c var184;
    reql_number_init(var184.get(), 1);

    reql_array_append(var182.get(), var184.get());

    reql_array_append(var4.get(), var182.get());

    ReQL_Obj_c var185;
    _C::CTypes::array arr185(new ReQL_Obj_t*[2]);
    reql_array_init(var185.get(), arr185.get(), 2);

    ReQL_Obj_c var186;
    reql_number_init(var186.get(), 60);

    reql_array_append(var185.get(), var186.get());

    ReQL_Obj_c var187;
    reql_number_init(var187.get(), 1);

    reql_array_append(var185.get(), var187.get());

    reql_array_append(var4.get(), var185.get());

    ReQL_Obj_c var188;
    _C::CTypes::array arr188(new ReQL_Obj_t*[2]);
    reql_array_init(var188.get(), arr188.get(), 2);

    ReQL_Obj_c var189;
    reql_number_init(var189.get(), 61);

    reql_array_append(var188.get(), var189.get());

    ReQL_Obj_c var190;
    reql_number_init(var190.get(), 1);

    reql_array_append(var188.get(), var190.get());

    reql_array_append(var4.get(), var188.get());

    ReQL_Obj_c var191;
    _C::CTypes::array arr191(new ReQL_Obj_t*[2]);
    reql_array_init(var191.get(), arr191.get(), 2);

    ReQL_Obj_c var192;
    reql_number_init(var192.get(), 62);

    reql_array_append(var191.get(), var192.get());

    ReQL_Obj_c var193;
    reql_number_init(var193.get(), 1);

    reql_array_append(var191.get(), var193.get());

    reql_array_append(var4.get(), var191.get());

    ReQL_Obj_c var194;
    _C::CTypes::array arr194(new ReQL_Obj_t*[2]);
    reql_array_init(var194.get(), arr194.get(), 2);

    ReQL_Obj_c var195;
    reql_number_init(var195.get(), 63);

    reql_array_append(var194.get(), var195.get());

    ReQL_Obj_c var196;
    reql_number_init(var196.get(), 1);

    reql_array_append(var194.get(), var196.get());

    reql_array_append(var4.get(), var194.get());

    ReQL_Obj_c var197;
    _C::CTypes::array arr197(new ReQL_Obj_t*[2]);
    reql_array_init(var197.get(), arr197.get(), 2);

    ReQL_Obj_c var198;
    reql_number_init(var198.get(), 64);

    reql_array_append(var197.get(), var198.get());

    ReQL_Obj_c var199;
    reql_number_init(var199.get(), 1);

    reql_array_append(var197.get(), var199.get());

    reql_array_append(var4.get(), var197.get());

    ReQL_Obj_c var200;
    _C::CTypes::array arr200(new ReQL_Obj_t*[2]);
    reql_array_init(var200.get(), arr200.get(), 2);

    ReQL_Obj_c var201;
    reql_number_init(var201.get(), 65);

    reql_array_append(var200.get(), var201.get());

    ReQL_Obj_c var202;
    reql_number_init(var202.get(), 1);

    reql_array_append(var200.get(), var202.get());

    reql_array_append(var4.get(), var200.get());

    ReQL_Obj_c var203;
    _C::CTypes::array arr203(new ReQL_Obj_t*[2]);
    reql_array_init(var203.get(), arr203.get(), 2);

    ReQL_Obj_c var204;
    reql_number_init(var204.get(), 66);

    reql_array_append(var203.get(), var204.get());

    ReQL_Obj_c var205;
    reql_number_init(var205.get(), 1);

    reql_array_append(var203.get(), var205.get());

    reql_array_append(var4.get(), var203.get());

    ReQL_Obj_c var206;
    _C::CTypes::array arr206(new ReQL_Obj_t*[2]);
    reql_array_init(var206.get(), arr206.get(), 2);

    ReQL_Obj_c var207;
    reql_number_init(var207.get(), 67);

    reql_array_append(var206.get(), var207.get());

    ReQL_Obj_c var208;
    reql_number_init(var208.get(), 1);

    reql_array_append(var206.get(), var208.get());

    reql_array_append(var4.get(), var206.get());

    ReQL_Obj_c var209;
    _C::CTypes::array arr209(new ReQL_Obj_t*[2]);
    reql_array_init(var209.get(), arr209.get(), 2);

    ReQL_Obj_c var210;
    reql_number_init(var210.get(), 68);

    reql_array_append(var209.get(), var210.get());

    ReQL_Obj_c var211;
    reql_number_init(var211.get(), 1);

    reql_array_append(var209.get(), var211.get());

    reql_array_append(var4.get(), var209.get());

    ReQL_Obj_c var212;
    _C::CTypes::array arr212(new ReQL_Obj_t*[2]);
    reql_array_init(var212.get(), arr212.get(), 2);

    ReQL_Obj_c var213;
    reql_number_init(var213.get(), 69);

    reql_array_append(var212.get(), var213.get());

    ReQL_Obj_c var214;
    reql_number_init(var214.get(), 1);

    reql_array_append(var212.get(), var214.get());

    reql_array_append(var4.get(), var212.get());

    ReQL_Obj_c var215;
    _C::CTypes::array arr215(new ReQL_Obj_t*[2]);
    reql_array_init(var215.get(), arr215.get(), 2);

    ReQL_Obj_c var216;
    reql_number_init(var216.get(), 70);

    reql_array_append(var215.get(), var216.get());

    ReQL_Obj_c var217;
    reql_number_init(var217.get(), 1);

    reql_array_append(var215.get(), var217.get());

    reql_array_append(var4.get(), var215.get());

    ReQL_Obj_c var218;
    _C::CTypes::array arr218(new ReQL_Obj_t*[2]);
    reql_array_init(var218.get(), arr218.get(), 2);

    ReQL_Obj_c var219;
    reql_number_init(var219.get(), 71);

    reql_array_append(var218.get(), var219.get());

    ReQL_Obj_c var220;
    reql_number_init(var220.get(), 1);

    reql_array_append(var218.get(), var220.get());

    reql_array_append(var4.get(), var218.get());

    ReQL_Obj_c var221;
    _C::CTypes::array arr221(new ReQL_Obj_t*[2]);
    reql_array_init(var221.get(), arr221.get(), 2);

    ReQL_Obj_c var222;
    reql_number_init(var222.get(), 72);

    reql_array_append(var221.get(), var222.get());

    ReQL_Obj_c var223;
    reql_number_init(var223.get(), 1);

    reql_array_append(var221.get(), var223.get());

    reql_array_append(var4.get(), var221.get());

    ReQL_Obj_c var224;
    _C::CTypes::array arr224(new ReQL_Obj_t*[2]);
    reql_array_init(var224.get(), arr224.get(), 2);

    ReQL_Obj_c var225;
    reql_number_init(var225.get(), 73);

    reql_array_append(var224.get(), var225.get());

    ReQL_Obj_c var226;
    reql_number_init(var226.get(), 1);

    reql_array_append(var224.get(), var226.get());

    reql_array_append(var4.get(), var224.get());

    ReQL_Obj_c var227;
    _C::CTypes::array arr227(new ReQL_Obj_t*[2]);
    reql_array_init(var227.get(), arr227.get(), 2);

    ReQL_Obj_c var228;
    reql_number_init(var228.get(), 74);

    reql_array_append(var227.get(), var228.get());

    ReQL_Obj_c var229;
    reql_number_init(var229.get(), 1);

    reql_array_append(var227.get(), var229.get());

    reql_array_append(var4.get(), var227.get());

    ReQL_Obj_c var230;
    _C::CTypes::array arr230(new ReQL_Obj_t*[2]);
    reql_array_init(var230.get(), arr230.get(), 2);

    ReQL_Obj_c var231;
    reql_number_init(var231.get(), 75);

    reql_array_append(var230.get(), var231.get());

    ReQL_Obj_c var232;
    reql_number_init(var232.get(), 1);

    reql_array_append(var230.get(), var232.get());

    reql_array_append(var4.get(), var230.get());

    ReQL_Obj_c var233;
    _C::CTypes::array arr233(new ReQL_Obj_t*[2]);
    reql_array_init(var233.get(), arr233.get(), 2);

    ReQL_Obj_c var234;
    reql_number_init(var234.get(), 76);

    reql_array_append(var233.get(), var234.get());

    ReQL_Obj_c var235;
    reql_number_init(var235.get(), 1);

    reql_array_append(var233.get(), var235.get());

    reql_array_append(var4.get(), var233.get());

    ReQL_Obj_c var236;
    _C::CTypes::array arr236(new ReQL_Obj_t*[2]);
    reql_array_init(var236.get(), arr236.get(), 2);

    ReQL_Obj_c var237;
    reql_number_init(var237.get(), 77);

    reql_array_append(var236.get(), var237.get());

    ReQL_Obj_c var238;
    reql_number_init(var238.get(), 1);

    reql_array_append(var236.get(), var238.get());

    reql_array_append(var4.get(), var236.get());

    ReQL_Obj_c var239;
    _C::CTypes::array arr239(new ReQL_Obj_t*[2]);
    reql_array_init(var239.get(), arr239.get(), 2);

    ReQL_Obj_c var240;
    reql_number_init(var240.get(), 78);

    reql_array_append(var239.get(), var240.get());

    ReQL_Obj_c var241;
    reql_number_init(var241.get(), 1);

    reql_array_append(var239.get(), var241.get());

    reql_array_append(var4.get(), var239.get());

    ReQL_Obj_c var242;
    _C::CTypes::array arr242(new ReQL_Obj_t*[2]);
    reql_array_init(var242.get(), arr242.get(), 2);

    ReQL_Obj_c var243;
    reql_number_init(var243.get(), 79);

    reql_array_append(var242.get(), var243.get());

    ReQL_Obj_c var244;
    reql_number_init(var244.get(), 1);

    reql_array_append(var242.get(), var244.get());

    reql_array_append(var4.get(), var242.get());

    ReQL_Obj_c var245;
    _C::CTypes::array arr245(new ReQL_Obj_t*[2]);
    reql_array_init(var245.get(), arr245.get(), 2);

    ReQL_Obj_c var246;
    reql_number_init(var246.get(), 80);

    reql_array_append(var245.get(), var246.get());

    ReQL_Obj_c var247;
    reql_number_init(var247.get(), 1);

    reql_array_append(var245.get(), var247.get());

    reql_array_append(var4.get(), var245.get());

    ReQL_Obj_c var248;
    _C::CTypes::array arr248(new ReQL_Obj_t*[2]);
    reql_array_init(var248.get(), arr248.get(), 2);

    ReQL_Obj_c var249;
    reql_number_init(var249.get(), 81);

    reql_array_append(var248.get(), var249.get());

    ReQL_Obj_c var250;
    reql_number_init(var250.get(), 1);

    reql_array_append(var248.get(), var250.get());

    reql_array_append(var4.get(), var248.get());

    ReQL_Obj_c var251;
    _C::CTypes::array arr251(new ReQL_Obj_t*[2]);
    reql_array_init(var251.get(), arr251.get(), 2);

    ReQL_Obj_c var252;
    reql_number_init(var252.get(), 82);

    reql_array_append(var251.get(), var252.get());

    ReQL_Obj_c var253;
    reql_number_init(var253.get(), 1);

    reql_array_append(var251.get(), var253.get());

    reql_array_append(var4.get(), var251.get());

    ReQL_Obj_c var254;
    _C::CTypes::array arr254(new ReQL_Obj_t*[2]);
    reql_array_init(var254.get(), arr254.get(), 2);

    ReQL_Obj_c var255;
    reql_number_init(var255.get(), 83);

    reql_array_append(var254.get(), var255.get());

    ReQL_Obj_c var256;
    reql_number_init(var256.get(), 1);

    reql_array_append(var254.get(), var256.get());

    reql_array_append(var4.get(), var254.get());

    ReQL_Obj_c var257;
    _C::CTypes::array arr257(new ReQL_Obj_t*[2]);
    reql_array_init(var257.get(), arr257.get(), 2);

    ReQL_Obj_c var258;
    reql_number_init(var258.get(), 84);

    reql_array_append(var257.get(), var258.get());

    ReQL_Obj_c var259;
    reql_number_init(var259.get(), 1);

    reql_array_append(var257.get(), var259.get());

    reql_array_append(var4.get(), var257.get());

    ReQL_Obj_c var260;
    _C::CTypes::array arr260(new ReQL_Obj_t*[2]);
    reql_array_init(var260.get(), arr260.get(), 2);

    ReQL_Obj_c var261;
    reql_number_init(var261.get(), 85);

    reql_array_append(var260.get(), var261.get());

    ReQL_Obj_c var262;
    reql_number_init(var262.get(), 1);

    reql_array_append(var260.get(), var262.get());

    reql_array_append(var4.get(), var260.get());

    ReQL_Obj_c var263;
    _C::CTypes::array arr263(new ReQL_Obj_t*[2]);
    reql_array_init(var263.get(), arr263.get(), 2);

    ReQL_Obj_c var264;
    reql_number_init(var264.get(), 86);

    reql_array_append(var263.get(), var264.get());

    ReQL_Obj_c var265;
    reql_number_init(var265.get(), 1);

    reql_array_append(var263.get(), var265.get());

    reql_array_append(var4.get(), var263.get());

    ReQL_Obj_c var266;
    _C::CTypes::array arr266(new ReQL_Obj_t*[2]);
    reql_array_init(var266.get(), arr266.get(), 2);

    ReQL_Obj_c var267;
    reql_number_init(var267.get(), 87);

    reql_array_append(var266.get(), var267.get());

    ReQL_Obj_c var268;
    reql_number_init(var268.get(), 1);

    reql_array_append(var266.get(), var268.get());

    reql_array_append(var4.get(), var266.get());

    ReQL_Obj_c var269;
    _C::CTypes::array arr269(new ReQL_Obj_t*[2]);
    reql_array_init(var269.get(), arr269.get(), 2);

    ReQL_Obj_c var270;
    reql_number_init(var270.get(), 88);

    reql_array_append(var269.get(), var270.get());

    ReQL_Obj_c var271;
    reql_number_init(var271.get(), 1);

    reql_array_append(var269.get(), var271.get());

    reql_array_append(var4.get(), var269.get());

    ReQL_Obj_c var272;
    _C::CTypes::array arr272(new ReQL_Obj_t*[2]);
    reql_array_init(var272.get(), arr272.get(), 2);

    ReQL_Obj_c var273;
    reql_number_init(var273.get(), 89);

    reql_array_append(var272.get(), var273.get());

    ReQL_Obj_c var274;
    reql_number_init(var274.get(), 1);

    reql_array_append(var272.get(), var274.get());

    reql_array_append(var4.get(), var272.get());

    ReQL_Obj_c var275;
    _C::CTypes::array arr275(new ReQL_Obj_t*[2]);
    reql_array_init(var275.get(), arr275.get(), 2);

    ReQL_Obj_c var276;
    reql_number_init(var276.get(), 90);

    reql_array_append(var275.get(), var276.get());

    ReQL_Obj_c var277;
    reql_number_init(var277.get(), 1);

    reql_array_append(var275.get(), var277.get());

    reql_array_append(var4.get(), var275.get());

    ReQL_Obj_c var278;
    _C::CTypes::array arr278(new ReQL_Obj_t*[2]);
    reql_array_init(var278.get(), arr278.get(), 2);

    ReQL_Obj_c var279;
    reql_number_init(var279.get(), 91);

    reql_array_append(var278.get(), var279.get());

    ReQL_Obj_c var280;
    reql_number_init(var280.get(), 1);

    reql_array_append(var278.get(), var280.get());

    reql_array_append(var4.get(), var278.get());

    ReQL_Obj_c var281;
    _C::CTypes::array arr281(new ReQL_Obj_t*[2]);
    reql_array_init(var281.get(), arr281.get(), 2);

    ReQL_Obj_c var282;
    reql_number_init(var282.get(), 92);

    reql_array_append(var281.get(), var282.get());

    ReQL_Obj_c var283;
    reql_number_init(var283.get(), 1);

    reql_array_append(var281.get(), var283.get());

    reql_array_append(var4.get(), var281.get());

    ReQL_Obj_c var284;
    _C::CTypes::array arr284(new ReQL_Obj_t*[2]);
    reql_array_init(var284.get(), arr284.get(), 2);

    ReQL_Obj_c var285;
    reql_number_init(var285.get(), 93);

    reql_array_append(var284.get(), var285.get());

    ReQL_Obj_c var286;
    reql_number_init(var286.get(), 1);

    reql_array_append(var284.get(), var286.get());

    reql_array_append(var4.get(), var284.get());

    ReQL_Obj_c var287;
    _C::CTypes::array arr287(new ReQL_Obj_t*[2]);
    reql_array_init(var287.get(), arr287.get(), 2);

    ReQL_Obj_c var288;
    reql_number_init(var288.get(), 94);

    reql_array_append(var287.get(), var288.get());

    ReQL_Obj_c var289;
    reql_number_init(var289.get(), 1);

    reql_array_append(var287.get(), var289.get());

    reql_array_append(var4.get(), var287.get());

    ReQL_Obj_c var290;
    _C::CTypes::array arr290(new ReQL_Obj_t*[2]);
    reql_array_init(var290.get(), arr290.get(), 2);

    ReQL_Obj_c var291;
    reql_number_init(var291.get(), 95);

    reql_array_append(var290.get(), var291.get());

    ReQL_Obj_c var292;
    reql_number_init(var292.get(), 1);

    reql_array_append(var290.get(), var292.get());

    reql_array_append(var4.get(), var290.get());

    ReQL_Obj_c var293;
    _C::CTypes::array arr293(new ReQL_Obj_t*[2]);
    reql_array_init(var293.get(), arr293.get(), 2);

    ReQL_Obj_c var294;
    reql_number_init(var294.get(), 96);

    reql_array_append(var293.get(), var294.get());

    ReQL_Obj_c var295;
    reql_number_init(var295.get(), 1);

    reql_array_append(var293.get(), var295.get());

    reql_array_append(var4.get(), var293.get());

    ReQL_Obj_c var296;
    _C::CTypes::array arr296(new ReQL_Obj_t*[2]);
    reql_array_init(var296.get(), arr296.get(), 2);

    ReQL_Obj_c var297;
    reql_number_init(var297.get(), 97);

    reql_array_append(var296.get(), var297.get());

    ReQL_Obj_c var298;
    reql_number_init(var298.get(), 1);

    reql_array_append(var296.get(), var298.get());

    reql_array_append(var4.get(), var296.get());

    ReQL_Obj_c var299;
    _C::CTypes::array arr299(new ReQL_Obj_t*[2]);
    reql_array_init(var299.get(), arr299.get(), 2);

    ReQL_Obj_c var300;
    reql_number_init(var300.get(), 98);

    reql_array_append(var299.get(), var300.get());

    ReQL_Obj_c var301;
    reql_number_init(var301.get(), 1);

    reql_array_append(var299.get(), var301.get());

    reql_array_append(var4.get(), var299.get());

    ReQL_Obj_c var302;
    _C::CTypes::array arr302(new ReQL_Obj_t*[2]);
    reql_array_init(var302.get(), arr302.get(), 2);

    ReQL_Obj_c var303;
    reql_number_init(var303.get(), 99);

    reql_array_append(var302.get(), var303.get());

    ReQL_Obj_c var304;
    reql_number_init(var304.get(), 1);

    reql_array_append(var302.get(), var304.get());

    reql_array_append(var4.get(), var302.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test85") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 0);

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 25);

    reql_array_append(var5.get(), var7.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::array arr8(new ReQL_Obj_t*[2]);
    reql_array_init(var8.get(), arr8.get(), 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_array_append(var8.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 25);

    reql_array_append(var8.get(), var10.get());

    reql_array_append(var4.get(), var8.get());

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 2);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 25);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var4.get(), var11.get());

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[2]);
    reql_array_init(var14.get(), arr14.get(), 2);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 25);

    reql_array_append(var14.get(), var16.get());

    reql_array_append(var4.get(), var14.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test86") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[100]);
    reql_array_init(var4.get(), arr4.get(), 100);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

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
    reql_number_init(var9.get(), 1);

    reql_array_append(var5.get(), var9.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var10;
    _C::CTypes::array arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 0);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 4);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var10.get(), var11.get());

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 1);

    reql_array_append(var10.get(), var14.get());

    reql_array_append(var4.get(), var10.get());

    ReQL_Obj_c var15;
    _C::CTypes::array arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    ReQL_Obj_c var16;
    _C::CTypes::array arr16(new ReQL_Obj_t*[2]);
    reql_array_init(var16.get(), arr16.get(), 2);

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 0);

    reql_array_append(var16.get(), var17.get());

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 8);

    reql_array_append(var16.get(), var18.get());

    reql_array_append(var15.get(), var16.get());

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 1);

    reql_array_append(var15.get(), var19.get());

    reql_array_append(var4.get(), var15.get());

    ReQL_Obj_c var20;
    _C::CTypes::array arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    ReQL_Obj_c var21;
    _C::CTypes::array arr21(new ReQL_Obj_t*[2]);
    reql_array_init(var21.get(), arr21.get(), 2);

    ReQL_Obj_c var22;
    reql_number_init(var22.get(), 0);

    reql_array_append(var21.get(), var22.get());

    ReQL_Obj_c var23;
    reql_number_init(var23.get(), 12);

    reql_array_append(var21.get(), var23.get());

    reql_array_append(var20.get(), var21.get());

    ReQL_Obj_c var24;
    reql_number_init(var24.get(), 1);

    reql_array_append(var20.get(), var24.get());

    reql_array_append(var4.get(), var20.get());

    ReQL_Obj_c var25;
    _C::CTypes::array arr25(new ReQL_Obj_t*[2]);
    reql_array_init(var25.get(), arr25.get(), 2);

    ReQL_Obj_c var26;
    _C::CTypes::array arr26(new ReQL_Obj_t*[2]);
    reql_array_init(var26.get(), arr26.get(), 2);

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 0);

    reql_array_append(var26.get(), var27.get());

    ReQL_Obj_c var28;
    reql_number_init(var28.get(), 16);

    reql_array_append(var26.get(), var28.get());

    reql_array_append(var25.get(), var26.get());

    ReQL_Obj_c var29;
    reql_number_init(var29.get(), 1);

    reql_array_append(var25.get(), var29.get());

    reql_array_append(var4.get(), var25.get());

    ReQL_Obj_c var30;
    _C::CTypes::array arr30(new ReQL_Obj_t*[2]);
    reql_array_init(var30.get(), arr30.get(), 2);

    ReQL_Obj_c var31;
    _C::CTypes::array arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    ReQL_Obj_c var32;
    reql_number_init(var32.get(), 0);

    reql_array_append(var31.get(), var32.get());

    ReQL_Obj_c var33;
    reql_number_init(var33.get(), 20);

    reql_array_append(var31.get(), var33.get());

    reql_array_append(var30.get(), var31.get());

    ReQL_Obj_c var34;
    reql_number_init(var34.get(), 1);

    reql_array_append(var30.get(), var34.get());

    reql_array_append(var4.get(), var30.get());

    ReQL_Obj_c var35;
    _C::CTypes::array arr35(new ReQL_Obj_t*[2]);
    reql_array_init(var35.get(), arr35.get(), 2);

    ReQL_Obj_c var36;
    _C::CTypes::array arr36(new ReQL_Obj_t*[2]);
    reql_array_init(var36.get(), arr36.get(), 2);

    ReQL_Obj_c var37;
    reql_number_init(var37.get(), 0);

    reql_array_append(var36.get(), var37.get());

    ReQL_Obj_c var38;
    reql_number_init(var38.get(), 24);

    reql_array_append(var36.get(), var38.get());

    reql_array_append(var35.get(), var36.get());

    ReQL_Obj_c var39;
    reql_number_init(var39.get(), 1);

    reql_array_append(var35.get(), var39.get());

    reql_array_append(var4.get(), var35.get());

    ReQL_Obj_c var40;
    _C::CTypes::array arr40(new ReQL_Obj_t*[2]);
    reql_array_init(var40.get(), arr40.get(), 2);

    ReQL_Obj_c var41;
    _C::CTypes::array arr41(new ReQL_Obj_t*[2]);
    reql_array_init(var41.get(), arr41.get(), 2);

    ReQL_Obj_c var42;
    reql_number_init(var42.get(), 0);

    reql_array_append(var41.get(), var42.get());

    ReQL_Obj_c var43;
    reql_number_init(var43.get(), 28);

    reql_array_append(var41.get(), var43.get());

    reql_array_append(var40.get(), var41.get());

    ReQL_Obj_c var44;
    reql_number_init(var44.get(), 1);

    reql_array_append(var40.get(), var44.get());

    reql_array_append(var4.get(), var40.get());

    ReQL_Obj_c var45;
    _C::CTypes::array arr45(new ReQL_Obj_t*[2]);
    reql_array_init(var45.get(), arr45.get(), 2);

    ReQL_Obj_c var46;
    _C::CTypes::array arr46(new ReQL_Obj_t*[2]);
    reql_array_init(var46.get(), arr46.get(), 2);

    ReQL_Obj_c var47;
    reql_number_init(var47.get(), 0);

    reql_array_append(var46.get(), var47.get());

    ReQL_Obj_c var48;
    reql_number_init(var48.get(), 32);

    reql_array_append(var46.get(), var48.get());

    reql_array_append(var45.get(), var46.get());

    ReQL_Obj_c var49;
    reql_number_init(var49.get(), 1);

    reql_array_append(var45.get(), var49.get());

    reql_array_append(var4.get(), var45.get());

    ReQL_Obj_c var50;
    _C::CTypes::array arr50(new ReQL_Obj_t*[2]);
    reql_array_init(var50.get(), arr50.get(), 2);

    ReQL_Obj_c var51;
    _C::CTypes::array arr51(new ReQL_Obj_t*[2]);
    reql_array_init(var51.get(), arr51.get(), 2);

    ReQL_Obj_c var52;
    reql_number_init(var52.get(), 0);

    reql_array_append(var51.get(), var52.get());

    ReQL_Obj_c var53;
    reql_number_init(var53.get(), 36);

    reql_array_append(var51.get(), var53.get());

    reql_array_append(var50.get(), var51.get());

    ReQL_Obj_c var54;
    reql_number_init(var54.get(), 1);

    reql_array_append(var50.get(), var54.get());

    reql_array_append(var4.get(), var50.get());

    ReQL_Obj_c var55;
    _C::CTypes::array arr55(new ReQL_Obj_t*[2]);
    reql_array_init(var55.get(), arr55.get(), 2);

    ReQL_Obj_c var56;
    _C::CTypes::array arr56(new ReQL_Obj_t*[2]);
    reql_array_init(var56.get(), arr56.get(), 2);

    ReQL_Obj_c var57;
    reql_number_init(var57.get(), 0);

    reql_array_append(var56.get(), var57.get());

    ReQL_Obj_c var58;
    reql_number_init(var58.get(), 40);

    reql_array_append(var56.get(), var58.get());

    reql_array_append(var55.get(), var56.get());

    ReQL_Obj_c var59;
    reql_number_init(var59.get(), 1);

    reql_array_append(var55.get(), var59.get());

    reql_array_append(var4.get(), var55.get());

    ReQL_Obj_c var60;
    _C::CTypes::array arr60(new ReQL_Obj_t*[2]);
    reql_array_init(var60.get(), arr60.get(), 2);

    ReQL_Obj_c var61;
    _C::CTypes::array arr61(new ReQL_Obj_t*[2]);
    reql_array_init(var61.get(), arr61.get(), 2);

    ReQL_Obj_c var62;
    reql_number_init(var62.get(), 0);

    reql_array_append(var61.get(), var62.get());

    ReQL_Obj_c var63;
    reql_number_init(var63.get(), 44);

    reql_array_append(var61.get(), var63.get());

    reql_array_append(var60.get(), var61.get());

    ReQL_Obj_c var64;
    reql_number_init(var64.get(), 1);

    reql_array_append(var60.get(), var64.get());

    reql_array_append(var4.get(), var60.get());

    ReQL_Obj_c var65;
    _C::CTypes::array arr65(new ReQL_Obj_t*[2]);
    reql_array_init(var65.get(), arr65.get(), 2);

    ReQL_Obj_c var66;
    _C::CTypes::array arr66(new ReQL_Obj_t*[2]);
    reql_array_init(var66.get(), arr66.get(), 2);

    ReQL_Obj_c var67;
    reql_number_init(var67.get(), 0);

    reql_array_append(var66.get(), var67.get());

    ReQL_Obj_c var68;
    reql_number_init(var68.get(), 48);

    reql_array_append(var66.get(), var68.get());

    reql_array_append(var65.get(), var66.get());

    ReQL_Obj_c var69;
    reql_number_init(var69.get(), 1);

    reql_array_append(var65.get(), var69.get());

    reql_array_append(var4.get(), var65.get());

    ReQL_Obj_c var70;
    _C::CTypes::array arr70(new ReQL_Obj_t*[2]);
    reql_array_init(var70.get(), arr70.get(), 2);

    ReQL_Obj_c var71;
    _C::CTypes::array arr71(new ReQL_Obj_t*[2]);
    reql_array_init(var71.get(), arr71.get(), 2);

    ReQL_Obj_c var72;
    reql_number_init(var72.get(), 0);

    reql_array_append(var71.get(), var72.get());

    ReQL_Obj_c var73;
    reql_number_init(var73.get(), 52);

    reql_array_append(var71.get(), var73.get());

    reql_array_append(var70.get(), var71.get());

    ReQL_Obj_c var74;
    reql_number_init(var74.get(), 1);

    reql_array_append(var70.get(), var74.get());

    reql_array_append(var4.get(), var70.get());

    ReQL_Obj_c var75;
    _C::CTypes::array arr75(new ReQL_Obj_t*[2]);
    reql_array_init(var75.get(), arr75.get(), 2);

    ReQL_Obj_c var76;
    _C::CTypes::array arr76(new ReQL_Obj_t*[2]);
    reql_array_init(var76.get(), arr76.get(), 2);

    ReQL_Obj_c var77;
    reql_number_init(var77.get(), 0);

    reql_array_append(var76.get(), var77.get());

    ReQL_Obj_c var78;
    reql_number_init(var78.get(), 56);

    reql_array_append(var76.get(), var78.get());

    reql_array_append(var75.get(), var76.get());

    ReQL_Obj_c var79;
    reql_number_init(var79.get(), 1);

    reql_array_append(var75.get(), var79.get());

    reql_array_append(var4.get(), var75.get());

    ReQL_Obj_c var80;
    _C::CTypes::array arr80(new ReQL_Obj_t*[2]);
    reql_array_init(var80.get(), arr80.get(), 2);

    ReQL_Obj_c var81;
    _C::CTypes::array arr81(new ReQL_Obj_t*[2]);
    reql_array_init(var81.get(), arr81.get(), 2);

    ReQL_Obj_c var82;
    reql_number_init(var82.get(), 0);

    reql_array_append(var81.get(), var82.get());

    ReQL_Obj_c var83;
    reql_number_init(var83.get(), 60);

    reql_array_append(var81.get(), var83.get());

    reql_array_append(var80.get(), var81.get());

    ReQL_Obj_c var84;
    reql_number_init(var84.get(), 1);

    reql_array_append(var80.get(), var84.get());

    reql_array_append(var4.get(), var80.get());

    ReQL_Obj_c var85;
    _C::CTypes::array arr85(new ReQL_Obj_t*[2]);
    reql_array_init(var85.get(), arr85.get(), 2);

    ReQL_Obj_c var86;
    _C::CTypes::array arr86(new ReQL_Obj_t*[2]);
    reql_array_init(var86.get(), arr86.get(), 2);

    ReQL_Obj_c var87;
    reql_number_init(var87.get(), 0);

    reql_array_append(var86.get(), var87.get());

    ReQL_Obj_c var88;
    reql_number_init(var88.get(), 64);

    reql_array_append(var86.get(), var88.get());

    reql_array_append(var85.get(), var86.get());

    ReQL_Obj_c var89;
    reql_number_init(var89.get(), 1);

    reql_array_append(var85.get(), var89.get());

    reql_array_append(var4.get(), var85.get());

    ReQL_Obj_c var90;
    _C::CTypes::array arr90(new ReQL_Obj_t*[2]);
    reql_array_init(var90.get(), arr90.get(), 2);

    ReQL_Obj_c var91;
    _C::CTypes::array arr91(new ReQL_Obj_t*[2]);
    reql_array_init(var91.get(), arr91.get(), 2);

    ReQL_Obj_c var92;
    reql_number_init(var92.get(), 0);

    reql_array_append(var91.get(), var92.get());

    ReQL_Obj_c var93;
    reql_number_init(var93.get(), 68);

    reql_array_append(var91.get(), var93.get());

    reql_array_append(var90.get(), var91.get());

    ReQL_Obj_c var94;
    reql_number_init(var94.get(), 1);

    reql_array_append(var90.get(), var94.get());

    reql_array_append(var4.get(), var90.get());

    ReQL_Obj_c var95;
    _C::CTypes::array arr95(new ReQL_Obj_t*[2]);
    reql_array_init(var95.get(), arr95.get(), 2);

    ReQL_Obj_c var96;
    _C::CTypes::array arr96(new ReQL_Obj_t*[2]);
    reql_array_init(var96.get(), arr96.get(), 2);

    ReQL_Obj_c var97;
    reql_number_init(var97.get(), 0);

    reql_array_append(var96.get(), var97.get());

    ReQL_Obj_c var98;
    reql_number_init(var98.get(), 72);

    reql_array_append(var96.get(), var98.get());

    reql_array_append(var95.get(), var96.get());

    ReQL_Obj_c var99;
    reql_number_init(var99.get(), 1);

    reql_array_append(var95.get(), var99.get());

    reql_array_append(var4.get(), var95.get());

    ReQL_Obj_c var100;
    _C::CTypes::array arr100(new ReQL_Obj_t*[2]);
    reql_array_init(var100.get(), arr100.get(), 2);

    ReQL_Obj_c var101;
    _C::CTypes::array arr101(new ReQL_Obj_t*[2]);
    reql_array_init(var101.get(), arr101.get(), 2);

    ReQL_Obj_c var102;
    reql_number_init(var102.get(), 0);

    reql_array_append(var101.get(), var102.get());

    ReQL_Obj_c var103;
    reql_number_init(var103.get(), 76);

    reql_array_append(var101.get(), var103.get());

    reql_array_append(var100.get(), var101.get());

    ReQL_Obj_c var104;
    reql_number_init(var104.get(), 1);

    reql_array_append(var100.get(), var104.get());

    reql_array_append(var4.get(), var100.get());

    ReQL_Obj_c var105;
    _C::CTypes::array arr105(new ReQL_Obj_t*[2]);
    reql_array_init(var105.get(), arr105.get(), 2);

    ReQL_Obj_c var106;
    _C::CTypes::array arr106(new ReQL_Obj_t*[2]);
    reql_array_init(var106.get(), arr106.get(), 2);

    ReQL_Obj_c var107;
    reql_number_init(var107.get(), 0);

    reql_array_append(var106.get(), var107.get());

    ReQL_Obj_c var108;
    reql_number_init(var108.get(), 80);

    reql_array_append(var106.get(), var108.get());

    reql_array_append(var105.get(), var106.get());

    ReQL_Obj_c var109;
    reql_number_init(var109.get(), 1);

    reql_array_append(var105.get(), var109.get());

    reql_array_append(var4.get(), var105.get());

    ReQL_Obj_c var110;
    _C::CTypes::array arr110(new ReQL_Obj_t*[2]);
    reql_array_init(var110.get(), arr110.get(), 2);

    ReQL_Obj_c var111;
    _C::CTypes::array arr111(new ReQL_Obj_t*[2]);
    reql_array_init(var111.get(), arr111.get(), 2);

    ReQL_Obj_c var112;
    reql_number_init(var112.get(), 0);

    reql_array_append(var111.get(), var112.get());

    ReQL_Obj_c var113;
    reql_number_init(var113.get(), 84);

    reql_array_append(var111.get(), var113.get());

    reql_array_append(var110.get(), var111.get());

    ReQL_Obj_c var114;
    reql_number_init(var114.get(), 1);

    reql_array_append(var110.get(), var114.get());

    reql_array_append(var4.get(), var110.get());

    ReQL_Obj_c var115;
    _C::CTypes::array arr115(new ReQL_Obj_t*[2]);
    reql_array_init(var115.get(), arr115.get(), 2);

    ReQL_Obj_c var116;
    _C::CTypes::array arr116(new ReQL_Obj_t*[2]);
    reql_array_init(var116.get(), arr116.get(), 2);

    ReQL_Obj_c var117;
    reql_number_init(var117.get(), 0);

    reql_array_append(var116.get(), var117.get());

    ReQL_Obj_c var118;
    reql_number_init(var118.get(), 88);

    reql_array_append(var116.get(), var118.get());

    reql_array_append(var115.get(), var116.get());

    ReQL_Obj_c var119;
    reql_number_init(var119.get(), 1);

    reql_array_append(var115.get(), var119.get());

    reql_array_append(var4.get(), var115.get());

    ReQL_Obj_c var120;
    _C::CTypes::array arr120(new ReQL_Obj_t*[2]);
    reql_array_init(var120.get(), arr120.get(), 2);

    ReQL_Obj_c var121;
    _C::CTypes::array arr121(new ReQL_Obj_t*[2]);
    reql_array_init(var121.get(), arr121.get(), 2);

    ReQL_Obj_c var122;
    reql_number_init(var122.get(), 0);

    reql_array_append(var121.get(), var122.get());

    ReQL_Obj_c var123;
    reql_number_init(var123.get(), 92);

    reql_array_append(var121.get(), var123.get());

    reql_array_append(var120.get(), var121.get());

    ReQL_Obj_c var124;
    reql_number_init(var124.get(), 1);

    reql_array_append(var120.get(), var124.get());

    reql_array_append(var4.get(), var120.get());

    ReQL_Obj_c var125;
    _C::CTypes::array arr125(new ReQL_Obj_t*[2]);
    reql_array_init(var125.get(), arr125.get(), 2);

    ReQL_Obj_c var126;
    _C::CTypes::array arr126(new ReQL_Obj_t*[2]);
    reql_array_init(var126.get(), arr126.get(), 2);

    ReQL_Obj_c var127;
    reql_number_init(var127.get(), 0);

    reql_array_append(var126.get(), var127.get());

    ReQL_Obj_c var128;
    reql_number_init(var128.get(), 96);

    reql_array_append(var126.get(), var128.get());

    reql_array_append(var125.get(), var126.get());

    ReQL_Obj_c var129;
    reql_number_init(var129.get(), 1);

    reql_array_append(var125.get(), var129.get());

    reql_array_append(var4.get(), var125.get());

    ReQL_Obj_c var130;
    _C::CTypes::array arr130(new ReQL_Obj_t*[2]);
    reql_array_init(var130.get(), arr130.get(), 2);

    ReQL_Obj_c var131;
    _C::CTypes::array arr131(new ReQL_Obj_t*[2]);
    reql_array_init(var131.get(), arr131.get(), 2);

    ReQL_Obj_c var132;
    reql_number_init(var132.get(), 1);

    reql_array_append(var131.get(), var132.get());

    ReQL_Obj_c var133;
    reql_number_init(var133.get(), 1);

    reql_array_append(var131.get(), var133.get());

    reql_array_append(var130.get(), var131.get());

    ReQL_Obj_c var134;
    reql_number_init(var134.get(), 1);

    reql_array_append(var130.get(), var134.get());

    reql_array_append(var4.get(), var130.get());

    ReQL_Obj_c var135;
    _C::CTypes::array arr135(new ReQL_Obj_t*[2]);
    reql_array_init(var135.get(), arr135.get(), 2);

    ReQL_Obj_c var136;
    _C::CTypes::array arr136(new ReQL_Obj_t*[2]);
    reql_array_init(var136.get(), arr136.get(), 2);

    ReQL_Obj_c var137;
    reql_number_init(var137.get(), 1);

    reql_array_append(var136.get(), var137.get());

    ReQL_Obj_c var138;
    reql_number_init(var138.get(), 5);

    reql_array_append(var136.get(), var138.get());

    reql_array_append(var135.get(), var136.get());

    ReQL_Obj_c var139;
    reql_number_init(var139.get(), 1);

    reql_array_append(var135.get(), var139.get());

    reql_array_append(var4.get(), var135.get());

    ReQL_Obj_c var140;
    _C::CTypes::array arr140(new ReQL_Obj_t*[2]);
    reql_array_init(var140.get(), arr140.get(), 2);

    ReQL_Obj_c var141;
    _C::CTypes::array arr141(new ReQL_Obj_t*[2]);
    reql_array_init(var141.get(), arr141.get(), 2);

    ReQL_Obj_c var142;
    reql_number_init(var142.get(), 1);

    reql_array_append(var141.get(), var142.get());

    ReQL_Obj_c var143;
    reql_number_init(var143.get(), 9);

    reql_array_append(var141.get(), var143.get());

    reql_array_append(var140.get(), var141.get());

    ReQL_Obj_c var144;
    reql_number_init(var144.get(), 1);

    reql_array_append(var140.get(), var144.get());

    reql_array_append(var4.get(), var140.get());

    ReQL_Obj_c var145;
    _C::CTypes::array arr145(new ReQL_Obj_t*[2]);
    reql_array_init(var145.get(), arr145.get(), 2);

    ReQL_Obj_c var146;
    _C::CTypes::array arr146(new ReQL_Obj_t*[2]);
    reql_array_init(var146.get(), arr146.get(), 2);

    ReQL_Obj_c var147;
    reql_number_init(var147.get(), 1);

    reql_array_append(var146.get(), var147.get());

    ReQL_Obj_c var148;
    reql_number_init(var148.get(), 13);

    reql_array_append(var146.get(), var148.get());

    reql_array_append(var145.get(), var146.get());

    ReQL_Obj_c var149;
    reql_number_init(var149.get(), 1);

    reql_array_append(var145.get(), var149.get());

    reql_array_append(var4.get(), var145.get());

    ReQL_Obj_c var150;
    _C::CTypes::array arr150(new ReQL_Obj_t*[2]);
    reql_array_init(var150.get(), arr150.get(), 2);

    ReQL_Obj_c var151;
    _C::CTypes::array arr151(new ReQL_Obj_t*[2]);
    reql_array_init(var151.get(), arr151.get(), 2);

    ReQL_Obj_c var152;
    reql_number_init(var152.get(), 1);

    reql_array_append(var151.get(), var152.get());

    ReQL_Obj_c var153;
    reql_number_init(var153.get(), 17);

    reql_array_append(var151.get(), var153.get());

    reql_array_append(var150.get(), var151.get());

    ReQL_Obj_c var154;
    reql_number_init(var154.get(), 1);

    reql_array_append(var150.get(), var154.get());

    reql_array_append(var4.get(), var150.get());

    ReQL_Obj_c var155;
    _C::CTypes::array arr155(new ReQL_Obj_t*[2]);
    reql_array_init(var155.get(), arr155.get(), 2);

    ReQL_Obj_c var156;
    _C::CTypes::array arr156(new ReQL_Obj_t*[2]);
    reql_array_init(var156.get(), arr156.get(), 2);

    ReQL_Obj_c var157;
    reql_number_init(var157.get(), 1);

    reql_array_append(var156.get(), var157.get());

    ReQL_Obj_c var158;
    reql_number_init(var158.get(), 21);

    reql_array_append(var156.get(), var158.get());

    reql_array_append(var155.get(), var156.get());

    ReQL_Obj_c var159;
    reql_number_init(var159.get(), 1);

    reql_array_append(var155.get(), var159.get());

    reql_array_append(var4.get(), var155.get());

    ReQL_Obj_c var160;
    _C::CTypes::array arr160(new ReQL_Obj_t*[2]);
    reql_array_init(var160.get(), arr160.get(), 2);

    ReQL_Obj_c var161;
    _C::CTypes::array arr161(new ReQL_Obj_t*[2]);
    reql_array_init(var161.get(), arr161.get(), 2);

    ReQL_Obj_c var162;
    reql_number_init(var162.get(), 1);

    reql_array_append(var161.get(), var162.get());

    ReQL_Obj_c var163;
    reql_number_init(var163.get(), 25);

    reql_array_append(var161.get(), var163.get());

    reql_array_append(var160.get(), var161.get());

    ReQL_Obj_c var164;
    reql_number_init(var164.get(), 1);

    reql_array_append(var160.get(), var164.get());

    reql_array_append(var4.get(), var160.get());

    ReQL_Obj_c var165;
    _C::CTypes::array arr165(new ReQL_Obj_t*[2]);
    reql_array_init(var165.get(), arr165.get(), 2);

    ReQL_Obj_c var166;
    _C::CTypes::array arr166(new ReQL_Obj_t*[2]);
    reql_array_init(var166.get(), arr166.get(), 2);

    ReQL_Obj_c var167;
    reql_number_init(var167.get(), 1);

    reql_array_append(var166.get(), var167.get());

    ReQL_Obj_c var168;
    reql_number_init(var168.get(), 29);

    reql_array_append(var166.get(), var168.get());

    reql_array_append(var165.get(), var166.get());

    ReQL_Obj_c var169;
    reql_number_init(var169.get(), 1);

    reql_array_append(var165.get(), var169.get());

    reql_array_append(var4.get(), var165.get());

    ReQL_Obj_c var170;
    _C::CTypes::array arr170(new ReQL_Obj_t*[2]);
    reql_array_init(var170.get(), arr170.get(), 2);

    ReQL_Obj_c var171;
    _C::CTypes::array arr171(new ReQL_Obj_t*[2]);
    reql_array_init(var171.get(), arr171.get(), 2);

    ReQL_Obj_c var172;
    reql_number_init(var172.get(), 1);

    reql_array_append(var171.get(), var172.get());

    ReQL_Obj_c var173;
    reql_number_init(var173.get(), 33);

    reql_array_append(var171.get(), var173.get());

    reql_array_append(var170.get(), var171.get());

    ReQL_Obj_c var174;
    reql_number_init(var174.get(), 1);

    reql_array_append(var170.get(), var174.get());

    reql_array_append(var4.get(), var170.get());

    ReQL_Obj_c var175;
    _C::CTypes::array arr175(new ReQL_Obj_t*[2]);
    reql_array_init(var175.get(), arr175.get(), 2);

    ReQL_Obj_c var176;
    _C::CTypes::array arr176(new ReQL_Obj_t*[2]);
    reql_array_init(var176.get(), arr176.get(), 2);

    ReQL_Obj_c var177;
    reql_number_init(var177.get(), 1);

    reql_array_append(var176.get(), var177.get());

    ReQL_Obj_c var178;
    reql_number_init(var178.get(), 37);

    reql_array_append(var176.get(), var178.get());

    reql_array_append(var175.get(), var176.get());

    ReQL_Obj_c var179;
    reql_number_init(var179.get(), 1);

    reql_array_append(var175.get(), var179.get());

    reql_array_append(var4.get(), var175.get());

    ReQL_Obj_c var180;
    _C::CTypes::array arr180(new ReQL_Obj_t*[2]);
    reql_array_init(var180.get(), arr180.get(), 2);

    ReQL_Obj_c var181;
    _C::CTypes::array arr181(new ReQL_Obj_t*[2]);
    reql_array_init(var181.get(), arr181.get(), 2);

    ReQL_Obj_c var182;
    reql_number_init(var182.get(), 1);

    reql_array_append(var181.get(), var182.get());

    ReQL_Obj_c var183;
    reql_number_init(var183.get(), 41);

    reql_array_append(var181.get(), var183.get());

    reql_array_append(var180.get(), var181.get());

    ReQL_Obj_c var184;
    reql_number_init(var184.get(), 1);

    reql_array_append(var180.get(), var184.get());

    reql_array_append(var4.get(), var180.get());

    ReQL_Obj_c var185;
    _C::CTypes::array arr185(new ReQL_Obj_t*[2]);
    reql_array_init(var185.get(), arr185.get(), 2);

    ReQL_Obj_c var186;
    _C::CTypes::array arr186(new ReQL_Obj_t*[2]);
    reql_array_init(var186.get(), arr186.get(), 2);

    ReQL_Obj_c var187;
    reql_number_init(var187.get(), 1);

    reql_array_append(var186.get(), var187.get());

    ReQL_Obj_c var188;
    reql_number_init(var188.get(), 45);

    reql_array_append(var186.get(), var188.get());

    reql_array_append(var185.get(), var186.get());

    ReQL_Obj_c var189;
    reql_number_init(var189.get(), 1);

    reql_array_append(var185.get(), var189.get());

    reql_array_append(var4.get(), var185.get());

    ReQL_Obj_c var190;
    _C::CTypes::array arr190(new ReQL_Obj_t*[2]);
    reql_array_init(var190.get(), arr190.get(), 2);

    ReQL_Obj_c var191;
    _C::CTypes::array arr191(new ReQL_Obj_t*[2]);
    reql_array_init(var191.get(), arr191.get(), 2);

    ReQL_Obj_c var192;
    reql_number_init(var192.get(), 1);

    reql_array_append(var191.get(), var192.get());

    ReQL_Obj_c var193;
    reql_number_init(var193.get(), 49);

    reql_array_append(var191.get(), var193.get());

    reql_array_append(var190.get(), var191.get());

    ReQL_Obj_c var194;
    reql_number_init(var194.get(), 1);

    reql_array_append(var190.get(), var194.get());

    reql_array_append(var4.get(), var190.get());

    ReQL_Obj_c var195;
    _C::CTypes::array arr195(new ReQL_Obj_t*[2]);
    reql_array_init(var195.get(), arr195.get(), 2);

    ReQL_Obj_c var196;
    _C::CTypes::array arr196(new ReQL_Obj_t*[2]);
    reql_array_init(var196.get(), arr196.get(), 2);

    ReQL_Obj_c var197;
    reql_number_init(var197.get(), 1);

    reql_array_append(var196.get(), var197.get());

    ReQL_Obj_c var198;
    reql_number_init(var198.get(), 53);

    reql_array_append(var196.get(), var198.get());

    reql_array_append(var195.get(), var196.get());

    ReQL_Obj_c var199;
    reql_number_init(var199.get(), 1);

    reql_array_append(var195.get(), var199.get());

    reql_array_append(var4.get(), var195.get());

    ReQL_Obj_c var200;
    _C::CTypes::array arr200(new ReQL_Obj_t*[2]);
    reql_array_init(var200.get(), arr200.get(), 2);

    ReQL_Obj_c var201;
    _C::CTypes::array arr201(new ReQL_Obj_t*[2]);
    reql_array_init(var201.get(), arr201.get(), 2);

    ReQL_Obj_c var202;
    reql_number_init(var202.get(), 1);

    reql_array_append(var201.get(), var202.get());

    ReQL_Obj_c var203;
    reql_number_init(var203.get(), 57);

    reql_array_append(var201.get(), var203.get());

    reql_array_append(var200.get(), var201.get());

    ReQL_Obj_c var204;
    reql_number_init(var204.get(), 1);

    reql_array_append(var200.get(), var204.get());

    reql_array_append(var4.get(), var200.get());

    ReQL_Obj_c var205;
    _C::CTypes::array arr205(new ReQL_Obj_t*[2]);
    reql_array_init(var205.get(), arr205.get(), 2);

    ReQL_Obj_c var206;
    _C::CTypes::array arr206(new ReQL_Obj_t*[2]);
    reql_array_init(var206.get(), arr206.get(), 2);

    ReQL_Obj_c var207;
    reql_number_init(var207.get(), 1);

    reql_array_append(var206.get(), var207.get());

    ReQL_Obj_c var208;
    reql_number_init(var208.get(), 61);

    reql_array_append(var206.get(), var208.get());

    reql_array_append(var205.get(), var206.get());

    ReQL_Obj_c var209;
    reql_number_init(var209.get(), 1);

    reql_array_append(var205.get(), var209.get());

    reql_array_append(var4.get(), var205.get());

    ReQL_Obj_c var210;
    _C::CTypes::array arr210(new ReQL_Obj_t*[2]);
    reql_array_init(var210.get(), arr210.get(), 2);

    ReQL_Obj_c var211;
    _C::CTypes::array arr211(new ReQL_Obj_t*[2]);
    reql_array_init(var211.get(), arr211.get(), 2);

    ReQL_Obj_c var212;
    reql_number_init(var212.get(), 1);

    reql_array_append(var211.get(), var212.get());

    ReQL_Obj_c var213;
    reql_number_init(var213.get(), 65);

    reql_array_append(var211.get(), var213.get());

    reql_array_append(var210.get(), var211.get());

    ReQL_Obj_c var214;
    reql_number_init(var214.get(), 1);

    reql_array_append(var210.get(), var214.get());

    reql_array_append(var4.get(), var210.get());

    ReQL_Obj_c var215;
    _C::CTypes::array arr215(new ReQL_Obj_t*[2]);
    reql_array_init(var215.get(), arr215.get(), 2);

    ReQL_Obj_c var216;
    _C::CTypes::array arr216(new ReQL_Obj_t*[2]);
    reql_array_init(var216.get(), arr216.get(), 2);

    ReQL_Obj_c var217;
    reql_number_init(var217.get(), 1);

    reql_array_append(var216.get(), var217.get());

    ReQL_Obj_c var218;
    reql_number_init(var218.get(), 69);

    reql_array_append(var216.get(), var218.get());

    reql_array_append(var215.get(), var216.get());

    ReQL_Obj_c var219;
    reql_number_init(var219.get(), 1);

    reql_array_append(var215.get(), var219.get());

    reql_array_append(var4.get(), var215.get());

    ReQL_Obj_c var220;
    _C::CTypes::array arr220(new ReQL_Obj_t*[2]);
    reql_array_init(var220.get(), arr220.get(), 2);

    ReQL_Obj_c var221;
    _C::CTypes::array arr221(new ReQL_Obj_t*[2]);
    reql_array_init(var221.get(), arr221.get(), 2);

    ReQL_Obj_c var222;
    reql_number_init(var222.get(), 1);

    reql_array_append(var221.get(), var222.get());

    ReQL_Obj_c var223;
    reql_number_init(var223.get(), 73);

    reql_array_append(var221.get(), var223.get());

    reql_array_append(var220.get(), var221.get());

    ReQL_Obj_c var224;
    reql_number_init(var224.get(), 1);

    reql_array_append(var220.get(), var224.get());

    reql_array_append(var4.get(), var220.get());

    ReQL_Obj_c var225;
    _C::CTypes::array arr225(new ReQL_Obj_t*[2]);
    reql_array_init(var225.get(), arr225.get(), 2);

    ReQL_Obj_c var226;
    _C::CTypes::array arr226(new ReQL_Obj_t*[2]);
    reql_array_init(var226.get(), arr226.get(), 2);

    ReQL_Obj_c var227;
    reql_number_init(var227.get(), 1);

    reql_array_append(var226.get(), var227.get());

    ReQL_Obj_c var228;
    reql_number_init(var228.get(), 77);

    reql_array_append(var226.get(), var228.get());

    reql_array_append(var225.get(), var226.get());

    ReQL_Obj_c var229;
    reql_number_init(var229.get(), 1);

    reql_array_append(var225.get(), var229.get());

    reql_array_append(var4.get(), var225.get());

    ReQL_Obj_c var230;
    _C::CTypes::array arr230(new ReQL_Obj_t*[2]);
    reql_array_init(var230.get(), arr230.get(), 2);

    ReQL_Obj_c var231;
    _C::CTypes::array arr231(new ReQL_Obj_t*[2]);
    reql_array_init(var231.get(), arr231.get(), 2);

    ReQL_Obj_c var232;
    reql_number_init(var232.get(), 1);

    reql_array_append(var231.get(), var232.get());

    ReQL_Obj_c var233;
    reql_number_init(var233.get(), 81);

    reql_array_append(var231.get(), var233.get());

    reql_array_append(var230.get(), var231.get());

    ReQL_Obj_c var234;
    reql_number_init(var234.get(), 1);

    reql_array_append(var230.get(), var234.get());

    reql_array_append(var4.get(), var230.get());

    ReQL_Obj_c var235;
    _C::CTypes::array arr235(new ReQL_Obj_t*[2]);
    reql_array_init(var235.get(), arr235.get(), 2);

    ReQL_Obj_c var236;
    _C::CTypes::array arr236(new ReQL_Obj_t*[2]);
    reql_array_init(var236.get(), arr236.get(), 2);

    ReQL_Obj_c var237;
    reql_number_init(var237.get(), 1);

    reql_array_append(var236.get(), var237.get());

    ReQL_Obj_c var238;
    reql_number_init(var238.get(), 85);

    reql_array_append(var236.get(), var238.get());

    reql_array_append(var235.get(), var236.get());

    ReQL_Obj_c var239;
    reql_number_init(var239.get(), 1);

    reql_array_append(var235.get(), var239.get());

    reql_array_append(var4.get(), var235.get());

    ReQL_Obj_c var240;
    _C::CTypes::array arr240(new ReQL_Obj_t*[2]);
    reql_array_init(var240.get(), arr240.get(), 2);

    ReQL_Obj_c var241;
    _C::CTypes::array arr241(new ReQL_Obj_t*[2]);
    reql_array_init(var241.get(), arr241.get(), 2);

    ReQL_Obj_c var242;
    reql_number_init(var242.get(), 1);

    reql_array_append(var241.get(), var242.get());

    ReQL_Obj_c var243;
    reql_number_init(var243.get(), 89);

    reql_array_append(var241.get(), var243.get());

    reql_array_append(var240.get(), var241.get());

    ReQL_Obj_c var244;
    reql_number_init(var244.get(), 1);

    reql_array_append(var240.get(), var244.get());

    reql_array_append(var4.get(), var240.get());

    ReQL_Obj_c var245;
    _C::CTypes::array arr245(new ReQL_Obj_t*[2]);
    reql_array_init(var245.get(), arr245.get(), 2);

    ReQL_Obj_c var246;
    _C::CTypes::array arr246(new ReQL_Obj_t*[2]);
    reql_array_init(var246.get(), arr246.get(), 2);

    ReQL_Obj_c var247;
    reql_number_init(var247.get(), 1);

    reql_array_append(var246.get(), var247.get());

    ReQL_Obj_c var248;
    reql_number_init(var248.get(), 93);

    reql_array_append(var246.get(), var248.get());

    reql_array_append(var245.get(), var246.get());

    ReQL_Obj_c var249;
    reql_number_init(var249.get(), 1);

    reql_array_append(var245.get(), var249.get());

    reql_array_append(var4.get(), var245.get());

    ReQL_Obj_c var250;
    _C::CTypes::array arr250(new ReQL_Obj_t*[2]);
    reql_array_init(var250.get(), arr250.get(), 2);

    ReQL_Obj_c var251;
    _C::CTypes::array arr251(new ReQL_Obj_t*[2]);
    reql_array_init(var251.get(), arr251.get(), 2);

    ReQL_Obj_c var252;
    reql_number_init(var252.get(), 1);

    reql_array_append(var251.get(), var252.get());

    ReQL_Obj_c var253;
    reql_number_init(var253.get(), 97);

    reql_array_append(var251.get(), var253.get());

    reql_array_append(var250.get(), var251.get());

    ReQL_Obj_c var254;
    reql_number_init(var254.get(), 1);

    reql_array_append(var250.get(), var254.get());

    reql_array_append(var4.get(), var250.get());

    ReQL_Obj_c var255;
    _C::CTypes::array arr255(new ReQL_Obj_t*[2]);
    reql_array_init(var255.get(), arr255.get(), 2);

    ReQL_Obj_c var256;
    _C::CTypes::array arr256(new ReQL_Obj_t*[2]);
    reql_array_init(var256.get(), arr256.get(), 2);

    ReQL_Obj_c var257;
    reql_number_init(var257.get(), 2);

    reql_array_append(var256.get(), var257.get());

    ReQL_Obj_c var258;
    reql_number_init(var258.get(), 2);

    reql_array_append(var256.get(), var258.get());

    reql_array_append(var255.get(), var256.get());

    ReQL_Obj_c var259;
    reql_number_init(var259.get(), 1);

    reql_array_append(var255.get(), var259.get());

    reql_array_append(var4.get(), var255.get());

    ReQL_Obj_c var260;
    _C::CTypes::array arr260(new ReQL_Obj_t*[2]);
    reql_array_init(var260.get(), arr260.get(), 2);

    ReQL_Obj_c var261;
    _C::CTypes::array arr261(new ReQL_Obj_t*[2]);
    reql_array_init(var261.get(), arr261.get(), 2);

    ReQL_Obj_c var262;
    reql_number_init(var262.get(), 2);

    reql_array_append(var261.get(), var262.get());

    ReQL_Obj_c var263;
    reql_number_init(var263.get(), 6);

    reql_array_append(var261.get(), var263.get());

    reql_array_append(var260.get(), var261.get());

    ReQL_Obj_c var264;
    reql_number_init(var264.get(), 1);

    reql_array_append(var260.get(), var264.get());

    reql_array_append(var4.get(), var260.get());

    ReQL_Obj_c var265;
    _C::CTypes::array arr265(new ReQL_Obj_t*[2]);
    reql_array_init(var265.get(), arr265.get(), 2);

    ReQL_Obj_c var266;
    _C::CTypes::array arr266(new ReQL_Obj_t*[2]);
    reql_array_init(var266.get(), arr266.get(), 2);

    ReQL_Obj_c var267;
    reql_number_init(var267.get(), 2);

    reql_array_append(var266.get(), var267.get());

    ReQL_Obj_c var268;
    reql_number_init(var268.get(), 10);

    reql_array_append(var266.get(), var268.get());

    reql_array_append(var265.get(), var266.get());

    ReQL_Obj_c var269;
    reql_number_init(var269.get(), 1);

    reql_array_append(var265.get(), var269.get());

    reql_array_append(var4.get(), var265.get());

    ReQL_Obj_c var270;
    _C::CTypes::array arr270(new ReQL_Obj_t*[2]);
    reql_array_init(var270.get(), arr270.get(), 2);

    ReQL_Obj_c var271;
    _C::CTypes::array arr271(new ReQL_Obj_t*[2]);
    reql_array_init(var271.get(), arr271.get(), 2);

    ReQL_Obj_c var272;
    reql_number_init(var272.get(), 2);

    reql_array_append(var271.get(), var272.get());

    ReQL_Obj_c var273;
    reql_number_init(var273.get(), 14);

    reql_array_append(var271.get(), var273.get());

    reql_array_append(var270.get(), var271.get());

    ReQL_Obj_c var274;
    reql_number_init(var274.get(), 1);

    reql_array_append(var270.get(), var274.get());

    reql_array_append(var4.get(), var270.get());

    ReQL_Obj_c var275;
    _C::CTypes::array arr275(new ReQL_Obj_t*[2]);
    reql_array_init(var275.get(), arr275.get(), 2);

    ReQL_Obj_c var276;
    _C::CTypes::array arr276(new ReQL_Obj_t*[2]);
    reql_array_init(var276.get(), arr276.get(), 2);

    ReQL_Obj_c var277;
    reql_number_init(var277.get(), 2);

    reql_array_append(var276.get(), var277.get());

    ReQL_Obj_c var278;
    reql_number_init(var278.get(), 18);

    reql_array_append(var276.get(), var278.get());

    reql_array_append(var275.get(), var276.get());

    ReQL_Obj_c var279;
    reql_number_init(var279.get(), 1);

    reql_array_append(var275.get(), var279.get());

    reql_array_append(var4.get(), var275.get());

    ReQL_Obj_c var280;
    _C::CTypes::array arr280(new ReQL_Obj_t*[2]);
    reql_array_init(var280.get(), arr280.get(), 2);

    ReQL_Obj_c var281;
    _C::CTypes::array arr281(new ReQL_Obj_t*[2]);
    reql_array_init(var281.get(), arr281.get(), 2);

    ReQL_Obj_c var282;
    reql_number_init(var282.get(), 2);

    reql_array_append(var281.get(), var282.get());

    ReQL_Obj_c var283;
    reql_number_init(var283.get(), 22);

    reql_array_append(var281.get(), var283.get());

    reql_array_append(var280.get(), var281.get());

    ReQL_Obj_c var284;
    reql_number_init(var284.get(), 1);

    reql_array_append(var280.get(), var284.get());

    reql_array_append(var4.get(), var280.get());

    ReQL_Obj_c var285;
    _C::CTypes::array arr285(new ReQL_Obj_t*[2]);
    reql_array_init(var285.get(), arr285.get(), 2);

    ReQL_Obj_c var286;
    _C::CTypes::array arr286(new ReQL_Obj_t*[2]);
    reql_array_init(var286.get(), arr286.get(), 2);

    ReQL_Obj_c var287;
    reql_number_init(var287.get(), 2);

    reql_array_append(var286.get(), var287.get());

    ReQL_Obj_c var288;
    reql_number_init(var288.get(), 26);

    reql_array_append(var286.get(), var288.get());

    reql_array_append(var285.get(), var286.get());

    ReQL_Obj_c var289;
    reql_number_init(var289.get(), 1);

    reql_array_append(var285.get(), var289.get());

    reql_array_append(var4.get(), var285.get());

    ReQL_Obj_c var290;
    _C::CTypes::array arr290(new ReQL_Obj_t*[2]);
    reql_array_init(var290.get(), arr290.get(), 2);

    ReQL_Obj_c var291;
    _C::CTypes::array arr291(new ReQL_Obj_t*[2]);
    reql_array_init(var291.get(), arr291.get(), 2);

    ReQL_Obj_c var292;
    reql_number_init(var292.get(), 2);

    reql_array_append(var291.get(), var292.get());

    ReQL_Obj_c var293;
    reql_number_init(var293.get(), 30);

    reql_array_append(var291.get(), var293.get());

    reql_array_append(var290.get(), var291.get());

    ReQL_Obj_c var294;
    reql_number_init(var294.get(), 1);

    reql_array_append(var290.get(), var294.get());

    reql_array_append(var4.get(), var290.get());

    ReQL_Obj_c var295;
    _C::CTypes::array arr295(new ReQL_Obj_t*[2]);
    reql_array_init(var295.get(), arr295.get(), 2);

    ReQL_Obj_c var296;
    _C::CTypes::array arr296(new ReQL_Obj_t*[2]);
    reql_array_init(var296.get(), arr296.get(), 2);

    ReQL_Obj_c var297;
    reql_number_init(var297.get(), 2);

    reql_array_append(var296.get(), var297.get());

    ReQL_Obj_c var298;
    reql_number_init(var298.get(), 34);

    reql_array_append(var296.get(), var298.get());

    reql_array_append(var295.get(), var296.get());

    ReQL_Obj_c var299;
    reql_number_init(var299.get(), 1);

    reql_array_append(var295.get(), var299.get());

    reql_array_append(var4.get(), var295.get());

    ReQL_Obj_c var300;
    _C::CTypes::array arr300(new ReQL_Obj_t*[2]);
    reql_array_init(var300.get(), arr300.get(), 2);

    ReQL_Obj_c var301;
    _C::CTypes::array arr301(new ReQL_Obj_t*[2]);
    reql_array_init(var301.get(), arr301.get(), 2);

    ReQL_Obj_c var302;
    reql_number_init(var302.get(), 2);

    reql_array_append(var301.get(), var302.get());

    ReQL_Obj_c var303;
    reql_number_init(var303.get(), 38);

    reql_array_append(var301.get(), var303.get());

    reql_array_append(var300.get(), var301.get());

    ReQL_Obj_c var304;
    reql_number_init(var304.get(), 1);

    reql_array_append(var300.get(), var304.get());

    reql_array_append(var4.get(), var300.get());

    ReQL_Obj_c var305;
    _C::CTypes::array arr305(new ReQL_Obj_t*[2]);
    reql_array_init(var305.get(), arr305.get(), 2);

    ReQL_Obj_c var306;
    _C::CTypes::array arr306(new ReQL_Obj_t*[2]);
    reql_array_init(var306.get(), arr306.get(), 2);

    ReQL_Obj_c var307;
    reql_number_init(var307.get(), 2);

    reql_array_append(var306.get(), var307.get());

    ReQL_Obj_c var308;
    reql_number_init(var308.get(), 42);

    reql_array_append(var306.get(), var308.get());

    reql_array_append(var305.get(), var306.get());

    ReQL_Obj_c var309;
    reql_number_init(var309.get(), 1);

    reql_array_append(var305.get(), var309.get());

    reql_array_append(var4.get(), var305.get());

    ReQL_Obj_c var310;
    _C::CTypes::array arr310(new ReQL_Obj_t*[2]);
    reql_array_init(var310.get(), arr310.get(), 2);

    ReQL_Obj_c var311;
    _C::CTypes::array arr311(new ReQL_Obj_t*[2]);
    reql_array_init(var311.get(), arr311.get(), 2);

    ReQL_Obj_c var312;
    reql_number_init(var312.get(), 2);

    reql_array_append(var311.get(), var312.get());

    ReQL_Obj_c var313;
    reql_number_init(var313.get(), 46);

    reql_array_append(var311.get(), var313.get());

    reql_array_append(var310.get(), var311.get());

    ReQL_Obj_c var314;
    reql_number_init(var314.get(), 1);

    reql_array_append(var310.get(), var314.get());

    reql_array_append(var4.get(), var310.get());

    ReQL_Obj_c var315;
    _C::CTypes::array arr315(new ReQL_Obj_t*[2]);
    reql_array_init(var315.get(), arr315.get(), 2);

    ReQL_Obj_c var316;
    _C::CTypes::array arr316(new ReQL_Obj_t*[2]);
    reql_array_init(var316.get(), arr316.get(), 2);

    ReQL_Obj_c var317;
    reql_number_init(var317.get(), 2);

    reql_array_append(var316.get(), var317.get());

    ReQL_Obj_c var318;
    reql_number_init(var318.get(), 50);

    reql_array_append(var316.get(), var318.get());

    reql_array_append(var315.get(), var316.get());

    ReQL_Obj_c var319;
    reql_number_init(var319.get(), 1);

    reql_array_append(var315.get(), var319.get());

    reql_array_append(var4.get(), var315.get());

    ReQL_Obj_c var320;
    _C::CTypes::array arr320(new ReQL_Obj_t*[2]);
    reql_array_init(var320.get(), arr320.get(), 2);

    ReQL_Obj_c var321;
    _C::CTypes::array arr321(new ReQL_Obj_t*[2]);
    reql_array_init(var321.get(), arr321.get(), 2);

    ReQL_Obj_c var322;
    reql_number_init(var322.get(), 2);

    reql_array_append(var321.get(), var322.get());

    ReQL_Obj_c var323;
    reql_number_init(var323.get(), 54);

    reql_array_append(var321.get(), var323.get());

    reql_array_append(var320.get(), var321.get());

    ReQL_Obj_c var324;
    reql_number_init(var324.get(), 1);

    reql_array_append(var320.get(), var324.get());

    reql_array_append(var4.get(), var320.get());

    ReQL_Obj_c var325;
    _C::CTypes::array arr325(new ReQL_Obj_t*[2]);
    reql_array_init(var325.get(), arr325.get(), 2);

    ReQL_Obj_c var326;
    _C::CTypes::array arr326(new ReQL_Obj_t*[2]);
    reql_array_init(var326.get(), arr326.get(), 2);

    ReQL_Obj_c var327;
    reql_number_init(var327.get(), 2);

    reql_array_append(var326.get(), var327.get());

    ReQL_Obj_c var328;
    reql_number_init(var328.get(), 58);

    reql_array_append(var326.get(), var328.get());

    reql_array_append(var325.get(), var326.get());

    ReQL_Obj_c var329;
    reql_number_init(var329.get(), 1);

    reql_array_append(var325.get(), var329.get());

    reql_array_append(var4.get(), var325.get());

    ReQL_Obj_c var330;
    _C::CTypes::array arr330(new ReQL_Obj_t*[2]);
    reql_array_init(var330.get(), arr330.get(), 2);

    ReQL_Obj_c var331;
    _C::CTypes::array arr331(new ReQL_Obj_t*[2]);
    reql_array_init(var331.get(), arr331.get(), 2);

    ReQL_Obj_c var332;
    reql_number_init(var332.get(), 2);

    reql_array_append(var331.get(), var332.get());

    ReQL_Obj_c var333;
    reql_number_init(var333.get(), 62);

    reql_array_append(var331.get(), var333.get());

    reql_array_append(var330.get(), var331.get());

    ReQL_Obj_c var334;
    reql_number_init(var334.get(), 1);

    reql_array_append(var330.get(), var334.get());

    reql_array_append(var4.get(), var330.get());

    ReQL_Obj_c var335;
    _C::CTypes::array arr335(new ReQL_Obj_t*[2]);
    reql_array_init(var335.get(), arr335.get(), 2);

    ReQL_Obj_c var336;
    _C::CTypes::array arr336(new ReQL_Obj_t*[2]);
    reql_array_init(var336.get(), arr336.get(), 2);

    ReQL_Obj_c var337;
    reql_number_init(var337.get(), 2);

    reql_array_append(var336.get(), var337.get());

    ReQL_Obj_c var338;
    reql_number_init(var338.get(), 66);

    reql_array_append(var336.get(), var338.get());

    reql_array_append(var335.get(), var336.get());

    ReQL_Obj_c var339;
    reql_number_init(var339.get(), 1);

    reql_array_append(var335.get(), var339.get());

    reql_array_append(var4.get(), var335.get());

    ReQL_Obj_c var340;
    _C::CTypes::array arr340(new ReQL_Obj_t*[2]);
    reql_array_init(var340.get(), arr340.get(), 2);

    ReQL_Obj_c var341;
    _C::CTypes::array arr341(new ReQL_Obj_t*[2]);
    reql_array_init(var341.get(), arr341.get(), 2);

    ReQL_Obj_c var342;
    reql_number_init(var342.get(), 2);

    reql_array_append(var341.get(), var342.get());

    ReQL_Obj_c var343;
    reql_number_init(var343.get(), 70);

    reql_array_append(var341.get(), var343.get());

    reql_array_append(var340.get(), var341.get());

    ReQL_Obj_c var344;
    reql_number_init(var344.get(), 1);

    reql_array_append(var340.get(), var344.get());

    reql_array_append(var4.get(), var340.get());

    ReQL_Obj_c var345;
    _C::CTypes::array arr345(new ReQL_Obj_t*[2]);
    reql_array_init(var345.get(), arr345.get(), 2);

    ReQL_Obj_c var346;
    _C::CTypes::array arr346(new ReQL_Obj_t*[2]);
    reql_array_init(var346.get(), arr346.get(), 2);

    ReQL_Obj_c var347;
    reql_number_init(var347.get(), 2);

    reql_array_append(var346.get(), var347.get());

    ReQL_Obj_c var348;
    reql_number_init(var348.get(), 74);

    reql_array_append(var346.get(), var348.get());

    reql_array_append(var345.get(), var346.get());

    ReQL_Obj_c var349;
    reql_number_init(var349.get(), 1);

    reql_array_append(var345.get(), var349.get());

    reql_array_append(var4.get(), var345.get());

    ReQL_Obj_c var350;
    _C::CTypes::array arr350(new ReQL_Obj_t*[2]);
    reql_array_init(var350.get(), arr350.get(), 2);

    ReQL_Obj_c var351;
    _C::CTypes::array arr351(new ReQL_Obj_t*[2]);
    reql_array_init(var351.get(), arr351.get(), 2);

    ReQL_Obj_c var352;
    reql_number_init(var352.get(), 2);

    reql_array_append(var351.get(), var352.get());

    ReQL_Obj_c var353;
    reql_number_init(var353.get(), 78);

    reql_array_append(var351.get(), var353.get());

    reql_array_append(var350.get(), var351.get());

    ReQL_Obj_c var354;
    reql_number_init(var354.get(), 1);

    reql_array_append(var350.get(), var354.get());

    reql_array_append(var4.get(), var350.get());

    ReQL_Obj_c var355;
    _C::CTypes::array arr355(new ReQL_Obj_t*[2]);
    reql_array_init(var355.get(), arr355.get(), 2);

    ReQL_Obj_c var356;
    _C::CTypes::array arr356(new ReQL_Obj_t*[2]);
    reql_array_init(var356.get(), arr356.get(), 2);

    ReQL_Obj_c var357;
    reql_number_init(var357.get(), 2);

    reql_array_append(var356.get(), var357.get());

    ReQL_Obj_c var358;
    reql_number_init(var358.get(), 82);

    reql_array_append(var356.get(), var358.get());

    reql_array_append(var355.get(), var356.get());

    ReQL_Obj_c var359;
    reql_number_init(var359.get(), 1);

    reql_array_append(var355.get(), var359.get());

    reql_array_append(var4.get(), var355.get());

    ReQL_Obj_c var360;
    _C::CTypes::array arr360(new ReQL_Obj_t*[2]);
    reql_array_init(var360.get(), arr360.get(), 2);

    ReQL_Obj_c var361;
    _C::CTypes::array arr361(new ReQL_Obj_t*[2]);
    reql_array_init(var361.get(), arr361.get(), 2);

    ReQL_Obj_c var362;
    reql_number_init(var362.get(), 2);

    reql_array_append(var361.get(), var362.get());

    ReQL_Obj_c var363;
    reql_number_init(var363.get(), 86);

    reql_array_append(var361.get(), var363.get());

    reql_array_append(var360.get(), var361.get());

    ReQL_Obj_c var364;
    reql_number_init(var364.get(), 1);

    reql_array_append(var360.get(), var364.get());

    reql_array_append(var4.get(), var360.get());

    ReQL_Obj_c var365;
    _C::CTypes::array arr365(new ReQL_Obj_t*[2]);
    reql_array_init(var365.get(), arr365.get(), 2);

    ReQL_Obj_c var366;
    _C::CTypes::array arr366(new ReQL_Obj_t*[2]);
    reql_array_init(var366.get(), arr366.get(), 2);

    ReQL_Obj_c var367;
    reql_number_init(var367.get(), 2);

    reql_array_append(var366.get(), var367.get());

    ReQL_Obj_c var368;
    reql_number_init(var368.get(), 90);

    reql_array_append(var366.get(), var368.get());

    reql_array_append(var365.get(), var366.get());

    ReQL_Obj_c var369;
    reql_number_init(var369.get(), 1);

    reql_array_append(var365.get(), var369.get());

    reql_array_append(var4.get(), var365.get());

    ReQL_Obj_c var370;
    _C::CTypes::array arr370(new ReQL_Obj_t*[2]);
    reql_array_init(var370.get(), arr370.get(), 2);

    ReQL_Obj_c var371;
    _C::CTypes::array arr371(new ReQL_Obj_t*[2]);
    reql_array_init(var371.get(), arr371.get(), 2);

    ReQL_Obj_c var372;
    reql_number_init(var372.get(), 2);

    reql_array_append(var371.get(), var372.get());

    ReQL_Obj_c var373;
    reql_number_init(var373.get(), 94);

    reql_array_append(var371.get(), var373.get());

    reql_array_append(var370.get(), var371.get());

    ReQL_Obj_c var374;
    reql_number_init(var374.get(), 1);

    reql_array_append(var370.get(), var374.get());

    reql_array_append(var4.get(), var370.get());

    ReQL_Obj_c var375;
    _C::CTypes::array arr375(new ReQL_Obj_t*[2]);
    reql_array_init(var375.get(), arr375.get(), 2);

    ReQL_Obj_c var376;
    _C::CTypes::array arr376(new ReQL_Obj_t*[2]);
    reql_array_init(var376.get(), arr376.get(), 2);

    ReQL_Obj_c var377;
    reql_number_init(var377.get(), 2);

    reql_array_append(var376.get(), var377.get());

    ReQL_Obj_c var378;
    reql_number_init(var378.get(), 98);

    reql_array_append(var376.get(), var378.get());

    reql_array_append(var375.get(), var376.get());

    ReQL_Obj_c var379;
    reql_number_init(var379.get(), 1);

    reql_array_append(var375.get(), var379.get());

    reql_array_append(var4.get(), var375.get());

    ReQL_Obj_c var380;
    _C::CTypes::array arr380(new ReQL_Obj_t*[2]);
    reql_array_init(var380.get(), arr380.get(), 2);

    ReQL_Obj_c var381;
    _C::CTypes::array arr381(new ReQL_Obj_t*[2]);
    reql_array_init(var381.get(), arr381.get(), 2);

    ReQL_Obj_c var382;
    reql_number_init(var382.get(), 3);

    reql_array_append(var381.get(), var382.get());

    ReQL_Obj_c var383;
    reql_number_init(var383.get(), 3);

    reql_array_append(var381.get(), var383.get());

    reql_array_append(var380.get(), var381.get());

    ReQL_Obj_c var384;
    reql_number_init(var384.get(), 1);

    reql_array_append(var380.get(), var384.get());

    reql_array_append(var4.get(), var380.get());

    ReQL_Obj_c var385;
    _C::CTypes::array arr385(new ReQL_Obj_t*[2]);
    reql_array_init(var385.get(), arr385.get(), 2);

    ReQL_Obj_c var386;
    _C::CTypes::array arr386(new ReQL_Obj_t*[2]);
    reql_array_init(var386.get(), arr386.get(), 2);

    ReQL_Obj_c var387;
    reql_number_init(var387.get(), 3);

    reql_array_append(var386.get(), var387.get());

    ReQL_Obj_c var388;
    reql_number_init(var388.get(), 7);

    reql_array_append(var386.get(), var388.get());

    reql_array_append(var385.get(), var386.get());

    ReQL_Obj_c var389;
    reql_number_init(var389.get(), 1);

    reql_array_append(var385.get(), var389.get());

    reql_array_append(var4.get(), var385.get());

    ReQL_Obj_c var390;
    _C::CTypes::array arr390(new ReQL_Obj_t*[2]);
    reql_array_init(var390.get(), arr390.get(), 2);

    ReQL_Obj_c var391;
    _C::CTypes::array arr391(new ReQL_Obj_t*[2]);
    reql_array_init(var391.get(), arr391.get(), 2);

    ReQL_Obj_c var392;
    reql_number_init(var392.get(), 3);

    reql_array_append(var391.get(), var392.get());

    ReQL_Obj_c var393;
    reql_number_init(var393.get(), 11);

    reql_array_append(var391.get(), var393.get());

    reql_array_append(var390.get(), var391.get());

    ReQL_Obj_c var394;
    reql_number_init(var394.get(), 1);

    reql_array_append(var390.get(), var394.get());

    reql_array_append(var4.get(), var390.get());

    ReQL_Obj_c var395;
    _C::CTypes::array arr395(new ReQL_Obj_t*[2]);
    reql_array_init(var395.get(), arr395.get(), 2);

    ReQL_Obj_c var396;
    _C::CTypes::array arr396(new ReQL_Obj_t*[2]);
    reql_array_init(var396.get(), arr396.get(), 2);

    ReQL_Obj_c var397;
    reql_number_init(var397.get(), 3);

    reql_array_append(var396.get(), var397.get());

    ReQL_Obj_c var398;
    reql_number_init(var398.get(), 15);

    reql_array_append(var396.get(), var398.get());

    reql_array_append(var395.get(), var396.get());

    ReQL_Obj_c var399;
    reql_number_init(var399.get(), 1);

    reql_array_append(var395.get(), var399.get());

    reql_array_append(var4.get(), var395.get());

    ReQL_Obj_c var400;
    _C::CTypes::array arr400(new ReQL_Obj_t*[2]);
    reql_array_init(var400.get(), arr400.get(), 2);

    ReQL_Obj_c var401;
    _C::CTypes::array arr401(new ReQL_Obj_t*[2]);
    reql_array_init(var401.get(), arr401.get(), 2);

    ReQL_Obj_c var402;
    reql_number_init(var402.get(), 3);

    reql_array_append(var401.get(), var402.get());

    ReQL_Obj_c var403;
    reql_number_init(var403.get(), 19);

    reql_array_append(var401.get(), var403.get());

    reql_array_append(var400.get(), var401.get());

    ReQL_Obj_c var404;
    reql_number_init(var404.get(), 1);

    reql_array_append(var400.get(), var404.get());

    reql_array_append(var4.get(), var400.get());

    ReQL_Obj_c var405;
    _C::CTypes::array arr405(new ReQL_Obj_t*[2]);
    reql_array_init(var405.get(), arr405.get(), 2);

    ReQL_Obj_c var406;
    _C::CTypes::array arr406(new ReQL_Obj_t*[2]);
    reql_array_init(var406.get(), arr406.get(), 2);

    ReQL_Obj_c var407;
    reql_number_init(var407.get(), 3);

    reql_array_append(var406.get(), var407.get());

    ReQL_Obj_c var408;
    reql_number_init(var408.get(), 23);

    reql_array_append(var406.get(), var408.get());

    reql_array_append(var405.get(), var406.get());

    ReQL_Obj_c var409;
    reql_number_init(var409.get(), 1);

    reql_array_append(var405.get(), var409.get());

    reql_array_append(var4.get(), var405.get());

    ReQL_Obj_c var410;
    _C::CTypes::array arr410(new ReQL_Obj_t*[2]);
    reql_array_init(var410.get(), arr410.get(), 2);

    ReQL_Obj_c var411;
    _C::CTypes::array arr411(new ReQL_Obj_t*[2]);
    reql_array_init(var411.get(), arr411.get(), 2);

    ReQL_Obj_c var412;
    reql_number_init(var412.get(), 3);

    reql_array_append(var411.get(), var412.get());

    ReQL_Obj_c var413;
    reql_number_init(var413.get(), 27);

    reql_array_append(var411.get(), var413.get());

    reql_array_append(var410.get(), var411.get());

    ReQL_Obj_c var414;
    reql_number_init(var414.get(), 1);

    reql_array_append(var410.get(), var414.get());

    reql_array_append(var4.get(), var410.get());

    ReQL_Obj_c var415;
    _C::CTypes::array arr415(new ReQL_Obj_t*[2]);
    reql_array_init(var415.get(), arr415.get(), 2);

    ReQL_Obj_c var416;
    _C::CTypes::array arr416(new ReQL_Obj_t*[2]);
    reql_array_init(var416.get(), arr416.get(), 2);

    ReQL_Obj_c var417;
    reql_number_init(var417.get(), 3);

    reql_array_append(var416.get(), var417.get());

    ReQL_Obj_c var418;
    reql_number_init(var418.get(), 31);

    reql_array_append(var416.get(), var418.get());

    reql_array_append(var415.get(), var416.get());

    ReQL_Obj_c var419;
    reql_number_init(var419.get(), 1);

    reql_array_append(var415.get(), var419.get());

    reql_array_append(var4.get(), var415.get());

    ReQL_Obj_c var420;
    _C::CTypes::array arr420(new ReQL_Obj_t*[2]);
    reql_array_init(var420.get(), arr420.get(), 2);

    ReQL_Obj_c var421;
    _C::CTypes::array arr421(new ReQL_Obj_t*[2]);
    reql_array_init(var421.get(), arr421.get(), 2);

    ReQL_Obj_c var422;
    reql_number_init(var422.get(), 3);

    reql_array_append(var421.get(), var422.get());

    ReQL_Obj_c var423;
    reql_number_init(var423.get(), 35);

    reql_array_append(var421.get(), var423.get());

    reql_array_append(var420.get(), var421.get());

    ReQL_Obj_c var424;
    reql_number_init(var424.get(), 1);

    reql_array_append(var420.get(), var424.get());

    reql_array_append(var4.get(), var420.get());

    ReQL_Obj_c var425;
    _C::CTypes::array arr425(new ReQL_Obj_t*[2]);
    reql_array_init(var425.get(), arr425.get(), 2);

    ReQL_Obj_c var426;
    _C::CTypes::array arr426(new ReQL_Obj_t*[2]);
    reql_array_init(var426.get(), arr426.get(), 2);

    ReQL_Obj_c var427;
    reql_number_init(var427.get(), 3);

    reql_array_append(var426.get(), var427.get());

    ReQL_Obj_c var428;
    reql_number_init(var428.get(), 39);

    reql_array_append(var426.get(), var428.get());

    reql_array_append(var425.get(), var426.get());

    ReQL_Obj_c var429;
    reql_number_init(var429.get(), 1);

    reql_array_append(var425.get(), var429.get());

    reql_array_append(var4.get(), var425.get());

    ReQL_Obj_c var430;
    _C::CTypes::array arr430(new ReQL_Obj_t*[2]);
    reql_array_init(var430.get(), arr430.get(), 2);

    ReQL_Obj_c var431;
    _C::CTypes::array arr431(new ReQL_Obj_t*[2]);
    reql_array_init(var431.get(), arr431.get(), 2);

    ReQL_Obj_c var432;
    reql_number_init(var432.get(), 3);

    reql_array_append(var431.get(), var432.get());

    ReQL_Obj_c var433;
    reql_number_init(var433.get(), 43);

    reql_array_append(var431.get(), var433.get());

    reql_array_append(var430.get(), var431.get());

    ReQL_Obj_c var434;
    reql_number_init(var434.get(), 1);

    reql_array_append(var430.get(), var434.get());

    reql_array_append(var4.get(), var430.get());

    ReQL_Obj_c var435;
    _C::CTypes::array arr435(new ReQL_Obj_t*[2]);
    reql_array_init(var435.get(), arr435.get(), 2);

    ReQL_Obj_c var436;
    _C::CTypes::array arr436(new ReQL_Obj_t*[2]);
    reql_array_init(var436.get(), arr436.get(), 2);

    ReQL_Obj_c var437;
    reql_number_init(var437.get(), 3);

    reql_array_append(var436.get(), var437.get());

    ReQL_Obj_c var438;
    reql_number_init(var438.get(), 47);

    reql_array_append(var436.get(), var438.get());

    reql_array_append(var435.get(), var436.get());

    ReQL_Obj_c var439;
    reql_number_init(var439.get(), 1);

    reql_array_append(var435.get(), var439.get());

    reql_array_append(var4.get(), var435.get());

    ReQL_Obj_c var440;
    _C::CTypes::array arr440(new ReQL_Obj_t*[2]);
    reql_array_init(var440.get(), arr440.get(), 2);

    ReQL_Obj_c var441;
    _C::CTypes::array arr441(new ReQL_Obj_t*[2]);
    reql_array_init(var441.get(), arr441.get(), 2);

    ReQL_Obj_c var442;
    reql_number_init(var442.get(), 3);

    reql_array_append(var441.get(), var442.get());

    ReQL_Obj_c var443;
    reql_number_init(var443.get(), 51);

    reql_array_append(var441.get(), var443.get());

    reql_array_append(var440.get(), var441.get());

    ReQL_Obj_c var444;
    reql_number_init(var444.get(), 1);

    reql_array_append(var440.get(), var444.get());

    reql_array_append(var4.get(), var440.get());

    ReQL_Obj_c var445;
    _C::CTypes::array arr445(new ReQL_Obj_t*[2]);
    reql_array_init(var445.get(), arr445.get(), 2);

    ReQL_Obj_c var446;
    _C::CTypes::array arr446(new ReQL_Obj_t*[2]);
    reql_array_init(var446.get(), arr446.get(), 2);

    ReQL_Obj_c var447;
    reql_number_init(var447.get(), 3);

    reql_array_append(var446.get(), var447.get());

    ReQL_Obj_c var448;
    reql_number_init(var448.get(), 55);

    reql_array_append(var446.get(), var448.get());

    reql_array_append(var445.get(), var446.get());

    ReQL_Obj_c var449;
    reql_number_init(var449.get(), 1);

    reql_array_append(var445.get(), var449.get());

    reql_array_append(var4.get(), var445.get());

    ReQL_Obj_c var450;
    _C::CTypes::array arr450(new ReQL_Obj_t*[2]);
    reql_array_init(var450.get(), arr450.get(), 2);

    ReQL_Obj_c var451;
    _C::CTypes::array arr451(new ReQL_Obj_t*[2]);
    reql_array_init(var451.get(), arr451.get(), 2);

    ReQL_Obj_c var452;
    reql_number_init(var452.get(), 3);

    reql_array_append(var451.get(), var452.get());

    ReQL_Obj_c var453;
    reql_number_init(var453.get(), 59);

    reql_array_append(var451.get(), var453.get());

    reql_array_append(var450.get(), var451.get());

    ReQL_Obj_c var454;
    reql_number_init(var454.get(), 1);

    reql_array_append(var450.get(), var454.get());

    reql_array_append(var4.get(), var450.get());

    ReQL_Obj_c var455;
    _C::CTypes::array arr455(new ReQL_Obj_t*[2]);
    reql_array_init(var455.get(), arr455.get(), 2);

    ReQL_Obj_c var456;
    _C::CTypes::array arr456(new ReQL_Obj_t*[2]);
    reql_array_init(var456.get(), arr456.get(), 2);

    ReQL_Obj_c var457;
    reql_number_init(var457.get(), 3);

    reql_array_append(var456.get(), var457.get());

    ReQL_Obj_c var458;
    reql_number_init(var458.get(), 63);

    reql_array_append(var456.get(), var458.get());

    reql_array_append(var455.get(), var456.get());

    ReQL_Obj_c var459;
    reql_number_init(var459.get(), 1);

    reql_array_append(var455.get(), var459.get());

    reql_array_append(var4.get(), var455.get());

    ReQL_Obj_c var460;
    _C::CTypes::array arr460(new ReQL_Obj_t*[2]);
    reql_array_init(var460.get(), arr460.get(), 2);

    ReQL_Obj_c var461;
    _C::CTypes::array arr461(new ReQL_Obj_t*[2]);
    reql_array_init(var461.get(), arr461.get(), 2);

    ReQL_Obj_c var462;
    reql_number_init(var462.get(), 3);

    reql_array_append(var461.get(), var462.get());

    ReQL_Obj_c var463;
    reql_number_init(var463.get(), 67);

    reql_array_append(var461.get(), var463.get());

    reql_array_append(var460.get(), var461.get());

    ReQL_Obj_c var464;
    reql_number_init(var464.get(), 1);

    reql_array_append(var460.get(), var464.get());

    reql_array_append(var4.get(), var460.get());

    ReQL_Obj_c var465;
    _C::CTypes::array arr465(new ReQL_Obj_t*[2]);
    reql_array_init(var465.get(), arr465.get(), 2);

    ReQL_Obj_c var466;
    _C::CTypes::array arr466(new ReQL_Obj_t*[2]);
    reql_array_init(var466.get(), arr466.get(), 2);

    ReQL_Obj_c var467;
    reql_number_init(var467.get(), 3);

    reql_array_append(var466.get(), var467.get());

    ReQL_Obj_c var468;
    reql_number_init(var468.get(), 71);

    reql_array_append(var466.get(), var468.get());

    reql_array_append(var465.get(), var466.get());

    ReQL_Obj_c var469;
    reql_number_init(var469.get(), 1);

    reql_array_append(var465.get(), var469.get());

    reql_array_append(var4.get(), var465.get());

    ReQL_Obj_c var470;
    _C::CTypes::array arr470(new ReQL_Obj_t*[2]);
    reql_array_init(var470.get(), arr470.get(), 2);

    ReQL_Obj_c var471;
    _C::CTypes::array arr471(new ReQL_Obj_t*[2]);
    reql_array_init(var471.get(), arr471.get(), 2);

    ReQL_Obj_c var472;
    reql_number_init(var472.get(), 3);

    reql_array_append(var471.get(), var472.get());

    ReQL_Obj_c var473;
    reql_number_init(var473.get(), 75);

    reql_array_append(var471.get(), var473.get());

    reql_array_append(var470.get(), var471.get());

    ReQL_Obj_c var474;
    reql_number_init(var474.get(), 1);

    reql_array_append(var470.get(), var474.get());

    reql_array_append(var4.get(), var470.get());

    ReQL_Obj_c var475;
    _C::CTypes::array arr475(new ReQL_Obj_t*[2]);
    reql_array_init(var475.get(), arr475.get(), 2);

    ReQL_Obj_c var476;
    _C::CTypes::array arr476(new ReQL_Obj_t*[2]);
    reql_array_init(var476.get(), arr476.get(), 2);

    ReQL_Obj_c var477;
    reql_number_init(var477.get(), 3);

    reql_array_append(var476.get(), var477.get());

    ReQL_Obj_c var478;
    reql_number_init(var478.get(), 79);

    reql_array_append(var476.get(), var478.get());

    reql_array_append(var475.get(), var476.get());

    ReQL_Obj_c var479;
    reql_number_init(var479.get(), 1);

    reql_array_append(var475.get(), var479.get());

    reql_array_append(var4.get(), var475.get());

    ReQL_Obj_c var480;
    _C::CTypes::array arr480(new ReQL_Obj_t*[2]);
    reql_array_init(var480.get(), arr480.get(), 2);

    ReQL_Obj_c var481;
    _C::CTypes::array arr481(new ReQL_Obj_t*[2]);
    reql_array_init(var481.get(), arr481.get(), 2);

    ReQL_Obj_c var482;
    reql_number_init(var482.get(), 3);

    reql_array_append(var481.get(), var482.get());

    ReQL_Obj_c var483;
    reql_number_init(var483.get(), 83);

    reql_array_append(var481.get(), var483.get());

    reql_array_append(var480.get(), var481.get());

    ReQL_Obj_c var484;
    reql_number_init(var484.get(), 1);

    reql_array_append(var480.get(), var484.get());

    reql_array_append(var4.get(), var480.get());

    ReQL_Obj_c var485;
    _C::CTypes::array arr485(new ReQL_Obj_t*[2]);
    reql_array_init(var485.get(), arr485.get(), 2);

    ReQL_Obj_c var486;
    _C::CTypes::array arr486(new ReQL_Obj_t*[2]);
    reql_array_init(var486.get(), arr486.get(), 2);

    ReQL_Obj_c var487;
    reql_number_init(var487.get(), 3);

    reql_array_append(var486.get(), var487.get());

    ReQL_Obj_c var488;
    reql_number_init(var488.get(), 87);

    reql_array_append(var486.get(), var488.get());

    reql_array_append(var485.get(), var486.get());

    ReQL_Obj_c var489;
    reql_number_init(var489.get(), 1);

    reql_array_append(var485.get(), var489.get());

    reql_array_append(var4.get(), var485.get());

    ReQL_Obj_c var490;
    _C::CTypes::array arr490(new ReQL_Obj_t*[2]);
    reql_array_init(var490.get(), arr490.get(), 2);

    ReQL_Obj_c var491;
    _C::CTypes::array arr491(new ReQL_Obj_t*[2]);
    reql_array_init(var491.get(), arr491.get(), 2);

    ReQL_Obj_c var492;
    reql_number_init(var492.get(), 3);

    reql_array_append(var491.get(), var492.get());

    ReQL_Obj_c var493;
    reql_number_init(var493.get(), 91);

    reql_array_append(var491.get(), var493.get());

    reql_array_append(var490.get(), var491.get());

    ReQL_Obj_c var494;
    reql_number_init(var494.get(), 1);

    reql_array_append(var490.get(), var494.get());

    reql_array_append(var4.get(), var490.get());

    ReQL_Obj_c var495;
    _C::CTypes::array arr495(new ReQL_Obj_t*[2]);
    reql_array_init(var495.get(), arr495.get(), 2);

    ReQL_Obj_c var496;
    _C::CTypes::array arr496(new ReQL_Obj_t*[2]);
    reql_array_init(var496.get(), arr496.get(), 2);

    ReQL_Obj_c var497;
    reql_number_init(var497.get(), 3);

    reql_array_append(var496.get(), var497.get());

    ReQL_Obj_c var498;
    reql_number_init(var498.get(), 95);

    reql_array_append(var496.get(), var498.get());

    reql_array_append(var495.get(), var496.get());

    ReQL_Obj_c var499;
    reql_number_init(var499.get(), 1);

    reql_array_append(var495.get(), var499.get());

    reql_array_append(var4.get(), var495.get());

    ReQL_Obj_c var500;
    _C::CTypes::array arr500(new ReQL_Obj_t*[2]);
    reql_array_init(var500.get(), arr500.get(), 2);

    ReQL_Obj_c var501;
    _C::CTypes::array arr501(new ReQL_Obj_t*[2]);
    reql_array_init(var501.get(), arr501.get(), 2);

    ReQL_Obj_c var502;
    reql_number_init(var502.get(), 3);

    reql_array_append(var501.get(), var502.get());

    ReQL_Obj_c var503;
    reql_number_init(var503.get(), 99);

    reql_array_append(var501.get(), var503.get());

    reql_array_append(var500.get(), var501.get());

    ReQL_Obj_c var504;
    reql_number_init(var504.get(), 1);

    reql_array_append(var500.get(), var504.get());

    reql_array_append(var4.get(), var500.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test87") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[4]);
    reql_array_init(var4.get(), arr4.get(), 4);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

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
    reql_number_init(var9.get(), 25);

    reql_array_append(var5.get(), var9.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var10;
    _C::CTypes::array arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    ReQL_Obj_c var11;
    _C::CTypes::array arr11(new ReQL_Obj_t*[2]);
    reql_array_init(var11.get(), arr11.get(), 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_array_append(var11.get(), var12.get());

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1);

    reql_array_append(var11.get(), var13.get());

    reql_array_append(var10.get(), var11.get());

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 25);

    reql_array_append(var10.get(), var14.get());

    reql_array_append(var4.get(), var10.get());

    ReQL_Obj_c var15;
    _C::CTypes::array arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    ReQL_Obj_c var16;
    _C::CTypes::array arr16(new ReQL_Obj_t*[2]);
    reql_array_init(var16.get(), arr16.get(), 2);

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 2);

    reql_array_append(var16.get(), var17.get());

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 2);

    reql_array_append(var16.get(), var18.get());

    reql_array_append(var15.get(), var16.get());

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 25);

    reql_array_append(var15.get(), var19.get());

    reql_array_append(var4.get(), var15.get());

    ReQL_Obj_c var20;
    _C::CTypes::array arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    ReQL_Obj_c var21;
    _C::CTypes::array arr21(new ReQL_Obj_t*[2]);
    reql_array_init(var21.get(), arr21.get(), 2);

    ReQL_Obj_c var22;
    reql_number_init(var22.get(), 3);

    reql_array_append(var21.get(), var22.get());

    ReQL_Obj_c var23;
    reql_number_init(var23.get(), 3);

    reql_array_append(var21.get(), var23.get());

    reql_array_append(var20.get(), var21.get());

    ReQL_Obj_c var24;
    reql_number_init(var24.get(), 25);

    reql_array_append(var20.get(), var24.get());

    reql_array_append(var4.get(), var20.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test88") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[11]);
    const uint8_t src1[] = "$reql_type$";
    reql_string_init(var1.get(), buf1.get(), 11);
    reql_string_append(var1.get(), src1, 11);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[12]);
    const uint8_t src2[] = "GROUPED_DATA";
    reql_string_init(var2.get(), buf2.get(), 12);
    reql_string_append(var2.get(), src2, 12);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "data";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[16]);
    reql_array_init(var4.get(), arr4.get(), 16);

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[2]);
    reql_array_init(var5.get(), arr5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::array arr6(new ReQL_Obj_t*[4]);
    reql_array_init(var6.get(), arr6.get(), 4);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_array_append(var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[1]);
    const uint8_t src8[] = "f";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    reql_array_append(var6.get(), var8.get());

    ReQL_Obj_c var9;
    reql_null_init(var9.get());

    reql_array_append(var6.get(), var9.get());

    ReQL_Obj_c var10;
    _C::CTypes::array arr10(new ReQL_Obj_t*[1]);
    reql_array_init(var10.get(), arr10.get(), 1);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_array_append(var10.get(), var11.get());

    reql_array_append(var6.get(), var10.get());

    reql_array_append(var5.get(), var6.get());

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 25);

    reql_array_append(var5.get(), var12.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var13;
    _C::CTypes::array arr13(new ReQL_Obj_t*[2]);
    reql_array_init(var13.get(), arr13.get(), 2);

    ReQL_Obj_c var14;
    _C::CTypes::array arr14(new ReQL_Obj_t*[4]);
    reql_array_init(var14.get(), arr14.get(), 4);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 0);

    reql_array_append(var14.get(), var15.get());

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[1]);
    const uint8_t src16[] = "f";
    reql_string_init(var16.get(), buf16.get(), 1);
    reql_string_append(var16.get(), src16, 1);

    reql_array_append(var14.get(), var16.get());

    ReQL_Obj_c var17;
    reql_null_init(var17.get());

    reql_array_append(var14.get(), var17.get());

    ReQL_Obj_c var18;
    reql_null_init(var18.get());

    reql_array_append(var14.get(), var18.get());

    reql_array_append(var13.get(), var14.get());

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 25);

    reql_array_append(var13.get(), var19.get());

    reql_array_append(var4.get(), var13.get());

    ReQL_Obj_c var20;
    _C::CTypes::array arr20(new ReQL_Obj_t*[2]);
    reql_array_init(var20.get(), arr20.get(), 2);

    ReQL_Obj_c var21;
    _C::CTypes::array arr21(new ReQL_Obj_t*[4]);
    reql_array_init(var21.get(), arr21.get(), 4);

    ReQL_Obj_c var22;
    reql_number_init(var22.get(), 0);

    reql_array_append(var21.get(), var22.get());

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[1]);
    const uint8_t src23[] = "f";
    reql_string_init(var23.get(), buf23.get(), 1);
    reql_string_append(var23.get(), src23, 1);

    reql_array_append(var21.get(), var23.get());

    ReQL_Obj_c var24;
    reql_null_init(var24.get());

    reql_array_append(var21.get(), var24.get());

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 0);

    reql_array_append(var21.get(), var25.get());

    reql_array_append(var20.get(), var21.get());

    ReQL_Obj_c var26;
    reql_number_init(var26.get(), 25);

    reql_array_append(var20.get(), var26.get());

    reql_array_append(var4.get(), var20.get());

    ReQL_Obj_c var27;
    _C::CTypes::array arr27(new ReQL_Obj_t*[2]);
    reql_array_init(var27.get(), arr27.get(), 2);

    ReQL_Obj_c var28;
    _C::CTypes::array arr28(new ReQL_Obj_t*[4]);
    reql_array_init(var28.get(), arr28.get(), 4);

    ReQL_Obj_c var29;
    reql_number_init(var29.get(), 0);

    reql_array_append(var28.get(), var29.get());

    ReQL_Obj_c var30;
    _C::CTypes::string buf30(new uint8_t[1]);
    const uint8_t src30[] = "f";
    reql_string_init(var30.get(), buf30.get(), 1);
    reql_string_append(var30.get(), src30, 1);

    reql_array_append(var28.get(), var30.get());

    ReQL_Obj_c var31;
    reql_null_init(var31.get());

    reql_array_append(var28.get(), var31.get());

    ReQL_Obj_c var32;
    reql_object_init(var32.get(), nullptr, 0);

    reql_array_append(var28.get(), var32.get());

    reql_array_append(var27.get(), var28.get());

    ReQL_Obj_c var33;
    reql_number_init(var33.get(), 25);

    reql_array_append(var27.get(), var33.get());

    reql_array_append(var4.get(), var27.get());

    ReQL_Obj_c var34;
    _C::CTypes::array arr34(new ReQL_Obj_t*[2]);
    reql_array_init(var34.get(), arr34.get(), 2);

    ReQL_Obj_c var35;
    _C::CTypes::array arr35(new ReQL_Obj_t*[4]);
    reql_array_init(var35.get(), arr35.get(), 4);

    ReQL_Obj_c var36;
    reql_number_init(var36.get(), 1);

    reql_array_append(var35.get(), var36.get());

    ReQL_Obj_c var37;
    _C::CTypes::string buf37(new uint8_t[1]);
    const uint8_t src37[] = "f";
    reql_string_init(var37.get(), buf37.get(), 1);
    reql_string_append(var37.get(), src37, 1);

    reql_array_append(var35.get(), var37.get());

    ReQL_Obj_c var38;
    reql_null_init(var38.get());

    reql_array_append(var35.get(), var38.get());

    ReQL_Obj_c var39;
    _C::CTypes::array arr39(new ReQL_Obj_t*[1]);
    reql_array_init(var39.get(), arr39.get(), 1);

    ReQL_Obj_c var40;
    reql_number_init(var40.get(), 0);

    reql_array_append(var39.get(), var40.get());

    reql_array_append(var35.get(), var39.get());

    reql_array_append(var34.get(), var35.get());

    ReQL_Obj_c var41;
    reql_number_init(var41.get(), 25);

    reql_array_append(var34.get(), var41.get());

    reql_array_append(var4.get(), var34.get());

    ReQL_Obj_c var42;
    _C::CTypes::array arr42(new ReQL_Obj_t*[2]);
    reql_array_init(var42.get(), arr42.get(), 2);

    ReQL_Obj_c var43;
    _C::CTypes::array arr43(new ReQL_Obj_t*[4]);
    reql_array_init(var43.get(), arr43.get(), 4);

    ReQL_Obj_c var44;
    reql_number_init(var44.get(), 1);

    reql_array_append(var43.get(), var44.get());

    ReQL_Obj_c var45;
    _C::CTypes::string buf45(new uint8_t[1]);
    const uint8_t src45[] = "f";
    reql_string_init(var45.get(), buf45.get(), 1);
    reql_string_append(var45.get(), src45, 1);

    reql_array_append(var43.get(), var45.get());

    ReQL_Obj_c var46;
    reql_null_init(var46.get());

    reql_array_append(var43.get(), var46.get());

    ReQL_Obj_c var47;
    reql_null_init(var47.get());

    reql_array_append(var43.get(), var47.get());

    reql_array_append(var42.get(), var43.get());

    ReQL_Obj_c var48;
    reql_number_init(var48.get(), 25);

    reql_array_append(var42.get(), var48.get());

    reql_array_append(var4.get(), var42.get());

    ReQL_Obj_c var49;
    _C::CTypes::array arr49(new ReQL_Obj_t*[2]);
    reql_array_init(var49.get(), arr49.get(), 2);

    ReQL_Obj_c var50;
    _C::CTypes::array arr50(new ReQL_Obj_t*[4]);
    reql_array_init(var50.get(), arr50.get(), 4);

    ReQL_Obj_c var51;
    reql_number_init(var51.get(), 1);

    reql_array_append(var50.get(), var51.get());

    ReQL_Obj_c var52;
    _C::CTypes::string buf52(new uint8_t[1]);
    const uint8_t src52[] = "f";
    reql_string_init(var52.get(), buf52.get(), 1);
    reql_string_append(var52.get(), src52, 1);

    reql_array_append(var50.get(), var52.get());

    ReQL_Obj_c var53;
    reql_null_init(var53.get());

    reql_array_append(var50.get(), var53.get());

    ReQL_Obj_c var54;
    reql_number_init(var54.get(), 0);

    reql_array_append(var50.get(), var54.get());

    reql_array_append(var49.get(), var50.get());

    ReQL_Obj_c var55;
    reql_number_init(var55.get(), 25);

    reql_array_append(var49.get(), var55.get());

    reql_array_append(var4.get(), var49.get());

    ReQL_Obj_c var56;
    _C::CTypes::array arr56(new ReQL_Obj_t*[2]);
    reql_array_init(var56.get(), arr56.get(), 2);

    ReQL_Obj_c var57;
    _C::CTypes::array arr57(new ReQL_Obj_t*[4]);
    reql_array_init(var57.get(), arr57.get(), 4);

    ReQL_Obj_c var58;
    reql_number_init(var58.get(), 1);

    reql_array_append(var57.get(), var58.get());

    ReQL_Obj_c var59;
    _C::CTypes::string buf59(new uint8_t[1]);
    const uint8_t src59[] = "f";
    reql_string_init(var59.get(), buf59.get(), 1);
    reql_string_append(var59.get(), src59, 1);

    reql_array_append(var57.get(), var59.get());

    ReQL_Obj_c var60;
    reql_null_init(var60.get());

    reql_array_append(var57.get(), var60.get());

    ReQL_Obj_c var61;
    reql_object_init(var61.get(), nullptr, 0);

    reql_array_append(var57.get(), var61.get());

    reql_array_append(var56.get(), var57.get());

    ReQL_Obj_c var62;
    reql_number_init(var62.get(), 25);

    reql_array_append(var56.get(), var62.get());

    reql_array_append(var4.get(), var56.get());

    ReQL_Obj_c var63;
    _C::CTypes::array arr63(new ReQL_Obj_t*[2]);
    reql_array_init(var63.get(), arr63.get(), 2);

    ReQL_Obj_c var64;
    _C::CTypes::array arr64(new ReQL_Obj_t*[4]);
    reql_array_init(var64.get(), arr64.get(), 4);

    ReQL_Obj_c var65;
    reql_number_init(var65.get(), 2);

    reql_array_append(var64.get(), var65.get());

    ReQL_Obj_c var66;
    _C::CTypes::string buf66(new uint8_t[1]);
    const uint8_t src66[] = "f";
    reql_string_init(var66.get(), buf66.get(), 1);
    reql_string_append(var66.get(), src66, 1);

    reql_array_append(var64.get(), var66.get());

    ReQL_Obj_c var67;
    reql_null_init(var67.get());

    reql_array_append(var64.get(), var67.get());

    ReQL_Obj_c var68;
    _C::CTypes::array arr68(new ReQL_Obj_t*[1]);
    reql_array_init(var68.get(), arr68.get(), 1);

    ReQL_Obj_c var69;
    reql_number_init(var69.get(), 0);

    reql_array_append(var68.get(), var69.get());

    reql_array_append(var64.get(), var68.get());

    reql_array_append(var63.get(), var64.get());

    ReQL_Obj_c var70;
    reql_number_init(var70.get(), 25);

    reql_array_append(var63.get(), var70.get());

    reql_array_append(var4.get(), var63.get());

    ReQL_Obj_c var71;
    _C::CTypes::array arr71(new ReQL_Obj_t*[2]);
    reql_array_init(var71.get(), arr71.get(), 2);

    ReQL_Obj_c var72;
    _C::CTypes::array arr72(new ReQL_Obj_t*[4]);
    reql_array_init(var72.get(), arr72.get(), 4);

    ReQL_Obj_c var73;
    reql_number_init(var73.get(), 2);

    reql_array_append(var72.get(), var73.get());

    ReQL_Obj_c var74;
    _C::CTypes::string buf74(new uint8_t[1]);
    const uint8_t src74[] = "f";
    reql_string_init(var74.get(), buf74.get(), 1);
    reql_string_append(var74.get(), src74, 1);

    reql_array_append(var72.get(), var74.get());

    ReQL_Obj_c var75;
    reql_null_init(var75.get());

    reql_array_append(var72.get(), var75.get());

    ReQL_Obj_c var76;
    reql_null_init(var76.get());

    reql_array_append(var72.get(), var76.get());

    reql_array_append(var71.get(), var72.get());

    ReQL_Obj_c var77;
    reql_number_init(var77.get(), 25);

    reql_array_append(var71.get(), var77.get());

    reql_array_append(var4.get(), var71.get());

    ReQL_Obj_c var78;
    _C::CTypes::array arr78(new ReQL_Obj_t*[2]);
    reql_array_init(var78.get(), arr78.get(), 2);

    ReQL_Obj_c var79;
    _C::CTypes::array arr79(new ReQL_Obj_t*[4]);
    reql_array_init(var79.get(), arr79.get(), 4);

    ReQL_Obj_c var80;
    reql_number_init(var80.get(), 2);

    reql_array_append(var79.get(), var80.get());

    ReQL_Obj_c var81;
    _C::CTypes::string buf81(new uint8_t[1]);
    const uint8_t src81[] = "f";
    reql_string_init(var81.get(), buf81.get(), 1);
    reql_string_append(var81.get(), src81, 1);

    reql_array_append(var79.get(), var81.get());

    ReQL_Obj_c var82;
    reql_null_init(var82.get());

    reql_array_append(var79.get(), var82.get());

    ReQL_Obj_c var83;
    reql_number_init(var83.get(), 0);

    reql_array_append(var79.get(), var83.get());

    reql_array_append(var78.get(), var79.get());

    ReQL_Obj_c var84;
    reql_number_init(var84.get(), 25);

    reql_array_append(var78.get(), var84.get());

    reql_array_append(var4.get(), var78.get());

    ReQL_Obj_c var85;
    _C::CTypes::array arr85(new ReQL_Obj_t*[2]);
    reql_array_init(var85.get(), arr85.get(), 2);

    ReQL_Obj_c var86;
    _C::CTypes::array arr86(new ReQL_Obj_t*[4]);
    reql_array_init(var86.get(), arr86.get(), 4);

    ReQL_Obj_c var87;
    reql_number_init(var87.get(), 2);

    reql_array_append(var86.get(), var87.get());

    ReQL_Obj_c var88;
    _C::CTypes::string buf88(new uint8_t[1]);
    const uint8_t src88[] = "f";
    reql_string_init(var88.get(), buf88.get(), 1);
    reql_string_append(var88.get(), src88, 1);

    reql_array_append(var86.get(), var88.get());

    ReQL_Obj_c var89;
    reql_null_init(var89.get());

    reql_array_append(var86.get(), var89.get());

    ReQL_Obj_c var90;
    reql_object_init(var90.get(), nullptr, 0);

    reql_array_append(var86.get(), var90.get());

    reql_array_append(var85.get(), var86.get());

    ReQL_Obj_c var91;
    reql_number_init(var91.get(), 25);

    reql_array_append(var85.get(), var91.get());

    reql_array_append(var4.get(), var85.get());

    ReQL_Obj_c var92;
    _C::CTypes::array arr92(new ReQL_Obj_t*[2]);
    reql_array_init(var92.get(), arr92.get(), 2);

    ReQL_Obj_c var93;
    _C::CTypes::array arr93(new ReQL_Obj_t*[4]);
    reql_array_init(var93.get(), arr93.get(), 4);

    ReQL_Obj_c var94;
    reql_number_init(var94.get(), 3);

    reql_array_append(var93.get(), var94.get());

    ReQL_Obj_c var95;
    _C::CTypes::string buf95(new uint8_t[1]);
    const uint8_t src95[] = "f";
    reql_string_init(var95.get(), buf95.get(), 1);
    reql_string_append(var95.get(), src95, 1);

    reql_array_append(var93.get(), var95.get());

    ReQL_Obj_c var96;
    reql_null_init(var96.get());

    reql_array_append(var93.get(), var96.get());

    ReQL_Obj_c var97;
    _C::CTypes::array arr97(new ReQL_Obj_t*[1]);
    reql_array_init(var97.get(), arr97.get(), 1);

    ReQL_Obj_c var98;
    reql_number_init(var98.get(), 0);

    reql_array_append(var97.get(), var98.get());

    reql_array_append(var93.get(), var97.get());

    reql_array_append(var92.get(), var93.get());

    ReQL_Obj_c var99;
    reql_number_init(var99.get(), 25);

    reql_array_append(var92.get(), var99.get());

    reql_array_append(var4.get(), var92.get());

    ReQL_Obj_c var100;
    _C::CTypes::array arr100(new ReQL_Obj_t*[2]);
    reql_array_init(var100.get(), arr100.get(), 2);

    ReQL_Obj_c var101;
    _C::CTypes::array arr101(new ReQL_Obj_t*[4]);
    reql_array_init(var101.get(), arr101.get(), 4);

    ReQL_Obj_c var102;
    reql_number_init(var102.get(), 3);

    reql_array_append(var101.get(), var102.get());

    ReQL_Obj_c var103;
    _C::CTypes::string buf103(new uint8_t[1]);
    const uint8_t src103[] = "f";
    reql_string_init(var103.get(), buf103.get(), 1);
    reql_string_append(var103.get(), src103, 1);

    reql_array_append(var101.get(), var103.get());

    ReQL_Obj_c var104;
    reql_null_init(var104.get());

    reql_array_append(var101.get(), var104.get());

    ReQL_Obj_c var105;
    reql_null_init(var105.get());

    reql_array_append(var101.get(), var105.get());

    reql_array_append(var100.get(), var101.get());

    ReQL_Obj_c var106;
    reql_number_init(var106.get(), 25);

    reql_array_append(var100.get(), var106.get());

    reql_array_append(var4.get(), var100.get());

    ReQL_Obj_c var107;
    _C::CTypes::array arr107(new ReQL_Obj_t*[2]);
    reql_array_init(var107.get(), arr107.get(), 2);

    ReQL_Obj_c var108;
    _C::CTypes::array arr108(new ReQL_Obj_t*[4]);
    reql_array_init(var108.get(), arr108.get(), 4);

    ReQL_Obj_c var109;
    reql_number_init(var109.get(), 3);

    reql_array_append(var108.get(), var109.get());

    ReQL_Obj_c var110;
    _C::CTypes::string buf110(new uint8_t[1]);
    const uint8_t src110[] = "f";
    reql_string_init(var110.get(), buf110.get(), 1);
    reql_string_append(var110.get(), src110, 1);

    reql_array_append(var108.get(), var110.get());

    ReQL_Obj_c var111;
    reql_null_init(var111.get());

    reql_array_append(var108.get(), var111.get());

    ReQL_Obj_c var112;
    reql_number_init(var112.get(), 0);

    reql_array_append(var108.get(), var112.get());

    reql_array_append(var107.get(), var108.get());

    ReQL_Obj_c var113;
    reql_number_init(var113.get(), 25);

    reql_array_append(var107.get(), var113.get());

    reql_array_append(var4.get(), var107.get());

    ReQL_Obj_c var114;
    _C::CTypes::array arr114(new ReQL_Obj_t*[2]);
    reql_array_init(var114.get(), arr114.get(), 2);

    ReQL_Obj_c var115;
    _C::CTypes::array arr115(new ReQL_Obj_t*[4]);
    reql_array_init(var115.get(), arr115.get(), 4);

    ReQL_Obj_c var116;
    reql_number_init(var116.get(), 3);

    reql_array_append(var115.get(), var116.get());

    ReQL_Obj_c var117;
    _C::CTypes::string buf117(new uint8_t[1]);
    const uint8_t src117[] = "f";
    reql_string_init(var117.get(), buf117.get(), 1);
    reql_string_append(var117.get(), src117, 1);

    reql_array_append(var115.get(), var117.get());

    ReQL_Obj_c var118;
    reql_null_init(var118.get());

    reql_array_append(var115.get(), var118.get());

    ReQL_Obj_c var119;
    reql_object_init(var119.get(), nullptr, 0);

    reql_array_append(var115.get(), var119.get());

    reql_array_append(var114.get(), var115.get());

    ReQL_Obj_c var120;
    reql_number_init(var120.get(), 25);

    reql_array_append(var114.get(), var120.get());

    reql_array_append(var4.get(), var114.get());

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test89") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[9]);
    const uint8_t src4[] = "reduction";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 25);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    _C::CTypes::pairs pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "group";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[9]);
    const uint8_t src9[] = "reduction";
    reql_string_init(var9.get(), buf9.get(), 9);
    reql_string_append(var9.get(), src9, 9);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 25);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[5]);
    const uint8_t src12[] = "group";
    reql_string_init(var12.get(), buf12.get(), 5);
    reql_string_append(var12.get(), src12, 5);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[9]);
    const uint8_t src14[] = "reduction";
    reql_string_init(var14.get(), buf14.get(), 9);
    reql_string_append(var14.get(), src14, 9);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 25);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[5]);
    const uint8_t src17[] = "group";
    reql_string_init(var17.get(), buf17.get(), 5);
    reql_string_append(var17.get(), src17, 5);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[9]);
    const uint8_t src19[] = "reduction";
    reql_string_init(var19.get(), buf19.get(), 9);
    reql_string_append(var19.get(), src19, 9);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 25);

    reql_object_add(var16.get(), var19.get(), var20.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test90") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 3);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test91") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    _C::CTypes::array arr3(new ReQL_Obj_t*[2]);
    reql_array_init(var3.get(), arr3.get(), 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_array_append(var3.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 0);

    reql_array_append(var3.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[9]);
    const uint8_t src6[] = "reduction";
    reql_string_init(var6.get(), buf6.get(), 9);
    reql_string_append(var6.get(), src6, 9);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 24);

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var8;
    _C::CTypes::pairs pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[5]);
    const uint8_t src9[] = "group";
    reql_string_init(var9.get(), buf9.get(), 5);
    reql_string_append(var9.get(), src9, 5);

    ReQL_Obj_c var10;
    _C::CTypes::array arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 1);

    reql_array_append(var10.get(), var11.get());

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_array_append(var10.get(), var12.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[9]);
    const uint8_t src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), 9);
    reql_string_append(var13.get(), src13, 9);

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 28);

    reql_object_add(var8.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var8.get());

    ReQL_Obj_c var15;
    _C::CTypes::pairs pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[5]);
    const uint8_t src16[] = "group";
    reql_string_init(var16.get(), buf16.get(), 5);
    reql_string_append(var16.get(), src16, 5);

    ReQL_Obj_c var17;
    _C::CTypes::array arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 2);

    reql_array_append(var17.get(), var18.get());

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 2);

    reql_array_append(var17.get(), var19.get());

    reql_object_add(var15.get(), var16.get(), var17.get());

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[9]);
    const uint8_t src20[] = "reduction";
    reql_string_init(var20.get(), buf20.get(), 9);
    reql_string_append(var20.get(), src20, 9);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 32);

    reql_object_add(var15.get(), var20.get(), var21.get());

    reql_array_append(var0.get(), var15.get());

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[2]);
    reql_object_init(var22.get(), pair22.get(), 2);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[5]);
    const uint8_t src23[] = "group";
    reql_string_init(var23.get(), buf23.get(), 5);
    reql_string_append(var23.get(), src23, 5);

    ReQL_Obj_c var24;
    _C::CTypes::array arr24(new ReQL_Obj_t*[2]);
    reql_array_init(var24.get(), arr24.get(), 2);

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 3);

    reql_array_append(var24.get(), var25.get());

    ReQL_Obj_c var26;
    reql_number_init(var26.get(), 3);

    reql_array_append(var24.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    ReQL_Obj_c var27;
    _C::CTypes::string buf27(new uint8_t[9]);
    const uint8_t src27[] = "reduction";
    reql_string_init(var27.get(), buf27.get(), 9);
    reql_string_append(var27.get(), src27, 9);

    ReQL_Obj_c var28;
    reql_number_init(var28.get(), 36);

    reql_object_add(var22.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var22.get());
  }

  SECTION("test92") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    _C::CTypes::array arr3(new ReQL_Obj_t*[2]);
    reql_array_init(var3.get(), arr3.get(), 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_array_append(var3.get(), var4.get());

    ReQL_Obj_c var5;
    reql_null_init(var5.get());

    reql_array_append(var3.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[9]);
    const uint8_t src6[] = "reduction";
    reql_string_init(var6.get(), buf6.get(), 9);
    reql_string_append(var6.get(), src6, 9);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 25);

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var8;
    _C::CTypes::pairs pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[5]);
    const uint8_t src9[] = "group";
    reql_string_init(var9.get(), buf9.get(), 5);
    reql_string_append(var9.get(), src9, 5);

    ReQL_Obj_c var10;
    _C::CTypes::array arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 1);

    reql_array_append(var10.get(), var11.get());

    ReQL_Obj_c var12;
    reql_null_init(var12.get());

    reql_array_append(var10.get(), var12.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[9]);
    const uint8_t src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), 9);
    reql_string_append(var13.get(), src13, 9);

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 25);

    reql_object_add(var8.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var8.get());

    ReQL_Obj_c var15;
    _C::CTypes::pairs pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[5]);
    const uint8_t src16[] = "group";
    reql_string_init(var16.get(), buf16.get(), 5);
    reql_string_append(var16.get(), src16, 5);

    ReQL_Obj_c var17;
    _C::CTypes::array arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 2);

    reql_array_append(var17.get(), var18.get());

    ReQL_Obj_c var19;
    reql_null_init(var19.get());

    reql_array_append(var17.get(), var19.get());

    reql_object_add(var15.get(), var16.get(), var17.get());

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[9]);
    const uint8_t src20[] = "reduction";
    reql_string_init(var20.get(), buf20.get(), 9);
    reql_string_append(var20.get(), src20, 9);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 25);

    reql_object_add(var15.get(), var20.get(), var21.get());

    reql_array_append(var0.get(), var15.get());

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[2]);
    reql_object_init(var22.get(), pair22.get(), 2);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[5]);
    const uint8_t src23[] = "group";
    reql_string_init(var23.get(), buf23.get(), 5);
    reql_string_append(var23.get(), src23, 5);

    ReQL_Obj_c var24;
    _C::CTypes::array arr24(new ReQL_Obj_t*[2]);
    reql_array_init(var24.get(), arr24.get(), 2);

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 3);

    reql_array_append(var24.get(), var25.get());

    ReQL_Obj_c var26;
    reql_null_init(var26.get());

    reql_array_append(var24.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    ReQL_Obj_c var27;
    _C::CTypes::string buf27(new uint8_t[9]);
    const uint8_t src27[] = "reduction";
    reql_string_init(var27.get(), buf27.get(), 9);
    reql_string_append(var27.get(), src27, 9);

    ReQL_Obj_c var28;
    reql_number_init(var28.get(), 25);

    reql_object_add(var22.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var22.get());
  }

  SECTION("test93") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[8]);
    reql_array_init(var0.get(), arr0.get(), 8);

    ReQL_Obj_c var1;
    _C::CTypes::pairs pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "group";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    ReQL_Obj_c var3;
    _C::CTypes::array arr3(new ReQL_Obj_t*[2]);
    reql_array_init(var3.get(), arr3.get(), 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_array_append(var3.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var3.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[9]);
    const uint8_t src6[] = "reduction";
    reql_string_init(var6.get(), buf6.get(), 9);
    reql_string_append(var6.get(), src6, 9);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 25);

    reql_object_add(var1.get(), var6.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var8;
    _C::CTypes::pairs pair8(new ReQL_Pair_t[2]);
    reql_object_init(var8.get(), pair8.get(), 2);

    ReQL_Obj_c var9;
    _C::CTypes::string buf9(new uint8_t[5]);
    const uint8_t src9[] = "group";
    reql_string_init(var9.get(), buf9.get(), 5);
    reql_string_append(var9.get(), src9, 5);

    ReQL_Obj_c var10;
    _C::CTypes::array arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_array_append(var10.get(), var11.get());

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[3]);
    const uint8_t src12[] = "two";
    reql_string_init(var12.get(), buf12.get(), 3);
    reql_string_append(var12.get(), src12, 3);

    reql_array_append(var10.get(), var12.get());

    reql_object_add(var8.get(), var9.get(), var10.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[9]);
    const uint8_t src13[] = "reduction";
    reql_string_init(var13.get(), buf13.get(), 9);
    reql_string_append(var13.get(), src13, 9);

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 25);

    reql_object_add(var8.get(), var13.get(), var14.get());

    reql_array_append(var0.get(), var8.get());

    ReQL_Obj_c var15;
    _C::CTypes::pairs pair15(new ReQL_Pair_t[2]);
    reql_object_init(var15.get(), pair15.get(), 2);

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[5]);
    const uint8_t src16[] = "group";
    reql_string_init(var16.get(), buf16.get(), 5);
    reql_string_append(var16.get(), src16, 5);

    ReQL_Obj_c var17;
    _C::CTypes::array arr17(new ReQL_Obj_t*[2]);
    reql_array_init(var17.get(), arr17.get(), 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 1);

    reql_array_append(var17.get(), var18.get());

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 1);

    reql_array_append(var17.get(), var19.get());

    reql_object_add(var15.get(), var16.get(), var17.get());

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[9]);
    const uint8_t src20[] = "reduction";
    reql_string_init(var20.get(), buf20.get(), 9);
    reql_string_append(var20.get(), src20, 9);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 25);

    reql_object_add(var15.get(), var20.get(), var21.get());

    reql_array_append(var0.get(), var15.get());

    ReQL_Obj_c var22;
    _C::CTypes::pairs pair22(new ReQL_Pair_t[2]);
    reql_object_init(var22.get(), pair22.get(), 2);

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[5]);
    const uint8_t src23[] = "group";
    reql_string_init(var23.get(), buf23.get(), 5);
    reql_string_append(var23.get(), src23, 5);

    ReQL_Obj_c var24;
    _C::CTypes::array arr24(new ReQL_Obj_t*[2]);
    reql_array_init(var24.get(), arr24.get(), 2);

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 1);

    reql_array_append(var24.get(), var25.get());

    ReQL_Obj_c var26;
    _C::CTypes::string buf26(new uint8_t[3]);
    const uint8_t src26[] = "two";
    reql_string_init(var26.get(), buf26.get(), 3);
    reql_string_append(var26.get(), src26, 3);

    reql_array_append(var24.get(), var26.get());

    reql_object_add(var22.get(), var23.get(), var24.get());

    ReQL_Obj_c var27;
    _C::CTypes::string buf27(new uint8_t[9]);
    const uint8_t src27[] = "reduction";
    reql_string_init(var27.get(), buf27.get(), 9);
    reql_string_append(var27.get(), src27, 9);

    ReQL_Obj_c var28;
    reql_number_init(var28.get(), 25);

    reql_object_add(var22.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var22.get());

    ReQL_Obj_c var29;
    _C::CTypes::pairs pair29(new ReQL_Pair_t[2]);
    reql_object_init(var29.get(), pair29.get(), 2);

    ReQL_Obj_c var30;
    _C::CTypes::string buf30(new uint8_t[5]);
    const uint8_t src30[] = "group";
    reql_string_init(var30.get(), buf30.get(), 5);
    reql_string_append(var30.get(), src30, 5);

    ReQL_Obj_c var31;
    _C::CTypes::array arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    ReQL_Obj_c var32;
    reql_number_init(var32.get(), 2);

    reql_array_append(var31.get(), var32.get());

    ReQL_Obj_c var33;
    reql_number_init(var33.get(), 1);

    reql_array_append(var31.get(), var33.get());

    reql_object_add(var29.get(), var30.get(), var31.get());

    ReQL_Obj_c var34;
    _C::CTypes::string buf34(new uint8_t[9]);
    const uint8_t src34[] = "reduction";
    reql_string_init(var34.get(), buf34.get(), 9);
    reql_string_append(var34.get(), src34, 9);

    ReQL_Obj_c var35;
    reql_number_init(var35.get(), 25);

    reql_object_add(var29.get(), var34.get(), var35.get());

    reql_array_append(var0.get(), var29.get());

    ReQL_Obj_c var36;
    _C::CTypes::pairs pair36(new ReQL_Pair_t[2]);
    reql_object_init(var36.get(), pair36.get(), 2);

    ReQL_Obj_c var37;
    _C::CTypes::string buf37(new uint8_t[5]);
    const uint8_t src37[] = "group";
    reql_string_init(var37.get(), buf37.get(), 5);
    reql_string_append(var37.get(), src37, 5);

    ReQL_Obj_c var38;
    _C::CTypes::array arr38(new ReQL_Obj_t*[2]);
    reql_array_init(var38.get(), arr38.get(), 2);

    ReQL_Obj_c var39;
    reql_number_init(var39.get(), 2);

    reql_array_append(var38.get(), var39.get());

    ReQL_Obj_c var40;
    _C::CTypes::string buf40(new uint8_t[3]);
    const uint8_t src40[] = "two";
    reql_string_init(var40.get(), buf40.get(), 3);
    reql_string_append(var40.get(), src40, 3);

    reql_array_append(var38.get(), var40.get());

    reql_object_add(var36.get(), var37.get(), var38.get());

    ReQL_Obj_c var41;
    _C::CTypes::string buf41(new uint8_t[9]);
    const uint8_t src41[] = "reduction";
    reql_string_init(var41.get(), buf41.get(), 9);
    reql_string_append(var41.get(), src41, 9);

    ReQL_Obj_c var42;
    reql_number_init(var42.get(), 25);

    reql_object_add(var36.get(), var41.get(), var42.get());

    reql_array_append(var0.get(), var36.get());

    ReQL_Obj_c var43;
    _C::CTypes::pairs pair43(new ReQL_Pair_t[2]);
    reql_object_init(var43.get(), pair43.get(), 2);

    ReQL_Obj_c var44;
    _C::CTypes::string buf44(new uint8_t[5]);
    const uint8_t src44[] = "group";
    reql_string_init(var44.get(), buf44.get(), 5);
    reql_string_append(var44.get(), src44, 5);

    ReQL_Obj_c var45;
    _C::CTypes::array arr45(new ReQL_Obj_t*[2]);
    reql_array_init(var45.get(), arr45.get(), 2);

    ReQL_Obj_c var46;
    reql_number_init(var46.get(), 3);

    reql_array_append(var45.get(), var46.get());

    ReQL_Obj_c var47;
    reql_number_init(var47.get(), 1);

    reql_array_append(var45.get(), var47.get());

    reql_object_add(var43.get(), var44.get(), var45.get());

    ReQL_Obj_c var48;
    _C::CTypes::string buf48(new uint8_t[9]);
    const uint8_t src48[] = "reduction";
    reql_string_init(var48.get(), buf48.get(), 9);
    reql_string_append(var48.get(), src48, 9);

    ReQL_Obj_c var49;
    reql_number_init(var49.get(), 25);

    reql_object_add(var43.get(), var48.get(), var49.get());

    reql_array_append(var0.get(), var43.get());

    ReQL_Obj_c var50;
    _C::CTypes::pairs pair50(new ReQL_Pair_t[2]);
    reql_object_init(var50.get(), pair50.get(), 2);

    ReQL_Obj_c var51;
    _C::CTypes::string buf51(new uint8_t[5]);
    const uint8_t src51[] = "group";
    reql_string_init(var51.get(), buf51.get(), 5);
    reql_string_append(var51.get(), src51, 5);

    ReQL_Obj_c var52;
    _C::CTypes::array arr52(new ReQL_Obj_t*[2]);
    reql_array_init(var52.get(), arr52.get(), 2);

    ReQL_Obj_c var53;
    reql_number_init(var53.get(), 3);

    reql_array_append(var52.get(), var53.get());

    ReQL_Obj_c var54;
    _C::CTypes::string buf54(new uint8_t[3]);
    const uint8_t src54[] = "two";
    reql_string_init(var54.get(), buf54.get(), 3);
    reql_string_append(var54.get(), src54, 3);

    reql_array_append(var52.get(), var54.get());

    reql_object_add(var50.get(), var51.get(), var52.get());

    ReQL_Obj_c var55;
    _C::CTypes::string buf55(new uint8_t[9]);
    const uint8_t src55[] = "reduction";
    reql_string_init(var55.get(), buf55.get(), 9);
    reql_string_append(var55.get(), src55, 9);

    ReQL_Obj_c var56;
    reql_number_init(var56.get(), 25);

    reql_object_add(var50.get(), var55.get(), var56.get());

    reql_array_append(var0.get(), var50.get());
  }

  SECTION("test94") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 100);
  }

  SECTION("test102") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test103") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test104") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 0);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test105") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test106") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test107") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[2]);
    const uint8_t src3[] = "id";
    reql_string_init(var3.get(), buf3.get(), 2);
    reql_string_append(var3.get(), src3, 2);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 99);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }
}
