// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/core.h"

#include <string>

static void
reql_test_cur_end_cb(void *data) {
  *static_cast<int*>(data) = 0;
}

static void
reql_test_cur_error_cb(ReQL_Obj_t *res, void *data) {
  if (res != nullptr) {
    *static_cast<int*>(data) = 0;
  }
}

static int
reql_test_cur_each_cb(ReQL_Obj_t *res, void *data) {
  if (res != nullptr) {
    ++(*static_cast<int*>(data));
  }
  return res == nullptr;
}

static int
reql_test_cur_each_inf_cb(ReQL_Obj_t *res, void *data) {
  int *num = static_cast<int*>(data);
  if (res != nullptr) {
    ++(*num);
  }
  if (*num > 99) {
    return 1;
  }
  return 0;
}

TEST_CASE("reql cursor", "[reql][cursor]") {
  std::unique_ptr<ReQL_Conn_t> conn(new ReQL_Conn_t);

  reql_conn_init(conn.get());

  REQUIRE(reql_conn_open(conn.get()) == 0);

  ReQL_Byte buffer[100];

  REQUIRE(reql_conn_connect(conn.get(), buffer, 100) == 0);

  REQUIRE(reql_conn_open(conn.get()) != 0);

  std::unique_ptr<ReQL_Cur_t> c(new ReQL_Cur_t);

  SECTION("basic") {
    ReQL_Size size = 1;

    ReQL_Obj_t *args = new ReQL_Obj_t;
    ReQL_Obj_t **array = new ReQL_Obj_t*[size];
    reql_array_init(args, array, size);

    ReQL_Obj_t *elem = new ReQL_Obj_t;
    reql_number_init(elem, 100);
    reql_array_append(args, elem);

    ReQL_Obj_t *query = new ReQL_Obj_t;
    reql_ast_range(query, args);

    REQUIRE(reql_run(c.get(), query, conn.get(), nullptr) == 0);

    reql_json_destroy(query);

    REQUIRE(reql_cur_open(c.get()) != 0);

    SECTION("reql_cur_set_end_cb") {
      int data = 1;
      reql_cur_set_end_cb(c.get(), reql_test_cur_end_cb, &data);
      reql_cur_drain(c.get());
      REQUIRE(data == 0);
    }

    SECTION("reql_cur_destroy") {
      reql_cur_destroy(c.get());

      REQUIRE(reql_cur_open(c.get()) == 0);
    }

    SECTION("reql_cur_close") {
      reql_cur_close(c.get());

      REQUIRE(reql_cur_open(c.get()) == 0);
    }

    SECTION("reql_cur_next") {
      int data = 0;
      ReQL_Obj_t *res = nullptr;
      while ((res = reql_cur_next(c.get())) != nullptr) {
        REQUIRE(reql_datum_type(res) == REQL_R_NUM);
        REQUIRE(reql_to_number(res) == Approx(data));
        reql_json_destroy(res);
        ++data;
      }
      REQUIRE(reql_cur_open(c.get()) == 0);
    }

    SECTION("reql_cur_each") {
      int data = 0;
      reql_cur_each(c.get(), reql_test_cur_each_cb, &data);
      reql_cur_drain(c.get());
      REQUIRE(data == 100);
      REQUIRE(reql_cur_open(c.get()) == 0);
    }
  }

  SECTION("infinite") {
    ReQL_Obj_t *query = new ReQL_Obj_t;
    reql_ast_range(query, nullptr);

    REQUIRE(reql_run(c.get(), query, conn.get(), nullptr) == 0);

    reql_json_destroy(query);

    REQUIRE(reql_cur_open(c.get()) != 0);
    
    SECTION("reql_cur_next") {
      int data = 0;
      ReQL_Obj_t *res = nullptr;
      for (; (res = reql_cur_next(c.get())) != nullptr && data < 100; ++data) {
        REQUIRE(reql_datum_type(res) == REQL_R_NUM);
        REQUIRE(reql_to_number(res) == Approx(data));
        reql_json_destroy(res);
      }
      REQUIRE(data == 100);
      REQUIRE(reql_cur_open(c.get()) != 0);
      reql_cur_close(c.get());
      REQUIRE(reql_cur_open(c.get()) == 0);
    }

    SECTION("reql_cur_each") {
      int data = 0;
      reql_cur_each(c.get(), reql_test_cur_each_inf_cb, &data);
      reql_cur_drain(c.get());
      REQUIRE(data == 100);
      REQUIRE(reql_cur_open(c.get()) == 0);
    }
  }

  SECTION("reql_cur_set_error_cb") {
    std::unique_ptr<ReQL_Obj_t> query(new ReQL_Obj_t);
    std::unique_ptr<ReQL_Byte> buf(new ReQL_Byte[2]);
    const ReQL_Byte src[] = "\0t";
    reql_string_init(query.get(), buf.get(), src, 2);
    reql_run(c.get(), query.get(), conn.get(), nullptr);

    REQUIRE(reql_cur_open(c.get()) != 0);

    int data = 1;
    reql_cur_set_error_cb(c.get(), reql_test_cur_error_cb, &data);
    reql_cur_drain(c.get());
    REQUIRE(data == 0);
  }

  SECTION("reql_cur_to_array") {
    ReQL_Size size = 1;

    ReQL_Obj_t *args = new ReQL_Obj_t;
    ReQL_Obj_t **array = new ReQL_Obj_t*[size];
    reql_array_init(args, array, size);

    ReQL_Obj_t *elem = new ReQL_Obj_t;
    reql_number_init(elem, 100);
    reql_array_append(args, elem);

    ReQL_Obj_t *query = new ReQL_Obj_t;
    reql_ast_range(query, args);

    REQUIRE(reql_run(c.get(), query, conn.get(), nullptr) == 0);
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
