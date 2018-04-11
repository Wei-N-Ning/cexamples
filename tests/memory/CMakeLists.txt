
add_tinytest_executable(mmap mmap.c)
add_test(NAME "memory::mmap" COMMAND mmap)
