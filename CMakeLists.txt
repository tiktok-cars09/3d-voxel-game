cmake_minimum_required(VERSION 3.16)
project(voxel_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(voxel_demo
    src/main.cpp
)

if (TARGET SDL2::SDL2)
  target_link_libraries(voxel_demo PRIVATE SDL2::SDL2)
else()
  if (DEFINED SDL2_LIBRARIES)
    target_link_libraries(voxel_demo PRIVATE ${SDL2_LIBRARIES})
  endif()
  if (DEFINED SDL2_INCLUDE_DIRS)
    target_include_directories(voxel_demo PRIVATE ${SDL2_INCLUDE_DIRS})
  endif()
endif()

target_link_libraries(voxel_demo PRIVATE glad::glad glm::glm SDL2::SDL2)

target_compile_definitions(voxel_demo PRIVATE SDL_MAIN_HANDLED)

if (MSVC)
  target_compile_options(voxel_demo PRIVATE /W4 /WX-)
else()
  target_compile_options(voxel_demo PRIVATE -Wall -Wextra -Wpedantic)
endif()
