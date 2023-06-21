cmake_minimum_required(VERSION 3.25)
project(ExampleApp)

set(CMAKE_CXX_STANDARD 20)


add_executable(${PROJECT_NAME} main.cpp ExampleApp.cpp)
target_link_libraries(${PROJECT_NAME} Dunno)

