// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test basic geometry operators", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[21]);
    const uint8_t src0[] = "89011.262538353315904";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[21]);
    const uint8_t src0[] = "110968.30443995493988";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[21]);
    const uint8_t src0[] = "89011.262538353315904";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[22]);
    const uint8_t src0[] = "0.01393875509649327056";
    reql_string_init(var0.get(), buf0.get(), 22);
    reql_string_append(var0.get(), src0, 22);
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[20]);
    const uint8_t src0[] = "40007862.91725089401";
    reql_string_init(var0.get(), buf0.get(), 20);
    reql_string_append(var0.get(), src0, 20);
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[20]);
    const uint8_t src0[] = "40007862.91725089401";
    reql_string_init(var0.get(), buf0.get(), 20);
    reql_string_append(var0.get(), src0, 20);
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[21]);
    const uint8_t src0[] = "492471.49900552548934";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[21]);
    const uint8_t src0[] = "492471.49900552548934";
    reql_string_init(var0.get(), buf0.get(), 21);
    reql_string_append(var0.get(), src0, 21);
  }

  SECTION("test20") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[1]);
    const uint8_t src0[] = "0";
    reql_string_init(var0.get(), buf0.get(), 1);
    reql_string_append(var0.get(), src0, 1);
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test24") {
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
    _C::CTypes::array arr5(new ReQL_Obj_t*[5]);
    reql_array_init(var5.get(), arr5.get(), 5);

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
    reql_number_init(var10.get(), 1);

    reql_array_append(var9.get(), var10.get());

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_array_append(var9.get(), var11.get());

    reql_array_append(var5.get(), var9.get());

    ReQL_Obj_c var12;
    _C::CTypes::array arr12(new ReQL_Obj_t*[2]);
    reql_array_init(var12.get(), arr12.get(), 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1);

    reql_array_append(var12.get(), var13.get());

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 1);

    reql_array_append(var12.get(), var14.get());

    reql_array_append(var5.get(), var12.get());

    ReQL_Obj_c var15;
    _C::CTypes::array arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 0);

    reql_array_append(var15.get(), var16.get());

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 1);

    reql_array_append(var15.get(), var17.get());

    reql_array_append(var5.get(), var15.get());

    ReQL_Obj_c var18;
    _C::CTypes::array arr18(new ReQL_Obj_t*[2]);
    reql_array_init(var18.get(), arr18.get(), 2);

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 0);

    reql_array_append(var18.get(), var19.get());

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 0);

    reql_array_append(var18.get(), var20.get());

    reql_array_append(var5.get(), var18.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var21;
    _C::CTypes::array arr21(new ReQL_Obj_t*[5]);
    reql_array_init(var21.get(), arr21.get(), 5);

    ReQL_Obj_c var22;
    _C::CTypes::array arr22(new ReQL_Obj_t*[2]);
    reql_array_init(var22.get(), arr22.get(), 2);

    ReQL_Obj_c var23;
    reql_number_init(var23.get(), 0.1);

    reql_array_append(var22.get(), var23.get());

    ReQL_Obj_c var24;
    reql_number_init(var24.get(), 0.1);

    reql_array_append(var22.get(), var24.get());

    reql_array_append(var21.get(), var22.get());

    ReQL_Obj_c var25;
    _C::CTypes::array arr25(new ReQL_Obj_t*[2]);
    reql_array_init(var25.get(), arr25.get(), 2);

    ReQL_Obj_c var26;
    reql_number_init(var26.get(), 0.9);

    reql_array_append(var25.get(), var26.get());

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 0.1);

    reql_array_append(var25.get(), var27.get());

    reql_array_append(var21.get(), var25.get());

    ReQL_Obj_c var28;
    _C::CTypes::array arr28(new ReQL_Obj_t*[2]);
    reql_array_init(var28.get(), arr28.get(), 2);

    ReQL_Obj_c var29;
    reql_number_init(var29.get(), 0.9);

    reql_array_append(var28.get(), var29.get());

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 0.9);

    reql_array_append(var28.get(), var30.get());

    reql_array_append(var21.get(), var28.get());

    ReQL_Obj_c var31;
    _C::CTypes::array arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    ReQL_Obj_c var32;
    reql_number_init(var32.get(), 0.1);

    reql_array_append(var31.get(), var32.get());

    ReQL_Obj_c var33;
    reql_number_init(var33.get(), 0.9);

    reql_array_append(var31.get(), var33.get());

    reql_array_append(var21.get(), var31.get());

    ReQL_Obj_c var34;
    _C::CTypes::array arr34(new ReQL_Obj_t*[2]);
    reql_array_init(var34.get(), arr34.get(), 2);

    ReQL_Obj_c var35;
    reql_number_init(var35.get(), 0.1);

    reql_array_append(var34.get(), var35.get());

    ReQL_Obj_c var36;
    reql_number_init(var36.get(), 0.1);

    reql_array_append(var34.get(), var36.get());

    reql_array_append(var21.get(), var34.get());

    reql_array_append(var4.get(), var21.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var37;
    _C::CTypes::string buf37(new uint8_t[4]);
    const uint8_t src37[] = "type";
    reql_string_init(var37.get(), buf37.get(), 4);
    reql_string_append(var37.get(), src37, 4);

    ReQL_Obj_c var38;
    _C::CTypes::string buf38(new uint8_t[7]);
    const uint8_t src38[] = "Polygon";
    reql_string_init(var38.get(), buf38.get(), 7);
    reql_string_append(var38.get(), src38, 7);

    reql_object_add(var0.get(), var37.get(), var38.get());
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

  SECTION("test28") {
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

  SECTION("test29") {
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

  SECTION("test30") {
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
    _C::CTypes::array arr5(new ReQL_Obj_t*[5]);
    reql_array_init(var5.get(), arr5.get(), 5);

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
    reql_number_init(var10.get(), 1);

    reql_array_append(var9.get(), var10.get());

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_array_append(var9.get(), var11.get());

    reql_array_append(var5.get(), var9.get());

    ReQL_Obj_c var12;
    _C::CTypes::array arr12(new ReQL_Obj_t*[2]);
    reql_array_init(var12.get(), arr12.get(), 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1);

    reql_array_append(var12.get(), var13.get());

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 1);

    reql_array_append(var12.get(), var14.get());

    reql_array_append(var5.get(), var12.get());

    ReQL_Obj_c var15;
    _C::CTypes::array arr15(new ReQL_Obj_t*[2]);
    reql_array_init(var15.get(), arr15.get(), 2);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 0);

    reql_array_append(var15.get(), var16.get());

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 1);

    reql_array_append(var15.get(), var17.get());

    reql_array_append(var5.get(), var15.get());

    ReQL_Obj_c var18;
    _C::CTypes::array arr18(new ReQL_Obj_t*[2]);
    reql_array_init(var18.get(), arr18.get(), 2);

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 0);

    reql_array_append(var18.get(), var19.get());

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 0);

    reql_array_append(var18.get(), var20.get());

    reql_array_append(var5.get(), var18.get());

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var21;
    _C::CTypes::array arr21(new ReQL_Obj_t*[5]);
    reql_array_init(var21.get(), arr21.get(), 5);

    ReQL_Obj_c var22;
    _C::CTypes::array arr22(new ReQL_Obj_t*[2]);
    reql_array_init(var22.get(), arr22.get(), 2);

    ReQL_Obj_c var23;
    reql_number_init(var23.get(), 0);

    reql_array_append(var22.get(), var23.get());

    ReQL_Obj_c var24;
    reql_number_init(var24.get(), 0);

    reql_array_append(var22.get(), var24.get());

    reql_array_append(var21.get(), var22.get());

    ReQL_Obj_c var25;
    _C::CTypes::array arr25(new ReQL_Obj_t*[2]);
    reql_array_init(var25.get(), arr25.get(), 2);

    ReQL_Obj_c var26;
    reql_number_init(var26.get(), 0.1);

    reql_array_append(var25.get(), var26.get());

    ReQL_Obj_c var27;
    reql_number_init(var27.get(), 0.9);

    reql_array_append(var25.get(), var27.get());

    reql_array_append(var21.get(), var25.get());

    ReQL_Obj_c var28;
    _C::CTypes::array arr28(new ReQL_Obj_t*[2]);
    reql_array_init(var28.get(), arr28.get(), 2);

    ReQL_Obj_c var29;
    reql_number_init(var29.get(), 0.9);

    reql_array_append(var28.get(), var29.get());

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 0.9);

    reql_array_append(var28.get(), var30.get());

    reql_array_append(var21.get(), var28.get());

    ReQL_Obj_c var31;
    _C::CTypes::array arr31(new ReQL_Obj_t*[2]);
    reql_array_init(var31.get(), arr31.get(), 2);

    ReQL_Obj_c var32;
    reql_number_init(var32.get(), 0.9);

    reql_array_append(var31.get(), var32.get());

    ReQL_Obj_c var33;
    reql_number_init(var33.get(), 0.1);

    reql_array_append(var31.get(), var33.get());

    reql_array_append(var21.get(), var31.get());

    ReQL_Obj_c var34;
    _C::CTypes::array arr34(new ReQL_Obj_t*[2]);
    reql_array_init(var34.get(), arr34.get(), 2);

    ReQL_Obj_c var35;
    reql_number_init(var35.get(), 0);

    reql_array_append(var34.get(), var35.get());

    ReQL_Obj_c var36;
    reql_number_init(var36.get(), 0);

    reql_array_append(var34.get(), var36.get());

    reql_array_append(var21.get(), var34.get());

    reql_array_append(var4.get(), var21.get());

    reql_object_add(var0.get(), var3.get(), var4.get());

    ReQL_Obj_c var37;
    _C::CTypes::string buf37(new uint8_t[4]);
    const uint8_t src37[] = "type";
    reql_string_init(var37.get(), buf37.get(), 4);
    reql_string_append(var37.get(), src37, 4);

    ReQL_Obj_c var38;
    _C::CTypes::string buf38(new uint8_t[7]);
    const uint8_t src38[] = "Polygon";
    reql_string_init(var38.get(), buf38.get(), 7);
    reql_string_append(var38.get(), src38, 7);

    reql_object_add(var0.get(), var37.get(), var38.get());
  }

  SECTION("test31") {
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

  SECTION("test32") {
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
