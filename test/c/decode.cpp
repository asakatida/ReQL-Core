// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.h"
#include "./c/dev/decode.h"

#include <string>

TEST_CASE("decode errors", "[c][decode]") {
  SECTION("empty string") {
    const uint32_t size = 1;
    uint8_t src[size] = "";

    REQUIRE(reql_decode(src, size) == nullptr);
  }

  SECTION("unterminated null") {
    const uint32_t size = 4;
    uint8_t src[size] = "nul";

    REQUIRE(reql_decode(src, size) == nullptr);
  }

  SECTION("unterminated object") {
    const uint32_t size = 2;
    uint8_t src[size] = "{";

    REQUIRE(reql_decode(src, size) == nullptr);
  }

  SECTION("unterminated array") {
    const uint32_t size = 12;
    uint8_t src[size] = "[{}, [], 10";

    REQUIRE(reql_decode(src, size) == nullptr);
  }
}

TEST_CASE("decode values", "[c][decode]") {
  SECTION("null") {
    const uint32_t size = 6;
    uint8_t src[size] = " null";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_NULL);
  }

  SECTION("true") {
    const uint32_t size = 6;
    uint8_t src[size] = "true ";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_BOOL);
  }

  SECTION("false") {
    const uint32_t size = 6;
    uint8_t src[size] = "false";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_BOOL);
  }

  SECTION("number") {
    const uint32_t size = 6;
    uint8_t src[size] = "12345";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_NUM);
    REQUIRE(reql_to_number(obj) == Approx(12345));
  }

  SECTION("string") {
    const uint32_t size = 6;
    uint8_t src[size] = "\"hi!\"";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_STR);
    REQUIRE(3 == reql_size(obj));

    std::string orig("hi!");

    REQUIRE(orig.compare(0, 3, reinterpret_cast<char*>(reql_string_buf(obj)), reql_size(obj)) == 0);
  }

  SECTION("array") {
    const uint32_t size = 7;
    uint8_t src[size] = "[true]";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_ARRAY);

    ReQL_Obj_t *val = reql_array_last(obj);

    REQUIRE(val != nullptr);
    REQUIRE(reql_datum_type(val) == REQL_R_BOOL);
  }

  SECTION("object") {
    const uint32_t size = 10;
    uint8_t src[size] = "{\"key\":0}";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_OBJECT);

    const uint32_t key_size = 3;
    uint8_t key_buf[4];

    std::unique_ptr<ReQL_Obj_t> key;
    reql_string_init(key.get(), key_buf, key_size);
    reql_string_append(key.get(), reinterpret_cast<std::uint8_t*>(const_cast<char*>("key")), key_size);

    REQUIRE(reql_object_get(obj, key.get()) != nullptr);
    REQUIRE(reql_datum_type(reql_object_get(obj, key.get())) == REQL_R_NUM);
  }
}

TEST_CASE("decode term", "[c][decode]") {
  const uint32_t size = 95;
  uint8_t src[size] = "[1, [[15, [[30], [17], [12, [13.7, 15.4, 16.8], {}]], {\"key\": \"value\", \"other\":  false}]], {}]";

  ReQL_Obj_t *obj = reql_decode(src, size);
  REQUIRE(obj != nullptr);
}
