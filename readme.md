# pdf_reader
[![CircleCI](https://circleci.com/gh/antonioborondo/pdf_reader.svg?style=svg)](https://circleci.com/gh/antonioborondo/pdf_reader)

![Screenshot](resources/screenshot.png?raw=true)

## Features
- Open PDF documents.
- Page navigation.

## Windows (MinGW 64-bit)
1. Install MSYS2: http://www.msys2.org
1. Run `mingw64.exe`
1. Install packages:
    ```
    pacman -S git mingw-w64-x86_64-cmake make mingw-w64-x86_64-make mingw-w64-x86_64-gcc mingw-w64-x86_64-qt5
    ```
    NOTE: Recommended packages for development are the following:
    ```
    pacman -S git mingw-w64-x86_64-cmake make mingw-w64-x86_64-make mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb mingw-w64-x86_64-qt-creator
    ```
1. Clone repository
1. Configure, build and test project:
    ```
    mkdir pdf_reader_cmake/
    cd pdf_reader_cmake/
    cmake -G "MinGW Makefiles" -DCMAKE_SH=CMAKE_SH-NOTFOUND ../pdf_reader
    cmake --build .
    ctest -V
    ```
1. Run application:
    ```
    cd bin/
    ./pdf_reader.exe
    ```
