// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <memory>

TEST_CASE("c Regression test for issue 294", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[12]);
    const uint8_t src1[] = "reql_ast_obj";
    reql_string_init(var1.get(), buf1.get(), 12);
    reql_string_append(var1.get(), src1, 12);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "reql_ast_obj";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[11]);
    const uint8_t src4[] = "TableListTL";
    reql_string_init(var4.get(), buf4.get(), 11);
    reql_string_append(var4.get(), src4, 11);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[12]);
    const uint8_t src1[] = "reql_ast_obj";
    reql_string_init(var1.get(), buf1.get(), 12);
    reql_string_append(var1.get(), src1, 12);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "reql_ast_obj";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[13]);
    const uint8_t src4[] = "TableCreateTL";
    reql_string_init(var4.get(), buf4.get(), 13);
    reql_string_append(var4.get(), src4, 13);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[12]);
    const uint8_t src1[] = "reql_ast_obj";
    reql_string_init(var1.get(), buf1.get(), 12);
    reql_string_append(var1.get(), src1, 12);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "reql_ast_obj";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[11]);
    const uint8_t src4[] = "TableDropTL";
    reql_string_init(var4.get(), buf4.get(), 11);
    reql_string_append(var4.get(), src4, 11);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[12]);
    const uint8_t src1[] = "reql_ast_obj";
    reql_string_init(var1.get(), buf1.get(), 12);
    reql_string_append(var1.get(), src1, 12);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "reql_ast_obj";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[9]);
    const uint8_t src4[] = "TableList";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[12]);
    const uint8_t src1[] = "reql_ast_obj";
    reql_string_init(var1.get(), buf1.get(), 12);
    reql_string_append(var1.get(), src1, 12);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "reql_ast_obj";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[11]);
    const uint8_t src4[] = "TableCreate";
    reql_string_init(var4.get(), buf4.get(), 11);
    reql_string_append(var4.get(), src4, 11);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var1(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[12]);
    const uint8_t src1[] = "reql_ast_obj";
    reql_string_init(var1.get(), buf1.get(), 12);
    reql_string_append(var1.get(), src1, 12);

    std::unique_ptr<ReQL_Obj_t> var2(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Pair_t[]> pair2(new ReQL_Pair_t[1]);
    reql_object_init(var2.get(), pair2.get(), 1);

    std::unique_ptr<ReQL_Obj_t> var3(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf3(new uint8_t[12]);
    const uint8_t src3[] = "reql_ast_obj";
    reql_string_init(var3.get(), buf3.get(), 12);
    reql_string_append(var3.get(), src3, 12);

    std::unique_ptr<ReQL_Obj_t> var4(new ReQL_Obj_t);
    std::unique_ptr<uint8_t[]> buf4(new uint8_t[9]);
    const uint8_t src4[] = "TableDrop";
    reql_string_init(var4.get(), buf4.get(), 9);
    reql_string_append(var4.get(), src4, 9);

    reql_object_add(var2.get(), var3.get(), var4.get());

    reql_object_add(var0.get(), var1.get(), var2.get());
  }
}
