#include "ReQL-test.hpp"

#include "catch.h"

#include <limits>

using namespace ReQL;

TEST_CASE("Connection", "[c++][connect]") {
  Connection conn = connect();

  REQUIRE(conn.isOpen());
}

TEST_CASE("decode errors", "[c][decode]") {
  SECTION("empty string") {
    const uint32_t size = 1;
    uint8_t src[size] = "";

    CHECK(reql_decode(src, size) == NULL);
  }

  SECTION("unterminated null") {
    const uint32_t size = 4;
    uint8_t src[size] = "nul";

    CHECK(reql_decode(src, size) == NULL);
  }

  SECTION("unterminated object") {
    const uint32_t size = 2;
    uint8_t src[size] = "{";

    CHECK(reql_decode(src, size) == NULL);
  }

  SECTION("unterminated array") {
    const uint32_t size = 12;
    uint8_t src[size] = "[{}, [], 10";

    CHECK(reql_decode(src, size) == NULL);
  }
}

TEST_CASE("decode values", "[c][decode]") {
  SECTION("null") {
    const uint32_t size = 6;
    uint8_t src[size] = " null";

    ReQL_Obj_t *obj = reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(reql_datum_type(obj) == REQL_R_NULL);

    reql_json_destroy(obj);
  }

  SECTION("true") {
    const uint32_t size = 6;
    uint8_t src[size] = "true ";

    ReQL_Obj_t *obj = reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(reql_datum_type(obj) == REQL_R_BOOL);

    reql_json_destroy(obj);
  }

  SECTION("false") {
    const uint32_t size = 6;
    uint8_t src[size] = "false";

    ReQL_Obj_t *obj = reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(reql_datum_type(obj) == REQL_R_BOOL);

    reql_json_destroy(obj);
  }

  SECTION("number") {
    const uint32_t size = 6;
    uint8_t src[size] = "12345";

    ReQL_Obj_t *obj = reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(reql_datum_type(obj) == REQL_R_NUM);
    REQUIRE(reql_to_number(obj) == 12345);

    reql_json_destroy(obj);
  }

  SECTION("string") {
    const uint32_t size = 6;
    uint8_t src[size] = "\"hi!\"";

    ReQL_Obj_t *obj = reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(reql_datum_type(obj) == REQL_R_STR);
    REQUIRE(3 == reql_string_size(obj));

    std::string orig("hi!");

    REQUIRE(orig.compare(0, 3, (char *)reql_string_buf(obj), reql_string_size(obj)) == 0);

    reql_json_destroy(obj);
  }

  SECTION("array") {
    const uint32_t size = 7;
    uint8_t src[size] = "[true]";

    ReQL_Obj_t *obj = reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(reql_datum_type(obj) == REQL_R_ARRAY);

    ReQL_Obj_t *val = reql_array_last(obj);

    REQUIRE(val != NULL);
    REQUIRE(reql_datum_type(val) == REQL_R_BOOL);

    reql_json_destroy(obj);
  }

  SECTION("object") {
    const uint32_t size = 10;
    uint8_t src[size] = "{\"key\":0}";

    ReQL_Obj_t *obj = reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(reql_datum_type(obj) == REQL_R_OBJECT);

    const uint32_t key_size = 3;
    uint8_t key_buf[4];

    ReQL_Obj_t key;
    reql_string_init(&key, key_buf, key_size);
    reql_string_append(&key, (uint8_t *)"key", key_size);

    REQUIRE(reql_object_get(obj, &key) != NULL);
    REQUIRE(reql_datum_type(reql_object_get(obj, &key)) == REQL_R_NUM);

    reql_json_destroy(obj);
  }
}

TEST_CASE("decode term", "[c][decode]") {
  const uint32_t size = 95;
  uint8_t src[size] = "[1, [[15, [[30], [17], [12, [13.7, 15.4, 16.8], {}]], {\"key\": \"value\", \"other\":  false}]], {}]";

  ReQL_Obj_t *obj = reql_decode(src, size);

  REQUIRE(obj != NULL);

  reql_json_destroy(obj);
}

TEST_CASE("encode values", "[c][encode]") {
  ReQL_Obj_t val;

  SECTION("null") {
    reql_null_init(&val);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 4);
  }

  SECTION("true") {
    reql_bool_init(&val, 1);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 4);
  }

  SECTION("false") {
    reql_bool_init(&val, 0);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 5);
  }

  SECTION("number") {
    reql_number_init(&val, 1.125);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 5);

    std::string comp("1.125", 0, str->size);

    INFO(std::string((char *)str->str));

    REQUIRE(comp.compare(0, str->size, (char *)str->str) == 0);
  }

  SECTION("string") {
    const uint32_t size = 11;

    uint8_t *buf = new uint8_t[size];
    const uint8_t hello[] = "Hello World";

    reql_string_init(&val, buf, size);
    reql_string_append(&val, hello, size);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == size + 2);

    delete [] buf;
  }

  SECTION("array") {
    reql_array_init(&val, NULL, 0);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 2);
  }

  SECTION("object") {
    reql_object_init(&val, NULL, 0);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 2);
  }
}

TEST_CASE("Expr array", "[c][expr][array]") {
  ReQL_Obj_t ary;

  const uint32_t size = 5;

  ReQL_Obj_t *arr[size];

  reql_array_init(&ary, arr, size);

  CHECK(reql_datum_type(&ary) == REQL_R_ARRAY);

  CHECK(reql_array_size(&ary) == 0);

  SECTION("over fill array") {
    uint32_t i;

    for (i=0; i<size; ++i) {
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
    CHECK(reql_to_number(res) == num);
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

    CHECK(num == reql_to_number(&val));
  }

  SECTION("number edges") {
    const double num = std::numeric_limits<std::double_t>::max();

    reql_number_init(&val, num);

    CHECK(num == reql_to_number(&val));
  }

  SECTION("string") {
    const uint32_t size = 12;

    uint8_t *buf = new uint8_t[size];
    const uint8_t hello[] = "Hello World";

    std::string orig = std::string((char *)hello, size);

    reql_string_init(&val, buf, size);
    reql_string_append(&val, hello, size);

    CHECK(reql_datum_type(&val) == REQL_R_STR);

    CHECK(orig.compare(0, size, (char *)reql_string_buf(&val), size) == 0);
    CHECK(size == reql_string_size(&val));

    delete [] buf;
  }
}
