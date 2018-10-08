set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(HEADERS
    src/document.h
    src/pdf_reader.h
)

set(SOURCES
    src/document.cpp
    src/main.cpp
    src/pdf_reader.cpp
)

add_definitions(
    -DQT_DEPRECATED_WARNINGS
)

list(APPEND RESOURCES resources/resources.qrc)

qt5_add_resources(RSOURCES ${RESOURCES})

set(FORMS
    src/pdf_reader.ui
)

qt5_wrap_ui(FORM_UI ${FORMS})

add_executable(pdf_reader ${SOURCES} ${RESOURCES} ${FORM_UI})

include_directories(src)

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    include_directories(${CMAKE_BINARY_DIR}/src/mupdf_wrapper/release/)
endif()

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
    include_directories(${CMAKE_BINARY_DIR}/src/mupdf_wrapper/debug/)
endif()

include_directories(${CMAKE_BINARY_DIR}/src/mupdf_wrapper/include)

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    include_directories(${CMAKE_BINARY_DIR}/lib/mupdf/build/debug/)
endif()

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
    include_directories(${CMAKE_BINARY_DIR}/lib/mupdf/build/release/)
endif()

if (UNIX)
    include_directories(${CMAKE_BINARY_DIR}/lib/mupdf/build/)
endif()

target_link_libraries(pdf_reader PUBLIC
    mupdf
    mupdf-third
    mupdf_wrapper
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)


