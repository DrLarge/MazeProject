cmake_minimum_required(VERSION 3.27)
project(Mproject
        VERSION 1.0
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
        
add_library(MyLib mazeGraph.h mazeGraph.cpp mazeNode.cpp mazeNode.h mazeEdge.cpp mazeEdge.h intPair.cpp intPair.h)
add_executable(Mproject main.cpp)
target_link_libraries(Mpoject PRIVATE MyLib)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
