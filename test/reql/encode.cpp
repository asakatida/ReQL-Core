// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./reql/encode.hpp"

TEST_CASE("encode values", "[reql][encode]") {
  std::unique_ptr<ReQL_Obj_t> val(new ReQL_Obj_t);

  SECTION("null") {
    reql_null_init(val.get());

    auto str = reql_encode(val.get());

    REQUIRE(str.size() == 4);
  }

  SECTION("true") {
    reql_bool_init(val.get(), 1 == 1);

    auto str = reql_encode(val.get());

    REQUIRE(str.size() == 4);
  }

  SECTION("false") {
    reql_bool_init(val.get(), 0 == 1);

    auto str = reql_encode(val.get());

    REQUIRE(str.size() == 5);
  }

  SECTION("number") {
    reql_number_init(val.get(), 1.125);

    auto str = reql_encode(val.get());

    REQUIRE(str.size() == 5);

    std::string comp("1.125", 0, str.size());

    REQUIRE(comp == str);
  }

  SECTION("string") {
    const uint32_t size = 11;

    std::unique_ptr<uint8_t> buf(new uint8_t[size]);

    const uint8_t hello[] = "Hello World";

    reql_string_init(val.get(), buf.get(), hello, size);

    auto str = reql_encode(val.get());

    REQUIRE(str.size() == size + 2);
  }

  SECTION("array") {
    reql_array_init(val.get(), nullptr, 0);

    auto str = reql_encode(val.get());

    REQUIRE(str.size() == 2);
  }

  SECTION("object") {
    reql_object_init(val.get(), nullptr, 0);

    auto str = reql_encode(val.get());

    REQUIRE(str.size() == 2);
  }
}
