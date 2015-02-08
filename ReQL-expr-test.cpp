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

    CHECK(_reql_decode(src, size) == NULL);
  }

  SECTION("unterminated null") {
    const uint32_t size = 4;
    uint8_t src[size] = "nul";

    CHECK(_reql_decode(src, size) == NULL);
  }

  SECTION("unterminated object") {
    const uint32_t size = 2;
    uint8_t src[size] = "{";

    CHECK(_reql_decode(src, size) == NULL);
  }

  SECTION("unterminated array") {
    const uint32_t size = 12;
    uint8_t src[size] = "[{}, [], 10";

    CHECK(_reql_decode(src, size) == NULL);
  }
}

TEST_CASE("decode values", "[c][decode]") {
  SECTION("null") {
    const uint32_t size = 6;
    uint8_t src[size] = " null";

    _ReQL_Obj_t *obj = _reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(_reql_datum_type(obj) == _REQL_R_NULL);

    _reql_json_destroy(obj);
  }

  SECTION("true") {
    const uint32_t size = 6;
    uint8_t src[size] = "true ";

    _ReQL_Obj_t *obj = _reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(_reql_datum_type(obj) == _REQL_R_BOOL);

    _reql_json_destroy(obj);
  }

  SECTION("false") {
    const uint32_t size = 6;
    uint8_t src[size] = "false";

    _ReQL_Obj_t *obj = _reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(_reql_datum_type(obj) == _REQL_R_BOOL);

    _reql_json_destroy(obj);
  }

  SECTION("number") {
    const uint32_t size = 6;
    uint8_t src[size] = "12345";

    _ReQL_Obj_t *obj = _reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(_reql_datum_type(obj) == _REQL_R_NUM);
    REQUIRE(_reql_to_number(obj) == 12345);

    _reql_json_destroy(obj);
  }

  SECTION("string") {
    const uint32_t size = 6;
    uint8_t src[size] = "\"hi!\"";

    _ReQL_Obj_t *obj = _reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(_reql_datum_type(obj) == _REQL_R_STR);
    REQUIRE(3 == _reql_string_size(obj));

    std::string orig("hi!");

    REQUIRE(orig.compare(0, 3, (char *)_reql_string_buf(obj), _reql_string_size(obj)) == 0);

    _reql_json_destroy(obj);
  }

  SECTION("array") {
    const uint32_t size = 7;
    uint8_t src[size] = "[true]";

    _ReQL_Obj_t *obj = _reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(_reql_datum_type(obj) == _REQL_R_ARRAY);

    _ReQL_Obj_t *val = _reql_array_last(obj);

    REQUIRE(val != NULL);
    REQUIRE(_reql_datum_type(val) == _REQL_R_BOOL);

    _reql_json_destroy(obj);
  }

  SECTION("object") {
    const uint32_t size = 10;
    uint8_t src[size] = "{\"key\":0}";

    _ReQL_Obj_t *obj = _reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(_reql_datum_type(obj) == _REQL_R_OBJECT);

    const uint32_t key_size = 3;
    uint8_t key_buf[4];

    _ReQL_Obj_t key;
    _reql_string_init(&key, key_buf, key_size);
    _reql_string_append(&key, (uint8_t *)"key", key_size);

    REQUIRE(_reql_object_get(obj, &key) != NULL);
    REQUIRE(_reql_datum_type(_reql_object_get(obj, &key)) == _REQL_R_NUM);

    _reql_json_destroy(obj);
  }
}

TEST_CASE("decode term", "[c][decode]") {
  const uint32_t size = 95;
  uint8_t src[size] = "[1, [[15, [[30], [17], [12, [13.7, 15.4, 16.8], {}]], {\"key\": \"value\", \"other\":  false}]], {}]";

  _ReQL_Obj_t *obj = _reql_decode(src, size);

  REQUIRE(obj != NULL);

  _reql_json_destroy(obj);
}

TEST_CASE("encode values", "[c][encode]") {
  _ReQL_Obj_t val;

  SECTION("null") {
    _reql_null_init(&val);

    _ReQL_String_t *str = _reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 4);
  }

  SECTION("true") {
    _reql_bool_init(&val, 1);

    _ReQL_String_t *str = _reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 4);
  }

  SECTION("false") {
    _reql_bool_init(&val, 0);

    _ReQL_String_t *str = _reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 5);
  }

  SECTION("number") {
    _reql_number_init(&val, 1.125);

    _ReQL_String_t *str = _reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 5);

    std::string comp("1.125");

    INFO(std::string((char *)str->str));

    REQUIRE(comp.compare(0, 5, (char *)str->str) == 0);
  }

  SECTION("string") {
    const uint32_t size = 11;

    uint8_t *buf = new uint8_t[size];
    const uint8_t hello[] = "Hello World";

    _reql_string_init(&val, buf, size);
    _reql_string_append(&val, hello, size);

    _ReQL_String_t *str = _reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == size + 2);

    delete [] buf;
  }

  SECTION("array") {
    _reql_array_init(&val, NULL, 0);

    _ReQL_String_t *str = _reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 2);
  }

  SECTION("object") {
    _reql_object_init(&val, NULL, 0);

    _ReQL_String_t *str = _reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 2);
  }
}

