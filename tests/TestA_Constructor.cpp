#include "vector.hpp"
#include <testasserts.hpp>

/*
  This test checks, whether a constructor of the form Vector(size, value)
  is defined, where size is the number of elements in the vector
  and value is the initial value all elements should be assigned.
*/

int main() {
  // ctor: length '1000', init with '10'
  auto vec = Vector(1000, 10);

  // check if the type of all elements is really int
  static_assert(std::is_same<Vector::value_type, int>::value,
                "value_type must be int");

  return 0;
}
