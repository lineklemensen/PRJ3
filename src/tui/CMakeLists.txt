cmake_minimum_required(VERSION 3.30)
project(tui)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Werror)

include_directories(${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/Elements
        ${CMAKE_SOURCE_DIR}/include/Enums
        ${CMAKE_SOURCE_DIR}/include/Screens)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_executable(tui ${SRC_FILES} ${HEADER_FILES})

set(MESON_PATH "C:/Program Files/Meson/meson.exe")
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1.12.0)
FetchContent_MakeAvailable(cpr)

target_link_libraries(tui PRIVATE cpr::cpr)
