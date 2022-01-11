cmake_minimum_required(VERSION 3.22)

project(my_regex)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

if(WITH_TESTS)
  add_subdirectory(test)
endif()
