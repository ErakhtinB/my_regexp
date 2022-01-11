enable_testing()

add_executable(
  regex_test
  regex_test.cc
)

target_link_libraries(
  regex PUBLIC
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(regex_test)
