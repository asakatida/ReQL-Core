// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests the RQL `map` function", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "STREAM";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[5]);
    const uint8_t src0[] = "ARRAY";
    reql_string_init(var0.get(), buf0.get(), 5);
    reql_string_append(var0.get(), src0, 5);
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[1]);
    reql_array_init(var1.get(), arr1.get(), 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var1.get(), var2.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[3]);
    reql_array_init(var1.get(), arr1.get(), 3);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_array_append(var1.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 1);

    reql_array_append(var1.get(), var4.get());

    reql_array_append(var0.get(), var1.get());
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
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 2);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::array arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_array_append(var7.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 3);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var0.get(), var7.get());

    ReQL_Obj_c var10;
    _C::CTypes::array arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 3);

    reql_array_append(var10.get(), var11.get());

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 4);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var0.get(), var10.get());
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::array arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_array_append(var7.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 2);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test15") {
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

  SECTION("test16") {
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

  SECTION("test17") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[1]);
    reql_array_init(var1.get(), arr1.get(), 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var1.get(), var2.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var3;
    _C::CTypes::array arr3(new ReQL_Obj_t*[1]);
    reql_array_init(var3.get(), arr3.get(), 1);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 1);

    reql_array_append(var3.get(), var4.get());

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var5;
    _C::CTypes::array arr5(new ReQL_Obj_t*[1]);
    reql_array_init(var5.get(), arr5.get(), 1);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_array_append(var5.get(), var6.get());

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test19") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 0);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 0);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::array arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_array_append(var7.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 2);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var0.get(), var7.get());
  }
}
