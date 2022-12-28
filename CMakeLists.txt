cmake_minimum_required(VERSION 3.14)

project(fifo)

set(CMAXE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/fifo.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/process.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/fifo.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/process.hpp
    )

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

# add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
