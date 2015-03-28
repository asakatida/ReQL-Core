// Copyright 2015 Adam Grandquist

#include <limits>
#include <string>

#include "./test.hpp"

#include "./catch.hpp"

using namespace ReQL;

TEST_CASE("Expr array", "[c][expr][array]") {
  ReQL_Obj_t ary;

  const uint32_t size = 5;

  ReQL_Obj_t *arr[size];

  reql_array_init(&ary, arr, size);

  CHECK(reql_datum_type(&ary) == REQL_R_ARRAY);

  CHECK(reql_size(&ary) == 0);

  SECTION("over fill array") {
    uint32_t i;

    for (i=0; i < size; ++i) {
      CHECK(reql_array_append(&ary, &ary) == 0);
    }

    CHECK(reql_array_append(&ary, &ary) != 0);
  }

  SECTION("grow and shrink") {
    reql_array_append(&ary, &ary);

    CHECK(reql_array_pop(&ary) != NULL);
    CHECK(reql_array_last(&ary) == NULL);
    CHECK(reql_array_pop(&ary) == NULL);
  }

  SECTION("insert after end") {
    CHECK(reql_array_insert(&ary, &ary, size * 2) != 0);
  }
}

TEST_CASE("Expr object", "[c][expr][object]") {
  ReQL_Obj_t obj, key, val;

  ReQL_Pair_t pair[1];

  reql_object_init(&obj, pair, 1);

  CHECK(reql_datum_type(&obj) == REQL_R_OBJECT);

  const uint32_t size = 4;

  uint8_t *buf = new uint8_t[size];
  const uint8_t string[] = "key";

  reql_string_init(&key, buf, size);
  reql_string_append(&key, string, size);

  reql_null_init(&val);

  CHECK(reql_object_add(&obj, &key, &val) == 0);

  SECTION("verify insert") {
    CHECK(reql_object_get(&obj, &key) != NULL);

    ReQL_Obj_t *res = reql_object_get(&obj, &key);

    CHECK(reql_datum_type(res) == REQL_R_NULL);
  }

  SECTION("reuse key") {
    ReQL_Obj_t new_val;

    const double num = 3.14;

    reql_number_init(&new_val, num);

    CHECK(reql_object_add(&obj, &key, &new_val) == 0);
    CHECK(reql_object_get(&obj, &key) != NULL);

    ReQL_Obj_t *res = reql_object_get(&obj, &key);

    CHECK(reql_datum_type(res) == REQL_R_NUM);
    CHECK(reql_to_number(res) == Approx(num));
  }

  SECTION("duplicate key") {
    ReQL_Obj_t new_key, new_val;

    const double num = 3.14;

    uint8_t *new_buf = new uint8_t[size];
    const uint8_t new_string[] = "key";

    reql_string_init(&new_key, new_buf, size);
    reql_string_append(&new_key, new_string, size);

    reql_number_init(&new_val, num);

    CHECK(reql_object_add(&obj, &new_key, &new_val) == 0);
    CHECK(reql_object_get(&obj, &new_key) != NULL);

    ReQL_Obj_t *res = reql_object_get(&obj, &new_key);

    CHECK(reql_datum_type(res) == REQL_R_NUM);

    delete [] new_buf;
  }

  SECTION("out of space") {
    ReQL_Obj_t new_key, new_val;

    const double num = 3.14;

    uint8_t *new_buf = new uint8_t[size];
    const uint8_t new_string[] = "new";

    reql_string_init(&new_key, new_buf, size);
    reql_string_append(&new_key, new_string, size);

    reql_number_init(&new_val, num);

    CHECK(reql_object_add(&obj, &new_key, &new_val) != 0);
    CHECK(reql_object_get(&obj, &new_key) == NULL);

    ReQL_Obj_t *res = reql_object_get(&obj, &key);

    CHECK(reql_datum_type(res) == REQL_R_NULL);

    delete [] new_buf;
  }

  delete [] buf;
}

TEST_CASE("Expr", "[c][expr]") {
  ReQL_Obj_t val;

  SECTION("bool") {
    reql_bool_init(&val, 10);

    CHECK(reql_datum_type(&val) == REQL_R_BOOL);

    CHECK(reql_to_bool(&val) == true);

    reql_bool_init(&val, false);

    CHECK(reql_to_bool(&val) == false);
  }

  SECTION("null") {
    reql_null_init(&val);

    CHECK(reql_datum_type(&val) == REQL_R_NULL);
  }

  SECTION("number") {
    const double num = 42.0;

    reql_number_init(&val, num);

    CHECK(reql_datum_type(&val) == REQL_R_NUM);

    CHECK(num == Approx(reql_to_number(&val)));
  }

  SECTION("number edges") {
    const double num = std::numeric_limits<std::double_t>::max();

    reql_number_init(&val, num);

    CHECK(num == Approx(reql_to_number(&val)));
  }

  SECTION("string") {
    const std::uint32_t size = 12;

    std::uint8_t *buf = new std::uint8_t[size];
    const std::uint8_t hello[] = "Hello World";

    std::string orig = std::string(reinterpret_cast<char*>(const_cast<std::uint8_t*>(hello)), size);

    reql_string_init(&val, buf, size);
    reql_string_append(&val, hello, size);

    CHECK(reql_datum_type(&val) == REQL_R_STR);

    CHECK(orig.compare(0, size, reinterpret_cast<char*>(reql_string_buf(&val)), size) == 0);
    CHECK(size == reql_size(&val));

    delete [] buf;
  }
}
