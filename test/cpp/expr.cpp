// Copyright 2015 Adam Grandquist

#include <limits>
#include <string>

#include "./test.hpp"

#include "./catch.hpp"

using namespace ReQL;

TEST_CASE("Connection", "[c++][connect]") {
  Connection conn;

  REQUIRE(conn.isOpen());

  const std::vector<Query> args({Query(std::string("libReQL"))});

  Cursor cur = db_create(args).run(conn);

  REQUIRE(cur.isOpen());

  Result res = cur.next();

  REQUIRE(res.type() == REQL_R_OBJECT);

  cur = db_drop(args).run(conn);
  res = cur.next();

  REQUIRE(res.type() == REQL_R_OBJECT);
}