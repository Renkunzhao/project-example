cmake_minimum_required(VERSION 3.10)
project(packageB VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建可执行文件
add_executable(packageB src/packageB.cpp)

# 如果在同一个 super project 里，就直接用 add_subdirectory 提供的 target
if(TARGET packageA)
    target_link_libraries(packageB packageA)
else()
    # 如果单独编译，就通过 find_package 找到安装好的 packageA
    find_package(packageA REQUIRED)
    target_link_libraries(packageB packageA::packageA)
endif()
