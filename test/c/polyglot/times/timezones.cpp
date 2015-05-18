// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Test basic timezone manipulation", "[c][ast]") {

  SECTION("test14") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[6]);
    const uint8_t src2[] = "+00:00";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 29);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[6]);
    const uint8_t src5[] = "+00:00";
    reql_string_init(var5.get(), buf5.get(), 6);
    reql_string_append(var5.get(), src5, 6);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 29);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::array arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[6]);
    const uint8_t src8[] = "+00:00";
    reql_string_init(var8.get(), buf8.get(), 6);
    reql_string_append(var8.get(), src8, 6);

    reql_array_append(var7.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 29);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[6]);
    const uint8_t src2[] = "-00:59";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 29);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[6]);
    const uint8_t src5[] = "-01:00";
    reql_string_init(var5.get(), buf5.get(), 6);
    reql_string_append(var5.get(), src5, 6);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 29);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::array arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[6]);
    const uint8_t src8[] = "-01:01";
    reql_string_init(var8.get(), buf8.get(), 6);
    reql_string_append(var8.get(), src8, 6);

    reql_array_append(var7.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 29);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    _C::CTypes::array arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    ReQL_Obj_c var2;
    _C::CTypes::string buf2(new uint8_t[6]);
    const uint8_t src2[] = "+00:59";
    reql_string_init(var2.get(), buf2.get(), 6);
    reql_string_append(var2.get(), src2, 6);

    reql_array_append(var1.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 30);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    _C::CTypes::array arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    ReQL_Obj_c var5;
    _C::CTypes::string buf5(new uint8_t[6]);
    const uint8_t src5[] = "+01:00";
    reql_string_init(var5.get(), buf5.get(), 6);
    reql_string_append(var5.get(), src5, 6);

    reql_array_append(var4.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 30);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    _C::CTypes::array arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[6]);
    const uint8_t src8[] = "+01:01";
    reql_string_init(var8.get(), buf8.get(), 6);
    reql_string_append(var8.get(), src8, 6);

    reql_array_append(var7.get(), var8.get());

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 30);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());
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

  SECTION("test23") {
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
}
