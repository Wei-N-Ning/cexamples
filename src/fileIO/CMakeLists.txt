
add_library(fileIO STATIC
    loadFile.h

    loadFile.c)
target_include_directories(fileIO
    PUBLIC
    .)

