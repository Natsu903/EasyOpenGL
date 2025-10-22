add_library(applicationLib STATIC 
    application.cpp
    application.h
)

target_include_directories(applicationLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

