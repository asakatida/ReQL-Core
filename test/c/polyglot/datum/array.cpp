// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests conversion to and from the RQL array type", "[c][ast]") {

  SECTION("test0") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 5);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[5]);
    const uint8_t src0[] = "ARRAY";
    reql_string_init(var0.get(), buf0.get(), 5);
    reql_string_append(var0.get(), src0, 5);
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "[1, 2]";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());
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
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "b";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 2);

    reql_object_add(var0.get(), var3.get(), var4.get());
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test10") {
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

  SECTION("test11") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test13") {
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
    const uint8_t src2[] = "blank";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

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
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test24") {
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
    const uint8_t src2[] = "blank";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

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
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test33") {
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
    const uint8_t src2[] = "blank";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test36") {
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

  SECTION("test37") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test38") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test39") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test40") {
    ReQL_Obj_c var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 4);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test41") {
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

  SECTION("test42") {
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

  SECTION("test43") {
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

  SECTION("test44") {
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

  SECTION("test45") {
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

  SECTION("test46") {
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
    const uint8_t src2[] = "blank";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test49") {
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

  SECTION("test50") {
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

  SECTION("test51") {
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

  SECTION("test52") {
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

  SECTION("test53") {
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

  SECTION("test54") {
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
