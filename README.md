# Exercise EX0
## Running Result

```bash
wang@wang-virtual-machine:~/Documents/ex0$ mkdir build && cd build
wang@wang-virtual-machine:~/Documents/ex0/build$ cmake ..
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Building shared library
-- Configuring done
-- Generating done
-- Build files have been written to: /home/wang/Documents/ex0/build
wang@wang-virtual-machine:~/Documents/ex0/build$ make
Scanning dependencies of target vector
[  7%] Building CXX object CMakeFiles/vector.dir/lib/vector.cpp.o
[ 14%] Linking CXX shared library libvector.so
[ 14%] Built target vector
Scanning dependencies of target TestF_Copy
[ 21%] Building CXX object tests/CMakeFiles/TestF_Copy.dir/TestF_Copy.cpp.o
[ 28%] Linking CXX executable TestF_Copy
[ 28%] Built target TestF_Copy
Scanning dependencies of target TestA_Constructor
[ 35%] Building CXX object tests/CMakeFiles/TestA_Constructor.dir/TestA_Constructor.cpp.o
[ 42%] Linking CXX executable TestA_Constructor
[ 42%] Built target TestA_Constructor
Scanning dependencies of target TestC_Data
[ 50%] Building CXX object tests/CMakeFiles/TestC_Data.dir/TestC_Data.cpp.o
[ 57%] Linking CXX executable TestC_Data
[ 57%] Built target TestC_Data
Scanning dependencies of target TestB_Size
[ 64%] Building CXX object tests/CMakeFiles/TestB_Size.dir/TestB_Size.cpp.o
[ 71%] Linking CXX executable TestB_Size
[ 71%] Built target TestB_Size
Scanning dependencies of target TestD_At
[ 78%] Building CXX object tests/CMakeFiles/TestD_At.dir/TestD_At.cpp.o
[ 85%] Linking CXX executable TestD_At
[ 85%] Built target TestD_At
Scanning dependencies of target TestE_Sum
[ 92%] Building CXX object tests/CMakeFiles/TestE_Sum.dir/TestE_Sum.cpp.o
[100%] Linking CXX executable TestE_Sum
[100%] Built target TestE_Sum
wang@wang-virtual-machine:~/Documents/ex0/build$ make test
Running tests...
Test project /home/wang/Documents/ex0/build
    Start 1: TestA_Constructor
1/6 Test #1: TestA_Constructor ................   Passed    0.00 sec
    Start 2: TestB_Size
2/6 Test #2: TestB_Size .......................   Passed    0.00 sec
    Start 3: TestC_Data
3/6 Test #3: TestC_Data .......................   Passed    0.00 sec
    Start 4: TestD_At
4/6 Test #4: TestD_At .........................   Passed    0.00 sec
    Start 5: TestE_Sum
5/6 Test #5: TestE_Sum ........................   Passed    0.00 sec
    Start 6: TestF_Copy
6/6 Test #6: TestF_Copy .......................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 6

Total Test time (real) =   0.01 sec
```

## Prerequisits

Make sure you have a working environment configured with access to:
- git 
- cmake >= 3.0
- compiler/linker for C++17
- recommended: clangd (clang-format, clang-tidy)

### You can use the preconfigured docker-container (Theia-IDE + clang/LLVM) provided here 
https://github.com/cppitems/docker

## Background

In this exercise you have to implement a class which should provide a data structure of dynamically allocated, contiguous memory, usually called a **Vector**.

