cmake_minimum_required(VERSION 3.10)

# SET(CMAKE_C_COMPILER C:/w64devkit/bin/gcc.exe)
# SET(CMAKE_CXX_COMPILER C:/w64devkit/bin/g++.exe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# project(lab)

add_library(lab_lib ./src/seven.cpp)

# add_executable(lab ./main.cpp)
# target_link_libraries(lab PRIVATE lab_lib)

enable_testing()

add_executable(
  test_lab
  ./gtests.cpp
)

target_link_libraries(
    test_lab
    PRIVATE 
    lab_lib 
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_lab)