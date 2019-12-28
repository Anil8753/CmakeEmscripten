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