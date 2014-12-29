#include "ReQL-ast-test.hpp"
#include "ReQL-expr-test.hpp"

#include "ReQL-CPP.hpp"

using namespace ReQL;

int testCONNECT(int argc, char **argv) {
  Connection conn = connect();
  return conn.close();
}

int main(int argc, char **argv) {
  return testAST(argc, argv) & testEXPR(argc, argv) & testCONNECT(argc, argv);
}
