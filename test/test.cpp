// Copyright 2015 Adam Grandquist

#define CATCH_CONFIG_MAIN
#include "./test.hpp"

namespace ReQL {

namespace _C {

extern "C" {

#include "./c/dev/json.h"

}

}  // namespace _C

using namespace ReQL;
using namespace _C;

ReQL_Conn_c::ReQL_Conn_c() : _C::CTypes::connection(new ReQL_Conn_t) {
  reql_connection_init(get());

  REQUIRE(reql_conn_open(get()) == 0);
}

ReQL_Conn_c::~ReQL_Conn_c() {
  reql_close_conn(get());

  REQUIRE(reql_conn_open(get()) == 0);

  reql_ensure_conn_close(get());

  REQUIRE(reql_conn_open(get()) == 0);
}

ReQL_Cur_c::ReQL_Cur_c() : _C::CTypes::cursor(new ReQL_Cur_t) {}

ReQL_Cur_c::~ReQL_Cur_c() {}

ReQL_Obj_c::ReQL_Obj_c() : _C::CTypes::object(new ReQL_Obj_t) {}

ReQL_Obj_c::~ReQL_Obj_c() {}

ReQL_Res_c::ReQL_Res_c(ReQL_Obj_t *ptr) : p_ptr(ptr) {
  REQUIRE(ptr != nullptr);
}

ReQL_Res_c::~ReQL_Res_c() {
  reql_json_destroy(p_ptr); p_ptr = nullptr;
}

std::string inspect(const Query &query) {
  return inspect(query._data());
}

std::string inspect(const ReQL_Obj_t *query) {
  if (query == nullptr) {
    return "unknown";
  }

  switch (reql_datum_type(query)) {
    case REQL_R_ARRAY: {
      std::stringstream buf;

      buf << "[";

      ReQL_Iter_t it = reql_new_iter(query);
      ReQL_Obj_t *elem = nullptr;
      char first = 1;

      while ((elem = reql_iter_next(&it)) != nullptr) {
        if (first == 0) {
          buf << ",";
        }
        buf << inspect(elem);
        first = 0;
      }

      buf << "]";

      return buf.str();
    }
    case REQL_R_BOOL: return reql_to_bool(query) ? "true" : "false";
    case REQL_R_JSON: return "error";
    case REQL_R_NULL: return "null";
    case REQL_R_NUM: return std::to_string(reql_to_number(query));
    case REQL_R_OBJECT: {
      std::stringstream buf;

      buf << "{";

      ReQL_Iter_t it = reql_new_iter(query);
      ReQL_Obj_t *key = nullptr;
      char first = 1;

      while ((key = reql_iter_next(&it)) != nullptr) {
        if (first == 0) {
          buf << ",";
        }
        buf << inspect(key);
        buf << ":";
        buf << inspect(reql_object_get(query, key));
        first = 0;
      }

      buf << "}";

      return buf.str();
    }
    case REQL_R_REQL: {
      std::stringstream buf;

      buf << "(";
      buf << reql_term_type(query);
      const ReQL_Obj_t *args = reql_args(query);
      if (args != nullptr) {
        buf << ",";
        buf << inspect(args);
      }
      const ReQL_Obj_t *kwargs = reql_kwargs(query);
      if (kwargs != nullptr) {
        buf << ",";
        buf << inspect(kwargs);
      }
      buf << ")";

      return buf.str();
    }
    case REQL_R_STR: return std::string(reinterpret_cast<char *>(reql_string_buf(query)), reql_size(query));
  }

  throw std::exception();
}

}  // namespace ReQL
