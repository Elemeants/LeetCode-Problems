cmake_minimum_required(VERSION 3.14)
project(LeetCode_3_Longest_Substring)

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
  LeetCode_3_Longest_Substring
  test.cpp
)

target_link_libraries(
  LeetCode_3_Longest_Substring
  GTest::gtest_main
)

target_include_directories (LeetCode_3_Longest_Substring PRIVATE ${CMAKE_CURRENT_LIST_DIR})

include(GoogleTest)
gtest_discover_tests(LeetCode_3_Longest_Substring)