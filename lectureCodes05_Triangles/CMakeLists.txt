cmake_minimum_required(VERSION 3.12)

project(Graphic)

set(CMAKE_CXX_STANDARD 17)

# Add UTF-8 support for MSVC
if(MSVC)
    add_compile_options(/utf-8)
endif()

add_subdirectory(application)
add_subdirectory(gpu)
add_subdirectory(math)

add_executable(softRenderer main.cpp)

target_link_libraries(softRenderer applicationLib gpuLib mathLib)