#include "vector.hpp"
#include <testasserts.hpp>

/*
  This test checks, whether the copy constructor and copy assignment
  operator have been implemented correctly.
*/

int main() {
  // initialise vector
  auto vec = Vector(1000, 0); // ctor: length '1000', init with '0'

  // RUNTIME Checks
  // set new values using at(i)
  for (size_t i = 0; i < vec.size(); ++i) {
    vec.at(i) = Vector::value_type(i);
  }

  // test copy assignment
  {
    Vector other = vec;
    TEST_ASSERT(vec.data() != other.data(),
                "Copy assignment: data should not alias");
    TEST_ASSERT(vec.sum() == other.sum(), "Copy assignment: sums do not match");
  }

  // copy constructor
  {
    Vector other(vec);
    TEST_ASSERT(vec.data() != other.data(),
                "Copy cpnstructor: data should not alias");
    TEST_ASSERT(vec.sum() == other.sum(),
                "Copy constructor: sums do not match");
  }

  return 0;
}
