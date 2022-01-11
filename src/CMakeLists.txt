set (CMAKE_CXX_STANDARD 17)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/line_provider")

add_subdirectory(regex)
add_executable(my_regex main.cpp)

target_link_libraries(my_regex PUBLIC regex)
target_include_directories(my_regex PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/regex")
