// Copyright 2015 Adam Grandquist

#include "./test.hpp"

using namespace ReQL;
using namespace _C;

TEST_CASE("cpp connection", "[c++][connect]") {
  Connection conn;

  REQUIRE(conn.isOpen());

  const Types::array args({Query(std::string("libReQL"))});

  Cursor cur = db_create(args).run(conn);

  REQUIRE(cur.isOpen());

  Query res = cur.next();

  REQUIRE(res._type() == REQL_R_OBJECT);

  cur = db_drop(args).run(conn);
  res = cur.next();

  REQUIRE(res._type() == REQL_R_OBJECT);

  conn.close();

  REQUIRE(!conn.isOpen());
}
