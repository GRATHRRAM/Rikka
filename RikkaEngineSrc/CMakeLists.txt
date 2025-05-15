file(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

Message(STATUS "Copying Header Files")
file(REMOVE_RECURSE "${CMAKE_CURRENT_BINARY_DIR}/include/Rikka")
file(REMOVE_RECURSE "${CMAKE_SOURCE_DIR}/include/Rikka")

file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/Rikka")
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/include/Rikka")

foreach(HEADER_FILE ${HEADER_FILES})
    get_filename_component(REL_PATH "${HEADER_FILE}" DIRECTORY)
    file(RELATIVE_PATH REL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" "${REL_PATH}")

    set(DEST_FILE "${CMAKE_CURRENT_BINARY_DIR}/include/Rikka/${REL_PATH}")
    file(MAKE_DIRECTORY "${DEST_FILE}/..")
    file(COPY "${HEADER_FILE}" DESTINATION "${DEST_FILE}")

    set(DEST_FILE "${CMAKE_SOURCE_DIR}/include/Rikka/${REL_PATH}")
    file(MAKE_DIRECTORY "${DEST_FILE}/..")
    file(COPY "${HEADER_FILE}" DESTINATION "${DEST_FILE}")
endforeach()

add_library(Rikka SHARED ${SOURCE})

target_link_libraries(Rikka glfw3 opengl32 gdi32)