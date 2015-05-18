// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test basic time arithmetic", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[24]);
    const uint8_t src0[] = "Sat May 30 23:34:00 1998";
    reql_string_init(var0.get(), buf0.get(), 24);
    reql_string_append(var0.get(), src0, 24);
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "more";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[24]);
    const uint8_t src3[] = "Tue Jul 31 09:20:40 2001";
    reql_string_init(var3.get(), buf3.get(), 24);
    reql_string_append(var3.get(), src3, 24);

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[5]);
    const uint8_t src4[] = "stuff";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[24]);
    const uint8_t src5[] = "Sat May 30 23:34:00 1998";
    reql_string_init(var5.get(), buf5.get(), 24);
    reql_string_append(var5.get(), src5, 24);

    reql_object_add(var0.get(), var4.get(), var5.get());
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[24]);
    const uint8_t src1[] = "Thu Mar 30 13:47:20 1995";
    reql_string_init(var1.get(), buf1.get(), 24);
    reql_string_append(var1.get(), src1, 24);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[24]);
    const uint8_t src2[] = "Sat May 30 23:34:00 1998";
    reql_string_init(var2.get(), buf2.get(), 24);
    reql_string_append(var2.get(), src2, 24);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[5]);
    const uint8_t src4[] = "stuff";
    reql_string_init(var4.get(), buf4.get(), 5);
    reql_string_append(var4.get(), src4, 5);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[24]);
    const uint8_t src5[] = "Tue Jul 31 09:20:40 2001";
    reql_string_init(var5.get(), buf5.get(), 24);
    reql_string_append(var5.get(), src5, 24);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "nested";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    ReQL_Obj_c var2;
    _C::CTypes::pairs pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "time";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[24]);
    const uint8_t src4[] = "Sat May 30 23:34:00 1998";
    reql_string_init(var4.get(), buf4.get(), 24);
    reql_string_append(var4.get(), src4, 24);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "two";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::array arr3(new ReQL_Obj_t*[3]);
    reql_array_init(var3.get(), arr3.get(), 3);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[1]);
    const uint8_t src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var3.get(), var4.get());

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[24]);
    const uint8_t src5[] = "Sat May 30 23:34:00 1998";
    reql_string_init(var5.get(), buf5.get(), 24);
    reql_string_append(var5.get(), src5, 24);

    reql_array_append(var3.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 3);

    reql_array_append(var3.get(), var6.get());

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), -1);
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.444);
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[29]);
    const uint8_t src0[] = "1970-01-01T00:00:01.444+00:00";
    reql_string_init(var0.get(), buf0.get(), 29);
    reql_string_append(var0.get(), src0, 29);
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1.444);
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 10000);
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

  SECTION("test13") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 253440000000);
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1400);
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
    reql_number_init(var0.get(), -17990000000);
  }
}
