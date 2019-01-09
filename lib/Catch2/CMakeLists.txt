SET(single_include "${CMAKE_CURRENT_BINARY_DIR}/include/catch2/catch.hpp")

if(NOT EXISTS "${single_include}")
    message(STATUS "Downloading Catch2 from https://github.com/catchorg/Catch2")
    file(DOWNLOAD "https://raw.githubusercontent.com/catchorg/Catch2/master/single_include/catch2/catch.hpp" "${single_include}")
endif()

add_library(catch2 INTERFACE)

target_include_directories(catch2 INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/include)
