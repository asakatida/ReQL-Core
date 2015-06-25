// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <string>

static void
reql_test_cur_end_cb(void *data) {
  int *num = static_cast<int*>(data);
  *num = 0;
}

static void
reql_test_cur_error_cb(ReQL_Obj_t *res, void *data) {
  (void)res;
  int *num = static_cast<int*>(data);
  *num = 0;
}

TEST_CASE("reql cursor", "[reql][cursor]") {
  std::unique_ptr<ReQL_Conn_t> conn(new ReQL_Conn_t);

  reql_conn_init(conn.get());

  REQUIRE(reql_conn_open(conn.get()) == 0);

  ReQL_Byte buffer[100];

  REQUIRE(reql_conn_connect(conn.get(), buffer, 100) == 0);

  REQUIRE(reql_conn_open(conn.get()) != 0);

  std::unique_ptr<ReQL_Cur_t> c(new ReQL_Cur_t);

  reql_run(c.get(), nullptr, conn.get(), nullptr);

  REQUIRE(reql_cur_open(c.get()) != 0);

  SECTION("reql_cur_set_end_cb") {
    int data = 1;
    reql_cur_set_end_cb(c.get(), reql_test_cur_end_cb, &data);
    reql_cur_drain(c.get());
    REQUIRE(data == 0);
  }

  SECTION("reql_cur_set_error_cb") {
    int data = 1;
    reql_cur_set_error_cb(c.get(), reql_test_cur_error_cb, &data);
    reql_cur_drain(c.get());
    REQUIRE(data == 1);
  }

  SECTION("reql_cur_destroy") {
    reql_cur_destroy(c.get());

    REQUIRE(reql_cur_open(c.get()) == 0);
  }

  SECTION("reql_cur_next") {
  }

  SECTION("reql_cur_each") {
  }
  
  SECTION("reql_cur_to_array") {
  }
  
  SECTION("reql_cur_close") {
    reql_cur_close(c.get());

    REQUIRE(reql_cur_open(c.get()) == 0);
  }

  reql_cur_close(c.get());

  REQUIRE(reql_cur_open(c.get()) == 0);

  reql_cur_destroy(c.get());

  REQUIRE(reql_cur_open(c.get()) == 0);

  reql_conn_close(conn.get());

  REQUIRE(reql_conn_open(conn.get()) == 0);

  reql_conn_destroy(conn.get());

  REQUIRE(reql_conn_open(conn.get()) == 0);
}
