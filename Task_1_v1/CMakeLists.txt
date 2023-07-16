cmake_minimum_required(VERSION 3.5)

project(Task_3_v1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        style.h
        style.cpp
        mainwindow.ui
)

add_executable(Task_3_v1
               ${PROJECT_SOURCES})

target_link_libraries(Task_3_v1 PRIVATE Qt6::Widgets)
