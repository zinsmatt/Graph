cmake_minimum_required(VERSION 2.8)

project(graph2D)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt5.5.0/5.5/gcc_64)
find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


include_directories(include ../graph_kernel/include)


file(GLOB_RECURSE sources_files
    src/*
    include/*
    main.cpp
    ui/*.ui
)


qt5_wrap_ui(ui_files ui/mainwindow.ui)

# Find the QtWidgets library


# Use the Widgets module from Qt 5.
add_library(${PROJECT_NAME} STATIC ${sources_files} ${ui_files})
target_link_libraries(${PROJECT_NAME}  Qt5::Widgets)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/../bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE})



add_executable(main main.cpp)

target_link_libraries(main graph2D)
link_directories(${CMAKE_SOURCE_DIR}/../bin/${PROJECT_NAME}/${CMAKE_BUILD_TYPE})
#install(TARGETS main DESTINATION ${CMAKE_SOURCE_DIR}/../bin/main/${CMAKE_BUILD_TYPE})

