cmake_minimum_required(VERSION 2.8)
project(fast-cpp-csv-parser CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CTest)

include(ClangFormat)
include(CppCheck)

find_package(Boost 1.59 COMPONENTS unit_test_framework REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++1y")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(tests)
