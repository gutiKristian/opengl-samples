cmake_minimum_required(VERSION 3.25)
project(Dunno)

set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE SOURCES "core/*.cpp" "glutil/*.cpp" "core/*.h" "glutil/*.h")

add_library(Dunno ${SOURCES})

target_include_directories(Dunno PUBLIC .)

target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} glm::glm)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad::glad)
