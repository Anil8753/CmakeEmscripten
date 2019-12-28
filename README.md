This is a starter project to build the C++ source to Web Assembly (WASM) with the Emscripten tool chain.
Actually we can build C++ files to WASM with Emscripten only.

emcc -o build\main.js file1.cpp file2.cpp

But managing the large project will be difficult. For a large project CMake build system helps a lot. This starter project uses the emscripten on top of the CMake project. It also allows us to build existing CMake projects with much changes.

Details: https://emscripten.org/docs/compiling/Building-Projects.html


Setup environment

    1. open bash
    2. go to emsdk directorty and followings run command
        ./emsdk activate latest
        source ./emsdk_env.sh

Build setup

    3. create directory 'cmake_test' 
        mkdir build
        cd build

    4. clear dirctory if needed
        go to build directory and run
        rm -rf *

    5. configure cmake
        emconfigure cmake .. 

    6. build the source to wasm
        emmake make
