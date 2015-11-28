cmake_minimum_required(VERSION 2.8)

project(Graph_kernel)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE})

include_directories(include)

file(GLOB_RECURSE sources_files
     src/*
     include/*)

add_library(graph_kernel STATIC ${sources_files})


