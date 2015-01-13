#include "ReQL.hpp"

#include <map>
#include <iostream>

#ifndef _REQL_TEST
#define _REQL_TEST

namespace ReQL {
extern "C" {

#include "ReQL-char.h"
#include "ReQL-decode.h"
#include "ReQL-encode.h"
#include "ReQL-error.h"
#include "ReQL-util.h"

}
}

class CoreTest {
public:
  CoreTest();

  virtual void setup();
  virtual void run();
  virtual void cleanup();

  void assert(bool, std::string);
  void fail(std::string);

  void addTest(CoreTest test);
  bool hasFailure();
  void printResults();

  void setName(std::string name);

  std::vector<CoreTest> p_subtests;

private:
  void collectFailures();
  long count();

  std::map<CoreTest*, std::string> getFailures();
  std::string getName();

  std::map<CoreTest*, std::string> p_failures;
  std::string p_name;
};

class UnitTest : public CoreTest {
public:
  UnitTest();

  void setup();
  void run();
  void cleanup();
};

#endif
