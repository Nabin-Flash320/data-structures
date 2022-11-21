
cmake_minimum_required(VERSION 3.15)

project(CIRCULAR_BUFFER)

add_executable(${PROJECT_NAME} main.c)
add_subdirectory(circular_buffer)
target_include_directories(${PROJECT_NAME} PUBLIC circular_buffer)
target_link_libraries(${PROJECT_NAME} cirbuf)





