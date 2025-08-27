add_executable(Demo1 Demo1.cpp)

target_link_libraries(Demo1 PRIVATE Rikka)
target_include_directories(Demo1 PRIVATE ${CMAKE_SOURCE_DIR}/Rikka)
