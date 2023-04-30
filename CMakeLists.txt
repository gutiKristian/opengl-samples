cmake_minimum_required(VERSION 3.25)
project(opengl_samples)

set(CMAKE_CXX_STANDARD 20)


add_executable(opengl_samples main.cpp
        core/Log.cpp core/Log.h
        core/Window.cpp core/Window.h core/Layer.h
        events/Event.h
        Application.cpp Application.h)


find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} glm::glm)
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad::glad)
