# Set the minimum CMake version
cmake_minimum_required(VERSION 3.10)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${PROJECT_NAME} VERSION 0.1 LANGUAGES ASM C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_FLAGS_DEBUG     "-O0 -g3 --coverage -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3 --coverage -DDEBUG")

set(CMAKE_C_FLAGS_RELEASE   "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_executable(${PROJECT_NAME} ./test/test_ring_buffer.c)
target_sources(${PROJECT_NAME} PRIVATE ./src/ring_buffer.c)
target_include_directories(${PROJECT_NAME} PRIVATE ./include)

target_link_libraries(${PROJECT_NAME} gcov)