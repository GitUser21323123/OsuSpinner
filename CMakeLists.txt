cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

# Header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files (*.cpp)
file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Compile and link
add_executable(zoomzoom main.cpp ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


