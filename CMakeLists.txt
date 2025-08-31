cmake_minimum_required(VERSION 3.10)
project(project-example)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加子项目
add_subdirectory(cmake-ros2-example/src/packageA)
add_subdirectory(cmake-ros2-example/src/packageB)
