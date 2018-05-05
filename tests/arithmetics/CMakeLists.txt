
add_tinytest_executable(roundingTest test_rounding.c)
target_link_libraries(roundingTest
    PUBLIC
    m)
add_test(NAME "arithmetics::rounding" COMMAND roundingTest)