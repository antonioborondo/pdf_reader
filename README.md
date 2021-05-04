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
- mupdf_wrapper: https://github.com/antonioborondo/mupdf_wrapper
- Qt: https://qt.io

## Tools
- CMake: https://cmake.org
- Travis CI: https://travis-ci.com

## Resources
- elementary OS icons: https://github.com/elementary/icons

## How to build on Windows (MinGW 64-bit)
1. Install MSYS2 x86_64: https://msys2.org
1. Open "MSYS2 MinGW 64-bit".
1. Install packages:
    ```
    pacman -S git make mingw-w64-x86_64-cmake mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-qt5
    ```
1. Clone the repository and update submodules:
    ```
    git clone --recurse-submodules git@github.com:antonioborondo/pdf_reader.git && cd pdf_reader
    ```
1. Configure and build:
    ```
    mkdir build && cd build
    cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .
    ```
