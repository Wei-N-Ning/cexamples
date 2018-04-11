
add_tinytest_executable(mmap mmap.c)
target_link_libraries(mmap testdata)
add_test(NAME "memory::mmap" COMMAND mmap)
