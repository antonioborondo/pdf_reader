project(pdf_reader)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(HEADER_FILES
    src/document.h
    src/pdf_reader.h
)

set(SOURCE_FILES
    src/document.cpp
    src/main.cpp
    src/pdf_reader.cpp
)

set(FORM_FILES
    src/pdf_reader.ui
)

set(RESOURCE_FILES
    resources/resources.qrc
)

add_executable(pdf_reader
    ${HEADER_FILES}
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
)
