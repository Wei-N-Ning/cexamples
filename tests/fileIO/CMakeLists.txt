
add_tinytest_executable(readlines readlines.c)
target_link_libraries(readlines testdata fileIO)
add_test(NAME "fileIO::readlines" COMMAND readlines)

add_tinytest_executable(freadTest test_fread.c)
target_link_libraries(freadTest testdata)
add_test(NAME "fileIO::freadTest" COMMAND freadTest)

add_tinytest_executable(fseekTest test_fseek.c)
target_link_libraries(fseekTest fileIO testdata)
add_test(NAME "fileIO::fseekTest" COMMAND fseekTest)
