// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./reql/core.h"

#include <string>

TEST_CASE("c connection", "[c][connection]") {
  std::unique_ptr<ReQL_Conn_t> c(new ReQL_Conn_t);

  reql_conn_init(c.get());

  REQUIRE(reql_conn_open(c.get()) == 0);

  SECTION("reql_conn_init") {
    REQUIRE(reql_conn_addr(c.get()) == nullptr);
    REQUIRE(reql_conn_auth_key(c.get()) == nullptr);
    REQUIRE(reql_conn_auth_size(c.get()) == 0);
    REQUIRE(std::strncmp(reql_conn_port(c.get()), "28015", 5) == 0);
    REQUIRE(reql_conn_timeout(c.get()) == uint64_t(20));
  }

  SECTION("reql_conn_set_auth") {
    char key[] = "test";

    reql_conn_set_auth(c.get(), 4, key);

    REQUIRE(reql_conn_auth_key(c.get()) == key);
    REQUIRE(reql_conn_auth_size(c.get()) == 4);
  }

  SECTION("reql_conn_set_addr") {
    char key[] = "test";

    reql_conn_set_addr(c.get(), key);

    REQUIRE(reql_conn_addr(c.get()) == key);
  }

  SECTION("reql_conn_set_port") {
    char key[] = "test";

    reql_conn_set_port(c.get(), key);

    REQUIRE(std::strncmp(reql_conn_port(c.get()), "test", 4) == 0);
  }

  SECTION("reql_conn_set_timeout") {
    reql_conn_set_timeout(c.get(), 15);

    REQUIRE(reql_conn_timeout(c.get()) == uint64_t(15));
  }

  SECTION("reql_connect") {
    std::unique_ptr<std::uint8_t> buf(new std::uint8_t[100]);

    REQUIRE(reql_connect(c.get(), buf.get(), 100) == 0);

    REQUIRE(reql_conn_open(c.get()) != 0);

    std::unique_ptr<ReQL_Obj_t> q(new ReQL_Obj_t);

    reql_number_init(q.get(), 2.72);

    std::unique_ptr<ReQL_Cur_t> cur(new ReQL_Cur_t);

    reql_run(cur.get(), q.get(), c.get(), nullptr);

    REQUIRE(reql_cur_open(cur.get()) != 0);

    ReQL_Obj_t *result = reql_cur_to_array(cur.get());

    REQUIRE(result != nullptr);

    reql_close_cur(cur.get());
  }

  reql_close_conn(c.get());

  REQUIRE(reql_conn_open(c.get()) == 0);

  reql_ensure_conn_close(c.get());

  REQUIRE(reql_conn_open(c.get()) == 0);
}