TEST_CASE("Expr array", "[c][expr][array]") {
  _ReQL_Obj_t ary;

  const uint32_t size = 5;

  _ReQL_Obj_t *arr[size];

  _reql_array_init(&ary, arr, size);

  CHECK(_reql_datum_type(&ary) == _REQL_R_ARRAY);

  CHECK(_reql_array_size(&ary) == 0);

  SECTION("over fill array") {
    uint32_t i;

    for (i=0; i<size; ++i) {
      CHECK(_reql_array_append(&ary, &ary) == 0);
    }

    CHECK(_reql_array_append(&ary, &ary) != 0);
  }

  SECTION("grow and shrink") {
    _reql_array_append(&ary, &ary);

    CHECK(_reql_array_pop(&ary) != NULL);
    CHECK(_reql_array_last(&ary) == NULL);
    CHECK(_reql_array_pop(&ary) == NULL);
  }

  SECTION("insert after end") {
    CHECK(_reql_array_insert(&ary, &ary, size * 2) != 0);
  }
}

TEST_CASE("Expr object", "[c][expr][object]") {
  _ReQL_Obj_t obj, key, val;

  _ReQL_Pair_t pair[1];

  _reql_object_init(&obj, pair, 1);

  CHECK(_reql_datum_type(&obj) == _REQL_R_OBJECT);

  const uint32_t size = 4;

  uint8_t *buf = new uint8_t[size];
  const uint8_t string[] = "key";

  _reql_string_init(&key, buf, size);
  _reql_string_append(&key, string, size);

  _reql_null_init(&val);

  CHECK(_reql_object_add(&obj, &key, &val) == 0);

  SECTION("verify insert") {
    CHECK(_reql_object_get(&obj, &key) != NULL);

    _ReQL_Obj_t *res = _reql_object_get(&obj, &key);

    CHECK(_reql_datum_type(res) == _REQL_R_NULL);
  }

  SECTION("reuse key") {
    _ReQL_Obj_t new_val;

    const double num = 3.14;

    _reql_number_init(&new_val, num);

    CHECK(_reql_object_add(&obj, &key, &new_val) == 0);
    CHECK(_reql_object_get(&obj, &key) != NULL);

    _ReQL_Obj_t *res = _reql_object_get(&obj, &key);

    CHECK(_reql_datum_type(res) == _REQL_R_NUM);
    CHECK(_reql_to_number(res) == num);
  }

  SECTION("duplicate key") {
    _ReQL_Obj_t new_key, new_val;

    const double num = 3.14;

    uint8_t *new_buf = new uint8_t[size];
    const uint8_t new_string[] = "key";

    _reql_string_init(&new_key, new_buf, size);
    _reql_string_append(&new_key, new_string, size);

    _reql_number_init(&new_val, num);

    CHECK(_reql_object_add(&obj, &new_key, &new_val) == 0);
    CHECK(_reql_object_get(&obj, &new_key) != NULL);

    _ReQL_Obj_t *res = _reql_object_get(&obj, &new_key);

    CHECK(_reql_datum_type(res) == _REQL_R_NUM);

    delete [] new_buf;
  }

  SECTION("out of space") {
    _ReQL_Obj_t new_key, new_val;

    const double num = 3.14;

    uint8_t *new_buf = new uint8_t[size];
    const uint8_t new_string[] = "new";

    _reql_string_init(&new_key, new_buf, size);
    _reql_string_append(&new_key, new_string, size);

    _reql_number_init(&new_val, num);

    CHECK(_reql_object_add(&obj, &new_key, &new_val) != 0);
    CHECK(_reql_object_get(&obj, &new_key) == NULL);

    _ReQL_Obj_t *res = _reql_object_get(&obj, &key);

    CHECK(_reql_datum_type(res) == _REQL_R_NULL);

    delete [] new_buf;
  }

  delete [] buf;
}

TEST_CASE("Expr", "[c][expr]") {
  _ReQL_Obj_t val;

  SECTION("bool") {
    _reql_bool_init(&val, 10);

    CHECK(_reql_datum_type(&val) == _REQL_R_BOOL);

    CHECK(_reql_to_bool(&val) == true);

    _reql_bool_init(&val, false);

    CHECK(_reql_to_bool(&val) == false);
  }

  SECTION("null") {
    _reql_null_init(&val);

    CHECK(_reql_datum_type(&val) == _REQL_R_NULL);
  }

  SECTION("number") {
    const double num = 42.0;

    _reql_number_init(&val, num);

    CHECK(_reql_datum_type(&val) == _REQL_R_NUM);

    CHECK(num == _reql_to_number(&val));
  }

  SECTION("number edges") {
    const double num = std::numeric_limits<std::double_t>::max();

    _reql_number_init(&val, num);

    CHECK(num == _reql_to_number(&val));
  }

  SECTION("string") {
    const uint32_t size = 12;

    uint8_t *buf = new uint8_t[size];
    const uint8_t hello[] = "Hello World";

    std::string orig = std::string((char *)hello, size);

    _reql_string_init(&val, buf, size);
    _reql_string_append(&val, hello, size);

    CHECK(_reql_datum_type(&val) == _REQL_R_STR);

    CHECK(orig.compare(0, size, (char *)_reql_string_buf(&val), size) == 0);
    CHECK(size == _reql_string_size(&val));

    delete [] buf;
  }
}
