// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/decode.h"

#include <string>

TEST_CASE("decode errors", "[reql][decode]") {
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
  ReQL_Obj_t *obj = nullptr;

  SECTION("null") {
    const uint32_t size = 6;
    uint8_t src[size] = " null";

    obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_NULL);
  }

  SECTION("true") {
    const uint32_t size = 6;
    uint8_t src[size] = "true ";

    obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_BOOL);
  }

  SECTION("false") {
    const uint32_t size = 6;
    uint8_t src[size] = "false";

    obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_BOOL);
  }

  SECTION("number") {
    const uint32_t size = 6;
    uint8_t src[size] = "12345";

    obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_NUM);
    REQUIRE(reql_to_number(obj) == Approx(12345));
  }

  SECTION("string") {
    const uint32_t size = 6;
    uint8_t src[size] = "\"hi!\"";

    obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    REQUIRE(reql_datum_type(obj) == REQL_R_STR);
    REQUIRE(3 == reql_size(obj));

    std::string orig("hi!");

    REQUIRE(std::strncmp(reinterpret_cast<char*>(reql_string_buf(obj)), "hi!", reql_size(obj)) == 0);
  }

  SECTION("array") {
    SECTION("one") {
      const uint32_t size = 7;
      uint8_t src[size] = "[true]";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_ARRAY);

      ReQL_Obj_t *val = reql_array_last(obj);

      REQUIRE(val != nullptr);
      REQUIRE(reql_datum_type(val) == REQL_R_BOOL);
    }

    SECTION("two") {
      const uint32_t size = 7;
      uint8_t src[size] = "[[[]]]";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_ARRAY);

      ReQL_Obj_t *val = reql_array_last(obj);

      REQUIRE(val != nullptr);
      REQUIRE(reql_datum_type(val) == REQL_R_ARRAY);

      val = reql_array_last(val);

      REQUIRE(val != nullptr);
      REQUIRE(reql_datum_type(val) == REQL_R_ARRAY);
    }

    SECTION("three") {
      const uint32_t size = 7;
      uint8_t src[size] = "[[{}]]";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_ARRAY);

      ReQL_Obj_t *val = reql_array_last(obj);

      REQUIRE(val != nullptr);
      REQUIRE(reql_datum_type(val) == REQL_R_ARRAY);

      val = reql_array_last(val);

      REQUIRE(val != nullptr);
      REQUIRE(reql_datum_type(val) == REQL_R_OBJECT);
    }
  }

  SECTION("object") {
    SECTION("one") {
      const uint32_t size = 10;
      uint8_t src[size] = "{\"key\":0}";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_OBJECT);

      const uint32_t key_size = 3;
      uint8_t key_buf[4];

      std::unique_ptr<ReQL_Obj_t> key(new ReQL_Obj_t);
      reql_string_init(key.get(), key_buf, key_size);
      reql_string_append(key.get(), reinterpret_cast<std::uint8_t*>(const_cast<char*>("key")), key_size);

      REQUIRE(reql_object_get(obj, key.get()) != nullptr);
      REQUIRE(reql_datum_type(reql_object_get(obj, key.get())) == REQL_R_NUM);
    }

    SECTION("two") {
      const uint32_t size = 10;
      uint8_t src[size] = "{\"\":[{}]}";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_OBJECT);

      std::unique_ptr<ReQL_Obj_t> key(new ReQL_Obj_t);
      reql_string_init(key.get(), nullptr, 0);

      ReQL_Obj_t *val = reql_object_get(obj, key.get());

      REQUIRE(val != nullptr);
      REQUIRE(reql_datum_type(val) == REQL_R_ARRAY);

      val = reql_array_last(val);

      REQUIRE(val != nullptr);
      REQUIRE(reql_datum_type(val) == REQL_R_OBJECT);
    }

    SECTION("three") {
      const uint32_t size = 10;
      uint8_t src[size] = "{\"\":\"\"}";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_OBJECT);
    }

    SECTION("four") {
      const uint32_t size = 13;
      uint8_t src[size] = "{\"\":{\"\":\"\"}}";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_OBJECT);
    }

    SECTION("five") {
      const uint32_t size = 20;
      uint8_t src[size] = "{\"\":[{\"\":{\"\":\"\"}}]}";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_OBJECT);
    }

    SECTION("six") {
      const uint32_t size = 27;
      uint8_t src[size] = "{\"\":[{\"\":[{\"\":{\"\":\"\"}}]}]}";

      obj = reql_decode(src, size);
      REQUIRE(obj != nullptr);

      REQUIRE(reql_datum_type(obj) == REQL_R_OBJECT);
    }
  }

  reql_json_destroy(obj);
}

TEST_CASE("decode term", "[c][decode]") {
  SECTION("term fake") {
    const uint32_t size = 95;
    uint8_t src[size] = "[1, [[15, [[30], [17], [12, [13.7, 15.4, 16.8], {}]], {\"key\": \"value\", \"other\":  false}]], {}]";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    reql_json_destroy(obj);
  }

  SECTION("term one") {
    const uint32_t size = 148;
    uint8_t src[size] = "{\"t\":1,\"r\":[{\"config_changes\":[{\"new_val\":{\"id\":\"32f1b212-1a27-4c62-97e3-5ac85a4786d0\",\"name\":\"libReQL\"},\"old_val\":null}],\"dbs_created\":1}],\"n\":[]}";

    ReQL_Obj_t *obj = reql_decode(src, size);
    REQUIRE(obj != nullptr);

    reql_json_destroy(obj);
  }
}
