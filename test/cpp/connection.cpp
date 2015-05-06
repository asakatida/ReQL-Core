// Copyright 2015 Adam Grandquist

#include "./test.hpp"

using namespace ReQL;

TEST_CASE("cpp connection", "[c++][connect]") {
  Connection conn;

  REQUIRE(conn.isOpen());

  const std::vector<Query> args({Query(std::string("libReQL"))});

  Cursor cur = db_create(args).run(conn);

  REQUIRE(cur.isOpen());

  Result res = cur.next();

  CHECK(res.type() == REQL_R_OBJECT);

  cur = db_drop(args).run(conn);
  res = cur.next();

  CHECK(res.type() == REQL_R_OBJECT);

  conn.close();

  REQUIRE(!conn.isOpen());
}
