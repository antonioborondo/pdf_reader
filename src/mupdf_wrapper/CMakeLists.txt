find_package(Qt5Core REQUIRED)

set(MUPDF_WRAPPER_HDRS
    include/mupdf_wrapper/context.h
    include/mupdf_wrapper/document.h
    include/mupdf_wrapper/matrix.h
    include/mupdf_wrapper/mupdf_wrapper.h
    include/mupdf_wrapper/pixmap.h
)

set(MUPDF_WRAPPER_SRCS
    src/context.cpp
    src/document.cpp
    src/matrix.cpp
    src/pixmap.cpp
)

add_library(mupdf_wrapper SHARED ${MUPDF_WRAPPER_SRCS})

add_definitions(
    -DMUPDF_WRAPPER
    -DQT_DEPRECATED_WARNINGS
)

include_directories(
    include/mupdf_wrapper
    ${CMAKE_BINARY_DIR}/lib/mupdf/include
)

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    include_directories(${CMAKE_BINARY_DIR}/lib/mupdf/build/debug/)
endif()

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
    include_directories(${CMAKE_BINARY_DIR}/lib/mupdf/build/release/)
endif()

if (UNIX)
    include_directories(${CMAKE_BINARY_DIR}/lib/mupdf/build/)
endif()

target_link_libraries(mupdf_wrapper PUBLIC
    mupdf
    mupdf-third
    Qt5::Core
)
