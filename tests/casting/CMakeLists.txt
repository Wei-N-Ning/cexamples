

add_tinytest_executable(casting_set_float set_float.c)
add_test(
    NAME
    "casting::set-float"
    COMMAND
    casting_set_float
)