file(GLOB_RECURSE SOURCE  "${CMAKE_SOURCE_DIR}/Rikka/*.cpp")

add_library(Rikka STATIC ${SOURCE})

target_link_libraries(Rikka PRIVATE GLEW GL GLU m glfw X11)
