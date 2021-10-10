cmake_minimum_required(VERSION 3.0)

# set up the project for building all tests
project(Tests LANGUAGES CXX)

# make a custom target for usage with make
# all tests can be built using `make myTests`
add_custom_target(myTests)

set(MY_TEST_SOURCES "")
list(APPEND MY_TEST_SOURCES "TestA_Constructor")
list(APPEND MY_TEST_SOURCES "TestB_Size")
list(APPEND MY_TEST_SOURCES "TestC_Data")
list(APPEND MY_TEST_SOURCES "TestD_At")
list(APPEND MY_TEST_SOURCES "TestE_Sum")
list(APPEND MY_TEST_SOURCES "TestF_Copy")

foreach(MY_TEST_SOURCE ${MY_TEST_SOURCES})
  add_executable(${MY_TEST_SOURCE} ${MY_TEST_SOURCE}.cpp)
  target_include_directories(${MY_TEST_SOURCE} PUBLIC "${MY_LIBRARY_INCLUDE_DIRS}")
  target_link_libraries(${MY_TEST_SOURCE} PRIVATE ${MY_LIBRARY})

  # Add to test framework, so test can be built with `make buildTests`
  add_dependencies(myTests ${MY_TEST_SOURCE})
  add_test(NAME ${MY_TEST_SOURCE} COMMAND ${MY_TEST_SOURCE})
endforeach(MY_TEST_SOURCE ${MY_TEST_SOURCES})
