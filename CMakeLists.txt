#指定Cmake版本
cmake_minimum_required(VERSION 3.28.1)
project(bwt LANGUAGES CXX)
#指定C++11新特性
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#搜索源文件和头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
#生成可执行文件
add_executable(bwt
    ${SRC})
