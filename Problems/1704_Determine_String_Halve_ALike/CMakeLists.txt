cmake_minimum_required(VERSION 3.14)
project(LeedCode_1704_Determine_String_Halve_ALike)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  Gtest
  test.cpp
)

target_link_libraries(
  Gtest
  GTest::gtest_main
  -lasan
)

target_compile_options(Gtest PUBLIC -g -Wall -Werror -fsanitize=address)
target_include_directories (Gtest PRIVATE ${CMAKE_CURRENT_LIST_DIR})

include(GoogleTest)
gtest_discover_tests(Gtest)
