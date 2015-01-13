#include "ReQL-expr-test.hpp"

using namespace ReQL;

class ConnectionTest : public ExprTest {
public:
  ConnectionTest() : ExprTest() {
  };

  void setup() {
    setName("ConnectionTest");
  }

  void run() {
    Connection conn = Connection();

    conn.close();
  };

  void cleanup() {
  }
};

void ExprTest::setup() {
  setName("ExprTest");
  addTest(ConnectionTest());
}
