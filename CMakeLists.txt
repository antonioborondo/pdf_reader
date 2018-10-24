cmake_minimum_required(VERSION 3.10)

project(pdf_reader)

set(CMAKE_CXX_STANDARD 14)

set(BINARY_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})

add_subdirectory(src/mupdf_wrapper)
add_subdirectory(src/pdf_reader)
