# PDF reader
## Prepare the repository
Clone the repository and run the following command to initialize the submodules:
```
git submodule update --init --recursive
```
## Compile muPDF library
1. Install MSYS2: http://www.msys2.org
1. Run "MSYS2 MinGW 32-bit" (mingw32.exe).
1. Run the following command to install the toolchain:
    ```
    pacman -S make gcc
    ```
1. Run the following commands to build muPDF:
    ```
    cd lib/mupdf/
    make build=debug HAVE_X11=no HAVE_GLUT=no -j8 libs
    make HAVE_X11=no HAVE_GLUT=no -j8 libs
    ```
