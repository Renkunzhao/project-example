cmake_minimum_required(VERSION 3.10)
project(packageA VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(packageA STATIC src/packageA.cpp)

target_include_directories(packageA
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# 安装库
install(TARGETS packageA EXPORT packageATargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

# 安装头文件
install(DIRECTORY include/ DESTINATION include)

# 安装导出文件
install(EXPORT packageATargets
        FILE packageAConfig.cmake
        NAMESPACE packageA::
        DESTINATION lib/cmake/packageA)
