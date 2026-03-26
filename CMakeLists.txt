cmake_minimum_required(VERSION 3.10)

project(VoxelGame LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

# GLAD
add_library(glad STATIC)
target_sources(glad PRIVATE external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# App
add_executable(app ${SRC_FILES})

target_link_libraries(app PRIVATE glfw OpenGL::GL glad)
