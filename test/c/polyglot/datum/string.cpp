// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests of converstion to and from the RQL string type", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[3]);
    const uint8_t src0[] = "str";
    reql_string_init(var0.get(), buf0.get(), 3);
    reql_string_append(var0.get(), src0, 3);
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[3]);
    const uint8_t src0[] = "str";
    reql_string_init(var0.get(), buf0.get(), 3);
    reql_string_append(var0.get(), src0, 3);
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[3]);
    const uint8_t src0[] = "str";
    reql_string_init(var0.get(), buf0.get(), 3);
    reql_string_append(var0.get(), src0, 3);
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[30]);
    const uint8_t src0[] = "\u3053\u3093\u306b\u3061\u306f";
    reql_string_init(var0.get(), buf0.get(), 30);
    reql_string_append(var0.get(), src0, 30);
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "STRING";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[3]);
    const uint8_t src0[] = "foo";
    reql_string_init(var0.get(), buf0.get(), 3);
    reql_string_append(var0.get(), src0, 3);
  }

  SECTION("test6") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_number_init(var0.get(), -1.2);
  }

  SECTION("test7") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test8") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test9") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_number_init(var0.get(), 10);
  }

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[0]);
    const uint8_t src1[] = "";
    reql_string_init(var1.get(), buf1.get(), 0);
    reql_string_append(var1.get(), src1, 0);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[0]);
    const uint8_t src1[] = "";
    reql_string_init(var1.get(), buf1.get(), 0);
    reql_string_append(var1.get(), src1, 0);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test17") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test18") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "cccc";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test19") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "cccc";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test20") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "cccc";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test21") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[16]);
    reql_array_init(var0.get(), arr0.get(), 16);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "a";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[1]);
    const uint8_t src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[1]);
    const uint8_t src5[] = " ";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[1]);
    const uint8_t src6[] = "b";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7;
    _C::CTypes::string buf7(new uint8_t[1]);
    const uint8_t src7[] = "b";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    reql_array_append(var0.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8;
    _C::CTypes::string buf8(new uint8_t[1]);
    const uint8_t src8[] = "b";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9;
    _C::CTypes::string buf9(new uint8_t[1]);
    const uint8_t src9[] = "b";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    reql_array_append(var0.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10;
    _C::CTypes::string buf10(new uint8_t[1]);
    const uint8_t src10[] = " ";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    reql_array_append(var0.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11;
    _C::CTypes::string buf11(new uint8_t[1]);
    const uint8_t src11[] = " ";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    reql_array_append(var0.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12;
    _C::CTypes::string buf12(new uint8_t[1]);
    const uint8_t src12[] = "c";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    reql_array_append(var0.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13;
    _C::CTypes::string buf13(new uint8_t[1]);
    const uint8_t src13[] = "c";
    reql_string_init(var13.get(), buf13.get(), 1);
    reql_string_append(var13.get(), src13, 1);

    reql_array_append(var0.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14;
    _C::CTypes::string buf14(new uint8_t[1]);
    const uint8_t src14[] = "c";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    reql_array_append(var0.get(), var14.get());

    std::unique_ptr<ReQL_Obj_t> var15;
    _C::CTypes::string buf15(new uint8_t[1]);
    const uint8_t src15[] = "c";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    reql_array_append(var0.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var16;
    _C::CTypes::string buf16(new uint8_t[1]);
    const uint8_t src16[] = " ";
    reql_string_init(var16.get(), buf16.get(), 1);
    reql_string_append(var16.get(), src16, 1);

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test22") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[0]);
    const uint8_t src4[] = "";
    reql_string_init(var4.get(), buf4.get(), 0);
    reql_string_append(var4.get(), src4, 0);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "  cccc ";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test23") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[7]);
    const uint8_t src3[] = "  cccc ";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test24") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "cccc ";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test25") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "  cccc b d ";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[3]);
    const uint8_t src4[] = " e ";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = " f";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test26") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[20]);
    const uint8_t src2[] = "cccc b d bb e bbbb f";
    reql_string_init(var2.get(), buf2.get(), 20);
    reql_string_append(var2.get(), src2, 20);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test27") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[13]);
    const uint8_t src2[] = "cccc b d bb e";
    reql_string_init(var2.get(), buf2.get(), 13);
    reql_string_append(var2.get(), src2, 13);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test28") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "cccc";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test29") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "cccc";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test30") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "a";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[1]);
    const uint8_t src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[1]);
    const uint8_t src5[] = " ";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[11]);
    const uint8_t src6[] = "bbbb  cccc ";
    reql_string_init(var6.get(), buf6.get(), 11);
    reql_string_append(var6.get(), src6, 11);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test31") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[0]);
    const uint8_t src4[] = "";
    reql_string_init(var4.get(), buf4.get(), 0);
    reql_string_append(var4.get(), src4, 0);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "  cccc ";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test32") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[7]);
    const uint8_t src3[] = "  cccc ";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test33") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "cccc ";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test34") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "  cccc b d ";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[3]);
    const uint8_t src4[] = " e ";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = " f";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test35") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[20]);
    const uint8_t src2[] = "cccc b d bb e bbbb f";
    reql_string_init(var2.get(), buf2.get(), 20);
    reql_string_append(var2.get(), src2, 20);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test36") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[13]);
    const uint8_t src2[] = "cccc b d bb e";
    reql_string_init(var2.get(), buf2.get(), 13);
    reql_string_append(var2.get(), src2, 13);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test37") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[5]);
    const uint8_t src3[] = "cccc ";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test38") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "b";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test39") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "cccc";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test40") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "a";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[1]);
    const uint8_t src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[12]);
    const uint8_t src5[] = " bbbb  cccc ";
    reql_string_init(var5.get(), buf5.get(), 12);
    reql_string_append(var5.get(), src5, 12);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test41") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[0]);
    const uint8_t src4[] = "";
    reql_string_init(var4.get(), buf4.get(), 0);
    reql_string_append(var4.get(), src4, 0);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "  cccc ";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test42") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[7]);
    const uint8_t src3[] = "  cccc ";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test43") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "cccc ";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test44") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "  cccc b d ";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[3]);
    const uint8_t src4[] = " e ";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = " f";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test45") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[20]);
    const uint8_t src2[] = "cccc b d bb e bbbb f";
    reql_string_init(var2.get(), buf2.get(), 20);
    reql_string_append(var2.get(), src2, 20);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test46") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[13]);
    const uint8_t src2[] = "cccc b d bb e";
    reql_string_init(var2.get(), buf2.get(), 13);
    reql_string_append(var2.get(), src2, 13);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test47") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[11]);
    const uint8_t src2[] = "bbbb  cccc ";
    reql_string_init(var2.get(), buf2.get(), 11);
    reql_string_append(var2.get(), src2, 11);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test48") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[6]);
    const uint8_t src3[] = " cccc ";
    reql_string_init(var3.get(), buf3.get(), 6);
    reql_string_append(var3.get(), src3, 6);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test49") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[14]);
    const uint8_t src3[] = "aa bbbb  cccc ";
    reql_string_init(var3.get(), buf3.get(), 14);
    reql_string_append(var3.get(), src3, 14);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test50") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[9]);
    const uint8_t src3[] = "bb  cccc ";
    reql_string_init(var3.get(), buf3.get(), 9);
    reql_string_append(var3.get(), src3, 9);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test51") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[7]);
    const uint8_t src3[] = "  cccc ";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test52") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "cccc ";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test53") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[5]);
    const uint8_t src1[] = "aaaa ";
    reql_string_init(var1.get(), buf1.get(), 5);
    reql_string_append(var1.get(), src1, 5);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[22]);
    const uint8_t src3[] = "  cccc b d bb e bbbb f";
    reql_string_init(var3.get(), buf3.get(), 22);
    reql_string_append(var3.get(), src3, 22);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test54") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[20]);
    const uint8_t src2[] = "cccc b d bb e bbbb f";
    reql_string_init(var2.get(), buf2.get(), 20);
    reql_string_append(var2.get(), src2, 20);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test55") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[13]);
    const uint8_t src2[] = "cccc b d bb e";
    reql_string_init(var2.get(), buf2.get(), 13);
    reql_string_append(var2.get(), src2, 13);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test56") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test57") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test58") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[0]);
    const uint8_t src1[] = "";
    reql_string_init(var1.get(), buf1.get(), 0);
    reql_string_append(var1.get(), src1, 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test59") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test60") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[0]);
    const uint8_t src1[] = "";
    reql_string_init(var1.get(), buf1.get(), 0);
    reql_string_append(var1.get(), src1, 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test61") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "cccc";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test62") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "cccc";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test63") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[7]);
    reql_array_init(var0.get(), arr0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[0]);
    const uint8_t src1[] = "";
    reql_string_init(var1.get(), buf1.get(), 0);
    reql_string_append(var1.get(), src1, 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "aaaa";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "bbbb";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[4]);
    const uint8_t src6[] = "cccc";
    reql_string_init(var6.get(), buf6.get(), 4);
    reql_string_append(var6.get(), src6, 4);

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7;
    _C::CTypes::string buf7(new uint8_t[0]);
    const uint8_t src7[] = "";
    reql_string_init(var7.get(), buf7.get(), 0);
    reql_string_append(var7.get(), src7, 0);

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test64") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[0]);
    const uint8_t src4[] = "";
    reql_string_init(var4.get(), buf4.get(), 0);
    reql_string_append(var4.get(), src4, 0);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "  cccc ";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test65") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[7]);
    const uint8_t src3[] = "  cccc ";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test66") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "cccc ";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test67") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "  cccc b d ";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[3]);
    const uint8_t src4[] = " e ";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = " f";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test68") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[20]);
    const uint8_t src2[] = "cccc b d bb e bbbb f";
    reql_string_init(var2.get(), buf2.get(), 20);
    reql_string_append(var2.get(), src2, 20);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test69") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[13]);
    const uint8_t src2[] = "cccc b d bb e";
    reql_string_init(var2.get(), buf2.get(), 13);
    reql_string_append(var2.get(), src2, 13);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test70") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "cccc";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test71") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[0]);
    const uint8_t src1[] = "";
    reql_string_init(var1.get(), buf1.get(), 0);
    reql_string_append(var1.get(), src1, 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "aaaa";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "bbbb";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[5]);
    const uint8_t src6[] = "cccc ";
    reql_string_init(var6.get(), buf6.get(), 5);
    reql_string_append(var6.get(), src6, 5);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test72") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[0]);
    const uint8_t src4[] = "";
    reql_string_init(var4.get(), buf4.get(), 0);
    reql_string_append(var4.get(), src4, 0);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "  cccc ";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test73") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[7]);
    const uint8_t src3[] = "  cccc ";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test74") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "cccc ";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test75") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "  cccc b d ";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[3]);
    const uint8_t src4[] = " e ";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = " f";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test76") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[20]);
    const uint8_t src2[] = "cccc b d bb e bbbb f";
    reql_string_init(var2.get(), buf2.get(), 20);
    reql_string_append(var2.get(), src2, 20);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test77") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[13]);
    const uint8_t src2[] = "cccc b d bb e";
    reql_string_init(var2.get(), buf2.get(), 13);
    reql_string_append(var2.get(), src2, 13);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test78") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "bbbb";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[5]);
    const uint8_t src3[] = "cccc ";
    reql_string_init(var3.get(), buf3.get(), 5);
    reql_string_append(var3.get(), src3, 5);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test79") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[1]);
    const uint8_t src2[] = "b";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test80") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[0]);
    const uint8_t src1[] = "";
    reql_string_init(var1.get(), buf1.get(), 0);
    reql_string_append(var1.get(), src1, 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[4]);
    const uint8_t src3[] = "aaaa";
    reql_string_init(var3.get(), buf3.get(), 4);
    reql_string_append(var3.get(), src3, 4);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "bbbb";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[6]);
    const uint8_t src5[] = " cccc ";
    reql_string_init(var5.get(), buf5.get(), 6);
    reql_string_append(var5.get(), src5, 6);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test81") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[5]);
    reql_array_init(var0.get(), arr0.get(), 5);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[0]);
    const uint8_t src3[] = "";
    reql_string_init(var3.get(), buf3.get(), 0);
    reql_string_append(var3.get(), src3, 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[0]);
    const uint8_t src4[] = "";
    reql_string_init(var4.get(), buf4.get(), 0);
    reql_string_append(var4.get(), src4, 0);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[7]);
    const uint8_t src5[] = "  cccc ";
    reql_string_init(var5.get(), buf5.get(), 7);
    reql_string_append(var5.get(), src5, 7);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test82") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[7]);
    const uint8_t src3[] = "  cccc ";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test83") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "cccc ";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test84") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[11]);
    const uint8_t src3[] = "  cccc b d ";
    reql_string_init(var3.get(), buf3.get(), 11);
    reql_string_append(var3.get(), src3, 11);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[3]);
    const uint8_t src4[] = " e ";
    reql_string_init(var4.get(), buf4.get(), 3);
    reql_string_append(var4.get(), src4, 3);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[0]);
    const uint8_t src5[] = "";
    reql_string_init(var5.get(), buf5.get(), 0);
    reql_string_append(var5.get(), src5, 0);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = " f";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test85") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[20]);
    const uint8_t src2[] = "cccc b d bb e bbbb f";
    reql_string_init(var2.get(), buf2.get(), 20);
    reql_string_append(var2.get(), src2, 20);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test86") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[13]);
    const uint8_t src2[] = "cccc b d bb e";
    reql_string_init(var2.get(), buf2.get(), 13);
    reql_string_append(var2.get(), src2, 13);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test87") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[4]);
    const uint8_t src1[] = "aaaa";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[11]);
    const uint8_t src2[] = "bbbb  cccc ";
    reql_string_init(var2.get(), buf2.get(), 11);
    reql_string_append(var2.get(), src2, 11);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test88") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[0]);
    const uint8_t src1[] = "";
    reql_string_init(var1.get(), buf1.get(), 0);
    reql_string_append(var1.get(), src1, 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[16]);
    const uint8_t src3[] = "aaaa bbbb  cccc ";
    reql_string_init(var3.get(), buf3.get(), 16);
    reql_string_append(var3.get(), src3, 16);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test89") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[9]);
    const uint8_t src3[] = "bb  cccc ";
    reql_string_init(var3.get(), buf3.get(), 9);
    reql_string_append(var3.get(), src3, 9);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test90") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[7]);
    const uint8_t src3[] = "  cccc ";
    reql_string_init(var3.get(), buf3.get(), 7);
    reql_string_append(var3.get(), src3, 7);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test91") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[5]);
    const uint8_t src2[] = "cccc ";
    reql_string_init(var2.get(), buf2.get(), 5);
    reql_string_append(var2.get(), src2, 5);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test92") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "  aaaa ";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[0]);
    const uint8_t src2[] = "";
    reql_string_init(var2.get(), buf2.get(), 0);
    reql_string_append(var2.get(), src2, 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[22]);
    const uint8_t src3[] = "  cccc b d bb e bbbb f";
    reql_string_init(var3.get(), buf3.get(), 22);
    reql_string_append(var3.get(), src3, 22);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test93") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[20]);
    const uint8_t src2[] = "cccc b d bb e bbbb f";
    reql_string_init(var2.get(), buf2.get(), 20);
    reql_string_append(var2.get(), src2, 20);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test94") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[6]);
    const uint8_t src1[] = "  aaaa";
    reql_string_init(var1.get(), buf1.get(), 6);
    reql_string_append(var1.get(), src1, 6);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[13]);
    const uint8_t src2[] = "cccc b d bb e";
    reql_string_init(var2.get(), buf2.get(), 13);
    reql_string_append(var2.get(), src2, 13);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "f";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test95") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[11]);
    const uint8_t src0[] = "ABC-DEF-GHJ";
    reql_string_init(var0.get(), buf0.get(), 11);
    reql_string_append(var0.get(), src0, 11);
  }

  SECTION("test96") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[11]);
    const uint8_t src0[] = "abc-def-ghj";
    reql_string_init(var0.get(), buf0.get(), 11);
    reql_string_append(var0.get(), src0, 11);
  }

  SECTION("test97") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "f";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[4]);
    const uint8_t src2[] = "\xe9";
    reql_string_init(var2.get(), buf2.get(), 4);
    reql_string_append(var2.get(), src2, 4);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "o";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[1]);
    const uint8_t src4[] = "o";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test98") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[1]);
    const uint8_t src1[] = "f";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[7]);
    const uint8_t src2[] = "e\u0301";
    reql_string_init(var2.get(), buf2.get(), 7);
    reql_string_append(var2.get(), src2, 7);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[1]);
    const uint8_t src3[] = "o";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[1]);
    const uint8_t src4[] = "o";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test99") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[7]);
    reql_array_init(var0.get(), arr0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[3]);
    const uint8_t src1[] = "foo";
    reql_string_init(var1.get(), buf1.get(), 3);
    reql_string_append(var1.get(), src1, 3);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "bar";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[3]);
    const uint8_t src3[] = "baz";
    reql_string_init(var3.get(), buf3.get(), 3);
    reql_string_append(var3.get(), src3, 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "quux";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[4]);
    const uint8_t src5[] = "fred";
    reql_string_init(var5.get(), buf5.get(), 4);
    reql_string_append(var5.get(), src5, 4);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[6]);
    const uint8_t src6[] = "barney";
    reql_string_init(var6.get(), buf6.get(), 6);
    reql_string_append(var6.get(), src6, 6);

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7;
    _C::CTypes::string buf7(new uint8_t[5]);
    const uint8_t src7[] = "wilma";
    reql_string_init(var7.get(), buf7.get(), 5);
    reql_string_append(var7.get(), src7, 5);

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test100") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[7]);
    reql_array_init(var0.get(), arr0.get(), 7);

    std::unique_ptr<ReQL_Obj_t> var1;
    _C::CTypes::string buf1(new uint8_t[3]);
    const uint8_t src1[] = "foo";
    reql_string_init(var1.get(), buf1.get(), 3);
    reql_string_append(var1.get(), src1, 3);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "bar";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    _C::CTypes::string buf3(new uint8_t[13]);
    const uint8_t src3[] = "baz\u2060quux";
    reql_string_init(var3.get(), buf3.get(), 13);
    reql_string_append(var3.get(), src3, 13);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    _C::CTypes::string buf4(new uint8_t[4]);
    const uint8_t src4[] = "fred";
    reql_string_init(var4.get(), buf4.get(), 4);
    reql_string_append(var4.get(), src4, 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    _C::CTypes::string buf5(new uint8_t[6]);
    const uint8_t src5[] = "barney";
    reql_string_init(var5.get(), buf5.get(), 6);
    reql_string_append(var5.get(), src5, 6);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    _C::CTypes::string buf6(new uint8_t[5]);
    const uint8_t src6[] = "wilma";
    reql_string_init(var6.get(), buf6.get(), 5);
    reql_string_append(var6.get(), src6, 5);

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7;
    _C::CTypes::string buf7(new uint8_t[11]);
    const uint8_t src7[] = "betty\u200b";
    reql_string_init(var7.get(), buf7.get(), 11);
    reql_string_append(var7.get(), src7, 11);

    reql_array_append(var0.get(), var7.get());
  }
}
