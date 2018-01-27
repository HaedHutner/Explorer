cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME Explorer)
project(${PROJECT_NAME})

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_SOURCES ${SRC_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# GLFW
set(GLFW_DIR ${LIBS}/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_subdirectory(${GLFW_DIR})

#GLEW
set(GLEW_DIR ${LIBS}/glew)
add_subdirectory(${GLEW_DIR})

target_link_libraries(${PROJECT_NAME} "glfw" ${GLFW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/include)

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)