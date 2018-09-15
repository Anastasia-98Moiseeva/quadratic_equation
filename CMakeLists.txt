cmake_minimum_required(VERSION 3.5)
project(QuadraticEquation)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(googletest-master)

include_directories(googletest-master/googletest/include)

include_directories(googletest-master/googlemock/include)

add_executable(QuadraticEquation main.cpp test.cpp)

target_link_libraries(QuadraticEquation gtest gtest_main)

target_link_libraries(QuadraticEquation gmock gmock_main)