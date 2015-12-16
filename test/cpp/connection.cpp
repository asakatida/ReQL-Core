// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.hpp"

#include <vector>

using namespace ReQL;

TEST_CASE("cpp connection", "[c++][connect]") {
  Connection conn;

  REQUIRE(conn.isOpen());

  std::vector<Query> args({std::wstring(L"libReQL")});

  Cursor cur = db_create(args).run(conn);

  std::vector<Result> results1(cur.begin(), cur.end());

  cur = db_drop(args).run(conn);

  std::vector<Result> results2(cur.begin(), cur.end());

  conn.close();

  REQUIRE(!conn.isOpen());
}
