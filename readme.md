# Cross-platform PDF reader
[![Build Status](https://travis-ci.com/antonioborondo/pdf_reader.svg?branch=master)](https://travis-ci.com/antonioborondo/pdf_reader)

![Screenshot](screenshot.png?raw=true)

## Description
Cross-platform application to read PDF files.

## Features
- UI implemented with Qt.
- PDF rendering implemented with MuPDF.
- MuPDF fully integrated in CMake as an external project.
- MuPDF wrapped in a C++ library using the RAII technique.
- BDD unit tests implemented with Catch2.
- CI implemented with Travis CI.

## Libraries
- Catch2: https://www.github.com/catchorg/Catch2
- MuPDF: https://www.mupdf.com
- Qt: https://www.qt.io

## Tools
- CMake: https://www.cmake.org
- Travis CI: https://www.travis-ci.com

## Resources
- elementary OS icons: https://www.github.com/elementary/icons

## How to build
### Windows (MinGW 64-bit)
1. Install MSYS2 x86_64: https://www.msys2.org
1. Run `mingw64.exe`
1. Install packages:
    ```
    pacman -S git mingw-w64-x86_64-cmake make mingw-w64-x86_64-make mingw-w64-x86_64-gcc mingw-w64-x86_64-qt5
    ```
    NOTE: Recommended extra packages for development:
    ```
    pacman -S mingw-w64-x86_64-gdb mingw-w64-x86_64-qt-creator
    ```
1. Clone repository
1. Configure, build and test project:
    ```
    mkdir pdf_reader_cmake/
    cd pdf_reader_cmake/
    cmake -G "MinGW Makefiles" -DCMAKE_SH=CMAKE_SH-NOTFOUND ../pdf_reader
    cmake --build .
    ctest --verbose
    ```
1. Run application:
    ```
    cd bin/
    ./pdf_reader.exe
    ```

### Linux (Ubuntu 18.04 LTS 64-bit)
1. Install packages:
    ```
    sudo apt install git cmake g++ qt5-default
    ```
    NOTE: Recommended extra package for development:
    ```
    sudo apt install qtcreator
    ```
1. Clone repository
1. Configure, build and test project:
    ```
    mkdir pdf_reader_cmake/
    cd pdf_reader_cmake/
    cmake ../pdf_reader
    cmake --build .
    ctest --verbose
    ```
1. Run application:
    ```
    cd bin/
    ./pdf_reader
    ```
