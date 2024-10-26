## About

## Build Instructions

This project requires a C++ 20 compiler and CMake 3.17. It has dependencies in Raylib and Ffmpeg. Ffmpeg is installed using vcpkg. To build:


To install Ffmpeg with vcpkg in manifest mode, run:
```
vcpkg install
```

To build the project:
```
mkdir build
cd build
cmake .. 
make
```

