#include "ReQL-test.hpp"

#include "catch.h"

using namespace ReQL;

TEST_CASE("Connection", "[c++][connect]") {
  Connection conn = connect();

  REQUIRE(conn.isOpen());
}

TEST_CASE("Expr", "[c][expr]") {
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
