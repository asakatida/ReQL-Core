// Copyright 2015 Adam Grandquist

#include "./catch.hpp"

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("c secondary indexes on times", "[c][ast]") {

  SECTION("test8") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 5);
  }

  SECTION("test10") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[295]);
    const uint8_t src0[] = "Duplicate primary key `id`:\n{\n\t\"id\":\t{\n\t\t\"$reql_type$\":\t\"TIME\",\n\t\t\"epoch_time\":\t1375445163.0869998932,\n\t\t\"timezone\":\t\"-07:00\"\n\t}\n}\n{\n\t\"id\":\t{\n\t\t\"$reql_type$\":\t\"TIME\",\n\t\t\"epoch_time\":\t1375445163.0869998932,\n\t\t\"timezone\":\t\"+00:00\"\n\t}\n}";
    reql_string_init(var0.get(), buf0.get(), 295);
    reql_string_append(var0.get(), src0, 295);
  }

  SECTION("test11") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 5);
  }

  SECTION("test12") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test13") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 4);
  }

  SECTION("test14") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 5);
  }

  SECTION("test15") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test16") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 4);
  }

  SECTION("test17") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 5);
  }

  SECTION("test18") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test19") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test20") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 5);
  }

  SECTION("test21") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test22") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 4);
  }

  SECTION("test23") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 5);
  }

  SECTION("test24") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test25") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 4);
  }

  SECTION("test26") {
    ReQL_Obj_c var0;
    std::unique_ptr<ReQL_Pair_t[]> pair0(new ReQL_Pair_t[1]);
    reql_object_init(var0.get(), pair0.get(), 1);

    ReQL_Obj_c var1;
    std::unique_ptr<uint8_t[]> buf1(new uint8_t[7]);
    const uint8_t src1[] = "created";
    reql_string_init(var1.get(), buf1.get(), 7);
    reql_string_append(var1.get(), src1, 7);

    ReQL_Obj_c var2;
    reql_number_init(var2.get(), 1);

    reql_object_add(var0.get(), var1.get(), var2.get());
  }

  SECTION("test27") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test28") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test29") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test30") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test31") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test32") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test33") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test34") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 3);
  }

  SECTION("test37") {
    ReQL_Obj_c var0;
    reql_number_init(var0.get(), 1);
  }

  SECTION("test38") {
    ReQL_Obj_c var0;
    std::unique_ptr<uint8_t[]> buf0(new uint8_t[11]);
    const uint8_t src0[] = "PTYPE<TIME>";
    reql_string_init(var0.get(), buf0.get(), 11);
    reql_string_append(var0.get(), src0, 11);
  }
}
