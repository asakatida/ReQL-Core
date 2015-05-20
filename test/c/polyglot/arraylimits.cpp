// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests array limit variations", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[8]);
    reql_array_init(var0.get(), arr0.get(), 8);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 1);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var0.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1);

    reql_array_append(var0.get(), var7.get());

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 1);

    reql_array_append(var0.get(), var8.get());
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
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
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

  SECTION("test3") {
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

  SECTION("test4") {
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
    reql_number_init(var0.get(), 100001);
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
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "partial";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    reql_null_init(var0.get());
  }

  SECTION("test11") {
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

  SECTION("test12") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "array";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[10]);
    reql_array_init(var2.get(), arr2.get(), 10);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_array_append(var2.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 2);

    reql_array_append(var2.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 3);

    reql_array_append(var2.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 4);

    reql_array_append(var2.get(), var6.get());

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 5);

    reql_array_append(var2.get(), var7.get());

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 6);

    reql_array_append(var2.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 7);

    reql_array_append(var2.get(), var9.get());

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 8);

    reql_array_append(var2.get(), var10.get());

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 9);

    reql_array_append(var2.get(), var11.get());

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 10);

    reql_array_append(var2.get(), var12.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[2]);
    const uint8_t src13[] = "id";
    reql_string_init(var13.get(), buf13.get(), 2);
    reql_string_append(var13.get(), src13, 2);

    ReQL_Obj_c var14;
    reql_number_init(var14.get(), 1);

    reql_object_add(var0.get(), var13.get(), var14.get());
  }
}
