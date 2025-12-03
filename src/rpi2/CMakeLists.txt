cmake_minimum_required(VERSION 3.30)
project(rpi2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

# llhttp sources (generated, shipped in external/llhttp)
set(LLHTTP_SRC
        ${CMAKE_SOURCE_DIR}/external/llhttp/api.c
        ${CMAKE_SOURCE_DIR}/external/llhttp/http.c
        ${CMAKE_SOURCE_DIR}/external/llhttp/llhttp.c
)

# Fix Windows API version warning - added later for remove warning
if (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0601)
endif()


add_definitions(-DFMT_HEADER_ONLY)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${LLHTTP_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/external
        ${CMAKE_SOURCE_DIR}/external/restinio
        ${CMAKE_SOURCE_DIR}/external/asio
        ${CMAKE_SOURCE_DIR}/external/fmt
        ${CMAKE_SOURCE_DIR}/external/json_dto
        ${CMAKE_SOURCE_DIR}/external/llhttp
        ${CMAKE_SOURCE_DIR}/external/expected-lite
        ${CMAKE_SOURCE_DIR}/external/rapidjson
)


# Link pthread (needed on Linux/Raspberry Pi)
target_link_libraries(${PROJECT_NAME} Threads::Threads)