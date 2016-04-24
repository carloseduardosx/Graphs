cmake_minimum_required(VERSION 3.3)
project(Graphs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/main.cpp
        src/model/impl/Graph.cpp
        src/model/Graph.h
        src/model/impl/Vertex.cpp
        src/model/Vertex.h
        src/model/impl/Corner.cpp
        src/model/Corner.h
        src/model/impl/Adjacency.cpp
        src/model/Adjacency.h
        src/controller/impl/GraphController.cpp
        src/controller/GraphController.h)

add_executable(Graphs ${SOURCE_FILES})