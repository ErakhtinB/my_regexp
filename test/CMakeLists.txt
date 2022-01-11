enable_testing()

include(GoogleTest)

add_executable(
  regex_test
  regex_test.cc
)

target_link_libraries(
  regex_test
  regex
  gtest
  gtest_main
  pthread
)

gtest_discover_tests(regex_test)
