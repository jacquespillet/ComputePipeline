cmake_minimum_required(VERSION 3.10)

project(ComputePipeline)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SRC_CODE 
    src/ComputePipeline.cpp
    src/Loader.cpp
    src/Action.cpp
    main.cpp)

add_executable(ComputePipeline ${SRC_CODE})