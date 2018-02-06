cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME Explorer)
project(${PROJECT_NAME})

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(${SRC_DIR})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# GLFW
set(GLFW_DIR ${LIBS}/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_subdirectory(${GLFW_DIR})

target_link_libraries(${PROJECT_NAME} "glfw" ${GLFW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/include)

#GLAD
set(GLAD_DIR ${LIBS}/glad)
add_library("glad" ${GLAD_DIR}/src/glad.c)

target_include_directories("glad" PRIVATE ${GLAD_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)
target_link_libraries(${PROJECT_NAME} "glad" ${CMAKE_DL_LIBS})

#GLM
set(GLM_DIR ${LIBS}/glm)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLM_DIR})

#STB
set(STB_DIR ${LIBS}/stb-cmake)
target_include_directories(${PROJECT_NAME} PRIVATE ${STB_DIR})

#FastNoiseSIMD
#set(FAST_NOISE_SIMD_DIR ${LIBS}/FastNoiseSIMD)
#target_include_directories(${PROJECT_NAME} PRIVATE ${FAST_NOISE_SIMD_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)