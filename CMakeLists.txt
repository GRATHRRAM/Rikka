cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Rikka VERSION 1.0)

add_compile_options(-Wall -Wextra -Wno-sequence-point -g)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/Rikka)
add_subdirectory(${CMAKE_SOURCE_DIR}/Demos)
