#include "ReQL-ast-test.hpp"
#include "ReQL-expr-test.hpp"

#include "ReQL-CPP.hpp"

int testCONNECT(int argc, char **argv) {
  return 0;
}

int main(int argc, char **argv) {
  return testAST(argc, argv) & testEXPR(argc, argv) & testCONNECT(argc, argv);
}
