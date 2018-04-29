cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME TerrainExplorer)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(
        PROJECT_SOURCES
        ${SRC_DIR}/engine/Game.h
        ${SRC_DIR}/engine/Game.cpp
        ${SRC_DIR}/engine/Engine.h
        ${SRC_DIR}/engine/render/AbstractRenderer.h
        ${SRC_DIR}/engine/render/SimpleRenderer.h
        ${SRC_DIR}/engine/render/SimpleRenderer.cpp
        ${SRC_DIR}/engine/render/Camera.h
        ${SRC_DIR}/engine/render/Camera.cpp
        ${SRC_DIR}/engine/render/Mesh.h
        ${SRC_DIR}/engine/render/Mesh.cpp
        ${SRC_DIR}/engine/render/Model.h
        ${SRC_DIR}/engine/render/Model.cpp
        ${SRC_DIR}/engine/render/ShaderProgram.h
        ${SRC_DIR}/engine/render/ShaderProgram.cpp
        ${SRC_DIR}/engine/render/Vertex.h
        ${SRC_DIR}/engine/terrain/Heightmap.h
        ${SRC_DIR}/engine/terrain/HeightmapRing.h
        ${SRC_DIR}/engine/texture/Texture.h
        ${SRC_DIR}/engine/texture/Texture.cpp
        ${SRC_DIR}/engine/texture/TextureArray.h
        ${SRC_DIR}/engine/texture/TextureArray.cpp
        ${SRC_DIR}/engine/texture/SimpleTexture.h
        ${SRC_DIR}/engine/texture/SimpleTexture.cpp
        ${SRC_DIR}/game/Explorer.h
        ${SRC_DIR}/game/Explorer.cpp
        ${SRC_DIR}/game/terrain/Terrain.h
        ${SRC_DIR}/game/terrain/SimpleTerrainRenderer.h
        ${SRC_DIR}/game/terrain/SimpleTerrainRenderer.cpp
        ${SRC_DIR}/game/terrain/TerrainGenerator.h
        ${SRC_DIR}/game/terrain/TerrainGenerator.cpp
        ${SRC_DIR}/game/terrain/SimpleTerrain.h
        ${SRC_DIR}/game/terrain/SimpleTerrain.cpp
        ${SRC_DIR}/game/terrain/HeightmapTerrain.cpp
        ${SRC_DIR}/game/terrain/HeightmapTerrain.h
        ${SRC_DIR}/game/terrain/SimpleHeightmap.cpp
        ${SRC_DIR}/game/terrain/SimpleHeightmap.h
        ${SRC_DIR}/game/terrain/SimpleHeightmapRing.cpp
        ${SRC_DIR}/game/terrain/SimpleHeightmapRing.h
        ${SRC_DIR}/util/Log.h
        ${SRC_DIR}/util/FileUtils.hpp
        ${SRC_DIR}/util/MathUtils.hpp
        ${SRC_DIR}/Main.cpp
        src/game/terrain/HeightmapRenderer.cpp src/game/terrain/HeightmapRenderer.h)

#file(GLOB_RECURSE PROJECT_SOURCES RELATIVE ${SRC_DIR} *.h *.hpp *.cpp *.cxx)

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
add_subdirectory(${STB_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${STB_DIR})
target_link_libraries(${PROJECT_NAME} "stb" ${CMAKE_DL_LIBS})

#FastNoise
set(FAST_NOISE_DIR ${LIBS}/FastNoise)
add_library("fastnoise" ${FAST_NOISE_DIR}/FastNoise.h ${FAST_NOISE_DIR}/FastNoise.cpp)

target_include_directories("fastnoise" PRIVATE ${FAST_NOISE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${FAST_NOISE_DIR})
target_link_libraries(${PROJECT_NAME} "fastnoise" ${CMAKE_DL_LIBS})

#glText
#set(GL_TEXT_DIR ${LIBS}/glText)
#add_library("gltext" ${GL_TEXT_DIR}/gltext.h)

#target_include_directories("gltext" PRIVATE ${GL_TEXT_DIR})
#target_include_directories(${PROJECT_NAME} PRIVATE ${GL_TEXT_DIR})
#target_link_libraries(${PROJECT_NAME} "gltext" ${CMAKE_DL_LIBS})

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)