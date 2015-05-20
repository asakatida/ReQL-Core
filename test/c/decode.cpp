// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"

#include "./ReQL.h"
#include "./c/dev/decode.h"

#include <string>

using namespace ReQL;

TEST_CASE("decode errors", "[c][decode]") {
  SECTION("empty string") {
    const uint32_t size = 1;
    uint8_t src[size] = "";

    REQUIRE(reql_decode(src, size) == NULL);
  }

  SECTION("unterminated null") {
    const uint32_t size = 4;
    uint8_t src[size] = "nul";

    REQUIRE(reql_decode(src, size) == NULL);
  }

  SECTION("unterminated object") {
    const uint32_t size = 2;
    uint8_t src[size] = "{";

    REQUIRE(reql_decode(src, size) == NULL);
  }

  SECTION("unterminated array") {
    const uint32_t size = 12;
    uint8_t src[size] = "[{}, [], 10";

    REQUIRE(reql_decode(src, size) == NULL);
  }
}

TEST_CASE("decode values", "[c][decode]") {
  SECTION("null") {
    const uint32_t size = 6;
    uint8_t src[size] = " null";

    ReQL_Res_c obj(reql_decode(src, size));

    REQUIRE(reql_datum_type(obj.p_ptr) == REQL_R_NULL);
  }

  SECTION("true") {
    const uint32_t size = 6;
    uint8_t src[size] = "true ";

    ReQL_Res_c obj(reql_decode(src, size));

    REQUIRE(reql_datum_type(obj.p_ptr) == REQL_R_BOOL);
  }

  SECTION("false") {
    const uint32_t size = 6;
    uint8_t src[size] = "false";

    ReQL_Res_c obj(reql_decode(src, size));

    REQUIRE(reql_datum_type(obj.p_ptr) == REQL_R_BOOL);
  }

  SECTION("number") {
    const uint32_t size = 6;
    uint8_t src[size] = "12345";

    ReQL_Res_c obj(reql_decode(src, size));

    REQUIRE(reql_datum_type(obj.p_ptr) == REQL_R_NUM);
    REQUIRE(reql_to_number(obj.p_ptr) == Approx(12345));
  }

  SECTION("string") {
    const uint32_t size = 6;
    uint8_t src[size] = "\"hi!\"";

    ReQL_Res_c obj(reql_decode(src, size));

    REQUIRE(reql_datum_type(obj.p_ptr) == REQL_R_STR);
    REQUIRE(3 == reql_size(obj.p_ptr));

    std::string orig("hi!");

    REQUIRE(orig.compare(0, 3, reinterpret_cast<char*>(reql_string_buf(obj.p_ptr)), reql_size(obj.p_ptr)) == 0);
  }

  SECTION("array") {
    const uint32_t size = 7;
    uint8_t src[size] = "[true]";

    ReQL_Res_c obj(reql_decode(src, size));

    REQUIRE(reql_datum_type(obj.p_ptr) == REQL_R_ARRAY);

    ReQL_Obj_t *val = reql_array_last(obj.p_ptr);

    REQUIRE(val != NULL);
    REQUIRE(reql_datum_type(val) == REQL_R_BOOL);
  }

  SECTION("object") {
    const uint32_t size = 10;
    uint8_t src[size] = "{\"key\":0}";

    ReQL_Res_c obj(reql_decode(src, size));

    REQUIRE(reql_datum_type(obj.p_ptr) == REQL_R_OBJECT);

    const uint32_t key_size = 3;
    uint8_t key_buf[4];

    ReQL_Obj_c key;
    reql_string_init(key.get(), key_buf, key_size);
    reql_string_append(key.get(), reinterpret_cast<std::uint8_t*>(const_cast<char*>("key")), key_size);

    REQUIRE(reql_object_get(obj.p_ptr, key.get()) != NULL);
    REQUIRE(reql_datum_type(reql_object_get(obj.p_ptr, key.get())) == REQL_R_NUM);
  }
}

TEST_CASE("decode term", "[c][decode]") {
  const uint32_t size = 95;
  uint8_t src[size] = "[1, [[15, [[30], [17], [12, [13.7, 15.4, 16.8], {}]], {\"key\": \"value\", \"other\":  false}]], {}]";

  ReQL_Res_c obj(reql_decode(src, size));
}
