cmake_minimum_required(VERSION 3.0)

project(fast-cpp-csv-parser CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(CTest)
include(ClangFormat)
include(ClangTidy)
include(CppCheck)

find_package(Boost 1.60 COMPONENTS unit_test_framework REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(tests)
