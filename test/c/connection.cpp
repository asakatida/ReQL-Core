// Copyright 2015 Adam Grandquist

#include "./test.hpp"

namespace ReQL {
namespace _C {
extern "C" {
#include "./c/dev/connection.h"
}
}
}  // namespace _C

#include <string>

using namespace ReQL;
using namespace _C;

TEST_CASE("c connection", "[c][connection]") {
  ReQL_Conn_c c;

  SECTION("reql_connection_init") {
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

    REQUIRE(reql_conn_port(c.get()) == key);
  }

  SECTION("reql_conn_set_timeout") {
    reql_conn_set_timeout(c.get(), 15);

    REQUIRE(reql_conn_timeout(c.get()) == uint64_t(15));
  }

  SECTION("reql_connect") {
    std::unique_ptr<std::uint8_t> buf(new std::uint8_t[100]);

    REQUIRE(reql_connect(c.get(), buf.get(), 100) == 0);

    REQUIRE(reql_conn_open(c.get()) != 0);

    ReQL_Obj_c q;

    reql_number_init(q.get(), 2.72);

    ReQL_Cur_c cur;

    reql_run(cur.get(), q.get(), c.get(), nullptr);

    REQUIRE(reql_cur_open(cur.get()) != 0);

    ReQL_Res_c result(reql_cursor_to_array(cur.get()));
  }
}
