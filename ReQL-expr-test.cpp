#include "ReQL-test.hpp"

#include "catch.h"

#include <limits>

using namespace ReQL;

TEST_CASE("Connection", "[c++][connect]") {
  Connection conn = connect();

  REQUIRE(conn.isOpen());
}

TEST_CASE("Expr", "[c][expr]") {
  SECTION("bool") {
    _ReQL_Op_t boolean;

    _reql_bool_init(&boolean, 10);

    CHECK(_reql_to_bool(&boolean) == true);

    _reql_bool_init(&boolean, false);

    CHECK(_reql_to_bool(&boolean) == false);
  }
  SECTION("null") {
    _ReQL_Op_t null;

    _reql_null_init(&null);

    CHECK(_reql_datum_type(&null) == _REQL_R_NULL);
  }
  SECTION("number") {
    _ReQL_Op_t num;

    const double val = 42.0;

    _reql_number_init(&num, val);

    CHECK(val == _reql_to_number(&num));
  }
  SECTION("number edges") {
    _ReQL_Op_t num;

    const double val = std::numeric_limits<std::double_t>::max();

    _reql_number_init(&num, val);

    CHECK(val == _reql_to_number(&num));
  }
  SECTION("string") {
    _ReQL_Op_t string;

    const uint32_t size = 12;

    uint8_t buf[size] = "Hello World";

    std::string orig = std::string((char *)buf, size);

    _reql_string_init(&string, buf, size, size);

    CHECK(orig.compare(0, size, (char *)_reql_string_buf(&string), size) == 0);
    CHECK(size == _reql_string_size(&string));
  }
}
