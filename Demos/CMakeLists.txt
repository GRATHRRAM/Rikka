add_executable(Demo1 Demo1.cpp)
add_executable(Demo2 Demo2.cpp)

target_link_libraries(Demo1 PRIVATE Rikka)
target_link_libraries(Demo2 PRIVATE Rikka)
target_include_directories(Demo1 PRIVATE ${CMAKE_SOURCE_DIR}/Rikka)
target_include_directories(Demo2 PRIVATE ${CMAKE_SOURCE_DIR}/Rikka)
