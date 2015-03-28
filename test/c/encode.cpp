// Copyright 2015 Adam Grandquist

#include "./test.hpp"

namespace ReQL {
extern "C" {
#include "./c/encode.h"
}
}

#include "./catch.hpp"

#include <limits>
#include <string>

using namespace ReQL;

TEST_CASE("encode values", "[c][encode]") {
  ReQL_Obj_t val;

  SECTION("null") {
    reql_null_init(&val);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 4);

    free(str->str);
    free(str);
  }

  SECTION("true") {
    reql_bool_init(&val, 1);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 4);

    free(str->str);
    free(str);
  }

  SECTION("false") {
    reql_bool_init(&val, 0);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 5);

    free(str->str);
    free(str);
  }

  SECTION("number") {
    reql_number_init(&val, 1.125);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 5);

    std::string comp("1.125", 0, str->size);

    REQUIRE(comp.compare(0, str->size, reinterpret_cast<char*>(str->str)) == 0);

    free(str->str);
    free(str);
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

    free(str->str);
    free(str);
  }

  SECTION("array") {
    reql_array_init(&val, NULL, 0);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 2);

    free(str->str);
    free(str);
  }

  SECTION("object") {
    reql_object_init(&val, NULL, 0);

    ReQL_String_t *str = reql_encode(&val);

    REQUIRE(str != NULL);

    REQUIRE(str->size == 2);

    free(str->str);
    free(str);
  }
}
