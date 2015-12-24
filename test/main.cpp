#include <winsock2.h>

#define CATCH_CONFIG_RUNNER
#include "./catch.hpp"
#include "./ReQL.hpp"

#include <exception>
#include <string>
#include <vector>

int
main(int argc, char **argv) {
  int result = -1;
  std::exception_ptr exc;

  try {
    result = Catch::Session().run(argc, argv);
  } catch (std::exception &) {
    exc = std::current_exception();
  }

  try {
    ReQL::Connection<ReQL::Result> conn;
/*
    ReQL::db_list(std::vector<ReQL::Query>())
    .filter(std::vector<ReQL::Query>({
      ReQL::func(std::vector<ReQL::Query>({
        ReQL::Query(std::vector<ReQL::Query>({ReQL::Query(1.0)})),
        ReQL::var(std::vector<ReQL::Query>({ReQL::Query(1.0)}))
        .ne(std::vector<ReQL::Query>({
          ReQL::Query(std::wstring(L"rethinkdb"))
        }))
      }))
    }))
    .for_each(std::vector<ReQL::Query>({
      ReQL::func(std::vector<ReQL::Query>({
        ReQL::Query(std::vector<ReQL::Query>({ReQL::Query(2.0)})),
        ReQL::func(std::vector<ReQL::Query>({
          ReQL::Query(std::vector<ReQL::Query>()),
          ReQL::db_drop(std::vector<ReQL::Query>({
            ReQL::var(std::vector<ReQL::Query>({ReQL::Query(2.0)}))
          }))
        }))
        .funcall(std::vector<ReQL::Query>({
          ReQL::db(std::vector<ReQL::Query>({
            ReQL::var(std::vector<ReQL::Query>({ReQL::Query(2.0)}))
          }))
          .wait(std::vector<ReQL::Query>())
        }))
      }))
    }))
    .no_reply(conn);
*/
    conn.close();
  } catch (_ReQL::Error_t &) {
    if (!exc) exc = std::current_exception();
  }

  if (exc) std::rethrow_exception(exc);

  return result;
}
