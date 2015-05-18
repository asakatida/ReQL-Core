// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests manipulation operations on arrays", "[c][ast]") {

  SECTION("test4") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
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

  SECTION("test5") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
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
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "a";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test6") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
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

  SECTION("test7") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[1]);
    const uint8_t src1[] = "a";
    reql_string_init(var1.get(), buf1.get(), 1);
    reql_string_append(var1.get(), src1, 1);

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

  SECTION("test8") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test9") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test10") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test12") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
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
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[5]);
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

  SECTION("test14") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[5]);
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
    reql_number_init(var4.get(), 5);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 6);

    reql_array_append(var0.get(), var5.get());
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test20") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 2);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test24") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 3);

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test25") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test26") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test27") {
    ReQL_Obj_c var0;
    reql_array_init(var0.get(), nullptr, 0);
  }

  SECTION("test28") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test29") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "a";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "a";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "b";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    ReQL_Obj_c var10;
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "b";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "a";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 3);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "b";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "c";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());
  }

  SECTION("test30") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "a";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    ReQL_Obj_c var8;
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "a";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 3);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test31") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_object_init(var1.get(), nullptr, 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_object_init(var2.get(), nullptr, 0);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_object_init(var3.get(), nullptr, 0);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test33") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "a";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    ReQL_Obj_c var8;
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "a";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 3);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var7.get());

    ReQL_Obj_c var10;
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    ReQL_Obj_c var11;
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "a";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var13;
    std::unique_ptr<ReQL_Pair_t[]> pair13(new ReQL_Pair_t[1]);
    reql_object_init(var13.get(), pair13.get(), 1);

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "a";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 2);

    reql_object_add(var13.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var13.get());

    ReQL_Obj_c var16;
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[1]);
    const uint8_t src17[] = "a";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 3);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test34") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "b";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "a";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "b";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    ReQL_Obj_c var6;
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[1]);
    const uint8_t src6[] = "b";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    ReQL_Obj_c var8;
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "b";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "c";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var7.get());

    ReQL_Obj_c var10;
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    ReQL_Obj_c var11;
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[1]);
    const uint8_t src11[] = "b";
    reql_string_init(var11.get(), buf11.get(), 1);
    reql_string_append(var11.get(), src11, 1);

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "a";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var13;
    std::unique_ptr<ReQL_Pair_t[]> pair13(new ReQL_Pair_t[1]);
    reql_object_init(var13.get(), pair13.get(), 1);

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "b";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "b";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    reql_object_add(var13.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var13.get());

    ReQL_Obj_c var16;
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[1]);
    const uint8_t src17[] = "b";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    ReQL_Obj_c var18;
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[1]);
    const uint8_t src18[] = "c";
    reql_string_init(var18.get(), buf18.get(), 1);
    reql_string_append(var18.get(), src18, 1);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test35") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "a";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "a";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "b";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    ReQL_Obj_c var10;
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "b";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "a";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 3);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "b";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "c";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());
  }

  SECTION("test36") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[10]);
    reql_array_init(var0.get(), arr0.get(), 10);

    ReQL_Obj_c var1;
    reql_object_init(var1.get(), nullptr, 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_object_init(var2.get(), nullptr, 0);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_object_init(var3.get(), nullptr, 0);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_object_init(var4.get(), nullptr, 0);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_object_init(var5.get(), nullptr, 0);

    reql_array_append(var0.get(), var5.get());

    ReQL_Obj_c var6;
    reql_object_init(var6.get(), nullptr, 0);

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var7;
    reql_object_init(var7.get(), nullptr, 0);

    reql_array_append(var0.get(), var7.get());

    ReQL_Obj_c var8;
    reql_object_init(var8.get(), nullptr, 0);

    reql_array_append(var0.get(), var8.get());

    ReQL_Obj_c var9;
    reql_object_init(var9.get(), nullptr, 0);

    reql_array_append(var0.get(), var9.get());

    ReQL_Obj_c var10;
    reql_object_init(var10.get(), nullptr, 0);

    reql_array_append(var0.get(), var10.get());
  }

  SECTION("test38") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "b";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    std::unique_ptr<ReQL_Pair_t[]> pair3(new ReQL_Pair_t[1]);
    reql_object_init(var3.get(), pair3.get(), 1);

    ReQL_Obj_c var4;
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "c";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_object_add(var3.get(), var4.get(), var5.get());

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[1]);
    reql_object_init(var6.get(), pair6.get(), 1);

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "b";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    std::unique_ptr<ReQL_Pair_t[]> pair8(new ReQL_Pair_t[1]);
    reql_object_init(var8.get(), pair8.get(), 1);

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "c";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    ReQL_Obj_c var10;
    reql_number_init(var10.get(), 2);

    reql_object_add(var8.get(), var9.get(), var10.get());

    reql_object_add(var6.get(), var7.get(), var8.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[1]);
    reql_object_init(var11.get(), pair11.get(), 1);

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "b";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    std::unique_ptr<ReQL_Pair_t[]> pair13(new ReQL_Pair_t[1]);
    reql_object_init(var13.get(), pair13.get(), 1);

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "c";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_object_add(var13.get(), var14.get(), var15.get());

    reql_object_add(var11.get(), var12.get(), var13.get());

    reql_array_append(var0.get(), var11.get());

    ReQL_Obj_c var16;
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[1]);
    const uint8_t src17[] = "b";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    ReQL_Obj_c var18;
    std::unique_ptr<ReQL_Pair_t[]> pair18(new ReQL_Pair_t[1]);
    reql_object_init(var18.get(), pair18.get(), 1);

    ReQL_Obj_c var19;
    std::unique_ptr<uint8_t[]> buf19(new uint8_t[1]);
    const uint8_t src19[] = "c";
    reql_string_init(var19.get(), buf19.get(), 1);
    reql_string_append(var19.get(), src19, 1);

    ReQL_Obj_c var20;
    reql_number_init(var20.get(), 1);

    reql_object_add(var18.get(), var19.get(), var20.get());

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_array_append(var0.get(), var16.get());

    ReQL_Obj_c var21;
    std::unique_ptr<ReQL_Pair_t[]> pair21(new ReQL_Pair_t[1]);
    reql_object_init(var21.get(), pair21.get(), 1);

    ReQL_Obj_c var22;
    std::unique_ptr<uint8_t[]> buf22(new uint8_t[1]);
    const uint8_t src22[] = "b";
    reql_string_init(var22.get(), buf22.get(), 1);
    reql_string_append(var22.get(), src22, 1);

    ReQL_Obj_c var23;
    std::unique_ptr<ReQL_Pair_t[]> pair23(new ReQL_Pair_t[1]);
    reql_object_init(var23.get(), pair23.get(), 1);

    ReQL_Obj_c var24;
    std::unique_ptr<uint8_t[]> buf24(new uint8_t[1]);
    const uint8_t src24[] = "c";
    reql_string_init(var24.get(), buf24.get(), 1);
    reql_string_append(var24.get(), src24, 1);

    ReQL_Obj_c var25;
    reql_number_init(var25.get(), 2);

    reql_object_add(var23.get(), var24.get(), var25.get());

    reql_object_add(var21.get(), var22.get(), var23.get());

    reql_array_append(var0.get(), var21.get());

    ReQL_Obj_c var26;
    std::unique_ptr<ReQL_Pair_t[]> pair26(new ReQL_Pair_t[1]);
    reql_object_init(var26.get(), pair26.get(), 1);

    ReQL_Obj_c var27;
    std::unique_ptr<uint8_t[]> buf27(new uint8_t[1]);
    const uint8_t src27[] = "b";
    reql_string_init(var27.get(), buf27.get(), 1);
    reql_string_append(var27.get(), src27, 1);

    ReQL_Obj_c var28;
    std::unique_ptr<ReQL_Pair_t[]> pair28(new ReQL_Pair_t[1]);
    reql_object_init(var28.get(), pair28.get(), 1);

    ReQL_Obj_c var29;
    std::unique_ptr<uint8_t[]> buf29(new uint8_t[1]);
    const uint8_t src29[] = "c";
    reql_string_init(var29.get(), buf29.get(), 1);
    reql_string_append(var29.get(), src29, 1);

    ReQL_Obj_c var30;
    reql_number_init(var30.get(), 3);

    reql_object_add(var28.get(), var29.get(), var30.get());

    reql_object_add(var26.get(), var27.get(), var28.get());

    reql_array_append(var0.get(), var26.get());
  }

  SECTION("test39") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test40") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test41") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    reql_object_init(var1.get(), nullptr, 0);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_object_init(var2.get(), nullptr, 0);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_object_init(var3.get(), nullptr, 0);

    reql_array_append(var0.get(), var3.get());
  }

  SECTION("test42") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "b";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[1]);
    const uint8_t src3[] = "a";
    reql_string_init(var3.get(), buf3.get(), 1);
    reql_string_append(var3.get(), src3, 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "b";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    ReQL_Obj_c var6;
    std::unique_ptr<uint8_t[]> buf6(new uint8_t[1]);
    const uint8_t src6[] = "b";
    reql_string_init(var6.get(), buf6.get(), 1);
    reql_string_append(var6.get(), src6, 1);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    ReQL_Obj_c var8;
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "b";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "c";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var7.get());
  }

  SECTION("test43") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "a";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "a";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "b";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    ReQL_Obj_c var10;
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "b";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "a";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 3);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "b";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "c";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());
  }

  SECTION("test44") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
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

  SECTION("test45") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 6);
  }

  SECTION("test46") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 6);
  }

  SECTION("test47") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 12);
  }

  SECTION("test48") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 12);
  }

  SECTION("test49") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[1]);
    reql_array_init(var0.get(), arr0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 2);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "b";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());
  }

  SECTION("test50") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_array_append(var0.get(), var3.get());

    ReQL_Obj_c var4;
    reql_number_init(var4.get(), 2);

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var5;
    reql_number_init(var5.get(), 1);

    reql_array_append(var0.get(), var5.get());

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_array_append(var0.get(), var6.get());
  }

  SECTION("test51") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "v";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[2]);
    const uint8_t src5[] = "v2";
    reql_string_init(var5.get(), buf5.get(), 2);
    reql_string_append(var5.get(), src5, 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var7;
    std::unique_ptr<ReQL_Pair_t[]> pair7(new ReQL_Pair_t[1]);
    reql_object_init(var7.get(), pair7.get(), 1);

    ReQL_Obj_c var8;
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "v";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    ReQL_Obj_c var9;
    reql_number_init(var9.get(), 2);

    reql_object_add(var7.get(), var8.get(), var9.get());

    reql_array_append(var0.get(), var7.get());

    ReQL_Obj_c var10;
    std::unique_ptr<ReQL_Pair_t[]> pair10(new ReQL_Pair_t[1]);
    reql_object_init(var10.get(), pair10.get(), 1);

    ReQL_Obj_c var11;
    std::unique_ptr<uint8_t[]> buf11(new uint8_t[2]);
    const uint8_t src11[] = "v2";
    reql_string_init(var11.get(), buf11.get(), 2);
    reql_string_append(var11.get(), src11, 2);

    ReQL_Obj_c var12;
    reql_number_init(var12.get(), 3);

    reql_object_add(var10.get(), var11.get(), var12.get());

    reql_array_append(var0.get(), var10.get());

    ReQL_Obj_c var13;
    std::unique_ptr<ReQL_Pair_t[]> pair13(new ReQL_Pair_t[1]);
    reql_object_init(var13.get(), pair13.get(), 1);

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "v";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    reql_number_init(var15.get(), 3);

    reql_object_add(var13.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var13.get());

    ReQL_Obj_c var16;
    std::unique_ptr<ReQL_Pair_t[]> pair16(new ReQL_Pair_t[1]);
    reql_object_init(var16.get(), pair16.get(), 1);

    ReQL_Obj_c var17;
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[2]);
    const uint8_t src17[] = "v2";
    reql_string_init(var17.get(), buf17.get(), 2);
    reql_string_append(var17.get(), src17, 2);

    ReQL_Obj_c var18;
    reql_number_init(var18.get(), 4);

    reql_object_add(var16.get(), var17.get(), var18.get());

    reql_array_append(var0.get(), var16.get());
  }

  SECTION("test52") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "a";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "a";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "b";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    ReQL_Obj_c var10;
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "b";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "a";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 3);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "b";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "c";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());
  }

  SECTION("test53") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[3]);
    reql_array_init(var0.get(), arr0.get(), 3);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[2]);
    reql_object_init(var1.get(), pair1.get(), 2);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[1]);
    const uint8_t src2[] = "a";
    reql_string_init(var2.get(), buf2.get(), 1);
    reql_string_append(var2.get(), src2, 1);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 3);

    reql_object_add(var1.get(), var2.get(), var3.get());

    ReQL_Obj_c var4;
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[1]);
    const uint8_t src4[] = "b";
    reql_string_init(var4.get(), buf4.get(), 1);
    reql_string_append(var4.get(), src4, 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "c";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    reql_object_add(var1.get(), var4.get(), var5.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var6;
    std::unique_ptr<ReQL_Pair_t[]> pair6(new ReQL_Pair_t[2]);
    reql_object_init(var6.get(), pair6.get(), 2);

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "a";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    reql_number_init(var8.get(), 2);

    reql_object_add(var6.get(), var7.get(), var8.get());

    ReQL_Obj_c var9;
    std::unique_ptr<uint8_t[]> buf9(new uint8_t[1]);
    const uint8_t src9[] = "b";
    reql_string_init(var9.get(), buf9.get(), 1);
    reql_string_append(var9.get(), src9, 1);

    ReQL_Obj_c var10;
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "b";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    reql_object_add(var6.get(), var9.get(), var10.get());

    reql_array_append(var0.get(), var6.get());

    ReQL_Obj_c var11;
    std::unique_ptr<ReQL_Pair_t[]> pair11(new ReQL_Pair_t[2]);
    reql_object_init(var11.get(), pair11.get(), 2);

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "a";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    reql_number_init(var13.get(), 1);

    reql_object_add(var11.get(), var12.get(), var13.get());

    ReQL_Obj_c var14;
    std::unique_ptr<uint8_t[]> buf14(new uint8_t[1]);
    const uint8_t src14[] = "b";
    reql_string_init(var14.get(), buf14.get(), 1);
    reql_string_append(var14.get(), src14, 1);

    ReQL_Obj_c var15;
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    reql_object_add(var11.get(), var14.get(), var15.get());

    reql_array_append(var0.get(), var11.get());
  }

  SECTION("test54") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    std::unique_ptr<ReQL_Pair_t[]> pair1(new ReQL_Pair_t[1]);
    reql_object_init(var1.get(), pair1.get(), 1);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[2]);
    const uint8_t src2[] = "-a";
    reql_string_init(var2.get(), buf2.get(), 2);
    reql_string_append(var2.get(), src2, 2);

    ReQL_Obj_c var3;
    reql_number_init(var3.get(), 1);

    reql_object_add(var1.get(), var2.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var4;
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[1]);
    reql_object_init(var4.get(), pair4.get(), 1);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[2]);
    const uint8_t src5[] = "-a";
    reql_string_init(var5.get(), buf5.get(), 2);
    reql_string_append(var5.get(), src5, 2);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 2);

    reql_object_add(var4.get(), var5.get(), var6.get());

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test55") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
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

  SECTION("test56") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test57") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[6]);
    reql_array_init(var0.get(), arr0.get(), 6);

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
    std::unique_ptr<ReQL_Pair_t[]> pair4(new ReQL_Pair_t[2]);
    reql_object_init(var4.get(), pair4.get(), 2);

    ReQL_Obj_c var5;
    std::unique_ptr<uint8_t[]> buf5(new uint8_t[1]);
    const uint8_t src5[] = "a";
    reql_string_init(var5.get(), buf5.get(), 1);
    reql_string_append(var5.get(), src5, 1);

    ReQL_Obj_c var6;
    reql_number_init(var6.get(), 1);

    reql_object_add(var4.get(), var5.get(), var6.get());

    ReQL_Obj_c var7;
    std::unique_ptr<uint8_t[]> buf7(new uint8_t[1]);
    const uint8_t src7[] = "b";
    reql_string_init(var7.get(), buf7.get(), 1);
    reql_string_append(var7.get(), src7, 1);

    ReQL_Obj_c var8;
    std::unique_ptr<uint8_t[]> buf8(new uint8_t[1]);
    const uint8_t src8[] = "a";
    reql_string_init(var8.get(), buf8.get(), 1);
    reql_string_append(var8.get(), src8, 1);

    reql_object_add(var4.get(), var7.get(), var8.get());

    reql_array_append(var0.get(), var4.get());

    ReQL_Obj_c var9;
    std::unique_ptr<ReQL_Pair_t[]> pair9(new ReQL_Pair_t[2]);
    reql_object_init(var9.get(), pair9.get(), 2);

    ReQL_Obj_c var10;
    std::unique_ptr<uint8_t[]> buf10(new uint8_t[1]);
    const uint8_t src10[] = "a";
    reql_string_init(var10.get(), buf10.get(), 1);
    reql_string_append(var10.get(), src10, 1);

    ReQL_Obj_c var11;
    reql_number_init(var11.get(), 2);

    reql_object_add(var9.get(), var10.get(), var11.get());

    ReQL_Obj_c var12;
    std::unique_ptr<uint8_t[]> buf12(new uint8_t[1]);
    const uint8_t src12[] = "b";
    reql_string_init(var12.get(), buf12.get(), 1);
    reql_string_append(var12.get(), src12, 1);

    ReQL_Obj_c var13;
    std::unique_ptr<uint8_t[]> buf13(new uint8_t[1]);
    const uint8_t src13[] = "b";
    reql_string_init(var13.get(), buf13.get(), 1);
    reql_string_append(var13.get(), src13, 1);

    reql_object_add(var9.get(), var12.get(), var13.get());

    reql_array_append(var0.get(), var9.get());

    ReQL_Obj_c var14;
    std::unique_ptr<ReQL_Pair_t[]> pair14(new ReQL_Pair_t[2]);
    reql_object_init(var14.get(), pair14.get(), 2);

    ReQL_Obj_c var15;
    std::unique_ptr<uint8_t[]> buf15(new uint8_t[1]);
    const uint8_t src15[] = "a";
    reql_string_init(var15.get(), buf15.get(), 1);
    reql_string_append(var15.get(), src15, 1);

    ReQL_Obj_c var16;
    reql_number_init(var16.get(), 3);

    reql_object_add(var14.get(), var15.get(), var16.get());

    ReQL_Obj_c var17;
    std::unique_ptr<uint8_t[]> buf17(new uint8_t[1]);
    const uint8_t src17[] = "b";
    reql_string_init(var17.get(), buf17.get(), 1);
    reql_string_append(var17.get(), src17, 1);

    ReQL_Obj_c var18;
    std::unique_ptr<uint8_t[]> buf18(new uint8_t[1]);
    const uint8_t src18[] = "c";
    reql_string_init(var18.get(), buf18.get(), 1);
    reql_string_append(var18.get(), src18, 1);

    reql_object_add(var14.get(), var17.get(), var18.get());

    reql_array_append(var0.get(), var14.get());
  }

  SECTION("test58") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 2);
  }

  SECTION("test59") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test60") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test61") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test62") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test63") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test64") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test65") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test66") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test67") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test68") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test69") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test70") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test71") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test72") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 0);
  }

  SECTION("test73") {
    ReQL_Obj_c var0;
    reql_bool_init(var0.get(), 1);
  }

  SECTION("test74") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[2]);
    reql_array_init(var0.get(), arr0.get(), 2);

    ReQL_Obj_c var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 3);

    reql_array_append(var0.get(), var2.get());
  }

  SECTION("test75") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    ReQL_Obj_c var2;
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "err";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
