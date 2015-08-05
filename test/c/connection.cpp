// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./ReQL.h"

int
result_parse_handler(ReQL_Result_t *result, ReQL_Parse_Event e, void *obj);

int
cursor_each_handler(ReQL_Result_t *res, void *data);

int
result_parse_handler(ReQL_Result_t *result, ReQL_Parse_Event e, void *obj) {
  (void)result;
  (void)obj;
  switch (e) {
    case ReQL_Bool: {
      break;
    }
    case ReQL_End_Array: {
      break;
    }
    case ReQL_End_Element: {
      break;
    }
    case ReQL_End_Key_Value: {
      break;
    }
    case ReQL_End_Object: {
      break;
    }
    case ReQL_Error: {
      break;
    }
    case ReQL_Null: {
      break;
    }
    case ReQL_Number: {
      break;
    }
    case ReQL_Start_Array: {
      break;
    }
    case ReQL_Start_Element: {
      break;
    }
    case ReQL_Start_Key_Value: {
      break;
    }
    case ReQL_Start_Object: {
      break;
    }
    case ReQL_String: {
      break;
    }
  }
  return 0;
}

int
cursor_each_handler(ReQL_Result_t *res, void *data) {
  if (res == NULL) {
    return 1;
  }
  reql_result_parse(res, result_parse_handler, data);
  return 0;
}

TEST_CASE("c connection", "[c][connect]") {
  ReQL_Connection_t *conn = reql_connect(0, nullptr, nullptr, nullptr, 0);

  REQUIRE(conn != nullptr);

  ReQL_t *db_name = reql_string("libReQLc", 8);

  REQUIRE(db_name != nullptr);

  ReQL_t **args = {&db_name};
  ReQL_t *query = reql_db_create(args);

  REQUIRE(query != nullptr);

  ReQL_Cursor_t *cur = reql_run(query, nullptr, conn);

  REQUIRE(cur != nullptr);

  reql_cursor_each_async(cur, cursor_each_handler, nullptr);
  reql_cursor_drain(cur);

  reql_cursor_close(cur);
  reql_connection_close(conn);
}
