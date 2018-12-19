cmake_minimum_required(VERSION 3.13)
project(SimVizDemo)

add_subdirectory(libraries/glfw)
include_directories(libraries/glfw/include)

set(CMAKE_CXX_STANDARD 17)

add_library(SimViz STATIC exceptions/GlfwException.cpp exceptions/GlfwException.h SimViz.cpp SimViz.h)
target_link_libraries(SimViz glfw ${GLFW_LIBRARIES})

add_executable(SimVizDemo ../SimVizDemo/main.cpp)
target_link_libraries(SimVizDemo SimViz)
