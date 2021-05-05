cmake_minimum_required(VERSION 3.16)

project(pdf_reader)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/mupdf_wrapper)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(pdf_reader
    src/document.h
    src/document.cpp
    src/main.cpp
    src/pdf_reader.cpp
    src/pdf_reader.h
    src/pdf_reader.qrc
    src/pdf_reader.ui
    src/single_page_view.h
    src/single_page_view.cpp
)

target_link_libraries(pdf_reader
    PRIVATE
    mupdf_wrapper
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    stdc++fs
)
