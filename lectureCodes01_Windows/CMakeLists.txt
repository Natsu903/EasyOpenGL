cmake_minimum_required(VERSION 3.12)

project(Graphic)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(application)

add_executable(softRenderer main.cpp)

target_link_libraries(softRenderer applicationLib)