cmake_minimum_required(VERSION 3.0.0)
project(hello_window VERSION 1.0.0)

find_package(OpenGL REQUIRED)

add_executable( hello_window 
    src/config.h 
    src/main.cpp 
    src/glad.c
)

target_include_directories(hello_window PRIVATE dependencies)

# Tell CMake where the GLFW .lib file is
target_link_directories(hello_window PRIVATE dependencies/glfw/lib-vc2022)
target_link_libraries(hello_window glfw3)

set_property(TARGET hello_window PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")