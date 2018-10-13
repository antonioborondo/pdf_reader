cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

set(var_target mupdf_wrapper)
set(var_path_source src)
project(Prj_${var_target})

set(CMAKE_CXX_FLAGS "-pipe -fexceptions -pedantic -Wall -Wextra")

add_definitions(-DMUPDF_WRAPPER)
add_definitions(-DQT_DEPRECATED_WARNINGS)
find_package(Qt5 REQUIRED COMPONENTS Core)

include_directories(
    include/mupdf_wrapper
    ${CMAKE_CURRENT_LIST_DIR}/../../lib/mupdf/include
)
link_directories(
    ${CMAKE_CURRENT_LIST_DIR}/../../lib/mupdf/build/release
)

file(GLOB_RECURSE var_sources ${var_path_source}/*.cpp)
add_library(${var_target} SHARED ${var_sources})
target_link_libraries(${var_target} Qt5::Core mupdf mupdfthird)

install(TARGETS ${var_target} DESTINATION ${CMAKE_CURRENT_LIST_DIR}/build)
