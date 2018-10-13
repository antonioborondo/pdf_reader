cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

set(var_target pdf_reader)
set(var_path_source src)
project(Prj_${var_target})

set(CMAKE_CXX_FLAGS "-pipe -fexceptions -pedantic -Wall -Wextra")

add_definitions(-DQT_DEPRECATED_WARNINGS)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
QT5_ADD_RESOURCES(RES_SOURCES resources/resources.qrc)

include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/../mupdf_wrapper/include
    ${CMAKE_CURRENT_LIST_DIR}/../../lib/mupdf/include
)
link_directories(
    ${CMAKE_CURRENT_LIST_DIR}/../mupdf_wrapper/build
    ${CMAKE_CURRENT_LIST_DIR}/../../lib/mupdf/build/release
)

file(GLOB_RECURSE var_sources ${var_path_source}/*.cpp)
add_executable(${var_target} ${var_sources} ${RES_SOURCES} ${UI_HEADERS})
target_link_libraries(${var_target} Qt5::Core Qt5::Gui Qt5::Widgets mupdf mupdfthird mupdf_wrapper)

install(TARGETS ${var_target} DESTINATION ${CMAKE_CURRENT_LIST_DIR}/build)
