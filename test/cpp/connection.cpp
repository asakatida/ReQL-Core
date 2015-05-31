// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./ReQL.hpp"

using namespace ReQL;

TEST_CASE("cpp connection", "[c++][connect]") {
  Connection conn;

  REQUIRE(conn.isOpen());

  const Types::array args({Query(std::string("libReQL"))});

  Cursor cur = db_create(args).run(conn);

  REQUIRE(cur.isOpen());

  Query res = cur.next();

  cur = db_drop(args).run(conn);
  res = cur.next();

  conn.close();

  REQUIRE(!conn.isOpen());
}
