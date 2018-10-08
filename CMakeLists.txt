cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 14)

project(pdf_reader)

add_subdirectory(src/mupdf_wrapper)
add_subdirectory(src/pdf_reader)
