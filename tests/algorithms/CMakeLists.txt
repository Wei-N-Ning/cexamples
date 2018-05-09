# for more algo and data structure examples see cci solutions
# this sub project is to use existing C standard library
# algorithm functions

add_tinytest_executable(sortingTests test_sorting.c)
add_test(NAME "algorithm::sorting" COMMAND sortingTests)

add_library(randTestIntel SHARED randomNumber/rand_intel.c)
add_library(randTestOrigLCG SHARED randomNumber/rand_orig_LCG.c)
