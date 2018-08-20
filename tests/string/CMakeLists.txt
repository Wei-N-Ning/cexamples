
add_tinytest_executable(string_strstr strstr.c)
add_test(
    NAME
    "string::strstr"
    COMMAND
    strstr
)
