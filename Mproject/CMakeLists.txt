cmake_minimum_required(VERSION 3.27)
project(Mproject)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(SOURCE_FILES main.cpp mazeGraph.h mazeGraph.cpp mazeNode.cpp mazeNode.h mazeEdge.cpp mazeEdge.h intPair.cpp intPair.h )
add_executable(
        Mproject
        main.cpp
        intPair.cpp
        mazeEdge.h
        mazeGraph.h
        mazeEdge.cpp
        mazeGraph.cpp
        mazeNode.h
        mazeNode.cpp
        mazeGraph.cpp
)

