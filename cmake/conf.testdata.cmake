
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/resources/testdata)
    message(FATAL_ERROR "Missing resources/testdata directory ")
endif()

function(copy_testdata_lib)
    get_filename_component(currentDir ${CMAKE_CURRENT_LIST_FILE} DIRECTORY)
    file(COPY ${currentDir}/testdata.h ${currentDir}/testdata.c
        DESTINATION ${PROJECT_BINARY_DIR}
        FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE)
endfunction()

copy_testdata_lib()

add_library(testdata STATIC ${PROJECT_BINARY_DIR}/testdata.c ${PROJECT_BINARY_DIR}/testdata.h)
target_compile_definitions(testdata
    PRIVATE
        TESTDATA_DIR="${CMAKE_SOURCE_DIR}/resources/testdata")
target_include_directories(testdata PUBLIC ${PROJECT_BINARY_DIR})
