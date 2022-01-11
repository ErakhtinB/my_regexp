cmake_minimum_required(VERSION 3.22)

project(my_regex)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

if(WITH_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )

  add_subdirectory(test)
endif()
