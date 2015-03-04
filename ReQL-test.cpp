#include "ReQL-test.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.h"

std::string inspect(ReQL::Query query) {
  return inspect(query.data());
}

std::string inspect(ReQL::ReQL_Obj_t *query) {
  if (query == nullptr) {
    return "unknown";
  }

  switch (ReQL::reql_datum_type(query)) {
    case ReQL::REQL_R_ARRAY: {
      std::stringstream buf;
      
      buf << "[";

      ReQL::ReQL_Iter_t it = ReQL::reql_new_iter(query);
      ReQL::ReQL_Obj_t *elem = nullptr;
      char first = 1;

      while ((elem = ReQL::reql_iter_next(&it)) != nullptr) {
        if (first == 0) {
          buf << ",";
        }
        buf << inspect(elem);
        first = 0;
      }

      buf << "]";

      return buf.str();
    }
    case ReQL::REQL_R_BOOL: return ReQL::reql_to_bool(query) ? "true" : "false";
    case ReQL::REQL_R_JSON: return "error";
    case ReQL::REQL_R_NULL: return "null";
    case ReQL::REQL_R_NUM: return std::to_string(ReQL::reql_to_number(query));
    case ReQL::REQL_R_OBJECT: {
      std::stringstream buf;

      buf << "{";

      ReQL::ReQL_Iter_t it = ReQL::reql_new_iter(query);
      ReQL::ReQL_Obj_t *key = nullptr;
      char first = 1;

      while ((key = ReQL::reql_iter_next(&it)) != nullptr) {
        if (first == 0) {
          buf << ",";
        }
        buf << inspect(key);
        buf << ":";
        buf << inspect(ReQL::reql_object_get(query, key));
        first = 0;
      }

      buf << "}";

      return buf.str();
    }
    case ReQL::REQL_R_REQL: {
      std::stringstream buf;

      buf << "(";
      buf << ReQL::reql_datum_type(query);
      ReQL::ReQL_Obj_t *args = ReQL::reql_args(query);
      if (args != nullptr) {
        buf << ",";
        buf << inspect(args);
      }
      ReQL::ReQL_Obj_t *kwargs = ReQL::reql_args(query);
      if (kwargs != nullptr) {
        buf << ",";
        buf << inspect(kwargs);
      }
      buf << ")";

      return buf.str();
    }
    case ReQL::REQL_R_STR: return std::string(reinterpret_cast<char *>(ReQL::reql_string_buf(query)), ReQL::reql_size(query));
  }

  throw;
}
