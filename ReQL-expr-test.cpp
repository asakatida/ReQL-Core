#include "ReQL-test.hpp"

#include "catch.h"

using namespace ReQL;

TEST_CASE("Connection", "[c++][connect]") {
  Connection conn = connect();

  REQUIRE(conn.isOpen());
}