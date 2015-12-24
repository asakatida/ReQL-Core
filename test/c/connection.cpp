// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.h"

TEST_CASE("c connection", "[c][connect]") {
  ReQL_Connection_t *conn = reql_connect(0, nullptr, nullptr, nullptr, 0);

  REQUIRE(conn != nullptr);
/*
  ReQL_t *db_name = reql_string("libReQLc", 8);

  REQUIRE(db_name != nullptr);

  ReQL_t **args = {&db_name};
  ReQL_t *query = reql_db_create(args);

  REQUIRE(query != nullptr);

  ReQL_Cursor_t *cur = reql_run(query, nullptr, conn);

  REQUIRE(cur != nullptr);

  reql_cursor_each_async(cur, cursor_each_handler, nullptr);
  reql_cursor_drain(cur);

  reql_cursor_close(cur);*/
  reql_connection_close(conn);
}
