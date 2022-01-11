set (CMAKE_CXX_STANDARD 17)

add_subdirectory(regex)
add_executable(my_regex main.cpp)

target_link_libraries(my_regex PUBLIC regex)
