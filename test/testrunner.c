#include "MinCTest/MinCTest.h"

#include "empty/empty.c"


int main(int argc, char *argv[]) {
  TestRunner tr = newTestRunner();

  registerTestGroup(tr, "empty");
  registerTest(tr, "empty", empty_test);

  return runTests(tr, argc, argv);
}
