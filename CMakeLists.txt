cmake_minimum_required(VERSION 3.10)

project(pdf_reader)

set(CMAKE_CXX_STANDARD 14)

set(BINARY_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})

##### Catch2 #####
set(CATCH2_LIBRARY ${CMAKE_CURRENT_BINARY_DIR}/lib/catch2/include/catch2/catch.hpp)

if(NOT EXISTS ${CATCH2_LIBRARY})
    message(STATUS "Downloading Catch2 from https://github.com/catchorg/Catch2")
    file(DOWNLOAD "https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp" ${CATCH2_LIBRARY})
endif()

add_library(catch2 INTERFACE)

target_include_directories(catch2 INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/lib/catch2/include)
##### Catch2 #####

add_subdirectory(src/mupdf_wrapper)
add_subdirectory(src/pdf_reader)

##### CTest #####
enable_testing()

set(TEST_FILES_DIRECTORY ${CMAKE_SOURCE_DIR}/test_files)
file(COPY ${TEST_FILES_DIRECTORY} DESTINATION ${BINARY_DIRECTORY})

add_test(NAME mupdf_wrapper_test COMMAND mupdf_wrapper_test WORKING_DIRECTORY ${BINARY_DIRECTORY})
##### CTest #####
