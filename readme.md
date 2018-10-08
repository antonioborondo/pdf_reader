# PDF reader
![Screenshot](resources/screenshot.png?raw=true)

## Features
- Open PDF documents.
- Page navigation controls.

## Prepare the repository
Clone the repository and run the following command to initialize the submodules:
```
git submodule update --init --recursive
```
## Install the toolchain (MinGW 64-bit)
1. Install MSYS2: http://www.msys2.org
1. Run "MSYS2 MinGW 64-bit" (mingw64.exe).
1. Run the following command to install the toolchain:
```
pacman -S make mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb mingw-w64-x86_64-qt-creator
```
## Compile muPDF library
Run the following commands to build muPDF:
```
cd lib/mupdf/
make build=debug HAVE_X11=no HAVE_GLUT=no -j8 libs
make HAVE_X11=no HAVE_GLUT=no -j8 libs
```
## Compile PDF reader
```
mkdir pdf_reader_cmake/
cd pdf_reader_cmake/
cmake -G "MinGW Makefiles" -DCMAKE_SH=CMAKE_SH-NOTFOUND -DCMAKE_PREFIX_PATH=<MSYS2_INSTALLATION_PATH>/mingw64 -DCMAKE_C_COMPILER=<MSYS2_INSTALLATION_PATH>/mingw64/bin/cc.exe -DCMAKE_CXX_COMPILER=<MSYS2_INSTALLATION_PATH>/mingw64/bin/c++.exe ../pdf_reader
cmake --build .
```
