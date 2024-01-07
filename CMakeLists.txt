cmake_minimum_required(VERSION 3.28.1)
project(BWT2.0 LANGUAGES CXX)
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
add_executable(BWT2.0
    ${SRC})
