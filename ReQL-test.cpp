#include "ReQL-test.hpp"

#include "ReQL-ast-test.hpp"
#include "ReQL-expr-test.hpp"

using namespace ReQL;

class TestFailure {
public:
  TestFailure(std::string msg) {
    p_msg = msg;
  }

  std::string failure() {
    return p_msg;
  }

  std::string p_msg;
};

CoreTest::CoreTest() {
}

void CoreTest::addTest(CoreTest test) {
  p_subtests.push_back(test);
};

void CoreTest::assert(bool cond, std::string msg) {
  if (!cond) {
    fail(msg);
  }
}

void CoreTest::cleanup() {
}

void CoreTest::collectFailures() {
  for (auto iter=p_subtests.begin(); iter!=p_subtests.end(); ++iter) {
    iter->collectFailures();
    std::map<CoreTest*, std::string> subFailures = iter->getFailures();
    p_failures.insert(subFailures.cbegin(), subFailures.cend());
  }
}

long CoreTest::count() {
  if (p_subtests.size() > 0) {
    long c = 0;
    for (auto iter=p_subtests.begin(); iter!=p_subtests.end(); ++iter) {
      c += iter->count();
    }
    return c;
  }
  return 1;
}

void CoreTest::fail(std::string msg) {
  p_failures.insert(std::pair<CoreTest*, std::string>(this, msg));
  throw TestFailure(msg);
}

std::map<CoreTest*, std::string> CoreTest::getFailures() {
  return p_failures;
};

std::string CoreTest::getName() {
  return p_name;
};

bool CoreTest::hasFailure() {
  return p_failures.size() > 0;
};

void CoreTest::printResults() {
  collectFailures();
  for (auto iter=p_failures.cbegin(); iter!=p_failures.cend(); ++iter) {
    std::cout << iter->first->getName() << " " << iter->second << std::endl;
  }
  std::cout << "Test results: " << p_failures.size() << " failed of " << count() << " tests." << std::endl;
}

void CoreTest::run() {
}

void CoreTest::setup() {
}

void CoreTest::setName(std::string name) {
  p_name = name;
};

UnitTest::UnitTest() {
}

void UnitTest::cleanup() {
}

void UnitTest::run() {
  for (auto iter=p_subtests.begin(); iter!=p_subtests.end(); ++iter) {
    try {
      iter->setup();
      try {
        iter->run();
      } catch (const TestFailure& e) {
      } catch (const std::exception& e) {
        std::string err = "Uncaught exception in test: ";
        err.append(e.what());
        try {
          fail(err);
        } catch (const TestFailure& e) {
        }
      }
      iter->cleanup();
    } catch (const TestFailure& e) {
    } catch (const std::exception& e) {
      std::string err = "Uncaught exception: ";
      err.append(e.what());
      try {
        fail(err);
      } catch (const TestFailure& e) {
      }
    }
  }
}

void UnitTest::setup() {
  setName("UnitTest");
  addTest(ASTTest());
  addTest(ExprTest());
}

int main(int argc, char **argv) {
  UnitTest test;

  test.setup();
  test.run();
  test.cleanup();

  test.printResults();

  if (test.hasFailure()) {
    return 1;
  }

  return 0;
}
