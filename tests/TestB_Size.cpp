#include "vector.hpp"
#include <testasserts.hpp>

/*
  This test checks, whether the member function size() is defined.
*/

int main() {
  // ctor: length '1000', init with '10'
  auto vec = Vector(1000, 10);
  // check if size is defined
  vec.size();

  // RUNTIME Checks
  // check if vec.size() returns the correct size
  TEST_ASSERT(vec.size() == 1000, "Wrong vector size!");

  return 0;
}