This exercise is designed to mimic the workflow of software development in a professional setting. You are provided with several [unit tests](https://en.wikipedia.org/wiki/Unit_testing), which are very short programs laying out the required functionality. These tests are stored in the folder `tests` and we have set up CMake to automatically build them. Writing these tests is usually the first step in developement and they should lay out the wanted functionality of a part of software. Oftentimes the tests are written by one programmer and then satisfied by another to avoid an implicit bias by a single programmer. Therefore, we have provided them for you.

Your library and all tests are built using the following commands in the project folder:
```bash
mkdir build && cd build
cmake ..    # this sets up the build system
make        # this builds the library and all tests      
make test   # this runs all tests
```

In order to turn off certain tests, you can uncomment them in the file `tests/CMakeLists.txt`. To turn off the test called "TestA", just add a `#` at the start of the corresponding line:
```bash
...
#list(APPEND MY_TEST_SOURCES "TestA")
list(APPEND MY_TEST_SOURCES "TestB")
...
```
Now, the test "TestB" will still be compiled and run, but not "TestA".

## Coding Task

Your task is to add the implementation of a `Vector` class for a small vector library which will store elements of type `int`. Once you are done, all available test cases should compile and pass without errors.

The source and header files for the vector library are initially empty and should be filled by you with the necessary C++ code.
You should **NOT** add any additional files but only modify the existing source files located at:
- `include/vector.hpp`
- `lib/vector.cpp`

There will be a test for every required aspect of the exercise. Tests are ordered with letters and should be finished in this order.
Your `Vector` class should satisfy the following:
- Test A: Constructor `Vector(size_t, int)`, member typedef `value_type` equal to `int`
- Test B: Member function `size_t size()` which returns the number of elements stored in the vector
- Test C: Member function `int *data()` which returns a pointer to the raw data
- Test D: Member function `int &at(size_t i)`, which returns the element at the index i
- Test E: Member function `int sum()` which sums alls elements and returns the results
- Test F: Correct copy constructor `Vector(const Vector &)`
- Test F: Correct copy assignment operator `Vector& operator=(const Vector&)`

*This exercise is not graded and just meant to give us an overview of how advanced each of you is. Do not worry if you do not manage to solve all the parts of the exercise, but please do try your best to pass as many tests as possible. For future exercises, we will have already covered all necessary topics in the lecture, so every one can successfully finish the exercise.*

You can build single tests by using their name as the first argument to make, and run them by executing them directly:
```bash
make TestA_Constructor                      # build test
tests/TestA_Constructor/TestA_Constructor   # execute test
```

Once you have implemented all the necessary features, make sure that all tests pass:
```bash
make buildTests
make test
```
and then push your changes to your Gitea repository.

## Pushing to Gitea

All exercises must be handed in to your repository on our Gitea server at [https://tea.iue.tuwien.ac.at](https://tea.iue.tuwien.ac.at)

### Initial Setup (only do this once)

git is a software versioning tool and is commonly used in almost all areas of software development.

You can obtain the exercise using:
```bash
git clone https://github.com/cppitems/ex0.git 
cd ex0 # change into the folder which was created by cloning
git status # check git status
git remote -v # show the configuration of remotes (where you can push to)
```
Next, you need to create a remote repository on tea.iue.tuwien.ac.at:
1. navigate to tea.iue.tuwien.ac.at
2. login with username and initial password
3. create a new repository named 'ex0'

Next, you want to connect your local repository to this new repository (to be able to push the assignments):
```bash
git remote add submission https://tea.iue.tuwien.ac.at/e12345678/ex0.git
git remote -v # show all remotes
git push -u submission master # make initial push and set new remote as default
```
where `submission` is the name we want to call this remote repository, `e12345678` should be replaced with `e<yourstudentid>` and `ex0` is the name of the repository on the server.
Make sure you have created the repository before trying to upload to it.

Now you can push to the submission remote in the usual way:
```bash
git push # now uses the default remote "submission"
```

#### Upload after working on the project

*FAQ: How often should I push my changes to Gitea?*
*Answer: **Every time you get up from your computer. Every. Single. Time.** *

After having done some exhausting coding, we want to add all file changes in the current folder (`.`) to git:
```bash
git add . 
```
In order to see what files have changed, you can run
```bash
git status
```
and you can check all changes within files with
```bash
git diff HEAD
```
Once you are happy with all changes you can `commit` them to save them locally using a meaningful message that describes what you have done
```bash
git commit -m "Added flux capacitor."
```
Once all changes are comitted, we can tell git to upload them using
```bash
git push
```
