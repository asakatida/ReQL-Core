#include "ReQL-test.hpp"

#include "catch.h"

#include <limits>

using namespace ReQL;

TEST_CASE("Connection", "[c++][connect]") {
  Connection conn = connect();

  REQUIRE(conn.isOpen());
}

TEST_CASE("Expr", "[c][expr]") {
  _ReQL_Op_t val;

  SECTION("bool") {
    _reql_bool_init(&val, 10);

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

    CHECK(num == _reql_to_number(&val));
  }

  SECTION("number edges") {
    const double num = std::numeric_limits<std::double_t>::max();

    _reql_number_init(&val, num);

    CHECK(num == _reql_to_number(&val));
  }

  SECTION("string") {
    const uint32_t size = 12;

    uint8_t buf[size] = "Hello World";

    std::string orig = std::string((char *)buf, size);

    _reql_string_init(&val, buf, size, size);

    CHECK(orig.compare(0, size, (char *)_reql_string_buf(&val), size) == 0);
    CHECK(size == _reql_string_size(&val));
  }
}
