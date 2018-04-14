
add_tinytest_executable(mmap mmap.c)
target_link_libraries(mmap testdata)
add_test(NAME "memory::mmap" COMMAND mmap)

add_tinytest_executable(structPacking structPacking.c)
target_link_libraries(structPacking testdata)
add_test(NAME "memory::structPacking" COMMAND structPacking)

add_tinytest_executable(funcPtr funcPtr.c)
add_test(NAME "memory::funcPtr" COMMAND funcPtr)

