cmake_minimum_required(VERSION 2.8)

project(graph_kernel)
SET(BUILD_STATIC "build_static" CACHE BOOL "Build library in static")
SET(BUILD_SHARED "build_shared" CACHE BOOL "Build library in shared")

include_directories(include)

file(GLOB_RECURSE sources_files
     src/*
     include/*)


if(${BUILD_STATIC})
    add_library(${PROJECT_NAME}_static STATIC ${sources_files})
    install(TARGETS ${PROJECT_NAME}_static DESTINATION ${CMAKE_SOURCE_DIR}/../bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE})
    set_target_properties(${PROJECT_NAME}_static  PROPERTIES OUTPUT_NAME ${PROJECT_NAME} )
endif(${BUILD_STATIC})

if(${BUILD_SHARED})
    add_library(${PROJECT_NAME} SHARED ${sources_files})
    install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/../bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE})
endif(${BUILD_SHARED})



