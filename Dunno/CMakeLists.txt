cmake_minimum_required(VERSION 3.25)
project(Dunno)

set(CMAKE_CXX_STANDARD 20)


add_library(Dunno
        core/Log.cpp
        core/Window.cpp
        core/Event.h
        core/Layer.h
        core/Application.cpp glutil/Shader.cpp glutil/Shader.h)

target_include_directories(Dunno PUBLIC .)

target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} glm::glm)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad::glad)
