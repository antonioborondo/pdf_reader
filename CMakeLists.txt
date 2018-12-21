cmake_minimum_required(VERSION 3.10)

project(pdf_reader)

set(CMAKE_CXX_STANDARD 14)

set(BINARY_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})

add_subdirectory(src/mupdf_wrapper)
add_subdirectory(src/pdf_reader)

enable_testing()

set(TEST_FILES_DIRECTORY ${CMAKE_SOURCE_DIR}/resources/test_files)
file(COPY ${TEST_FILES_DIRECTORY} DESTINATION ${BINARY_DIRECTORY})

add_test(NAME mupdf_wrapper_test COMMAND mupdf_wrapper_test WORKING_DIRECTORY ${BINARY_DIRECTORY})
