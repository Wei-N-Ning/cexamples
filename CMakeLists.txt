cmake_minimum_required(VERSION 3.5)
project(CExamples)

enable_testing()
include(cmake/tinyCUnit.cmake)

add_subdirectory(src)
add_subdirectory(tests)
