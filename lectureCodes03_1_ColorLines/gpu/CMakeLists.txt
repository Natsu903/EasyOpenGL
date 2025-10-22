file(GLOB_RECURSE GPU ./ *.cpp)

add_library(gpuLib ${GPU})

target_include_directories(gpuLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)