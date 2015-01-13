#include "ReQL-ast-test.hpp"

class BlankTest : public ASTTest {
public:
  BlankTest() : ASTTest() {
  }

  void setup() {
    setName("BlankTest");
  }

  void run() {
  }

  void cleanup() {
  }
};

void ASTTest::setup() {
  setName("ASTTest");
  addTest(BlankTest());
}
