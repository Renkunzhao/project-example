cmake_minimum_required(VERSION 3.10)
project(package_a VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(package_a STATIC src/package_a.cpp)

target_include_directories(package_a
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
ament_target_dependencies(package_a rclcpp)

# 安装库
install(TARGETS package_a EXPORT package_aTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)

# 安装头文件
install(DIRECTORY include/ DESTINATION include)

# 安装导出文件
install(EXPORT package_aTargets
        FILE package_aConfig.cmake
        NAMESPACE package_a::
        DESTINATION lib/cmake/package_a)

ament_package()
