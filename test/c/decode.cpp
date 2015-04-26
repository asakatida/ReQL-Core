// Copyright 2015 Adam Grandquist

#include "./test.hpp"

namespace ReQL {
extern "C" {
#include "./c/dev/decode.h"
}
}

#include "./catch.hpp"

#include <string>

using namespace ReQL;

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
    REQUIRE(reql_to_number(obj) == Approx(12345));

    reql_json_destroy(obj);
  }

  SECTION("string") {
    const uint32_t size = 6;
    uint8_t src[size] = "\"hi!\"";

    ReQL_Obj_t *obj = reql_decode(src, size);

    REQUIRE(obj != NULL);
    REQUIRE(reql_datum_type(obj) == REQL_R_STR);
    REQUIRE(3 == reql_size(obj));

    std::string orig("hi!");

    REQUIRE(orig.compare(0, 3, reinterpret_cast<char*>(reql_string_buf(obj)), reql_size(obj)) == 0);

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

    std::unique_ptr<ReQL_Obj_t> key(new ReQL_Obj_t);
    reql_string_init(key.get(), key_buf, key_size);
    reql_string_append(key.get(), reinterpret_cast<std::uint8_t*>(const_cast<char*>("key")), key_size);

    REQUIRE(reql_object_get(obj, key.get()) != NULL);
    REQUIRE(reql_datum_type(reql_object_get(obj, key.get())) == REQL_R_NUM);

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
