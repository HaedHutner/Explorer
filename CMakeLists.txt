cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME Explorer)
project(${PROJECT_NAME})

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_SOURCES ${SRC_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)