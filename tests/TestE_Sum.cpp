#include "vector.hpp"
#include <testasserts.hpp>

/*
  This test checks, whether the member function sum() is defined
  and returns the correct sum of all elements.
*/

int main() {
  // initialise vector
  auto vec = Vector(1000, 0); // ctor: length '1000', init with '0'
  // check if sum is defined
  vec.sum();

  // RUNTIME Checks
  // set new values using at(i)
  for (size_t i = 0; i < vec.size(); ++i) {
    vec.at(i) = Vector::value_type(i);
  }

  // now check whether the correct sum is returned
  const int sum = vec.size() * (vec.size() - 1) / 2;
  TEST_ASSERT(vec.sum() == sum, "Wrong sum of natural numbers");

  return 0;
}
