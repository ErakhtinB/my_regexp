cmake_minimum_required(VERSION 3.22)

project(my_regex)

set (CMAKE_CXX_STANDARD 17)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/line_provider")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src/regex")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

if(WITH_TESTS)
  add_subdirectory(test)
endif()
