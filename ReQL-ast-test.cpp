#include "ReQL-ast-test.hpp"

using namespace ReQL;

class BlankTest : public ASTTest {
public:
  BlankTest() : ASTTest() {
  }

  void setup();

  void cleanup() {
    conn.close();
  }

  Connection conn;
};

class TableTermTest : public BlankTest {
public:
  TableTermTest() : BlankTest() {};

  void run() {
    table({expr("test")}).run(conn);
  }
};

void BlankTest::setup() {
  setName("BlankTest");
  conn = connect();
  assert(conn.isOpen(), "Connection failed.");
  addTest(TableTermTest());
}

void ASTTest::setup() {
  setName("ASTTest");
  addTest(BlankTest());
}
