
add_tinytest_executable(loadTestData testdata/test_load.c)
target_link_libraries(loadTestData testdata)

add_subdirectory(memory)
