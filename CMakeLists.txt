cmake_minimum_required(VERSION 3.15)
project(cmake2_demo)

find_package(Catch2 3 REQUIRED)

add_executable(tests tests.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
