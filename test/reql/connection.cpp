// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <string>

TEST_CASE("reql connection", "[reql][connection]") {
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

    REQUIRE(std::strncmp(reql_conn_auth_key(c.get()), "test", 4) == 0);
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
    reql_conn_set_timeout(c.get(), 15, 0);

    REQUIRE(reql_conn_timeout(c.get()) == ReQL_Token(15));
  }

  SECTION("reql_conn_connect") {
    std::unique_ptr<std::uint8_t> buf(new std::uint8_t[100]);

    REQUIRE(reql_conn_connect(c.get(), buf.get(), 100) == 0);

    REQUIRE(reql_conn_open(c.get()) != 0);

    SECTION("reql_run") {
      std::unique_ptr<ReQL_Obj_t> q(new ReQL_Obj_t);

      reql_number_init(q.get(), 2.72);

      std::unique_ptr<ReQL_Cur_t> cur(new ReQL_Cur_t);

      reql_run_query(cur.get(), q.get(), c.get(), nullptr);

      REQUIRE(reql_cur_open(cur.get()) != 0);

      reql_cur_close(cur.get());
    }

    SECTION("reql_no_reply_wait_query") {
      std::unique_ptr<ReQL_Obj_t> db_name(new ReQL_Obj_t);
      ReQL_Byte buf1[7];
      const ReQL_Byte src[] = "no_reply";

      reql_string_init(db_name.get(), buf1, src, 7);

      std::unique_ptr<ReQL_Obj_t> db_args(new ReQL_Obj_t);
      ReQL_Obj_t *arr[1];

      reql_array_init(db_args.get(), arr, 1);
      reql_array_append(db_args.get(), db_name.get());

      std::unique_ptr<ReQL_Obj_t> db(new ReQL_Obj_t);

      reql_ast_db_create(db.get(), db_args.get());

      reql_run_query(nullptr, db.get(), c.get(), nullptr);

      reql_no_reply_wait_query(c.get());

      db_args.get()->owner = nullptr;

      reql_ast_db(db.get(), db_args.get());

      std::unique_ptr<ReQL_Obj_t> table_name(new ReQL_Obj_t);
      ReQL_Byte buf2[7];

      reql_string_init(table_name.get(), buf2, src, 7);

      std::unique_ptr<ReQL_Obj_t> table_args(new ReQL_Obj_t);
      ReQL_Obj_t *arr1[2];

      reql_array_init(table_args.get(), arr1, 2);
      reql_array_append(table_args.get(), db.get());
      reql_array_append(table_args.get(), table_name.get());

      std::unique_ptr<ReQL_Obj_t> table(new ReQL_Obj_t);

      reql_ast_table_create(table.get(), table_args.get(), nullptr);

      reql_run_query(nullptr, table.get(), c.get(), nullptr);

      reql_no_reply_wait_query(c.get());

      table_args.get()->owner = nullptr;

      reql_ast_table(table.get(), table_args.get(), nullptr);

      std::unique_ptr<ReQL_Obj_t> empty(new ReQL_Obj_t);

      reql_object_init(empty.get(), nullptr, 0);

      std::unique_ptr<ReQL_Obj_t> insert_args(new ReQL_Obj_t);
      ReQL_Obj_t *arr2[2];

      reql_array_init(insert_args.get(), arr2, 2);
      reql_array_append(insert_args.get(), table.get());
      reql_array_append(insert_args.get(), empty.get());

      std::unique_ptr<ReQL_Obj_t> insert(new ReQL_Obj_t);

      reql_ast_insert(insert.get(), insert_args.get());

      reql_run_query(nullptr, insert.get(), c.get(), nullptr);

      reql_no_reply_wait_query(c.get());

      std::unique_ptr<ReQL_Cur_t> cur(new ReQL_Cur_t);

      reql_run_query(cur.get(), table.get(), c.get(), nullptr);

      REQUIRE(reql_cur_open(cur.get()) != 0);

      reql_cur_close(cur.get());
    }

    SECTION("reql_stop_query") {
      std::unique_ptr<ReQL_Obj_t> db_name(new ReQL_Obj_t);
      ReQL_Byte buf1[4];
      const ReQL_Byte src[] = "stop";

      reql_string_init(db_name.get(), buf1, src, 4);

      std::unique_ptr<ReQL_Obj_t> db_args(new ReQL_Obj_t);
      ReQL_Obj_t *arr[1];

      reql_array_init(db_args.get(), arr, 1);
      reql_array_append(db_args.get(), db_name.get());

      std::unique_ptr<ReQL_Obj_t> db(new ReQL_Obj_t);

      reql_ast_db_create(db.get(), db_args.get());

      reql_run_query(nullptr, db.get(), c.get(), nullptr);

      reql_no_reply_wait_query(c.get());

      db_args.get()->owner = nullptr;

      reql_ast_db(db.get(), db_args.get());

      std::unique_ptr<ReQL_Obj_t> table_name(new ReQL_Obj_t);
      ReQL_Byte buf2[4];

      reql_string_init(table_name.get(), buf2, src, 4);

      std::unique_ptr<ReQL_Obj_t> table_args(new ReQL_Obj_t);
      ReQL_Obj_t *arr1[2];

      reql_array_init(table_args.get(), arr1, 2);
      reql_array_append(table_args.get(), db.get());
      reql_array_append(table_args.get(), table_name.get());

      std::unique_ptr<ReQL_Obj_t> table(new ReQL_Obj_t);

      reql_ast_table_create(table.get(), table_args.get(), nullptr);

      reql_run_query(nullptr, table.get(), c.get(), nullptr);

      reql_no_reply_wait_query(c.get());

      table_args.get()->owner = nullptr;

      reql_ast_table(table.get(), table_args.get(), nullptr);

      std::unique_ptr<ReQL_Obj_t> empty(new ReQL_Obj_t);

      reql_object_init(empty.get(), nullptr, 0);

      std::unique_ptr<ReQL_Obj_t> insert_args(new ReQL_Obj_t);
      ReQL_Obj_t *arr2[2];

      reql_array_init(insert_args.get(), arr2, 2);
      reql_array_append(insert_args.get(), table.get());
      reql_array_append(insert_args.get(), empty.get());

      std::unique_ptr<ReQL_Obj_t> insert(new ReQL_Obj_t);

      reql_ast_insert(insert.get(), insert_args.get());

      reql_run_query(nullptr, insert.get(), c.get(), nullptr);

      reql_no_reply_wait_query(c.get());

      std::unique_ptr<ReQL_Cur_t> cur(new ReQL_Cur_t);

      reql_run_query(cur.get(), table.get(), c.get(), nullptr);

      REQUIRE(reql_cur_open(cur.get()) != 0);

      reql_cur_close(cur.get());
    }
  }

  SECTION("reql_conn_close") {
    reql_conn_close(c.get());

    REQUIRE(reql_conn_open(c.get()) == 0);
  }

  SECTION("reql_conn_destroy") {
    reql_conn_destroy(c.get());

    REQUIRE(reql_conn_open(c.get()) == 0);
  }

  reql_conn_close(c.get());

  REQUIRE(reql_conn_open(c.get()) == 0);

  reql_conn_destroy(c.get());

  REQUIRE(reql_conn_open(c.get()) == 0);
}
