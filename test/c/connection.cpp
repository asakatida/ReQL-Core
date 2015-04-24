// Copyright 2015 Adam Grandquist

#include "./test.hpp"

namespace ReQL {
extern "C" {
#include "./c/dev/connection.h"
}
}

#include "./catch.hpp"

#include <string>

using namespace ReQL;

TEST_CASE("connection", "[c][connection]") {
  SECTION("reql_connection_init") {
  }

  SECTION("reql_conn_set_auth") {
  }

  SECTION("reql_conn_auth_key") {
  }

  SECTION("reql_conn_auth_size") {
  }

  SECTION("reql_conn_set_addr") {
  }

  SECTION("reql_conn_addr") {
  }

  SECTION("reql_conn_set_port") {
  }

  SECTION("reql_conn_set_timeout") {
  }

  SECTION("reql_connect") {
  }

  SECTION("reql_close_conn") {
  }

  SECTION("reql_ensure_conn_close") {
  }

  SECTION("reql_conn_open") {
  }

  SECTION("reql_run") {
  }
}
