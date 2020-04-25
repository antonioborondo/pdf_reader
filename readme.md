# pdf_reader
[![Build Status](https://travis-ci.com/antonioborondo/pdf_reader.svg?branch=master)](https://travis-ci.com/antonioborondo/pdf_reader)

![Screenshot](screenshot.png?raw=true)

## Description
Cross-platform PDF reader.

## Features
- UI implemented with Qt.
- PDF rendering implemented with MuPDF (mupdf_wrapper).
- CI implemented with Travis CI.

## Libraries
- mupdf_wrapper: https://www.github.com/antonioborondo/mupdf_wrapper
- Qt: https://www.qt.io

## Tools
- CMake: https://www.cmake.org
- Travis CI: https://www.travis-ci.com

## Resources
- elementary OS icons: https://www.github.com/elementary/icons

## How to build on Windows (MinGW 64-bit)
1. Install MSYS2 x86_64: https://www.msys2.org
1. Run `mingw64.exe`
1. Install packages:
    ```
    pacman -S git make mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-qt5
    ```
    NOTE: Recommended extra packages for development:
    ```
    pacman -S mingw-w64-x86_64-gdb mingw-w64-x86_64-qt-creator
    ```
1. Clone repository.
1. Update submodules:
    ```
    git submodule update --init --recursive
    ```
1. Configure and build:
    ```
    mkdir build
    cd build
    cmake -G "MinGW Makefiles" -DCMAKE_SH=CMAKE_SH-NOTFOUND -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .
    ```
