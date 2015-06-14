#define CATCH_CONFIG_RUNNER
#include "./catch.hpp"
#include "./ReQL.hpp"

int
main(int argc, char **argv) {
  int result = Catch::Session().run(argc, argv);

  try {
    ReQL::Connection conn;

    ReQL::db_list(ReQL::Types::array())
    .filter(ReQL::Types::array({
      ReQL::func(ReQL::Types::array({
        ReQL::Query(ReQL::Types::array({ReQL::Query(1.0)})),
        ReQL::var(ReQL::Types::array({ReQL::Query(1.0)}))
        .ne(ReQL::Types::array({
          ReQL::Query(ReQL::Types::string("rethinkdb"))
        }))
      }))
    }))
    .for_each(ReQL::Types::array({
      ReQL::func(ReQL::Types::array({
        ReQL::Query(ReQL::Types::array({ReQL::Query(2.0)})),
        ReQL::func(ReQL::Types::array({
          ReQL::Query(ReQL::Types::array()),
          ReQL::db_drop(ReQL::Types::array({
            ReQL::var(ReQL::Types::array({ReQL::Query(2.0)}))
          }))
        }))
        .funcall(ReQL::Types::array({
          ReQL::db(ReQL::Types::array({
            ReQL::var(ReQL::Types::array({ReQL::Query(2.0)}))
          }))
          .wait(ReQL::Types::array())
        }))
      }))
    }))
    .run(conn).toVector().clear();
    
    conn.close();
  } catch (ReQL::ReQLError &e) {
    (void)e;
  }

  return result;
}
