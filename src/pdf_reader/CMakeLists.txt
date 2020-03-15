project(pdf_reader)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES_DIRECTORY src)

set(SOURCE_FILES
    ${SOURCE_FILES_DIRECTORY}/document.h
    ${SOURCE_FILES_DIRECTORY}/document.cpp
    ${SOURCE_FILES_DIRECTORY}/main.cpp
    ${SOURCE_FILES_DIRECTORY}/pdf_reader.cpp
    ${SOURCE_FILES_DIRECTORY}/pdf_reader.h
)

set(FORM_FILES
    ${SOURCE_FILES_DIRECTORY}/pdf_reader.ui
)

set(RESOURCE_FILES
    ${SOURCE_FILES_DIRECTORY}/pdf_reader.qrc
)

add_executable(pdf_reader
    ${SOURCE_FILES}
    ${FORM_FILES}
    ${RESOURCE_FILES}
)

add_definitions(
    -DQT_DEPRECATED_WARNINGS
)

target_link_libraries(pdf_reader
    PRIVATE
    mupdf_wrapper
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    stdc++fs
)
