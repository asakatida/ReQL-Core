// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"
#include "./test.hpp"

#include <vector>

using namespace ReQL;

TEST_CASE("cpp connection", "[c++][connect]") {
  Connection conn;

  REQUIRE(conn.isOpen());

  std::vector<Query> args({std::wstring(L"libReQL")});

  consume(db_create(args).run(conn));

  consume(db_drop(args).run(conn));

  conn.close();

  REQUIRE(!conn.isOpen());
}
