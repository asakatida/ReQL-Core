#define CATCH_CONFIG_RUNNER
#include "./catch.hpp"
#include "./ReQL.hpp"

#include <string>
#include <vector>

int
main(int argc, char **argv) {
  int result = Catch::Session().run(argc, argv);

  try {
    ReQL::Connection conn;

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

    conn.close();
  } catch (ReQL::ReQLError &e) {
    (void)e;
  }

  return result;
}
