cmake_minimum_required(VERSION 3.10)
project(cmake-example)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加子项目
add_subdirectory(src/packageA)
add_subdirectory(src/packageB)
