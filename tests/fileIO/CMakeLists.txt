
add_tinytest_executable(readlines readlines.c)
target_link_libraries(readlines testdata fileIO)
add_test(NAME "fileIO::readlines" COMMAND readlines)

