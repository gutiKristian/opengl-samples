cmake_minimum_required(VERSION 3.25)
project(opengl-samples)

set(CMAKE_CXX_STANDARD 20)

find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/Dunno)
include_directories(${PROJECT_SOURCE_DIR}/ExampleApp)

add_subdirectory(Dunno)
add_subdirectory(ExampleApp)