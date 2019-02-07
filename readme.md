# pdf_reader
[![CircleCI](https://circleci.com/gh/antonioborondo/pdf_reader.svg?style=svg)](https://circleci.com/gh/antonioborondo/pdf_reader)

![Screenshot](resources/screenshot.png?raw=true)

## Features
- Open PDF documents.
- Page navigation.

## Windows (MinGW 64-bit)
1. Install MSYS2: http://www.msys2.org
1. Execute `mingw64.exe`
1. Install the packages required:
    ```
    pacman -S git mingw-w64-x86_64-cmake make mingw-w64-x86_64-gcc mingw-w64-x86_64-qt5
    ```
1. Clone the repository:
    ```
    git clone git@github.com:antonioborondo/pdf_reader.git
    ```
1. Configure, build and test the project:
    ```
    mkdir pdf_reader_cmake/
    cd pdf_reader_cmake/
    cmake -G "MinGW Makefiles" -DCMAKE_SH=CMAKE_SH-NOTFOUND ../pdf_reader
    cmake --build .
    ctest -V
    ```
1. Start the application:
    ```
    cd bin
    ./pdf_reader.exe
    ```
