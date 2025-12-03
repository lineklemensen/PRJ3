cmake_minimum_required(VERSION 3.30)
project(tui)

set(CMAKE_CXX_STANDARD 20)
#add_compile_options(-Wall -Wextra -Werror)


include_directories(${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include/Elements
        ${CMAKE_SOURCE_DIR}/include/Enums
        ${CMAKE_SOURCE_DIR}/include/HTTP
        ${CMAKE_SOURCE_DIR}/include/Screens
        ${CMAKE_SOURCE_DIR}/external
        ${CMAKE_SOURCE_DIR}/../rpi2/external/json_dto
        ${CMAKE_SOURCE_DIR}/../rpi2/external/rapidjson)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_executable(tui ${SRC_FILES} ${HEADER_FILES})