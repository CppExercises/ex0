#include "vector.hpp"
#include <testasserts.hpp>

/*
  This test checks, whether the member function at() is defined
  and returns the correct element.
*/

int main() {
  // initialise vector
  auto vec = Vector(1000, 0); // ctor: length '1000', init with '0'
  // check if at is defined
  vec.at(0);

  // RUNTIME Checks
  // set new values using at(i)
  for (size_t i = 0; i < vec.size(); ++i) {
    vec.at(i) = Vector::value_type(i);
  }

  // now check whether elements have been set correctly
  for (size_t i = 0; i < vec.size(); ++i) {
    auto data = vec.data();
    TEST_ASSERT(data[i] == Vector::value_type(i),
                "Wrong value for element " + std::to_string(i));
  }

  return 0;
}
