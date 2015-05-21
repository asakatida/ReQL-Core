// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c Tests for basic usage of the add operation", "[c][ast]") {

  SECTION("test0") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_number_init(var0.get(), 2);
  }

  SECTION("test1") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_number_init(var0.get(), 0);
  }

  SECTION("test2") {
    std::unique_ptr<ReQL_Obj_t> var0;
    reql_number_init(var0.get(), 10.25);
  }

  SECTION("test3") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[0]);
    const uint8_t src0[] = "";
    reql_string_init(var0.get(), buf0.get(), 0);
    reql_string_append(var0.get(), src0, 0);
  }

  SECTION("test4") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::string buf0(new uint8_t[6]);
    const uint8_t src0[] = "abcdef";
    reql_string_init(var0.get(), buf0.get(), 6);
    reql_string_append(var0.get(), src0, 6);
  }

  SECTION("test5") {
    std::unique_ptr<ReQL_Obj_t> var0;
    _C::CTypes::array arr0(new ReQL_Obj_t*[8]);
    reql_array_init(var0.get(), arr0.get(), 8);

    std::unique_ptr<ReQL_Obj_t> var1;
    reql_number_init(var1.get(), 1);

    reql_array_append(var0.get(), var1.get());

    std::unique_ptr<ReQL_Obj_t> var2;
    reql_number_init(var2.get(), 2);

    reql_array_append(var0.get(), var2.get());

    std::unique_ptr<ReQL_Obj_t> var3;
    reql_number_init(var3.get(), 3);

    reql_array_append(var0.get(), var3.get());

    std::unique_ptr<ReQL_Obj_t> var4;
    reql_number_init(var4.get(), 4);

    reql_array_append(var0.get(), var4.get());

    std::unique_ptr<ReQL_Obj_t> var5;
    reql_number_init(var5.get(), 5);

    reql_array_append(var0.get(), var5.get());

    std::unique_ptr<ReQL_Obj_t> var6;
    reql_number_init(var6.get(), 6);

    reql_array_append(var0.get(), var6.get());

    std::unique_ptr<ReQL_Obj_t> var7;
    reql_number_init(var7.get(), 7);

    reql_array_append(var0.get(), var7.get());

    std::unique_ptr<ReQL_Obj_t> var8;
    reql_number_init(var8.get(), 8);

    reql_array_append(var0.get(), var8.get());
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
}
