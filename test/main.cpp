#define CATCH_CONFIG_RUNNER
#include "./catch.hpp"
#include "./ReQL.hpp"

int
main(int argc, char **argv) {
  int result = Catch::Session().run(argc, argv);

  try {
    ReQL::Connection conn;

    ReQL::db_list({}).filter({
      ReQL::func({
        1.0,
        ReQL::var({1.0}).ne({std::string("rethinkdb")})
      })
    }).for_each({
      ReQL::func({
        2.0,
        ReQL::var({2.0}).db({}).wait({})
        .funcall({
          ReQL::func({
            3.0,
            ReQL::var({2.0}).db_drop({})
          })
        })
      })
    })
    .run(conn).toVector().clear();
    
    conn.close();
  } catch (ReQL::ReQLError &e) {
    (void)e;
  }

  return result;
}
