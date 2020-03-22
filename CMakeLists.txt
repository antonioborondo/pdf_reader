cmake_minimum_required(VERSION 3.12)

project(pdf_reader)

set(CMAKE_CXX_STANDARD 17)

set(BINARY_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})

enable_testing()

##### Conan #####
set(CONAN_CMAKE ${CMAKE_BINARY_DIR}/conan.cmake)

if(NOT EXISTS ${CONAN_CMAKE})
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop/conan.cmake" ${CONAN_CMAKE})
endif()

include(${CONAN_CMAKE})

conan_cmake_run(
    REQUIRES
    Catch2/2.11.3@catchorg/stable
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)
##### Conan #####

add_subdirectory(src/mupdf_wrapper)
add_subdirectory(src/pdf_reader)
