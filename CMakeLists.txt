cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RikkaEngine VERSION 1.0)

if(WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "")
  set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif()

add_compile_options(-Wall -Wextra)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/DependenciesSrc/glfw-3.4/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/DependenciesSrc)
add_subdirectory(${CMAKE_SOURCE_DIR}/RikkaEngineSrc)
add_subdirectory(${CMAKE_SOURCE_DIR}/Demos)