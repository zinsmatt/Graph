cmake_minimum_required(VERSION 2.8)

project(Graph_main)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE})

include_directories(../graph_kernel/include)

file(GLOB_RECURSE sources_files
    src/*
    include/*)

add_executable(${PROJECT_NAME} ${sources_files})

target_link_libraries(${PROJECT_NAME} graph_kernel)

