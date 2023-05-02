cmake_minimum_required(VERSION 3.17)

project(Collections)

add_library(collectionsLib STATIC collections.cpp)

include(FetchContent)
FetchContent_Declare(googletest GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG v1.13.0)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endIf()

add_executable(app main.cpp)
target_link_libraries(app collectionsLib)

add_executable(test test.cpp)
target_link_libraries(test collectionsLib gtest_main gmock_main)

