#include "vector.hpp"
#include <testasserts.hpp>

/*
  This test checks, whether the member function data() is defined
  and returns the correct pointer.
*/

int main() {
  // ctor: length '1000', init with '10'
  auto vec = Vector(1000, 10);
  // check if size is defined
  vec.data();

  // RUNTIME Checks
  // check whether data returns the correct pointer to the underlying data
  // structure
  for (size_t i = 0; i < vec.size(); ++i) {
    const int *data = vec.data();
    TEST_ASSERT(data[i] == 10, "Wrong value for element " + std::to_string(i));
  }

  return 0;
}
