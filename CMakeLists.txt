cmake_minimum_required(VERSION 3.15)
project(cmake2_demo)

find_package(Catch2 3 REQUIRED)

add_executable(my_tests my_tests.cpp)

target_link_libraries(my_tests PRIVATE Catch2::Catch2WithMain)
