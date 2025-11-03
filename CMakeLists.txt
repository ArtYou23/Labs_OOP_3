cmake_minimum_required(VERSION 3.14)
project(third_laba)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(run_file
    src/main.cpp
    src/Figure.cpp
    src/Trapezoid.cpp
    src/Rhombus.cpp 
    src/Pentagon.cpp
)

target_include_directories(run_file PRIVATE include)

add_executable(tests tests/tests.cpp
    src/Figure.cpp
    src/Trapezoid.cpp
    src/Rhombus.cpp 
    src/Pentagon.cpp
)

target_include_directories(tests PRIVATE include)
target_link_libraries(tests GTest::gtest)

enable_testing()
add_test(NAME MyProjectTests COMMAND tests)