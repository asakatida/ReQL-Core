// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests replacement of selections", "[c][ast]") {

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
    _C::CTypes::string buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    reql_null_init(var9.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[2]);
    const uint8_t src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[11]);
    const uint8_t src12[] = "first_error";
    reql_string_init(var12.get(), buf12.get(), 11);
    reql_string_append(var12.get(), src12, 11);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[67]);
    const uint8_t src13[] = "Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
    reql_string_init(var13.get(), buf13.get(), 67);
    reql_string_append(var13.get(), src13, 67);

    reql_object_add(var0.get(), var12.get(), var13.get());
  }

  SECTION("test3") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 1);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    reql_null_init(var9.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[7]);
    const uint8_t src10[] = "deleted";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_object_add(var0.get(), var10.get(), var11.get());

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[6]);
    const uint8_t src12[] = "errors";
    reql_string_init(var12.get(), buf12.get(), 6);
    reql_string_append(var12.get(), src12, 6);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_object_add(var0.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[8]);
    const uint8_t src14[] = "inserted";
    reql_string_init(var14.get(), buf14.get(), 8);
    reql_string_append(var14.get(), src14, 8);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 1);

    reql_object_add(var0.get(), var14.get(), var15.get());

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[8]);
    const uint8_t src16[] = "replaced";
    reql_string_init(var16.get(), buf16.get(), 8);
    reql_string_append(var16.get(), src16, 8);

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 0);

    reql_object_add(var0.get(), var16.get(), var17.get());

    ReQL_Obj_c var18;
    _C::CTypes::string buf18(new uint8_t[7]);
    const uint8_t src18[] = "skipped";
    reql_string_init(var18.get(), buf18.get(), 7);
    reql_string_append(var18.get(), src18, 7);

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 0);

    reql_object_add(var0.get(), var18.get(), var19.get());

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[9]);
    const uint8_t src20[] = "unchanged";
    reql_string_init(var20.get(), buf20.get(), 9);
    reql_string_append(var20.get(), src20, 9);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 0);

    reql_object_add(var0.get(), var20.get(), var21.get());
  }

  SECTION("test4") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[2]);
    const uint8_t src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[11]);
    const uint8_t src12[] = "first_error";
    reql_string_init(var12.get(), buf12.get(), 11);
    reql_string_append(var12.get(), src12, 11);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[67]);
    const uint8_t src13[] = "Duplicate primary key `id`:\n{\n\t\"id\":\t0\n}\n{\n\t\"id\":\t0\n}";
    reql_string_init(var13.get(), buf13.get(), 67);
    reql_string_append(var13.get(), src13, 67);

    reql_object_add(var0.get(), var12.get(), var13.get());
  }

  SECTION("test5") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[1]);
    const uint8_t src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[7]);
    const uint8_t src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[1]);
    const uint8_t src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[7]);
    const uint8_t src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[1]);
    const uint8_t src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[11]);
    const uint8_t src16[] = "first_error";
    reql_string_init(var16.get(), buf16.get(), 11);
    reql_string_append(var16.get(), src16, 11);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[1]);
    const uint8_t src17[] = "a";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    reql_object_add(var0.get(), var16.get(), var17.get());
  }

  SECTION("test7") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[2]);
    reql_array_init(var2.get(), arr2.get(), 2);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[1]);
    const uint8_t src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 3);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[7]);
    const uint8_t src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[1]);
    const uint8_t src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[2]);
    reql_object_init(var16.get(), pair16.get(), 2);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[7]);
    const uint8_t src17[] = "new_val";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    ReQL_Obj_c var18;
    _C::CTypes::pairs pair18(new ReQL_Pair_t[2]);
    reql_object_init(var18.get(), pair18.get(), 2);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[2]);
    const uint8_t src19[] = "id";
    reql_string_init(var19.get(), buf19.get(), 2);
    reql_string_append(var19.get(), src19, 2);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 1);

    reql_object_add(var18.get(), var19.get(), var20.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[1]);
    const uint8_t src21[] = "x";
    reql_string_init(var21.get(), buf21.get(), 1);
    reql_string_append(var21.get(), src21, 1);

    ReQL_Obj_c var22;
    reql_number_init(var22.get(), 3);

    reql_object_add(var18.get(), var21.get(), var22.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[7]);
    const uint8_t src23[] = "old_val";
    reql_string_init(var23.get(), buf23.get(), 7);
    reql_string_append(var23.get(), src23, 7);

    ReQL_Obj_c var24;
    _C::CTypes::pairs pair24(new ReQL_Pair_t[1]);
    reql_object_init(var24.get(), pair24.get(), 1);

    ReQL_Obj_c var25;
    _C::CTypes::string buf25(new uint8_t[2]);
    const uint8_t src25[] = "id";
    reql_string_init(var25.get(), buf25.get(), 2);
    reql_string_append(var25.get(), src25, 2);

    ReQL_Obj_c var26;
    reql_number_init(var26.get(), 1);

    reql_object_add(var24.get(), var25.get(), var26.get());

    reql_object_add(var16.get(), var23.get(), var24.get());

    reql_array_append(var2.get(), var16.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test8") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[1]);
    const uint8_t src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 2);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[7]);
    const uint8_t src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[1]);
    const uint8_t src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[2]);
    reql_object_init(var5.get(), pair5.get(), 2);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[1]);
    const uint8_t src8[] = "x";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 2);

    reql_object_add(var5.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[7]);
    const uint8_t src10[] = "old_val";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    ReQL_Obj_c var11;
    _C::CTypes::pairs pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[2]);
    const uint8_t src12[] = "id";
    reql_string_init(var12.get(), buf12.get(), 2);
    reql_string_append(var12.get(), src12, 2);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[1]);
    const uint8_t src14[] = "x";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 2);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_object_add(var3.get(), var10.get(), var11.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[11]);
    const uint8_t src16[] = "first_error";
    reql_string_init(var16.get(), buf16.get(), 11);
    reql_string_append(var16.get(), src16, 11);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[1]);
    const uint8_t src17[] = "a";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    reql_object_add(var0.get(), var16.get(), var17.get());
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[2]);
    reql_array_init(var2.get(), arr2.get(), 2);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[2]);
    reql_object_init(var9.get(), pair9.get(), 2);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[2]);
    const uint8_t src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_object_add(var9.get(), var10.get(), var11.get());

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[1]);
    const uint8_t src12[] = "x";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 2);

    reql_object_add(var9.get(), var12.get(), var13.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[7]);
    const uint8_t src15[] = "new_val";
    reql_string_init(var15.get(), buf15.get(), 7);
    reql_string_append(var15.get(), src15, 7);

    ReQL_Obj_c var16;
    _C::CTypes::pairs pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[2]);
    const uint8_t src17[] = "id";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 1);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[7]);
    const uint8_t src19[] = "old_val";
    reql_string_init(var19.get(), buf19.get(), 7);
    reql_string_append(var19.get(), src19, 7);

    ReQL_Obj_c var20;
    _C::CTypes::pairs pair20(new ReQL_Pair_t[2]);
    reql_object_init(var20.get(), pair20.get(), 2);

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[2]);
    const uint8_t src21[] = "id";
    reql_string_init(var21.get(), buf21.get(), 2);
    reql_string_append(var21.get(), src21, 2);

    ReQL_Obj_c var22;
    reql_number_init(var22.get(), 1);

    reql_object_add(var20.get(), var21.get(), var22.get());

    ReQL_Obj_c var23;
    _C::CTypes::string buf23(new uint8_t[1]);
    const uint8_t src23[] = "x";
    reql_string_init(var23.get(), buf23.get(), 1);
    reql_string_append(var23.get(), src23, 1);

    ReQL_Obj_c var24;
    reql_number_init(var24.get(), 3);

    reql_object_add(var20.get(), var23.get(), var24.get());

    reql_object_add(var14.get(), var19.get(), var20.get());

    reql_array_append(var2.get(), var14.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[2]);
    reql_object_init(var0.get(), pair0.get(), 2);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[2]);
    reql_array_init(var2.get(), arr2.get(), 2);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    _C::CTypes::pairs pair5(new ReQL_Pair_t[1]);
    reql_object_init(var5.get(), pair5.get(), 1);

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[2]);
    const uint8_t src6[] = "id";
    reql_string_init(var6.get(), buf6.get(), 2);
    reql_string_append(var6.get(), src6, 2);

    ReQL_Obj_c var7;
    reql_number_init(var7.get(), 0);

    reql_object_add(var5.get(), var6.get(), var7.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[7]);
    const uint8_t src8[] = "old_val";
    reql_string_init(var8.get(), buf8.get(), 7);
    reql_string_append(var8.get(), src8, 7);

    ReQL_Obj_c var9;
    _C::CTypes::pairs pair9(new ReQL_Pair_t[1]);
    reql_object_init(var9.get(), pair9.get(), 1);

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[2]);
    const uint8_t src10[] = "id";
    reql_string_init(var10.get(), buf10.get(), 2);
    reql_string_append(var10.get(), src10, 2);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 0);

    reql_object_add(var9.get(), var10.get(), var11.get());

    reql_object_add(var3.get(), var8.get(), var9.get());

    reql_array_append(var2.get(), var3.get());

    ReQL_Obj_c var12;
    _C::CTypes::pairs pair12(new ReQL_Pair_t[2]);
    reql_object_init(var12.get(), pair12.get(), 2);

    ReQL_Obj_c var13;
    _C::CTypes::string buf13(new uint8_t[7]);
    const uint8_t src13[] = "new_val";
    reql_string_init(var13.get(), buf13.get(), 7);
    reql_string_append(var13.get(), src13, 7);

    ReQL_Obj_c var14;
    _C::CTypes::pairs pair14(new ReQL_Pair_t[1]);
    reql_object_init(var14.get(), pair14.get(), 1);

    ReQL_Obj_c var15;
    _C::CTypes::string buf15(new uint8_t[2]);
    const uint8_t src15[] = "id";
    reql_string_init(var15.get(), buf15.get(), 2);
    reql_string_append(var15.get(), src15, 2);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 1);

    reql_object_add(var14.get(), var15.get(), var16.get());

    reql_object_add(var12.get(), var13.get(), var14.get());

    ReQL_Obj_c var17;
    _C::CTypes::string buf17(new uint8_t[7]);
    const uint8_t src17[] = "old_val";
    reql_string_init(var17.get(), buf17.get(), 7);
    reql_string_append(var17.get(), src17, 7);

    ReQL_Obj_c var18;
    _C::CTypes::pairs pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    ReQL_Obj_c var19;
    _C::CTypes::string buf19(new uint8_t[2]);
    const uint8_t src19[] = "id";
    reql_string_init(var19.get(), buf19.get(), 2);
    reql_string_append(var19.get(), src19, 2);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 1);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var12.get(), var17.get(), var18.get());

    reql_array_append(var2.get(), var12.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var21;
    _C::CTypes::string buf21(new uint8_t[11]);
    const uint8_t src21[] = "first_error";
    reql_string_init(var21.get(), buf21.get(), 11);
    reql_string_append(var21.get(), src21, 11);

    ReQL_Obj_c var22;
    _C::CTypes::string buf22(new uint8_t[62]);
    const uint8_t src22[] = "Inserted object must have primary key `id`:\n{\n\t\"x\":\t1\n}";
    reql_string_init(var22.get(), buf22.get(), 62);
    reql_string_append(var22.get(), src22, 62);

    reql_object_add(var0.get(), var21.get(), var22.get());
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    reql_null_init(var5.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    ReQL_Obj_c var7;
    _C::CTypes::pairs pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 0);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    _C::CTypes::pairs pair0(new ReQL_Pair_t[7]);
    reql_object_init(var0.get(), pair0.get(), 7);

    ReQL_Obj_c var1;
    _C::CTypes::string buf1(new uint8_t[7]);
    const uint8_t src1[] = "changes";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    _C::CTypes::array arr2(new ReQL_Obj_t*[1]);
    reql_array_init(var2.get(), arr2.get(), 1);

    ReQL_Obj_c var3;
    _C::CTypes::pairs pair3(new ReQL_Pair_t[2]);
    reql_object_init(var3.get(), pair3.get(), 2);

    ReQL_Obj_c var4;
    _C::CTypes::string buf4(new uint8_t[7]);
    const uint8_t src4[] = "new_val";
    reql_string_init(var4.get(), buf4.get(), 7);
    reql_string_append(var4.get(), src4, 7);

    ReQL_Obj_c var5;
    reql_null_init(var5.get());

    reql_object_add(var3.get(), var4.get(), var5.get());

    ReQL_Obj_c var6;
    _C::CTypes::string buf6(new uint8_t[7]);
    const uint8_t src6[] = "old_val";
    reql_string_init(var6.get(), buf6.get(), 7);
    reql_string_append(var6.get(), src6, 7);

    ReQL_Obj_c var7;
    _C::CTypes::pairs pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    ReQL_Obj_c var8;
    _C::CTypes::string buf8(new uint8_t[2]);
    const uint8_t src8[] = "id";
    reql_string_init(var8.get(), buf8.get(), 2);
    reql_string_append(var8.get(), src8, 2);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 1);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_object_add(var3.get(), var6.get(), var7.get());

    reql_array_append(var2.get(), var3.get());

    reql_object_add(var0.get(), var1.get(), var2.get());

    ReQL_Obj_c var10;
    _C::CTypes::string buf10(new uint8_t[7]);
    const uint8_t src10[] = "deleted";
    reql_string_init(var10.get(), buf10.get(), 7);
    reql_string_append(var10.get(), src10, 7);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 1);

    reql_object_add(var0.get(), var10.get(), var11.get());

    ReQL_Obj_c var12;
    _C::CTypes::string buf12(new uint8_t[6]);
    const uint8_t src12[] = "errors";
    reql_string_init(var12.get(), buf12.get(), 6);
    reql_string_append(var12.get(), src12, 6);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 0);

    reql_object_add(var0.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    _C::CTypes::string buf14(new uint8_t[8]);
    const uint8_t src14[] = "inserted";
    reql_string_init(var14.get(), buf14.get(), 8);
    reql_string_append(var14.get(), src14, 8);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 0);

    reql_object_add(var0.get(), var14.get(), var15.get());

    ReQL_Obj_c var16;
    _C::CTypes::string buf16(new uint8_t[8]);
    const uint8_t src16[] = "replaced";
    reql_string_init(var16.get(), buf16.get(), 8);
    reql_string_append(var16.get(), src16, 8);

    ReQL_Obj_c var17;
    reql_number_init(var17.get(), 0);

    reql_object_add(var0.get(), var16.get(), var17.get());

    ReQL_Obj_c var18;
    _C::CTypes::string buf18(new uint8_t[7]);
    const uint8_t src18[] = "skipped";
    reql_string_init(var18.get(), buf18.get(), 7);
    reql_string_append(var18.get(), src18, 7);

    ReQL_Obj_c var19;
    reql_number_init(var19.get(), 0);

    reql_object_add(var0.get(), var18.get(), var19.get());

    ReQL_Obj_c var20;
    _C::CTypes::string buf20(new uint8_t[9]);
    const uint8_t src20[] = "unchanged";
    reql_string_init(var20.get(), buf20.get(), 9);
    reql_string_append(var20.get(), src20, 9);

    ReQL_Obj_c var21;
    reql_number_init(var21.get(), 0);

    reql_object_add(var0.get(), var20.get(), var21.get());
  }
}
