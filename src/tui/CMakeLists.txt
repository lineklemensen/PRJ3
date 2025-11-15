cmake_minimum_required(VERSION 3.30)
project(tui)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/Elements
        ${CMAKE_SOURCE_DIR}/include/Enums)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(tui ${SRC_FILES})
