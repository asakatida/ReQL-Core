// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"
#include "./test.hpp"

TEST_CASE("cpp connection", "[c++][connect]") {
  ReQL::Connection<ReQL::Result> conn;

  REQUIRE(conn.isOpen());

  std::vector<ReQL::Query> args({std::wstring(L"libReQL")});

  consume(ReQL::db_create(args).run(conn));

  consume(ReQL::db_drop(args).run(conn));

  conn.close();

  REQUIRE(!conn.isOpen());
}
