// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("c accessing portions 350", "[c][ast]") {

  SECTION("test10") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 1375142400);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 1375142400);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 1375142400);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 2375136000);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test11") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 0);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 0);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 0);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 0);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test12") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    reql_number_init(var1.get(), 4896.681);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 4896.682);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 4897.681);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 11296.681);

    reql_array_append(var0.get(), var4.get());
  }

  SECTION("test13") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr1(new ReQL_Obj_t*[6]);
    reql_array_init(var1.get(), arr1.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2013);

    reql_array_append(var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 7);

    reql_array_append(var1.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    reql_number_init(var4.get(), 30);

    reql_array_append(var1.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 1);

    reql_array_append(var1.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 21);

    reql_array_append(var1.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    reql_number_init(var7.get(), 36.681);

    reql_array_append(var1.get(), var7.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr8(new ReQL_Obj_t*[6]);
    reql_array_init(var8.get(), arr8.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 2013);

    reql_array_append(var8.get(), var9.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    reql_number_init(var10.get(), 7);

    reql_array_append(var8.get(), var10.get());

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 30);

    reql_array_append(var8.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 1);

    reql_array_append(var8.get(), var12.get());

    std::unique_ptr<ReQL_Obj_t> var13(new ReQL_Obj_t);
    reql_number_init(var13.get(), 21);

    reql_array_append(var8.get(), var13.get());

    std::unique_ptr<ReQL_Obj_t> var14(new ReQL_Obj_t);
    reql_number_init(var14.get(), 36.682);

    reql_array_append(var8.get(), var14.get());

    reql_array_append(var0.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var15(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr15(new ReQL_Obj_t*[6]);
    reql_array_init(var15.get(), arr15.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var16(new ReQL_Obj_t);
    reql_number_init(var16.get(), 2013);

    reql_array_append(var15.get(), var16.get());

    std::unique_ptr<ReQL_Obj_t> var17(new ReQL_Obj_t);
    reql_number_init(var17.get(), 7);

    reql_array_append(var15.get(), var17.get());

    std::unique_ptr<ReQL_Obj_t> var18(new ReQL_Obj_t);
    reql_number_init(var18.get(), 30);

    reql_array_append(var15.get(), var18.get());

    std::unique_ptr<ReQL_Obj_t> var19(new ReQL_Obj_t);
    reql_number_init(var19.get(), 1);

    reql_array_append(var15.get(), var19.get());

    std::unique_ptr<ReQL_Obj_t> var20(new ReQL_Obj_t);
    reql_number_init(var20.get(), 21);

    reql_array_append(var15.get(), var20.get());

    std::unique_ptr<ReQL_Obj_t> var21(new ReQL_Obj_t);
    reql_number_init(var21.get(), 37.681);

    reql_array_append(var15.get(), var21.get());

    reql_array_append(var0.get(), var15.get());

    std::unique_ptr<ReQL_Obj_t> var22(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr22(new ReQL_Obj_t*[6]);
    reql_array_init(var22.get(), arr22.get(), 6);

    std::unique_ptr<ReQL_Obj_t> var23(new ReQL_Obj_t);
    reql_number_init(var23.get(), 2045);

    reql_array_append(var22.get(), var23.get());

    std::unique_ptr<ReQL_Obj_t> var24(new ReQL_Obj_t);
    reql_number_init(var24.get(), 4);

    reql_array_append(var22.get(), var24.get());

    std::unique_ptr<ReQL_Obj_t> var25(new ReQL_Obj_t);
    reql_number_init(var25.get(), 7);

    reql_array_append(var22.get(), var25.get());

    std::unique_ptr<ReQL_Obj_t> var26(new ReQL_Obj_t);
    reql_number_init(var26.get(), 3);

    reql_array_append(var22.get(), var26.get());

    std::unique_ptr<ReQL_Obj_t> var27(new ReQL_Obj_t);
    reql_number_init(var27.get(), 8);

    reql_array_append(var22.get(), var27.get());

    std::unique_ptr<ReQL_Obj_t> var28(new ReQL_Obj_t);
    reql_number_init(var28.get(), 16.681);

    reql_array_append(var22.get(), var28.get());

    reql_array_append(var0.get(), var22.get());
  }

  SECTION("test14") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[4]);
    const uint8_t src1[] = "func";
    reql_string_init(var1.get(), buf1.get(), 4);
    reql_string_append(var1.get(), src1, 4);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf2(new uint8_t[3]);
    const uint8_t src2[] = "rts";
    reql_string_init(var2.get(), buf2.get(), 3);
    reql_string_append(var2.get(), src2, 3);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test15") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    reql_number_init(var0.get(), 0);
  }

  SECTION("test16") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr0(new ReQL_Obj_t*[4]);
    reql_array_init(var0.get(), arr0.get(), 4);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr1(new ReQL_Obj_t*[2]);
    reql_array_init(var1.get(), arr1.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    reql_number_init(var2.get(), 2);

    reql_array_append(var1.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    reql_number_init(var3.get(), 211);

    reql_array_append(var1.get(), var3.get());

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr4(new ReQL_Obj_t*[2]);
    reql_array_init(var4.get(), arr4.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var5(new ReQL_Obj_t);
    reql_number_init(var5.get(), 2);

    reql_array_append(var4.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6(new ReQL_Obj_t);
    reql_number_init(var6.get(), 211);

    reql_array_append(var4.get(), var6.get());

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var7(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr7(new ReQL_Obj_t*[2]);
    reql_array_init(var7.get(), arr7.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var8(new ReQL_Obj_t);
    reql_number_init(var8.get(), 2);

    reql_array_append(var7.get(), var8.get());

    std::unique_ptr<ReQL_Obj_t> var9(new ReQL_Obj_t);
    reql_number_init(var9.get(), 211);

    reql_array_append(var7.get(), var9.get());

    reql_array_append(var0.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var10(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Obj_t*[]> arr10(new ReQL_Obj_t*[2]);
    reql_array_init(var10.get(), arr10.get(), 2);

    std::unique_ptr<ReQL_Obj_t> var11(new ReQL_Obj_t);
    reql_number_init(var11.get(), 5);

    reql_array_append(var10.get(), var11.get());

    std::unique_ptr<ReQL_Obj_t> var12(new ReQL_Obj_t);
    reql_number_init(var12.get(), 97);

    reql_array_append(var10.get(), var12.get());

    reql_array_append(var0.get(), var10.get());
  }
}
