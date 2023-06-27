cmake_minimum_required(VERSION 3.25)
project(CrossRoad)

set(CMAKE_CXX_STANDARD 20)


add_executable(${PROJECT_NAME} main.cpp CrossRoadLayer.cpp CrossRoadLayer.h)
target_link_libraries(${PROJECT_NAME} Dunno)

