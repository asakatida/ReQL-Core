#define CATCH_CONFIG_RUNNER
#include "./catch.hpp"
#include "./ReQL.hpp"

int
main(int argc, char **argv) {
  int result = Catch::Session().run(argc, argv);

  try {
    ReQL::Connection conn;

    ReQL::wait({})
    .funcall({
      ReQL::func({
        1.0,
        ReQL::db({std::string("rethinkdb")})
        .table({std::string("db_config")})
        .delete_({})
      })
    }).run(conn).toVector().clear();
    
    conn.close();
  } catch (ReQL::ReQLError &e) {
  }

  return result;
}
